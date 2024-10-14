#pragma once

typedef struct WGPUDeviceDescriptor {
    WGPUChainedStruct const* nextInChain;
    WGPU_NULLABLE char const* label;
    size_t requiredFeatureCount;
    WGPUFeatureName const* requiredFeatures;
    WGPU_NULLABLE WGPURequiredLimits const* requiredLimits;
    WGPUQueueDescriptor defaultQueue;
    WGPUDeviceLostCallback deviceLostCallback;
    void* deviceLostUserdata;
} WGPUDeviceDescriptor;

// (this struct definition is actually above)
typedef struct WGPUQueueDescriptor {
    WGPUChainedStruct const* nextInChain;
    WGPU_NULLABLE char const* label;
} WGPUQueueDescriptor;