#include "zgmpch.h"
#include "DebugGUI.h"


DebugGUI::DebugGUI(GLFWwindow* window, const char* OpenGLVersion, float scale)
{
    ImGui::CreateContext();
    bool isGUI_GLFW_Init = ImGui_ImplGlfw_InitForOpenGL(window, true);
    bool isGUI_OpenGL3_Init = ImGui_ImplOpenGL3_Init(OpenGLVersion);
    ImGui::StyleColorsDark();
    ImGui::GetIO().FontGlobalScale = scale;

    if (isGUI_GLFW_Init)
        print("ImGui GLFW successfully loaded");
    else {
        print("ImGui GLFW not loaded");
        exit(1);
    }
        

    if (isGUI_GLFW_Init)
        print("ImGui OpenGL3 successfully loaded");
    else {
        print("ImGui OpenGL3 not loaded");
        exit(1);
    }   
}

DebugGUI::~DebugGUI()
{
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
    print("GUI Destructed");
}

void DebugGUI::NewFrame() const
{
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();
}

void DebugGUI::Render() const
{
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

const ImGuiIO& DebugGUI::GetIO() const
{
    return ImGui::GetIO();
}
