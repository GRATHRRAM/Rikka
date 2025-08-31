#include "../RikkaDraw.hpp"
#include <GL/gl.h>

void RikkaDraw::Clear(RikkaColor Color) {
    glClearColor(Color.fr(), Color.fg(), Color.fb(), Color.fa());
    glClear(GL_COLOR_BUFFER_BIT);
}

void RikkaDraw::Rect(Vector2 Position, Vector2 Size, RikkaColor Color) {
  GLfloat vertices[] = {
        Position.x,          Position.y,          0.0f,
        Position.x + Size.x, Position.y,          0.0f,
        Position.x + Size.x, Position.y + Size.y, 0.0f,
        Position.x,          Position.y + Size.y, 0.0f
    };

    GLuint indices[] = {
        0, 1, 2,
        0, 2, 3
    };

    GLuint VAO, VBO, EBO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    glUseProgram(Shaders.RectShader.GetShader());

    GLint colorLoc = glGetUniformLocation(Shaders.RectShader.GetShader(), "rectColor");
    glUniform4f(colorLoc, Color.fr(), Color.fg(), Color.fb(), Color.fa());

    GLuint ScreenSizeLoc = glGetUniformLocation(Shaders.RectShader.GetShader(), "ScreenSize");
    glUniform3f(ScreenSizeLoc, ScreenSize.x, ScreenSize.y, 0);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
}

void RikkaDraw::Rect(Shapes::Rect& Rect, RikkaColor Color) {
    RikkaDraw::Rect(Rect.Position, Rect.Size, Color);
}   

void RikkaDraw::Rect(Shapes::CRect& Rect) {
    RikkaDraw::Rect(Rect.Position, Rect.Size, Rect.Color);
}


void RikkaDraw::Triangle(Shapes::Triangle Triangle, RikkaColor Color) {
    GLfloat vertices[] = {
        Triangle.Position.x + Triangle.Point1.x, Triangle.Position.y + Triangle.Point1.y, 0.0f,
        Triangle.Position.x + Triangle.Point2.x, Triangle.Position.y + Triangle.Point2.y, 0.0f,
        Triangle.Position.x + Triangle.Point3.x, Triangle.Position.y + Triangle.Point3.y, 0.0f
    };

    GLuint VAO, VBO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glUseProgram(Shaders.TriangleShader.GetShader());

    GLint colorLoc = glGetUniformLocation(Shaders.TriangleShader.GetShader(), "TriangleColor");
    glUniform4f(colorLoc, Color.fr(), Color.fg(), Color.fb(), Color.fa());

    GLuint ScreenSizeLoc = glGetUniformLocation(Shaders.TriangleShader.GetShader(), "ScreenSize");
    glUniform2f(ScreenSizeLoc, ScreenSize.x, ScreenSize.y);

    glDrawArrays(GL_TRIANGLES, 0, 3);

    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
}

void RikkaDraw::Triangle(Shapes::CTriangle Triangle) {
    RikkaDraw::Triangle(Shapes::Triangle{
        .Position = Triangle.Position,
        .Point1 = Triangle.Point1,
        .Point2 = Triangle.Point2,
        .Point3 = Triangle.Point3
    }, Triangle.Color);
}

void RikkaDraw::Triangle(Shapes::BlendTriangle& Triangle, float Alpha) {
    GLfloat vertices[] = {
        Triangle.Position.x + Triangle.Point1.x, Triangle.Position.y + Triangle.Point1.y, 0.0f,
        Triangle.Point1Color.fr(), Triangle.Point1Color.fg(), Triangle.Point1Color.fb(),

        Triangle.Position.x + Triangle.Point2.x, Triangle.Position.y + Triangle.Point2.y, 0.0f,
        Triangle.Point2Color.fr(), Triangle.Point2Color.fg(), Triangle.Point2Color.fb(),
        
        Triangle.Position.x + Triangle.Point3.x, Triangle.Position.y + Triangle.Point3.y, 0.0f,
        Triangle.Point3Color.fr(), Triangle.Point3Color.fg(), Triangle.Point3Color.fb(),
    };

    GLuint VAO, VBO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    
    glUseProgram(Shaders.BlendTriangleShader.GetShader());

    GLuint ScreenSizeLoc = glGetUniformLocation(Shaders.BlendTriangleShader.GetShader(), "ScreenSize");
    glUniform2f(ScreenSizeLoc, ScreenSize.x, ScreenSize.y);

    GLuint AlphaLoc = glGetUniformLocation(Shaders.BlendTriangleShader.GetShader(), "Alpha");
    glUniform1f(AlphaLoc, Alpha);

    glDrawArrays(GL_TRIANGLES, 0, 3);
    
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
}

void RikkaDraw::Triangle(Shapes::BlendTriangle& Triangle) {
    RikkaDraw::Triangle(Triangle, 1.0f);
}


void RikkaDraw::Texture(RikkaTexture& texture) {
    float vertices[] = {
        // positions                                                                      // colors           // tex coords
        texture.Position.x + texture.Size.x, texture.Position.y + texture.Size.y, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f,   // top right
        texture.Position.x + texture.Size.x, texture.Position.y,                  0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f,   // bottom right
        texture.Position.x,                  texture.Position.y,                  0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f,   // bottom left
        texture.Position.x,                  texture.Position.y + texture.Size.y, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f    // top left 
    };

    GLuint indices[] = {
        0, 1, 2,
        2, 3, 0
    };

    GLuint VAO, VBO, EBO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
    glEnableVertexAttribArray(2);

    glUseProgram(Shaders.TextureShader.GetShader());

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, texture.GetTexture());

    GLint samplerLoc = glGetUniformLocation(Shaders.TextureShader.GetShader(), "uTexture");
    glUniform1i(samplerLoc, 0);

    unsigned int ScreenSizeLoc = glGetUniformLocation(Shaders.TextureShader.GetShader(), "ScreenSize");
    glUniform2f(ScreenSizeLoc, ScreenSize.x, ScreenSize.y);

    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

    glBindVertexArray(0);
    glUseProgram(0);
    
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
    glDeleteVertexArrays(1, &VAO);
}
