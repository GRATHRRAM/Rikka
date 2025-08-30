#include "Rikka.hpp"
#include "RikkaTypes.hpp"

int main() {
    Rikka Engine("Rikka Engine", 800, 600);

    Shapes::Triangle Triangle = {
        .Position = Vector2{0,0},
        .Point1 = Vector2{500,500},
        .Point2 = Vector2{300,200},
        .Point3 = Vector2{300,600}
    };

    while(!glfwWindowShouldClose(Engine.GetWindow())) {
        glfwPollEvents();
        Engine.Draw->Clear(RikkaColor());    
        Engine.Draw->Triangle(Triangle, RikkaColor(255,0,0,255));
        glfwSwapBuffers(Engine.GetWindow());
    }
}
