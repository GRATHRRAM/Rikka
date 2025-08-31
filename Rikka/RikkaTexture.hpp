#pragma once
#include "RikkaShader.hpp"

class RikkaTexture {
    private:
    bool Loaded = false;
    unsigned int Texture;
 
    public:
    ~RikkaTexture();

    bool LoadTexture(const char* Path, unsigned int WrapMode, unsigned int FilteringMode);
    unsigned int GetTexture() const;
};
