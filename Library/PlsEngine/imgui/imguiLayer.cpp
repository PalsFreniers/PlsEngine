#include "imguiLayer.h"
#include "PlsEngine/Log.h"

namespace PlsEngine {
    
#define BIND_EVENT_FNC(x) std::bind(&x, this, std::placeholders::_1)
    
    ImGUILayer::ImGUILayer() :
        Layer("ImGUILayer") {
        ;
    }
    
    ImGUILayer::~ImGUILayer() {
        ;
    }
    
    void ImGUILayer::OnAttach() {
        ImGui::CreateContext();
        ImGui::StyleColorsDark();
        
        ImGuiIO& io = ImGui::GetIO();
        io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;
        io.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;
        
        // TODO : modify to PlsEngine KeyCodes
        io.KeyMap[ImGuiKey_Tab] = GLFW_KEY_TAB;
        io.KeyMap[ImGuiKey_LeftArrow] = GLFW_KEY_LEFT;
        io.KeyMap[ImGuiKey_RightArrow] = GLFW_KEY_RIGHT;
        io.KeyMap[ImGuiKey_UpArrow] = GLFW_KEY_UP;
        io.KeyMap[ImGuiKey_DownArrow] = GLFW_KEY_DOWN;
        io.KeyMap[ImGuiKey_PageUp] = GLFW_KEY_PAGE_UP;
        io.KeyMap[ImGuiKey_PageDown] = GLFW_KEY_PAGE_DOWN;
        io.KeyMap[ImGuiKey_Home] = GLFW_KEY_HOME;
        io.KeyMap[ImGuiKey_End] = GLFW_KEY_END;
        io.KeyMap[ImGuiKey_Insert] = GLFW_KEY_INSERT;
        io.KeyMap[ImGuiKey_Delete] = GLFW_KEY_DELETE;
        io.KeyMap[ImGuiKey_Backspace] = GLFW_KEY_BACKSPACE;
        io.KeyMap[ImGuiKey_Space] = GLFW_KEY_SPACE;
        io.KeyMap[ImGuiKey_Enter] = GLFW_KEY_ENTER;
        io.KeyMap[ImGuiKey_Escape] = GLFW_KEY_ESCAPE;
        io.KeyMap[ImGuiKey_A] = GLFW_KEY_A;
        io.KeyMap[ImGuiKey_C] = GLFW_KEY_C;
        io.KeyMap[ImGuiKey_V] = GLFW_KEY_V;
        io.KeyMap[ImGuiKey_X] = GLFW_KEY_X;
        io.KeyMap[ImGuiKey_Y] = GLFW_KEY_Y;
        io.KeyMap[ImGuiKey_Z] = GLFW_KEY_Z;
        
        ImGui_ImplOpenGL3_Init("#version 410");
    }
    
    void ImGUILayer::OnDetach() {
        ;
    }
    
    void ImGUILayer::OnUpdate() {
        ImGuiIO& io = ImGui::GetIO();
        Application& app = Application::get();
        io.DisplaySize = ImVec2(app.getWindow().GetWidth(), app.getWindow().GetHeight());
        
        ImGui_ImplOpenGL3_NewFrame();
        ImGui::NewFrame();
        
        float time = (float)glfwGetTime();
        io.DeltaTime = m_time > 0.0 ? (time - m_time) : (1.0f / 60.0f);
        m_time = time;
        
        static bool show = true;
        ImGui::ShowDemoWindow(&show);
        
        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    }
    
    void ImGUILayer::OnEvent(Event &e) {
        EventDispacher dispatcher(e);
        
        dispatcher.Dispach<MouseButtonPressedEvent>(BIND_EVENT_FNC(ImGUILayer::OnMouseButtonPressedEvent));
        dispatcher.Dispach<MouseButtonReleasedEvent>(BIND_EVENT_FNC(ImGUILayer::OnMouseButtonReleasedEvent));
        dispatcher.Dispach<MouseMovedEvent>(BIND_EVENT_FNC(ImGUILayer::OnMouseMovedEvent));
        dispatcher.Dispach<MouseScrolledEvent>(BIND_EVENT_FNC(ImGUILayer::OnMouseScrolledEvent));
        dispatcher.Dispach<KeyPressedEvent>(BIND_EVENT_FNC(ImGUILayer::OnKeyPressedEvent));
        dispatcher.Dispach<KeyReleaseEvent>(BIND_EVENT_FNC(ImGUILayer::OnKeyReleasedEvent));
        dispatcher.Dispach<KeyTypedEvent>(BIND_EVENT_FNC(ImGUILayer::OnKeyTypedEvent));
        dispatcher.Dispach<WindowResizeEvent>(BIND_EVENT_FNC(ImGUILayer::OnWindowResizeEvent));
    }
    
    bool ImGUILayer::OnMouseButtonPressedEvent(MouseButtonPressedEvent& e) {
        ImGuiIO& io = ImGui::GetIO();
        io.MouseDown[e.GetMouseButton()] = true;
        return false;
    }
    
    bool ImGUILayer::OnMouseButtonReleasedEvent(MouseButtonReleasedEvent& e) {
        ImGuiIO& io = ImGui::GetIO();
        io.MouseDown[e.GetMouseButton()] = false;
        return false;
    }
    
    bool ImGUILayer::OnMouseMovedEvent(MouseMovedEvent& e) {
        ImGuiIO& io = ImGui::GetIO();
        io.MousePos = ImVec2(e.GetX(), e.GetY());
        return false;
    }
    
    bool ImGUILayer::OnMouseScrolledEvent(MouseScrolledEvent& e) {
        ImGuiIO& io = ImGui::GetIO();
        io.MouseWheelH += e.GetXOffset();
        io.MouseWheel  += e.GetYOffset();
        return false;
    }

    bool ImGUILayer::OnKeyPressedEvent(KeyPressedEvent& e) {
        ImGuiIO& io = ImGui::GetIO();
        io.KeysDown[e.GetKeyCode()] = true;
        
        io.KeyCtrl  = io.KeysDown[GLFW_KEY_LEFT_CONTROL] || io.KeysDown[GLFW_KEY_RIGHT_CONTROL];
        io.KeyShift = io.KeysDown[GLFW_KEY_LEFT_SHIFT]   || io.KeysDown[GLFW_KEY_RIGHT_SHIFT];
        io.KeySuper = io.KeysDown[GLFW_KEY_LEFT_SUPER]   || io.KeysDown[GLFW_KEY_RIGHT_SUPER];
        io.KeyAlt   = io.KeysDown[GLFW_KEY_LEFT_ALT]     || io.KeysDown[GLFW_KEY_RIGHT_ALT];
        return false;
    }

    bool ImGUILayer::OnKeyReleasedEvent(KeyReleaseEvent& e) {
        ImGuiIO& io = ImGui::GetIO();
        io.KeysDown[e.GetKeyCode()] = false;
        
        io.KeyCtrl  = io.KeysDown[GLFW_KEY_LEFT_CONTROL] || io.KeysDown[GLFW_KEY_RIGHT_CONTROL];
        io.KeyShift = io.KeysDown[GLFW_KEY_LEFT_SHIFT]   || io.KeysDown[GLFW_KEY_RIGHT_SHIFT];
        io.KeySuper = io.KeysDown[GLFW_KEY_LEFT_SUPER]   || io.KeysDown[GLFW_KEY_RIGHT_SUPER];
        io.KeyAlt   = io.KeysDown[GLFW_KEY_LEFT_ALT]     || io.KeysDown[GLFW_KEY_RIGHT_ALT];
        return false;
        return false;
    }

    bool ImGUILayer::OnKeyTypedEvent(KeyTypedEvent& e) {
        ImGuiIO& io = ImGui::GetIO();
        int c = e.GetKeyCode();
        if(c > 0 && c < 0x10000) io.AddInputCharacter((unsigned short)c);
        return false;
    }

    bool ImGUILayer::OnWindowResizeEvent(WindowResizeEvent& e) {
        ImGuiIO& io = ImGui::GetIO();
        io.DisplaySize = ImVec2(e.GetWidth(), e.GetHeight());
        io.DisplayFramebufferScale = ImVec2(1.0f, 1.0f);
        glViewport(0, 0, e.GetWidth(), e.GetHeight());
        return false;
    }
}
