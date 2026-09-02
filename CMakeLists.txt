cmake_minimum_required(VERSION 3.20)
project(rogue VERSION 0.1.0)

# C++ standart
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Явно указыва юпапку сборки
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)


# Поиск всех исходников рекурсивно
file(GLOB_RECURSE SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/main.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/external/glad/src/glad.c"
)

add_executable(rogue ${SOURCES})

# Папки с хедерами
target_include_directories(rogue PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/external/SDL/include
    ${CMAKE_CURRENT_SOURCE_DIR}/external/glad/include
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

# Путь к сборке SDL
target_link_directories(rogue PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/external/SDL/lib)

# Зависимости
target_link_libraries(rogue PRIVATE
    SDL3
    opengl32
    gdi32
    winmm
    dxgi
    ole32
)



# add_executable(rogue main.cpp
#     src/world/World.cpp
#     src/engine/Engine.cpp
#     src/game/Game.cpp
#     src/factories/EntityFactory.cpp
#     src/rendering/Renderer.cpp
#     src/systems/CombatSystem.cpp
#     src/systems/DamageSystem.cpp
#     src/systems/InputSystem.cpp
#     src/systems/MovementSystem.cpp
#     src/systems/SystemManager.cpp
# )