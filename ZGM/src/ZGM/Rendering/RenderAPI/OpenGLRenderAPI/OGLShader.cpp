#include "zgmpch.h"
#include "OGLShader.h"
 
namespace Render {
    std::string OGLShader::GetShaderSourceCode(const std::string& filepath)
    {
#ifdef _DEBUG
        IsFileExists(filepath.c_str());
#endif

        std::ifstream stream(filepath);
        std::string shaderType;
        std::string line;
        std::string shaderSource = "";

        while (std::getline(stream, line)) {
            if (line.find("#shader") != std::string::npos) {
                shaderType = line.find("vertex") != std::string::npos ? "Vertex" : "Fragment";
                ZGM_CORE_INFO("Load {0} Shader", shaderType);
            }
            else {
                shaderSource += line + "\n";
            }
        }
        return shaderSource;
    }

    unsigned int OGLShader::CompileShader(unsigned int type, const char* source)
    {
        unsigned int shaderID = glCreateShader(type);
        glShaderSource(shaderID, 1, &source, nullptr);
        glCompileShader(shaderID);

        // Erorr Handling
        int compilationStatus;
        glGetShaderiv(shaderID, GL_COMPILE_STATUS, &compilationStatus);

        int shaderType;
        glGetShaderiv(shaderID, GL_SHADER_TYPE, &shaderType);
        const char* shaderTypeStr = shaderType == GL_VERTEX_SHADER ? "Vertex" : "Fragment";

        if (compilationStatus != GL_TRUE) {
            // Log Message
            int logLength;
            glGetShaderiv(shaderID, GL_INFO_LOG_LENGTH, &logLength);
            char* logMessage = (char*)alloca(logLength * sizeof(char));
            glGetShaderInfoLog(shaderID, logLength, &logLength, logMessage);

            // Print
            std::cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Shader Compile Error ~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
            ZGM_CORE_ERROR("Failed to compile {0} Shader", shaderTypeStr);
            ZGM_CORE_ERROR(logMessage);
            std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";

            // Delete failed shader
            glDeleteShader(shaderID);
            exit(EXIT_FAILURE);
            return 0;
        }
        else {
            ZGM_CORE_INFO("{0} Shader successfully compiled", shaderTypeStr);
        }
        return shaderID;
    }

    OGLShader::OGLShader(std::string vertexShaderFilepath, std::string fragmentShaderFilepath)
    {
        ZGM_DEBUG_PRINT("------------------------------------------ Shader Compilation ------------------------------------------");
        m_objectID = glCreateProgram();
        AddVertexShader(vertexShaderFilepath);
        AddFragmentShader(fragmentShaderFilepath);
        ZGM_DEBUG_PRINT("--------------------------------------------------------------------------------------------------------");
    }

    OGLShader::~OGLShader()
    {
        glDeleteProgram(m_objectID);
    }

    void OGLShader::AddVertexShader(const std::string& filepath)
    {
        std::string vertexShaderSourceCode = GetShaderSourceCode(filepath);
        m_vertexShaderID = CompileShader(GL_VERTEX_SHADER, vertexShaderSourceCode.c_str());
        glAttachShader(m_objectID, m_vertexShaderID);
    }

    void OGLShader::AddFragmentShader(const std::string& filepath)
    {
        std::string fragmentShaderSourceCode = GetShaderSourceCode(filepath);
        m_fragmentShaderID = CompileShader(GL_FRAGMENT_SHADER, fragmentShaderSourceCode.c_str());
        glAttachShader(m_objectID, m_fragmentShaderID);
    }

    void OGLShader::Link() const
    {
        glLinkProgram(m_objectID);
        glValidateProgram(m_objectID);

        glDeleteShader(m_vertexShaderID);
        glDeleteShader(m_fragmentShaderID);
    }



    void OGLShader::Bind() const
    {
        glUseProgram(m_objectID);
    }

    void OGLShader::Unbind() const
    {
        glUseProgram(0);
    }

    unsigned int  OGLShader::GetUniformLocation(const std::string& varName)
    {
        if (m_locationCache.find(varName) == m_locationCache.end()) {
            m_locationCache[varName] = glGetUniformLocation(m_objectID, varName.c_str());
        }
        return  m_locationCache[varName];
    }

    void OGLShader::SetUniform(const std::string& varName, Vector4& vec4)
    {

        glUniform4f(GetUniformLocation(varName), vec4.x, vec4.y, vec4.z, vec4.w);

    }

    void OGLShader::SetUniform1i(const std::string& varName, int value)
    {
        glUniform1f(GetUniformLocation(varName), value);
    }

    void OGLShader::SetUniformMat4f(const std::string& varName, glm::mat4& projMatrix)
    {
        glUniformMatrix4fv(GetUniformLocation(varName), 1, GL_FALSE, &projMatrix[0][0]);
    }
}

