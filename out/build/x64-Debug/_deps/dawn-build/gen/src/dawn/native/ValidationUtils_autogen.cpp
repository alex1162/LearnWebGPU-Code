
#include "dawn/native/ValidationUtils_autogen.h"

namespace dawn::native {

    MaybeError ValidateWGSLFeatureName(wgpu::WGSLFeatureName value) {
        switch (value) {
            case wgpu::WGSLFeatureName::ReadonlyAndReadwriteStorageTextures:
                return {};
            case wgpu::WGSLFeatureName::Packed4x8IntegerDotProduct:
                return {};
            case wgpu::WGSLFeatureName::UnrestrictedPointerParameters:
                return {};
            case wgpu::WGSLFeatureName::PointerCompositeAccess:
                return {};
            case wgpu::WGSLFeatureName::ChromiumTestingUnimplemented:
                return {};
            case wgpu::WGSLFeatureName::ChromiumTestingUnsafeExperimental:
                return {};
            case wgpu::WGSLFeatureName::ChromiumTestingExperimental:
                return {};
            case wgpu::WGSLFeatureName::ChromiumTestingShippedWithKillswitch:
                return {};
            case wgpu::WGSLFeatureName::ChromiumTestingShipped:
                return {};
            default:
                return DAWN_VALIDATION_ERROR("Value %i is invalid for WGPUWGSLFeatureName.", value);
        }
    }

    MaybeError ValidateAdapterType(wgpu::AdapterType value) {
        switch (value) {
            case wgpu::AdapterType::DiscreteGPU:
                return {};
            case wgpu::AdapterType::IntegratedGPU:
                return {};
            case wgpu::AdapterType::CPU:
                return {};
            case wgpu::AdapterType::Unknown:
                return {};
            default:
                return DAWN_VALIDATION_ERROR("Value %i is invalid for WGPUAdapterType.", value);
        }
    }

    MaybeError ValidateAddressMode(wgpu::AddressMode value) {
        switch (value) {
            case wgpu::AddressMode::Undefined:
                return {};
            case wgpu::AddressMode::ClampToEdge:
                return {};
            case wgpu::AddressMode::Repeat:
                return {};
            case wgpu::AddressMode::MirrorRepeat:
                return {};
            default:
                return DAWN_VALIDATION_ERROR("Value %i is invalid for WGPUAddressMode.", value);
        }
    }

    MaybeError ValidateAlphaMode(wgpu::AlphaMode value) {
        switch (value) {
            case wgpu::AlphaMode::Opaque:
                return {};
            case wgpu::AlphaMode::Premultiplied:
                return {};
            case wgpu::AlphaMode::Unpremultiplied:
                return {};
            default:
                return DAWN_VALIDATION_ERROR("Value %i is invalid for WGPUAlphaMode.", value);
        }
    }

    MaybeError ValidateBackendType(wgpu::BackendType value) {
        switch (value) {
            case wgpu::BackendType::Null:
                return {};
            case wgpu::BackendType::WebGPU:
                return {};
            case wgpu::BackendType::D3D11:
                return {};
            case wgpu::BackendType::D3D12:
                return {};
            case wgpu::BackendType::Metal:
                return {};
            case wgpu::BackendType::Vulkan:
                return {};
            case wgpu::BackendType::OpenGL:
                return {};
            case wgpu::BackendType::OpenGLES:
                return {};
            default:
                return DAWN_VALIDATION_ERROR("Value %i is invalid for WGPUBackendType.", value);
        }
    }

    MaybeError ValidateBlendFactor(wgpu::BlendFactor value) {
        switch (value) {
            case wgpu::BlendFactor::Undefined:
                return {};
            case wgpu::BlendFactor::Zero:
                return {};
            case wgpu::BlendFactor::One:
                return {};
            case wgpu::BlendFactor::Src:
                return {};
            case wgpu::BlendFactor::OneMinusSrc:
                return {};
            case wgpu::BlendFactor::SrcAlpha:
                return {};
            case wgpu::BlendFactor::OneMinusSrcAlpha:
                return {};
            case wgpu::BlendFactor::Dst:
                return {};
            case wgpu::BlendFactor::OneMinusDst:
                return {};
            case wgpu::BlendFactor::DstAlpha:
                return {};
            case wgpu::BlendFactor::OneMinusDstAlpha:
                return {};
            case wgpu::BlendFactor::SrcAlphaSaturated:
                return {};
            case wgpu::BlendFactor::Constant:
                return {};
            case wgpu::BlendFactor::OneMinusConstant:
                return {};
            case wgpu::BlendFactor::Src1:
                return {};
            case wgpu::BlendFactor::OneMinusSrc1:
                return {};
            case wgpu::BlendFactor::Src1Alpha:
                return {};
            case wgpu::BlendFactor::OneMinusSrc1Alpha:
                return {};
            default:
                return DAWN_VALIDATION_ERROR("Value %i is invalid for WGPUBlendFactor.", value);
        }
    }

    MaybeError ValidateBlendOperation(wgpu::BlendOperation value) {
        switch (value) {
            case wgpu::BlendOperation::Undefined:
                return {};
            case wgpu::BlendOperation::Add:
                return {};
            case wgpu::BlendOperation::Subtract:
                return {};
            case wgpu::BlendOperation::ReverseSubtract:
                return {};
            case wgpu::BlendOperation::Min:
                return {};
            case wgpu::BlendOperation::Max:
                return {};
            default:
                return DAWN_VALIDATION_ERROR("Value %i is invalid for WGPUBlendOperation.", value);
        }
    }

    MaybeError ValidateBufferBindingType(wgpu::BufferBindingType value) {
        switch (value) {
            case wgpu::BufferBindingType::Uniform:
                return {};
            case wgpu::BufferBindingType::Storage:
                return {};
            case wgpu::BufferBindingType::ReadOnlyStorage:
                return {};
            default:
                return DAWN_VALIDATION_ERROR("Value %i is invalid for WGPUBufferBindingType.", value);
        }
    }

    MaybeError ValidateBufferMapAsyncStatus(wgpu::BufferMapAsyncStatus value) {
        switch (value) {
            case wgpu::BufferMapAsyncStatus::Success:
                return {};
            case wgpu::BufferMapAsyncStatus::InstanceDropped:
                return {};
            case wgpu::BufferMapAsyncStatus::ValidationError:
                return {};
            case wgpu::BufferMapAsyncStatus::Unknown:
                return {};
            case wgpu::BufferMapAsyncStatus::DeviceLost:
                return {};
            case wgpu::BufferMapAsyncStatus::DestroyedBeforeCallback:
                return {};
            case wgpu::BufferMapAsyncStatus::UnmappedBeforeCallback:
                return {};
            case wgpu::BufferMapAsyncStatus::MappingAlreadyPending:
                return {};
            case wgpu::BufferMapAsyncStatus::OffsetOutOfRange:
                return {};
            case wgpu::BufferMapAsyncStatus::SizeOutOfRange:
                return {};
            default:
                return DAWN_VALIDATION_ERROR("Value %i is invalid for WGPUBufferMapAsyncStatus.", value);
        }
    }

    MaybeError ValidateBufferMapState(wgpu::BufferMapState value) {
        switch (value) {
            case wgpu::BufferMapState::Unmapped:
                return {};
            case wgpu::BufferMapState::Pending:
                return {};
            case wgpu::BufferMapState::Mapped:
                return {};
            default:
                return DAWN_VALIDATION_ERROR("Value %i is invalid for WGPUBufferMapState.", value);
        }
    }

    MaybeError ValidateCallbackMode(wgpu::CallbackMode value) {
        switch (value) {
            case wgpu::CallbackMode::WaitAnyOnly:
                return {};
            case wgpu::CallbackMode::AllowProcessEvents:
                return {};
            case wgpu::CallbackMode::AllowSpontaneous:
                return {};
            default:
                return DAWN_VALIDATION_ERROR("Value %i is invalid for WGPUCallbackMode.", value);
        }
    }

    MaybeError ValidateCompareFunction(wgpu::CompareFunction value) {
        switch (value) {
            case wgpu::CompareFunction::Undefined:
                return {};
            case wgpu::CompareFunction::Never:
                return {};
            case wgpu::CompareFunction::Less:
                return {};
            case wgpu::CompareFunction::Equal:
                return {};
            case wgpu::CompareFunction::LessEqual:
                return {};
            case wgpu::CompareFunction::Greater:
                return {};
            case wgpu::CompareFunction::NotEqual:
                return {};
            case wgpu::CompareFunction::GreaterEqual:
                return {};
            case wgpu::CompareFunction::Always:
                return {};
            default:
                return DAWN_VALIDATION_ERROR("Value %i is invalid for WGPUCompareFunction.", value);
        }
    }

    MaybeError ValidateCompilationInfoRequestStatus(wgpu::CompilationInfoRequestStatus value) {
        switch (value) {
            case wgpu::CompilationInfoRequestStatus::Success:
                return {};
            case wgpu::CompilationInfoRequestStatus::InstanceDropped:
                return {};
            case wgpu::CompilationInfoRequestStatus::Error:
                return {};
            case wgpu::CompilationInfoRequestStatus::DeviceLost:
                return {};
            case wgpu::CompilationInfoRequestStatus::Unknown:
                return {};
            default:
                return DAWN_VALIDATION_ERROR("Value %i is invalid for WGPUCompilationInfoRequestStatus.", value);
        }
    }

    MaybeError ValidateCompilationMessageType(wgpu::CompilationMessageType value) {
        switch (value) {
            case wgpu::CompilationMessageType::Error:
                return {};
            case wgpu::CompilationMessageType::Warning:
                return {};
            case wgpu::CompilationMessageType::Info:
                return {};
            default:
                return DAWN_VALIDATION_ERROR("Value %i is invalid for WGPUCompilationMessageType.", value);
        }
    }

    MaybeError ValidateCompositeAlphaMode(wgpu::CompositeAlphaMode value) {
        switch (value) {
            case wgpu::CompositeAlphaMode::Auto:
                return {};
            case wgpu::CompositeAlphaMode::Opaque:
                return {};
            case wgpu::CompositeAlphaMode::Premultiplied:
                return {};
            case wgpu::CompositeAlphaMode::Unpremultiplied:
                return {};
            case wgpu::CompositeAlphaMode::Inherit:
                return {};
            default:
                return DAWN_VALIDATION_ERROR("Value %i is invalid for WGPUCompositeAlphaMode.", value);
        }
    }

    MaybeError ValidateCreatePipelineAsyncStatus(wgpu::CreatePipelineAsyncStatus value) {
        switch (value) {
            case wgpu::CreatePipelineAsyncStatus::Success:
                return {};
            case wgpu::CreatePipelineAsyncStatus::InstanceDropped:
                return {};
            case wgpu::CreatePipelineAsyncStatus::ValidationError:
                return {};
            case wgpu::CreatePipelineAsyncStatus::InternalError:
                return {};
            case wgpu::CreatePipelineAsyncStatus::DeviceLost:
                return {};
            case wgpu::CreatePipelineAsyncStatus::DeviceDestroyed:
                return {};
            case wgpu::CreatePipelineAsyncStatus::Unknown:
                return {};
            default:
                return DAWN_VALIDATION_ERROR("Value %i is invalid for WGPUCreatePipelineAsyncStatus.", value);
        }
    }

    MaybeError ValidateCullMode(wgpu::CullMode value) {
        switch (value) {
            case wgpu::CullMode::Undefined:
                return {};
            case wgpu::CullMode::None:
                return {};
            case wgpu::CullMode::Front:
                return {};
            case wgpu::CullMode::Back:
                return {};
            default:
                return DAWN_VALIDATION_ERROR("Value %i is invalid for WGPUCullMode.", value);
        }
    }

    MaybeError ValidateDeviceLostReason(wgpu::DeviceLostReason value) {
        switch (value) {
            case wgpu::DeviceLostReason::Unknown:
                return {};
            case wgpu::DeviceLostReason::Destroyed:
                return {};
            case wgpu::DeviceLostReason::InstanceDropped:
                return {};
            case wgpu::DeviceLostReason::FailedCreation:
                return {};
            default:
                return DAWN_VALIDATION_ERROR("Value %i is invalid for WGPUDeviceLostReason.", value);
        }
    }

    MaybeError ValidateErrorFilter(wgpu::ErrorFilter value) {
        switch (value) {
            case wgpu::ErrorFilter::Validation:
                return {};
            case wgpu::ErrorFilter::OutOfMemory:
                return {};
            case wgpu::ErrorFilter::Internal:
                return {};
            default:
                return DAWN_VALIDATION_ERROR("Value %i is invalid for WGPUErrorFilter.", value);
        }
    }

    MaybeError ValidateErrorType(wgpu::ErrorType value) {
        switch (value) {
            case wgpu::ErrorType::NoError:
                return {};
            case wgpu::ErrorType::Validation:
                return {};
            case wgpu::ErrorType::OutOfMemory:
                return {};
            case wgpu::ErrorType::Internal:
                return {};
            case wgpu::ErrorType::Unknown:
                return {};
            case wgpu::ErrorType::DeviceLost:
                return {};
            default:
                return DAWN_VALIDATION_ERROR("Value %i is invalid for WGPUErrorType.", value);
        }
    }

    MaybeError ValidateExternalTextureRotation(wgpu::ExternalTextureRotation value) {
        switch (value) {
            case wgpu::ExternalTextureRotation::Rotate0Degrees:
                return {};
            case wgpu::ExternalTextureRotation::Rotate90Degrees:
                return {};
            case wgpu::ExternalTextureRotation::Rotate180Degrees:
                return {};
            case wgpu::ExternalTextureRotation::Rotate270Degrees:
                return {};
            default:
                return DAWN_VALIDATION_ERROR("Value %i is invalid for WGPUExternalTextureRotation.", value);
        }
    }

    MaybeError ValidateFeatureName(wgpu::FeatureName value) {
        switch (value) {
            case wgpu::FeatureName::DepthClipControl:
                return {};
            case wgpu::FeatureName::Depth32FloatStencil8:
                return {};
            case wgpu::FeatureName::TimestampQuery:
                return {};
            case wgpu::FeatureName::TextureCompressionBC:
                return {};
            case wgpu::FeatureName::TextureCompressionETC2:
                return {};
            case wgpu::FeatureName::TextureCompressionASTC:
                return {};
            case wgpu::FeatureName::IndirectFirstInstance:
                return {};
            case wgpu::FeatureName::ShaderF16:
                return {};
            case wgpu::FeatureName::RG11B10UfloatRenderable:
                return {};
            case wgpu::FeatureName::BGRA8UnormStorage:
                return {};
            case wgpu::FeatureName::Float32Filterable:
                return {};
            case wgpu::FeatureName::DawnInternalUsages:
                return {};
            case wgpu::FeatureName::DawnMultiPlanarFormats:
                return {};
            case wgpu::FeatureName::DawnNative:
                return {};
            case wgpu::FeatureName::ChromiumExperimentalTimestampQueryInsidePasses:
                return {};
            case wgpu::FeatureName::ImplicitDeviceSynchronization:
                return {};
            case wgpu::FeatureName::SurfaceCapabilities:
                return {};
            case wgpu::FeatureName::TransientAttachments:
                return {};
            case wgpu::FeatureName::MSAARenderToSingleSampled:
                return {};
            case wgpu::FeatureName::DualSourceBlending:
                return {};
            case wgpu::FeatureName::D3D11MultithreadProtected:
                return {};
            case wgpu::FeatureName::ANGLETextureSharing:
                return {};
            case wgpu::FeatureName::ChromiumExperimentalSubgroups:
                return {};
            case wgpu::FeatureName::ChromiumExperimentalSubgroupUniformControlFlow:
                return {};
            case wgpu::FeatureName::PixelLocalStorageCoherent:
                return {};
            case wgpu::FeatureName::PixelLocalStorageNonCoherent:
                return {};
            case wgpu::FeatureName::Unorm16TextureFormats:
                return {};
            case wgpu::FeatureName::Snorm16TextureFormats:
                return {};
            case wgpu::FeatureName::MultiPlanarFormatExtendedUsages:
                return {};
            case wgpu::FeatureName::MultiPlanarFormatP010:
                return {};
            case wgpu::FeatureName::HostMappedPointer:
                return {};
            case wgpu::FeatureName::MultiPlanarRenderTargets:
                return {};
            case wgpu::FeatureName::MultiPlanarFormatNv12a:
                return {};
            case wgpu::FeatureName::FramebufferFetch:
                return {};
            case wgpu::FeatureName::BufferMapExtendedUsages:
                return {};
            case wgpu::FeatureName::AdapterPropertiesMemoryHeaps:
                return {};
            case wgpu::FeatureName::AdapterPropertiesD3D:
                return {};
            case wgpu::FeatureName::AdapterPropertiesVk:
                return {};
            case wgpu::FeatureName::R8UnormStorage:
                return {};
            case wgpu::FeatureName::FormatCapabilities:
                return {};
            case wgpu::FeatureName::DrmFormatCapabilities:
                return {};
            case wgpu::FeatureName::Norm16TextureFormats:
                return {};
            case wgpu::FeatureName::MultiPlanarFormatNv16:
                return {};
            case wgpu::FeatureName::MultiPlanarFormatNv24:
                return {};
            case wgpu::FeatureName::MultiPlanarFormatP210:
                return {};
            case wgpu::FeatureName::MultiPlanarFormatP410:
                return {};
            case wgpu::FeatureName::SharedTextureMemoryVkDedicatedAllocation:
                return {};
            case wgpu::FeatureName::SharedTextureMemoryAHardwareBuffer:
                return {};
            case wgpu::FeatureName::SharedTextureMemoryDmaBuf:
                return {};
            case wgpu::FeatureName::SharedTextureMemoryOpaqueFD:
                return {};
            case wgpu::FeatureName::SharedTextureMemoryZirconHandle:
                return {};
            case wgpu::FeatureName::SharedTextureMemoryDXGISharedHandle:
                return {};
            case wgpu::FeatureName::SharedTextureMemoryD3D11Texture2D:
                return {};
            case wgpu::FeatureName::SharedTextureMemoryIOSurface:
                return {};
            case wgpu::FeatureName::SharedTextureMemoryEGLImage:
                return {};
            case wgpu::FeatureName::SharedFenceVkSemaphoreOpaqueFD:
                return {};
            case wgpu::FeatureName::SharedFenceVkSemaphoreSyncFD:
                return {};
            case wgpu::FeatureName::SharedFenceVkSemaphoreZirconHandle:
                return {};
            case wgpu::FeatureName::SharedFenceDXGISharedHandle:
                return {};
            case wgpu::FeatureName::SharedFenceMTLSharedEvent:
                return {};
            case wgpu::FeatureName::SharedBufferMemoryD3D12Resource:
                return {};
            case wgpu::FeatureName::StaticSamplers:
                return {};
            case wgpu::FeatureName::YCbCrVulkanSamplers:
                return {};
            case wgpu::FeatureName::ShaderModuleCompilationOptions:
                return {};
            case wgpu::FeatureName::DawnLoadResolveTexture:
                return {};
            default:
                return DAWN_VALIDATION_ERROR("Value %i is invalid for WGPUFeatureName.", value);
        }
    }

    MaybeError ValidateFilterMode(wgpu::FilterMode value) {
        switch (value) {
            case wgpu::FilterMode::Undefined:
                return {};
            case wgpu::FilterMode::Nearest:
                return {};
            case wgpu::FilterMode::Linear:
                return {};
            default:
                return DAWN_VALIDATION_ERROR("Value %i is invalid for WGPUFilterMode.", value);
        }
    }

    MaybeError ValidateFrontFace(wgpu::FrontFace value) {
        switch (value) {
            case wgpu::FrontFace::Undefined:
                return {};
            case wgpu::FrontFace::CCW:
                return {};
            case wgpu::FrontFace::CW:
                return {};
            default:
                return DAWN_VALIDATION_ERROR("Value %i is invalid for WGPUFrontFace.", value);
        }
    }

    MaybeError ValidateIndexFormat(wgpu::IndexFormat value) {
        switch (value) {
            case wgpu::IndexFormat::Undefined:
                return {};
            case wgpu::IndexFormat::Uint16:
                return {};
            case wgpu::IndexFormat::Uint32:
                return {};
            default:
                return DAWN_VALIDATION_ERROR("Value %i is invalid for WGPUIndexFormat.", value);
        }
    }

    MaybeError ValidateLoadOp(wgpu::LoadOp value) {
        switch (value) {
            case wgpu::LoadOp::Undefined:
                return {};
            case wgpu::LoadOp::Clear:
                return {};
            case wgpu::LoadOp::Load:
                return {};
            case wgpu::LoadOp::ExpandResolveTexture:
                return {};
            default:
                return DAWN_VALIDATION_ERROR("Value %i is invalid for WGPULoadOp.", value);
        }
    }

    MaybeError ValidateLoggingType(wgpu::LoggingType value) {
        switch (value) {
            case wgpu::LoggingType::Verbose:
                return {};
            case wgpu::LoggingType::Info:
                return {};
            case wgpu::LoggingType::Warning:
                return {};
            case wgpu::LoggingType::Error:
                return {};
            default:
                return DAWN_VALIDATION_ERROR("Value %i is invalid for WGPULoggingType.", value);
        }
    }

    MaybeError ValidateMipmapFilterMode(wgpu::MipmapFilterMode value) {
        switch (value) {
            case wgpu::MipmapFilterMode::Undefined:
                return {};
            case wgpu::MipmapFilterMode::Nearest:
                return {};
            case wgpu::MipmapFilterMode::Linear:
                return {};
            default:
                return DAWN_VALIDATION_ERROR("Value %i is invalid for WGPUMipmapFilterMode.", value);
        }
    }

    MaybeError ValidatePopErrorScopeStatus(wgpu::PopErrorScopeStatus value) {
        switch (value) {
            case wgpu::PopErrorScopeStatus::Success:
                return {};
            case wgpu::PopErrorScopeStatus::InstanceDropped:
                return {};
            default:
                return DAWN_VALIDATION_ERROR("Value %i is invalid for WGPUPopErrorScopeStatus.", value);
        }
    }

    MaybeError ValidatePowerPreference(wgpu::PowerPreference value) {
        switch (value) {
            case wgpu::PowerPreference::Undefined:
                return {};
            case wgpu::PowerPreference::LowPower:
                return {};
            case wgpu::PowerPreference::HighPerformance:
                return {};
            default:
                return DAWN_VALIDATION_ERROR("Value %i is invalid for WGPUPowerPreference.", value);
        }
    }

    MaybeError ValidatePresentMode(wgpu::PresentMode value) {
        switch (value) {
            case wgpu::PresentMode::Fifo:
                return {};
            case wgpu::PresentMode::FifoRelaxed:
                return {};
            case wgpu::PresentMode::Immediate:
                return {};
            case wgpu::PresentMode::Mailbox:
                return {};
            default:
                return DAWN_VALIDATION_ERROR("Value %i is invalid for WGPUPresentMode.", value);
        }
    }

    MaybeError ValidatePrimitiveTopology(wgpu::PrimitiveTopology value) {
        switch (value) {
            case wgpu::PrimitiveTopology::Undefined:
                return {};
            case wgpu::PrimitiveTopology::PointList:
                return {};
            case wgpu::PrimitiveTopology::LineList:
                return {};
            case wgpu::PrimitiveTopology::LineStrip:
                return {};
            case wgpu::PrimitiveTopology::TriangleList:
                return {};
            case wgpu::PrimitiveTopology::TriangleStrip:
                return {};
            default:
                return DAWN_VALIDATION_ERROR("Value %i is invalid for WGPUPrimitiveTopology.", value);
        }
    }

    MaybeError ValidateQueryType(wgpu::QueryType value) {
        switch (value) {
            case wgpu::QueryType::Occlusion:
                return {};
            case wgpu::QueryType::Timestamp:
                return {};
            default:
                return DAWN_VALIDATION_ERROR("Value %i is invalid for WGPUQueryType.", value);
        }
    }

    MaybeError ValidateQueueWorkDoneStatus(wgpu::QueueWorkDoneStatus value) {
        switch (value) {
            case wgpu::QueueWorkDoneStatus::Success:
                return {};
            case wgpu::QueueWorkDoneStatus::InstanceDropped:
                return {};
            case wgpu::QueueWorkDoneStatus::Error:
                return {};
            case wgpu::QueueWorkDoneStatus::Unknown:
                return {};
            case wgpu::QueueWorkDoneStatus::DeviceLost:
                return {};
            default:
                return DAWN_VALIDATION_ERROR("Value %i is invalid for WGPUQueueWorkDoneStatus.", value);
        }
    }

    MaybeError ValidateRequestAdapterStatus(wgpu::RequestAdapterStatus value) {
        switch (value) {
            case wgpu::RequestAdapterStatus::Success:
                return {};
            case wgpu::RequestAdapterStatus::InstanceDropped:
                return {};
            case wgpu::RequestAdapterStatus::Unavailable:
                return {};
            case wgpu::RequestAdapterStatus::Error:
                return {};
            case wgpu::RequestAdapterStatus::Unknown:
                return {};
            default:
                return DAWN_VALIDATION_ERROR("Value %i is invalid for WGPURequestAdapterStatus.", value);
        }
    }

    MaybeError ValidateRequestDeviceStatus(wgpu::RequestDeviceStatus value) {
        switch (value) {
            case wgpu::RequestDeviceStatus::Success:
                return {};
            case wgpu::RequestDeviceStatus::InstanceDropped:
                return {};
            case wgpu::RequestDeviceStatus::Error:
                return {};
            case wgpu::RequestDeviceStatus::Unknown:
                return {};
            default:
                return DAWN_VALIDATION_ERROR("Value %i is invalid for WGPURequestDeviceStatus.", value);
        }
    }

    MaybeError ValidateSType(wgpu::SType value) {
        switch (value) {
            case wgpu::SType::SurfaceDescriptorFromMetalLayer:
                return {};
            case wgpu::SType::SurfaceDescriptorFromWindowsHWND:
                return {};
            case wgpu::SType::SurfaceDescriptorFromXlibWindow:
                return {};
            case wgpu::SType::SurfaceDescriptorFromCanvasHTMLSelector:
                return {};
            case wgpu::SType::ShaderModuleSPIRVDescriptor:
                return {};
            case wgpu::SType::ShaderModuleWGSLDescriptor:
                return {};
            case wgpu::SType::PrimitiveDepthClipControl:
                return {};
            case wgpu::SType::SurfaceDescriptorFromWaylandSurface:
                return {};
            case wgpu::SType::SurfaceDescriptorFromAndroidNativeWindow:
                return {};
            case wgpu::SType::SurfaceDescriptorFromWindowsCoreWindow:
                return {};
            case wgpu::SType::ExternalTextureBindingEntry:
                return {};
            case wgpu::SType::ExternalTextureBindingLayout:
                return {};
            case wgpu::SType::SurfaceDescriptorFromWindowsSwapChainPanel:
                return {};
            case wgpu::SType::RenderPassDescriptorMaxDrawCount:
                return {};
            case wgpu::SType::DepthStencilStateDepthWriteDefinedDawn:
                return {};
            case wgpu::SType::TextureBindingViewDimensionDescriptor:
                return {};
            case wgpu::SType::DawnTextureInternalUsageDescriptor:
                return {};
            case wgpu::SType::DawnEncoderInternalUsageDescriptor:
                return {};
            case wgpu::SType::DawnInstanceDescriptor:
                return {};
            case wgpu::SType::DawnCacheDeviceDescriptor:
                return {};
            case wgpu::SType::DawnAdapterPropertiesPowerPreference:
                return {};
            case wgpu::SType::DawnBufferDescriptorErrorInfoFromWireClient:
                return {};
            case wgpu::SType::DawnTogglesDescriptor:
                return {};
            case wgpu::SType::DawnShaderModuleSPIRVOptionsDescriptor:
                return {};
            case wgpu::SType::RequestAdapterOptionsLUID:
                return {};
            case wgpu::SType::RequestAdapterOptionsGetGLProc:
                return {};
            case wgpu::SType::RequestAdapterOptionsD3D11Device:
                return {};
            case wgpu::SType::DawnMultisampleStateRenderToSingleSampled:
                return {};
            case wgpu::SType::DawnRenderPassColorAttachmentRenderToSingleSampled:
                return {};
            case wgpu::SType::RenderPassPixelLocalStorage:
                return {};
            case wgpu::SType::PipelineLayoutPixelLocalStorage:
                return {};
            case wgpu::SType::BufferHostMappedPointer:
                return {};
            case wgpu::SType::DawnExperimentalSubgroupLimits:
                return {};
            case wgpu::SType::AdapterPropertiesMemoryHeaps:
                return {};
            case wgpu::SType::AdapterPropertiesD3D:
                return {};
            case wgpu::SType::AdapterPropertiesVk:
                return {};
            case wgpu::SType::DawnComputePipelineFullSubgroups:
                return {};
            case wgpu::SType::DawnWireWGSLControl:
                return {};
            case wgpu::SType::DawnWGSLBlocklist:
                return {};
            case wgpu::SType::DrmFormatCapabilities:
                return {};
            case wgpu::SType::ShaderModuleCompilationOptions:
                return {};
            case wgpu::SType::ColorTargetStateExpandResolveTextureDawn:
                return {};
            case wgpu::SType::SharedTextureMemoryVkDedicatedAllocationDescriptor:
                return {};
            case wgpu::SType::SharedTextureMemoryAHardwareBufferDescriptor:
                return {};
            case wgpu::SType::SharedTextureMemoryDmaBufDescriptor:
                return {};
            case wgpu::SType::SharedTextureMemoryOpaqueFDDescriptor:
                return {};
            case wgpu::SType::SharedTextureMemoryZirconHandleDescriptor:
                return {};
            case wgpu::SType::SharedTextureMemoryDXGISharedHandleDescriptor:
                return {};
            case wgpu::SType::SharedTextureMemoryD3D11Texture2DDescriptor:
                return {};
            case wgpu::SType::SharedTextureMemoryIOSurfaceDescriptor:
                return {};
            case wgpu::SType::SharedTextureMemoryEGLImageDescriptor:
                return {};
            case wgpu::SType::SharedTextureMemoryInitializedBeginState:
                return {};
            case wgpu::SType::SharedTextureMemoryInitializedEndState:
                return {};
            case wgpu::SType::SharedTextureMemoryVkImageLayoutBeginState:
                return {};
            case wgpu::SType::SharedTextureMemoryVkImageLayoutEndState:
                return {};
            case wgpu::SType::SharedTextureMemoryD3DSwapchainBeginState:
                return {};
            case wgpu::SType::SharedFenceVkSemaphoreOpaqueFDDescriptor:
                return {};
            case wgpu::SType::SharedFenceVkSemaphoreOpaqueFDExportInfo:
                return {};
            case wgpu::SType::SharedFenceVkSemaphoreSyncFDDescriptor:
                return {};
            case wgpu::SType::SharedFenceVkSemaphoreSyncFDExportInfo:
                return {};
            case wgpu::SType::SharedFenceVkSemaphoreZirconHandleDescriptor:
                return {};
            case wgpu::SType::SharedFenceVkSemaphoreZirconHandleExportInfo:
                return {};
            case wgpu::SType::SharedFenceDXGISharedHandleDescriptor:
                return {};
            case wgpu::SType::SharedFenceDXGISharedHandleExportInfo:
                return {};
            case wgpu::SType::SharedFenceMTLSharedEventDescriptor:
                return {};
            case wgpu::SType::SharedFenceMTLSharedEventExportInfo:
                return {};
            case wgpu::SType::SharedBufferMemoryD3D12ResourceDescriptor:
                return {};
            case wgpu::SType::StaticSamplerBindingLayout:
                return {};
            case wgpu::SType::YCbCrVkDescriptor:
                return {};
            case wgpu::SType::SharedTextureMemoryAHardwareBufferProperties:
                return {};
            case wgpu::SType::AHardwareBufferProperties:
                return {};
            default:
                return DAWN_VALIDATION_ERROR("Value %i is invalid for WGPUSType.", value);
        }
    }

    MaybeError ValidateSamplerBindingType(wgpu::SamplerBindingType value) {
        switch (value) {
            case wgpu::SamplerBindingType::Filtering:
                return {};
            case wgpu::SamplerBindingType::NonFiltering:
                return {};
            case wgpu::SamplerBindingType::Comparison:
                return {};
            default:
                return DAWN_VALIDATION_ERROR("Value %i is invalid for WGPUSamplerBindingType.", value);
        }
    }

    MaybeError ValidateSharedFenceType(wgpu::SharedFenceType value) {
        switch (value) {
            case wgpu::SharedFenceType::VkSemaphoreOpaqueFD:
                return {};
            case wgpu::SharedFenceType::VkSemaphoreSyncFD:
                return {};
            case wgpu::SharedFenceType::VkSemaphoreZirconHandle:
                return {};
            case wgpu::SharedFenceType::DXGISharedHandle:
                return {};
            case wgpu::SharedFenceType::MTLSharedEvent:
                return {};
            default:
                return DAWN_VALIDATION_ERROR("Value %i is invalid for WGPUSharedFenceType.", value);
        }
    }

    MaybeError ValidateStatus(wgpu::Status value) {
        switch (value) {
            case wgpu::Status::Success:
                return {};
            case wgpu::Status::Error:
                return {};
            default:
                return DAWN_VALIDATION_ERROR("Value %i is invalid for WGPUStatus.", value);
        }
    }

    MaybeError ValidateStencilOperation(wgpu::StencilOperation value) {
        switch (value) {
            case wgpu::StencilOperation::Undefined:
                return {};
            case wgpu::StencilOperation::Keep:
                return {};
            case wgpu::StencilOperation::Zero:
                return {};
            case wgpu::StencilOperation::Replace:
                return {};
            case wgpu::StencilOperation::Invert:
                return {};
            case wgpu::StencilOperation::IncrementClamp:
                return {};
            case wgpu::StencilOperation::DecrementClamp:
                return {};
            case wgpu::StencilOperation::IncrementWrap:
                return {};
            case wgpu::StencilOperation::DecrementWrap:
                return {};
            default:
                return DAWN_VALIDATION_ERROR("Value %i is invalid for WGPUStencilOperation.", value);
        }
    }

    MaybeError ValidateStorageTextureAccess(wgpu::StorageTextureAccess value) {
        switch (value) {
            case wgpu::StorageTextureAccess::WriteOnly:
                return {};
            case wgpu::StorageTextureAccess::ReadOnly:
                return {};
            case wgpu::StorageTextureAccess::ReadWrite:
                return {};
            default:
                return DAWN_VALIDATION_ERROR("Value %i is invalid for WGPUStorageTextureAccess.", value);
        }
    }

    MaybeError ValidateStoreOp(wgpu::StoreOp value) {
        switch (value) {
            case wgpu::StoreOp::Undefined:
                return {};
            case wgpu::StoreOp::Store:
                return {};
            case wgpu::StoreOp::Discard:
                return {};
            default:
                return DAWN_VALIDATION_ERROR("Value %i is invalid for WGPUStoreOp.", value);
        }
    }

    MaybeError ValidateSurfaceGetCurrentTextureStatus(wgpu::SurfaceGetCurrentTextureStatus value) {
        switch (value) {
            case wgpu::SurfaceGetCurrentTextureStatus::Success:
                return {};
            case wgpu::SurfaceGetCurrentTextureStatus::Timeout:
                return {};
            case wgpu::SurfaceGetCurrentTextureStatus::Outdated:
                return {};
            case wgpu::SurfaceGetCurrentTextureStatus::Lost:
                return {};
            case wgpu::SurfaceGetCurrentTextureStatus::OutOfMemory:
                return {};
            case wgpu::SurfaceGetCurrentTextureStatus::DeviceLost:
                return {};
            default:
                return DAWN_VALIDATION_ERROR("Value %i is invalid for WGPUSurfaceGetCurrentTextureStatus.", value);
        }
    }

    MaybeError ValidateTextureAspect(wgpu::TextureAspect value) {
        switch (value) {
            case wgpu::TextureAspect::Undefined:
                return {};
            case wgpu::TextureAspect::All:
                return {};
            case wgpu::TextureAspect::StencilOnly:
                return {};
            case wgpu::TextureAspect::DepthOnly:
                return {};
            case wgpu::TextureAspect::Plane0Only:
                return {};
            case wgpu::TextureAspect::Plane1Only:
                return {};
            case wgpu::TextureAspect::Plane2Only:
                return {};
            default:
                return DAWN_VALIDATION_ERROR("Value %i is invalid for WGPUTextureAspect.", value);
        }
    }

    MaybeError ValidateTextureDimension(wgpu::TextureDimension value) {
        switch (value) {
            case wgpu::TextureDimension::Undefined:
                return {};
            case wgpu::TextureDimension::e1D:
                return {};
            case wgpu::TextureDimension::e2D:
                return {};
            case wgpu::TextureDimension::e3D:
                return {};
            default:
                return DAWN_VALIDATION_ERROR("Value %i is invalid for WGPUTextureDimension.", value);
        }
    }

    MaybeError ValidateTextureFormat(wgpu::TextureFormat value) {
        switch (value) {
            case wgpu::TextureFormat::R8Unorm:
                return {};
            case wgpu::TextureFormat::R8Snorm:
                return {};
            case wgpu::TextureFormat::R8Uint:
                return {};
            case wgpu::TextureFormat::R8Sint:
                return {};
            case wgpu::TextureFormat::R16Uint:
                return {};
            case wgpu::TextureFormat::R16Sint:
                return {};
            case wgpu::TextureFormat::R16Float:
                return {};
            case wgpu::TextureFormat::RG8Unorm:
                return {};
            case wgpu::TextureFormat::RG8Snorm:
                return {};
            case wgpu::TextureFormat::RG8Uint:
                return {};
            case wgpu::TextureFormat::RG8Sint:
                return {};
            case wgpu::TextureFormat::R32Float:
                return {};
            case wgpu::TextureFormat::R32Uint:
                return {};
            case wgpu::TextureFormat::R32Sint:
                return {};
            case wgpu::TextureFormat::RG16Uint:
                return {};
            case wgpu::TextureFormat::RG16Sint:
                return {};
            case wgpu::TextureFormat::RG16Float:
                return {};
            case wgpu::TextureFormat::RGBA8Unorm:
                return {};
            case wgpu::TextureFormat::RGBA8UnormSrgb:
                return {};
            case wgpu::TextureFormat::RGBA8Snorm:
                return {};
            case wgpu::TextureFormat::RGBA8Uint:
                return {};
            case wgpu::TextureFormat::RGBA8Sint:
                return {};
            case wgpu::TextureFormat::BGRA8Unorm:
                return {};
            case wgpu::TextureFormat::BGRA8UnormSrgb:
                return {};
            case wgpu::TextureFormat::RGB10A2Uint:
                return {};
            case wgpu::TextureFormat::RGB10A2Unorm:
                return {};
            case wgpu::TextureFormat::RG11B10Ufloat:
                return {};
            case wgpu::TextureFormat::RGB9E5Ufloat:
                return {};
            case wgpu::TextureFormat::RG32Float:
                return {};
            case wgpu::TextureFormat::RG32Uint:
                return {};
            case wgpu::TextureFormat::RG32Sint:
                return {};
            case wgpu::TextureFormat::RGBA16Uint:
                return {};
            case wgpu::TextureFormat::RGBA16Sint:
                return {};
            case wgpu::TextureFormat::RGBA16Float:
                return {};
            case wgpu::TextureFormat::RGBA32Float:
                return {};
            case wgpu::TextureFormat::RGBA32Uint:
                return {};
            case wgpu::TextureFormat::RGBA32Sint:
                return {};
            case wgpu::TextureFormat::Stencil8:
                return {};
            case wgpu::TextureFormat::Depth16Unorm:
                return {};
            case wgpu::TextureFormat::Depth24Plus:
                return {};
            case wgpu::TextureFormat::Depth24PlusStencil8:
                return {};
            case wgpu::TextureFormat::Depth32Float:
                return {};
            case wgpu::TextureFormat::Depth32FloatStencil8:
                return {};
            case wgpu::TextureFormat::BC1RGBAUnorm:
                return {};
            case wgpu::TextureFormat::BC1RGBAUnormSrgb:
                return {};
            case wgpu::TextureFormat::BC2RGBAUnorm:
                return {};
            case wgpu::TextureFormat::BC2RGBAUnormSrgb:
                return {};
            case wgpu::TextureFormat::BC3RGBAUnorm:
                return {};
            case wgpu::TextureFormat::BC3RGBAUnormSrgb:
                return {};
            case wgpu::TextureFormat::BC4RUnorm:
                return {};
            case wgpu::TextureFormat::BC4RSnorm:
                return {};
            case wgpu::TextureFormat::BC5RGUnorm:
                return {};
            case wgpu::TextureFormat::BC5RGSnorm:
                return {};
            case wgpu::TextureFormat::BC6HRGBUfloat:
                return {};
            case wgpu::TextureFormat::BC6HRGBFloat:
                return {};
            case wgpu::TextureFormat::BC7RGBAUnorm:
                return {};
            case wgpu::TextureFormat::BC7RGBAUnormSrgb:
                return {};
            case wgpu::TextureFormat::ETC2RGB8Unorm:
                return {};
            case wgpu::TextureFormat::ETC2RGB8UnormSrgb:
                return {};
            case wgpu::TextureFormat::ETC2RGB8A1Unorm:
                return {};
            case wgpu::TextureFormat::ETC2RGB8A1UnormSrgb:
                return {};
            case wgpu::TextureFormat::ETC2RGBA8Unorm:
                return {};
            case wgpu::TextureFormat::ETC2RGBA8UnormSrgb:
                return {};
            case wgpu::TextureFormat::EACR11Unorm:
                return {};
            case wgpu::TextureFormat::EACR11Snorm:
                return {};
            case wgpu::TextureFormat::EACRG11Unorm:
                return {};
            case wgpu::TextureFormat::EACRG11Snorm:
                return {};
            case wgpu::TextureFormat::ASTC4x4Unorm:
                return {};
            case wgpu::TextureFormat::ASTC4x4UnormSrgb:
                return {};
            case wgpu::TextureFormat::ASTC5x4Unorm:
                return {};
            case wgpu::TextureFormat::ASTC5x4UnormSrgb:
                return {};
            case wgpu::TextureFormat::ASTC5x5Unorm:
                return {};
            case wgpu::TextureFormat::ASTC5x5UnormSrgb:
                return {};
            case wgpu::TextureFormat::ASTC6x5Unorm:
                return {};
            case wgpu::TextureFormat::ASTC6x5UnormSrgb:
                return {};
            case wgpu::TextureFormat::ASTC6x6Unorm:
                return {};
            case wgpu::TextureFormat::ASTC6x6UnormSrgb:
                return {};
            case wgpu::TextureFormat::ASTC8x5Unorm:
                return {};
            case wgpu::TextureFormat::ASTC8x5UnormSrgb:
                return {};
            case wgpu::TextureFormat::ASTC8x6Unorm:
                return {};
            case wgpu::TextureFormat::ASTC8x6UnormSrgb:
                return {};
            case wgpu::TextureFormat::ASTC8x8Unorm:
                return {};
            case wgpu::TextureFormat::ASTC8x8UnormSrgb:
                return {};
            case wgpu::TextureFormat::ASTC10x5Unorm:
                return {};
            case wgpu::TextureFormat::ASTC10x5UnormSrgb:
                return {};
            case wgpu::TextureFormat::ASTC10x6Unorm:
                return {};
            case wgpu::TextureFormat::ASTC10x6UnormSrgb:
                return {};
            case wgpu::TextureFormat::ASTC10x8Unorm:
                return {};
            case wgpu::TextureFormat::ASTC10x8UnormSrgb:
                return {};
            case wgpu::TextureFormat::ASTC10x10Unorm:
                return {};
            case wgpu::TextureFormat::ASTC10x10UnormSrgb:
                return {};
            case wgpu::TextureFormat::ASTC12x10Unorm:
                return {};
            case wgpu::TextureFormat::ASTC12x10UnormSrgb:
                return {};
            case wgpu::TextureFormat::ASTC12x12Unorm:
                return {};
            case wgpu::TextureFormat::ASTC12x12UnormSrgb:
                return {};
            case wgpu::TextureFormat::R16Unorm:
                return {};
            case wgpu::TextureFormat::RG16Unorm:
                return {};
            case wgpu::TextureFormat::RGBA16Unorm:
                return {};
            case wgpu::TextureFormat::R16Snorm:
                return {};
            case wgpu::TextureFormat::RG16Snorm:
                return {};
            case wgpu::TextureFormat::RGBA16Snorm:
                return {};
            case wgpu::TextureFormat::R8BG8Biplanar420Unorm:
                return {};
            case wgpu::TextureFormat::R10X6BG10X6Biplanar420Unorm:
                return {};
            case wgpu::TextureFormat::R8BG8A8Triplanar420Unorm:
                return {};
            case wgpu::TextureFormat::R8BG8Biplanar422Unorm:
                return {};
            case wgpu::TextureFormat::R8BG8Biplanar444Unorm:
                return {};
            case wgpu::TextureFormat::R10X6BG10X6Biplanar422Unorm:
                return {};
            case wgpu::TextureFormat::R10X6BG10X6Biplanar444Unorm:
                return {};
            default:
                return DAWN_VALIDATION_ERROR("Value %i is invalid for WGPUTextureFormat.", value);
        }
    }

    MaybeError ValidateTextureSampleType(wgpu::TextureSampleType value) {
        switch (value) {
            case wgpu::TextureSampleType::Float:
                return {};
            case wgpu::TextureSampleType::UnfilterableFloat:
                return {};
            case wgpu::TextureSampleType::Depth:
                return {};
            case wgpu::TextureSampleType::Sint:
                return {};
            case wgpu::TextureSampleType::Uint:
                return {};
            default:
                return DAWN_VALIDATION_ERROR("Value %i is invalid for WGPUTextureSampleType.", value);
        }
    }

    MaybeError ValidateTextureViewDimension(wgpu::TextureViewDimension value) {
        switch (value) {
            case wgpu::TextureViewDimension::Undefined:
                return {};
            case wgpu::TextureViewDimension::e1D:
                return {};
            case wgpu::TextureViewDimension::e2D:
                return {};
            case wgpu::TextureViewDimension::e2DArray:
                return {};
            case wgpu::TextureViewDimension::Cube:
                return {};
            case wgpu::TextureViewDimension::CubeArray:
                return {};
            case wgpu::TextureViewDimension::e3D:
                return {};
            default:
                return DAWN_VALIDATION_ERROR("Value %i is invalid for WGPUTextureViewDimension.", value);
        }
    }

    MaybeError ValidateVertexFormat(wgpu::VertexFormat value) {
        switch (value) {
            case wgpu::VertexFormat::Uint8x2:
                return {};
            case wgpu::VertexFormat::Uint8x4:
                return {};
            case wgpu::VertexFormat::Sint8x2:
                return {};
            case wgpu::VertexFormat::Sint8x4:
                return {};
            case wgpu::VertexFormat::Unorm8x2:
                return {};
            case wgpu::VertexFormat::Unorm8x4:
                return {};
            case wgpu::VertexFormat::Snorm8x2:
                return {};
            case wgpu::VertexFormat::Snorm8x4:
                return {};
            case wgpu::VertexFormat::Uint16x2:
                return {};
            case wgpu::VertexFormat::Uint16x4:
                return {};
            case wgpu::VertexFormat::Sint16x2:
                return {};
            case wgpu::VertexFormat::Sint16x4:
                return {};
            case wgpu::VertexFormat::Unorm16x2:
                return {};
            case wgpu::VertexFormat::Unorm16x4:
                return {};
            case wgpu::VertexFormat::Snorm16x2:
                return {};
            case wgpu::VertexFormat::Snorm16x4:
                return {};
            case wgpu::VertexFormat::Float16x2:
                return {};
            case wgpu::VertexFormat::Float16x4:
                return {};
            case wgpu::VertexFormat::Float32:
                return {};
            case wgpu::VertexFormat::Float32x2:
                return {};
            case wgpu::VertexFormat::Float32x3:
                return {};
            case wgpu::VertexFormat::Float32x4:
                return {};
            case wgpu::VertexFormat::Uint32:
                return {};
            case wgpu::VertexFormat::Uint32x2:
                return {};
            case wgpu::VertexFormat::Uint32x3:
                return {};
            case wgpu::VertexFormat::Uint32x4:
                return {};
            case wgpu::VertexFormat::Sint32:
                return {};
            case wgpu::VertexFormat::Sint32x2:
                return {};
            case wgpu::VertexFormat::Sint32x3:
                return {};
            case wgpu::VertexFormat::Sint32x4:
                return {};
            case wgpu::VertexFormat::Unorm10_10_10_2:
                return {};
            default:
                return DAWN_VALIDATION_ERROR("Value %i is invalid for WGPUVertexFormat.", value);
        }
    }

    MaybeError ValidateVertexStepMode(wgpu::VertexStepMode value) {
        switch (value) {
            case wgpu::VertexStepMode::Undefined:
                return {};
            case wgpu::VertexStepMode::VertexBufferNotUsed:
                return {};
            case wgpu::VertexStepMode::Vertex:
                return {};
            case wgpu::VertexStepMode::Instance:
                return {};
            default:
                return DAWN_VALIDATION_ERROR("Value %i is invalid for WGPUVertexStepMode.", value);
        }
    }

    MaybeError ValidateWaitStatus(wgpu::WaitStatus value) {
        switch (value) {
            case wgpu::WaitStatus::Success:
                return {};
            case wgpu::WaitStatus::TimedOut:
                return {};
            case wgpu::WaitStatus::UnsupportedTimeout:
                return {};
            case wgpu::WaitStatus::UnsupportedCount:
                return {};
            case wgpu::WaitStatus::UnsupportedMixedSources:
                return {};
            case wgpu::WaitStatus::Unknown:
                return {};
            default:
                return DAWN_VALIDATION_ERROR("Value %i is invalid for WGPUWaitStatus.", value);
        }
    }


    MaybeError ValidateBufferUsage(wgpu::BufferUsage value) {
        if ((value & static_cast<wgpu::BufferUsage>(~1023)) == 0) {
            return {};
        }
        return DAWN_VALIDATION_ERROR("Value %i is invalid for WGPUBufferUsage.", value);
    }

    MaybeError ValidateColorWriteMask(wgpu::ColorWriteMask value) {
        if ((value & static_cast<wgpu::ColorWriteMask>(~15)) == 0) {
            return {};
        }
        return DAWN_VALIDATION_ERROR("Value %i is invalid for WGPUColorWriteMask.", value);
    }

    MaybeError ValidateHeapProperty(wgpu::HeapProperty value) {
        if ((value & static_cast<wgpu::HeapProperty>(~31)) == 0) {
            return {};
        }
        return DAWN_VALIDATION_ERROR("Value %i is invalid for WGPUHeapProperty.", value);
    }

    MaybeError ValidateMapMode(wgpu::MapMode value) {
        if ((value & static_cast<wgpu::MapMode>(~3)) == 0) {
            return {};
        }
        return DAWN_VALIDATION_ERROR("Value %i is invalid for WGPUMapMode.", value);
    }

    MaybeError ValidateShaderStage(wgpu::ShaderStage value) {
        if ((value & static_cast<wgpu::ShaderStage>(~7)) == 0) {
            return {};
        }
        return DAWN_VALIDATION_ERROR("Value %i is invalid for WGPUShaderStage.", value);
    }

    MaybeError ValidateTextureUsage(wgpu::TextureUsage value) {
        if ((value & static_cast<wgpu::TextureUsage>(~127)) == 0) {
            return {};
        }
        return DAWN_VALIDATION_ERROR("Value %i is invalid for WGPUTextureUsage.", value);
    }


} // namespace dawn::native
