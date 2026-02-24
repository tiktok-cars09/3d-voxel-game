#include <iostream>

// Prefer real headers when available; otherwise provide minimal local stubs
#if defined(__has_include)
#  if __has_include(<SDL.h>)
#    define SDL_MAIN_HANDLED
#    include <SDL.h>
#  else
/* Minimal SDL stubs to satisfy editor/static analysis when SDL header isn't available. */
typedef unsigned int Uint32; typedef unsigned long long Uint64; typedef unsigned char Uint8;
typedef struct SDL_Window SDL_Window; typedef void* SDL_GLContext;
enum { SDL_INIT_VIDEO = 0x00000020 };
enum { SDL_WINDOW_OPENGL = 0x00000002, SDL_WINDOW_RESIZABLE = 0x00000020 };
#define SDL_WINDOWPOS_CENTERED 0
/* minimal GL attribute macros */
#define SDL_GL_CONTEXT_MAJOR_VERSION 1
#define SDL_GL_CONTEXT_MINOR_VERSION 2
#define SDL_GL_CONTEXT_PROFILE_MASK 3
#define SDL_GL_CONTEXT_PROFILE_CORE 4
#define SDL_GL_DOUBLEBUFFER 5
/* SDL event constants */
#define SDL_QUIT 0x100
#define SDL_WINDOWEVENT 0x200
#define SDL_KEYDOWN 0x300
#define SDL_WINDOWEVENT_SIZE_CHANGED 0x01
#define SDLK_ESCAPE 27
typedef struct { int sym; } SDL_Keysym;
typedef struct { Uint32 type; SDL_Keysym keysym; } SDL_KeyboardEvent;
typedef struct { Uint32 type; Uint32 event; int data1; int data2; } SDL_WindowEvent;
typedef struct { Uint32 type; union { SDL_KeyboardEvent key; SDL_WindowEvent window; }; } SDL_Event;
int SDL_Init(Uint32){return 0;} const char* SDL_GetError(){return "";} int SDL_GL_SetAttribute(int,int){return 0;}
void* SDL_GL_GetProcAddress(const char*){return nullptr;}
SDL_Window* SDL_CreateWindow(const char*, int, int, int, int, Uint32){return nullptr;} SDL_GLContext SDL_GL_CreateContext(SDL_Window*){return nullptr;}
void SDL_GL_DeleteContext(SDL_GLContext){} void SDL_DestroyWindow(SDL_Window*){} void SDL_Quit(void){}
Uint64 SDL_GetPerformanceCounter(void){return 1;} Uint64 SDL_GetPerformanceFrequency(void){return 1;} int SDL_PollEvent(SDL_Event*){return 0;}
void SDL_GetWindowSize(SDL_Window*, int* w, int* h){ if(w) *w=1280; if(h) *h=720; } void SDL_Delay(Uint32){}
void SDL_GL_SwapWindow(SDL_Window*){}
#  endif
#  if __has_include(<glad/glad.h>)
#    include <glad/glad.h>
#  else
#/* Minimal GL types/enums used by the file to silence analyzer when real GL headers are absent. */
typedef unsigned int GLuint; typedef int GLint; typedef unsigned int GLenum; typedef unsigned char GLboolean; typedef float GLfloat; typedef int GLsizei; typedef unsigned int GLbitfield;
#define GL_COMPILE_STATUS 0x8B81
#define GL_LINK_STATUS 0x8B82
#define GL_DEPTH_TEST 0x0B71
#define GL_ARRAY_BUFFER 0x8892
#define GL_STATIC_DRAW 0x88E4
#define GL_FLOAT 0x1406
#define GL_FALSE 0
#define GL_VERTEX_SHADER 0x8B31
#define GL_FRAGMENT_SHADER 0x8B30
#define GL_TRIANGLES 0x0004
#define GL_COLOR_BUFFER_BIT 0x4000
#define GL_DEPTH_BUFFER_BIT 0x0100
typedef void* (*GLADloadproc)(const char*);
int gladLoadGLLoader(GLADloadproc){return 1;}
void glEnable(GLenum cap){}
GLuint glCreateShader(GLenum){return 1;} void glShaderSource(GLuint, GLsizei, const char**, const GLint*){}
void glCompileShader(GLuint){} void glGetShaderiv(GLuint, GLenum, GLint*){} void glGetShaderInfoLog(GLuint, GLsizei, GLsizei*, char*){}
GLuint glCreateProgram(void){return 1;} void glAttachShader(GLuint, GLuint){} void glLinkProgram(GLuint){}
void glGetProgramiv(GLuint, GLenum, GLint*){} void glGetProgramInfoLog(GLuint, GLsizei, GLsizei*, char*){}
void glDeleteShader(GLuint){} void glDeleteProgram(GLuint){}
void glGenVertexArrays(GLsizei, GLuint*){} void glGenBuffers(GLsizei, GLuint*){} void glBindVertexArray(GLuint){}
void glBindBuffer(GLenum, GLuint){} void glBufferData(GLenum, std::size_t, const void*, GLenum){}
void glEnableVertexAttribArray(GLuint){} void glVertexAttribPointer(GLuint, GLint, GLenum, GLboolean, GLsizei, const void*){}
void glDeleteBuffers(GLsizei, const GLuint*){} void glDeleteVertexArrays(GLsizei, const GLuint*){}
void glDrawArrays(GLenum, GLint, GLsizei){} void glClear(GLbitfield){} void glClearColor(GLfloat,GLfloat,GLfloat,GLfloat){}
void glViewport(GLint, GLint, GLsizei, GLsizei){} void glUseProgram(GLuint){} void glUniformMatrix4fv(GLint, GLsizei, GLboolean, const GLfloat*){}
GLint glGetUniformLocation(GLuint, const char*){return 0;}
#  endif
#  if __has_include(<glm/glm.hpp>)
#    include <glm/glm.hpp>
#    include <glm/gtc/matrix_transform.hpp>
#    include <glm/gtc/type_ptr.hpp>
#  else
/* Minimal glm stubs to satisfy static analysis when glm isn't installed. */
namespace glm {
    struct vec3 { float x,y,z; vec3(float a=0,float b=0,float c=0):x(a),y(b),z(c){} };
    struct mat4 { float data[16]; mat4(){ for(int i=0;i<16;++i) data[i]=(i%5)==0?1.0f:0.0f; } mat4(float d){ for(int i=0;i<16;++i) data[i]=0.0f; for(int i=0;i<4;++i) data[i*5]=d; } };
    inline float radians(float deg){ return deg * 3.14159265358979323846f / 180.0f; }
    inline mat4 perspective(float,float,float,float){ return mat4(); }
    inline mat4 translate(const mat4&, const vec3&){ return mat4(); }
    inline mat4 rotate(const mat4&, float, const vec3&){ return mat4(); }
    inline const float* value_ptr(const mat4& m){ return m.data; }
    inline mat4 operator*(const mat4& a, const mat4& b){ mat4 r; for (int i=0;i<4;++i) for (int j=0;j<4;++j){ r.data[i*4+j]=0.0f; for(int k=0;k<4;++k) r.data[i*4+j]+=a.data[i*4+k]*b.data[k*4+j]; } return r; }
}
#  endif
#else
/* Fallback: assume headers exist on compilers without __has_include */
#define SDL_MAIN_HANDLED
#include <SDL.h>
#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#endif

static const char* vertex_shader_src = R"glsl(
#version 330 core
layout(location = 0) in vec3 inPos;
layout(location = 1) in vec3 inColor;
out vec3 fragColor;
uniform mat4 uMVP;
void main() {
    fragColor = inColor;
    gl_Position = uMVP * vec4(inPos, 1.0);
}
)glsl";

static const char* fragment_shader_src = R"glsl(
#version 330 core
in vec3 fragColor;
out vec4 outColor;
void main() {
    outColor = vec4(fragColor, 1.0);
}
)glsl";

static GLuint compileShader(GLenum type, const char* src) {
    GLuint s = glCreateShader(type);
    glShaderSource(s, 1, &src, nullptr);
    glCompileShader(s);
    GLint ok = 0;
    glGetShaderiv(s, GL_COMPILE_STATUS, &ok);
    if (!ok) {
        char buf[1024];
        glGetShaderInfoLog(s, sizeof(buf), nullptr, buf);
        std::cerr << "Shader compile error: " << buf << std::endl;
    }
    return s;
}

static GLuint linkProgram(GLuint vs, GLuint fs) {
    GLuint p = glCreateProgram();
    glAttachShader(p, vs);
    glAttachShader(p, fs);
    glLinkProgram(p);
    GLint ok = 0;
    glGetProgramiv(p, GL_LINK_STATUS, &ok);
    if (!ok) {
        char buf[1024];
        glGetProgramInfoLog(p, sizeof(buf), nullptr, buf);
        std::cerr << "Program link error: " << buf << std::endl;
    }
    return p;
}

int main(int argc, char** argv) {
    (void)argc; (void)argv;

    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cerr << "SDL_Init error: " << SDL_GetError() << std::endl;
        return 1;
    }

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

    SDL_Window* window = SDL_CreateWindow("voxel_demo",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        1280, 720,
        SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);

    if (!window) {
        std::cerr << "SDL_CreateWindow error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    SDL_GLContext glContext = SDL_GL_CreateContext(window);
    if (!glContext) {
        std::cerr << "SDL_GL_CreateContext error: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    if (!gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress)) {
        std::cerr << "Failed to initialize GLAD" << std::endl;
        SDL_GL_DeleteContext(glContext);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    glEnable(GL_DEPTH_TEST);

    // Simple colored cube (36 vertices)
    float vertices[] = {
        // positions        // colors
        -0.5f,-0.5f,-0.5f,  1,0,0,
         0.5f,-0.5f,-0.5f,  0,1,0,
         0.5f, 0.5f,-0.5f,  0,0,1,
         0.5f, 0.5f,-0.5f,  0,0,1,
        -0.5f, 0.5f,-0.5f,  1,1,0,
        -0.5f,-0.5f,-0.5f,  1,0,0,

        -0.5f,-0.5f, 0.5f,  1,0,1,
         0.5f,-0.5f, 0.5f,  0,1,1,
         0.5f, 0.5f, 0.5f,  1,1,1,
         0.5f, 0.5f, 0.5f,  1,1,1,
        -0.5f, 0.5f, 0.5f,  0.5,0.5,0.5,
        -0.5f,-0.5f, 0.5f,  1,0,1,

        -0.5f, 0.5f, 0.5f,  1,0,0,
        -0.5f, 0.5f,-0.5f,  0,1,0,
        -0.5f,-0.5f,-0.5f,  0,0,1,
        -0.5f,-0.5f,-0.5f,  0,0,1,
        -0.5f,-0.5f, 0.5f,  1,1,0,
        -0.5f, 0.5f, 0.5f,  1,0,0,

         0.5f, 0.5f, 0.5f,  1,0,1,
         0.5f, 0.5f,-0.5f,  0,1,1,
         0.5f,-0.5f,-0.5f,  1,1,1,
         0.5f,-0.5f,-0.5f,  1,1,1,
         0.5f,-0.5f, 0.5f,  0.5,0.5,0.5,
         0.5f, 0.5f, 0.5f,  1,0,1,

        -0.5f,-0.5f,-0.5f,  1,0,0,
         0.5f,-0.5f,-0.5f,  0,1,0,
         0.5f,-0.5f, 0.5f,  0,0,1,
         0.5f,-0.5f, 0.5f,  0,0,1,
        -0.5f,-0.5f, 0.5f,  1,1,0,
        -0.5f,-0.5f,-0.5f,  1,0,0,

        -0.5f, 0.5f,-0.5f,  1,0,1,
         0.5f, 0.5f,-0.5f,  0,1,1,
         0.5f, 0.5f, 0.5f,  1,1,1,
         0.5f, 0.5f, 0.5f,  1,1,1,
        -0.5f, 0.5f, 0.5f,  0.5,0.5,0.5,
        -0.5f, 0.5f,-0.5f,  1,0,1
    };

    GLuint vao, vbo;
    glGenVertexArrays(1, &vao);
    glGenBuffers(1, &vbo);
    glBindVertexArray(vao);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glBindVertexArray(0);

    GLuint vs = compileShader(GL_VERTEX_SHADER, vertex_shader_src);
    GLuint fs = compileShader(GL_FRAGMENT_SHADER, fragment_shader_src);
    GLuint program = linkProgram(vs, fs);
    glDeleteShader(vs);
    glDeleteShader(fs);

    bool running = true;
    Uint64 start = SDL_GetPerformanceCounter();
    while (running) {
        SDL_Event ev;
        while (SDL_PollEvent(&ev)) {
            if (ev.type == SDL_QUIT) running = false;
            if (ev.type == SDL_KEYDOWN && ev.key.keysym.sym == SDLK_ESCAPE) running = false;
            if (ev.type == SDL_WINDOWEVENT && ev.window.event == SDL_WINDOWEVENT_SIZE_CHANGED) {
                int w = ev.window.data1;
                int h = ev.window.data2;
                glViewport(0,0,w,h);
            }
        }

        Uint64 now = SDL_GetPerformanceCounter();
        double elapsed = (double)(now - start) / (double)SDL_GetPerformanceFrequency();

        glClearColor(0.1f, 0.12f, 0.15f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        int w, h;
        SDL_GetWindowSize(window, &w, &h);
        float aspect = w > 0 && h > 0 ? (float)w / (float)h : 16.0f/9.0f;

        glm::mat4 proj = glm::perspective(glm::radians(45.0f), aspect, 0.1f, 100.0f);
        glm::mat4 view = glm::translate(glm::mat4(1.0f), glm::vec3(0,0,-3.0f));
        // base slight angle on X axis
        glm::mat4 baseTilt = glm::rotate(glm::mat4(1.0f), glm::radians(-25.0f), glm::vec3(1,0,0));
        glm::mat4 rot = glm::rotate(glm::mat4(1.0f), (float)elapsed * glm::radians(25.0f), glm::vec3(0,1,0));
        glm::mat4 model = baseTilt * rot;

        glm::mat4 mvp = proj * view * model;

        glUseProgram(program);
        GLint loc = glGetUniformLocation(program, "uMVP");
        glUniformMatrix4fv(loc, 1, GL_FALSE, glm::value_ptr(mvp));

        glBindVertexArray(vao);
        glDrawArrays(GL_TRIANGLES, 0, 36);

        SDL_GL_SwapWindow(window);
        SDL_Delay(16); // ~60fps
    }

    glDeleteProgram(program);
    glDeleteBuffers(1, &vbo);
    glDeleteVertexArrays(1, &vao);

    SDL_GL_DeleteContext(glContext);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
