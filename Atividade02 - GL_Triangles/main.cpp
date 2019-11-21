#include <GL/glew.h>
#include <GLFW/glfw3.h>

int main( void )
{
    GLFWwindow *window;

    if ( !glfwInit( ) )
    {
        return -1;
    }

    window = glfwCreateWindow( 640, 480, "GL_Triangles", NULL, NULL );

    if ( !window )
    {
        glfwTerminate( );
        return -1;
    }

    glfwMakeContextCurrent( window );

    float vertices[] =
    {
           0,  0.5, 0.0, // CIMA
        -0.5, -0.5, 0.0, // BASE ESQUERDA
         0.5, -0.5, 0.0  // BASE DIREITA
    };

    while (!glfwWindowShouldClose(window))
    {
        glClear( GL_COLOR_BUFFER_BIT );

        glEnableClientState(GL_VERTEX_ARRAY);
        //Lista os vértices a serem desenhados de acordo com o array de vertices que foi criado
        glVertexPointer(3, GL_FLOAT, 0, vertices);
        //Desenha os vértices em forma de triangulos
        glDrawArrays(GL_TRIANGLES, 0, 3);
        glDisableClientState(GL_VERTEX_ARRAY);

        glfwSwapBuffers( window );
        glfwPollEvents( );
    }

    glfwTerminate( );
    return 0;
}
