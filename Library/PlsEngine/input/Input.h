#pragma once

#include "Keycodes.h"
#include "MouseButtons.h"

namespace PlsEngine {
        class Input {
        public:
                inline static bool isKeyPressed(int keycode)  { return s_instance->isKeyPressed_p(keycode); }
                inline static bool isMouseButtonPressed(int button)  { return s_instance->isMouseButtonPressed_p(button); }
                inline static std::pair<float, float> getMousePosition() {return s_instance->getMousePosition_p(); }
                inline static float getMouseY()  { return s_instance->getMouseY_p(); }
                inline static float getMouseX()  { return s_instance->getMouseX_p(); }
                
        protected:
                virtual bool isKeyPressed_p(int keycode) = 0;
                virtual bool isMouseButtonPressed_p(int button) = 0;
                virtual std::pair<float, float> getMousePosition_p() = 0;
                virtual float getMouseY_p() = 0;
                virtual float getMouseX_p() = 0;
                
        private:
                static Input* s_instance;
        };
}
