#include "OpenGLContext.h"

namespace PlsEngine {
        OpenGLContext::OpenGLContext(GLFWwindow *windowHandle) : m_windowHandle(windowHandle){
                if(!m_windowHandle) CORE_ERROR("Null window handle");
        }

        void OpenGLContext::Init() {
                glfwMakeContextCurrent(m_windowHandle);
                int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
                if(!status) CORE_ERROR("Failed to initialize Glad!");
        }

        void OpenGLContext::SwapBuffers() {
                glfwSwapBuffers(m_windowHandle);
        }
}
