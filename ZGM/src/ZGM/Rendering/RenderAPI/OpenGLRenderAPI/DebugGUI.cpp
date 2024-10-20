#include "zgmpch.h"
#include "DebugGUI.h"


DebugGUI::DebugGUI(GLFWwindow* window, const char* OpenGLVersion, float scale)
{
    ImGui::CreateContext();
    bool isGUI_GLFW_Init = ImGui_ImplGlfw_InitForOpenGL(window, true);
    bool isGUI_OpenGL3_Init = ImGui_ImplOpenGL3_Init(OpenGLVersion);
    ImGui::StyleColorsDark();
    ImGui::GetIO().FontGlobalScale = scale;
    std::cout << "------------------------------------------ ImGui ------------------------------------------\n";
    if (isGUI_GLFW_Init)
        ZGM_CORE_INFO("ImGui GLFW successfully loaded");
    else {
        ZGM_CORE_INFO("ImGui GLFW not loaded");
        exit(1);
    }
        
    if (isGUI_GLFW_Init)
        ZGM_CORE_INFO("ImGui OpenGL3 successfully loaded");
    else {
        ZGM_CORE_INFO("ImGui OpenGL3 not loaded");
        exit(1);
    }
    std::cout << "-------------------------------------------------------------------------------------------\n";
}

DebugGUI::~DebugGUI()
{
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
    ZGM_CORE_INFO("GUI Destructed");
}

void DebugGUI::NewFrame()
{
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();
}

void DebugGUI::Render()
{
    ImGui::Render();
    if (ImGui::GetIO().ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
    {
        GLFWwindow* backup_current_context = glfwGetCurrentContext();
        ImGui::UpdatePlatformWindows();
        ImGui::RenderPlatformWindowsDefault();
        glfwMakeContextCurrent(backup_current_context);
    }
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

ImGuiIO& DebugGUI::GetIO()
{
    return ImGui::GetIO();
}

// ImGui Wrapper

void DebugGUI::MakeViewport()
{
    ImGui::DockSpaceOverViewport();
}

bool DebugGUI::Begin(const char* title) {
    return ImGui::Begin(title);
}

bool DebugGUI::Button(const char* title) {
    return ImGui::Button(title);
}

void DebugGUI::Text(const char* text) {
    ImGui::Text(text);
}

void DebugGUI::End() {
    ImGui::End();
}

bool DebugGUI::OnMouseMoved(ZGM::MouseMovedEvent& event)
{
    ZGM_CLIENT_INFO("OnMouseMoved ImGui");
    ImGuiIO& io = GetIO();
    ImVec2 eventPos(event.GetXPos(), event.GetYPos());
    io.MousePos = eventPos;
    return false;
}

bool DebugGUI::OnMousePressed(ZGM::MouseButtonPressedEvent& event)
{
    ImGuiIO& io = GetIO();
    const ImGuiMouseButton button = event.GetKeyCode();
    io.MouseDown[button] = true;
    io.MouseSource = ImGuiMouseSource::ImGuiMouseSource_Mouse;
    return false;
}

bool DebugGUI::OnMouseReleased(ZGM::MouseButtonReleasedEvent& event)
{
    ImGuiIO& io = GetIO();
    const ImGuiMouseButton button = event.GetKeyCode();
    io.MouseDown[button] = false;
    io.MouseSource = ImGuiMouseSource::ImGuiMouseSource_Mouse;

    return false;
}

bool DebugGUI::OnMouseScrolled(ZGM::MouseScrolledEvent& event)
{
    ImGuiIO& io = GetIO();
    io.MouseWheel += event.GetDirection() == "Up" ? 1.0f : -1.0f;
    io.MouseSource = ImGuiMouseSource::ImGuiMouseSource_Mouse;

    return false;
}
