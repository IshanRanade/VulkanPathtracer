# Vulkan Pathtracer

## Setup

### MacOS

# Initial setup
1. Download Xcode
2. Download the vulkan sdk from online, it should download as a zip.  Unzip the file to any directory.
3. Set the environment variable VULKAN_SDK=/pathtodownloadedsdk/macOS: <br/>
`export VULKAN_SDK=/pathtodownloadedvulkansdkunzippedcontentss/macOS`
4. `xcode-select --install`
5. `brew install glfw` 

# Download and setup repo
1. Change to directory where you would like to download repo
2. `git clone git@github.com:IshanRanade/VulkanPathtracer.git`
3. `cd VulkanPathtracer`
5. `mkdir build`
6. `cd build`

# Run normally
1. `cmake ..`
2. `make`
3. `./VulkanPathtracer`

# Run through Xcode
1. `cmake -G Xcode ..
2. Open Xcode project, run through Xcode
