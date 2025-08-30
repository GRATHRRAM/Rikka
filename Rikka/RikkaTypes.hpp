#pragma once
#include "RikkaColor.hpp"

struct Vector2 {
    float x;
    float y;
};

struct Vector2i {
    int x;
    int y;
};

namespace Shapes {
    struct Rect {
        Vector2 Position;
        Vector2 Size;
    };

    struct CRect {
        Vector2 Position;
        Vector2 Size;
        RikkaColor Color;
    };

    struct Triangle {
        Vector2 Position;
        Vector2 Point1;
        Vector2 Point2;
        Vector2 Point3;
    };
    
    struct CTriangle {
        Vector2 Position;
        Vector2 Point1;
        Vector2 Point2;
        Vector2 Point3;
        RikkaColor Color;
    };

    struct BlendTriangle {
        Vector2 Position;
        Vector2 Point1;
        Vector2 Point2;
        Vector2 Point3;
        RikkaColor Point1Color;
        RikkaColor Point2Color;
        RikkaColor Point3Color;
    };
}

typedef void (*RikkaUniformSetter)(unsigned int shaderProgram);
