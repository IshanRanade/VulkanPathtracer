# Vulkan Pathtracer

## Setup

### MacOS

#### Initial setup
1. Download Xcode
2. Download the vulkan sdk from online, it should download as a zip.  Unzip the file to any directory.
3. Set the environment variable VULKAN_SDK=/pathtodownloadedsdk/macOS: <br/>
`export VULKAN_SDK=/pathtodownloadedvulkansdkunzippedcontentss/macOS` <br/>
You need to run this command in the terminal window that you use to run cmake so the terminal knows this variable.
4. `xcode-select --install`
5. If glfw is not installed, then do: <br/>
`brew install glfw --HEAD`
6. If glfw is installed, then do: <br/>
`brew uninstall glfw` <br/>
`brew install glfw --HEAD`

#### Download and setup repo
1. Change to directory where you would like to download repo
2. `git clone git@github.com:IshanRanade/VulkanPathtracer.git`
3. `cd VulkanPathtracer`
5. `mkdir build`
6. `cd build`

#### Run normally
1. `cmake ..`
2. `make`
3. `./VulkanPathtracer`

#### Run through Xcode
https://vulkan.lunarg.com/doc/sdk/1.1.92.1/mac/getting_started.html
1. `cmake -G Xcode ..
2. Open Xcode project, run through Xcode
3. Press Command + Shift + <, this allows you to edit the Scheme for this project.  Add to the arguments tab the following environment variables: <br/> 
VK_ICD_FILENAMES = /pathtosdk/macOS/etc/vulkan/icd.d/MoltenVK_icd.json
VK_LAYER_PATH = /pathtosdk/macOS/etc/vulkan/explicit_layer.d
