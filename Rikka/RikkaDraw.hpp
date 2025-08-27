#pragma once
#include "RikkaColor.hpp"
#include "RikkaShaders.hpp"
#include "RikkaTypes.hpp"

class RikkaDraw {
    const RikkaShaders& Shaders;
    Vector2i ScreenSize;

    public:
    RikkaDraw(const RikkaShaders& Shaders, Vector2i ScreenSize) :
        Shaders(Shaders), ScreenSize(ScreenSize) {}

    void Resize(int Width, int Height) {ScreenSize.x = Width; ScreenSize.y = Height;}
    void Clear(Color ClearColor);
    void Rect(Vector2 Position, Vector2 Size, Color RectColor);
};
