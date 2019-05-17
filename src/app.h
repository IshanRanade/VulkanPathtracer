#pragma once

#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <imgui/imgui.h>
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <vulkan/vulkan.h>
#include <imgui/imgui_impl_glfw.h>
#include <imgui/imgui_impl_vulkan.h>
#include <exception>
#include <stdexcept>

#include "pathtracer.h"


class App {
public:
    VkAllocationCallbacks*   g_Allocator = NULL;
    VkInstance               g_Instance = VK_NULL_HANDLE;
    VkPhysicalDevice         g_PhysicalDevice = VK_NULL_HANDLE;
    VkDevice                 g_Device = VK_NULL_HANDLE;
    uint32_t                 g_QueueFamily = (uint32_t)-1;
    VkQueue                  g_Queue = VK_NULL_HANDLE;
    VkDebugReportCallbackEXT g_DebugReport = VK_NULL_HANDLE;
    VkPipelineCache          g_PipelineCache = VK_NULL_HANDLE;
    VkDescriptorPool         g_DescriptorPool = VK_NULL_HANDLE;
    
    uint32_t                 c_QueueFamily = (uint32_t)-1;
    VkQueue                  c_Queue = VK_NULL_HANDLE;
    VkDebugReportCallbackEXT c_DebugReport = VK_NULL_HANDLE;
    VkPipelineCache          c_PipelineCache = VK_NULL_HANDLE;
    VkDescriptorPool         c_DescriptorPool = VK_NULL_HANDLE;
    
    GLFWwindow *window;
    ImGui_ImplVulkanH_Window* wd;
    ImVec4 clear_color;
    VkResult err;
    
    PathTracer *pathtracer;
    
    ImGui_ImplVulkanH_Window g_MainWindowData;
    int                      g_MinImageCount = 2;
    bool                     g_SwapChainRebuild = false;
    int                      g_SwapChainResizeWidth = 0;
    int                      g_SwapChainResizeHeight = 0;
    
    App();
    
    void check_vk_result(VkResult err);
    void SetupVulkan(const char** extensions, uint32_t extensions_count);
    void SetupVulkanWindow(ImGui_ImplVulkanH_Window* wd, VkSurfaceKHR surface, int width, int height);
    void CleanupVulkan();
    void CleanupVulkanWindow();
    void FrameRender(ImGui_ImplVulkanH_Window* wd);
    void FramePresent(ImGui_ImplVulkanH_Window* wd);
    void glfw_error_callback(int error, const char* description);
    void glfw_resize_callback(GLFWwindow*, int w, int h);
    
    int start();
};
