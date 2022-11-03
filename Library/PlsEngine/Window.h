#ifndef PLSENGINE_WINDOW_H
#define PLSENGINE_WINDOW_H

#include "PlsIncludes.h"

#include "PlsEngine/Core.h"
#include "PlsEngine/Event/Event.h"

namespace PlsEngine {
    struct WindowProps {
        std::string Title;
        unsigned int Width, Height;
        
        WindowProps(const std::string& title = "PlaceholderTitle", unsigned int width = 800, unsigned int height = 600) : Title(title), Width(width), Height(height) {}
    };
    
    class Window {
    public:
        using EventCallbackFn = std::function<void(Event&)>;
        
        virtual ~Window() {}
        
        virtual void OnUpdate() = 0;
        
        virtual unsigned int GetWidth() const = 0;
        virtual unsigned int GetHeight() const = 0;
        
        //Window attributes
        virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
        virtual void SetVSync(bool enabled) = 0;
        virtual bool IsVSync() const = 0;
        
        static Window* Create(const WindowProps& props = WindowProps());
    };
};

#endif
