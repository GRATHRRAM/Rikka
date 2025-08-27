#include <GL/glew.h>

class RikkaShaders {
    private:
    bool Compiled;

    void DeleteShaders();
    public:
    ~RikkaShaders();
  
    bool CompileShaders();
    bool DidShadersCompiled();//RKK Success == ok

    unsigned int RectShaderProgram;
};
