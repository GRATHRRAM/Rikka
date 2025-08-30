#pragma once
#include <GL/glew.h>
#include "RikkaTypes.hpp"

class RikkaShader {
    private:
       unsigned int ShaderProgram;
       bool Inited = false;
    public:
        RikkaUniformSetter UniformSetter = nullptr;

        ~RikkaShader();

        bool Compile(const char* VertexSrc, const char* FragmentSrc);
        unsigned int GetShader() const;
};
