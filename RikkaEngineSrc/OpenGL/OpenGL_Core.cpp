#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "OpenGL_Core.hpp"

#include <iostream>
#include <sstream>
#include <unordered_map>

namespace rkk {
    Engine::Engine(const std::string& Title, ruint Width, ruint Height) {
        LogBuildTime();
        LogBuildVersion();

        if (InitGLFW() == rkk_Failure) return;
        
        Window = glfwCreateWindow(Width, Height, Title.c_str(), nullptr, nullptr);
        if (!Window) {
            glfwTerminate();
            std::cerr << "Failed to create GLFW window\n";
            return;
        } std::cout << "Created GLFW Window Successfully!\n";

        glfwMakeContextCurrent(Window);

        if (InitGLAD() == rkk_Failure) return;

        std::cout << "OpenGL version: " << glGetString(GL_VERSION) << "\n";

        Init = rkk_Success;
    }

    Engine::~Engine() {
        glfwTerminate();
    }

    void Engine::LogBuildTime() {
        std::string monthStr, day, year;
        std::stringstream ss(__DATE__);
        ss >> monthStr >> day >> year;

        static const std::unordered_map<std::string, std::string> months = {
            {"Jan", "01"}, {"Feb", "02"}, {"Mar", "03"}, {"Apr", "04"},
            {"May", "05"}, {"Jun", "06"}, {"Jul", "07"}, {"Aug", "08"},
            {"Sep", "09"}, {"Oct", "10"}, {"Nov", "11"}, {"Dec", "12"}
        };

        std::string month = months.at(monthStr);
        if (day.size() == 1) day = "0" + day;

        std::string formattedDate = day + "." + month + "." + year;

        std::cout << "Rikka Build Date -> " << formattedDate << " (d.m.y)\n";
        std::cout << "Rikka Build Time -> " << __TIME__ << "\n";
    }

    void Engine::LogBuildVersion() {
        std::cout << "Rikka Version: " << rkk_Version << "\n";
        std::cout << "Rikka Version Info: " << rkk_VersionInfo << "\n";
    }

    TaskDone Engine::InitGLFW() {
        if (!glfwInit()) {
            std::cerr << "Failed to Initialize GLFW\n";
            return rkk_Failure;
        }

        std::cout << "Initialized GLFW Successfully!\n";

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        
        return rkk_Success;
    }

    TaskDone Engine::InitGLAD() {
        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
            std::cerr << "Failed to initialize GLAD\n";
            return rkk_Failure;
        }

        std::cout << "Initialized GLAD Successfully!\n";
        return rkk_Success;
    }

    GLFWwindow* Engine::GetWindow() {
        return Window;
    }
}