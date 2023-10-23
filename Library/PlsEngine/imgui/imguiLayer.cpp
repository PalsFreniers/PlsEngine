#include "PlsEngine/Application.h"
#include "imguiLayer.h"
#include "PlsEngine/Log.h"

namespace PlsEngine {
    
#define BIND_EVENT_FNC(x) std::bind(&x, this, std::placeholders::_1)
    
        ImGUILayer::ImGUILayer() : Layer("ImGUILayer") {
                ;
        }
        
        ImGUILayer::~ImGUILayer() {
                ;
        }
        
        void ImGUILayer::OnAttach() {
                IMGUI_CHECKVERSION();
                ImGui::CreateContext();
                ImGuiIO& io = ImGui::GetIO(); (void)io;
                io.ConfigFlags  |= ImGuiConfigFlags_NavEnableKeyboard
                                |  ImGuiConfigFlags_DockingEnable
                                |  ImGuiConfigFlags_ViewportsEnable;
                                
                ImGuiStyle& style = ImGui::GetStyle();
                if(io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable) {
                        style.WindowRounding = 0.0f;
                        style.Colors[ImGuiCol_WindowBg].w = 1.0f;
                }
                
                ImGui::StyleColorsDark();
                
                Application& app = Application::get();
                GLFWwindow* window = static_cast<GLFWwindow*>(app.getWindow().getNativeWindow());
                
                ImGui_ImplGlfw_InitForOpenGL(window, true);
                ImGui_ImplOpenGL3_Init("#version 410");
        }
        
        void ImGUILayer::OnDetach() {
                ImGui_ImplOpenGL3_Shutdown();
                ImGui_ImplGlfw_Shutdown();
                ImGui::DestroyContext();
        }
        
        void ImGUILayer::begin() {
                ImGui_ImplOpenGL3_NewFrame();
                ImGui_ImplGlfw_NewFrame();
                ImGui::NewFrame();
        }
        
        void ImGUILayer::end() {
                ImGuiIO& io = ImGui::GetIO();
                Application& app = Application::get();
                io.DisplaySize = ImVec2(app.getWindow().GetWidth(), app.getWindow().GetHeight());
                
                ImGui::Render();
                ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
                
                if(io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable) {
                        GLFWwindow* backup_current_context = glfwGetCurrentContext();
                        ImGui::UpdatePlatformWindows();
                        ImGui::RenderPlatformWindowsDefault();
                        glfwMakeContextCurrent(backup_current_context);
                }
        }
        
        void ImGUILayer::onImGuiRender() {
                static bool show = true;
                ImGui::ShowDemoWindow(&show);
        }
}
