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
}

