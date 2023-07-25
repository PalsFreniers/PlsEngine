#pragma once

#include <imgui.h>
// temporary //
#include <GLFW/glfw3.h>
#include <glad/glad.h>
// temporary //
#include "PlsEngine/Layer.h"
#include "imguiOpenGLRenderer.h"
#include "PlsEngine/Application.h"
#include "PlsEngine/Event/ApplicationEvent.h"
#include "PlsEngine/Event/KeyEvent.h"
#include "PlsEngine/Event/MouseEvent.h"

namespace PlsEngine {
    class ImGUILayer : public Layer {
    public:
        ImGUILayer();
        ~ImGUILayer();
        
        void OnAttach() override;
        void OnDetach() override;
        void OnUpdate() override;
        void OnEvent(PlsEngine::Event &e) override;
        
    private:
        bool OnMouseButtonPressedEvent(MouseButtonPressedEvent& e);
        bool OnMouseButtonReleasedEvent(MouseButtonReleasedEvent& e);
        bool OnMouseMovedEvent(MouseMovedEvent& e);
        bool OnMouseScrolledEvent(MouseScrolledEvent& e);
        bool OnKeyPressedEvent(KeyPressedEvent& e);
        bool OnKeyReleasedEvent(KeyReleaseEvent& e);
        bool OnKeyTypedEvent(KeyTypedEvent& e);
        bool OnWindowResizeEvent(WindowResizeEvent& e);
        
        float m_time = 0.0f;
    };
};
