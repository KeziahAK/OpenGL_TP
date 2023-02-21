#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <glimac/Program.hpp>
#include <glimac/FilePath.hpp>
#include <glimac/glm.hpp> //Permet d'avoir des types de vecteurs, matrices et autres
#include <cstddef>
#include <vector>


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
//     GLFWwindow* window = glfwCreateWindow(window_width, window_height, "TP2", nullptr, nullptr);
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
//         glClearColor(0.5f, 0.5f, 1.f, 1.f);
//         glClear(GL_COLOR_BUFFER_BIT);

//         /* Swap front and back buffers */
//         glfwSwapBuffers(window);
//         /* Poll for and process events */
//         glfwPollEvents();
//     }

//     glfwTerminate();
//     return 0;
// }






// //Triangle couleur
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

// int main([[maybe_unused]]int argc, char* argv[])
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
    
//     glimac::FilePath applicationPath(argv[0]);
//     glimac::Program program = glimac::loadProgram(applicationPath.dirPath() + "TP2/shaders/color2D.vs.glsl", applicationPath.dirPath() + "TP2/shaders/color2D.fs.glsl");
//     program.use();

//     //Création d'un VBO
//     GLuint vbo;
//     glGenBuffers(1, &vbo);
//     //À partir de ce point la variable vbo contient l'identifiant d'un vbo
//     //1 est le nombre de vbo à créer
//     //vbo est un pointeur vers un tableau d'entiers remplis par les identifiants des VBOs crées.

//     // Binding d'un VBO sur la cible GL_ARRAY_BUFFER:
//     glBindBuffer(GL_ARRAY_BUFFER, vbo);
//     //1er paramètre : nom de la cible, sous la forme d'une constante OPENGL
//     //2e parametre : le buffer à binder
//     // On peut à présent modifier le VBO en passant par la cible GL_ARRAY_BUFFER

//     //Remplir le vbo
//     GLfloat vertices[] = { -0.5f, -0.5f, 1.f, 0.f, 0.f, // premier sommet
//     0.5f, -0.5f, 0.f, 1.f, 0.f, // deuxième sommet
//     0.0f, 0.5f, 0.f, 0.f, 1.f // troisième sommet
//     };//On ajoute la couleur à la fin des coordonnées de chaque sommet
//     //envoie des données
//     glBufferData(GL_ARRAY_BUFFER, 15*sizeof(GLfloat), vertices, GL_STATIC_DRAW);
//     //1e argument : la cible sur laquelle le buffer est bindé (GL_ARRAY_BUFFER dans notre cas)
//     //2e argument : le pointeur vers les données (notre tableau de flottants)
//     //3e argument : un flag indiquant à OpenGL quel usage on va faire du buffer. On utilise GL_STATIC_DRAW pour un buffer dont les données ne changeront jamais.
//     //On debind le vbo
//     glBindBuffer(GL_ARRAY_BUFFER, 0);

//     //Création d'un VAO
//     GLuint vao;
//     glGenVertexArrays(1, &vao);

//     //on bind le vao
//     glBindVertexArray(vao);

//     //Utilisation d'un attribut
//     const GLuint VERTEX_ATTR_POSITION = 0;
//     const GLuint VERTEX_ATTR_COLOR =1;
//     glEnableVertexAttribArray(VERTEX_ATTR_POSITION);
//     glEnableVertexAttribArray(VERTEX_ATTR_COLOR);
//     //Le 0 correspond a l'attribut du sommet identifiant la position
//     //1e argument : l'index de l'attribut à activer

//     //On bind le VBO
//     glBindBuffer(GL_ARRAY_BUFFER, vbo);


//     //indication à OpenGL où il va trouver les sommets à dessiner, et comment lire les informations associé à chaque sommet.
//     glVertexAttribPointer(VERTEX_ATTR_POSITION,2, GL_FLOAT,GL_FALSE, 5 * sizeof(GLfloat),0);
//     glVertexAttribPointer(VERTEX_ATTR_COLOR,3, GL_FLOAT,GL_FALSE, 5 * sizeof(GLfloat),(void*) (2 * sizeof(GLfloat)));

//     //On débind le vbo
//     glBindBuffer(GL_ARRAY_BUFFER, 0);

//     //On débind le vao
//     glBindVertexArray(0);


//     /* Loop until the user closes the window */
//     while (!glfwWindowShouldClose(window)) {
//         glClearColor(1.f, 0.6f, 0.2f, 1.f);
//         glClear(GL_COLOR_BUFFER_BIT);//Le code de dessin est répété à chaque tour de la boucle d'application. Il faut donc d'abord nettoyer la fenêtre afin de ne pas avoir de résidu du tour précédent.
        

//         /*Code de rendu ici*/
        

//         glBindVertexArray(vao);
//         glDrawArrays(GL_TRIANGLES,0,3);
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


// //Triangle couleur Noir et Blanc et halo de lumière
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

// int main([[maybe_unused]]int argc, char* argv[])
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
//     argv[1]=(char*) "TP2/shaders/color2D.vs.glsl";
//     argv[2]=(char*) "TP2/shaders/2D.fs.glsl";
//     glimac::FilePath applicationPath(argv[0]);
//     glimac::Program program = glimac::loadProgram(applicationPath.dirPath() + argv[1], applicationPath.dirPath() + argv[2]);
//     program.use();

//     //Création d'un VBO
//     GLuint vbo;
//     glGenBuffers(1, &vbo);
//     //À partir de ce point la variable vbo contient l'identifiant d'un vbo
//     //1 est le nombre de vbo à créer
//     //vbo est un pointeur vers un tableau d'entiers remplis par les identifiants des VBOs crées.

//     // Binding d'un VBO sur la cible GL_ARRAY_BUFFER:
//     glBindBuffer(GL_ARRAY_BUFFER, vbo);
//     //1er paramètre : nom de la cible, sous la forme d'une constante OPENGL
//     //2e parametre : le buffer à binder
//     // On peut à présent modifier le VBO en passant par la cible GL_ARRAY_BUFFER

//     //Remplir le vbo
//     GLfloat vertices[] = { -0.5f, -0.5f, 1.f, 0.f, 0.f, // premier sommet
//     0.5f, -0.5f, 0.f, 1.f, 0.f, // deuxième sommet
//     0.0f, 0.5f, 0.f, 0.f, 1.f // troisième sommet
//     };//On ajoute la couleur à la fin des coordonnées de chaque sommet
//     //envoie des données
//     glBufferData(GL_ARRAY_BUFFER, 15*sizeof(GLfloat), vertices, GL_STATIC_DRAW);
//     //1e argument : la cible sur laquelle le buffer est bindé (GL_ARRAY_BUFFER dans notre cas)
//     //2e argument : le pointeur vers les données (notre tableau de flottants)
//     //3e argument : un flag indiquant à OpenGL quel usage on va faire du buffer. On utilise GL_STATIC_DRAW pour un buffer dont les données ne changeront jamais.
//     //On debind le vbo
//     glBindBuffer(GL_ARRAY_BUFFER, 0);

//     //Création d'un VAO
//     GLuint vao;
//     glGenVertexArrays(1, &vao);

//     //on bind le vao
//     glBindVertexArray(vao);

//     //Utilisation d'un attribut
//     const GLuint VERTEX_ATTR_POSITION = 0;
//     const GLuint VERTEX_ATTR_COLOR =1;
//     glEnableVertexAttribArray(VERTEX_ATTR_POSITION);
//     glEnableVertexAttribArray(VERTEX_ATTR_COLOR);
//     //Le 0 correspond a l'attribut du sommet identifiant la position
//     //1e argument : l'index de l'attribut à activer

//     //On bind le VBO
//     glBindBuffer(GL_ARRAY_BUFFER, vbo);


//     //indication à OpenGL où il va trouver les sommets à dessiner, et comment lire les informations associé à chaque sommet.
//     glVertexAttribPointer(VERTEX_ATTR_POSITION,2, GL_FLOAT,GL_FALSE, 5 * sizeof(GLfloat),0);
//     glVertexAttribPointer(VERTEX_ATTR_COLOR,3, GL_FLOAT,GL_FALSE, 5 * sizeof(GLfloat),(void*) (2 * sizeof(GLfloat)));

//     //On débind le vbo
//     glBindBuffer(GL_ARRAY_BUFFER, 0);

//     //On débind le vao
//     glBindVertexArray(0);


//     /* Loop until the user closes the window */
//     while (!glfwWindowShouldClose(window)) {
//         glClearColor(0.f, 0.f, 0.f, 1.f);
//         glClear(GL_COLOR_BUFFER_BIT);//Le code de dessin est répété à chaque tour de la boucle d'application. Il faut donc d'abord nettoyer la fenêtre afin de ne pas avoir de résidu du tour précédent.
        

//         /*Code de rendu ici*/
        

//         glBindVertexArray(vao);
//         glDrawArrays(GL_TRIANGLES,0,3);
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


//Dessiner un quad

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

struct Vertex2DColor{
    glm::vec2 position;
    
    Vertex2DColor(){
        position=glm::vec2();
        
    }
    Vertex2DColor(glm::vec2 _position){
        
        position=_position; 
    }

};

// struct Vertex2DColor {
//     glm::vec2 position;
//     glm::vec3 color;
    
//     Vertex2DColor() : position(glm::vec2()), color(glm::vec3()) {}
//     Vertex2DColor(glm::vec2 _position, glm::vec3 _color) : position(_position), color(_color) {}
// };


int main([[maybe_unused]]int argc, char* argv[])
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
    
    glimac::FilePath applicationPath(argv[0]);
    glimac::Program program = glimac::loadProgram(applicationPath.dirPath() + "TP2/shaders/triangle.vs.glsl", applicationPath.dirPath() + "TP2/shaders/triangle.fs.glsl");
    program.use();

    //Création d'un VBO
    GLuint vbo;
    glGenBuffers(1, &vbo);
    //À partir de ce point la variable vbo contient l'identifiant d'un vbo
    //1 est le nombre de vbo à créer
    //vbo est un pointeur vers un tableau d'entiers remplis par les identifiants des VBOs crées.

    // Binding d'un VBO sur la cible GL_ARRAY_BUFFER:
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    //1er paramètre : nom de la cible, sous la forme d'une constante OPENGL
    //2e parametre : le buffer à binder
    // On peut à présent modifier le VBO en passant par la cible GL_ARRAY_BUFFER

    //Remplir le vbo
    // float vertices[] = { 
    //     -0.5, -0.5, 1, 0, 0,
    //     0.5, -0.5, 0, 1, 0,
    //     0, 0.5, 0, 0, 1
    // };

    Vertex2DColor vertices[] = { 
        Vertex2DColor(glm::vec2(-1, -1)),
        Vertex2DColor(glm::vec2(1, -1)),
        Vertex2DColor(glm::vec2(1, 1)),
        Vertex2DColor(glm::vec2(-1, -1)),
        Vertex2DColor(glm::vec2(1, 1)),
        Vertex2DColor(glm::vec2(-1, 1))
    };
    glBufferData(GL_ARRAY_BUFFER, 6*sizeof(Vertex2DColor), vertices, GL_STATIC_DRAW);
    //1e argument : la cible sur laquelle le buffer est bindé (GL_ARRAY_BUFFER dans notre cas)
    //2e argument : le pointeur vers les données (notre tableau de flottants)
    //3e argument : un flag indiquant à OpenGL quel usage on va faire du buffer. On utilise GL_STATIC_DRAW pour un buffer dont les données ne changeront jamais.
    //On debind le vbo
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    //Création d'un VAO
    GLuint vao;
    glGenVertexArrays(1, &vao);

    //on bind le vao
    glBindVertexArray(vao);

    //Utilisation d'un attribut
    const GLuint VERTEX_ATTR_POSITION = 3;
    const GLuint VERTEX_ATTR_COLOR =8;
    glEnableVertexAttribArray(VERTEX_ATTR_POSITION);
    glEnableVertexAttribArray(VERTEX_ATTR_COLOR);
    //Le 0 correspond a l'attribut du sommet identifiant la position
    //1e argument : l'index de l'attribut à activer

    //On bind le VBO
    glBindBuffer(GL_ARRAY_BUFFER, vbo);


    //indication à OpenGL où il va trouver les sommets à dessiner, et comment lire les informations associé à chaque sommet.
    glVertexAttribPointer(VERTEX_ATTR_POSITION,2, GL_FLOAT,GL_FALSE, sizeof(Vertex2DColor),(const GLvoid*)(offsetof(Vertex2DColor, position)));
    //glVertexAttribPointer(VERTEX_ATTR_COLOR,3, GL_FLOAT,GL_FALSE, sizeof(Vertex2DColor),(const GLvoid*) (offsetof(Vertex2DColor, color)));

    //On débind le vbo
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    //On débind le vao
    glBindVertexArray(0);


    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window)) {
        glClearColor(0.3f, 0.6f, 0.5f, 1.f);
        glClear(GL_COLOR_BUFFER_BIT);//Le code de dessin est répété à chaque tour de la boucle d'application. Il faut donc d'abord nettoyer la fenêtre afin de ne pas avoir de résidu du tour précédent.
        

        /*Code de rendu ici*/
        

        glBindVertexArray(vao);
        glDrawArrays(GL_TRIANGLES,0,6);
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
