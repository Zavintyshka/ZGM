#include "zgmpch.h"
#include "WindowAPI.h"


void ZGM::Window::OnUpdate()
{
    glfwSwapBuffers(m_window);
    glfwPollEvents();
}

void ZGM::Window::SetEventCallbackFN(EventCallbackFN eventFN)
{
    m_winProps.eventCallbackFN = eventFN;
}

ZGM::Window::Window(WindowProperties winProps, OpenGLProperties oglProps)
    : m_winProps(winProps), m_oglProps(oglProps)
{
    ZGM_DEBUG_PRINT("------------------------------------------ WINDOW ------------------------------------------");

    ZGM_ASSERT(glfwInit(), "GLFW successfully initialized", "GLFW initialization failed");

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, m_oglProps.majorVersion);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, m_oglProps.minorVersion);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    ZGM_CORE_INFO("OpenGL version: {0}.{1}", m_oglProps.majorVersion, m_oglProps.minorVersion);

    m_window = glfwCreateWindow(m_winProps.width, m_winProps.height, m_winProps.title, NULL, NULL);
    ZGM_ASSERT(m_window, "Window successfully created", "Window created failed");
    ZGM_CORE_INFO("Title: \"{0}\"", m_winProps.title);
    ZGM_CORE_INFO("Resolution: ({0},{1})", m_winProps.width, m_winProps.height);

    glfwMakeContextCurrent(m_window);
    glfwSwapInterval(1);

    ZGM_ASSERT(gladLoadGLLoader((GLADloadproc)glfwGetProcAddress), "GLAD has successfully found pointers to OpenGL functions", "GLAD initialization failed");
    std::string OGL_VERSION = reinterpret_cast<const char*>(glGetString(GL_VERSION));
    ZGM_CORE_INFO("{0} {1}", "Driver:", OGL_VERSION);
    ZGM_DEBUG_PRINT("--------------------------------------------------------------------------------------------");

    // GLFW Callbacks
    glfwSetWindowUserPointer(m_window, &m_winProps);

    // I. App Callbacks
    glfwSetWindowSizeCallback(m_window, [](GLFWwindow* window, int width, int height) {
        WindowProperties& winData = *(WindowProperties*)glfwGetWindowUserPointer(window);
        winData.width = width;
        winData.height = height;

        WindowResizeEvent e(width, height);
        winData.eventCallbackFN(e);
        }
    );

    glfwSetWindowCloseCallback(m_window, [](GLFWwindow* window) {
        WindowProperties& winData = *(WindowProperties*)glfwGetWindowUserPointer(window);
        WindowCloseEvent e;
        winData.eventCallbackFN(e);
        }
    );

    // II. Keyboard Callbacks
    glfwSetKeyCallback(m_window, [](GLFWwindow* window, int key, int scancode, int action, int mods) {
        WindowProperties& winData = *(WindowProperties*)glfwGetWindowUserPointer(window);

        switch (action)
        {
        case GLFW_PRESS:
        {
            KeyPressedEvent e(key, false);
            winData.eventCallbackFN(e);
            break;
        }
        case GLFW_RELEASE:
        {
            KeyReleasedEvent e(key);
            winData.eventCallbackFN(e);
            break;
        }
        case GLFW_REPEAT:
        {
            KeyPressedEvent e(key, true);
            winData.eventCallbackFN(e);
            break;
        }
        }
        });

    // III. Mouse Callbacks
        // 1. Mouse Buttons
    glfwSetMouseButtonCallback(m_window, [](GLFWwindow* window, int button, int action, int mods) {
        WindowProperties& winData = *(WindowProperties*)glfwGetWindowUserPointer(window);

        switch (action) {
        case GLFW_PRESS:
        {
            MouseButtonPressedEvent e(button);
            winData.eventCallbackFN(e);
            break;
        }
        case GLFW_RELEASE:
        {
            MouseButtonReleasedEvent e(button);
            winData.eventCallbackFN(e);
            break;
        }
        }
        });

        // 2. Mouse Scroll
    glfwSetScrollCallback(m_window, [](GLFWwindow* window, double xoffset, double yoffset) {
        WindowProperties& winData = *(WindowProperties*)glfwGetWindowUserPointer(window);
        MouseScrolledEvent e(yoffset);
        winData.eventCallbackFN(e);
        });

        // 3. Mouse Position
    glfwSetCursorPosCallback(m_window, [](GLFWwindow* window, double xpos, double ypos) {
        WindowProperties& winData = *(WindowProperties*)glfwGetWindowUserPointer(window);
        MouseMovedEvent e(xpos, ypos);
        winData.eventCallbackFN(e);
        });

    // IV. Error Callback
    glfwSetErrorCallback(GLFWErrorCallback);
}

const char* ZGM::Window::GetTitle() const
{
	return m_winProps.title;
}

const unsigned int ZGM::Window::GetWidth() const
{
	return m_winProps.width;
}

const unsigned int ZGM::Window::GetHeight() const
{
	return m_winProps.height;
}

GLFWwindow* ZGM::Window::GetWindow()
{
    return m_window;
}

void ZGM::Window::GLFWErrorCallback(int errorCode, const char* description)
{
    ZGM_CORE_ERROR("GLFW Error ({0}): {1}", errorCode, description);
}
