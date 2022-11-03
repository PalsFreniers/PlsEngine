//
// Created by tidian on 18/09/22.
//

#include "Application.h"
#include "Log.h"

namespace PlsEngine {
    
#define BIND_EVENT_FNC(x) std::bind(&x, this, std::placeholders::_1)
    
    Application::Application() {
        m_Window = std::unique_ptr<Window>(Window::Create());
        m_Window->SetEventCallback(BIND_EVENT_FNC(Application::OnEvent));
    }

    Application::~Application() {

    }

    void Application::Run() {
        while(m_Running) {
            m_Window->OnUpdate();
        }
    }
    
    void Application::OnEvent(Event& e) {
        CORE_TRACE("{0}", e);
        EventDispacher disp(e);
        disp.Dispach<WindowCloseEvent>(BIND_EVENT_FNC(Application::OnWindowClose));
    }
    
    bool Application::OnWindowClose(WindowCloseEvent& e) {
        m_Running = false;
        return true;
    }
} // PlsEngine
