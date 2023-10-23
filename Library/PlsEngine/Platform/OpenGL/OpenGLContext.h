#ifndef OPENGL_CONTEXT_H
#define OPENGL_CONTEXT_H

#include "PlsEngine/Log.h"

#include "PlsEngine/Renderer/GraphicsContext.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace PlsEngine {
        class OpenGLContext : public GraphicsContext {
        public:
                OpenGLContext(GLFWwindow *windowHandle);

                void Init() override;
                void SwapBuffers() override;
        private:
                GLFWwindow *m_windowHandle;
        };
}

#endif
