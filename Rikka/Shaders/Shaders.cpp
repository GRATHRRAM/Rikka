#include "../RikkaShaders.hpp"
#include "ShaderCode.h"
#include "../RikkaMacros.hpp"
#include <iostream>

bool RikkaShaders::CompileShaders() {
    if(!RectShader.Compile(RKK_RectVertexGLSL, RKK_RectFragmentGLSL)) {Compiled = false; return RKK_FALIURE;}
    if(!TriangleShader.Compile(RKK_TriangleVertexGLSL, RKK_TriangleFragmentGLSL)) {Compiled = false; return RKK_FALIURE;}
    Compiled = true; return RKK_SUCCESS;
}

bool RikkaShaders::DidShadersCompiled() {
    return Compiled;
}
