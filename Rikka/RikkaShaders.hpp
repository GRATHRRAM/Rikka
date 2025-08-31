#pragma once
#include "RikkaShader.hpp"

class RikkaShaders {
    private:
    bool Compiled;
    public:
    bool CompileShaders();
    bool DidShadersCompiled();//RKK Success == ok

    RikkaShader RectShader;
    RikkaShader TriangleShader;
    RikkaShader BlendTriangleShader;
    RikkaShader TextureShader;
};
