#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <unistd.h>
#include <chrono>
#include <cstddef>
#include <glimac/FilePath.hpp>
#include <glimac/Image.hpp>
#include <glimac/Program.hpp>
#include <glimac/Sphere.hpp>
#include <glimac/glm.hpp> //Permet d'avoir des types de vecteurs, matrices et autres
#include <iostream>
#include <vector>
#include "glimac/common.hpp"
#include "glm/ext/matrix_clip_space.hpp"
#include "glm/fwd.hpp"

using namespace std;

// int window_width  = 1280;
// int window_height = 720;

// static void key_callback(GLFWwindow* /*window*/, int /*key*/, int /*scancode*/, int /*action*/, int /*mods*/)
// {
// }

// static void mouse_button_callback(GLFWwindow* /*window*/, int /*button*/, int /*action*/, int /*mods*/)
// {
// }

// static void scroll_callback(GLFWwindow* /*window*/, double /*xoffset*/, double /*yoffset*/)
// {
// }

// static void cursor_position_callback(GLFWwindow* /*window*/, double /*xpos*/, double /*ypos*/)
// {
// }

// static void size_callback(GLFWwindow* /*window*/, int width, int height)
// {
//     window_width  = width;
//     window_height = height;
// }

// glimac::Sphere sphere(1, 32, 16);

// int main()
// {
//     /* Initialize the library */
//     if (!glfwInit()) {
//         return -1;
//     }

//     /* Create a window and its OpenGL context */
// #ifdef __APPLE__
//     /* We need to explicitly ask for a 3.3 context on Mac */
//     glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//     glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//     glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
//     glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
// #endif
//     GLFWwindow* window = glfwCreateWindow(window_width, window_height, "TP3", nullptr, nullptr);
//     if (!window) {
//         glfwTerminate();
//         return -1;
//     }

//     /* Make the window's context current */
//     glfwMakeContextCurrent(window);

//     /* Intialize glad (loads the OpenGL functions) */
//     if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
//         return -1;
//     }

//     /* Hook input callbacks */
//     glfwSetKeyCallback(window, &key_callback);
//     glfwSetMouseButtonCallback(window, &mouse_button_callback);
//     glfwSetScrollCallback(window, &scroll_callback);
//     glfwSetCursorPosCallback(window, &cursor_position_callback);
//     glfwSetWindowSizeCallback(window, &size_callback);

//     /* Loop until the user closes the window */
//     while (!glfwWindowShouldClose(window)) {
//         glClearColor(0.5f, 1.f, 0.5f, 1.f);
//         glClear(GL_COLOR_BUFFER_BIT);

//         /* Swap front and back buffers */
//         glfwSwapBuffers(window);
//         /* Poll for and process events */
//         glfwPollEvents();
//     }

//     glfwTerminate();
//     return 0;
// }

// Vertex
int window_width  = 1280;
int window_height = 720;

static void key_callback(GLFWwindow* /*window*/, int /*key*/, int /*scancode*/, int /*action*/, int /*mods*/)
{
}

static void mouse_button_callback(GLFWwindow* /*window*/, int /*button*/, int /*action*/, int /*mods*/)
{
}

static void scroll_callback(GLFWwindow* /*window*/, double /*xoffset*/, double /*yoffset*/)
{
}

static void cursor_position_callback(GLFWwindow* /*window*/, double /*xpos*/, double /*ypos*/)
{
}

static void size_callback(GLFWwindow* /*window*/, int width, int height)
{
    window_width  = width;
    window_height = height;
}

int main([[maybe_unused]] int argc, char* argv[])
{
    /* Initialize the library */
    if (!glfwInit()) {
        return -1;
    }

    /* Create a window and its OpenGL context */
#ifdef __APPLE__
    /* We need to explicitly ask for a 3.3 context on Mac */
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#endif
    GLFWwindow* window = glfwCreateWindow(window_width, window_height, "TP1", nullptr, nullptr);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    /* Intialize glad (loads the OpenGL functions) */
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        return -1;
    }

    /* Hook input callbacks */
    glfwSetKeyCallback(window, &key_callback);
    glfwSetMouseButtonCallback(window, &mouse_button_callback);
    glfwSetScrollCallback(window, &scroll_callback);
    glfwSetCursorPosCallback(window, &cursor_position_callback);
    glfwSetWindowSizeCallback(window, &size_callback);

    /*Here should come the initialization code, trucs avant la boucle while (création des meshs...)*/

    glimac::Sphere sphere(1, 32, 16);

    glm::mat4 ProjMatrix = glm::perspective(glm::radians(70.f), (window_width / (float)window_height), 0.1f, 100.f);

    glm::mat4 MVMatrix = glm::translate(glm::mat4(1.0), glm::vec3(0, 0, -5));

    glm::mat4 NormalMatrix = glm::transpose(glm::inverse(MVMatrix));

    glimac::FilePath applicationPath(argv[0]);
    glimac::Program  program = glimac::loadProgram(applicationPath.dirPath() + "TP3/shaders/3D.vs.glsl", applicationPath.dirPath() + "TP3/shaders/normals.fs.glsl");
    program.use();

    // Récupération des locations
    GLuint u_mvp    = glGetUniformLocation(program.getGLId(), "uMVPMatrix");
    GLuint u_mv     = glGetUniformLocation(program.getGLId(), "uMVMatrix");
    GLuint u_normal = glGetUniformLocation(program.getGLId(), "uNormalMatrix");

    glEnable(GL_DEPTH_TEST);

    // Création d'un VBO
    GLuint vbo;
    glGenBuffers(1, &vbo);
    // À partir de ce point la variable vbo contient l'identifiant d'un vbo
    // 1 est le nombre de vbo à créer
    // vbo est un pointeur vers un tableau d'entiers remplis par les identifiants des VBOs crées.

    // Binding d'un VBO sur la cible GL_ARRAY_BUFFER:
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    // 1er paramètre : nom de la cible, sous la forme d'une constante OPENGL
    // 2e parametre : le buffer à binder
    //  On peut à présent modifier le VBO en passant par la cible GL_ARRAY_BUFFER

    // Remplir le vbo
    //  float vertices[] = {
    //      -0.5, -0.5, 1, 0, 0,
    //      0.5, -0.5, 0, 1, 0,
    //      0, 0.5, 0, 0, 1
    //  };

    glBufferData(GL_ARRAY_BUFFER, sphere.getVertexCount() * sizeof(glimac::ShapeVertex), sphere.getDataPointer(), GL_STATIC_DRAW);
    // 1e argument : la cible sur laquelle le buffer est bindé (GL_ARRAY_BUFFER dans notre cas)
    // 2e argument : le pointeur vers les données (notre tableau de flottants)
    // 3e argument : un flag indiquant à OpenGL quel usage on va faire du buffer. On utilise GL_STATIC_DRAW pour un buffer dont les données ne changeront jamais.
    // On debind le vbo
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    // Création d'un VAO
    GLuint vao;
    glGenVertexArrays(1, &vao);

    // on bind le vao
    glBindVertexArray(vao);

    // Utilisation d'un attribut
    const GLuint VERTEX_ATTR_POSITION = 3;
    const GLuint VERTEX_ATTR_NORM     = 8;
    const GLuint VERTEX_ATTR_COORD    = 8;
    glEnableVertexAttribArray(VERTEX_ATTR_POSITION);
    glEnableVertexAttribArray(VERTEX_ATTR_NORM);
    glEnableVertexAttribArray(VERTEX_ATTR_COORD);
    // Le 0 correspond a l'attribut du sommet identifiant la position
    // 1e argument : l'index de l'attribut à activer

    // On bind le VBO
    glBindBuffer(GL_ARRAY_BUFFER, vbo);

    // indication à OpenGL où il va trouver les sommets à dessiner, et comment lire les informations associé à chaque sommet.
    glVertexAttribPointer(VERTEX_ATTR_POSITION, 2, GL_FLOAT, GL_FALSE, sizeof(glimac::ShapeVertex), (const GLvoid*)(offsetof(glimac::ShapeVertex, position)));
    glVertexAttribPointer(VERTEX_ATTR_NORM, 3, GL_FLOAT, GL_FALSE, sizeof(glimac::ShapeVertex), (const GLvoid*)(offsetof(glimac::ShapeVertex, normal)));
    glVertexAttribPointer(VERTEX_ATTR_COORD, 2, GL_FLOAT, GL_FALSE, sizeof(glimac::ShapeVertex), (const GLvoid*)(offsetof(glimac::ShapeVertex, texCoords)));
    // On débind le vbo
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    // On débind le vao
    glBindVertexArray(0);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window)) {
        glClearColor(0.5f, 0.5f, 0.5f, 1.f);
        glClear(GL_COLOR_BUFFER_BIT); // Le code de dessin est répété à chaque tour de la boucle d'application. Il faut donc d'abord nettoyer la fenêtre afin de ne pas avoir de résidu du tour précédent.

        /*Code de rendu ici*/

        glBindVertexArray(vao);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        glBindVertexArray(0);

        /* Swap front and back buffers (envoyer le buffer sur l'écran)*/
        glfwSwapBuffers(window);
        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    glDeleteBuffers(1, &vbo);
    glDeleteVertexArrays(1, &vao);
    return 0;
}