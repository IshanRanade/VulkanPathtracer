cmake_minimum_required(VERSION 3.8)
project(VulkanPathtracer)

set(CMAKE_CXX_STANDARD 11)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -Wall")

add_executable(${CMAKE_PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp)

find_package (Vulkan)
    if (Vulkan_FOUND)
    include_directories(${Vulkan_INCLUDE_DIRS})
    target_link_libraries (${CMAKE_PROJECT_NAME} ${Vulkan_LIBRARIES})
endif (Vulkan_FOUND)
