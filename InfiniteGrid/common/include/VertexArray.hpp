#pragma once

#include <glad/gl.h>
#include <utils/glutils.h>

#include <VertexBuffer.hpp>
#include <VertexBufferLayout.hpp>

class VertexArray
{                                
private:
    unsigned int m_ID;
public:
    VertexArray()
    {
        CHECK_GL(glGenVertexArrays(1,&m_ID));
    }

    ~VertexArray()
    {
        CHECK_GL(glDeleteVertexArrays(1,&m_ID));
    }

    void bind() const
    {
        CHECK_GL(glBindVertexArray(m_ID));
    }
    
    void unbind() const
    {
        CHECK_GL(glBindVertexArray(0));
    }

    void addBuffer(const VertexBuffer& vb, const VertextBufferLayout& vbe);
};
