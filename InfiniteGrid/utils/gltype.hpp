#pragma once

#include <glad/gl.h>
#include <glm/glm.hpp>

using float3 = glm::vec3<float>;
using float4 = glm::vec4<float>;

template<class T>
struct gl_type{
};

template<>
struct gl_type<int>{
    static constexpr int type = GL_INT;
    static constexpr int dim = 1;
};
 
template<>
struct gl_type<float>{
    static constexpr int type = GL_FLOAT;
    static constexpr int dim = 1;
};                               

template<>
struct gl_type<unsigned int>
{
    static constexpr int type = GL_UNSIGNED_INT;
    static constexpr int dim = 1;
};

template<>
struct gl_type<unsigned char>
{
    static constexpr int type = GL_UNSIGNED_BYTE;
    static constexpr int dim = 1;
};

template<T>
struct gl_type<glm::vec3<T>>:gl_type<T>
{
    static constexpr int dim = 3;
};  

template<>
struct gl_type<glm::vec4<T>>:gl_type<T>
{
    static constexpr int dim = 4;
};
