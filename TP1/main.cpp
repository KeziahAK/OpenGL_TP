#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/glad.h>

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

int main()
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
    GLfloat vertices[] = {-0.5f, -0.5f, 0.5f, -0.5f, 0.0f, 0.5f };
    //envoie des données
    glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat), vertices, GL_STATIC_DRAW);
    //1e argument : la cible sur laquelle le buffer est bindé (GL_ARRAY_BUFFER dans notre cas)
    //2e argument : le pointeur vers les données (notre tableau de flottants)
    //3e argument : un flag indiquant à OpenGL quel usage on va faire du buffer. On utilise GL_STATIC_DRAW pour un buffer dont les données ne changeront jamais.
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    //Création d'un VAO
    GLuint vao;
    glGenVertexArrays(1, &vao);

    //on bind le vao
    glBindVertexArray(vao);

    //Utilisation d'un attribut
    const GLuint VERTEX_ATTR_POSITION = 0;
    glEnableVertexAttribArray(VERTEX_ATTR_POSITION);
    //Le 0 correspond a l'attribut du sommet identifiant la position
    //1e argument : l'index de l'attribut à activer

    //indication à OpenGL où il va trouver les sommets à dessiner, et comment lire les informations associé à chaque sommet.
    glVertexAttribPointer(0,2, GL_FLOAT, );


    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window)) {
        glClearColor(1.f, 0.5f, 0.5f, 1.f);
        glClear(GL_COLOR_BUFFER_BIT);

        /*Code de rendu ici*/

        /* Swap front and back buffers (envoyer le buffer sur l'écran)*/
        glfwSwapBuffers(window);
        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}