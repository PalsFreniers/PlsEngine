#pragma once

#include <GLFW/glfw3.h>

#include "PlsIncludes.h"
#include "PlsEngine/Application.h"
#include "PlsEngine/input/Input.h"

namespace PlsEngine {
        class LinuxInput : public Input {
        protected:
                bool isKeyPressed_p(int keycode) override;
                bool isMouseButtonPressed_p(int button) override;
                std::pair<float, float> getMousePosition_p() override;
                float getMouseY_p() override;
                float getMouseX_p() override;
        };
}

