#include "webgpu-utils.h"
#include "ResourceManager.h"

#include <webgpu/webgpu.h>
#ifdef WEBGPU_BACKEND_WGPU
#  include <webgpu/wgpu.h>
#endif // WEBGPU_BACKEND_WGPU

#include <GLFW/glfw3.h>
#include <glfw3webgpu.h>

#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#define GLM_FORCE_LEFT_HANDED
#include <glm/glm.hpp> // all types inspired from GLSL
#include <glm/ext.hpp>

#ifdef __EMSCRIPTEN__
#  include <emscripten.h>
#endif // __EMSCRIPTEN__

#include <iostream>
#include <cassert>
#include <vector>
#include <array>

using glm::mat4x4;
using glm::vec4;
using glm::vec3;

constexpr float PI = 3.14159265358979323846f;

class Application {
public:
	// Initialize everything and return true if it went all right
	bool Initialize();

	// Uninitialize everything that was initialized
	void Terminate();

	// Draw a frame and handle events
	void MainLoop();

	// Return true as long as the main loop should keep on running
	bool IsRunning();

private:
	// Internal structures
	/**
	 * The same structure as in the shader, replicated in C++
	 */

	struct MyUniforms {
		mat4x4 projectionMatrix;
		mat4x4 viewMatrix;
		mat4x4 modelMatrix;
		vec4 color;
		float time;
		float _pad[3];
	};
	// Have the compiler check byte alignment
	static_assert(sizeof(MyUniforms) % 16 == 0);

	/**
	 * A structure that describes the data layout in the vertex buffer
	 * We do not instantiate it but use it in `sizeof` and `offsetof`
	 */
	struct VertexAttributes {
		vec3 position;
		vec3 normal;
		vec3 color;
	};

private:
	WGPUTextureView GetNextSurfaceTextureView();
	WGPURequiredLimits GetRequiredLimits(WGPUAdapter adapter) const;

	// Substeps of Initialize() that creates the render pipeline
	void InitializePipeline();
	void InitializeBuffers();
	void InitializeBindGroups();

private:
	// We put here all the variables that are shared between init and main loop
	GLFWwindow* window;
	WGPUDevice device;
	WGPUQueue queue;
	WGPUSurface surface;
	WGPUTextureFormat surfaceFormat = WGPUTextureFormat_Undefined;
	WGPURenderPipeline pipeline;
	WGPUBuffer pointBuffer;
	WGPUBuffer indexBuffer;
	uint32_t indexCount;
	WGPUBuffer uniformBuffer;
	WGPUPipelineLayout layout;
	WGPUBindGroupLayout bindGroupLayout;
	WGPUBindGroup bindGroup;
	WGPUTexture depthTexture;
	WGPUTextureView depthTextureView;
	MyUniforms uniforms;
};

int main() {
	Application app;

	if (!app.Initialize()) {
		return 1;
	}

#ifdef __EMSCRIPTEN__
	// Equivalent of the main loop when using Emscripten:
	auto callback = [](void* arg) {
		Application* pApp = reinterpret_cast<Application*>(arg);
		pApp->MainLoop(); // 4. We can use the application object
		};
	emscripten_set_main_loop_arg(callback, &app, 0, true);
#else // __EMSCRIPTEN__
	while (app.IsRunning()) {
		app.MainLoop();
	}
#endif // __EMSCRIPTEN__

	app.Terminate();

	return 0;
}

// If you do not use webgpu.hpp, I suggest you create a function to init the
// WGPULimits structure:
void setDefault(WGPULimits& limits) {
	limits.maxTextureDimension1D = WGPU_LIMIT_U32_UNDEFINED;
	limits.maxTextureDimension2D = WGPU_LIMIT_U32_UNDEFINED;
	limits.maxTextureDimension3D = WGPU_LIMIT_U32_UNDEFINED;
	limits.maxTextureArrayLayers = WGPU_LIMIT_U32_UNDEFINED;
	limits.maxBindGroups = WGPU_LIMIT_U32_UNDEFINED;
	limits.maxBindGroupsPlusVertexBuffers = WGPU_LIMIT_U32_UNDEFINED;
	limits.maxBindingsPerBindGroup = WGPU_LIMIT_U32_UNDEFINED;
	limits.maxDynamicUniformBuffersPerPipelineLayout = WGPU_LIMIT_U32_UNDEFINED;
	limits.maxDynamicStorageBuffersPerPipelineLayout = WGPU_LIMIT_U32_UNDEFINED;
	limits.maxSampledTexturesPerShaderStage = WGPU_LIMIT_U32_UNDEFINED;
	limits.maxSamplersPerShaderStage = WGPU_LIMIT_U32_UNDEFINED;
	limits.maxStorageBuffersPerShaderStage = WGPU_LIMIT_U32_UNDEFINED;
	limits.maxStorageTexturesPerShaderStage = WGPU_LIMIT_U32_UNDEFINED;
	limits.maxUniformBuffersPerShaderStage = WGPU_LIMIT_U32_UNDEFINED;
	limits.maxUniformBufferBindingSize = WGPU_LIMIT_U64_UNDEFINED;
	limits.maxStorageBufferBindingSize = WGPU_LIMIT_U64_UNDEFINED;
	limits.minUniformBufferOffsetAlignment = WGPU_LIMIT_U32_UNDEFINED;
	limits.minStorageBufferOffsetAlignment = WGPU_LIMIT_U32_UNDEFINED;
	limits.maxVertexBuffers = WGPU_LIMIT_U32_UNDEFINED;
	limits.maxBufferSize = WGPU_LIMIT_U64_UNDEFINED;
	limits.maxVertexAttributes = WGPU_LIMIT_U32_UNDEFINED;
	limits.maxVertexBufferArrayStride = WGPU_LIMIT_U32_UNDEFINED;
	limits.maxInterStageShaderComponents = WGPU_LIMIT_U32_UNDEFINED;
	limits.maxInterStageShaderVariables = WGPU_LIMIT_U32_UNDEFINED;
	limits.maxColorAttachments = WGPU_LIMIT_U32_UNDEFINED;
	limits.maxColorAttachmentBytesPerSample = WGPU_LIMIT_U32_UNDEFINED;
	limits.maxComputeWorkgroupStorageSize = WGPU_LIMIT_U32_UNDEFINED;
	limits.maxComputeInvocationsPerWorkgroup = WGPU_LIMIT_U32_UNDEFINED;
	limits.maxComputeWorkgroupSizeX = WGPU_LIMIT_U32_UNDEFINED;
	limits.maxComputeWorkgroupSizeY = WGPU_LIMIT_U32_UNDEFINED;
	limits.maxComputeWorkgroupSizeZ = WGPU_LIMIT_U32_UNDEFINED;
	limits.maxComputeWorkgroupsPerDimension = WGPU_LIMIT_U32_UNDEFINED;
}

void setDefault(WGPUBindGroupLayoutEntry& bindingLayout) {
	bindingLayout.buffer.nextInChain = nullptr;
	bindingLayout.buffer.type = WGPUBufferBindingType_Undefined;
	bindingLayout.buffer.hasDynamicOffset = false;

	bindingLayout.sampler.nextInChain = nullptr;
	bindingLayout.sampler.type = WGPUSamplerBindingType_Undefined;

	bindingLayout.storageTexture.nextInChain = nullptr;
	bindingLayout.storageTexture.access = WGPUStorageTextureAccess_Undefined;
	bindingLayout.storageTexture.format = WGPUTextureFormat_Undefined;
	bindingLayout.storageTexture.viewDimension = WGPUTextureViewDimension_Undefined;

	bindingLayout.texture.nextInChain = nullptr;
	bindingLayout.texture.multisampled = false;
	bindingLayout.texture.sampleType = WGPUTextureSampleType_Undefined;
	bindingLayout.texture.viewDimension = WGPUTextureViewDimension_Undefined;
}

void setDefault(WGPUStencilFaceState& stencilFaceState) {
	stencilFaceState.compare = WGPUCompareFunction_Always;
	stencilFaceState.failOp = WGPUStencilOperation_Keep;
	stencilFaceState.depthFailOp = WGPUStencilOperation_Keep;
	stencilFaceState.passOp = WGPUStencilOperation_Keep;
}

void setDefault(WGPUDepthStencilState& depthStencilState) {
	depthStencilState.nextInChain = nullptr;
	depthStencilState.format = WGPUTextureFormat_Undefined;
	depthStencilState.depthWriteEnabled = true;
	depthStencilState.depthCompare = WGPUCompareFunction_Always;
	depthStencilState.stencilReadMask = 0xFFFFFFFF;
	depthStencilState.stencilWriteMask = 0xFFFFFFFF;
	depthStencilState.depthBias = 0;
	depthStencilState.depthBiasSlopeScale = 0;
	depthStencilState.depthBiasClamp = 0;
	setDefault(depthStencilState.stencilFront);
	setDefault(depthStencilState.stencilBack);
}

bool Application::Initialize() {
	// Open window
	glfwInit();
	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
	window = glfwCreateWindow(640, 480, "Learn WebGPU", nullptr, nullptr);

	WGPUInstance instance = wgpuCreateInstance(nullptr);

	std::cout << "Requesting adapter..." << std::endl;
	surface = glfwGetWGPUSurface(instance, window);
	WGPURequestAdapterOptions adapterOpts = {};
	adapterOpts.nextInChain = nullptr;
	adapterOpts.compatibleSurface = surface;
	WGPUAdapter adapter = requestAdapterSync(instance, &adapterOpts);
	std::cout << "Got adapter: " << adapter << std::endl;

	wgpuInstanceRelease(instance);

	std::cout << "Requesting device..." << std::endl;
	WGPUDeviceDescriptor deviceDesc = {};
	deviceDesc.nextInChain = nullptr;
	deviceDesc.label = "My Device";
	deviceDesc.requiredFeatureCount = 0;
	WGPURequiredLimits requiredLimits = GetRequiredLimits(adapter);
	deviceDesc.requiredLimits = &requiredLimits;
	deviceDesc.defaultQueue.nextInChain = nullptr;
	deviceDesc.defaultQueue.label = "The default queue";
	deviceDesc.deviceLostCallback = [](WGPUDeviceLostReason reason, char const* message, void* /* pUserData */) {
		std::cout << "Device lost: reason " << reason;
		if (message) std::cout << " (" << message << ")";
		std::cout << std::endl;
		};
	device = requestDeviceSync(adapter, &deviceDesc);
	std::cout << "Got device: " << device << std::endl;

	auto onDeviceError = [](WGPUErrorType type, char const* message, void* /* pUserData */) {
		std::cout << "Uncaptured device error: type " << type;
		if (message) std::cout << " (" << message << ")";
		std::cout << std::endl;
		};
	wgpuDeviceSetUncapturedErrorCallback(device, onDeviceError, nullptr /* pUserData */);

	queue = wgpuDeviceGetQueue(device);

	// Configure the surface
	WGPUSurfaceConfiguration config = {};
	config.nextInChain = nullptr;

	// Configuration of the textures created for the underlying swap chain
	config.width = 640;
	config.height = 480;
	config.usage = WGPUTextureUsage_RenderAttachment;
	surfaceFormat = wgpuSurfaceGetPreferredFormat(surface, adapter);
	config.format = surfaceFormat;

	// And we do not need any particular view format:
	config.viewFormatCount = 0;
	config.viewFormats = nullptr;
	config.device = device;
	config.presentMode = WGPUPresentMode_Fifo;
	config.alphaMode = WGPUCompositeAlphaMode_Auto;

	wgpuSurfaceConfigure(surface, &config);

	// Release the adapter only after it has been fully utilized
	wgpuAdapterRelease(adapter);

	InitializePipeline();
	InitializeBuffers();
	InitializeBindGroups();

	return true;
}

void Application::InitializePipeline() {
	std::cout << "Creating shader module..." << std::endl;
	WGPUShaderModule shaderModule = ResourceManager::loadShaderModule(RESOURCE_DIR "/shader.wgsl", device);
	std::cout << "Shader module: " << shaderModule << std::endl;

	// Check for errors
	if (shaderModule == nullptr) {
		std::cerr << "Could not load shader!" << std::endl;
		exit(1);
	}

	// Create the render pipeline
	WGPURenderPipelineDescriptor pipelineDesc{};
	pipelineDesc.nextInChain = nullptr;

	// Configure the vertex pipeline
	// We use one vertex buffer
	WGPUVertexBufferLayout vertexBufferLayout{};
	// We now have 2 attributes
	std::vector<WGPUVertexAttribute> vertexAttribs(3);
	//                                             ^ This was a 2

	// Position attribute
	vertexAttribs[0].shaderLocation = 0;
	vertexAttribs[0].format = WGPUVertexFormat_Float32x3;
	vertexAttribs[0].offset = offsetof(VertexAttributes, position);

	// Normal attribute
	vertexAttribs[1].shaderLocation = 1;
	vertexAttribs[1].format = WGPUVertexFormat_Float32x3;
	vertexAttribs[1].offset = offsetof(VertexAttributes, normal);

	// Color attribute
	vertexAttribs[2].shaderLocation = 2;
	vertexAttribs[2].format = WGPUVertexFormat_Float32x3;
	vertexAttribs[2].offset = offsetof(VertexAttributes, color);

	vertexBufferLayout.attributeCount = static_cast<uint32_t>(vertexAttribs.size());
	vertexBufferLayout.attributes = vertexAttribs.data();

	// The buffer stride
	vertexBufferLayout.arrayStride = sizeof(VertexAttributes);
	//                               ^^^^^^^^^^^^^^^^^^^^^^^^ This was 6 * sizeof(float)
	vertexBufferLayout.stepMode = WGPUVertexStepMode_Vertex;

	pipelineDesc.vertex.bufferCount = 1;
	pipelineDesc.vertex.buffers = &vertexBufferLayout;

	// NB: We define the 'shaderModule' in the second part of this chapter.
	// Here we tell that the programmable vertex shader stage is described
	// by the function called 'vs_main' in that module.
	pipelineDesc.vertex.module = shaderModule;
	pipelineDesc.vertex.entryPoint = "vs_main";
	pipelineDesc.vertex.constantCount = 0;
	pipelineDesc.vertex.constants = nullptr;

	// Each sequence of 3 vertices is considered as a triangle
	pipelineDesc.primitive.topology = WGPUPrimitiveTopology_TriangleList;

	// We'll see later how to specify the order in which vertices should be
	// connected. When not specified, vertices are considered sequentially.
	pipelineDesc.primitive.stripIndexFormat = WGPUIndexFormat_Undefined;

	// The face orientation is defined by assuming that when looking
	// from the front of the face, its corner vertices are enumerated
	// in the counter-clockwise (CCW) order.
	pipelineDesc.primitive.frontFace = WGPUFrontFace_CCW;

	// But the face orientation does not matter much because we do not
	// cull (i.e. "hide") the faces pointing away from us (which is often
	// used for optimization).
	pipelineDesc.primitive.cullMode = WGPUCullMode_None;

	// We tell that the programmable fragment shader stage is described
	// by the function called 'fs_main' in the shader module.
	WGPUFragmentState fragmentState{};
	fragmentState.module = shaderModule;
	fragmentState.entryPoint = "fs_main";
	fragmentState.constantCount = 0;
	fragmentState.constants = nullptr;

	WGPUBlendState blendState{};
	blendState.color.srcFactor = WGPUBlendFactor_SrcAlpha;
	blendState.color.dstFactor = WGPUBlendFactor_OneMinusSrcAlpha;
	blendState.color.operation = WGPUBlendOperation_Add;
	blendState.alpha.srcFactor = WGPUBlendFactor_Zero;
	blendState.alpha.dstFactor = WGPUBlendFactor_One;
	blendState.alpha.operation = WGPUBlendOperation_Add;

	WGPUColorTargetState colorTarget{};
	colorTarget.format = surfaceFormat;
	colorTarget.blend = &blendState;
	colorTarget.writeMask = WGPUColorWriteMask_All; // We could write to only some of the color channels.

	// We have only one target because our render pass has only one output color
	// attachment.
	fragmentState.targetCount = 1;
	fragmentState.targets = &colorTarget;
	pipelineDesc.fragment = &fragmentState;

	WGPUDepthStencilState depthStencilState;
	setDefault(depthStencilState);

	depthStencilState.depthCompare = WGPUCompareFunction_Less;
	depthStencilState.depthWriteEnabled = true;
	// Store the format in a variable as later parts of the code depend on it
	WGPUTextureFormat depthTextureFormat = WGPUTextureFormat_Depth24Plus;
	depthStencilState.format = depthTextureFormat;
	// Deactivate the stencil alltogether
	depthStencilState.stencilReadMask = 0;
	depthStencilState.stencilWriteMask = 0;

	pipelineDesc.depthStencil = &depthStencilState;

	// Samples per pixel
	pipelineDesc.multisample.count = 1;

	// Default value for the mask, meaning "all bits on"
	pipelineDesc.multisample.mask = ~0u;

	// Default value as well (irrelevant for count = 1 anyways)
	pipelineDesc.multisample.alphaToCoverageEnabled = false;

	// Define binding layout
	WGPUBindGroupLayoutEntry bindingLayout{};
	setDefault(bindingLayout);
	// The binding index as used in the @binding attribute in the shader
	bindingLayout.binding = 0;
	// The stage that needs to access this resource
	bindingLayout.visibility = WGPUShaderStage_Vertex | WGPUShaderStage_Fragment;
	//                         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ This changed
	bindingLayout.buffer.type = WGPUBufferBindingType_Uniform;
	bindingLayout.buffer.minBindingSize = sizeof(MyUniforms);
	//                                    ^^^^^^^^^^^^^^^^^^ This was 4 * sizeof(float)

	// Create a bind group layout
	WGPUBindGroupLayoutDescriptor bindGroupLayoutDesc{};
	bindGroupLayoutDesc.nextInChain = nullptr;
	bindGroupLayoutDesc.entryCount = 1;
	bindGroupLayoutDesc.entries = &bindingLayout;
	bindGroupLayout = wgpuDeviceCreateBindGroupLayout(device, &bindGroupLayoutDesc);

	// Create the pipeline layout
	WGPUPipelineLayoutDescriptor layoutDesc{};
	layoutDesc.nextInChain = nullptr;
	layoutDesc.bindGroupLayoutCount = 1;
	layoutDesc.bindGroupLayouts = &bindGroupLayout;
	layout = wgpuDeviceCreatePipelineLayout(device, &layoutDesc);

	// Assign the PipelineLayout to the RenderPipelineDescriptor's layout field
	pipelineDesc.layout = layout;

	pipeline = wgpuDeviceCreateRenderPipeline(device, &pipelineDesc);

	// Create the depth texture
	WGPUTextureDescriptor depthTextureDesc = {};
	depthTextureDesc.dimension = WGPUTextureDimension_2D;
	depthTextureDesc.format = depthTextureFormat;
	depthTextureDesc.mipLevelCount = 1;
	depthTextureDesc.sampleCount = 1;
	depthTextureDesc.size = { 640, 480, 1 };
	depthTextureDesc.usage = WGPUTextureUsage_RenderAttachment;
	depthTextureDesc.viewFormatCount = 1;
	depthTextureDesc.viewFormats = &depthTextureFormat;

	depthTexture = wgpuDeviceCreateTexture(device, &depthTextureDesc);

	// Create the view of the depth texture manipulated by the rasterizer
	WGPUTextureViewDescriptor depthTextureViewDesc = {};
	depthTextureViewDesc.aspect = WGPUTextureAspect_DepthOnly;
	depthTextureViewDesc.baseArrayLayer = 0;
	depthTextureViewDesc.arrayLayerCount = 1;
	depthTextureViewDesc.baseMipLevel = 0;
	depthTextureViewDesc.mipLevelCount = 1;
	depthTextureViewDesc.dimension = WGPUTextureViewDimension_2D;
	depthTextureViewDesc.format = depthTextureFormat;
	depthTextureView = wgpuTextureCreateView(depthTexture, &depthTextureViewDesc);

	// We no longer need to access the shader module
	wgpuShaderModuleRelease(shaderModule);
}

void Application::InitializeBuffers() {
	// Define data vectors, but without filling them in
	std::vector<float> pointData;
	std::vector<uint16_t> indexData;

	// Here we use the new 'loadGeometry' function:
	bool success = ResourceManager::loadGeometry(RESOURCE_DIR "/pyramid.txt", pointData, indexData, 6);
	//                                                                                              ^ This was a 3

	// Check for errors
	if (!success) {
		std::cerr << "Could not load geometry!" << std::endl;
		exit(1);
	}

	// We now store the index count rather than the vertex count
	indexCount = static_cast<uint32_t>(indexData.size());

	// Create point buffer
	WGPUBufferDescriptor bufferDesc{};
	bufferDesc.nextInChain = nullptr;
	bufferDesc.size = pointData.size() * sizeof(float);
	bufferDesc.usage = WGPUBufferUsage_CopyDst | WGPUBufferUsage_Vertex; // Vertex usage here!
	bufferDesc.mappedAtCreation = false;
	pointBuffer = wgpuDeviceCreateBuffer(device, &bufferDesc);

	// Upload geometry data to the buffer
	wgpuQueueWriteBuffer(queue, pointBuffer, 0, pointData.data(), bufferDesc.size);

	// Create index buffer
	// (we reuse the bufferDesc initialized for the pointBuffer)
	bufferDesc.size = indexData.size() * sizeof(uint16_t);
	bufferDesc.size = (bufferDesc.size + 3) & ~3; // round up to the next multiple of 4
	bufferDesc.usage = WGPUBufferUsage_CopyDst | WGPUBufferUsage_Index;;
	indexBuffer = wgpuDeviceCreateBuffer(device, &bufferDesc);

	wgpuQueueWriteBuffer(queue, indexBuffer, 0, indexData.data(), bufferDesc.size);

	// Create uniform buffer (reusing bufferDesc from other buffer creations)
	// The buffer will only contain 1 float with the value of uTime
	// then 3 floats left empty but needed by alignment constraints
	bufferDesc.size = sizeof(MyUniforms);
	//                ^^^^^^^^^^^^^^^^^^ This was 4 * sizeof(float)

	// Make sure to flag the buffer as BufferUsage::Uniform
	bufferDesc.usage = WGPUBufferUsage_CopyDst | WGPUBufferUsage_Uniform;

	bufferDesc.mappedAtCreation = false;
	uniformBuffer = wgpuDeviceCreateBuffer(device, &bufferDesc);

	// Upload the initial value of the uniforms
	//MyUniforms uniforms;
	uniforms.time = 1.0f;
	uniforms.color = { 0.0f, 1.0f, 0.4f, 1.0f };

	mat4x4 M(1.0);
	float angle1 = (float)glfwGetTime();
	M = glm::rotate(M, angle1, vec3(0.0, 0.0, 1.0));
	M = glm::translate(M, vec3(0.5, 0.0, 0.0));
	M = glm::scale(M, vec3(0.3f));
	uniforms.modelMatrix = M;

	mat4x4 V(1.0);
	vec3 focalPoint(0.0, 0.0, -2.0);
	float angle2 = 3.0f * PI / 4.0f;
	V = glm::translate(V, -focalPoint);
	V = glm::rotate(V, -angle2, vec3(1.0, 0.0, 0.0));
	uniforms.viewMatrix = V;

	float near = 0.001f;
	float far = 100.0f;
	float ratio = 640.0f / 480.0f;
	float focalLength = 2.0;
	float fov = 2 * glm::atan(1 / focalLength);
	uniforms.projectionMatrix = glm::perspective(fov, ratio, near, far);

	wgpuQueueWriteBuffer(queue, uniformBuffer, 0, &uniforms, sizeof(MyUniforms));
}

void Application::InitializeBindGroups() {
	// Create a binding
	WGPUBindGroupEntry binding{};
	binding.nextInChain = nullptr;
	// The index of the binding (the entries in bindGroupDesc can be in any order)
	binding.binding = 0;
	// The buffer it is actually bound to
	binding.buffer = uniformBuffer;
	// We can specify an offset within the buffer, so that a single buffer can hold
	// multiple uniform blocks.
	binding.offset = 0;
	// And we specify again the size of the buffer.
	binding.size = sizeof(MyUniforms);
	//             ^^^^^^^^^^^^^^^^^^ This was 4 * sizeof(float)

	// A bind group contains one or multiple bindings
	WGPUBindGroupDescriptor bindGroupDesc{};
	bindGroupDesc.nextInChain = nullptr;
	bindGroupDesc.layout = bindGroupLayout;
	// There must be as many bindings as declared in the layout!
	bindGroupDesc.entryCount = 1;
	bindGroupDesc.entries = &binding;
	bindGroup = wgpuDeviceCreateBindGroup(device, &bindGroupDesc);
}

bool Application::IsRunning() {
	return !glfwWindowShouldClose(window);
}

void Application::MainLoop() {
	glfwPollEvents();

	// Update uniform buffer
	uniforms.time = static_cast<float>(glfwGetTime());
	// Only update the 1-st float of the buffer
	wgpuQueueWriteBuffer(queue, uniformBuffer, offsetof(MyUniforms, time), &uniforms.time, sizeof(float));

	// Update view matrix
	float angle1 = uniforms.time;
	mat4x4 S(1.0);
	S = glm::scale(mat4x4(1.0), vec3(0.3f));
	mat4x4 T1(1.0);
	T1 = glm::translate(mat4x4(1.0), vec3(0.5, 0.0, 0.0));
	mat4x4 R1(1.0);
	R1 = glm::rotate(mat4x4(1.0), angle1, vec3(0.0, 0.0, 1.0));

	R1 = glm::rotate(mat4x4(1.0), angle1, vec3(0.0, 0.0, 1.0));
	uniforms.modelMatrix = R1 * T1 * S;
	wgpuQueueWriteBuffer(queue, uniformBuffer, offsetof(MyUniforms, modelMatrix), &uniforms.modelMatrix, sizeof(MyUniforms::modelMatrix));

	// Get the next target texture view
	WGPUTextureView targetView = GetNextSurfaceTextureView();
	if (!targetView) return;

	// Create a command encoder for the draw call
	WGPUCommandEncoderDescriptor encoderDesc = {};
	encoderDesc.nextInChain = nullptr;
	encoderDesc.label = "My command encoder";
	WGPUCommandEncoder encoder = wgpuDeviceCreateCommandEncoder(device, &encoderDesc);

	// Create the render pass that clears the screen with our color
	WGPURenderPassDescriptor renderPassDesc = {};
	renderPassDesc.nextInChain = nullptr;

	// The attachment part of the render pass descriptor describes the target texture of the pass
	WGPURenderPassColorAttachment renderPassColorAttachment = {};
	renderPassColorAttachment.view = targetView;
	renderPassColorAttachment.resolveTarget = nullptr;
	renderPassColorAttachment.loadOp = WGPULoadOp_Clear;
	renderPassColorAttachment.storeOp = WGPUStoreOp_Store;
	renderPassColorAttachment.clearValue = WGPUColor{ 0.05, 0.05, 0.05, 1.0 };
#ifndef WEBGPU_BACKEND_WGPU
	renderPassColorAttachment.depthSlice = WGPU_DEPTH_SLICE_UNDEFINED;
#endif // NOT WEBGPU_BACKEND_WGPU

	renderPassDesc.colorAttachmentCount = 1;
	renderPassDesc.colorAttachments = &renderPassColorAttachment;

	// We now add a depth/stencil attachment:
	WGPURenderPassDepthStencilAttachment depthStencilAttachment;

	// Setup depth/stencil attachment
	// The view of the depth texture
	depthStencilAttachment.view = depthTextureView;

	// The initial value of the depth buffer, meaning "far"
	depthStencilAttachment.depthClearValue = 1.0f;
	// Operation settings comparable to the color attachment
	depthStencilAttachment.depthLoadOp = WGPULoadOp_Clear;
	depthStencilAttachment.depthStoreOp = WGPUStoreOp_Store;
	// we could turn off writing to the depth buffer globally here
	depthStencilAttachment.depthReadOnly = false;

	// Stencil setup, mandatory but unused
	depthStencilAttachment.stencilClearValue = 0;
	depthStencilAttachment.stencilLoadOp = WGPULoadOp_Undefined;
	depthStencilAttachment.stencilStoreOp = WGPUStoreOp_Undefined;
	depthStencilAttachment.stencilReadOnly = true;

	renderPassDesc.depthStencilAttachment = &depthStencilAttachment;

	renderPassDesc.timestampWrites = nullptr;

	WGPURenderPassEncoder renderPass = wgpuCommandEncoderBeginRenderPass(encoder, &renderPassDesc);

	// Select which render pipeline to use
	wgpuRenderPassEncoderSetPipeline(renderPass, pipeline);

	// Set vertex buffer while encoding the render pass
	wgpuRenderPassEncoderSetVertexBuffer(renderPass, 0, pointBuffer, 0, wgpuBufferGetSize(pointBuffer));

	// The second argument must correspond to the choice of uint16_t or uint32_t
	// we've done when creating the index buffer.
	wgpuRenderPassEncoderSetIndexBuffer(renderPass, indexBuffer, WGPUIndexFormat_Uint16, 0, wgpuBufferGetSize(indexBuffer));

	// Set binding group here!
	wgpuRenderPassEncoderSetBindGroup(renderPass, 0, bindGroup, 0, nullptr);

	// Replace `draw()` with `drawIndexed()` and `vertexCount` with `indexCount`
	// The extra argument is an offset within the index buffer.
	wgpuRenderPassEncoderDrawIndexed(renderPass, indexCount, 1, 0, 0, 0);

	wgpuRenderPassEncoderEnd(renderPass);
	wgpuRenderPassEncoderRelease(renderPass);

	// Encode and submit the render pass
	WGPUCommandBufferDescriptor cmdBufferDescriptor = {};
	cmdBufferDescriptor.nextInChain = nullptr;
	cmdBufferDescriptor.label = "Command buffer";
	WGPUCommandBuffer command = wgpuCommandEncoderFinish(encoder, &cmdBufferDescriptor);
	wgpuCommandEncoderRelease(encoder);

	std::cout << "Submitting command..." << std::endl;
	wgpuQueueSubmit(queue, 1, &command);
	wgpuCommandBufferRelease(command);
	std::cout << "Command submitted." << std::endl;

	// At the end of the frame
	wgpuTextureViewRelease(targetView);
#ifndef __EMSCRIPTEN__
	wgpuSurfacePresent(surface);
#endif

#if defined(WEBGPU_BACKEND_DAWN)
	wgpuDeviceTick(device);
#elif defined(WEBGPU_BACKEND_WGPU)
	wgpuDevicePoll(device, false, nullptr);
#endif
}

void Application::Terminate() {
	wgpuBindGroupRelease(bindGroup);
	wgpuPipelineLayoutRelease(layout);
	wgpuBindGroupLayoutRelease(bindGroupLayout);
	wgpuBufferRelease(uniformBuffer);
	wgpuBufferRelease(pointBuffer);
	wgpuBufferRelease(indexBuffer);

	// Destroy the depth texture and its view
	wgpuTextureViewRelease(depthTextureView);
	wgpuTextureDestroy(depthTexture);
	wgpuTextureRelease(depthTexture);

	wgpuRenderPipelineRelease(pipeline);
	wgpuSurfaceUnconfigure(surface);
	wgpuQueueRelease(queue);
	wgpuSurfaceRelease(surface);
	wgpuDeviceRelease(device);
	glfwDestroyWindow(window);
	glfwTerminate();
}

WGPUTextureView Application::GetNextSurfaceTextureView() {
	// Get the surface texture
	WGPUSurfaceTexture surfaceTexture;
	wgpuSurfaceGetCurrentTexture(surface, &surfaceTexture);
	if (surfaceTexture.status != WGPUSurfaceGetCurrentTextureStatus_Success) {
		return nullptr;
	}

	// Create a view for this surface texture
	WGPUTextureViewDescriptor viewDescriptor;
	viewDescriptor.nextInChain = nullptr;
	viewDescriptor.label = "Surface texture view";
	viewDescriptor.format = wgpuTextureGetFormat(surfaceTexture.texture);
	viewDescriptor.dimension = WGPUTextureViewDimension_2D;
	viewDescriptor.baseMipLevel = 0;
	viewDescriptor.mipLevelCount = 1;
	viewDescriptor.baseArrayLayer = 0;
	viewDescriptor.arrayLayerCount = 1;
	viewDescriptor.aspect = WGPUTextureAspect_All;
	WGPUTextureView targetView = wgpuTextureCreateView(surfaceTexture.texture, &viewDescriptor);

#ifndef WEBGPU_BACKEND_WGPU
	// We no longer need the texture, only its view
	// (NB: with wgpu-native, surface textures must not be manually released)
	wgpuTextureRelease(surfaceTexture.texture);
#endif // WEBGPU_BACKEND_WGPU

	return targetView;
}

WGPURequiredLimits Application::GetRequiredLimits(WGPUAdapter adapter) const {
	// Get adapter supported limits, in case we need them
	WGPUSupportedLimits supportedLimits;
	supportedLimits.nextInChain = nullptr;
	wgpuAdapterGetLimits(adapter, &supportedLimits);

	WGPURequiredLimits requiredLimits{};
	setDefault(requiredLimits.limits);

	// We use at most 2 vertex attributes
	requiredLimits.limits.maxVertexAttributes = 3;
	//                                          ^ This was a 2
	// We should also tell that we use 1 vertex buffers
	requiredLimits.limits.maxVertexBuffers = 1;
	// Maximum size of a buffer is 6 vertices of 5 float each
	requiredLimits.limits.maxBufferSize = 16 * sizeof(VertexAttributes);
	//                                         ^^^^^^^^^^^^^^^^^^^^^^^^ This was 6 * sizeof(float)
	//                                    ^^ This was 15
	// Maximum stride between 2 consecutive vertices in the vertex buffer
	requiredLimits.limits.maxVertexBufferArrayStride = sizeof(VertexAttributes);
	//                                                        ^^^^^^^^^^^^^^^^^^^^^^^^ This was 6 * sizeof(float)


	// There is a maximum of 3 float forwarded from vertex to fragment shader
	requiredLimits.limits.maxInterStageShaderComponents = 6;
	//                                                    ^ This was a 3

	// We use at most 1 bind group for now
	requiredLimits.limits.maxBindGroups = 1;
	// We use at most 1 uniform buffer per stage
	requiredLimits.limits.maxUniformBuffersPerShaderStage = 1;
	// Uniform structs have a size of maximum 16 float (more than what we need)
	requiredLimits.limits.maxUniformBufferBindingSize = 16 * 4 * sizeof(float);

	// For the depth buffer, we enable textures (up to the size of the window):
	requiredLimits.limits.maxTextureDimension1D = 480;
	requiredLimits.limits.maxTextureDimension2D = 640;
	requiredLimits.limits.maxTextureArrayLayers = 1;

	// These two limits are different because they are "minimum" limits,
	// they are the only ones we are may forward from the adapter's supported
	// limits.
	requiredLimits.limits.minUniformBufferOffsetAlignment = supportedLimits.limits.minUniformBufferOffsetAlignment;
	requiredLimits.limits.minStorageBufferOffsetAlignment = supportedLimits.limits.minStorageBufferOffsetAlignment;

	return requiredLimits;
}