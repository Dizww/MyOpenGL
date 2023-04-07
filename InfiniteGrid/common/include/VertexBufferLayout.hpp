#pragma once

#include <vector> 
#include <type_traits>

#include <glad/gl.h>
#include <utils/glutils.h>
#include <utils/gltype.hpp>

struct VertextBufferElement
{
    unsigned int type;
    unsigned int count;
    unsigned int normalized;
};

class VertextBufferLayout
{
private:
    std::vector<VertextBufferElement> m_elements;
    unsigned int m_stride;
public:
    VertextBufferLayout(): m_stride(0) {}
    
    template<typename T,int normalized = GL_FALSE>
    void push()
    {
        m_elements.push_back({gl_type<T>::type, gl_type<T>::dim,normalized});
        m_stride += sizeof(T)*gl_type<T>::dim;
    }

};
