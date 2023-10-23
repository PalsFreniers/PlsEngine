//
// Created by tidian on 18/09/22.
//

#include "Application.h"
#include "Log.h"

#include <glad/glad.h>
#include <SFML/Graphics.hpp>

namespace PlsEngine {
    
#define BIND_EVENT_FNC(x) std::bind(&x, this, std::placeholders::_1)
    
        Application* Application::s_Instance = nullptr;
    
        Application::Application() {
                if(s_Instance) {
                        CORE_ERROR("Application Already Exist!");
                        exit(1);
                }
                s_Instance = this;
                
                m_Window = std::unique_ptr<Window>(Window::Create());
                m_Window->SetEventCallback(BIND_EVENT_FNC(Application::OnEvent));
                
                m_ImGUILayer = new ImGUILayer();
                PushLayer(m_ImGUILayer, true);
        }

        Application::~Application() {

        }
    
        void Application::PushLayer(Layer* layer, bool overlay) {
                if(overlay) m_LayerStack.PushOverlay(layer);
                else m_LayerStack.PushLayer(layer);
                layer->OnAttach();
        }

        void Application::Run() {
                while(m_Running) {
                        glClearColor(1, 0, 1, 1);
                        glClear(GL_COLOR_BUFFER_BIT);
                        for(Layer* l : m_LayerStack) l->OnUpdate();
                        
                        m_ImGUILayer->begin();
                        for(Layer* l : m_LayerStack) l->onImGuiRender();
                        m_ImGUILayer->end();
                        
                        m_Window->OnUpdate();
                }
        }
    
        void Application::OnEvent(Event& e) {
                EventDispacher disp(e);
                disp.Dispach<WindowCloseEvent>(BIND_EVENT_FNC(Application::OnWindowClose));
                // CORE_TRACE("{0}", e);
                for(auto it = m_LayerStack.end(); it != m_LayerStack.begin();) {
                        (*--it)->OnEvent(e);
                        if(e.m_Handled) break;
                }
        }
    
        bool Application::OnWindowClose(WindowCloseEvent& e) {
                m_Running = false;
                return true;
        }
} // PlsEngine
