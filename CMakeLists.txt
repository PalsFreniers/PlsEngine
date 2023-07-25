cmake_minimum_required(VERSION 3.18)
project(PlsEngine)

set(CMAKE_CXX_STANDARD 17)

add_definitions(-DGLFW_INCLUDE_NONE)

link_libraries(glfw GL)

include_directories(Library/vendor/spdlog/include)
include_directories(Library/vendor/GLAD/include)
include_directories(Library/vendor/ImGui)

add_library(plsEngine SHARED Library/PlsEngine/Application.cpp
                                            Library/PlsEngine/Log.cpp
                                            Library/PlsEngine/Windows/LinuxWindow.cpp
                                            Library/PlsEngine/Layer.cpp
                                            Library/PlsEngine/LayerStack.cpp
                                            Library/PlsEngine/imgui/imguiLayer.cpp
                                            Library/PlsEngine/imgui/imguiOpenGLRenderer.cpp
                                            Library/vendor/GLAD/src/glad.c
                                            Library/vendor/ImGui/imgui.cpp
                                            Library/vendor/ImGui/imgui_draw.cpp
                                            Library/vendor/ImGui/imgui_tables.cpp
                                            Library/vendor/ImGui/imgui_widgets.cpp
                                            Library/vendor/ImGui/imgui_demo.cpp)


include_directories(Library)
add_executable(PlsSandbox Sandbox/Application.cpp)
target_link_libraries(PlsSandbox plsEngine)
