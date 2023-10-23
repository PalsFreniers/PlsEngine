#include "PlsIncludes.h"
#include "LayerStack.h"

namespace PlsEngine {
        LayerStack::~LayerStack() {
                for(Layer* l : m_Layers) {
                        l->OnDetach();
                        delete l;
                }
        }
        
        void LayerStack::PushLayer(Layer* layer) {
                m_Layers.emplace(m_Layers.begin() + m_LayersInsert, layer);
                m_LayersInsert++;
        }
        
        void LayerStack::PushOverlay(Layer* overlay) {
                m_Layers.emplace_back(overlay);
        }
        
        void LayerStack::PopLayer(Layer* layer) {
                auto it = std::find(m_Layers.begin(), m_Layers.begin() + m_LayersInsert, layer);
                if(it != m_Layers.end()) {
                        layer->OnDetach();
                        m_Layers.erase(it);
                        m_LayersInsert--;
                }
        }
        
        void LayerStack::PopOverlay(Layer* overlay) {
                auto it = std::find(m_Layers.begin() + m_LayersInsert, m_Layers.end(), overlay);
                if(it != m_Layers.end()) {
                        overlay->OnDetach();
                        m_Layers.erase(it);
                }
        }
}
