#include "../RikkaTexture.hpp"
#include "../RikkaMacros.hpp"
#include <iostream>

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

bool RikkaTexture::LoadTexture(const char* Path, unsigned int WrapMode, unsigned int FilteringMode) {
    int width, height, nrChannels;
    unsigned char *data = stbi_load(Path, &width, &height, &nrChannels, 0);
    if(!data) {
        std::cout << "RikkaTexture -> Failed To Load Image -> " << Path << "\n";
        return RKK_FALIURE;
    }

    glGenTextures(1, &Texture);  
    glBindTexture(GL_TEXTURE_2D, Texture);  

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);
    
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, WrapMode);	
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, WrapMode);
    
    if(FilteringMode == GL_LINEAR)
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    else
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);
    
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, FilteringMode);

    stbi_image_free(data);

    Loaded = true;
    return RKK_SUCCESS;
}

unsigned int RikkaTexture::GetTexture() const {
    return Texture;
}

RikkaTexture::~RikkaTexture() {
    if(Loaded) glDeleteTextures(0, &Texture);
}
