cmake_minimum_required(VERSION 3.8)
project(VulkanPathtracer)

set(CMAKE_CXX_STANDARD 14)

add_executable(${CMAKE_PROJECT_NAME} ${PROJECT_SOURCE_DIR}/main.cpp)

find_package (Vulkan)
    if (Vulkan_FOUND)
    include_directories(${Vulkan_INCLUDE_DIRS})
    target_link_libraries (${CMAKE_PROJECT_NAME} ${Vulkan_LIBRARIES})
endif (Vulkan_FOUND)
