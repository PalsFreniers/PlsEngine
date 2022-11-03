#ifndef PLSENGINE_LINUX_WINDOW_H
#define PLSENGINE_LINUX_WINDOW_H

#include "PlsEngine/Window.h"

#include <GLFW/glfw3.h>

namespace PlsEngine {
    class LinuxWindow : public Window {
    private:
        GLFWwindow* m_window;
        
        
        struct WindowData {
            std::string Title;
            unsigned int Width, Height;
            bool VSync;
            
            EventCallbackFn EventCallBack;
        };
        
        WindowData m_Data;
        
    private:
        virtual void Init(const WindowProps& props);
        virtual void Shutdown();
    public:
        LinuxWindow(const WindowProps& props);
        virtual ~LinuxWindow();
        
        void OnUpdate() override;
        
        inline unsigned int GetWidth() const override {return m_Data.Width;}
        inline unsigned int GetHeight() const override {return m_Data.Height;}
        
        inline void SetEventCallback(const EventCallbackFn& callback) override {m_Data.EventCallBack = callback;}
        
        void SetVSync(bool enabled) override;
        bool IsVSync() const override;
    };
};

#endif
