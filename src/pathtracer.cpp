#include "pathtracer.h"
#include <vector>
#include "utilities.h"

PathTracer::PathTracer(int width, int height, VkPhysicalDevice physicalDevice)
: width(width), height(height), physicalDevice(physicalDevice) {
    
}

void PathTracer::setup() {
    // First find the compute queue family index and save it
    getComputeQueueFamilyIndex();
    
    //
}

void PathTracer::getComputeQueueFamilyIndex() {
    uint32_t queueFamilyCount;
    
    vkGetPhysicalDeviceQueueFamilyProperties(physicalDevice, &queueFamilyCount, NULL);
    
    // Retrieve all queue families
    std::vector<VkQueueFamilyProperties> queueFamilies(queueFamilyCount);
    vkGetPhysicalDeviceQueueFamilyProperties(physicalDevice, &queueFamilyCount, queueFamilies.data());
    
    // Find a family that supports compute operations
    uint32_t i = 0;
    for (; i < queueFamilies.size(); ++i) {
        VkQueueFamilyProperties props = queueFamilies[i];
        
        if (props.queueCount > 0 && (props.queueFlags & VK_QUEUE_COMPUTE_BIT)) {
            // found a queue with compute. We're done!
            break;
        }
    }
    
    if (i == queueFamilies.size()) {
        throw std::runtime_error("could not find a queue family that supports operations");
    }
    
    queueFamilyIndex = i;
}


