#include "zgmpch.h"
#include "OGLVertexArray.h"

namespace Render {
    OGLVertexArray::OGLVertexArray()
    {
        GLCall(glGenVertexArrays(1, &m_vertexArrayID));
    }

    OGLVertexArray::~OGLVertexArray()
    {
        GLCall(glDeleteVertexArrays(1, &m_vertexArrayID));
    }

    void OGLVertexArray::Bind() const
    {
        GLCall(glBindVertexArray(m_vertexArrayID));
    }

    void OGLVertexArray::Unbind() const
    {
        GLCall(glBindVertexArray(0));
    }

    void OGLVertexArray::AddBuffer(const VertexBuffer& vertexBuffer, const VertexBufferLayout& vertexBufferLayout) const {
        Bind();
        // Vertex Buffer
        vertexBuffer.Bind();
        vertexBuffer.Init();
        // Buffer Layout
        auto elements = *vertexBufferLayout.GetLayout();
        unsigned int offset = 0;

        for (int i = 0; i < elements.size(); i++) {
            auto element = elements[i];
            unsigned int stride = element.strideComponentCount * sizeof(element.componentType);

            GLCall(glEnableVertexAttribArray(i));
            GLCall(glVertexAttribPointer(i, element.componentCount, element.componentType, element.normalized, stride, (void*)offset));
            offset += element.componentCount * sizeof(element.componentType);
        }
    }
}


