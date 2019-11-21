#include <iostream>
#include<cmath>
#include<array>
#include<cstdio>

#define PI 3.14159265

using namespace std;


class mat33 {
public:
    mat33();  // Construtor
    ~mat33();  // Destrutor

    // Ponteiro p�blico para os elementos da matrix
    const float *mptr;

    // Principais m�todos
    void identity();  // Carrega a matriz identidade
    void rotate(int degrees); // Multiplica a esquerda por uma matriz de rota��o
    void translate(float x, float y, float tx, float ty); // Multiplica a esquerda por uma matriz de transla��o
    void scale(float x, float y,float sx, float sy); // Multiplica a esquerda por uma matriz de escala
    void print();  // Imprime no console a matriz atual

private:
    array <float, 9> m;  // Matriz (vetor) principal
    array <float, 9> maux; // // Matriz (vetor) auxiliar
};

