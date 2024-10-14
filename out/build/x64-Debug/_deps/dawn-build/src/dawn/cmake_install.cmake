# Install script for directory: C:/Users/alexp/GitHub/LearnWebGPU-Code/out/build/x64-Debug/_deps/dawn-src/src/dawn

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Users/alexp/GitHub/LearnWebGPU-Code/out/install/x64-Debug")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("C:/Users/alexp/GitHub/LearnWebGPU-Code/out/build/x64-Debug/_deps/dawn-build/src/dawn/partition_alloc/cmake_install.cmake")
  include("C:/Users/alexp/GitHub/LearnWebGPU-Code/out/build/x64-Debug/_deps/dawn-build/src/dawn/common/cmake_install.cmake")
  include("C:/Users/alexp/GitHub/LearnWebGPU-Code/out/build/x64-Debug/_deps/dawn-build/src/dawn/platform/cmake_install.cmake")
  include("C:/Users/alexp/GitHub/LearnWebGPU-Code/out/build/x64-Debug/_deps/dawn-build/src/dawn/native/cmake_install.cmake")
  include("C:/Users/alexp/GitHub/LearnWebGPU-Code/out/build/x64-Debug/_deps/dawn-build/src/dawn/wire/cmake_install.cmake")
  include("C:/Users/alexp/GitHub/LearnWebGPU-Code/out/build/x64-Debug/_deps/dawn-build/src/dawn/utils/cmake_install.cmake")
  include("C:/Users/alexp/GitHub/LearnWebGPU-Code/out/build/x64-Debug/_deps/dawn-build/src/dawn/glfw/cmake_install.cmake")

endif()

