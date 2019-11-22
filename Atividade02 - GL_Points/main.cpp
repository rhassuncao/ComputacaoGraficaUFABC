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

    window = glfwCreateWindow( SCREEN_WIDTH, SCREEN_HEIGHT, "GL Points", NULL, NULL );

    if ( !window )
    {
        glfwTerminate( );
        return -1;
    }

    glfwMakeContextCurrent( window );

    //Mesmo codigo dos quads
    glViewport( 0.0f, 0.0f, SCREEN_WIDTH, SCREEN_HEIGHT );
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity( );
    glOrtho( 0, SCREEN_WIDTH, 0, SCREEN_HEIGHT, 0, 1 );
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity( );

    //Posicionamento dos pontos
    GLfloat pointVertex[]  = { SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 };
    GLfloat pointVertex2[] = { SCREEN_WIDTH * 0.75, SCREEN_HEIGHT / 2 };

    while ( !glfwWindowShouldClose( window ) )
    {
        glClear( GL_COLOR_BUFFER_BIT );

        //Torna os pontos circularr
        glEnable( GL_POINT_SMOOTH );
        glEnableClientState( GL_VERTEX_ARRAY );
        //Configura o tamanho do ponto
        glPointSize( 50 );
        glVertexPointer( 2, GL_FLOAT, 0, pointVertex );
        //Especifica que serao desenhados pontos
        glDrawArrays( GL_POINTS, 0, 1 );
        glDisableClientState( GL_VERTEX_ARRAY );
        glDisable( GL_POINT_SMOOTH );

        //Como smooth esta desligado desenha um ponto quadrado
        glEnableClientState( GL_VERTEX_ARRAY );
        glVertexPointer( 2, GL_FLOAT, 0, pointVertex2 );
        glPointSize( 10 );
        glDrawArrays( GL_POINTS, 0, 1 );
        glDisableClientState( GL_VERTEX_ARRAY );

        glfwSwapBuffers( window );
        glfwPollEvents( );
    }

    glfwTerminate( );
    return 0;
}
