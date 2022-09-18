cmake_minimum_required(VERSION 3.23)
project(PlsEngine)

set(CMAKE_CXX_STANDARD 23)

add_library(plsEngine SHARED Library/PlsEngine/Application.cpp Library/PlsEngine.h Library/PlsEngine/EntryPoint.h)

include_directories(Library)
add_executable(PlsSandbox Sandbox/Application.cpp)
target_link_libraries(PlsSandbox plsEngine)
