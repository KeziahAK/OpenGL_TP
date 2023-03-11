#include "glm/ext/matrix_transform.hpp"
#include "glm/ext/vector_float3.hpp"
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
#include "glm/ext/matrix_transform.hpp"


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
//         glClear(|GL_DEPTH_BUFFER_BIT);

//         /* Swap front and back buffers */
//         glfwSwapBuffers(window);
//         /* Poll for and process events */
//         glfwPollEvents();
//     }

//     glfwTerminate();
//     return 0;
// }

// // Sphere
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

// int main([[maybe_unused]] int argc, char* argv[])
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
//     GLFWwindow* window = glfwCreateWindow(window_width, window_height, "TP1", nullptr, nullptr);
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

//     /*Here should come the initialization code, trucs avant la boucle while (création des meshs...)*/

//     glimac::Sphere sphere(1, 32, 16);

//     glm::mat4 ProjMatrix = glm::perspective(glm::radians(70.f), (window_width / (float)window_height), 0.1f, 100.f);

//     glm::mat4 MVMatrix = glm::translate(glm::mat4(1.0), glm::vec3(0, 0, -5));

//     glm::mat4 NormalMatrix = glm::transpose(glm::inverse(MVMatrix));

//     glimac::FilePath applicationPath(argv[0]);
//     glimac::Program  program = glimac::loadProgram(applicationPath.dirPath() + "TP3/shaders/3D.vs.glsl", applicationPath.dirPath() + "TP3/shaders/normals.fs.glsl");
//     program.use();

//     // Récupération des locations
//     GLuint u_mvp    = glGetUniformLocation(program.getGLId(), "uMVPMatrix");
//     GLuint u_mv     = glGetUniformLocation(program.getGLId(), "uMVMatrix");
//     GLuint u_normal = glGetUniformLocation(program.getGLId(), "uNormalMatrix");

//     glEnable(GL_DEPTH_TEST);

//     // Création d'un VBO
//     GLuint vbo;
//     glGenBuffers(1, &vbo);
//     // À partir de ce point la variable vbo contient l'identifiant d'un vbo
//     // 1 est le nombre de vbo à créer
//     // vbo est un pointeur vers un tableau d'entiers remplis par les identifiants des VBOs crées.

//     // Binding d'un VBO sur la cible GL_ARRAY_BUFFER:
//     glBindBuffer(GL_ARRAY_BUFFER, vbo);
//     // 1er paramètre : nom de la cible, sous la forme d'une constante OPENGL
//     // 2e parametre : le buffer à binder
//     //  On peut à présent modifier le VBO en passant par la cible GL_ARRAY_BUFFER

//     // Remplir le vbo
//     //  float vertices[] = {
//     //      -0.5, -0.5, 1, 0, 0,
//     //      0.5, -0.5, 0, 1, 0,
//     //      0, 0.5, 0, 0, 1
//     //  };

//     glBufferData(GL_ARRAY_BUFFER, sphere.getVertexCount() * sizeof(glimac::ShapeVertex), sphere.getDataPointer(), GL_STATIC_DRAW);
//     // 1e argument : la cible sur laquelle le buffer est bindé (GL_ARRAY_BUFFER dans notre cas)
//     // 2e argument : le pointeur vers les données (notre tableau de flottants)
//     // 3e argument : un flag indiquant à OpenGL quel usage on va faire du buffer. On utilise GL_STATIC_DRAW pour un buffer dont les données ne changeront jamais.
//     // On debind le vbo
//     glBindBuffer(GL_ARRAY_BUFFER, 0);

//     // Création d'un VAO
//     GLuint vao;
//     glGenVertexArrays(1, &vao);

//     // on bind le vao
//     glBindVertexArray(vao);

//     // Utilisation d'un attribut
//     const GLuint VERTEX_ATTR_POSITION = 0;
//     const GLuint VERTEX_ATTR_NORM     = 1;
//     const GLuint VERTEX_ATTR_COORD    = 2;
//     glEnableVertexAttribArray(VERTEX_ATTR_POSITION);
//     glEnableVertexAttribArray(VERTEX_ATTR_NORM);
//     glEnableVertexAttribArray(VERTEX_ATTR_COORD);
//     // Le 0 correspond a l'attribut du sommet identifiant la position
//     // 1e argument : l'index de l'attribut à activer

//     // On bind le VBO
//     glBindBuffer(GL_ARRAY_BUFFER, vbo);

//     // indication à OpenGL où il va trouver les sommets à dessiner, et comment lire les informations associé à chaque sommet.
//     glVertexAttribPointer(VERTEX_ATTR_POSITION, 2, GL_FLOAT, GL_FALSE, sizeof(glimac::ShapeVertex), (const GLvoid*)(offsetof(glimac::ShapeVertex, position)));
//     glVertexAttribPointer(VERTEX_ATTR_NORM, 3, GL_FLOAT, GL_FALSE, sizeof(glimac::ShapeVertex), (const GLvoid*)(offsetof(glimac::ShapeVertex, normal)));
//     glVertexAttribPointer(VERTEX_ATTR_COORD, 2, GL_FLOAT, GL_FALSE, sizeof(glimac::ShapeVertex), (const GLvoid*)(offsetof(glimac::ShapeVertex, texCoords)));
//     // On débind le vbo
//     glBindBuffer(GL_ARRAY_BUFFER, 0);

//     // On débind le vao
//     glBindVertexArray(0);

//     /* Loop until the user closes the window */
//     while (!glfwWindowShouldClose(window)) {
//         glClearColor(0.3f, 0.4f, 0.2f, 1.f);
//         glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT); // Le code de dessin est répété à chaque tour de la boucle d'application. Il faut donc d'abord nettoyer la fenêtre afin de ne pas avoir de résidu du tour précédent.

//         /*Code de rendu ici*/
//         glUniformMatrix4fv(u_mv,1,GL_FALSE,glm::value_ptr(MVMatrix));
//         glUniformMatrix4fv(u_mvp,1,GL_FALSE,glm::value_ptr(ProjMatrix * MVMatrix));
//         glUniformMatrix4fv(u_normal,1,GL_FALSE,glm::value_ptr(NormalMatrix));
        
//         glBindVertexArray(vao);
        
//         glDrawArrays(GL_TRIANGLES, 0, sphere.getVertexCount());
//         glBindVertexArray(0);

//         /* Swap front and back buffers (envoyer le buffer sur l'écran)*/
//         glfwSwapBuffers(window);
//         /* Poll for and process events */
//         glfwPollEvents();
//     }

//     glfwTerminate();
//     glDeleteBuffers(1, &vbo);
//     glDeleteVertexArrays(1, &vao);
//     return 0;
// }


// // Lune 3D
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

// int main([[maybe_unused]] int argc, char* argv[])
// {

//     auto t_start = std::chrono::high_resolution_clock::now();
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
//     GLFWwindow* window = glfwCreateWindow(window_width, window_height, "TP1", nullptr, nullptr);
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

//     /*Here should come the initialization code, trucs avant la boucle while (création des meshs...)*/

//     glimac::Sphere sphere(1, 32, 16);



//     glimac::FilePath applicationPath(argv[0]);
//     glimac::Program  program = glimac::loadProgram(applicationPath.dirPath() + "TP3/shaders/3D.vs.glsl", applicationPath.dirPath() + "TP3/shaders/normals.fs.glsl");
//     program.use();

//     // Récupération des locations
//     GLuint u_mvp    = glGetUniformLocation(program.getGLId(), "uMVPMatrix");
//     GLuint u_mv     = glGetUniformLocation(program.getGLId(), "uMVMatrix");
//     GLuint u_normal = glGetUniformLocation(program.getGLId(), "uNormalMatrix");

//     glEnable(GL_DEPTH_TEST);

//     // Création d'un VBO
//     GLuint vbo;
//     glGenBuffers(1, &vbo);
//     // À partir de ce point la variable vbo contient l'identifiant d'un vbo
//     // 1 est le nombre de vbo à créer
//     // vbo est un pointeur vers un tableau d'entiers remplis par les identifiants des VBOs crées.

//     // Binding d'un VBO sur la cible GL_ARRAY_BUFFER:
//     glBindBuffer(GL_ARRAY_BUFFER, vbo);
//     // 1er paramètre : nom de la cible, sous la forme d'une constante OPENGL
//     // 2e parametre : le buffer à binder
//     //  On peut à présent modifier le VBO en passant par la cible GL_ARRAY_BUFFER

//     glBufferData(GL_ARRAY_BUFFER, sphere.getVertexCount() * sizeof(glimac::ShapeVertex), sphere.getDataPointer(), GL_STATIC_DRAW);
//     // 1e argument : la cible sur laquelle le buffer est bindé (GL_ARRAY_BUFFER dans notre cas)
//     // 2e argument : le pointeur vers les données (notre tableau de flottants)
//     // 3e argument : un flag indiquant à OpenGL quel usage on va faire du buffer. On utilise GL_STATIC_DRAW pour un buffer dont les données ne changeront jamais.
//     // On debind le vbo
//     glBindBuffer(GL_ARRAY_BUFFER, 0);

//     // Création d'un VAO
//     GLuint vao;
//     glGenVertexArrays(1, &vao);

//     // on bind le vao
//     glBindVertexArray(vao);

//     // Utilisation d'un attribut
//     const GLuint VERTEX_ATTR_POSITION = 0;
//     const GLuint VERTEX_ATTR_NORM     = 1;
//     const GLuint VERTEX_ATTR_COORD    = 2;
//     glEnableVertexAttribArray(VERTEX_ATTR_POSITION);
//     glEnableVertexAttribArray(VERTEX_ATTR_NORM);
//     glEnableVertexAttribArray(VERTEX_ATTR_COORD);
//     // Le 0 correspond a l'attribut du sommet identifiant la position
//     // 1e argument : l'index de l'attribut à activer

//     // On bind le VBO
//     glBindBuffer(GL_ARRAY_BUFFER, vbo);

//     // indication à OpenGL où il va trouver les sommets à dessiner, et comment lire les informations associé à chaque sommet.
//     glVertexAttribPointer(VERTEX_ATTR_POSITION, 3, GL_FLOAT, GL_FALSE, sizeof(glimac::ShapeVertex), (const GLvoid*)(offsetof(glimac::ShapeVertex, position)));
//     glVertexAttribPointer(VERTEX_ATTR_NORM, 3, GL_FLOAT, GL_FALSE, sizeof(glimac::ShapeVertex), (const GLvoid*)(offsetof(glimac::ShapeVertex, normal)));
//     glVertexAttribPointer(VERTEX_ATTR_COORD, 2, GL_FLOAT, GL_FALSE, sizeof(glimac::ShapeVertex), (const GLvoid*)(offsetof(glimac::ShapeVertex, texCoords)));
//     // On débind le vbo
//     glBindBuffer(GL_ARRAY_BUFFER, 0);

//     // On débind le vao
//     glBindVertexArray(0);


//     /* Loop until the user closes the window */
//     while (!glfwWindowShouldClose(window)) {
//         glClearColor(0.2f, 0.4f, 0.6f, 1.f);
//         glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT); // Le code de dessin est répété à chaque tour de la boucle d'application. Il faut donc d'abord nettoyer la fenêtre afin de ne pas avoir de résidu du tour précédent.


//         auto t_now = std::chrono::high_resolution_clock::now();
//         float time = std::chrono::duration_cast<std::chrono::duration<float>>(t_now - t_start).count();

//         glBindVertexArray(vao);
//         glm::mat4 ProjMatrix = glm::perspective(glm::radians(70.f), (window_width / (float)window_height), 0.1f, 100.f);

//         glm::mat4 MVMatrix = glm::translate(glm::mat4(1.0), glm::vec3(0, 0, -5));

//         glm::mat4 NormalMatrix = glm::transpose(glm::inverse(MVMatrix));

//         glUniformMatrix4fv(u_mvp,1,GL_FALSE,glm::value_ptr(ProjMatrix * MVMatrix));
//         glUniformMatrix4fv(u_normal,1,GL_FALSE,glm::value_ptr(NormalMatrix));
//         glUniformMatrix4fv(u_mv,1,GL_FALSE,glm::value_ptr(MVMatrix));

//         glDrawArrays(GL_TRIANGLES, 0, sphere.getVertexCount());

//         MVMatrix=glm::rotate(MVMatrix, time * glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
//         MVMatrix = glm::translate(MVMatrix, glm::vec3(-2, 0, 0)); // Translation * Rotation * Translation
//         MVMatrix = glm::scale(MVMatrix, glm::vec3(0.2, 0.2, 0.2)); // Translation * Rotation * Translation * Scale  

//         glUniformMatrix4fv(u_mvp,1,GL_FALSE,glm::value_ptr(ProjMatrix * MVMatrix));
//         glUniformMatrix4fv(u_normal,1,GL_FALSE,glm::value_ptr(NormalMatrix));
//         glUniformMatrix4fv(u_mv,1,GL_FALSE,glm::value_ptr(MVMatrix));
//         /*Code de rendu ici*/


//         glDrawArrays(GL_TRIANGLES, 0, sphere.getVertexCount());
//         //glDrawArrays(GL_TRIANGLES, 0, sphere.getVertexCount());


//         //glDrawArrays(GL_TRIANGLES, 0, sphere.getVertexCount());

        
        
        
//         glBindVertexArray(0);

//         /* Swap front and back buffers (envoyer le buffer sur l'écran)*/
//         glfwSwapBuffers(window);
//         /* Poll for and process events */
//         glfwPollEvents();
//     }

//     glfwTerminate();
//     glDeleteBuffers(1, &vbo);
//     glDeleteVertexArrays(1, &vao);
//     return 0;
// }



// // Plein de lune 3D
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

// int main([[maybe_unused]] int argc, char* argv[])
// {

//     auto t_start = std::chrono::high_resolution_clock::now();
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
//     GLFWwindow* window = glfwCreateWindow(window_width, window_height, "TP1", nullptr, nullptr);
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

//     /*Here should come the initialization code, trucs avant la boucle while (création des meshs...)*/

//     glimac::Sphere sphere(1, 32, 16);



//     glimac::FilePath applicationPath(argv[0]);
//     glimac::Program  program = glimac::loadProgram(applicationPath.dirPath() + "TP3/shaders/3D.vs.glsl", applicationPath.dirPath() + "TP3/shaders/normals.fs.glsl");
//     program.use();

//     // Récupération des locations
//     GLuint u_mvp    = glGetUniformLocation(program.getGLId(), "uMVPMatrix");
//     GLuint u_mv     = glGetUniformLocation(program.getGLId(), "uMVMatrix");
//     GLuint u_normal = glGetUniformLocation(program.getGLId(), "uNormalMatrix");

//     glEnable(GL_DEPTH_TEST);

//     // Création d'un VBO
//     GLuint vbo;
//     glGenBuffers(1, &vbo);
//     // À partir de ce point la variable vbo contient l'identifiant d'un vbo
//     // 1 est le nombre de vbo à créer
//     // vbo est un pointeur vers un tableau d'entiers remplis par les identifiants des VBOs crées.

//     // Binding d'un VBO sur la cible GL_ARRAY_BUFFER:
//     glBindBuffer(GL_ARRAY_BUFFER, vbo);
//     // 1er paramètre : nom de la cible, sous la forme d'une constante OPENGL
//     // 2e parametre : le buffer à binder
//     //  On peut à présent modifier le VBO en passant par la cible GL_ARRAY_BUFFER

//     glBufferData(GL_ARRAY_BUFFER, sphere.getVertexCount() * sizeof(glimac::ShapeVertex), sphere.getDataPointer(), GL_STATIC_DRAW);
//     // 1e argument : la cible sur laquelle le buffer est bindé (GL_ARRAY_BUFFER dans notre cas)
//     // 2e argument : le pointeur vers les données (notre tableau de flottants)
//     // 3e argument : un flag indiquant à OpenGL quel usage on va faire du buffer. On utilise GL_STATIC_DRAW pour un buffer dont les données ne changeront jamais.
//     // On debind le vbo
//     glBindBuffer(GL_ARRAY_BUFFER, 0);

//     // Création d'un VAO
//     GLuint vao;
//     glGenVertexArrays(1, &vao);

//     // on bind le vao
//     glBindVertexArray(vao);

//     // Utilisation d'un attribut
//     const GLuint VERTEX_ATTR_POSITION = 0;
//     const GLuint VERTEX_ATTR_NORM     = 1;
//     const GLuint VERTEX_ATTR_COORD    = 2;
//     glEnableVertexAttribArray(VERTEX_ATTR_POSITION);
//     glEnableVertexAttribArray(VERTEX_ATTR_NORM);
//     glEnableVertexAttribArray(VERTEX_ATTR_COORD);
//     // Le 0 correspond a l'attribut du sommet identifiant la position
//     // 1e argument : l'index de l'attribut à activer

//     // On bind le VBO
//     glBindBuffer(GL_ARRAY_BUFFER, vbo);

//     // indication à OpenGL où il va trouver les sommets à dessiner, et comment lire les informations associé à chaque sommet.
//     glVertexAttribPointer(VERTEX_ATTR_POSITION, 3, GL_FLOAT, GL_FALSE, sizeof(glimac::ShapeVertex), (const GLvoid*)(offsetof(glimac::ShapeVertex, position)));
//     glVertexAttribPointer(VERTEX_ATTR_NORM, 3, GL_FLOAT, GL_FALSE, sizeof(glimac::ShapeVertex), (const GLvoid*)(offsetof(glimac::ShapeVertex, normal)));
//     glVertexAttribPointer(VERTEX_ATTR_COORD, 2, GL_FLOAT, GL_FALSE, sizeof(glimac::ShapeVertex), (const GLvoid*)(offsetof(glimac::ShapeVertex, texCoords)));
//     // On débind le vbo
//     glBindBuffer(GL_ARRAY_BUFFER, 0);

//     // On débind le vao
//     glBindVertexArray(0);

//     std::vector<glm::vec3> angle;
//     std::vector<glm::vec3> trans;
//     for (int i = 1; i < 33; ++i)
//     { 
//         angle.push_back(glm::sphericalRand(1.0f));
//         trans.push_back(glm::sphericalRand(2.0f));
//     }




//     /* Loop until the user closes the window */
//     while (!glfwWindowShouldClose(window)) {
//         glClearColor(0.2f, 0.4f, 0.6f, 1.f);
//         glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT); // Le code de dessin est répété à chaque tour de la boucle d'application. Il faut donc d'abord nettoyer la fenêtre afin de ne pas avoir de résidu du tour précédent.


//         auto t_now = std::chrono::high_resolution_clock::now();
//         float time = std::chrono::duration_cast<std::chrono::duration<float>>(t_now - t_start).count();

//         glBindVertexArray(vao);
//         glm::mat4 ProjMatrix = glm::perspective(glm::radians(70.f), (window_width / (float)window_height), 0.1f, 100.f);

//         glm::mat4 MVMatrix = glm::translate(glm::mat4(1.0), glm::vec3(0, 0, -5));

//         glm::mat4 NormalMatrix = glm::transpose(glm::inverse(MVMatrix));

//         glUniformMatrix4fv(u_mvp,1,GL_FALSE,glm::value_ptr(ProjMatrix * MVMatrix));
//         glUniformMatrix4fv(u_normal,1,GL_FALSE,glm::value_ptr(NormalMatrix));
//         glUniformMatrix4fv(u_mv,1,GL_FALSE,glm::value_ptr(MVMatrix));

//         glDrawArrays(GL_TRIANGLES, 0, sphere.getVertexCount());


        
        
//         for (int i =0; i<33; i++){

//             glm::mat4 MVMatrix_2 = glm::translate(glm::mat4(1.0), glm::vec3(0, 0, -5));
//             glm::mat4 NormalMatrix_2 = glm::transpose(glm::inverse(MVMatrix_2));

//             MVMatrix_2=glm::rotate(MVMatrix_2, time, glm::vec3(angle[i]));
//             MVMatrix_2 = glm::translate(MVMatrix_2, glm::vec3(trans[i])); // Translation * Rotation * Translation
//             MVMatrix_2 = glm::scale(MVMatrix_2, glm::vec3(0.2, 0.2, 0.2)); // Translation * Rotation * Translation * Scale  


//             glUniformMatrix4fv(u_mvp,1,GL_FALSE,glm::value_ptr(ProjMatrix * MVMatrix_2));
//             glUniformMatrix4fv(u_normal,1,GL_FALSE,glm::value_ptr(NormalMatrix_2));
//             glUniformMatrix4fv(u_mv,1,GL_FALSE,glm::value_ptr(MVMatrix_2));
//             /*Code de rendu ici*/


//             glDrawArrays(GL_TRIANGLES, 0, sphere.getVertexCount());

//         }

            

        


        
        
        
        
//         //glDrawArrays(GL_TRIANGLES, 0, sphere.getVertexCount());


//         //glDrawArrays(GL_TRIANGLES, 0, sphere.getVertexCount());

        
        
        
//         glBindVertexArray(0);

//         /* Swap front and back buffers (envoyer le buffer sur l'écran)*/
//         glfwSwapBuffers(window);
//         /* Poll for and process events */
//         glfwPollEvents();
//     }

//     glfwTerminate();
//     glDeleteBuffers(1, &vbo);
//     glDeleteVertexArrays(1, &vao);
//     return 0;
// }

// // textures
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

// int main([[maybe_unused]] int argc, char* argv[])
// {

//     auto t_start = std::chrono::high_resolution_clock::now();
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
//     GLFWwindow* window = glfwCreateWindow(window_width, window_height, "TP1", nullptr, nullptr);
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

//     /*Here should come the initialization code, trucs avant la boucle while (création des meshs...)*/

//     std::unique_ptr<glimac::Image> Earth = glimac::loadImage("/Users/keziahapaloo-kingslove/Documents/IMAC/Semestre_4/OpenGL_TP/GLImac-Template/assets/textures/EarthMap.jpg");
//     std::unique_ptr<glimac::Image> Moon = glimac::loadImage("/Users/keziahapaloo-kingslove/Documents/IMAC/Semestre_4/OpenGL_TP/GLImac-Template/assets/textures/MoonMap.jpg");
    
//     GLuint txt;
//     glGenTextures(1,&txt);

//     glBindTexture(GL_TEXTURE_2D,txt);

    
//     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

//     glBindTexture(GL_TEXTURE_2D,0);

    
    
//     glimac::Sphere sphere(1, 32, 16);



//     glimac::FilePath applicationPath(argv[0]);
//     glimac::Program  program = glimac::loadProgram(applicationPath.dirPath() + "TP3/shaders/3D.vs.glsl", applicationPath.dirPath() + "TP3/shaders/tex3D.fs.glsl");
//     program.use();

//     // Récupération des locations
//     GLuint u_mvp    = glGetUniformLocation(program.getGLId(), "uMVPMatrix");
//     GLuint u_mv     = glGetUniformLocation(program.getGLId(), "uMVMatrix");
//     GLuint u_normal = glGetUniformLocation(program.getGLId(), "uNormalMatrix");
//     GLuint u_txt = glGetUniformLocation(program.getGLId(),"uTexture");

//     glEnable(GL_DEPTH_TEST);

//     // Création d'un VBO
//     GLuint vbo;
//     glGenBuffers(1, &vbo);
//     // À partir de ce point la variable vbo contient l'identifiant d'un vbo
//     // 1 est le nombre de vbo à créer
//     // vbo est un pointeur vers un tableau d'entiers remplis par les identifiants des VBOs crées.

//     // Binding d'un VBO sur la cible GL_ARRAY_BUFFER:
//     glBindBuffer(GL_ARRAY_BUFFER, vbo);
//     // 1er paramètre : nom de la cible, sous la forme d'une constante OPENGL
//     // 2e parametre : le buffer à binder
//     //  On peut à présent modifier le VBO en passant par la cible GL_ARRAY_BUFFER

//     glBufferData(GL_ARRAY_BUFFER, sphere.getVertexCount() * sizeof(glimac::ShapeVertex), sphere.getDataPointer(), GL_STATIC_DRAW);
//     // 1e argument : la cible sur laquelle le buffer est bindé (GL_ARRAY_BUFFER dans notre cas)
//     // 2e argument : le pointeur vers les données (notre tableau de flottants)
//     // 3e argument : un flag indiquant à OpenGL quel usage on va faire du buffer. On utilise GL_STATIC_DRAW pour un buffer dont les données ne changeront jamais.
//     // On debind le vbo
//     glBindBuffer(GL_ARRAY_BUFFER, 0);

//     // Création d'un VAO
//     GLuint vao;
//     glGenVertexArrays(1, &vao);

//     // on bind le vao
//     glBindVertexArray(vao);

//     // Utilisation d'un attribut
//     const GLuint VERTEX_ATTR_POSITION = 0;
//     const GLuint VERTEX_ATTR_NORM     = 1;
//     const GLuint VERTEX_ATTR_COORD    = 2;
//     glEnableVertexAttribArray(VERTEX_ATTR_POSITION);
//     glEnableVertexAttribArray(VERTEX_ATTR_NORM);
//     glEnableVertexAttribArray(VERTEX_ATTR_COORD);
//     // Le 0 correspond a l'attribut du sommet identifiant la position
//     // 1e argument : l'index de l'attribut à activer

//     // On bind le VBO
//     glBindBuffer(GL_ARRAY_BUFFER, vbo);

//     // indication à OpenGL où il va trouver les sommets à dessiner, et comment lire les informations associé à chaque sommet.
//     glVertexAttribPointer(VERTEX_ATTR_POSITION, 3, GL_FLOAT, GL_FALSE, sizeof(glimac::ShapeVertex), (const GLvoid*)(offsetof(glimac::ShapeVertex, position)));
//     glVertexAttribPointer(VERTEX_ATTR_NORM, 3, GL_FLOAT, GL_FALSE, sizeof(glimac::ShapeVertex), (const GLvoid*)(offsetof(glimac::ShapeVertex, normal)));
//     glVertexAttribPointer(VERTEX_ATTR_COORD, 2, GL_FLOAT, GL_FALSE, sizeof(glimac::ShapeVertex), (const GLvoid*)(offsetof(glimac::ShapeVertex, texCoords)));
//     // On débind le vbo
//     glBindBuffer(GL_ARRAY_BUFFER, 0);

//     // On débind le vao
//     glBindVertexArray(0);

//     std::vector<glm::vec3> angle;
//     std::vector<glm::vec3> trans;
//     for (int i = 1; i < 33; ++i)
//     { 
//         angle.push_back(glm::sphericalRand(1.0f));
//         trans.push_back(glm::sphericalRand(2.0f));
//     }




//     /* Loop until the user closes the window */
//     while (!glfwWindowShouldClose(window)) {
//         glClearColor(0.3f, 0.5f, 0.7f, 1.f);
//         glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT); // Le code de dessin est répété à chaque tour de la boucle d'application. Il faut donc d'abord nettoyer la fenêtre afin de ne pas avoir de résidu du tour précédent.


//         auto t_now = std::chrono::high_resolution_clock::now();
//         float time = std::chrono::duration_cast<std::chrono::duration<float>>(t_now - t_start).count();

//         glBindVertexArray(vao);
//         glBindTexture(GL_TEXTURE_2D,txt);
//         glUniform1i(u_txt,0);

//         glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA, Earth->getWidth(),Earth->getHeight(),0,GL_RGBA,GL_FLOAT,Earth->getPixels());
//         glm::mat4 ProjMatrix = glm::perspective(glm::radians(70.f), (window_width / (float)window_height), 0.1f, 100.f);

//         glm::mat4 MVMatrix = glm::translate(glm::mat4(1.0), glm::vec3(0, 0, -5));

//         glm::mat4 NormalMatrix = glm::transpose(glm::inverse(MVMatrix));

//         MVMatrix = glm::rotate(MVMatrix, time, glm::vec3(0, 1, 0));

//         glUniformMatrix4fv(u_mvp,1,GL_FALSE,glm::value_ptr(ProjMatrix * MVMatrix));
//         glUniformMatrix4fv(u_normal,1,GL_FALSE,glm::value_ptr(NormalMatrix));
//         glUniformMatrix4fv(u_mv,1,GL_FALSE,glm::value_ptr(MVMatrix));

//         glDrawArrays(GL_TRIANGLES, 0, sphere.getVertexCount());

//         glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA, Moon->getWidth(),Moon->getHeight(),0,GL_RGBA,GL_FLOAT,Moon->getPixels());
        
        
//         for (int i =0; i<33; i++){

//             glm::mat4 MVMatrix_2 = glm::translate(glm::mat4(1.0), glm::vec3(0, 0, -5));
//             glm::mat4 NormalMatrix_2 = glm::transpose(glm::inverse(MVMatrix_2));

//             MVMatrix_2=glm::rotate(MVMatrix_2, time, glm::vec3(angle[i].x,0,angle[i].z));
//             MVMatrix_2 = glm::translate(MVMatrix_2, glm::vec3(trans[i])); // Translation * Rotation * Translation
//             MVMatrix_2 = glm::scale(MVMatrix_2, glm::vec3(0.2, 0.2, 0.2)); // Translation * Rotation * Translation * Scale  


//             glUniformMatrix4fv(u_mvp,1,GL_FALSE,glm::value_ptr(ProjMatrix * MVMatrix_2));
//             glUniformMatrix4fv(u_normal,1,GL_FALSE,glm::value_ptr(NormalMatrix_2));
//             glUniformMatrix4fv(u_mv,1,GL_FALSE,glm::value_ptr(MVMatrix_2));
//             /*Code de rendu ici*/


//             glDrawArrays(GL_TRIANGLES, 0, sphere.getVertexCount());

//         }

            
        
        


        
        
        
        
//         //glDrawArrays(GL_TRIANGLES, 0, sphere.getVertexCount());


//         //glDrawArrays(GL_TRIANGLES, 0, sphere.getVertexCount());

        
        
        
//         glBindVertexArray(0);

//         /* Swap front and back buffers (envoyer le buffer sur l'écran)*/
//         glfwSwapBuffers(window);
//         /* Poll for and process events */
//         glfwPollEvents();
//     }

//     glfwTerminate();
//     glDeleteBuffers(1, &vbo);
//     glDeleteVertexArrays(1, &vao);
//     return 0;
// }

// // multi texturing
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

// int main([[maybe_unused]] int argc, char* argv[])
// {

//     auto t_start = std::chrono::high_resolution_clock::now();
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
//     GLFWwindow* window = glfwCreateWindow(window_width, window_height, "TP1", nullptr, nullptr);
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

//     /*Here should come the initialization code, trucs avant la boucle while (création des meshs...)*/

//     std::unique_ptr<glimac::Image> Earth = glimac::loadImage("/Users/keziahapaloo-kingslove/Documents/IMAC/Semestre_4/OpenGL_TP/GLImac-Template/assets/textures/EarthMap.jpg");
//     std::unique_ptr<glimac::Image> Moon = glimac::loadImage("/Users/keziahapaloo-kingslove/Documents/IMAC/Semestre_4/OpenGL_TP/GLImac-Template/assets/textures/MoonMap.jpg");
//     std::unique_ptr<glimac::Image> Cloud = glimac::loadImage("/Users/keziahapaloo-kingslove/Documents/IMAC/Semestre_4/OpenGL_TP/GLImac-Template/assets/textures/CloudMap.jpg");

//     GLuint cloud_txt;
//     GLuint earth_txt;
//     GLuint moon_txt;
//     glGenTextures(1,&earth_txt);    
//     glActiveTexture(GL_TEXTURE0);
//     glBindTexture(GL_TEXTURE_2D, earth_txt);
//     glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA, Earth->getWidth(),Earth->getHeight(),0,GL_RGBA,GL_FLOAT,Earth->getPixels());
//     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);    
//     glActiveTexture(GL_TEXTURE0);
//     glBindTexture(GL_TEXTURE_2D,0);
    
//     glGenTextures(1,&cloud_txt);
//     glActiveTexture(GL_TEXTURE1);
//     glBindTexture(GL_TEXTURE_2D, cloud_txt); // la texture cloudTexture est bindée sur l'unité GL_TEXTURE1
//     glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA, Cloud->getWidth(),Cloud->getHeight(),0,GL_RGBA,GL_FLOAT,Cloud->getPixels());
//     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//     glActiveTexture(GL_TEXTURE1);
//     glBindTexture(GL_TEXTURE_2D,0);

//     glGenTextures(1,&moon_txt);
//     glActiveTexture(GL_TEXTURE0);
//     glBindTexture(GL_TEXTURE_2D, moon_txt); // la texture cloudTexture est bindée sur l'unité GL_TEXTURE0
//     glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA, Moon->getWidth(),Moon->getHeight(),0,GL_RGBA,GL_FLOAT,Moon->getPixels());
//     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//     glActiveTexture(GL_TEXTURE0);
//     glBindTexture(GL_TEXTURE_2D,0);

//  // la texture earthTexture est bindée sur l'unité GL_TEXTURE0

//      //glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA, Earth->getWidth(),Earth->getHeight(),0,GL_RGBA,GL_FLOAT,Earth->getPixels());
//         //glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA, Cloud->getWidth(),Earth->getHeight(),0,GL_RGBA,GL_FLOAT,Cloud->getPixels());
        
//     //glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA, Cloud->getWidth(),Earth->getHeight(),0,GL_RGBA,GL_FLOAT,Cloud->getPixels());
    





    
    
//     glimac::Sphere sphere(1, 32, 16);



//     glimac::FilePath applicationPath(argv[0]);
//     glimac::Program  program = glimac::loadProgram(applicationPath.dirPath() + "TP3/shaders/3D.vs.glsl", applicationPath.dirPath() + "TP3/shaders/multiTex3D.fs.glsl");
//     program.use();

//     // Récupération des locations
//     GLuint u_mvp    = glGetUniformLocation(program.getGLId(), "uMVPMatrix");
//     GLuint u_mv     = glGetUniformLocation(program.getGLId(), "uMVMatrix");
//     GLuint u_normal = glGetUniformLocation(program.getGLId(), "uNormalMatrix");
//     GLuint u_txt = glGetUniformLocation(program.getGLId(),"uTexture1");
//     GLuint u_cloud_txt = glGetUniformLocation(program.getGLId(),"uTexture2");



//     glEnable(GL_DEPTH_TEST);

//     // Création d'un VBO
//     GLuint vbo;
//     glGenBuffers(1, &vbo);
//     // À partir de ce point la variable vbo contient l'identifiant d'un vbo
//     // 1 est le nombre de vbo à créer
//     // vbo est un pointeur vers un tableau d'entiers remplis par les identifiants des VBOs crées.

//     // Binding d'un VBO sur la cible GL_ARRAY_BUFFER:
//     glBindBuffer(GL_ARRAY_BUFFER, vbo);
//     // 1er paramètre : nom de la cible, sous la forme d'une constante OPENGL
//     // 2e parametre : le buffer à binder
//     //  On peut à présent modifier le VBO en passant par la cible GL_ARRAY_BUFFER

//     glBufferData(GL_ARRAY_BUFFER, sphere.getVertexCount() * sizeof(glimac::ShapeVertex), sphere.getDataPointer(), GL_STATIC_DRAW);
//     // 1e argument : la cible sur laquelle le buffer est bindé (GL_ARRAY_BUFFER dans notre cas)
//     // 2e argument : le pointeur vers les données (notre tableau de flottants)
//     // 3e argument : un flag indiquant à OpenGL quel usage on va faire du buffer. On utilise GL_STATIC_DRAW pour un buffer dont les données ne changeront jamais.
//     // On debind le vbo
//     glBindBuffer(GL_ARRAY_BUFFER, 0);

//     // Création d'un VAO
//     GLuint vao;
//     glGenVertexArrays(1, &vao);

//     // on bind le vao
//     glBindVertexArray(vao);

//     // Utilisation d'un attribut
//     const GLuint VERTEX_ATTR_POSITION = 0;
//     const GLuint VERTEX_ATTR_NORM     = 1;
//     const GLuint VERTEX_ATTR_COORD    = 2;
//     glEnableVertexAttribArray(VERTEX_ATTR_POSITION);
//     glEnableVertexAttribArray(VERTEX_ATTR_NORM);
//     glEnableVertexAttribArray(VERTEX_ATTR_COORD);
//     // Le 0 correspond a l'attribut du sommet identifiant la position
//     // 1e argument : l'index de l'attribut à activer

//     // On bind le VBO
//     glBindBuffer(GL_ARRAY_BUFFER, vbo);

//     // indication à OpenGL où il va trouver les sommets à dessiner, et comment lire les informations associé à chaque sommet.
//     glVertexAttribPointer(VERTEX_ATTR_POSITION, 3, GL_FLOAT, GL_FALSE, sizeof(glimac::ShapeVertex), (const GLvoid*)(offsetof(glimac::ShapeVertex, position)));
//     glVertexAttribPointer(VERTEX_ATTR_NORM, 3, GL_FLOAT, GL_FALSE, sizeof(glimac::ShapeVertex), (const GLvoid*)(offsetof(glimac::ShapeVertex, normal)));
//     glVertexAttribPointer(VERTEX_ATTR_COORD, 2, GL_FLOAT, GL_FALSE, sizeof(glimac::ShapeVertex), (const GLvoid*)(offsetof(glimac::ShapeVertex, texCoords)));
//     // On débind le vbo
//     glBindBuffer(GL_ARRAY_BUFFER, 0);

//     // On débind le vao
//     glBindVertexArray(0);

//     std::vector<glm::vec3> angle;
//     std::vector<glm::vec3> trans;
//     for (int i = 1; i < 33; ++i)
//     { 
//         angle.push_back(glm::sphericalRand(1.0f));
//         trans.push_back(glm::sphericalRand(2.0f));
//     }




//     /* Loop until the user closes the window */
//     while (!glfwWindowShouldClose(window)) {
//         glClearColor(0.3f, 0.5f, 0.7f, 1.f);
//         glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT); // Le code de dessin est répété à chaque tour de la boucle d'application. Il faut donc d'abord nettoyer la fenêtre afin de ne pas avoir de résidu du tour précédent.


//         auto t_now = std::chrono::high_resolution_clock::now();
//         float time = std::chrono::duration_cast<std::chrono::duration<float>>(t_now - t_start).count();

//         glUniform1i(u_txt,0);
//         glUniform1i(u_cloud_txt, 1);
//         glBindVertexArray(vao);

//         glm::mat4 ProjMatrix = glm::perspective(glm::radians(70.f), (window_width / (float)window_height), 0.1f, 100.f);

//         glm::mat4 MVMatrix = glm::translate(glm::mat4(1.0), glm::vec3(0, 0, -5));

//         glm::mat4 NormalMatrix = glm::transpose(glm::inverse(MVMatrix));

//         MVMatrix = glm::rotate(MVMatrix, time, glm::vec3(0, 1, 0));

//         glUniformMatrix4fv(u_mvp,1,GL_FALSE,glm::value_ptr(ProjMatrix * MVMatrix));
//         glUniformMatrix4fv(u_normal,1,GL_FALSE,glm::value_ptr(NormalMatrix));
//         glUniformMatrix4fv(u_mv,1,GL_FALSE,glm::value_ptr(MVMatrix));

        
//         glActiveTexture(GL_TEXTURE0);
//         glBindTexture(GL_TEXTURE_2D, earth_txt); // la texture earthTexture est bindée sur l'unité GL_TEXTURE0
//         glActiveTexture(GL_TEXTURE1);
//         glBindTexture(GL_TEXTURE_2D, cloud_txt); // la texture cloudTexture est bindée sur l'unité GL_TEXTURE1

//         glDrawArrays(GL_TRIANGLES, 0, sphere.getVertexCount());

//         glActiveTexture(GL_TEXTURE1);
//         glBindTexture(GL_TEXTURE_2D,0);

//         glActiveTexture(GL_TEXTURE0);
//         glBindTexture(GL_TEXTURE_2D, moon_txt);

        
//         for (int i =0; i<33; i++){

//             glm::mat4 MVMatrix_2 = glm::translate(glm::mat4(1.0), glm::vec3(0, 0, -5));
//             glm::mat4 NormalMatrix_2 = glm::transpose(glm::inverse(MVMatrix_2));

//             MVMatrix_2=glm::rotate(MVMatrix_2, time, glm::vec3(angle[i].x,0,angle[i].z));
//             MVMatrix_2 = glm::translate(MVMatrix_2, glm::vec3(trans[i])); // Translation * Rotation * Translation
//             MVMatrix_2 = glm::scale(MVMatrix_2, glm::vec3(0.2, 0.2, 0.2)); // Translation * Rotation * Translation * Scale  


//             glUniformMatrix4fv(u_mvp,1,GL_FALSE,glm::value_ptr(ProjMatrix * MVMatrix_2));
//             glUniformMatrix4fv(u_normal,1,GL_FALSE,glm::value_ptr(NormalMatrix_2));
//             glUniformMatrix4fv(u_mv,1,GL_FALSE,glm::value_ptr(MVMatrix_2));
//             /*Code de rendu ici*/


//             glDrawArrays(GL_TRIANGLES, 0, sphere.getVertexCount());

//         }

            
        
        


        
        
        
        
//         //glDrawArrays(GL_TRIANGLES, 0, sphere.getVertexCount());


//         //glDrawArrays(GL_TRIANGLES, 0, sphere.getVertexCount());

        
        
        
//         glBindVertexArray(0);
//         glActiveTexture(GL_TEXTURE0);
//         glBindTexture(GL_TEXTURE_2D,0);



//         /* Swap front and back buffers (envoyer le buffer sur l'écran)*/
//         glfwSwapBuffers(window);
//         /* Poll for and process events */
//         glfwPollEvents();
//     }

//     glfwTerminate();
//     glDeleteBuffers(1, &vbo);
//     glDeleteVertexArrays(1, &vao);
//     return 0;
// }


// multi texturing
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

struct EarthProgram {
    glimac::Program m_Program;

    GLint u_mvp;
    GLint u_mv;
    GLint u_normal;
    GLint u_earth;
    GLint u_cloud_txt;

    EarthProgram(const glimac::FilePath& applicationPath):
        m_Program(loadProgram(applicationPath.dirPath() + "TP3/shaders/3D.vs.glsl",
                              applicationPath.dirPath() + "TP3/shaders/multiTex3D.fs.glsl")) {
        u_mvp = glGetUniformLocation(m_Program.getGLId(), "uMVPMatrix");
        u_mv = glGetUniformLocation(m_Program.getGLId(), "uMVMatrix");
        u_normal = glGetUniformLocation(m_Program.getGLId(), "uNormalMatrix");
        u_earth = glGetUniformLocation(m_Program.getGLId(), "uEarthTexture");
        u_cloud_txt = glGetUniformLocation(m_Program.getGLId(), "uCloudTexture");
    }
};

struct MoonProgram {
    glimac::Program m_Program;

    GLint u_mvp;
    GLint u_mv;
    GLint u_normal;
    GLint u_moon;

    MoonProgram(const glimac::FilePath& applicationPath):
        m_Program(loadProgram(applicationPath.dirPath() + "TP3/shaders/3D.vs.glsl",
                              applicationPath.dirPath() + "TP3/shaders/multiTex3D.fs.glsl")) {
        u_mvp = glGetUniformLocation(m_Program.getGLId(), "uMVPMatrix");
        u_mv = glGetUniformLocation(m_Program.getGLId(), "uMVMatrix");
        u_normal = glGetUniformLocation(m_Program.getGLId(), "uNormalMatrix");
        u_moon = glGetUniformLocation(m_Program.getGLId(), "uMoonTexture");
    }
};

int main([[maybe_unused]] int argc, char* argv[])
{

    auto t_start = std::chrono::high_resolution_clock::now();
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

    std::unique_ptr<glimac::Image> Earth = glimac::loadImage("/Users/keziahapaloo-kingslove/Documents/IMAC/Semestre_4/OpenGL_TP/GLImac-Template/assets/textures/EarthMap.jpg");
    std::unique_ptr<glimac::Image> Moon = glimac::loadImage("/Users/keziahapaloo-kingslove/Documents/IMAC/Semestre_4/OpenGL_TP/GLImac-Template/assets/textures/MoonMap.jpg");
    std::unique_ptr<glimac::Image> Cloud = glimac::loadImage("/Users/keziahapaloo-kingslove/Documents/IMAC/Semestre_4/OpenGL_TP/GLImac-Template/assets/textures/CloudMap.jpg");

    GLuint cloud_txt;
    GLuint earth_txt;
    GLuint moon_txt;
    glGenTextures(1,&earth_txt);    
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, earth_txt);
    glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA, Earth->getWidth(),Earth->getHeight(),0,GL_RGBA,GL_FLOAT,Earth->getPixels());
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);    
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D,0);
    
    glGenTextures(1,&cloud_txt);
    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D, cloud_txt); // la texture cloudTexture est bindée sur l'unité GL_TEXTURE1
    glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA, Cloud->getWidth(),Cloud->getHeight(),0,GL_RGBA,GL_FLOAT,Cloud->getPixels());
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D,0);

    glGenTextures(1,&moon_txt);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, moon_txt); // la texture cloudTexture est bindée sur l'unité GL_TEXTURE0
    glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA, Moon->getWidth(),Moon->getHeight(),0,GL_RGBA,GL_FLOAT,Moon->getPixels());
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D,0);

 // la texture earthTexture est bindée sur l'unité GL_TEXTURE0

     //glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA, Earth->getWidth(),Earth->getHeight(),0,GL_RGBA,GL_FLOAT,Earth->getPixels());
        //glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA, Cloud->getWidth(),Earth->getHeight(),0,GL_RGBA,GL_FLOAT,Cloud->getPixels());
        
    //glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA, Cloud->getWidth(),Earth->getHeight(),0,GL_RGBA,GL_FLOAT,Cloud->getPixels());
    





    
    
    glimac::Sphere sphere(1, 32, 16);

    glimac::FilePath applicationPath(argv[0]);
    EarthProgram earthProgram(applicationPath);
    MoonProgram moonProgram(applicationPath);

    // glimac::FilePath applicationPath(argv[0]);
    // glimac::Program  program = glimac::loadProgram(applicationPath.dirPath() + "TP3/shaders/3D.vs.glsl", applicationPath.dirPath() + "TP3/shaders/multiTex3D.fs.glsl");
    // program.use();

    // Récupération des locations
    // GLuint u_mvp    = glGetUniformLocation(program.getGLId(), "uMVPMatrix");
    // GLuint u_mv     = glGetUniformLocation(program.getGLId(), "uMVMatrix");
    // GLuint u_normal = glGetUniformLocation(program.getGLId(), "uNormalMatrix");
    // GLuint u_earth = glGetUniformLocation(program.getGLId(),"uTexture1");
    // GLuint u_cloud_txt = glGetUniformLocation(program.getGLId(),"uTexture2");



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
    const GLuint VERTEX_ATTR_POSITION = 0;
    const GLuint VERTEX_ATTR_NORM     = 1;
    const GLuint VERTEX_ATTR_COORD    = 2;
    glEnableVertexAttribArray(VERTEX_ATTR_POSITION);
    glEnableVertexAttribArray(VERTEX_ATTR_NORM);
    glEnableVertexAttribArray(VERTEX_ATTR_COORD);
    // Le 0 correspond a l'attribut du sommet identifiant la position
    // 1e argument : l'index de l'attribut à activer

    // On bind le VBO
    glBindBuffer(GL_ARRAY_BUFFER, vbo);

    // indication à OpenGL où il va trouver les sommets à dessiner, et comment lire les informations associé à chaque sommet.
    glVertexAttribPointer(VERTEX_ATTR_POSITION, 3, GL_FLOAT, GL_FALSE, sizeof(glimac::ShapeVertex), (const GLvoid*)(offsetof(glimac::ShapeVertex, position)));
    glVertexAttribPointer(VERTEX_ATTR_NORM, 3, GL_FLOAT, GL_FALSE, sizeof(glimac::ShapeVertex), (const GLvoid*)(offsetof(glimac::ShapeVertex, normal)));
    glVertexAttribPointer(VERTEX_ATTR_COORD, 2, GL_FLOAT, GL_FALSE, sizeof(glimac::ShapeVertex), (const GLvoid*)(offsetof(glimac::ShapeVertex, texCoords)));
    // On débind le vbo
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    // On débind le vao
    glBindVertexArray(0);

    std::vector<glm::vec3> angle;
    std::vector<glm::vec3> trans;
    for (int i = 1; i < 33; ++i)
    { 
        angle.push_back(glm::sphericalRand(1.0f));
        trans.push_back(glm::sphericalRand(2.0f));
    }




    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window)) {
        glClearColor(0.3f, 0.5f, 0.7f, 1.f);
        glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT); // Le code de dessin est répété à chaque tour de la boucle d'application. Il faut donc d'abord nettoyer la fenêtre afin de ne pas avoir de résidu du tour précédent.


        auto t_now = std::chrono::high_resolution_clock::now();
        float time = std::chrono::duration_cast<std::chrono::duration<float>>(t_now - t_start).count();

        // glUniform1i(u_earth,0);
        // glUniform1i(u_cloud_txt, 1);
        glBindVertexArray(vao);
        glm::mat4 ProjMatrix = glm::perspective(glm::radians(70.f), (window_width / (float)window_height), 0.1f, 100.f);


        // glm::mat4 ProjMatrix = glm::perspective(glm::radians(70.f), (window_width / (float)window_height), 0.1f, 100.f);

        // glm::mat4 MVMatrix = glm::translate(glm::mat4(1.0), glm::vec3(0, 0, -5));

        // glm::mat4 NormalMatrix = glm::transpose(glm::inverse(MVMatrix));

        // MVMatrix = glm::rotate(MVMatrix, time, glm::vec3(0, 1, 0));

        // glUniformMatrix4fv(u_mvp,1,GL_FALSE,glm::value_ptr(ProjMatrix * MVMatrix));
        // glUniformMatrix4fv(u_normal,1,GL_FALSE,glm::value_ptr(NormalMatrix));
        // glUniformMatrix4fv(u_mv,1,GL_FALSE,glm::value_ptr(MVMatrix));

        
        // glActiveTexture(GL_TEXTURE0);
        // glBindTexture(GL_TEXTURE_2D, earth_txt); // la texture earthTexture est bindée sur l'unité GL_TEXTURE0
        // glActiveTexture(GL_TEXTURE1);
        // glBindTexture(GL_TEXTURE_2D, cloud_txt); // la texture cloudTexture est bindée sur l'unité GL_TEXTURE1

        // glDrawArrays(GL_TRIANGLES, 0, sphere.getVertexCount());

        earthProgram.m_Program.use();
        moonProgram.m_Program.use();

        glUniform1i(earthProgram.u_earth, 0);
        glUniform1i(moonProgram.u_moon, 0);
        glUniform1i(earthProgram.u_cloud_txt, 1);

        glm::mat4 globalMVMatrix = glm::translate(glm::mat4(1.f), glm::vec3(0, 0, -5));

        glm::mat4 earthMVMatrix = glm::rotate(globalMVMatrix, time, glm::vec3(0, 1, 0));
        glUniformMatrix4fv(earthProgram.u_mv, 1, GL_FALSE, glm::value_ptr(earthMVMatrix));
        glUniformMatrix4fv(earthProgram.u_normal, 1, GL_FALSE, glm::value_ptr(glm::transpose(glm::inverse(earthMVMatrix))));
        glUniformMatrix4fv(earthProgram.u_mvp, 1, GL_FALSE, glm::value_ptr(ProjMatrix * earthMVMatrix));

        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, earth_txt);
        glActiveTexture(GL_TEXTURE1);
        glBindTexture(GL_TEXTURE_2D, cloud_txt);

        glDrawArrays(GL_TRIANGLES, 0, sphere.getVertexCount());

        glActiveTexture(GL_TEXTURE1);
        glBindTexture(GL_TEXTURE_2D,0);

        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, moon_txt);

        
        for (int i =0; i<33; i++){

            glm::mat4 moonMVMatrix = glm::translate(glm::mat4(1.0), glm::vec3(0, 0, -5));
            //glm::mat4 NormalMatrix_2 = glm::transpose(glm::inverse(moonMVMatrix));

            moonMVMatrix=glm::rotate(moonMVMatrix, time, glm::vec3(angle[i].x,0,angle[i].z));
            moonMVMatrix = glm::translate(moonMVMatrix, glm::vec3(trans[i])); // Translation * Rotation * Translation
            moonMVMatrix = glm::scale(moonMVMatrix, glm::vec3(0.2, 0.2, 0.2)); // Translation * Rotation * Translation * Scale  


            // glUniformMatrix4fv(u_mvp,1,GL_FALSE,glm::value_ptr(ProjMatrix * moonMVMatrix));
            // glUniformMatrix4fv(u_normal,1,GL_FALSE,glm::value_ptr(NormalMatrix_2));
            // glUniformMatrix4fv(u_mv,1,GL_FALSE,glm::value_ptr(moonMVMatrix));
            /*Code de rendu ici*/
            glUniformMatrix4fv(earthProgram.u_mv, 1, GL_FALSE, glm::value_ptr(moonMVMatrix));
            glUniformMatrix4fv(moonProgram.u_normal, 1, GL_FALSE, glm::value_ptr(glm::transpose(glm::inverse(moonMVMatrix))));
            glUniformMatrix4fv(moonProgram.u_mvp, 1, GL_FALSE, glm::value_ptr(ProjMatrix * moonMVMatrix));

            glDrawArrays(GL_TRIANGLES, 0, sphere.getVertexCount());

        }

            
        
        


        
        
        
        
        //glDrawArrays(GL_TRIANGLES, 0, sphere.getVertexCount());


        //glDrawArrays(GL_TRIANGLES, 0, sphere.getVertexCount());

        
        
        
        glBindVertexArray(0);
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D,0);



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
