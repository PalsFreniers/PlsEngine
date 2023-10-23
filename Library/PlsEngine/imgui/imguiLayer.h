#pragma once

#include <imgui.h>
#include <backends/imgui_impl_opengl3.h>
#include <backends/imgui_impl_glfw.h>
// temporary //
#include <GLFW/glfw3.h>
#include <glad/glad.h>
// temporary //
#include "PlsEngine/Layer.h"
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
                
                void onImGuiRender() override;
                
                void begin();
                void end();
        private:
                float m_time = 0.0f;
        };
};
