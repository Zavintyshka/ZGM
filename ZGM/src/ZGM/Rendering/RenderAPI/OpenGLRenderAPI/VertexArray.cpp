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

    void VertexArray::AddBuffer(const VertexBuffer& vertexBuffer, const BufferLayout& bufferLayout) const {
        BindVertexArray();
        // Vertex Buffer
        vertexBuffer.Bind();
        vertexBuffer.Init();
        // Buffer Layout
        auto elements = *bufferLayout.GetElements();
        unsigned int offset = 0;

        for (int i = 0; i < elements.size(); i++) {
            auto element = elements[i];
            unsigned int stride = element.strideCount * sizeof(element.type);

            GLCall(glEnableVertexAttribArray(i));
            GLCall(glVertexAttribPointer(i, element.count, element.type, element.normalized, stride, (void*)offset));
            offset += element.count * sizeof(element.type);
        }
    }
}


