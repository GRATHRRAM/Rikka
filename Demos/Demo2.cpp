#include "Rikka.hpp"
#include "RikkaTypes.hpp"

int main() {
    Rikka Engine("Rikka Engine", 800, 600);

    Shapes::BlendTriangle Triangle = {
        .Position = Vector2{0,0},
        .Point1 = Vector2{500,500},
        .Point2 = Vector2{300,200},
        .Point3 = Vector2{300,600},
        .Point1Color = RikkaColor(255,0,0,255),
        .Point2Color = RikkaColor(0,255,0,255),
        .Point3Color = RikkaColor(0,0,255,255)
    };

    while(!glfwWindowShouldClose(Engine.GetWindow())) {
        glfwPollEvents();
        Engine.Draw->Clear(RikkaColor());    
        Engine.Draw->Triangle(Triangle);
        glfwSwapBuffers(Engine.GetWindow());
    }
}
