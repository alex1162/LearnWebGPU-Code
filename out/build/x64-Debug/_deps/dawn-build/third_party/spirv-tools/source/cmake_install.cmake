# Install script for directory: C:/Users/alexp/GitHub/LearnWebGPU-Code/out/build/x64-Debug/_deps/dawn-src/third_party/spirv-tools/src/source

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
  # Include the install script for the subdirectory.
  include("C:/Users/alexp/GitHub/LearnWebGPU-Code/out/build/x64-Debug/_deps/dawn-build/third_party/spirv-tools/source/opt/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/alexp/GitHub/LearnWebGPU-Code/out/build/x64-Debug/_deps/dawn-build/third_party/spirv-tools/source/reduce/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/alexp/GitHub/LearnWebGPU-Code/out/build/x64-Debug/_deps/dawn-build/third_party/spirv-tools/source/fuzz/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/alexp/GitHub/LearnWebGPU-Code/out/build/x64-Debug/_deps/dawn-build/third_party/spirv-tools/source/link/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/alexp/GitHub/LearnWebGPU-Code/out/build/x64-Debug/_deps/dawn-build/third_party/spirv-tools/source/lint/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/alexp/GitHub/LearnWebGPU-Code/out/build/x64-Debug/_deps/dawn-build/third_party/spirv-tools/source/diff/cmake_install.cmake")
endif()

