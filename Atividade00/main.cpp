#define GLEW_STATIC
#define GLFW_INCLUDE_NONE

#include <GLFW/glfw3.h>
#include <iostream>
#include <GL/glew.h>
#include <string>

using namespace std;

//DRAW
float xc    = 0;
float yc    = 0;
float size  = 0.1;

//MOVE
float stepx = 0.0009;
float stepy = 0.0008;

//COLOR
float color     = 1;
float colorstep = 0.001;

void changeColor()
{
    if(color >= 1 || color <= 0)
        colorstep = colorstep * -1;

    color += colorstep;
}

void changeDirection()
{
    if(xc > 1 || xc < -1)
        stepx = stepx * -1;

    if(yc > 1 || yc < -1)
        stepy = stepy * -1;

    xc = xc + stepx;
    yc = yc + stepy;
}

int main(void)
{

    GLFWwindow* window;

    if (!glfwInit())
        return -1;

    window = glfwCreateWindow(1360, 768, "Atividade 00", NULL, NULL);

    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    if(glewInit()!= GLEW_OK)
    {
        cout << "Erro ao iniciar GLEW";
        return 0;
    }

    while (!glfwWindowShouldClose(window))
    {
        glfwSwapBuffers(window);
        //REMOVE THE TAIL
        glClear(GL_COLOR_BUFFER_BIT);
        glfwPollEvents();

        glBegin(GL_TRIANGLES);
        glColor3f(0, 0, color);
        glVertex2f(xc-size, yc-size);
        glColor3f(0, color, 0);
        glVertex2f(xc+0.0f, yc+size);
        glColor3f(color, 0, 0);
        glVertex2f(xc+size, yc-size);
        glEnd();

        changeDirection();
        changeColor();
    }

    glfwTerminate();
    return 0;
}
