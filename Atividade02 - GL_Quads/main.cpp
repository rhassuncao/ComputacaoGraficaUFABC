#include <GL/glew.h>
#include <GLFW/glfw3.h>

#define SCREEN_WIDTH 1024
#define SCREEN_HEIGHT 480

int main(void)
{
    GLFWwindow *window;

    if (!glfwInit( )){

        return -1;
    }

    window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "GL_QUADS", NULL, NULL);

    if (!window){

        glfwTerminate( );
        return -1;
    }

    // Make the window's context current
    glfwMakeContextCurrent(window);

    //OLD
    /*
    float vertices[] =
    {
        -0.5,  0.5, 0.0, // Canto superior esquerdo
         0.5,  0.5, 0.0, // Canto superior direito
         0.5, -0.5, 0.0, // canto inferior direito
        -0.5, -0.5, 0.0  // Canto Inferior Direito
    }; */

    //Para Garantir que será um quadrado em qualquer tela
    float vertices[] =
    {
        300, 300, 0.0, // top right corner
          0, 300, 0.0, // top left corner
          0,   0, 0.0, // bottom left corner
        300,   0, 0.0 // bottom right corner
    };

    //Convert do espaço normalizado para o espaço de pixels
    glViewport(0.0f, 0.0f, SCREEN_WIDTH, SCREEN_HEIGHT);
    //Define propriedades de camera
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //Define o sistema de coordanadas
    glOrtho(0, SCREEN_WIDTH, 0, SCREEN_HEIGHT, 0, 1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);

        glEnableClientState(GL_VERTEX_ARRAY);
        //Aposta para os vertices que serao utilizados
        glVertexPointer(3, GL_FLOAT, 0, vertices);
        //size - 3 coordenadas (X,y,z)
        //tipo - float
        //Gaps entre vertices
        //ponteiro para os vertices

        //Desenha os vertices
        glDrawArrays(GL_QUADS, 0, 4 );
        //Objeto a ser desenhado
        //vertice de inicio
        //numero de vertices
        glDisableClientState(GL_VERTEX_ARRAY);

        glfwSwapBuffers( window );
        glfwPollEvents( );
    }

    glfwTerminate( );
    return 0;
}
