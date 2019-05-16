#pragma once

#include <vulkan/vulkan.h>

class PathTracer {
public:
    int width;
    int height;
    
    VkPhysicalDevice physicalDevice;
    VkDevice device;
    VkPipeline pipeline;
    VkPipelineLayout pipelineLayout;
    VkShaderModule computeShaderModule;
    VkCommandPool commandPool;
    VkCommandBuffer commandBuffer;
    VkDescriptorPool descriptorPool;
    VkDescriptorSet descriptorSet;
    VkDescriptorSetLayout descriptorSetLayout;
    VkBuffer buffer;
    VkDeviceMemory bufferMemory;
    VkQueue queue;
    uint32_t queueFamilyIndex;
    
    PathTracer(int width, int height, VkPhysicalDevice physicalDevice);
    
    void setup();
    
private:
    void getComputeQueueFamilyIndex();
};
