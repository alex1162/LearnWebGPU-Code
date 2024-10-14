# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "C:/Users/alexp/GitHub/LearnWebGPU-Code/out/build/x64-Debug/_deps/dawn-src"
  "C:/Users/alexp/GitHub/LearnWebGPU-Code/out/build/x64-Debug/_deps/dawn-build"
  "C:/Users/alexp/GitHub/LearnWebGPU-Code/out/build/x64-Debug/_deps/dawn-subbuild/dawn-populate-prefix"
  "C:/Users/alexp/GitHub/LearnWebGPU-Code/out/build/x64-Debug/_deps/dawn-subbuild/dawn-populate-prefix/tmp"
  "C:/Users/alexp/GitHub/LearnWebGPU-Code/out/build/x64-Debug/_deps/dawn-subbuild/dawn-populate-prefix/src/dawn-populate-stamp"
  "C:/Users/alexp/GitHub/LearnWebGPU-Code/out/build/x64-Debug/_deps/dawn-subbuild/dawn-populate-prefix/src"
  "C:/Users/alexp/GitHub/LearnWebGPU-Code/out/build/x64-Debug/_deps/dawn-subbuild/dawn-populate-prefix/src/dawn-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "C:/Users/alexp/GitHub/LearnWebGPU-Code/out/build/x64-Debug/_deps/dawn-subbuild/dawn-populate-prefix/src/dawn-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "C:/Users/alexp/GitHub/LearnWebGPU-Code/out/build/x64-Debug/_deps/dawn-subbuild/dawn-populate-prefix/src/dawn-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
