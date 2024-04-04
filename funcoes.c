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
    glEnable(GL_DEPTH_TEST);                   // Remoção de superfície oculta
    glMatrixMode(GL_MODELVIEW);                // Define que a matriz é de modelo
    glLoadIdentity();                          // Carrega a matriz identidade
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-2.0, 2.0, -2.0, 2.0, -2.0, 2.0);  // Define uma projeção ortográfica
    iluminacao();
}

/*
 * FUNÇÃO PARA CONFIGURAR A ILUMINAÇÃO
 */
void iluminacao()
{
    float position[4] = {2.0f, 2.0f, 2.0f, 1.0f};
    float white[4] = {1.0f, 1.0f, 1.0f, 1.0f};
    float black[4] = {0.0f, 0.0f, 0.0f, 1.0f};

    glLightfv(GL_LIGHT0, GL_POSITION, position);
    glLightfv(GL_LIGHT0, GL_AMBIENT, black);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, white);
    glLightfv(GL_LIGHT0, GL_SPECULAR, white);

    glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION, 0.06f);
    glLightf(GL_LIGHT0, GL_LINEAR_ATTENUATION, 0.15f);
    glLightf(GL_LIGHT0, GL_QUADRATIC_ATTENUATION, 0.01f);

    float global_ambient[4] = {0.9f, 0.9f, 0.9f, 1.0f};
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global_ambient);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
}

void timer(int extra)
{
    glutPostRedisplay();
    glutTimerFunc(15, timer, 0);
}

///////////////////////////////////////////////////////////////////

/*
 * FUNÇÃO PARA ATUALIZAR A POSIÇÃO DO OBJETO
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
    glMaterialfv(GL_FRONT, GL_AMBIENT, material.ka);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, material.kd);
    glMaterialfv(GL_FRONT, GL_SPECULAR, material.ks);
    glMaterialf(GL_FRONT, GL_SHININESS, material.ns);
}