#include "../RikkaMath.hpp"
#include <math.h>

Shapes::Triangle RikkaMath::RotateTriangle(Shapes::Triangle Triangle, float Angle, Vector2 Origin) {
    float radians = Angle * 3.14159265f / 180.0f;

    float cosAngle = cos(radians);
    float sinAngle = sin(radians);

    auto rotatePoint = [cosAngle, sinAngle, Origin](Vector2 point) -> Vector2 {
        float x = point.x - Origin.x;
        float y = point.y - Origin.y;
        float x_rot = x * cosAngle - y * sinAngle;
        float y_rot = x * sinAngle + y * cosAngle;
        return Vector2{x_rot + Origin.x, y_rot + Origin.y};
    };

    Shapes::Triangle rotatedTriangle;
    rotatedTriangle.Position = Triangle.Position;
    rotatedTriangle.Point1 = rotatePoint(Triangle.Point1);
    rotatedTriangle.Point2 = rotatePoint(Triangle.Point2);
    rotatedTriangle.Point3 = rotatePoint(Triangle.Point3);

    return rotatedTriangle;
}
