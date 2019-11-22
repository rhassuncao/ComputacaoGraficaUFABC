#include <GL/glew.h>
#include <GLFW/glfw3.h>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

int main( void )
{
    GLFWwindow *window;

    if ( !glfwInit( ) )
    {
        return -1;
    }

    window = glfwCreateWindow( SCREEN_WIDTH, SCREEN_HEIGHT, "GL Lines", NULL, NULL );

    if ( !window )
    {
        glfwTerminate( );
        return -1;
    }

    glfwMakeContextCurrent( window );

    //Mesmo do exemplo dos quads
    glViewport( 0.0f, 0.0f, SCREEN_WIDTH, SCREEN_HEIGHT );
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity( );
    glOrtho( 0, SCREEN_WIDTH, 0, SCREEN_HEIGHT, 0, 1 );
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity( );

    //Pontos que irao compor a linha
    GLfloat lineVertices[] =
    {
        200, 100, 0,
        100, 300, 0
    };

    while ( !glfwWindowShouldClose( window ) )
    {
        glClear( GL_COLOR_BUFFER_BIT );

        //Deixa a linha mais suave
        glEnable( GL_LINE_SMOOTH );
        //Cria listras na linha
        glEnable( GL_LINE_STIPPLE );
        glPushAttrib( GL_LINE_BIT );
        //Altera a espessura da linha
        glLineWidth( 10 );
        //configura as listas
        //fator
        //padrao
        glLineStipple( 1, 0x00FF );
        glEnableClientState( GL_VERTEX_ARRAY );
        glVertexPointer( 3, GL_FLOAT, 0, lineVertices );
        glDrawArrays( GL_LINES, 0, 2 );
        glDisableClientState( GL_VERTEX_ARRAY );
        //remove o cascateamento de atributos
        glPopAttrib( );
        glDisable( GL_LINE_STIPPLE );
        glDisable( GL_LINE_SMOOTH );

        glfwSwapBuffers( window );
        glfwPollEvents( );
    }

    glfwTerminate( );
    return 0;
}
