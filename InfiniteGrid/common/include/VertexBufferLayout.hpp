#pragma once

#include <vector> 
#include <type_traits>

#include <glad/gl.h>
#include <utils/glutils.h>
 namespace my
{
struct VertextBufferElement
{
    unsigned int type;
    unsigned int count;
    unsigned int normalized;

    static unsigned int getTypeSize(unsigned int gltype)
    {
        switch (gltype)
        {
        case GL_FLOAT: return 4;
        case GL_DOUBLE: return 8;
        case GL_INT: return 4;
        case GL_UNSIGNED_INT: return 4;
        case GL_UNSIGNED_BYTE: return 1;  
        }
        std::cout << "[OpenGL]: type " << gltype << " is unidentification" << std::endl;

        return 0;
    }
};

class VertextBufferLayout
{
private:
    std::vector<VertextBufferElement> m_elements;
    unsigned int m_stride;
public:
    VertextBufferLayout(): m_stride(0) {}
    
    template<typename T>
    void push(unsigned int count)
    {
        static_assert(!std::is_void_v<std::void_t<T>>);
    }

    template<>
    void push<float>(unsigned int count)
    {
        using vbe = VertextBufferElement;
        m_elements.push_back({GL_FLOAT, count, GLFALSE});
        m_stride += vbe::getTypeSize(GL_FLOAT);
    } 

    template<>
    void push<double>(unsigned int count)
    {
        using vbe = VertextBufferElement;
        m_elements.push_back({GL_DOUBLE, count, GLFALSE});
        m_stride += vbe::getTypeSize(GL_DOUBLE);
    }      

    template<>
    void push<unsigned int>(unsigned int count)
    {                                          
        using vbe = VertextBufferElement;
        m_elements.push_back({GL_UNSIGNED_INT, count, GLFALSE});
        m_stride += vbe::getTypeSize(GL_UNSIGNED_INT);
    } 

    template<>
    void push<unsigned char>(unsigned int count)
    {
        using vbe = VertextBufferElement;
        m_elements.push_back({GL_UNSIGNED_BYTE, count, GLFALSE});
        m_stride += vbe::getTypeSize(GL_UNSIGNED_BYTE);
    } 

};
}
