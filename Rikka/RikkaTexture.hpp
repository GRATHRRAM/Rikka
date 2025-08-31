#pragma once
#include "RikkaShader.hpp"
#include "RikkaTypes.hpp"

class RikkaTexture {
    private:
    bool Loaded = false;
    unsigned int Texture;
 
    public:
    ~RikkaTexture();
    
    Vector2 Position;
    Vector2 Size;

    bool LoadTexture(const char* Path, unsigned int WrapMode, unsigned int FilteringMode);
    unsigned int GetTexture() const;
};
