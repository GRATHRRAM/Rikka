#include "../RikkaCore.hpp"
#include <GLFW/glfw3.h>
#include <iostream>
#include <memory>
#include <thread>

#include "../RikkaMacros.hpp"

Rikka::Rikka(const char* Title, uint16_t ResX, uint16_t ResY, bool CanResize) { 
    if (!glfwInit()) {
        std::cerr << "GLFW Init Failed!\n";
        return;
    }
    
    if(CanResize) glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);
    else glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

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
   
    ScreenSize = {ResX, ResY};
    Draw = std::make_unique<RikkaDraw>(Shaders, ScreenSize);
    
    glfwSetWindowUserPointer(Window, this);
    glfwSetFramebufferSizeCallback(Window, framebuffer_size_callback);

    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);
}

Rikka::~Rikka() {
    glfwDestroyWindow(Window);
    glfwTerminate();
}

void Rikka::NewFrame() {
    auto currentTime = std::chrono::high_resolution_clock::now();
        
    std::chrono::duration<float> delta = currentTime - lastTime;
    DeltaTime = delta.count();
        
    lastTime = currentTime;
}

float Rikka::GetDelta() const {
    return DeltaTime;
}

void Rikka::SetFrameLock(int FPS) {
    CalcFrameTime = 1000.0f / FPS;
}

void Rikka::LockFrame() {
    if (DeltaTime < CalcFrameTime / 1000.0f) {
        std::this_thread::sleep_for(std::chrono::milliseconds(int(CalcFrameTime - DeltaTime * 1000)));
    }
}
