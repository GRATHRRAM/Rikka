#pragma once
#include "RikkaDraw.hpp"
#include "RikkaTypes.hpp"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <cstdint>
#include <memory>
#include <chrono>

class Rikka {
    public:
        RikkaShaders Shaders;
        std::unique_ptr<RikkaDraw> Draw; 

        Rikka(const char* Title, uint16_t ResX, uint16_t ResY, bool CanResize = true);
        ~Rikka();

        GLFWwindow* GetWindow() const {return Window;}

        void ResizeWindow(int width, int height) {glViewport(0, 0, width, height); ScreenSize = {width, height};}
 
        void NewFrame();
        float GetDelta() const;

        void SetFrameLock(int FPS = 60);
        void LockFrame();

    private:
        Vector2i ScreenSize;
        GLFWwindow* Window;

        std::chrono::time_point<std::chrono::high_resolution_clock> lastTime;
        float DeltaTime;
        float CalcFrameTime;

        static void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
            Rikka* rikka = static_cast<Rikka*>(glfwGetWindowUserPointer(window));
            if (rikka) {
                rikka->ResizeWindow(width, height);
            }
        }
};

