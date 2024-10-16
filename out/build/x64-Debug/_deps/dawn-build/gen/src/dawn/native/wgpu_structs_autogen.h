
#ifndef DAWNNATIVE_WGPU_STRUCTS_H_
#define DAWNNATIVE_WGPU_STRUCTS_H_

#include "dawn/webgpu_cpp.h"
#include "dawn/native/Forward.h"
#include <cmath>

namespace dawn::native {


    using wgpu::ChainedStruct;
    using wgpu::ChainedStructOut;

    struct AdapterInfo {
        AdapterInfo() = default;
        ~AdapterInfo();
        AdapterInfo(const AdapterInfo&) = delete;
        AdapterInfo& operator=(const AdapterInfo&) = delete;
        AdapterInfo(AdapterInfo&&);
        AdapterInfo& operator=(AdapterInfo&&);

        ChainedStructOut * nextInChain = nullptr;
        char const * vendor = nullptr;
        char const * architecture = nullptr;
        char const * device = nullptr;
        char const * description = nullptr;
        wgpu::BackendType backendType;
        wgpu::AdapterType adapterType;
        uint32_t vendorID;
        uint32_t deviceID;

        // Equality operators, mostly for testing. Note that this tests
        // strict pointer-pointer equality if the struct contains member pointers.
        bool operator==(const AdapterInfo& rhs) const;
    };

    struct AdapterProperties {
        AdapterProperties() = default;
        ~AdapterProperties();
        AdapterProperties(const AdapterProperties&) = delete;
        AdapterProperties& operator=(const AdapterProperties&) = delete;
        AdapterProperties(AdapterProperties&&);
        AdapterProperties& operator=(AdapterProperties&&);

        ChainedStructOut * nextInChain = nullptr;
        uint32_t vendorID;
        char const * vendorName = nullptr;
        char const * architecture = nullptr;
        uint32_t deviceID;
        char const * name = nullptr;
        char const * driverDescription = nullptr;
        wgpu::AdapterType adapterType;
        wgpu::BackendType backendType;
        wgpu::Bool compatibilityMode = false;

        // Equality operators, mostly for testing. Note that this tests
        // strict pointer-pointer equality if the struct contains member pointers.
        bool operator==(const AdapterProperties& rhs) const;
    };

    struct AdapterPropertiesD3D : ChainedStructOut {
        AdapterPropertiesD3D() {
            sType = wgpu::SType::AdapterPropertiesD3D;
        }
        alignas(wgpu::AdapterPropertiesD3D::kFirstMemberAlignment) uint32_t shaderModel;

        // Equality operators, mostly for testing. Note that this tests
        // strict pointer-pointer equality if the struct contains member pointers.
        bool operator==(const AdapterPropertiesD3D& rhs) const;
    };

    struct AdapterPropertiesVk : ChainedStructOut {
        AdapterPropertiesVk() {
            sType = wgpu::SType::AdapterPropertiesVk;
        }
        alignas(wgpu::AdapterPropertiesVk::kFirstMemberAlignment) uint32_t driverVersion;

        // Equality operators, mostly for testing. Note that this tests
        // strict pointer-pointer equality if the struct contains member pointers.
        bool operator==(const AdapterPropertiesVk& rhs) const;
    };

    struct BindGroupEntry {
        ChainedStruct const * nextInChain = nullptr;
        uint32_t binding;
        BufferBase* buffer = nullptr;
        uint64_t offset = 0;
        uint64_t size = WGPU_WHOLE_SIZE;
        SamplerBase* sampler = nullptr;
        TextureViewBase* textureView = nullptr;

        // Equality operators, mostly for testing. Note that this tests
        // strict pointer-pointer equality if the struct contains member pointers.
        bool operator==(const BindGroupEntry& rhs) const;
    };

    struct BlendComponent {
        wgpu::BlendOperation operation = wgpu::BlendOperation::Add;
        wgpu::BlendFactor srcFactor = wgpu::BlendFactor::One;
        wgpu::BlendFactor dstFactor = wgpu::BlendFactor::Zero;

        // This method makes a copy of the struct, then, for any enum members with trivial
        // defaulting (where something like "Undefined" is replaced with a default), applies
        // all of the defaults for the struct, and recursively its by-value substructs (but
        // NOT by-pointer substructs since they are const*). It must be called in an
        // appropriate place in Dawn.
        [[nodiscard]] BlendComponent WithTrivialFrontendDefaults() const;
        // Equality operators, mostly for testing. Note that this tests
        // strict pointer-pointer equality if the struct contains member pointers.
        bool operator==(const BlendComponent& rhs) const;
    };

    struct BufferBindingLayout {
        ChainedStruct const * nextInChain = nullptr;
        wgpu::BufferBindingType type = wgpu::BufferBindingType::Undefined;
        wgpu::Bool hasDynamicOffset = false;
        uint64_t minBindingSize = 0;

        // Equality operators, mostly for testing. Note that this tests
        // strict pointer-pointer equality if the struct contains member pointers.
        bool operator==(const BufferBindingLayout& rhs) const;
    };

    struct BufferDescriptor {
        ChainedStruct const * nextInChain = nullptr;
        char const * label = nullptr;
        wgpu::BufferUsage usage;
        uint64_t size;
        wgpu::Bool mappedAtCreation = false;

        // Equality operators, mostly for testing. Note that this tests
        // strict pointer-pointer equality if the struct contains member pointers.
        bool operator==(const BufferDescriptor& rhs) const;
    };

    struct BufferHostMappedPointer : ChainedStruct {
        BufferHostMappedPointer() {
            sType = wgpu::SType::BufferHostMappedPointer;
        }
        alignas(wgpu::BufferHostMappedPointer::kFirstMemberAlignment) void * pointer;
        WGPUCallback disposeCallback;
        void * userdata;

        // Equality operators, mostly for testing. Note that this tests
        // strict pointer-pointer equality if the struct contains member pointers.
        bool operator==(const BufferHostMappedPointer& rhs) const;
    };

    struct BufferMapCallbackInfo {
        ChainedStruct const * nextInChain = nullptr;
        wgpu::CallbackMode mode;
        WGPUBufferMapCallback callback;
        void * userdata;

        // Equality operators, mostly for testing. Note that this tests
        // strict pointer-pointer equality if the struct contains member pointers.
        bool operator==(const BufferMapCallbackInfo& rhs) const;
    };

    struct Color {
        double r;
        double g;
        double b;
        double a;

        // Equality operators, mostly for testing. Note that this tests
        // strict pointer-pointer equality if the struct contains member pointers.
        bool operator==(const Color& rhs) const;
    };

    struct ColorTargetStateExpandResolveTextureDawn : ChainedStruct {
        ColorTargetStateExpandResolveTextureDawn() {
            sType = wgpu::SType::ColorTargetStateExpandResolveTextureDawn;
        }
        alignas(wgpu::ColorTargetStateExpandResolveTextureDawn::kFirstMemberAlignment) wgpu::Bool enabled = false;

        // Equality operators, mostly for testing. Note that this tests
        // strict pointer-pointer equality if the struct contains member pointers.
        bool operator==(const ColorTargetStateExpandResolveTextureDawn& rhs) const;
    };

    struct CommandBufferDescriptor {
        ChainedStruct const * nextInChain = nullptr;
        char const * label = nullptr;

        // Equality operators, mostly for testing. Note that this tests
        // strict pointer-pointer equality if the struct contains member pointers.
        bool operator==(const CommandBufferDescriptor& rhs) const;
    };

    struct CommandEncoderDescriptor {
        ChainedStruct const * nextInChain = nullptr;
        char const * label = nullptr;

        // Equality operators, mostly for testing. Note that this tests
        // strict pointer-pointer equality if the struct contains member pointers.
        bool operator==(const CommandEncoderDescriptor& rhs) const;
    };

    struct CompilationInfoCallbackInfo {
        ChainedStruct const * nextInChain = nullptr;
        wgpu::CallbackMode mode;
        WGPUCompilationInfoCallback callback;
        void * userdata = nullptr;

        // Equality operators, mostly for testing. Note that this tests
        // strict pointer-pointer equality if the struct contains member pointers.
        bool operator==(const CompilationInfoCallbackInfo& rhs) const;
    };

    struct CompilationMessage {
        ChainedStruct const * nextInChain = nullptr;
        char const * message = nullptr;
        wgpu::CompilationMessageType type;
        uint64_t lineNum;
        uint64_t linePos;
        uint64_t offset;
        uint64_t length;
        uint64_t utf16LinePos;
        uint64_t utf16Offset;
        uint64_t utf16Length;

        // Equality operators, mostly for testing. Note that this tests
        // strict pointer-pointer equality if the struct contains member pointers.
        bool operator==(const CompilationMessage& rhs) const;
    };

    struct ComputePassTimestampWrites {
        QuerySetBase* querySet;
        uint32_t beginningOfPassWriteIndex = WGPU_QUERY_SET_INDEX_UNDEFINED;
        uint32_t endOfPassWriteIndex = WGPU_QUERY_SET_INDEX_UNDEFINED;

        // Equality operators, mostly for testing. Note that this tests
        // strict pointer-pointer equality if the struct contains member pointers.
        bool operator==(const ComputePassTimestampWrites& rhs) const;
    };

    struct ConstantEntry {
        ChainedStruct const * nextInChain = nullptr;
        char const * key;
        double value;

        // Equality operators, mostly for testing. Note that this tests
        // strict pointer-pointer equality if the struct contains member pointers.
        bool operator==(const ConstantEntry& rhs) const;
    };

    struct CopyTextureForBrowserOptions {
        ChainedStruct const * nextInChain = nullptr;
        wgpu::Bool flipY = false;
        wgpu::Bool needsColorSpaceConversion = false;
        wgpu::AlphaMode srcAlphaMode = wgpu::AlphaMode::Unpremultiplied;
        float const * srcTransferFunctionParameters = nullptr;
        float const * conversionMatrix = nullptr;
        float const * dstTransferFunctionParameters = nullptr;
        wgpu::AlphaMode dstAlphaMode = wgpu::AlphaMode::Unpremultiplied;
        wgpu::Bool internalUsage = false;

        // Equality operators, mostly for testing. Note that this tests
        // strict pointer-pointer equality if the struct contains member pointers.
        bool operator==(const CopyTextureForBrowserOptions& rhs) const;
    };

    struct CreateComputePipelineAsyncCallbackInfo {
        ChainedStruct const * nextInChain = nullptr;
        wgpu::CallbackMode mode;
        WGPUCreateComputePipelineAsyncCallback callback;
        void * userdata;

        // Equality operators, mostly for testing. Note that this tests
        // strict pointer-pointer equality if the struct contains member pointers.
        bool operator==(const CreateComputePipelineAsyncCallbackInfo& rhs) const;
    };

    struct CreateRenderPipelineAsyncCallbackInfo {
        ChainedStruct const * nextInChain = nullptr;
        wgpu::CallbackMode mode;
        WGPUCreateRenderPipelineAsyncCallback callback;
        void * userdata;

        // Equality operators, mostly for testing. Note that this tests
        // strict pointer-pointer equality if the struct contains member pointers.
        bool operator==(const CreateRenderPipelineAsyncCallbackInfo& rhs) const;
    };

    struct DawnWGSLBlocklist : ChainedStruct {
        DawnWGSLBlocklist() {
            sType = wgpu::SType::DawnWGSLBlocklist;
        }
        alignas(wgpu::DawnWGSLBlocklist::kFirstMemberAlignment) size_t blocklistedFeatureCount = 0;
        const char* const * blocklistedFeatures;

        // Equality operators, mostly for testing. Note that this tests
        // strict pointer-pointer equality if the struct contains member pointers.
        bool operator==(const DawnWGSLBlocklist& rhs) const;
    };

    struct DawnAdapterPropertiesPowerPreference : ChainedStructOut {
        DawnAdapterPropertiesPowerPreference() {
            sType = wgpu::SType::DawnAdapterPropertiesPowerPreference;
        }
        alignas(wgpu::DawnAdapterPropertiesPowerPreference::kFirstMemberAlignment) wgpu::PowerPreference powerPreference = wgpu::PowerPreference::Undefined;

        // Equality operators, mostly for testing. Note that this tests
        // strict pointer-pointer equality if the struct contains member pointers.
        bool operator==(const DawnAdapterPropertiesPowerPreference& rhs) const;
    };

    struct DawnBufferDescriptorErrorInfoFromWireClient : ChainedStruct {
        DawnBufferDescriptorErrorInfoFromWireClient() {
            sType = wgpu::SType::DawnBufferDescriptorErrorInfoFromWireClient;
        }
        alignas(wgpu::DawnBufferDescriptorErrorInfoFromWireClient::kFirstMemberAlignment) wgpu::Bool outOfMemory = false;

        // Equality operators, mostly for testing. Note that this tests
        // strict pointer-pointer equality if the struct contains member pointers.
        bool operator==(const DawnBufferDescriptorErrorInfoFromWireClient& rhs) const;
    };

    struct DawnCacheDeviceDescriptor : ChainedStruct {
        DawnCacheDeviceDescriptor() {
            sType = wgpu::SType::DawnCacheDeviceDescriptor;
        }
        alignas(wgpu::DawnCacheDeviceDescriptor::kFirstMemberAlignment) char const * isolationKey = "";
        WGPUDawnLoadCacheDataFunction loadDataFunction = nullptr;
        WGPUDawnStoreCacheDataFunction storeDataFunction = nullptr;
        void * functionUserdata = nullptr;

        // Equality operators, mostly for testing. Note that this tests
        // strict pointer-pointer equality if the struct contains member pointers.
        bool operator==(const DawnCacheDeviceDescriptor& rhs) const;
    };

    struct DawnComputePipelineFullSubgroups : ChainedStruct {
        DawnComputePipelineFullSubgroups() {
            sType = wgpu::SType::DawnComputePipelineFullSubgroups;
        }
        alignas(wgpu::DawnComputePipelineFullSubgroups::kFirstMemberAlignment) wgpu::Bool requiresFullSubgroups = false;

        // Equality operators, mostly for testing. Note that this tests
        // strict pointer-pointer equality if the struct contains member pointers.
        bool operator==(const DawnComputePipelineFullSubgroups& rhs) const;
    };

    struct DawnEncoderInternalUsageDescriptor : ChainedStruct {
        DawnEncoderInternalUsageDescriptor() {
            sType = wgpu::SType::DawnEncoderInternalUsageDescriptor;
        }
        alignas(wgpu::DawnEncoderInternalUsageDescriptor::kFirstMemberAlignment) wgpu::Bool useInternalUsages = false;

        // Equality operators, mostly for testing. Note that this tests
        // strict pointer-pointer equality if the struct contains member pointers.
        bool operator==(const DawnEncoderInternalUsageDescriptor& rhs) const;
    };

    struct DawnExperimentalSubgroupLimits : ChainedStructOut {
        DawnExperimentalSubgroupLimits() {
            sType = wgpu::SType::DawnExperimentalSubgroupLimits;
        }
        alignas(wgpu::DawnExperimentalSubgroupLimits::kFirstMemberAlignment) uint32_t minSubgroupSize = WGPU_LIMIT_U32_UNDEFINED;
        uint32_t maxSubgroupSize = WGPU_LIMIT_U32_UNDEFINED;

        // Equality operators, mostly for testing. Note that this tests
        // strict pointer-pointer equality if the struct contains member pointers.
        bool operator==(const DawnExperimentalSubgroupLimits& rhs) const;
    };

    struct DawnMultisampleStateRenderToSingleSampled : ChainedStruct {
        DawnMultisampleStateRenderToSingleSampled() {
            sType = wgpu::SType::DawnMultisampleStateRenderToSingleSampled;
        }
        alignas(wgpu::DawnMultisampleStateRenderToSingleSampled::kFirstMemberAlignment) wgpu::Bool enabled = false;

        // Equality operators, mostly for testing. Note that this tests
        // strict pointer-pointer equality if the struct contains member pointers.
        bool operator==(const DawnMultisampleStateRenderToSingleSampled& rhs) const;
    };

    struct DawnRenderPassColorAttachmentRenderToSingleSampled : ChainedStruct {
        DawnRenderPassColorAttachmentRenderToSingleSampled() {
            sType = wgpu::SType::DawnRenderPassColorAttachmentRenderToSingleSampled;
        }
        alignas(wgpu::DawnRenderPassColorAttachmentRenderToSingleSampled::kFirstMemberAlignment) uint32_t implicitSampleCount = 1;

        // Equality operators, mostly for testing. Note that this tests
        // strict pointer-pointer equality if the struct contains member pointers.
        bool operator==(const DawnRenderPassColorAttachmentRenderToSingleSampled& rhs) const;
    };

    struct DawnShaderModuleSPIRVOptionsDescriptor : ChainedStruct {
        DawnShaderModuleSPIRVOptionsDescriptor() {
            sType = wgpu::SType::DawnShaderModuleSPIRVOptionsDescriptor;
        }
        alignas(wgpu::DawnShaderModuleSPIRVOptionsDescriptor::kFirstMemberAlignment) wgpu::Bool allowNonUniformDerivatives = false;

        // Equality operators, mostly for testing. Note that this tests
        // strict pointer-pointer equality if the struct contains member pointers.
        bool operator==(const DawnShaderModuleSPIRVOptionsDescriptor& rhs) const;
    };

    struct DawnTextureInternalUsageDescriptor : ChainedStruct {
        DawnTextureInternalUsageDescriptor() {
            sType = wgpu::SType::DawnTextureInternalUsageDescriptor;
        }
        alignas(wgpu::DawnTextureInternalUsageDescriptor::kFirstMemberAlignment) wgpu::TextureUsage internalUsage = wgpu::TextureUsage::None;

        // Equality operators, mostly for testing. Note that this tests
        // strict pointer-pointer equality if the struct contains member pointers.
        bool operator==(const DawnTextureInternalUsageDescriptor& rhs) const;
    };

    struct DawnTogglesDescriptor : ChainedStruct {
        DawnTogglesDescriptor() {
            sType = wgpu::SType::DawnTogglesDescriptor;
        }
        alignas(wgpu::DawnTogglesDescriptor::kFirstMemberAlignment) size_t enabledToggleCount = 0;
        const char* const * enabledToggles;
        size_t disabledToggleCount = 0;
        const char* const * disabledToggles;

        // Equality operators, mostly for testing. Note that this tests
        // strict pointer-pointer equality if the struct contains member pointers.
        bool operator==(const DawnTogglesDescriptor& rhs) const;
    };

    struct DawnWireWGSLControl : ChainedStruct {
        DawnWireWGSLControl() {
            sType = wgpu::SType::DawnWireWGSLControl;
        }
        alignas(wgpu::DawnWireWGSLControl::kFirstMemberAlignment) wgpu::Bool enableExperimental = false;
        wgpu::Bool enableUnsafe = false;
        wgpu::Bool enableTesting = false;

        // Equality operators, mostly for testing. Note that this tests
        // strict pointer-pointer equality if the struct contains member pointers.
        bool operator==(const DawnWireWGSLControl& rhs) const;
    };

    struct DepthStencilStateDepthWriteDefinedDawn : ChainedStruct {
        DepthStencilStateDepthWriteDefinedDawn() {
            sType = wgpu::SType::DepthStencilStateDepthWriteDefinedDawn;
        }
        alignas(wgpu::DepthStencilStateDepthWriteDefinedDawn::kFirstMemberAlignment) wgpu::Bool depthWriteDefined;

        // Equality operators, mostly for testing. Note that this tests
        // strict pointer-pointer equality if the struct contains member pointers.
        bool operator==(const DepthStencilStateDepthWriteDefinedDawn& rhs) const;
    };

    struct DeviceLostCallbackInfo {
        ChainedStruct const * nextInChain = nullptr;
        wgpu::CallbackMode mode = wgpu::CallbackMode::WaitAnyOnly;
        WGPUDeviceLostCallbackNew callback = nullptr;
        void * userdata = nullptr;

        // Equality operators, mostly for testing. Note that this tests
        // strict pointer-pointer equality if the struct contains member pointers.
        bool operator==(const DeviceLostCallbackInfo& rhs) const;
    };

    struct DrmFormatProperties {
        uint64_t modifier;
        uint32_t modifierPlaneCount;

        // Equality operators, mostly for testing. Note that this tests
        // strict pointer-pointer equality if the struct contains member pointers.
        bool operator==(const DrmFormatProperties& rhs) const;
    };

    struct Extent2D {
        uint32_t width;
        uint32_t height;

        // Equality operators, mostly for testing. Note that this tests
        // strict pointer-pointer equality if the struct contains member pointers.
        bool operator==(const Extent2D& rhs) const;
    };

    struct Extent3D {
        uint32_t width;
        uint32_t height = 1;
        uint32_t depthOrArrayLayers = 1;

        // Equality operators, mostly for testing. Note that this tests
        // strict pointer-pointer equality if the struct contains member pointers.
        bool operator==(const Extent3D& rhs) const;
    };

    struct ExternalTextureBindingEntry : ChainedStruct {
        ExternalTextureBindingEntry() {
            sType = wgpu::SType::ExternalTextureBindingEntry;
        }
        alignas(wgpu::ExternalTextureBindingEntry::kFirstMemberAlignment) ExternalTextureBase* externalTexture;

        // Equality operators, mostly for testing. Note that this tests
        // strict pointer-pointer equality if the struct contains member pointers.
        bool operator==(const ExternalTextureBindingEntry& rhs) const;
    };

    struct ExternalTextureBindingLayout : ChainedStruct {
        ExternalTextureBindingLayout() {
            sType = wgpu::SType::ExternalTextureBindingLayout;
        }

        // Equality operators, mostly for testing. Note that this tests
        // strict pointer-pointer equality if the struct contains member pointers.
        bool operator==(const ExternalTextureBindingLayout& rhs) const;
    };

    struct FormatCapabilities {
        ChainedStructOut * nextInChain = nullptr;

        // Equality operators, mostly for testing. Note that this tests
        // strict pointer-pointer equality if the struct contains member pointers.
        bool operator==(const FormatCapabilities& rhs) const;
    };

    struct Future {
        uint64_t id;

        // Equality operators, mostly for testing. Note that this tests
        // strict pointer-pointer equality if the struct contains member pointers.
        bool operator==(const Future& rhs) const;
    };

    struct InstanceFeatures {
        ChainedStruct const * nextInChain = nullptr;
        wgpu::Bool timedWaitAnyEnable = false;
        size_t timedWaitAnyMaxCount = 0;

        // Equality operators, mostly for testing. Note that this tests
        // strict pointer-pointer equality if the struct contains member pointers.
        bool operator==(const InstanceFeatures& rhs) const;
    };

    struct Limits {
        uint32_t maxTextureDimension1D = WGPU_LIMIT_U32_UNDEFINED;
        uint32_t maxTextureDimension2D = WGPU_LIMIT_U32_UNDEFINED;
        uint32_t maxTextureDimension3D = WGPU_LIMIT_U32_UNDEFINED;
        uint32_t maxTextureArrayLayers = WGPU_LIMIT_U32_UNDEFINED;
        uint32_t maxBindGroups = WGPU_LIMIT_U32_UNDEFINED;
        uint32_t maxBindGroupsPlusVertexBuffers = WGPU_LIMIT_U32_UNDEFINED;
        uint32_t maxBindingsPerBindGroup = WGPU_LIMIT_U32_UNDEFINED;
        uint32_t maxDynamicUniformBuffersPerPipelineLayout = WGPU_LIMIT_U32_UNDEFINED;
        uint32_t maxDynamicStorageBuffersPerPipelineLayout = WGPU_LIMIT_U32_UNDEFINED;
        uint32_t maxSampledTexturesPerShaderStage = WGPU_LIMIT_U32_UNDEFINED;
        uint32_t maxSamplersPerShaderStage = WGPU_LIMIT_U32_UNDEFINED;
        uint32_t maxStorageBuffersPerShaderStage = WGPU_LIMIT_U32_UNDEFINED;
        uint32_t maxStorageTexturesPerShaderStage = WGPU_LIMIT_U32_UNDEFINED;
        uint32_t maxUniformBuffersPerShaderStage = WGPU_LIMIT_U32_UNDEFINED;
        uint64_t maxUniformBufferBindingSize = WGPU_LIMIT_U64_UNDEFINED;
        uint64_t maxStorageBufferBindingSize = WGPU_LIMIT_U64_UNDEFINED;
        uint32_t minUniformBufferOffsetAlignment = WGPU_LIMIT_U32_UNDEFINED;
        uint32_t minStorageBufferOffsetAlignment = WGPU_LIMIT_U32_UNDEFINED;
        uint32_t maxVertexBuffers = WGPU_LIMIT_U32_UNDEFINED;
        uint64_t maxBufferSize = WGPU_LIMIT_U64_UNDEFINED;
        uint32_t maxVertexAttributes = WGPU_LIMIT_U32_UNDEFINED;
        uint32_t maxVertexBufferArrayStride = WGPU_LIMIT_U32_UNDEFINED;
        uint32_t maxInterStageShaderComponents = WGPU_LIMIT_U32_UNDEFINED;
        uint32_t maxInterStageShaderVariables = WGPU_LIMIT_U32_UNDEFINED;
        uint32_t maxColorAttachments = WGPU_LIMIT_U32_UNDEFINED;
        uint32_t maxColorAttachmentBytesPerSample = WGPU_LIMIT_U32_UNDEFINED;
        uint32_t maxComputeWorkgroupStorageSize = WGPU_LIMIT_U32_UNDEFINED;
        uint32_t maxComputeInvocationsPerWorkgroup = WGPU_LIMIT_U32_UNDEFINED;
        uint32_t maxComputeWorkgroupSizeX = WGPU_LIMIT_U32_UNDEFINED;
        uint32_t maxComputeWorkgroupSizeY = WGPU_LIMIT_U32_UNDEFINED;
        uint32_t maxComputeWorkgroupSizeZ = WGPU_LIMIT_U32_UNDEFINED;
        uint32_t maxComputeWorkgroupsPerDimension = WGPU_LIMIT_U32_UNDEFINED;

        // Equality operators, mostly for testing. Note that this tests
        // strict pointer-pointer equality if the struct contains member pointers.
        bool operator==(const Limits& rhs) const;
    };

    struct MemoryHeapInfo {
        wgpu::HeapProperty properties;
        uint64_t size;

        // Equality operators, mostly for testing. Note that this tests
        // strict pointer-pointer equality if the struct contains member pointers.
        bool operator==(const MemoryHeapInfo& rhs) const;
    };

    struct MultisampleState {
        ChainedStruct const * nextInChain = nullptr;
        uint32_t count = 1;
        uint32_t mask = 0xFFFFFFFF;
        wgpu::Bool alphaToCoverageEnabled = false;

        // Equality operators, mostly for testing. Note that this tests
        // strict pointer-pointer equality if the struct contains member pointers.
        bool operator==(const MultisampleState& rhs) const;
    };

    struct Origin2D {
        uint32_t x = 0;
        uint32_t y = 0;

        // Equality operators, mostly for testing. Note that this tests
        // strict pointer-pointer equality if the struct contains member pointers.
        bool operator==(const Origin2D& rhs) const;
    };

    struct Origin3D {
        uint32_t x = 0;
        uint32_t y = 0;
        uint32_t z = 0;

        // Equality operators, mostly for testing. Note that this tests
        // strict pointer-pointer equality if the struct contains member pointers.
        bool operator==(const Origin3D& rhs) const;
    };

    struct PipelineLayoutDescriptor {
        ChainedStruct const * nextInChain = nullptr;
        char const * label = nullptr;
        size_t bindGroupLayoutCount;
        BindGroupLayoutBase* const * bindGroupLayouts;

        // Equality operators, mostly for testing. Note that this tests
        // strict pointer-pointer equality if the struct contains member pointers.
        bool operator==(const PipelineLayoutDescriptor& rhs) const;
    };

    struct PipelineLayoutStorageAttachment {
        ChainedStruct const * nextInChain = nullptr;
        uint64_t offset = 0;
        wgpu::TextureFormat format;

        // Equality operators, mostly for testing. Note that this tests
        // strict pointer-pointer equality if the struct contains member pointers.
        bool operator==(const PipelineLayoutStorageAttachment& rhs) const;
    };

    struct PopErrorScopeCallbackInfo {
        ChainedStruct const * nextInChain = nullptr;
        wgpu::CallbackMode mode = wgpu::CallbackMode::WaitAnyOnly;
        WGPUPopErrorScopeCallback callback;
        WGPUErrorCallback oldCallback;
        void * userdata = nullptr;

        // Equality operators, mostly for testing. Note that this tests
        // strict pointer-pointer equality if the struct contains member pointers.
        bool operator==(const PopErrorScopeCallbackInfo& rhs) const;
    };

    struct PrimitiveDepthClipControl : ChainedStruct {
        PrimitiveDepthClipControl() {
            sType = wgpu::SType::PrimitiveDepthClipControl;
        }
        alignas(wgpu::PrimitiveDepthClipControl::kFirstMemberAlignment) wgpu::Bool unclippedDepth = false;

        // Equality operators, mostly for testing. Note that this tests
        // strict pointer-pointer equality if the struct contains member pointers.
        bool operator==(const PrimitiveDepthClipControl& rhs) const;
    };

    struct PrimitiveState {
        ChainedStruct const * nextInChain = nullptr;
        wgpu::PrimitiveTopology topology = wgpu::PrimitiveTopology::TriangleList;
        wgpu::IndexFormat stripIndexFormat = wgpu::IndexFormat::Undefined;
        wgpu::FrontFace frontFace = wgpu::FrontFace::CCW;
        wgpu::CullMode cullMode = wgpu::CullMode::None;

        // This method makes a copy of the struct, then, for any enum members with trivial
        // defaulting (where something like "Undefined" is replaced with a default), applies
        // all of the defaults for the struct, and recursively its by-value substructs (but
        // NOT by-pointer substructs since they are const*). It must be called in an
        // appropriate place in Dawn.
        [[nodiscard]] PrimitiveState WithTrivialFrontendDefaults() const;
        // Equality operators, mostly for testing. Note that this tests
        // strict pointer-pointer equality if the struct contains member pointers.
        bool operator==(const PrimitiveState& rhs) const;
    };

    struct QuerySetDescriptor {
        ChainedStruct const * nextInChain = nullptr;
        char const * label = nullptr;
        wgpu::QueryType type;
        uint32_t count;

        // Equality operators, mostly for testing. Note that this tests
        // strict pointer-pointer equality if the struct contains member pointers.
        bool operator==(const QuerySetDescriptor& rhs) const;
    };

    struct QueueDescriptor {
        ChainedStruct const * nextInChain = nullptr;
        char const * label = nullptr;

        // Equality operators, mostly for testing. Note that this tests
        // strict pointer-pointer equality if the struct contains member pointers.
        bool operator==(const QueueDescriptor& rhs) const;
    };

    struct QueueWorkDoneCallbackInfo {
        ChainedStruct const * nextInChain = nullptr;
        wgpu::CallbackMode mode;
        WGPUQueueWorkDoneCallback callback;
        void * userdata;

        // Equality operators, mostly for testing. Note that this tests
        // strict pointer-pointer equality if the struct contains member pointers.
        bool operator==(const QueueWorkDoneCallbackInfo& rhs) const;
    };

    struct RenderBundleDescriptor {
        ChainedStruct const * nextInChain = nullptr;
        char const * label = nullptr;

        // Equality operators, mostly for testing. Note that this tests
        // strict pointer-pointer equality if the struct contains member pointers.
        bool operator==(const RenderBundleDescriptor& rhs) const;
    };

    struct RenderBundleEncoderDescriptor {
        ChainedStruct const * nextInChain = nullptr;
        char const * label = nullptr;
        size_t colorFormatCount;
        wgpu::TextureFormat const * colorFormats;
        wgpu::TextureFormat depthStencilFormat = wgpu::TextureFormat::Undefined;
        uint32_t sampleCount = 1;
        wgpu::Bool depthReadOnly = false;
        wgpu::Bool stencilReadOnly = false;

        // Equality operators, mostly for testing. Note that this tests
        // strict pointer-pointer equality if the struct contains member pointers.
        bool operator==(const RenderBundleEncoderDescriptor& rhs) const;
    };

    struct RenderPassDepthStencilAttachment {
        TextureViewBase* view;
        wgpu::LoadOp depthLoadOp = wgpu::LoadOp::Undefined;
        wgpu::StoreOp depthStoreOp = wgpu::StoreOp::Undefined;
        float depthClearValue = NAN;
        wgpu::Bool depthReadOnly = false;
        wgpu::LoadOp stencilLoadOp = wgpu::LoadOp::Undefined;
        wgpu::StoreOp stencilStoreOp = wgpu::StoreOp::Undefined;
        uint32_t stencilClearValue = 0;
        wgpu::Bool stencilReadOnly = false;

        // Equality operators, mostly for testing. Note that this tests
        // strict pointer-pointer equality if the struct contains member pointers.
        bool operator==(const RenderPassDepthStencilAttachment& rhs) const;
    };

    struct RenderPassDescriptorMaxDrawCount : ChainedStruct {
        RenderPassDescriptorMaxDrawCount() {
            sType = wgpu::SType::RenderPassDescriptorMaxDrawCount;
        }
        alignas(wgpu::RenderPassDescriptorMaxDrawCount::kFirstMemberAlignment) uint64_t maxDrawCount = 50000000;

        // Equality operators, mostly for testing. Note that this tests
        // strict pointer-pointer equality if the struct contains member pointers.
        bool operator==(const RenderPassDescriptorMaxDrawCount& rhs) const;
    };

    struct RenderPassTimestampWrites {
        QuerySetBase* querySet;
        uint32_t beginningOfPassWriteIndex = WGPU_QUERY_SET_INDEX_UNDEFINED;
        uint32_t endOfPassWriteIndex = WGPU_QUERY_SET_INDEX_UNDEFINED;

        // Equality operators, mostly for testing. Note that this tests
        // strict pointer-pointer equality if the struct contains member pointers.
        bool operator==(const RenderPassTimestampWrites& rhs) const;
    };

    struct RequestAdapterCallbackInfo {
        ChainedStruct const * nextInChain = nullptr;
        wgpu::CallbackMode mode;
        WGPURequestAdapterCallback callback;
        void * userdata;

        // Equality operators, mostly for testing. Note that this tests
        // strict pointer-pointer equality if the struct contains member pointers.
        bool operator==(const RequestAdapterCallbackInfo& rhs) const;
    };

    struct RequestAdapterOptions {
        ChainedStruct const * nextInChain = nullptr;
        SurfaceBase* compatibleSurface = nullptr;
        wgpu::PowerPreference powerPreference = wgpu::PowerPreference::Undefined;
        wgpu::BackendType backendType = wgpu::BackendType::Undefined;
        wgpu::Bool forceFallbackAdapter = false;
        wgpu::Bool compatibilityMode = false;

        // Equality operators, mostly for testing. Note that this tests
        // strict pointer-pointer equality if the struct contains member pointers.
        bool operator==(const RequestAdapterOptions& rhs) const;
    };

    struct RequestDeviceCallbackInfo {
        ChainedStruct const * nextInChain = nullptr;
        wgpu::CallbackMode mode;
        WGPURequestDeviceCallback callback;
        void * userdata;

        // Equality operators, mostly for testing. Note that this tests
        // strict pointer-pointer equality if the struct contains member pointers.
        bool operator==(const RequestDeviceCallbackInfo& rhs) const;
    };

    struct SamplerBindingLayout {
        ChainedStruct const * nextInChain = nullptr;
        wgpu::SamplerBindingType type = wgpu::SamplerBindingType::Undefined;

        // Equality operators, mostly for testing. Note that this tests
        // strict pointer-pointer equality if the struct contains member pointers.
        bool operator==(const SamplerBindingLayout& rhs) const;
    };

    struct SamplerDescriptor {
        ChainedStruct const * nextInChain = nullptr;
        char const * label = nullptr;
        wgpu::AddressMode addressModeU = wgpu::AddressMode::ClampToEdge;
        wgpu::AddressMode addressModeV = wgpu::AddressMode::ClampToEdge;
        wgpu::AddressMode addressModeW = wgpu::AddressMode::ClampToEdge;
        wgpu::FilterMode magFilter = wgpu::FilterMode::Nearest;
        wgpu::FilterMode minFilter = wgpu::FilterMode::Nearest;
        wgpu::MipmapFilterMode mipmapFilter = wgpu::MipmapFilterMode::Nearest;
        float lodMinClamp = 0.0f;
        float lodMaxClamp = 32.0f;
        wgpu::CompareFunction compare = wgpu::CompareFunction::Undefined;
        uint16_t maxAnisotropy = 1;

        // This method makes a copy of the struct, then, for any enum members with trivial
        // defaulting (where something like "Undefined" is replaced with a default), applies
        // all of the defaults for the struct, and recursively its by-value substructs (but
        // NOT by-pointer substructs since they are const*). It must be called in an
        // appropriate place in Dawn.
        [[nodiscard]] SamplerDescriptor WithTrivialFrontendDefaults() const;
        // Equality operators, mostly for testing. Note that this tests
        // strict pointer-pointer equality if the struct contains member pointers.
        bool operator==(const SamplerDescriptor& rhs) const;
    };

    struct ShaderModuleSPIRVDescriptor : ChainedStruct {
        ShaderModuleSPIRVDescriptor() {
            sType = wgpu::SType::ShaderModuleSPIRVDescriptor;
        }
        alignas(wgpu::ShaderModuleSPIRVDescriptor::kFirstMemberAlignment) uint32_t codeSize;
        uint32_t const * code;

        // Equality operators, mostly for testing. Note that this tests
        // strict pointer-pointer equality if the struct contains member pointers.
        bool operator==(const ShaderModuleSPIRVDescriptor& rhs) const;
    };

    struct ShaderModuleWGSLDescriptor : ChainedStruct {
        ShaderModuleWGSLDescriptor() {
            sType = wgpu::SType::ShaderModuleWGSLDescriptor;
        }
        alignas(wgpu::ShaderModuleWGSLDescriptor::kFirstMemberAlignment) char const * code;

        // Equality operators, mostly for testing. Note that this tests
        // strict pointer-pointer equality if the struct contains member pointers.
        bool operator==(const ShaderModuleWGSLDescriptor& rhs) const;
    };

    struct ShaderModuleCompilationOptions : ChainedStruct {
        ShaderModuleCompilationOptions() {
            sType = wgpu::SType::ShaderModuleCompilationOptions;
        }
        alignas(wgpu::ShaderModuleCompilationOptions::kFirstMemberAlignment) wgpu::Bool strictMath;

        // Equality operators, mostly for testing. Note that this tests
        // strict pointer-pointer equality if the struct contains member pointers.
        bool operator==(const ShaderModuleCompilationOptions& rhs) const;
    };

    struct ShaderModuleDescriptor {
        ChainedStruct const * nextInChain = nullptr;
        char const * label = nullptr;

        // Equality operators, mostly for testing. Note that this tests
        // strict pointer-pointer equality if the struct contains member pointers.
        bool operator==(const ShaderModuleDescriptor& rhs) const;
    };

    struct SharedBufferMemoryBeginAccessDescriptor {
        ChainedStruct const * nextInChain = nullptr;
        wgpu::Bool initialized;
        size_t fenceCount = 0;
        SharedFenceBase* const * fences;
        uint64_t const * signaledValues;

        // Equality operators, mostly for testing. Note that this tests
        // strict pointer-pointer equality if the struct contains member pointers.
        bool operator==(const SharedBufferMemoryBeginAccessDescriptor& rhs) const;
    };

    struct SharedBufferMemoryDescriptor {
        ChainedStruct const * nextInChain = nullptr;
        char const * label = nullptr;

        // Equality operators, mostly for testing. Note that this tests
        // strict pointer-pointer equality if the struct contains member pointers.
        bool operator==(const SharedBufferMemoryDescriptor& rhs) const;
    };

    struct SharedBufferMemoryEndAccessState {
        SharedBufferMemoryEndAccessState() = default;
        ~SharedBufferMemoryEndAccessState();
        SharedBufferMemoryEndAccessState(const SharedBufferMemoryEndAccessState&) = delete;
        SharedBufferMemoryEndAccessState& operator=(const SharedBufferMemoryEndAccessState&) = delete;
        SharedBufferMemoryEndAccessState(SharedBufferMemoryEndAccessState&&);
        SharedBufferMemoryEndAccessState& operator=(SharedBufferMemoryEndAccessState&&);

        ChainedStructOut * nextInChain = nullptr;
        wgpu::Bool initialized;
        size_t fenceCount = 0;
        SharedFenceBase* const * fences;
        uint64_t const * signaledValues;

        // Equality operators, mostly for testing. Note that this tests
        // strict pointer-pointer equality if the struct contains member pointers.
        bool operator==(const SharedBufferMemoryEndAccessState& rhs) const;
    };

    struct SharedBufferMemoryProperties {
        ChainedStructOut * nextInChain = nullptr;
        wgpu::BufferUsage usage;
        uint64_t size;

        // Equality operators, mostly for testing. Note that this tests
        // strict pointer-pointer equality if the struct contains member pointers.
        bool operator==(const SharedBufferMemoryProperties& rhs) const;
    };

    struct SharedFenceDXGISharedHandleDescriptor : ChainedStruct {
        SharedFenceDXGISharedHandleDescriptor() {
            sType = wgpu::SType::SharedFenceDXGISharedHandleDescriptor;
        }
        alignas(wgpu::SharedFenceDXGISharedHandleDescriptor::kFirstMemberAlignment) void * handle;

        // Equality operators, mostly for testing. Note that this tests
        // strict pointer-pointer equality if the struct contains member pointers.
        bool operator==(const SharedFenceDXGISharedHandleDescriptor& rhs) const;
    };

    struct SharedFenceDXGISharedHandleExportInfo : ChainedStructOut {
        SharedFenceDXGISharedHandleExportInfo() {
            sType = wgpu::SType::SharedFenceDXGISharedHandleExportInfo;
        }
        alignas(wgpu::SharedFenceDXGISharedHandleExportInfo::kFirstMemberAlignment) void * handle;

        // Equality operators, mostly for testing. Note that this tests
        // strict pointer-pointer equality if the struct contains member pointers.
        bool operator==(const SharedFenceDXGISharedHandleExportInfo& rhs) const;
    };

    struct SharedFenceMTLSharedEventDescriptor : ChainedStruct {
        SharedFenceMTLSharedEventDescriptor() {
            sType = wgpu::SType::SharedFenceMTLSharedEventDescriptor;
        }
        alignas(wgpu::SharedFenceMTLSharedEventDescriptor::kFirstMemberAlignment) void * sharedEvent;

        // Equality operators, mostly for testing. Note that this tests
        // strict pointer-pointer equality if the struct contains member pointers.
        bool operator==(const SharedFenceMTLSharedEventDescriptor& rhs) const;
    };

    struct SharedFenceMTLSharedEventExportInfo : ChainedStructOut {
        SharedFenceMTLSharedEventExportInfo() {
            sType = wgpu::SType::SharedFenceMTLSharedEventExportInfo;
        }
        alignas(wgpu::SharedFenceMTLSharedEventExportInfo::kFirstMemberAlignment) void * sharedEvent;

        // Equality operators, mostly for testing. Note that this tests
        // strict pointer-pointer equality if the struct contains member pointers.
        bool operator==(const SharedFenceMTLSharedEventExportInfo& rhs) const;
    };

    struct SharedFenceDescriptor {
        ChainedStruct const * nextInChain = nullptr;
        char const * label = nullptr;

        // Equality operators, mostly for testing. Note that this tests
        // strict pointer-pointer equality if the struct contains member pointers.
        bool operator==(const SharedFenceDescriptor& rhs) const;
    };

    struct SharedFenceExportInfo {
        ChainedStructOut * nextInChain = nullptr;
        wgpu::SharedFenceType type;

        // Equality operators, mostly for testing. Note that this tests
        // strict pointer-pointer equality if the struct contains member pointers.
        bool operator==(const SharedFenceExportInfo& rhs) const;
    };

    struct SharedFenceVkSemaphoreOpaqueFDDescriptor : ChainedStruct {
        SharedFenceVkSemaphoreOpaqueFDDescriptor() {
            sType = wgpu::SType::SharedFenceVkSemaphoreOpaqueFDDescriptor;
        }
        alignas(wgpu::SharedFenceVkSemaphoreOpaqueFDDescriptor::kFirstMemberAlignment) int handle;

        // Equality operators, mostly for testing. Note that this tests
        // strict pointer-pointer equality if the struct contains member pointers.
        bool operator==(const SharedFenceVkSemaphoreOpaqueFDDescriptor& rhs) const;
    };

    struct SharedFenceVkSemaphoreOpaqueFDExportInfo : ChainedStructOut {
        SharedFenceVkSemaphoreOpaqueFDExportInfo() {
            sType = wgpu::SType::SharedFenceVkSemaphoreOpaqueFDExportInfo;
        }
        alignas(wgpu::SharedFenceVkSemaphoreOpaqueFDExportInfo::kFirstMemberAlignment) int handle;

        // Equality operators, mostly for testing. Note that this tests
        // strict pointer-pointer equality if the struct contains member pointers.
        bool operator==(const SharedFenceVkSemaphoreOpaqueFDExportInfo& rhs) const;
    };

    struct SharedFenceVkSemaphoreSyncFDDescriptor : ChainedStruct {
        SharedFenceVkSemaphoreSyncFDDescriptor() {
            sType = wgpu::SType::SharedFenceVkSemaphoreSyncFDDescriptor;
        }
        alignas(wgpu::SharedFenceVkSemaphoreSyncFDDescriptor::kFirstMemberAlignment) int handle;

        // Equality operators, mostly for testing. Note that this tests
        // strict pointer-pointer equality if the struct contains member pointers.
        bool operator==(const SharedFenceVkSemaphoreSyncFDDescriptor& rhs) const;
    };

    struct SharedFenceVkSemaphoreSyncFDExportInfo : ChainedStructOut {
        SharedFenceVkSemaphoreSyncFDExportInfo() {
            sType = wgpu::SType::SharedFenceVkSemaphoreSyncFDExportInfo;
        }
        alignas(wgpu::SharedFenceVkSemaphoreSyncFDExportInfo::kFirstMemberAlignment) int handle;

        // Equality operators, mostly for testing. Note that this tests
        // strict pointer-pointer equality if the struct contains member pointers.
        bool operator==(const SharedFenceVkSemaphoreSyncFDExportInfo& rhs) const;
    };

    struct SharedFenceVkSemaphoreZirconHandleDescriptor : ChainedStruct {
        SharedFenceVkSemaphoreZirconHandleDescriptor() {
            sType = wgpu::SType::SharedFenceVkSemaphoreZirconHandleDescriptor;
        }
        alignas(wgpu::SharedFenceVkSemaphoreZirconHandleDescriptor::kFirstMemberAlignment) uint32_t handle;

        // Equality operators, mostly for testing. Note that this tests
        // strict pointer-pointer equality if the struct contains member pointers.
        bool operator==(const SharedFenceVkSemaphoreZirconHandleDescriptor& rhs) const;
    };

    struct SharedFenceVkSemaphoreZirconHandleExportInfo : ChainedStructOut {
        SharedFenceVkSemaphoreZirconHandleExportInfo() {
            sType = wgpu::SType::SharedFenceVkSemaphoreZirconHandleExportInfo;
        }
        alignas(wgpu::SharedFenceVkSemaphoreZirconHandleExportInfo::kFirstMemberAlignment) uint32_t handle;

        // Equality operators, mostly for testing. Note that this tests
        // strict pointer-pointer equality if the struct contains member pointers.
        bool operator==(const SharedFenceVkSemaphoreZirconHandleExportInfo& rhs) const;
    };

    struct SharedTextureMemoryD3DSwapchainBeginState : ChainedStruct {
        SharedTextureMemoryD3DSwapchainBeginState() {
            sType = wgpu::SType::SharedTextureMemoryD3DSwapchainBeginState;
        }
        alignas(wgpu::SharedTextureMemoryD3DSwapchainBeginState::kFirstMemberAlignment) wgpu::Bool isSwapchain = false;

        // Equality operators, mostly for testing. Note that this tests
        // strict pointer-pointer equality if the struct contains member pointers.
        bool operator==(const SharedTextureMemoryD3DSwapchainBeginState& rhs) const;
    };

    struct SharedTextureMemoryDXGISharedHandleDescriptor : ChainedStruct {
        SharedTextureMemoryDXGISharedHandleDescriptor() {
            sType = wgpu::SType::SharedTextureMemoryDXGISharedHandleDescriptor;
        }
        alignas(wgpu::SharedTextureMemoryDXGISharedHandleDescriptor::kFirstMemberAlignment) void * handle;
        wgpu::Bool useKeyedMutex;

        // Equality operators, mostly for testing. Note that this tests
        // strict pointer-pointer equality if the struct contains member pointers.
        bool operator==(const SharedTextureMemoryDXGISharedHandleDescriptor& rhs) const;
    };

    struct SharedTextureMemoryEGLImageDescriptor : ChainedStruct {
        SharedTextureMemoryEGLImageDescriptor() {
            sType = wgpu::SType::SharedTextureMemoryEGLImageDescriptor;
        }
        alignas(wgpu::SharedTextureMemoryEGLImageDescriptor::kFirstMemberAlignment) void * image;

        // Equality operators, mostly for testing. Note that this tests
        // strict pointer-pointer equality if the struct contains member pointers.
        bool operator==(const SharedTextureMemoryEGLImageDescriptor& rhs) const;
    };

    struct SharedTextureMemoryIOSurfaceDescriptor : ChainedStruct {
        SharedTextureMemoryIOSurfaceDescriptor() {
            sType = wgpu::SType::SharedTextureMemoryIOSurfaceDescriptor;
        }
        alignas(wgpu::SharedTextureMemoryIOSurfaceDescriptor::kFirstMemberAlignment) void * ioSurface;

        // Equality operators, mostly for testing. Note that this tests
        // strict pointer-pointer equality if the struct contains member pointers.
        bool operator==(const SharedTextureMemoryIOSurfaceDescriptor& rhs) const;
    };

    struct SharedTextureMemoryAHardwareBufferDescriptor : ChainedStruct {
        SharedTextureMemoryAHardwareBufferDescriptor() {
            sType = wgpu::SType::SharedTextureMemoryAHardwareBufferDescriptor;
        }
        alignas(wgpu::SharedTextureMemoryAHardwareBufferDescriptor::kFirstMemberAlignment) void * handle;

        // Equality operators, mostly for testing. Note that this tests
        // strict pointer-pointer equality if the struct contains member pointers.
        bool operator==(const SharedTextureMemoryAHardwareBufferDescriptor& rhs) const;
    };

    struct SharedTextureMemoryBeginAccessDescriptor {
        ChainedStruct const * nextInChain = nullptr;
        wgpu::Bool concurrentRead;
        wgpu::Bool initialized;
        size_t fenceCount;
        SharedFenceBase* const * fences;
        uint64_t const * signaledValues;

        // Equality operators, mostly for testing. Note that this tests
        // strict pointer-pointer equality if the struct contains member pointers.
        bool operator==(const SharedTextureMemoryBeginAccessDescriptor& rhs) const;
    };

    struct SharedTextureMemoryDescriptor {
        ChainedStruct const * nextInChain = nullptr;
        char const * label = nullptr;

        // Equality operators, mostly for testing. Note that this tests
        // strict pointer-pointer equality if the struct contains member pointers.
        bool operator==(const SharedTextureMemoryDescriptor& rhs) const;
    };

    struct SharedTextureMemoryDmaBufPlane {
        int fd;
        uint64_t offset;
        uint32_t stride;

        // Equality operators, mostly for testing. Note that this tests
        // strict pointer-pointer equality if the struct contains member pointers.
        bool operator==(const SharedTextureMemoryDmaBufPlane& rhs) const;
    };

    struct SharedTextureMemoryEndAccessState {
        SharedTextureMemoryEndAccessState() = default;
        ~SharedTextureMemoryEndAccessState();
        SharedTextureMemoryEndAccessState(const SharedTextureMemoryEndAccessState&) = delete;
        SharedTextureMemoryEndAccessState& operator=(const SharedTextureMemoryEndAccessState&) = delete;
        SharedTextureMemoryEndAccessState(SharedTextureMemoryEndAccessState&&);
        SharedTextureMemoryEndAccessState& operator=(SharedTextureMemoryEndAccessState&&);

        ChainedStructOut * nextInChain = nullptr;
        wgpu::Bool initialized;
        size_t fenceCount;
        SharedFenceBase* const * fences;
        uint64_t const * signaledValues;

        // Equality operators, mostly for testing. Note that this tests
        // strict pointer-pointer equality if the struct contains member pointers.
        bool operator==(const SharedTextureMemoryEndAccessState& rhs) const;
    };

    struct SharedTextureMemoryOpaqueFDDescriptor : ChainedStruct {
        SharedTextureMemoryOpaqueFDDescriptor() {
            sType = wgpu::SType::SharedTextureMemoryOpaqueFDDescriptor;
        }
        alignas(wgpu::SharedTextureMemoryOpaqueFDDescriptor::kFirstMemberAlignment) void const * vkImageCreateInfo;
        int memoryFD;
        uint32_t memoryTypeIndex;
        uint64_t allocationSize;
        wgpu::Bool dedicatedAllocation;

        // Equality operators, mostly for testing. Note that this tests
        // strict pointer-pointer equality if the struct contains member pointers.
        bool operator==(const SharedTextureMemoryOpaqueFDDescriptor& rhs) const;
    };

    struct SharedTextureMemoryVkDedicatedAllocationDescriptor : ChainedStruct {
        SharedTextureMemoryVkDedicatedAllocationDescriptor() {
            sType = wgpu::SType::SharedTextureMemoryVkDedicatedAllocationDescriptor;
        }
        alignas(wgpu::SharedTextureMemoryVkDedicatedAllocationDescriptor::kFirstMemberAlignment) wgpu::Bool dedicatedAllocation;

        // Equality operators, mostly for testing. Note that this tests
        // strict pointer-pointer equality if the struct contains member pointers.
        bool operator==(const SharedTextureMemoryVkDedicatedAllocationDescriptor& rhs) const;
    };

    struct SharedTextureMemoryVkImageLayoutBeginState : ChainedStruct {
        SharedTextureMemoryVkImageLayoutBeginState() {
            sType = wgpu::SType::SharedTextureMemoryVkImageLayoutBeginState;
        }
        alignas(wgpu::SharedTextureMemoryVkImageLayoutBeginState::kFirstMemberAlignment) int32_t oldLayout;
        int32_t newLayout;

        // Equality operators, mostly for testing. Note that this tests
        // strict pointer-pointer equality if the struct contains member pointers.
        bool operator==(const SharedTextureMemoryVkImageLayoutBeginState& rhs) const;
    };

    struct SharedTextureMemoryVkImageLayoutEndState : ChainedStructOut {
        SharedTextureMemoryVkImageLayoutEndState() {
            sType = wgpu::SType::SharedTextureMemoryVkImageLayoutEndState;
        }
        alignas(wgpu::SharedTextureMemoryVkImageLayoutEndState::kFirstMemberAlignment) int32_t oldLayout;
        int32_t newLayout;

        // Equality operators, mostly for testing. Note that this tests
        // strict pointer-pointer equality if the struct contains member pointers.
        bool operator==(const SharedTextureMemoryVkImageLayoutEndState& rhs) const;
    };

    struct SharedTextureMemoryZirconHandleDescriptor : ChainedStruct {
        SharedTextureMemoryZirconHandleDescriptor() {
            sType = wgpu::SType::SharedTextureMemoryZirconHandleDescriptor;
        }
        alignas(wgpu::SharedTextureMemoryZirconHandleDescriptor::kFirstMemberAlignment) uint32_t memoryFD;
        uint64_t allocationSize;

        // Equality operators, mostly for testing. Note that this tests
        // strict pointer-pointer equality if the struct contains member pointers.
        bool operator==(const SharedTextureMemoryZirconHandleDescriptor& rhs) const;
    };

    struct StaticSamplerBindingLayout : ChainedStruct {
        StaticSamplerBindingLayout() {
            sType = wgpu::SType::StaticSamplerBindingLayout;
        }
        alignas(wgpu::StaticSamplerBindingLayout::kFirstMemberAlignment) SamplerBase* sampler;

        // Equality operators, mostly for testing. Note that this tests
        // strict pointer-pointer equality if the struct contains member pointers.
        bool operator==(const StaticSamplerBindingLayout& rhs) const;
    };

    struct StencilFaceState {
        wgpu::CompareFunction compare = wgpu::CompareFunction::Always;
        wgpu::StencilOperation failOp = wgpu::StencilOperation::Keep;
        wgpu::StencilOperation depthFailOp = wgpu::StencilOperation::Keep;
        wgpu::StencilOperation passOp = wgpu::StencilOperation::Keep;

        // This method makes a copy of the struct, then, for any enum members with trivial
        // defaulting (where something like "Undefined" is replaced with a default), applies
        // all of the defaults for the struct, and recursively its by-value substructs (but
        // NOT by-pointer substructs since they are const*). It must be called in an
        // appropriate place in Dawn.
        [[nodiscard]] StencilFaceState WithTrivialFrontendDefaults() const;
        // Equality operators, mostly for testing. Note that this tests
        // strict pointer-pointer equality if the struct contains member pointers.
        bool operator==(const StencilFaceState& rhs) const;
    };

    struct StorageTextureBindingLayout {
        ChainedStruct const * nextInChain = nullptr;
        wgpu::StorageTextureAccess access = wgpu::StorageTextureAccess::Undefined;
        wgpu::TextureFormat format = wgpu::TextureFormat::Undefined;
        wgpu::TextureViewDimension viewDimension = wgpu::TextureViewDimension::e2D;

        // This method makes a copy of the struct, then, for any enum members with trivial
        // defaulting (where something like "Undefined" is replaced with a default), applies
        // all of the defaults for the struct, and recursively its by-value substructs (but
        // NOT by-pointer substructs since they are const*). It must be called in an
        // appropriate place in Dawn.
        [[nodiscard]] StorageTextureBindingLayout WithTrivialFrontendDefaults() const;
        // Equality operators, mostly for testing. Note that this tests
        // strict pointer-pointer equality if the struct contains member pointers.
        bool operator==(const StorageTextureBindingLayout& rhs) const;
    };

    struct SurfaceCapabilities {
        SurfaceCapabilities() = default;
        ~SurfaceCapabilities();
        SurfaceCapabilities(const SurfaceCapabilities&) = delete;
        SurfaceCapabilities& operator=(const SurfaceCapabilities&) = delete;
        SurfaceCapabilities(SurfaceCapabilities&&);
        SurfaceCapabilities& operator=(SurfaceCapabilities&&);

        ChainedStructOut * nextInChain = nullptr;
        wgpu::TextureUsage usages;
        size_t formatCount;
        wgpu::TextureFormat const * formats;
        size_t presentModeCount;
        wgpu::PresentMode const * presentModes;
        size_t alphaModeCount;
        wgpu::CompositeAlphaMode const * alphaModes;

        // Equality operators, mostly for testing. Note that this tests
        // strict pointer-pointer equality if the struct contains member pointers.
        bool operator==(const SurfaceCapabilities& rhs) const;
    };

    struct SurfaceConfiguration {
        ChainedStruct const * nextInChain = nullptr;
        DeviceBase* device;
        wgpu::TextureFormat format;
        wgpu::TextureUsage usage = wgpu::TextureUsage::RenderAttachment;
        size_t viewFormatCount = 0;
        wgpu::TextureFormat const * viewFormats;
        wgpu::CompositeAlphaMode alphaMode = wgpu::CompositeAlphaMode::Auto;
        uint32_t width;
        uint32_t height;
        wgpu::PresentMode presentMode = wgpu::PresentMode::Fifo;

        // Equality operators, mostly for testing. Note that this tests
        // strict pointer-pointer equality if the struct contains member pointers.
        bool operator==(const SurfaceConfiguration& rhs) const;
    };

    struct SurfaceDescriptor {
        ChainedStruct const * nextInChain = nullptr;
        char const * label = nullptr;

        // Equality operators, mostly for testing. Note that this tests
        // strict pointer-pointer equality if the struct contains member pointers.
        bool operator==(const SurfaceDescriptor& rhs) const;
    };

    struct SurfaceDescriptorFromAndroidNativeWindow : ChainedStruct {
        SurfaceDescriptorFromAndroidNativeWindow() {
            sType = wgpu::SType::SurfaceDescriptorFromAndroidNativeWindow;
        }
        alignas(wgpu::SurfaceDescriptorFromAndroidNativeWindow::kFirstMemberAlignment) void * window;

        // Equality operators, mostly for testing. Note that this tests
        // strict pointer-pointer equality if the struct contains member pointers.
        bool operator==(const SurfaceDescriptorFromAndroidNativeWindow& rhs) const;
    };

    struct SurfaceDescriptorFromCanvasHTMLSelector : ChainedStruct {
        SurfaceDescriptorFromCanvasHTMLSelector() {
            sType = wgpu::SType::SurfaceDescriptorFromCanvasHTMLSelector;
        }
        alignas(wgpu::SurfaceDescriptorFromCanvasHTMLSelector::kFirstMemberAlignment) char const * selector;

        // Equality operators, mostly for testing. Note that this tests
        // strict pointer-pointer equality if the struct contains member pointers.
        bool operator==(const SurfaceDescriptorFromCanvasHTMLSelector& rhs) const;
    };

    struct SurfaceDescriptorFromMetalLayer : ChainedStruct {
        SurfaceDescriptorFromMetalLayer() {
            sType = wgpu::SType::SurfaceDescriptorFromMetalLayer;
        }
        alignas(wgpu::SurfaceDescriptorFromMetalLayer::kFirstMemberAlignment) void * layer;

        // Equality operators, mostly for testing. Note that this tests
        // strict pointer-pointer equality if the struct contains member pointers.
        bool operator==(const SurfaceDescriptorFromMetalLayer& rhs) const;
    };

    struct SurfaceDescriptorFromWaylandSurface : ChainedStruct {
        SurfaceDescriptorFromWaylandSurface() {
            sType = wgpu::SType::SurfaceDescriptorFromWaylandSurface;
        }
        alignas(wgpu::SurfaceDescriptorFromWaylandSurface::kFirstMemberAlignment) void * display;
        void * surface;

        // Equality operators, mostly for testing. Note that this tests
        // strict pointer-pointer equality if the struct contains member pointers.
        bool operator==(const SurfaceDescriptorFromWaylandSurface& rhs) const;
    };

    struct SurfaceDescriptorFromWindowsHWND : ChainedStruct {
        SurfaceDescriptorFromWindowsHWND() {
            sType = wgpu::SType::SurfaceDescriptorFromWindowsHWND;
        }
        alignas(wgpu::SurfaceDescriptorFromWindowsHWND::kFirstMemberAlignment) void * hinstance;
        void * hwnd;

        // Equality operators, mostly for testing. Note that this tests
        // strict pointer-pointer equality if the struct contains member pointers.
        bool operator==(const SurfaceDescriptorFromWindowsHWND& rhs) const;
    };

    struct SurfaceDescriptorFromWindowsCoreWindow : ChainedStruct {
        SurfaceDescriptorFromWindowsCoreWindow() {
            sType = wgpu::SType::SurfaceDescriptorFromWindowsCoreWindow;
        }
        alignas(wgpu::SurfaceDescriptorFromWindowsCoreWindow::kFirstMemberAlignment) void * coreWindow;

        // Equality operators, mostly for testing. Note that this tests
        // strict pointer-pointer equality if the struct contains member pointers.
        bool operator==(const SurfaceDescriptorFromWindowsCoreWindow& rhs) const;
    };

    struct SurfaceDescriptorFromWindowsSwapChainPanel : ChainedStruct {
        SurfaceDescriptorFromWindowsSwapChainPanel() {
            sType = wgpu::SType::SurfaceDescriptorFromWindowsSwapChainPanel;
        }
        alignas(wgpu::SurfaceDescriptorFromWindowsSwapChainPanel::kFirstMemberAlignment) void * swapChainPanel;

        // Equality operators, mostly for testing. Note that this tests
        // strict pointer-pointer equality if the struct contains member pointers.
        bool operator==(const SurfaceDescriptorFromWindowsSwapChainPanel& rhs) const;
    };

    struct SurfaceDescriptorFromXlibWindow : ChainedStruct {
        SurfaceDescriptorFromXlibWindow() {
            sType = wgpu::SType::SurfaceDescriptorFromXlibWindow;
        }
        alignas(wgpu::SurfaceDescriptorFromXlibWindow::kFirstMemberAlignment) void * display;
        uint64_t window;

        // Equality operators, mostly for testing. Note that this tests
        // strict pointer-pointer equality if the struct contains member pointers.
        bool operator==(const SurfaceDescriptorFromXlibWindow& rhs) const;
    };

    struct SurfaceTexture {
        TextureBase* texture;
        wgpu::Bool suboptimal;
        wgpu::SurfaceGetCurrentTextureStatus status;

        // Equality operators, mostly for testing. Note that this tests
        // strict pointer-pointer equality if the struct contains member pointers.
        bool operator==(const SurfaceTexture& rhs) const;
    };

    struct SwapChainDescriptor {
        ChainedStruct const * nextInChain = nullptr;
        char const * label = nullptr;
        wgpu::TextureUsage usage;
        wgpu::TextureFormat format;
        uint32_t width;
        uint32_t height;
        wgpu::PresentMode presentMode;

        // Equality operators, mostly for testing. Note that this tests
        // strict pointer-pointer equality if the struct contains member pointers.
        bool operator==(const SwapChainDescriptor& rhs) const;
    };

    struct TextureBindingLayout {
        ChainedStruct const * nextInChain = nullptr;
        wgpu::TextureSampleType sampleType = wgpu::TextureSampleType::Undefined;
        wgpu::TextureViewDimension viewDimension = wgpu::TextureViewDimension::e2D;
        wgpu::Bool multisampled = false;

        // This method makes a copy of the struct, then, for any enum members with trivial
        // defaulting (where something like "Undefined" is replaced with a default), applies
        // all of the defaults for the struct, and recursively its by-value substructs (but
        // NOT by-pointer substructs since they are const*). It must be called in an
        // appropriate place in Dawn.
        [[nodiscard]] TextureBindingLayout WithTrivialFrontendDefaults() const;
        // Equality operators, mostly for testing. Note that this tests
        // strict pointer-pointer equality if the struct contains member pointers.
        bool operator==(const TextureBindingLayout& rhs) const;
    };

    struct TextureBindingViewDimensionDescriptor : ChainedStruct {
        TextureBindingViewDimensionDescriptor() {
            sType = wgpu::SType::TextureBindingViewDimensionDescriptor;
        }
        alignas(wgpu::TextureBindingViewDimensionDescriptor::kFirstMemberAlignment) wgpu::TextureViewDimension textureBindingViewDimension = wgpu::TextureViewDimension::Undefined;

        // Equality operators, mostly for testing. Note that this tests
        // strict pointer-pointer equality if the struct contains member pointers.
        bool operator==(const TextureBindingViewDimensionDescriptor& rhs) const;
    };

    struct TextureDataLayout {
        ChainedStruct const * nextInChain = nullptr;
        uint64_t offset = 0;
        uint32_t bytesPerRow = WGPU_COPY_STRIDE_UNDEFINED;
        uint32_t rowsPerImage = WGPU_COPY_STRIDE_UNDEFINED;

        // Equality operators, mostly for testing. Note that this tests
        // strict pointer-pointer equality if the struct contains member pointers.
        bool operator==(const TextureDataLayout& rhs) const;
    };

    struct TextureViewDescriptor {
        ChainedStruct const * nextInChain = nullptr;
        char const * label = nullptr;
        wgpu::TextureFormat format = wgpu::TextureFormat::Undefined;
        wgpu::TextureViewDimension dimension = wgpu::TextureViewDimension::Undefined;
        uint32_t baseMipLevel = 0;
        uint32_t mipLevelCount = WGPU_MIP_LEVEL_COUNT_UNDEFINED;
        uint32_t baseArrayLayer = 0;
        uint32_t arrayLayerCount = WGPU_ARRAY_LAYER_COUNT_UNDEFINED;
        wgpu::TextureAspect aspect = wgpu::TextureAspect::All;

        // This method makes a copy of the struct, then, for any enum members with trivial
        // defaulting (where something like "Undefined" is replaced with a default), applies
        // all of the defaults for the struct, and recursively its by-value substructs (but
        // NOT by-pointer substructs since they are const*). It must be called in an
        // appropriate place in Dawn.
        [[nodiscard]] TextureViewDescriptor WithTrivialFrontendDefaults() const;
        // Equality operators, mostly for testing. Note that this tests
        // strict pointer-pointer equality if the struct contains member pointers.
        bool operator==(const TextureViewDescriptor& rhs) const;
    };

    struct UncapturedErrorCallbackInfo {
        ChainedStruct const * nextInChain = nullptr;
        WGPUErrorCallback callback = nullptr;
        void * userdata = nullptr;

        // Equality operators, mostly for testing. Note that this tests
        // strict pointer-pointer equality if the struct contains member pointers.
        bool operator==(const UncapturedErrorCallbackInfo& rhs) const;
    };

    struct VertexAttribute {
        wgpu::VertexFormat format;
        uint64_t offset;
        uint32_t shaderLocation;

        // Equality operators, mostly for testing. Note that this tests
        // strict pointer-pointer equality if the struct contains member pointers.
        bool operator==(const VertexAttribute& rhs) const;
    };

    struct YCbCrVkDescriptor : ChainedStruct {
        YCbCrVkDescriptor() {
            sType = wgpu::SType::YCbCrVkDescriptor;
        }
        alignas(wgpu::YCbCrVkDescriptor::kFirstMemberAlignment) uint32_t vkFormat = 0;
        uint32_t vkYCbCrModel = 0;
        uint32_t vkYCbCrRange = 0;
        uint32_t vkComponentSwizzleRed = 0;
        uint32_t vkComponentSwizzleGreen = 0;
        uint32_t vkComponentSwizzleBlue = 0;
        uint32_t vkComponentSwizzleAlpha = 0;
        uint32_t vkXChromaOffset = 0;
        uint32_t vkYChromaOffset = 0;
        wgpu::FilterMode vkChromaFilter = wgpu::FilterMode::Nearest;
        wgpu::Bool forceExplicitReconstruction = false;
        uint64_t externalFormat = 0;

        // This method makes a copy of the struct, then, for any enum members with trivial
        // defaulting (where something like "Undefined" is replaced with a default), applies
        // all of the defaults for the struct, and recursively its by-value substructs (but
        // NOT by-pointer substructs since they are const*). It must be called in an
        // appropriate place in Dawn.
        [[nodiscard]] YCbCrVkDescriptor WithTrivialFrontendDefaults() const;
        // Equality operators, mostly for testing. Note that this tests
        // strict pointer-pointer equality if the struct contains member pointers.
        bool operator==(const YCbCrVkDescriptor& rhs) const;
    };

    struct AHardwareBufferProperties {
        YCbCrVkDescriptor yCbCrInfo;

        // This method makes a copy of the struct, then, for any enum members with trivial
        // defaulting (where something like "Undefined" is replaced with a default), applies
        // all of the defaults for the struct, and recursively its by-value substructs (but
        // NOT by-pointer substructs since they are const*). It must be called in an
        // appropriate place in Dawn.
        [[nodiscard]] AHardwareBufferProperties WithTrivialFrontendDefaults() const;
        // Equality operators, mostly for testing. Note that this tests
        // strict pointer-pointer equality if the struct contains member pointers.
        bool operator==(const AHardwareBufferProperties& rhs) const;
    };

    struct AdapterPropertiesMemoryHeaps : ChainedStructOut {
        AdapterPropertiesMemoryHeaps() {
            sType = wgpu::SType::AdapterPropertiesMemoryHeaps;
        }
        ~AdapterPropertiesMemoryHeaps();
        AdapterPropertiesMemoryHeaps(const AdapterPropertiesMemoryHeaps&) = delete;
        AdapterPropertiesMemoryHeaps& operator=(const AdapterPropertiesMemoryHeaps&) = delete;
        AdapterPropertiesMemoryHeaps(AdapterPropertiesMemoryHeaps&&);
        AdapterPropertiesMemoryHeaps& operator=(AdapterPropertiesMemoryHeaps&&);

        alignas(wgpu::AdapterPropertiesMemoryHeaps::kFirstMemberAlignment) size_t heapCount;
        MemoryHeapInfo const * heapInfo;

        // Equality operators, mostly for testing. Note that this tests
        // strict pointer-pointer equality if the struct contains member pointers.
        bool operator==(const AdapterPropertiesMemoryHeaps& rhs) const;
    };

    struct BindGroupDescriptor {
        ChainedStruct const * nextInChain = nullptr;
        char const * label = nullptr;
        BindGroupLayoutBase* layout;
        size_t entryCount;
        BindGroupEntry const * entries;

        // Equality operators, mostly for testing. Note that this tests
        // strict pointer-pointer equality if the struct contains member pointers.
        bool operator==(const BindGroupDescriptor& rhs) const;
    };

    struct BindGroupLayoutEntry {
        ChainedStruct const * nextInChain = nullptr;
        uint32_t binding;
        wgpu::ShaderStage visibility;
        BufferBindingLayout buffer;
        SamplerBindingLayout sampler;
        TextureBindingLayout texture;
        StorageTextureBindingLayout storageTexture;

        // This method makes a copy of the struct, then, for any enum members with trivial
        // defaulting (where something like "Undefined" is replaced with a default), applies
        // all of the defaults for the struct, and recursively its by-value substructs (but
        // NOT by-pointer substructs since they are const*). It must be called in an
        // appropriate place in Dawn.
        [[nodiscard]] BindGroupLayoutEntry WithTrivialFrontendDefaults() const;
        // Equality operators, mostly for testing. Note that this tests
        // strict pointer-pointer equality if the struct contains member pointers.
        bool operator==(const BindGroupLayoutEntry& rhs) const;
    };

    struct BlendState {
        BlendComponent color;
        BlendComponent alpha;

        // This method makes a copy of the struct, then, for any enum members with trivial
        // defaulting (where something like "Undefined" is replaced with a default), applies
        // all of the defaults for the struct, and recursively its by-value substructs (but
        // NOT by-pointer substructs since they are const*). It must be called in an
        // appropriate place in Dawn.
        [[nodiscard]] BlendState WithTrivialFrontendDefaults() const;
        // Equality operators, mostly for testing. Note that this tests
        // strict pointer-pointer equality if the struct contains member pointers.
        bool operator==(const BlendState& rhs) const;
    };

    struct CompilationInfo {
        ChainedStruct const * nextInChain = nullptr;
        size_t messageCount;
        CompilationMessage const * messages;

        // Equality operators, mostly for testing. Note that this tests
        // strict pointer-pointer equality if the struct contains member pointers.
        bool operator==(const CompilationInfo& rhs) const;
    };

    struct ComputePassDescriptor {
        ChainedStruct const * nextInChain = nullptr;
        char const * label = nullptr;
        ComputePassTimestampWrites const * timestampWrites = nullptr;

        // Equality operators, mostly for testing. Note that this tests
        // strict pointer-pointer equality if the struct contains member pointers.
        bool operator==(const ComputePassDescriptor& rhs) const;
    };

    struct DepthStencilState {
        ChainedStruct const * nextInChain = nullptr;
        wgpu::TextureFormat format;
        wgpu::Bool depthWriteEnabled = false;
        wgpu::CompareFunction depthCompare = wgpu::CompareFunction::Undefined;
        StencilFaceState stencilFront;
        StencilFaceState stencilBack;
        uint32_t stencilReadMask = 0xFFFFFFFF;
        uint32_t stencilWriteMask = 0xFFFFFFFF;
        int32_t depthBias = 0;
        float depthBiasSlopeScale = 0.0f;
        float depthBiasClamp = 0.0f;

        // This method makes a copy of the struct, then, for any enum members with trivial
        // defaulting (where something like "Undefined" is replaced with a default), applies
        // all of the defaults for the struct, and recursively its by-value substructs (but
        // NOT by-pointer substructs since they are const*). It must be called in an
        // appropriate place in Dawn.
        [[nodiscard]] DepthStencilState WithTrivialFrontendDefaults() const;
        // Equality operators, mostly for testing. Note that this tests
        // strict pointer-pointer equality if the struct contains member pointers.
        bool operator==(const DepthStencilState& rhs) const;
    };

    struct DrmFormatCapabilities : ChainedStructOut {
        DrmFormatCapabilities() {
            sType = wgpu::SType::DrmFormatCapabilities;
        }
        ~DrmFormatCapabilities();
        DrmFormatCapabilities(const DrmFormatCapabilities&) = delete;
        DrmFormatCapabilities& operator=(const DrmFormatCapabilities&) = delete;
        DrmFormatCapabilities(DrmFormatCapabilities&&);
        DrmFormatCapabilities& operator=(DrmFormatCapabilities&&);

        alignas(wgpu::DrmFormatCapabilities::kFirstMemberAlignment) size_t propertiesCount;
        DrmFormatProperties const * properties;

        // Equality operators, mostly for testing. Note that this tests
        // strict pointer-pointer equality if the struct contains member pointers.
        bool operator==(const DrmFormatCapabilities& rhs) const;
    };

    struct ExternalTextureDescriptor {
        ChainedStruct const * nextInChain = nullptr;
        char const * label = nullptr;
        TextureViewBase* plane0;
        TextureViewBase* plane1 = nullptr;
        Origin2D visibleOrigin;
        Extent2D visibleSize;
        wgpu::Bool doYuvToRgbConversionOnly = false;
        float const * yuvToRgbConversionMatrix = nullptr;
        float const * srcTransferFunctionParameters;
        float const * dstTransferFunctionParameters;
        float const * gamutConversionMatrix;
        wgpu::Bool mirrored = false;
        wgpu::ExternalTextureRotation rotation = wgpu::ExternalTextureRotation::Rotate0Degrees;

        // Equality operators, mostly for testing. Note that this tests
        // strict pointer-pointer equality if the struct contains member pointers.
        bool operator==(const ExternalTextureDescriptor& rhs) const;
    };

    struct FutureWaitInfo {
        Future future;
        wgpu::Bool completed = false;

        // Equality operators, mostly for testing. Note that this tests
        // strict pointer-pointer equality if the struct contains member pointers.
        bool operator==(const FutureWaitInfo& rhs) const;
    };

    struct ImageCopyBuffer {
        TextureDataLayout layout;
        BufferBase* buffer;

        // Equality operators, mostly for testing. Note that this tests
        // strict pointer-pointer equality if the struct contains member pointers.
        bool operator==(const ImageCopyBuffer& rhs) const;
    };

    struct ImageCopyExternalTexture {
        ChainedStruct const * nextInChain = nullptr;
        ExternalTextureBase* externalTexture;
        Origin3D origin;
        Extent2D naturalSize;

        // Equality operators, mostly for testing. Note that this tests
        // strict pointer-pointer equality if the struct contains member pointers.
        bool operator==(const ImageCopyExternalTexture& rhs) const;
    };

    struct ImageCopyTexture {
        TextureBase* texture;
        uint32_t mipLevel = 0;
        Origin3D origin;
        wgpu::TextureAspect aspect = wgpu::TextureAspect::All;

        // This method makes a copy of the struct, then, for any enum members with trivial
        // defaulting (where something like "Undefined" is replaced with a default), applies
        // all of the defaults for the struct, and recursively its by-value substructs (but
        // NOT by-pointer substructs since they are const*). It must be called in an
        // appropriate place in Dawn.
        [[nodiscard]] ImageCopyTexture WithTrivialFrontendDefaults() const;
        // Equality operators, mostly for testing. Note that this tests
        // strict pointer-pointer equality if the struct contains member pointers.
        bool operator==(const ImageCopyTexture& rhs) const;
    };

    struct InstanceDescriptor {
        ChainedStruct const * nextInChain = nullptr;
        InstanceFeatures features;

        // Equality operators, mostly for testing. Note that this tests
        // strict pointer-pointer equality if the struct contains member pointers.
        bool operator==(const InstanceDescriptor& rhs) const;
    };

    struct PipelineLayoutPixelLocalStorage : ChainedStruct {
        PipelineLayoutPixelLocalStorage() {
            sType = wgpu::SType::PipelineLayoutPixelLocalStorage;
        }
        alignas(wgpu::PipelineLayoutPixelLocalStorage::kFirstMemberAlignment) uint64_t totalPixelLocalStorageSize;
        size_t storageAttachmentCount = 0;
        PipelineLayoutStorageAttachment const * storageAttachments;

        // Equality operators, mostly for testing. Note that this tests
        // strict pointer-pointer equality if the struct contains member pointers.
        bool operator==(const PipelineLayoutPixelLocalStorage& rhs) const;
    };

    struct ProgrammableStageDescriptor {
        ChainedStruct const * nextInChain = nullptr;
        ShaderModuleBase* module;
        char const * entryPoint = nullptr;
        size_t constantCount = 0;
        ConstantEntry const * constants;

        // Equality operators, mostly for testing. Note that this tests
        // strict pointer-pointer equality if the struct contains member pointers.
        bool operator==(const ProgrammableStageDescriptor& rhs) const;
    };

    struct RenderPassColorAttachment {
        ChainedStruct const * nextInChain = nullptr;
        TextureViewBase* view = nullptr;
        uint32_t depthSlice = WGPU_DEPTH_SLICE_UNDEFINED;
        TextureViewBase* resolveTarget = nullptr;
        wgpu::LoadOp loadOp;
        wgpu::StoreOp storeOp;
        Color clearValue;

        // Equality operators, mostly for testing. Note that this tests
        // strict pointer-pointer equality if the struct contains member pointers.
        bool operator==(const RenderPassColorAttachment& rhs) const;
    };

    struct RenderPassStorageAttachment {
        ChainedStruct const * nextInChain = nullptr;
        uint64_t offset = 0;
        TextureViewBase* storage;
        wgpu::LoadOp loadOp;
        wgpu::StoreOp storeOp;
        Color clearValue;

        // Equality operators, mostly for testing. Note that this tests
        // strict pointer-pointer equality if the struct contains member pointers.
        bool operator==(const RenderPassStorageAttachment& rhs) const;
    };

    struct RequiredLimits {
        ChainedStruct const * nextInChain = nullptr;
        Limits limits;

        // Equality operators, mostly for testing. Note that this tests
        // strict pointer-pointer equality if the struct contains member pointers.
        bool operator==(const RequiredLimits& rhs) const;
    };

    struct SharedTextureMemoryAHardwareBufferProperties : ChainedStructOut {
        SharedTextureMemoryAHardwareBufferProperties() {
            sType = wgpu::SType::SharedTextureMemoryAHardwareBufferProperties;
        }
        alignas(wgpu::SharedTextureMemoryAHardwareBufferProperties::kFirstMemberAlignment) YCbCrVkDescriptor yCbCrInfo;

        // This method makes a copy of the struct, then, for any enum members with trivial
        // defaulting (where something like "Undefined" is replaced with a default), applies
        // all of the defaults for the struct, and recursively its by-value substructs (but
        // NOT by-pointer substructs since they are const*). It must be called in an
        // appropriate place in Dawn.
        [[nodiscard]] SharedTextureMemoryAHardwareBufferProperties WithTrivialFrontendDefaults() const;
        // Equality operators, mostly for testing. Note that this tests
        // strict pointer-pointer equality if the struct contains member pointers.
        bool operator==(const SharedTextureMemoryAHardwareBufferProperties& rhs) const;
    };

    struct SharedTextureMemoryDmaBufDescriptor : ChainedStruct {
        SharedTextureMemoryDmaBufDescriptor() {
            sType = wgpu::SType::SharedTextureMemoryDmaBufDescriptor;
        }
        alignas(wgpu::SharedTextureMemoryDmaBufDescriptor::kFirstMemberAlignment) Extent3D size;
        uint32_t drmFormat;
        uint64_t drmModifier;
        size_t planeCount;
        SharedTextureMemoryDmaBufPlane const * planes;

        // Equality operators, mostly for testing. Note that this tests
        // strict pointer-pointer equality if the struct contains member pointers.
        bool operator==(const SharedTextureMemoryDmaBufDescriptor& rhs) const;
    };

    struct SharedTextureMemoryProperties {
        ChainedStructOut * nextInChain = nullptr;
        wgpu::TextureUsage usage;
        Extent3D size;
        wgpu::TextureFormat format;

        // Equality operators, mostly for testing. Note that this tests
        // strict pointer-pointer equality if the struct contains member pointers.
        bool operator==(const SharedTextureMemoryProperties& rhs) const;
    };

    struct SupportedLimits {
        ChainedStructOut * nextInChain = nullptr;
        Limits limits;

        // Equality operators, mostly for testing. Note that this tests
        // strict pointer-pointer equality if the struct contains member pointers.
        bool operator==(const SupportedLimits& rhs) const;
    };

    struct TextureDescriptor {
        ChainedStruct const * nextInChain = nullptr;
        char const * label = nullptr;
        wgpu::TextureUsage usage;
        wgpu::TextureDimension dimension = wgpu::TextureDimension::e2D;
        Extent3D size;
        wgpu::TextureFormat format;
        uint32_t mipLevelCount = 1;
        uint32_t sampleCount = 1;
        size_t viewFormatCount = 0;
        wgpu::TextureFormat const * viewFormats;

        // This method makes a copy of the struct, then, for any enum members with trivial
        // defaulting (where something like "Undefined" is replaced with a default), applies
        // all of the defaults for the struct, and recursively its by-value substructs (but
        // NOT by-pointer substructs since they are const*). It must be called in an
        // appropriate place in Dawn.
        [[nodiscard]] TextureDescriptor WithTrivialFrontendDefaults() const;
        // Equality operators, mostly for testing. Note that this tests
        // strict pointer-pointer equality if the struct contains member pointers.
        bool operator==(const TextureDescriptor& rhs) const;
    };

    struct VertexBufferLayout {
        uint64_t arrayStride;
        wgpu::VertexStepMode stepMode = wgpu::VertexStepMode::Vertex;
        size_t attributeCount;
        VertexAttribute const * attributes;

        // This method makes a copy of the struct, then, for any enum members with trivial
        // defaulting (where something like "Undefined" is replaced with a default), applies
        // all of the defaults for the struct, and recursively its by-value substructs (but
        // NOT by-pointer substructs since they are const*). It must be called in an
        // appropriate place in Dawn.
        [[nodiscard]] VertexBufferLayout WithTrivialFrontendDefaults() const;
        // Equality operators, mostly for testing. Note that this tests
        // strict pointer-pointer equality if the struct contains member pointers.
        bool operator==(const VertexBufferLayout& rhs) const;
    };

    struct BindGroupLayoutDescriptor {
        ChainedStruct const * nextInChain = nullptr;
        char const * label = nullptr;
        size_t entryCount;
        BindGroupLayoutEntry const * entries;

        // Equality operators, mostly for testing. Note that this tests
        // strict pointer-pointer equality if the struct contains member pointers.
        bool operator==(const BindGroupLayoutDescriptor& rhs) const;
    };

    struct ColorTargetState {
        ChainedStruct const * nextInChain = nullptr;
        wgpu::TextureFormat format;
        BlendState const * blend = nullptr;
        wgpu::ColorWriteMask writeMask = wgpu::ColorWriteMask::All;

        // Equality operators, mostly for testing. Note that this tests
        // strict pointer-pointer equality if the struct contains member pointers.
        bool operator==(const ColorTargetState& rhs) const;
    };

    struct ComputePipelineDescriptor {
        ChainedStruct const * nextInChain = nullptr;
        char const * label = nullptr;
        PipelineLayoutBase* layout = nullptr;
        ProgrammableStageDescriptor compute;

        // Equality operators, mostly for testing. Note that this tests
        // strict pointer-pointer equality if the struct contains member pointers.
        bool operator==(const ComputePipelineDescriptor& rhs) const;
    };

    struct DeviceDescriptor {
        ChainedStruct const * nextInChain = nullptr;
        char const * label = nullptr;
        size_t requiredFeatureCount = 0;
        wgpu::FeatureName const * requiredFeatures = nullptr;
        RequiredLimits const * requiredLimits = nullptr;
        QueueDescriptor defaultQueue;
        WGPUDeviceLostCallback deviceLostCallback = nullptr;
        void * deviceLostUserdata = nullptr;
        DeviceLostCallbackInfo deviceLostCallbackInfo;
        UncapturedErrorCallbackInfo uncapturedErrorCallbackInfo;

        // Equality operators, mostly for testing. Note that this tests
        // strict pointer-pointer equality if the struct contains member pointers.
        bool operator==(const DeviceDescriptor& rhs) const;
    };

    struct RenderPassDescriptor {
        ChainedStruct const * nextInChain = nullptr;
        char const * label = nullptr;
        size_t colorAttachmentCount;
        RenderPassColorAttachment const * colorAttachments;
        RenderPassDepthStencilAttachment const * depthStencilAttachment = nullptr;
        QuerySetBase* occlusionQuerySet = nullptr;
        RenderPassTimestampWrites const * timestampWrites = nullptr;

        // Equality operators, mostly for testing. Note that this tests
        // strict pointer-pointer equality if the struct contains member pointers.
        bool operator==(const RenderPassDescriptor& rhs) const;
    };

    struct RenderPassPixelLocalStorage : ChainedStruct {
        RenderPassPixelLocalStorage() {
            sType = wgpu::SType::RenderPassPixelLocalStorage;
        }
        alignas(wgpu::RenderPassPixelLocalStorage::kFirstMemberAlignment) uint64_t totalPixelLocalStorageSize;
        size_t storageAttachmentCount = 0;
        RenderPassStorageAttachment const * storageAttachments;

        // Equality operators, mostly for testing. Note that this tests
        // strict pointer-pointer equality if the struct contains member pointers.
        bool operator==(const RenderPassPixelLocalStorage& rhs) const;
    };

    struct VertexState {
        ChainedStruct const * nextInChain = nullptr;
        ShaderModuleBase* module;
        char const * entryPoint = nullptr;
        size_t constantCount = 0;
        ConstantEntry const * constants;
        size_t bufferCount = 0;
        VertexBufferLayout const * buffers;

        // Equality operators, mostly for testing. Note that this tests
        // strict pointer-pointer equality if the struct contains member pointers.
        bool operator==(const VertexState& rhs) const;
    };

    struct FragmentState {
        ChainedStruct const * nextInChain = nullptr;
        ShaderModuleBase* module;
        char const * entryPoint = nullptr;
        size_t constantCount = 0;
        ConstantEntry const * constants;
        size_t targetCount;
        ColorTargetState const * targets;

        // Equality operators, mostly for testing. Note that this tests
        // strict pointer-pointer equality if the struct contains member pointers.
        bool operator==(const FragmentState& rhs) const;
    };

    struct RenderPipelineDescriptor {
        ChainedStruct const * nextInChain = nullptr;
        char const * label = nullptr;
        PipelineLayoutBase* layout = nullptr;
        VertexState vertex;
        PrimitiveState primitive;
        DepthStencilState const * depthStencil = nullptr;
        MultisampleState multisample;
        FragmentState const * fragment = nullptr;

        // This method makes a copy of the struct, then, for any enum members with trivial
        // defaulting (where something like "Undefined" is replaced with a default), applies
        // all of the defaults for the struct, and recursively its by-value substructs (but
        // NOT by-pointer substructs since they are const*). It must be called in an
        // appropriate place in Dawn.
        [[nodiscard]] RenderPipelineDescriptor WithTrivialFrontendDefaults() const;
        // Equality operators, mostly for testing. Note that this tests
        // strict pointer-pointer equality if the struct contains member pointers.
        bool operator==(const RenderPipelineDescriptor& rhs) const;
    };



    // AdapterInfo
    void APIAdapterInfoFreeMembers(WGPUAdapterInfo);
    // AdapterProperties
    void APIAdapterPropertiesFreeMembers(WGPUAdapterProperties);
    // SharedBufferMemoryEndAccessState
    void APISharedBufferMemoryEndAccessStateFreeMembers(WGPUSharedBufferMemoryEndAccessState);
    // SharedTextureMemoryEndAccessState
    void APISharedTextureMemoryEndAccessStateFreeMembers(WGPUSharedTextureMemoryEndAccessState);
    // SurfaceCapabilities
    void APISurfaceCapabilitiesFreeMembers(WGPUSurfaceCapabilities);
    // AdapterPropertiesMemoryHeaps
    void APIAdapterPropertiesMemoryHeapsFreeMembers(WGPUAdapterPropertiesMemoryHeaps);
    // DrmFormatCapabilities
    void APIDrmFormatCapabilitiesFreeMembers(WGPUDrmFormatCapabilities);

} // namespace dawn::native

#endif  // DAWNNATIVE_WGPU_STRUCTS_H_
