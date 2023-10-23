#pragma once

#include "Core.h"
#include "Event/Event.h"

namespace PlsEngine {
    class Layer {
    public:
        Layer(const std::string& name = "Layer");
        virtual ~Layer() = default;
        
        virtual void OnAttach() {}
        virtual void OnDetach() {}
        virtual void OnUpdate() {}
        virtual void onImGuiRender() {}
        virtual void OnEvent(Event& e) {}
        
        const std::string& GetName() const { return m_DebugName; }
    protected:
        std::string m_DebugName;
    };
}
