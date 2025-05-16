#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "Rikka/Rikka.hpp"

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

int main() {
    rkk::Engine Engine("Rikka Engine Demo1", 800 , 600);

    glfwSetFramebufferSizeCallback(Engine.GetWindow(), framebuffer_size_callback);

    // Main loop
    while (!glfwWindowShouldClose(Engine.GetWindow())) {
        glClearColor(0.1f, 0.2f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(Engine.GetWindow());
        glfwPollEvents();
    }

    return 0;
}