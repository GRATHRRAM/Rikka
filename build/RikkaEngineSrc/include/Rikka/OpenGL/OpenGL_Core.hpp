#pragma once
#include <string>
#include "../Types.hpp"
#include "../Macros.hpp"

namespace rkk { 
    class Engine {
        private:
        GLFWwindow* Window = nullptr;
        
        TaskDone Init = rkk_Failure;

        void LogBuildTime();
        void LogBuildVersion();
        TaskDone InitGLFW();
        TaskDone InitGLAD();

        public:
        Engine(const std::string& Title, ruint Width, ruint Height);
        ~Engine();

        GLFWwindow* GetWindow();
        TaskDone GetInitStatus();
    };
}