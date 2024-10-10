#include "zgmpch.h"
#include "WindowAPI.h"

void ZGM::Window::OnUpdate()
{
    glfwSwapBuffers(m_window);
    glfwPollEvents();
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
    
    std::string OGL_VERSION = reinterpret_cast<const char*>(glGetString(GL_VERSION));
    ZGM_ASSERT(glewInit() == 0, std::string("Driver: ") + OGL_VERSION, "GLEW initialization failed");
    ZGM_DEBUG_PRINT("--------------------------------------------------------------------------------------------");
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
