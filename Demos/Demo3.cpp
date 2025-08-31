#include <Rikka.hpp>

int main() {
    Rikka Engine("Rikka Demo3", 800, 600);
    Engine.SetFrameLock();
    
    RikkaTexture Texture;
    Texture.Position = Vector2{0,0};
    Texture.Size = {618,1096};

    if(!Texture.LoadTexture("rikka.png", GL_CLAMP_TO_BORDER, GL_LINEAR)) return -1;

    while (!glfwWindowShouldClose(Engine.GetWindow())) {
        Engine.NewFrame();
        glfwPollEvents();

        Engine.Draw->Texture(Texture);

        glfwSwapBuffers(Engine.GetWindow());
        Engine.LockFrame();
    }
}
