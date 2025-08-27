#include "Rikka.hpp"
#include "RikkaTypes.hpp"
#include <cstdlib>
#include <stdlib.h>

int main() {
    Rikka Engine("Rikka Engine", 800, 600);

    while(!glfwWindowShouldClose(Engine.Window)) {
        glfwPollEvents();
        Engine.Draw->Clear(Color());    
        Engine.Draw->Rect(Vector2{100,100}, Vector2{100,100}, Color(255,0,0,128));
        Engine.Draw->Rect(Vector2{150,150}, Vector2{100,100}, Color(0,255,0,128));
        Engine.Draw->Rect(Vector2{200,200}, Vector2{100,100}, Color(0,0,255,128));
        glfwSwapBuffers(Engine.Window);
    }
}
