cmake_minimum_required(VERSION 3.8)
project(VulkanPathtracer CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -Wall")
set(CMAKE_BUILD_TYPE Debug)

# GLFW
find_package(glfw3 REQUIRED)

# Vulkan
find_package(Vulkan REQUIRED)
include_directories(${Vulkan_INCLUDE_DIRS})

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

# Imgui
set(IMGUI_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/include/imgui/imgui.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/imgui/imgui_demo.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/imgui/imgui_draw.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/imgui/imgui_widgets.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/imgui/imgui_impl_vulkan.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/imgui/imgui_impl_glfw.cpp
)

set(CPP_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/pathtracer.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/pathtracer.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/utilities.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/utilities.cpp
)

add_executable(${CMAKE_PROJECT_NAME} ${CPP_SOURCES} ${IMGUI_SOURCES})

source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}"
    PREFIX "Source Files"
    FILES ${CPP_SOURCES} ${IMGUI_SOURCES})

target_link_libraries(${CMAKE_PROJECT_NAME} glfw ${Vulkan_LIBRARIES})
