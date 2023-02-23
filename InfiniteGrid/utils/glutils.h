#pragma once

#include <iostream>
#include <stdio.h>

#include <glad/gl.h>

static const char* get_opengl_error_string(GLenum err){
    switch (err){
    #define  PRE_GL_ERR(x) \
        case x: return #x;
        PRE_GL_ERR(GL_NO_ERROR)
        PRE_GL_ERR(GL_INVALID_ENUM)
        PRE_GL_ERR(GL_INVALID_VALUE)
        PRE_GL_ERR(GL_INVALID_OPERATION)
        PRE_GL_ERR(GL_INVALID_FRAMEBUFFER_OPERATION)
        PRE_GL_ERR(GL_OUT_OF_MEMORY)
        PRE_GL_ERR(GL_STACK_OVERFLOW)
        PRE_GL_ERR(GL_STACK_UNDERFLOW)
    #undef PRE_GL_ERR
    }                      
    static char tmp[233];
    sprintf(tmp,"%d\n",err);
    
    return tmp;
}

static void _check_opengl_error(const char* file,int line, const char *hint){
    auto err = glGetError();
    if(err !=  GL_NO_ERROR){
        auto msg = get_opengl_error_string(err);
        std::cout << "[OpenGL Error] (" << err << "): "
            << hint << " " << file << ":" << line << std::endl;
    }

}

#define CHECK_GL(x)                                \
    do {                                           \
        (x);                                       \
        _check_opengl_error(__FILE__,__LINE__,#x); \
    }while(0)                                     
