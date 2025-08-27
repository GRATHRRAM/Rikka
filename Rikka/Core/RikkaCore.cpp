#include "../RikkaCore.hpp"
#include <GLFW/glfw3.h>
#include <iostream>
#include <memory>

#include "../RikkaMacros.hpp"

Rikka::Rikka(const char* Title, uint16_t ResX, uint16_t ResY) { 
    if (!glfwInit()) {
        std::cerr << "GLFW Init Failed!\n";
        return;
    }

    Window = glfwCreateWindow(ResX, ResY, Title, nullptr, nullptr);
    if (!Window) {
        std::cerr << "GLFW CreateWindow Failed!\n";
        glfwTerminate();
        return;
    }

    glfwMakeContextCurrent(Window);

    GLenum err = glewInit();
    if (err != GLEW_OK) {
        std::cerr << "GLEW Init Failed! " << glewGetErrorString(err) << "\n";
        return;
    }

    glViewport(0, 0, ResX, ResY);

    std::cout << "GLEW Version: " << glewGetString(GLEW_VERSION) << "\n";
    std::cout << "OpenGL Version -> " << glGetString(GL_VERSION) << "\n";

    if(Shaders.CompileShaders() == RKK_FALIURE) {
        std::cout << "RikkaCore -> Shaders Failded To Compile!!!" << "\n";
        return;
    }
    
    Draw = std::make_unique<RikkaDraw>(Shaders, Vector2i{static_cast<int>(ResX),static_cast<int>(ResY)});
    
    glfwSetWindowUserPointer(Window, this);
    glfwSetFramebufferSizeCallback(Window, framebuffer_size_callback);

    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);
}

Rikka::~Rikka() {
    glfwDestroyWindow(Window);
    glfwTerminate();
}
