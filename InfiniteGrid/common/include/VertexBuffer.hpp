#pragma once

#include <glad/gl.h>                    
#include <utils/glutils.h>


class VertexBuffer
{
private:
    unsigned int m_ID;

public:
    VertexBuffer(const void* data,unsigned int size)
    {
        CHECK_GL(glGenBuffers(1, &m_ID));
        CHECK_GL(glBindBuffer(GL_ARRAY_BUFFER,m_ID));
        CHECK_GL(glBufferData(GL_ARRAY_BUFFER,size,data,GL_STATIC_DRAW));
    }

    ~VertexBuffer()
    {
        CHECK_GL(glDeleteBuffers(1,&m_ID));
    }

    void bind() const 
    {
        CHECK_GL(glBindBuffer(GL_ARRAY_BUFFER,m_ID));
    }

    void unbind() const
    {
        CHECK_GL(glBindBuffer(GL_ARRAY_BUFFER,0));
    }
};
