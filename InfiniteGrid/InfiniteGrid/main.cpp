#include <glad/gl.h>
#include <glm/glm.hpp>
#include <GLFW/glfw3.h>

#include <iostream>


void processInput(GLFWwindow* window);
void framebuffer_size_call_back(GLFWwindow* window,int width,int height);


int main(){
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,3);
    glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(800,600,"InfiniteGrid",NULL,NULL);
    if(window == nullptr){
        std::cout << "Fail to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_call_back);
    if(!gladLoadGL(glfwGetProcAddress)){
        std::cout << "Failed to initalize GLAD" << std::endl;
    }     

    while(!glfwWindowShouldClose(window)){      
        processInput(window);

        glClearColor(1,1,1,1);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    
    return 0;
}
void processInput(GLFWwindow* window){
    if(glfwGetKey(window,GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

void framebuffer_size_call_back(GLFWwindow* window,int width,int height){
    glViewport(0,0,width,height);
}
