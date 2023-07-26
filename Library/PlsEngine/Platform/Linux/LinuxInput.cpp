#include "LinuxInput.h"

namespace PlsEngine {
        
        Input* Input::s_instance = new LinuxInput();
        
        bool LinuxInput::isKeyPressed_p(int keycode) {
                auto window = static_cast<GLFWwindow*>(Application::get().getWindow().getNativeWindow());
                auto state = glfwGetKey(window, keycode);
                return state == GLFW_PRESS || state == GLFW_REPEAT;
        }
        
        bool isMouseButtonPressed_p(int button) {
                auto window = static_cast<GLFWwindow*>(Application::get().getWindow().getNativeWindow());
                auto state = glfwGetMouseButton(window, button);
                return state == GLFW_PRESS;
        }
        
        std::pair<float, float> getMousePosition_p()  {
                auto window = static_cast<GLFWwindow*>(Application::get().getWindow().getNativeWindow());
                double Ypos, Xpos;
                glfwGetCursorPos(window, &Xpos, &Ypos);
                return { (float)Xpos, (float)Ypos };
        }
        
        float getMouseY_p() {
                auto[x, y] = getMousePosition_p();
                return y;
        }
        
        float getMouseX_p() {
                auto[x, y] = getMousePosition_p();
                return x;
        }
}
