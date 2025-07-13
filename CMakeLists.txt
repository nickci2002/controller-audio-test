cmake_minimum_required(VERSION 3.23)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(ControllerAudioTest VERSION 1.0)

find_package(SDL3 3.1.2 CONFIG)

add_subdirectory(externals)
include_directories(src)

set(SOURCE
  src/test.cpp
)

add_executable(controlleraudiotest ${SOURCE})
target_link_libraries(controlleraudiotest PRIVATE SDL3::SDL3)
