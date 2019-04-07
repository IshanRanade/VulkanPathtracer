# Vulkan Pathtracer

## Setup

### MacOS

1. Download the vulkan sdk from online, it should download as a zip.  Unzip the file to any directory.
2. Set the environment variable VULKAN_SDK=/pathtodownloadedsdk/macOS: <br/>
`export VULKAN_SDK=/pathtodownloadedsdk/macOS`
3. `cd` to the root of the directory
4. `brew install glfw`
5. `mkdir build`
6. `cd build`
7. `cmake ..`
8. `make`
9. `./VulkanPathtracer`