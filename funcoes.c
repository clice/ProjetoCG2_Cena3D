#include <stdio.h>
#include <stdlib.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/freeglut.h>
#include <GL/glut.h>

#include "funcoes.h"

/*
 * VARIÁVEL
 */
float x = 0.0;

///////////////////////////////////////////////////////////////////

/*
 * FUNÇÃO PARA INICIAR O SISTEMA
 */
void init()
{
    glClearColor(0.5f, 0.5f, 0.5f, 1.0f);      // Cor do background
    glEnable(GL_DEPTH_TEST);                   // Habilita teste de profundidade

    glMatrixMode(GL_MODELVIEW);                // Define que a matriz é de modelo
    glLoadIdentity();                          // Carrega a matriz identidade

    gluLookAt(-0.7, 0.5, 0.7,    // Posição da câmera 
                0.0, 0.0, 0.0,   // Para onde a câmera aponta
                0.0, 1.0, 0.0);  // vetor view-up

    glMatrixMode(GL_PROJECTION);               // Define que a matriz é de projeção
    glLoadIdentity();                          // Carrega a matriz identidade

    glOrtho(-2.0, 2.0, -2.0, 2.0, -2.0, 2.0);  // Define uma projeção ortográfica

    iluminacao();
}

/*
 * FUNÇÃO PARA CONFIGURAR A ILUMINAÇÃO DA CENA 1
 */
void iluminacao()
{
    float position[4] = {2.0f, 2.0f, 2.0f, 1.0f};
    float white[4] = {1.0f, 1.0f, 1.0f, 1.0f};
    float black[4] = {0.0f, 0.0f, 0.0f, 1.0f};

    glLightfv(GL_LIGHT0, GL_POSITION, position);  // Matriz da posição da fonte de luz
    glLightfv(GL_LIGHT0, GL_AMBIENT, black);      // Matriz da cor ambiente (Sem luz - Preto)
    glLightfv(GL_LIGHT0, GL_DIFFUSE, white);      // Matriz da cor da fonte de luz (Alta luminosidade - Branco)
    glLightfv(GL_LIGHT0, GL_SPECULAR, white);     // Matriz da luz ambiente global

    glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION, 0.5f);    // Define a0
    glLightf(GL_LIGHT0, GL_LINEAR_ATTENUATION, 0.5f);      // Define a1
    glLightf(GL_LIGHT0, GL_QUADRATIC_ATTENUATION, 0.01f);  // Define a2

    // Representa a intensidade na ordem RGB e alfa controla a transparência da cor
    GLfloat posicaoLuz[4] = {0.9f, 0.9f, 0.9f, 1.0f};    // Fonte de luz local
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, posicaoLuz);  // Define a posição da luz local

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    // glEnable(GL_COLOR_MATERIAL);
    // glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
}

void timer(int extra)
{
    glutPostRedisplay();
    glutTimerFunc(15, timer, 0);
}

///////////////////////////////////////////////////////////////////

/*
 * FUNÇÃO PARA CONFIGURAR A TELA INICIAL
 */
void atualizarObjetos()
{
    x = x + 1.0;
}

/*
 * FUNÇÃO PARA DEFINIR O MATERIAL DOS OBJETOS
 */
void definirMaterialObjeto(Material material)
{
    glMaterialfv(GL_FRONT, GL_AMBIENT, material.kAmbiente);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, material.kDifusa);
    glMaterialfv(GL_FRONT, GL_SPECULAR, material.kEspecular);
    glMaterialf(GL_FRONT, GL_SHININESS, material.nBrilhosidade);
}
