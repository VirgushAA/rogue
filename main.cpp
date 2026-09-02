#include <iostream>
#include <SDL3/SDL.h>
#include <glad/glad.h>
#include <GL/gl.h>

#include "src/engine/Engine.hpp"
#include "src/game/Game.hpp"

// Вершинный шейдер
const char* vertexShaderSource = R"(
#version 450 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;

out vec3 vertexColor;

uniform float angle;

void main() {

    const vec2 pivot = vec2( 0.0f, -0.16667f );
    vec2 centeredXY = aPos.xy - pivot;

    mat4 rotation = mat4(
        cos(angle), -sin(angle), 0.0f, 0.0f,
        sin(angle), cos(angle), 0.0f, 0.0f,
        0.0f, 0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 0.0f, 1.0f);

    vec4 rotated = rotation * vec4( centeredXY, aPos.z, 1.0 );
    vec2 rotatedXY = rotated.xy + pivot;

    gl_Position = vec4( rotatedXY, aPos.z, 1.0 );

    vertexColor = aColor;
}
)";

// Фрагментный шейдер
const char* fragmentShaderSource = R"(
#version 450 core
in vec3 vertexColor;
out vec4 FragColor;

void main()
{
    FragColor = vec4(vertexColor, 1.0);
}
)";

const int width = 600;
const int height = 460;
const int gridWidth = 20;
const int gridHeight = 16;
const int cellSize_x = width / gridWidth;
const int cellSize_y = height / gridHeight;


int main() {
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 5);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1); // Двойная буферизация
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24); // Буфер глубины

    if ( !SDL_Init(SDL_INIT_VIDEO) ) {
        std::cout << "SDL_init error: " << SDL_GetError() << std::endl;
        return 1;
    }

    SDL_Window* window = SDL_CreateWindow( "Rogue Huegue", width, height, SDL_WINDOW_OPENGL );
    
    if ( !window ) {
        std::cout << "SDL_CreateWindow error: " << SDL_GetError() << std::endl;
        return 1;
    }
    
    SDL_GLContext gl_context = SDL_GL_CreateContext(window);
    if ( !gl_context ) {
        std::cout << "GLContext error: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        return 1;
    }
    
    if ( !gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress) ) {
        std::cout << "Failed to load initialize GLAD" << std::endl;
        SDL_GL_DestroyContext(gl_context);
        SDL_DestroyWindow(window);
        return 1;
    }

    // Компиляция вершинного шейдера
    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);

    int success;
    char infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    // Компиляция фрагментного шейдера
    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);

    int success1;
    char infoLog1[512];
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success1);
    if (!success1) {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog1);
        std::cout << "ERROR::SHADER::COMPILATION_FAILED\n" << infoLog1 << std::endl;
    }

    // Сборка программы
    unsigned int shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    // И удалить промежуточные шейдеры, они уже в программе
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);


    float vertices[] = {
        0.0f, 0.5f, 0.0f, 1.0f, 0.0f, 0.0f,
        0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f,
        -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f
    };
    GLuint VBO, VAO;
    glGenBuffers(1, &VBO);
    glGenVertexArrays(1, &VAO);

    // привязываю?
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBindVertexArray(VAO);

    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));

    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    
    // Отвязываю?
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    // glBindVertexArray(0);

    glUseProgram(shaderProgram);
    glBindVertexArray(VAO);

    SDL_GL_SetSwapInterval(1);

    std::cout << "renderer: " << glGetString(GL_RENDERER) << std::endl;
    std::cout << "verion: " << glGetString(GL_VERSION) << std::endl;
    
    bool isRunning = true;
    SDL_Event event;

    GLint angleLocation = glGetUniformLocation(shaderProgram, "angle");
    float angle = 0.0f;
    glUniform1f(angleLocation, angle);
    glClearColor(0.05f, 0.05f, 0.1f, 1.0f);

    auto previousTime = std::chrono::steady_clock::now();
    float dt = updateTime(previousTime);
    float speed = 1;
    
    while ( isRunning ) {
        while ( SDL_PollEvent(&event) ) {
            if ( event.type == SDL_EVENT_QUIT ) isRunning = false;
            if ( event.type == SDL_EVENT_KEY_DOWN && event.key.key == SDLK_ESCAPE ) isRunning = false;
        }
        
        angle += speed * dt;
        dt = updateTime(previousTime);
        glUniform1f(angleLocation, angle);
        
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        
        glDrawArrays(GL_TRIANGLES, 0, 3);
        

        SDL_GL_SwapWindow(window);
    }
    
    SDL_GL_DestroyContext(gl_context);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
