#include "zgmpch.h"
#include "VertexArray.h"

namespace Render {
    VertexArray::VertexArray()
    {
        GLCall(glGenVertexArrays(1, &m_objectID));
    }

    VertexArray::~VertexArray()
    {
        GLCall(glDeleteVertexArrays(1, &m_objectID));
    }

    void VertexArray::BindVertexArray() const
    {
        GLCall(glBindVertexArray(m_objectID));
    }

    void VertexArray::UnbindVertexArray() const
    {
        GLCall(glBindVertexArray(0));
    }

    void VertexArray::AddBuffer(const OGLVertexBuffer& vertexBuffer, const OGLVertexBufferLayout& bufferLayout) const {
        BindVertexArray();
        // Vertex Buffer
        vertexBuffer.Bind();
        vertexBuffer.Init();
        // Buffer Layout
        auto elements = *bufferLayout.GetLayout();
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


