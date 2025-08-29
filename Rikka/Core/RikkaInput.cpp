#include "../RikkaInput.hpp"

bool RikkaInput::isKeyDown(GLFWwindow* window, int key) {
    return glfwGetKey(window, key) == GLFW_PRESS;
}

void RikkaInput::BindKey(const std::string& actionName, int key) {
    actionBindings[actionName].push_back(key);
    previousKeyStates[key] = false;
}

void RikkaInput::Update(GLFWwindow* window) {
    for (auto& [key, wasDown] : previousKeyStates) {
        bool isDown = isKeyDown(window, key);
        previousKeyStates[key] = isDown;
    }

    for (auto& [action, keys] : actionBindings) {
        bool anyPressed = false;
        bool anyJustPressed = false;
        bool anyJustReleased = false;

        for (int key : keys) {
            bool isDown = isKeyDown(window, key);
            bool wasDown = previousKeyStates[key];

            if (isDown && !wasDown) anyJustPressed = true;
            if (!isDown && wasDown) anyJustReleased = true;
            if (isDown) anyPressed = true;

            previousKeyStates[key] = isDown;
        }

        if (anyJustPressed)
            actionStates[action] = ActionState::JustPressed;
        else if (anyJustReleased)
            actionStates[action] = ActionState::JustReleased;
        else if (anyPressed)
            actionStates[action] = ActionState::Pressed;
        else
            actionStates[action] = ActionState::Released;
    }
}

ActionState RikkaInput::GetActionState(const std::string& actionName) const {
    auto it = actionStates.find(actionName);
    if (it != actionStates.end()) {
        return it->second;
    }
    return ActionState::Released;
}

