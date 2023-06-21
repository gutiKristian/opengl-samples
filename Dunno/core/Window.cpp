//
// Created by krist on 22. 4. 2023.
//
#include <format>

#include "glad/glad.h"
#include "glm/ext.hpp"
#include "GLFW/glfw3.h"
#include "Window.h"
#include "Log.h"
#include "Event.h"

namespace Dunno
{
    Window::Window(std::string title, int width, int height)
    {
        m_data.title = std::move(title);
        m_data.width = width;
        m_data.height = height;

        this->Initialize();
    }

    Window::~Window()
    {
        glfwDestroyWindow(m_window);
    }

    void Window::Initialize()
    {
        Log::Init();

        if (!glfwInit())
        {
            LOG_CRITICAL("GLFW failed to initialize!");
        }

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);


        m_window = glfwCreateWindow(m_data.width, m_data.height, m_data.title.c_str(), nullptr, nullptr);

        if (m_window == nullptr)
        {
            LOG_CRITICAL("Failed to create GLFW window");
            glfwTerminate();
        }

        glfwMakeContextCurrent(m_window);

        // init glad
        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        {
            LOG_CRITICAL("Failed to initialize GLAD");
        }


        LOG_INFO("OpenGL Info:");
        LOG_INFO("  Vendor: {0}", reinterpret_cast<const char*>(glGetString(GL_VENDOR)));
        LOG_INFO("  Renderer: {0}", reinterpret_cast<const char*>(glGetString(GL_RENDERER)));
        LOG_INFO("  Version: {0}", reinterpret_cast<const char*>(glGetString(GL_VERSION)));

        // Set pointer for callback access
        glfwSetWindowUserPointer(m_window, &m_data);

        // Callbacks
        glfwSetFramebufferSizeCallback(m_window, [](GLFWwindow *window, int width, int height)
        {
            WindowData& data = *(WindowData *) glfwGetWindowUserPointer(window);
            data.width = width;
            data.height = height;
        });

        glfwSetWindowCloseCallback(m_window, [](GLFWwindow* window)
        {
            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
            WindowCloseEvent event;
            data.callback(event);
        });

        glfwSetKeyCallback(m_window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
        {
            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

            switch (action)
            {
                case GLFW_PRESS:
                {
                    KeyPressedEvent event(key, false);
                    data.callback(event);
                    break;
                }
                case GLFW_RELEASE:
                {
                    KeyReleasedEvent event(key);
                    data.callback(event);
                    break;
                }
                case GLFW_REPEAT:
                {
                    KeyPressedEvent event(key, true);
                    data.callback(event);
                    break;
                }
                default:
                    break;
            }
        });

//        glfwSetCharCallback(m_window, [](GLFWwindow* window, uint32_t keycode)
//        {
//            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
//
//            KeyTypedEvent event(keycode);
//            data.EventCallback(event);
//        });
//
//        glfwSetMouseButtonCallback(m_window, [](GLFWwindow* window, int button, int action, int mods)
//        {
//            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
//
//            switch (action)
//            {
//                case GLFW_PRESS:
//                {
//                    MouseButtonPressedEvent event(button);
//                    data.EventCallback(event);
//                    break;
//                }
//                case GLFW_RELEASE:
//                {
//                    MouseButtonReleasedEvent event(button);
//                    data.EventCallback(event);
//                    break;
//                }
//            }
//        });
//
//        glfwSetScrollCallback(m_window, [](GLFWwindow* window, double xOffset, double yOffset)
//        {
//            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
//
//            MouseScrolledEvent event((float)xOffset, (float)yOffset);
//            data.EventCallback(event);
//        });
//
//        glfwSetCursorPosCallback(m_window, [](GLFWwindow* window, double xPos, double yPos)
//        {
//            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
//
//            MouseMovedEvent event((float)xPos, (float)yPos);
//            data.EventCallback(event);
//        });


    }

    void Window::OnUpdate()
    {
        glfwPollEvents();
        glfwSwapBuffers(m_window);
    }

    void Window::SetEventCallback(const Window::EventCallback& callback)
    {
        this->m_data.callback = callback;
    }


}
