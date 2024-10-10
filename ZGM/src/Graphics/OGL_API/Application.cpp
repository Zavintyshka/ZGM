// C++
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

// GLM
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

// IMGUI
#include "DebugGUI.h"

// Project
#include "General.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "BufferLayout.h"
#include "VertexArray.h"
#include "Shader.h"
#include "Renderer.h"
#include "Texture.h"


int main(void)
{
    GLFWwindow* window;

    if (!glfwInit())
        return -1;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


    window = glfwCreateWindow(800, 800, "Cyberpunk 2077", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

    if (glewInit() == GLEW_OK) {
        print(glGetString(GL_VERSION));
    }



    // Renderer
    Renderer renderer;

    // ImGui
    DebugGUI gui(window, "#version 330", 1.5f);
    const ImGuiIO& io = gui.GetIO();


    float squareWidth =0.50f;
    float squareHeight = 0.50f;
    float offsetX = 0.00f;

    struct Vertex {
        float position[2];
        float color[4];
        float texCoords[2];
        float texIndex;
   };




    

    unsigned int squaresIndecis[12] = {
        3,0,1,3,2,1,
        7,4,5,7,6,5
    };


    VertexArray va;
    VertexBuffer vb(nullptr, sizeof(Vertex) * 1000);
    BufferLayout bl;
    bl.Push(GL_FLOAT, 2, 9); // TODO rewrite from FLOAT to VERTEX
    bl.Push(GL_FLOAT, 4, 9);
    bl.Push(GL_FLOAT, 2, 9);
    bl.Push(GL_FLOAT, 1, 9);
    va.AddBuffer(vb, bl);
    IndexBuffer ib(squaresIndecis, 12);
    Shader shader;
    shader.AddVertexShader("res/shader/VertexShader.shader");
    shader.AddFragmentShader("res/shader/FragmentShader.shader");
    shader.LinkAndValidate();
    shader.BindShader();
    Vector4 color = { 1.0f,0.0f ,1.0f ,1.0f};
    shader.SetUniform("u_color", color);
    Texture textureEnder("res/textures/ender.png");
    Texture textureBrick("res/textures/brick.png");

    textureEnder.Bind(0);
    textureBrick.Bind(1);

    int samplers[2] = { 0, 1 };
    auto loc = glGetUniformLocation(shader.GetShaderID(), "u_texture");
    glUniform1iv(loc, 2, samplers);

 
     


    while (!glfwWindowShouldClose(window))
    {
        renderer.Clear();
        
        // Dynamic Vertex
        float squaresVertecis[] = {
            -offsetX, -squareHeight / 2,                0.0f, 1.0f, 0.0f, 1.0f,         1.0f, 0.0f,     0.0f,// 0
            -offsetX, squareHeight / 2,                 0.0f, 1.0f, 0.0f, 1.0f,         1.0f, 1.0f,     0.0f,// 1
            -squareWidth - offsetX, squareHeight / 2,   0.0f, 1.0f, 0.0f, 1.0f,         0.0f, 1.0f,     0.0f,// 2
            -squareWidth - offsetX, -squareHeight / 2,  0.0f, 1.0f, 0.0f, 1.0f,         0.0f, 0.0f,     0.0f,// 3

            squareWidth + offsetX, -squareHeight / 2,   1.0f, 0.0f, 0.0f, 1.0f,         1.0f, 0.0f,     1.0f,// 4
            squareWidth + offsetX, squareHeight / 2,    1.0f, 0.0f, 0.0f, 1.0f,         1.0f, 1.0f,     1.0f,// 5
            offsetX, squareHeight / 2,                  1.0f, 0.0f, 0.0f, 1.0f,         0.0f, 1.0f,     1.0f,// 6
            offsetX, -squareHeight / 2,                 1.0f, 0.0f, 0.0f, 1.0f,         0.0f, 0.0f,     1.0f,// 7
        };

        glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(squaresVertecis), squaresVertecis);

        glDrawElements(GL_TRIANGLES, 12, GL_UNSIGNED_INT, nullptr);



        glfwSwapBuffers(window);
        glfwPollEvents();
    }


    glfwTerminate();
    return 0;
}