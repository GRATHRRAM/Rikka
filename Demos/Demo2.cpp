#include "Rikka.hpp"
#include "RikkaMath.hpp"
#include "RikkaTypes.hpp"

int main() {
    Rikka Engine("Rikka Engine", 800, 600);
    Engine.SetFrameLock();

    Shapes::BlendTriangle Triangle = {
        .Position = Vector2{300,300},
        .Point1 = Vector2{150,0},
        .Point2 = Vector2{0,300},
        .Point3 = Vector2{300,300},
        .Point1Color = RikkaColor(255,0,0,255),
        .Point2Color = RikkaColor(0,255,0,255),
        .Point3Color = RikkaColor(0,0,255,255)
    };

    while(!glfwWindowShouldClose(Engine.GetWindow())) {
        Engine.NewFrame();
        glfwPollEvents();

        Shapes::Triangle TriRot = RikkaMath::RotateTriangle(Shapes::Triangle{
            Vector2{0,0},
            Triangle.Point1,
            Triangle.Point2,
            Triangle.Point3
            },
            Engine.GetDelta() * 10,
            Vector2{150,150}
        );

        Triangle.Point1 = TriRot.Point1;
        Triangle.Point2 = TriRot.Point2;
        Triangle.Point3 = TriRot.Point3;

        Engine.Draw->Clear(RikkaColor());    
        Engine.Draw->Triangle(Triangle);
        glfwSwapBuffers(Engine.GetWindow());
        Engine.LockFrame();
    }
}
