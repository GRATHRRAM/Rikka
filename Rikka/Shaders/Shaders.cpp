#include "../RikkaShaders.hpp"
#include "ShaderCode.h"
#include "../RikkaMacros.hpp"
#include <iostream>

bool CompileShader(unsigned int& Shader, GLenum ShaderType, const char* Src) {
    Shader = glCreateShader(ShaderType);
    glShaderSource(Shader, 1, &Src, nullptr);
    glCompileShader(Shader);

    int  success;
    char infoLog[512];
    glGetShaderiv(Shader, GL_COMPILE_STATUS, &success);

    if(!success) {
        glGetShaderInfoLog(Shader, 512, NULL, infoLog);
        std::cout << "RikkaShader -> Shader Compilation Failed!!!\n" << infoLog << "\n";
        return RKK_FALIURE;
    }
    return RKK_SUCCESS;
}

bool CompileShaderProgram(unsigned int& Program, const char* VertexSrc, const char* FragmentSrc) {
    unsigned int VertexShader;
    CompileShader(VertexShader, GL_VERTEX_SHADER, VertexSrc);

    unsigned int FragmentShader;
    CompileShader(FragmentShader, GL_FRAGMENT_SHADER, FragmentSrc);

    Program = glCreateProgram();
    glAttachShader(Program, VertexShader);
    glAttachShader(Program, FragmentShader);
    glLinkProgram(Program);

    glDeleteShader(VertexShader);
    glDeleteShader(FragmentShader);

    int  success;
    char infoLog[512];
    glGetProgramiv(Program, GL_LINK_STATUS, &success);
    if(!success) {
        glGetProgramInfoLog(Program, 512, NULL, infoLog);
        std::cout << "RikkaShader -> Program Linking Failed!!!\n" << infoLog << "\n";
        return RKK_FALIURE;
    }
    return RKK_SUCCESS;
}

bool RikkaShaders::CompileShaders() {
    if(!CompileShaderProgram(RectShaderProgram, RKK_RectVertexGLSL, RKK_RectFragmentGLSL)) {Compiled = true; return RKK_FALIURE;}
    Compiled = true; return RKK_SUCCESS;
}

void RikkaShaders::DeleteShaders() {
    glDeleteProgram(RectShaderProgram);
}

RikkaShaders::~RikkaShaders() {
    if(!Compiled) return;
    DeleteShaders();
}

bool RikkaShaders::DidShadersCompiled() {
    return Compiled;
}
