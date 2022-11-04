cmake_minimum_required(VERSION 3.18)
project(PlsEngine)

set(CMAKE_CXX_STANDARD 11)
link_libraries(glfw GL)
include_directories(Library/vendor/spdlog/include)

add_library(plsEngine SHARED Library/PlsEngine/Application.cpp
                                                  Library/PlsEngine/Log.cpp
                                                  Library/PlsEngine/Windows/LinuxWindow.cpp
                                                  Library/PlsEngine/Layer.cpp
                                                  Library/PlsEngine/LayerStack.cpp)


include_directories(Library)
add_executable(PlsSandbox Sandbox/Application.cpp)
target_link_libraries(PlsSandbox plsEngine)
