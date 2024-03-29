//
// Created by tidian on 18/09/22.
//

#ifndef PLSENGINE_APPLICATION_H
#define PLSENGINE_APPLICATION_H

#include "PlsEngine/Core.h"
#include "PlsEngine/LayerStack.h"
#include "PlsEngine/imgui/imguiLayer.h"
#include "PlsEngine/Event/Event.h"
#include "PlsEngine/Event/KeyEvent.h"
#include "PlsEngine/Event/MouseEvent.h"
#include "PlsEngine/Event/ApplicationEvent.h"
#include "PlsEngine/input/Input.h"
#include "PlsEngine/Window.h"

namespace PlsEngine {

    class Application {
    public:
        Application();
        virtual ~Application();

        void Run();
        
        void OnEvent(Event& e);
        
        void PushLayer(Layer* layer, bool overlay);
    
        inline static Application& get() { return *s_Instance; }
        inline Window& getWindow() { return *m_Window; }
    
    private:
        bool OnWindowClose(WindowCloseEvent& e);
        
        bool m_Running = true;
        std::unique_ptr<Window> m_Window;
        ImGUILayer* m_ImGUILayer;
        LayerStack m_LayerStack;
        
        static Application* s_Instance;
    };

    //to be defined in client
    Application* CreateApplication();

} // PlsEngine

#endif //PLSENGINE_APPLICATION_H
