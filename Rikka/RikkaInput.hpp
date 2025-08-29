#pragma once

#include <GLFW/glfw3.h>
#include <unordered_map>
#include <vector>
#include <string>

enum class ActionState {
    Released,
    Pressed,
    JustPressed,
    JustReleased
};

class RikkaInput {
public:
    void BindKey(const std::string& actionName, int key);
    void Update(GLFWwindow* window);
    ActionState GetActionState(const std::string& actionName) const;

private:
    std::unordered_map<std::string, std::vector<int>> actionBindings; // action -> keys
    std::unordered_map<std::string, ActionState> actionStates;
    std::unordered_map<int, bool> previousKeyStates;

    bool isKeyDown(GLFWwindow* window, int key);
};

