#include "Rikka.hpp"

int main() {
    Rikka Engine("Rikka Engine", 800, 600, false);

    RikkaInput Input;
    Input.BindKey("Up",    GLFW_KEY_UP);
    Input.BindKey("Down",  GLFW_KEY_DOWN);
    Input.BindKey("Left",  GLFW_KEY_LEFT);
    Input.BindKey("Right", GLFW_KEY_RIGHT);

    Input.BindKey("Up",    GLFW_KEY_W);
    Input.BindKey("Down",  GLFW_KEY_S);
    Input.BindKey("Left",  GLFW_KEY_A);
    Input.BindKey("Right", GLFW_KEY_D);
    
    Shapes::CRect Player = {};
    Player.Position = Vector2{500,100};
    Player.Size = Vector2{100,100};
    Player.Color = RikkaColor(255,0,255,200);

    while(!glfwWindowShouldClose(Engine.GetWindow())) {
        glfwPollEvents();
        Input.Update(Engine.GetWindow());

        if(Input.GetActionState("Up")    == ActionState::Pressed) Player.Position.y -= 1;
        if(Input.GetActionState("Down")  == ActionState::Pressed) Player.Position.y += 1;
        if(Input.GetActionState("Left")  == ActionState::Pressed) Player.Position.x -= 1;
        if(Input.GetActionState("Right") == ActionState::Pressed) Player.Position.x += 1;
        
        Engine.Draw->Clear(RikkaColor());    
        Engine.Draw->Rect(Vector2{100,100}, Vector2{100,100}, RikkaColor(255,0,0,128));
        Engine.Draw->Rect(Vector2{150,150}, Vector2{100,100}, RikkaColor(0,255,0,128));
        Engine.Draw->Rect(Vector2{200,200}, Vector2{100,100}, RikkaColor(0,0,255,128));
        Engine.Draw->Rect(Player);
        glfwSwapBuffers(Engine.GetWindow());
    }
}
