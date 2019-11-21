#define GLEW_STATIC
#define GLFW_INCLUDE_NONE

#include <GLFW/glfw3.h>
#include <iostream>
#include <GL/glew.h>
#include <string>

//trabalhar com arquivos
#include <fstream>
#include <sstream>

using namespace std;

struct vertex {
    float x, y, r, g, b;
};

string readFile(string filename) {

    ifstream t(filename);
    stringstream buffer;
    buffer << t.rdbuf();
    return buffer.str();
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

    vertex v[] = {
        {0.0f, 0.0f, 1.0f, 1.0f, 1.0f} ,
        //Top
        {-0.2f, 0.8f, 0.0f, 1.0f, 0.0f} ,
        { 0.2f, 0.8f, 0.0f, 0.0f, 1.0f} ,
        { 0.0f, 0.8f, 0.0f, 1.0f, 1.0f} ,
        { 0.0f, 1.0f, 1.0f, 0.0f, 0.0f} ,
        //Bottom
        {-0.2f,-0.8f, 0.0f, 0.0f, 1.0f} ,
        { 0.2f,-0.8f, 0.0f, 1.0f, 0.0f} ,
        { 0.0f,-0.8f, 0.0f, 1.0f, 1.0f} ,
        { 0.0f,-1.0f, 1.0f, 0.0f, 0.0f} ,
        //Left
        {-0.8f,-0.2f, 0.0f, 1.0f, 0.0f} ,
        {-0.8f, 0.2f, 0.0f, 0.0f, 1.0f} ,
        {-0.8f, 0.0f, 0.0f, 1.0f, 1.0f} ,
        {-1.0f, 0.0f, 1.0f, 0.0f, 0.0f} ,
        //Right
        { 0.8f,-0.2f, 0.0f, 0.0f, 1.0f} ,
        { 0.8f, 0.2f, 0.0f, 1.0f, 0.0f} ,
        { 0.8f, 0.0f, 0.0f, 1.0f, 1.0f} ,
        { 1.0f, 0.0f, 1.0f, 0.0f, 1.0f}
    };

    unsigned short ind[] = {
        //Top
        0,1,3,
        0,3,2,
        3,1,4,
        3,4,2,
        //Bottom
        0,5,7,
        0,7,6,
        7,5,8,
        7,8,6,
        //Left
        0,9,11,
        0,11,10,
        11,9,12,
        11,12,10,
        //Right
        0,13,15,
        0,15,14,
        15,13,16,
        15,16,14
    };

    GLuint myIBO;
    glGenBuffers(1, &myIBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, myIBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(ind), ind, GL_STATIC_DRAW);

    GLuint VBO1;
    glGenBuffers(1, &VBO1);
    glBindBuffer(GL_ARRAY_BUFFER, VBO1);
    glBufferData(GL_ARRAY_BUFFER, sizeof(v), v, GL_STATIC_DRAW);

    string vss = readFile("vertex.sdr");
    string fss = readFile("fragment.sdr");
    const char *vertexShaderText = vss.c_str();
    const char *fragmentShaderText = fss.c_str();

    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderText, nullptr);
    glCompileShader(vertexShader);
    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderText, nullptr);
    glCompileShader(fragmentShader);
    GLuint shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);
    glUseProgram(shaderProgram);

    //glVertexPointer(2, GL_FLOAT, 0, nullptr);
    //glEnableClientState(GL_VERTEX_ARRAY);

    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(vertex), (void *) 0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(vertex), (void *) 8);

    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);


    while (!glfwWindowShouldClose(window))
    {
        glClearColor(0.0, 0.0, 0.0, 1.0);
        glClear(GL_COLOR_BUFFER_BIT);
        glDrawElements(GL_TRIANGLES, 48, GL_UNSIGNED_SHORT, (GLvoid*)0);

        glfwSwapBuffers(window);
        //framecount++;

        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
