#ifndef RIKKA_SHADER_CORE_H
#define RIKKA_SHADER_CORE_H

const char* RKK_RectVertexGLSL =
"#version 330 core\n"
"\n"
"layout(location = 0) in vec3 aPos;    // Vertex position\n"
"out vec4 fragColor;  // Output to fragment shader\n"
"\n"
"uniform vec4 rectColor; // Uniform color to apply to rectangle\n"
"uniform vec3 ScreenSize;\n"
"\n"
"void main() {\n"
"   float sx = aPos.x / ScreenSize.x * 2 - 1;\n"
"   float sy = aPos.y / ScreenSize.y * 2 - 1;\n"
"   gl_Position = vec4(sx, -sy, aPos.z, 1.0);  // Directly use the position in screen coordinates\n"
"   fragColor = rectColor;  // Pass the color to the fragment shader\n"
"}";

const char* RKK_RectFragmentGLSL =
"#version 330 core\n"
"\n"
"in vec4 fragColor;  // Input from the vertex shader\n"
"out vec4 FragColor; // Final color to output\n"
"\n"
"void main() {\n"
"// Output the color directly\n"
"   FragColor = fragColor;\n"
"}";

const char* RKK_TriangleVertexGLSL = 
"#version 330 core\n"
"\n"
"layout(location = 0) in vec3 VPos; //VertexPos\n"
"\n"
"out vec4 VertFragColor;\n"
"\n"
"uniform vec4 TriangleColor;\n"
"uniform vec2 ScreenSize;\n"
"\n"
"void main() {\n"
"   float sx = VPos.x / ScreenSize.x * 2 - 1;\n"
"   float sy = VPos.y / ScreenSize.y * 2 - 1;\n"
"   gl_Position = vec4(sx, -sy, VPos.z, 1.0);\n"
"   VertFragColor = TriangleColor;\n"
"}\n";

const char* RKK_TriangleFragmentGLSL =
"#version 330 core\n"
"\n"
"in vec4 VertFragColor;\n"
"out vec4 FragColor;\n"
"\n"
"void main() {\n"
"   FragColor = VertFragColor;\n"
"}\n";

const char* RKK_TriangleBlendFragmentGLSL =
"";

#endif

