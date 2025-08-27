#pragma once
#include "RikkaDraw.hpp"
#include "RikkaTypes.hpp"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <cstdint>
#include <memory>

class Rikka {
    public:
        GLFWwindow *Window;
        RikkaShaders Shaders;
        std::unique_ptr<RikkaDraw> Draw; 

        Rikka(const char* Title, uint16_t ResX, uint16_t ResY);
        ~Rikka();

        void ResizeWindow(int width, int height) {glViewport(0, 0, width, height); Draw->Resize(width, height);}
    private:
        static void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
            Rikka* rikka = static_cast<Rikka*>(glfwGetWindowUserPointer(window));
            if (rikka) {
                rikka->ResizeWindow(width, height);
            }
        }
};

