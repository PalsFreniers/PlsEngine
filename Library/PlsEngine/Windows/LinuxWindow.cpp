#include "LinuxWindow.h"

#include <glad/glad.h>

namespace PlsEngine {
    static bool s_GLFWInitialized = false;
    
    static void GLFWErrorCallback(int error, const char* descritption) {
        CORE_ERROR("GLFWError code : <{0}, \"{1}\"> ", error, descritption);
    }
    
    Window* Window::Create(const WindowProps& props) {
        return new LinuxWindow(props);
    }
    
    LinuxWindow::LinuxWindow(const WindowProps& props) {
        Init(props);
    }
    
    LinuxWindow::~LinuxWindow() {Shutdown();}
    
    void LinuxWindow::Init(const WindowProps& props) {
        m_Data.Title = props.Title;
        m_Data.Width = props.Width;
        m_Data.Height = props.Height;
        
        CORE_INFO("Initialisation : creating window <{0}, {1}, {2}>", props.Title, props.Width, props.Height);
        if (!s_GLFWInitialized) {
            int success = glfwInit();
            if(!success) {
                CORE_ERROR("GLFW Initialisation Error (could not initialise GLFW)");
                exit(1);
            }
            glfwSetErrorCallback(GLFWErrorCallback);
            s_GLFWInitialized = true;
        }
        
        m_window = glfwCreateWindow((int)props.Width, (int)props.Height, m_Data.Title.c_str(), nullptr, nullptr);
        glfwMakeContextCurrent(m_window);
        int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
        if(!status) CORE_ERROR("Failed to initialize Glad!");
        glfwSetWindowUserPointer(m_window, &m_Data);
        SetVSync(true);
        
        //Set GLFW Callbacks
        //Keyboard Events
        glfwSetKeyCallback(m_window, [](GLFWwindow* window, int key, int scancode, int action, int mods) {
            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
            switch(action) {
                case GLFW_PRESS:
                {
                    KeyPressedEvent e(key, 0);
                    data.EventCallBack(e);
                    break;
                }
                case GLFW_RELEASE:
                {
                    KeyReleaseEvent e(key);
                    data.EventCallBack(e);
                    break;
                }
                case GLFW_REPEAT:
                {
                    KeyPressedEvent e(key, 1);
                    data.EventCallBack(e);
                    break;
                }
            }
        });
        
        glfwSetCharCallback(m_window, [](GLFWwindow* window, unsigned int character) {
            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
            KeyTypedEvent e(character);
            data.EventCallBack(e);
        });
        
        //MouseEvents
        glfwSetMouseButtonCallback(m_window, [](GLFWwindow* window, int buttons, int action, int mods) {
            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
            
            switch(action) {
                case GLFW_PRESS:
                {
                    MouseButtonPressedEvent e(buttons);
                    data.EventCallBack(e);
                    break;
                }
                case GLFW_RELEASE:
                {
                    MouseButtonReleasedEvent e(buttons);
                    data.EventCallBack(e);
                    break;
                }
            }
        });
        
        glfwSetScrollCallback(m_window, [](GLFWwindow* window, double xOffset, double yOffset) {
            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
            
            MouseScrolledEvent e((float)xOffset, (float)yOffset);
            data.EventCallBack(e);
        });
        
        glfwSetCursorPosCallback(m_window, [](GLFWwindow* window, double x, double y) {
           WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
           
           MouseMovedEvent e((float)x, (float)y);
           data.EventCallBack(e);
        });
        
        //Application Events
        glfwSetWindowSizeCallback(m_window, [](GLFWwindow* window, int width, int height) {
            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
            data.Width = width;
            data.Height = height;
            
            WindowResizeEvent e(width, height);
            data.EventCallBack(e);
        });
        
        glfwSetWindowCloseCallback(m_window, [](GLFWwindow* window){
            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
            WindowCloseEvent e;
            data.EventCallBack(e);
        });
    }
    
    void LinuxWindow::Shutdown() {
        glfwDestroyWindow(m_window);
    }
    
    void LinuxWindow::OnUpdate() {
        glfwPollEvents();
        glfwSwapBuffers(m_window);
    }
    
    void LinuxWindow::SetVSync(bool enabled) {
        if(enabled)
            glfwSwapInterval(1);
        else
            glfwSwapInterval(0);
        
        m_Data.VSync = enabled;
    }
    
    bool LinuxWindow::IsVSync() const {
        return m_Data.VSync;
    }
}
