#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/freeglut.h>
#include <GL/glut.h>

#include "cena_1.h"

/*
 * VARIÁVEL
 */
static int telaCena1;

///////////////////////////////////////////////////////////////////

/*
 * DECLARAÇÕES DOS MATERIAIS ESTÁTICOS
 */
Material Amarelo = {
    {0.05f, 0.05f, 0.0f, 1.0f},
    {0.5f, 0.5f, 0.4f, 1.0f},
    {0.7f, 0.7f, 0.4f, 1.0f},
    0.5f * 50.0f
};

Material Rubi = {
    {0.1745f, 0.05175f, 0.05175f, 1.0f},
    {0.61424f, 0.04136f, 0.04136f, 1.0f},
    {0.727811f, 0.626959f, 0.626959f, 1.0f},
    0.2f * 128.0f
};

Material Turquesa = {
    {0.1f, 0.18725f,0.1745f, 1.0f},
    {0.396f, 0.74151f, 0.69102f, 1.0f},
    {0.297254f,0.30829f, 0.306678f, 1.0f},
    0.8f * 128.0f
};

Material Branco = {
    {0.0f, 0.0f,0.0f, 1.0f},
    {0.55f, 0.55f, 0.55f, 1.0f},
    {0.7f,0.7f, 0.7f, 1.0f},
    0.5f * 50.0f
};

Material Ouro1 = {
    {0.24725f, 0.1995f,0.0745f, 1.0f},
    {0.75164f, 0.60648f, 0.22648f, 1.0f},
    {0.628281f,0.555802f,0.366065f, 1.0f},
    0.4f * 50.0f
};

///////////////////////////////////////////////////////////////////

/*
 * FUNÇÃO PARA INICIAR A CENA 1 -  - BULE, BOLA E TORO
 */
int iniciarCena1(int argc, char ** argv)
{
    // Inicializando o OpenGL
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowPosition(200, 0);
    glutInitWindowSize(400, 400);

    telaCena1 = glutCreateWindow("Renderizacao da Cena 1 - Bule, Bola e Toro");

    // glutSpecialFunc(funcoesEspeciaisTeclado);   // Chamadas quando as teclas "especiais" do teclado são

    init();
    glutDisplayFunc(telaInicialCena1);                  // Para mostrar elementos na tela rederizando os objetos
    glutTimerFunc(0, timer, 0);
    glutMainLoop();

    return 0;
}

/*
 * FUNÇÃO PARA CONFIGURAR A TELA INICIAL
 */
void telaInicialCena1()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);    // Limpa o buffer

    glMatrixMode(GL_MODELVIEW);                            // Define que a matriz é a de modelo
    atualizarObjetos();

    glLoadIdentity();
    //glViewport(200, 0, 400, 400);
    gluLookAt(-0.7, 0.5, 0.7,
                0.0, 0.0, 0.0,
                0.0, 1.0, 0.0);
    gluPerspective(40, 1.0, 1.0, 1.0);
    desenharAmbiente();
    desenharEsfera();
    desenharBule();
    desenharToro();

    // glLoadIdentity();                                      // Carrega a matriz identidade

    glFlush();                                             // Desenha os comandos não executados

    glutSwapBuffers();
}

///////////////////////////////////////////////////////////////////

/*
 * FUNÇÃO PARA CONFIGURAR A TELA INICIAL
 */
void desenharChao()
{
    glBegin(GL_QUADS);
    definirMaterialObjeto(Rubi); //Fundo
    glVertex3f(-1.0f, 0.05f, -1.0f);
    glVertex3f(1.0f, 0.05f, -1.0f);
    glVertex3f(1.0f, 0.05f, 1.0f);
    glVertex3f(-1.0f, 0.05f, 1.0f);


    glVertex3f(-1.0f, 0.15f,1.0f); //Topo
    glVertex3f(-1.0f, 0.15f,-1.0f);
    glVertex3f(1.0f, 0.15f,1.0f);
    glVertex3f(1.0f, 0.15f,-1.0f);

    //Lado Z+
    glVertex3f(-1.0f, 0.05f, 1.0f);
    glVertex3f(1.0f, 0.05f, 1.0f);
    glVertex3f(1.0f, 0.15f, 1.0f);
    glVertex3f(-1.0f, 0.15f, 1.0f);

    // Lado Z-
    glVertex3f(-1.0f, 0.05f,-1.0f);
    glVertex3f(1.0f, 0.05f, -1.0f);
    glVertex3f(1.0f, 0.15f, -1.0f);
    glVertex3f(-1.0f, 0.15f, -1.0f);

    //Lado X+
    glVertex3f(1.0f, 0.05f, 1.0f);
    glVertex3f(1.0f, 0.15f,-1.0f);
    glVertex3f(1.0f, 0.05f, -1.0f);
    glVertex3f(1.0f, 0.15f, 1.0f);

    //Lado X-
    glVertex3f(-1.0f, 0.05f, 1.0f);
    glVertex3f(-1.0f, 0.15f, -1.0f);
    glVertex3f(-1.0f, 0.05f, -1.0f);
    glVertex3f(-1.0f, 0.15f, 1.0f);

    glEnd();
}

/*
 * FUNÇÃO PARA CONFIGURAR A TELA INICIAL
 */
void desenharParedeA() //Parede no Eixo Z-
{
    glBegin(GL_QUADS);
    //Fundo
    glVertex3f(-1.0f, 0.15f, -1.0f);
    glVertex3f(1.0f, 0.15f, -1.0f);
    glVertex3f(1.0f, 0.15f, -0.9f);
    glVertex3f(-1.0f, 0.15f, -0.9f);


    glVertex3f(-1.0f, 1.0f, -0.9f); //Topo
    glVertex3f(-1.0f, 1.0f, -1.0f);
    glVertex3f(1.0f, 1.0f, -0.9f);
    glVertex3f(1.0f, 1.0f, -1.0f);

    //Lado Z+
    glVertex3f(-1.0f, 0.15f, -0.9f);
    glVertex3f(1.0f, 0.15f, -0.9f);
    glVertex3f(1.0f, 1.0f, -0.9f);
    glVertex3f(-1.0f, 1.0f, -0.9f);

    // Lado Z-
    glVertex3f(-1.0f, 0.15f,-1.0f);
    glVertex3f(1.0f, 0.15f, -1.0f);
    glVertex3f(1.0f, 1.0f, -1.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);

    //Lado X+
    glVertex3f(1.0f, 0.15f, -0.9f);
    glVertex3f(1.0f, 1.0f,-1.0f);
    glVertex3f(1.0f, 0.15f, -1.0f);
    glVertex3f(1.0f, 1.0f, -0.9f);

    //Lado X-
    glVertex3f(-1.0f, 0.15f, -0.9f);
    glVertex3f(-1.0f, 1.0f, -1.0f);
    glVertex3f(-1.0f, 0.15f, -1.0f);
    glVertex3f(-1.0f, 1.0f, -0.9f);

    glEnd();
}

/*
 * FUNÇÃO PARA CONFIGURAR A TELA INICIAL
 */
void desenharParedeL() //Parede no Eixo X+
{
    glBegin(GL_QUADS);
     //Fundo
    glVertex3f(0.9f, 0.15f, -1.0f);
    glVertex3f(1.0f, 0.15f, -1.0f);
    glVertex3f(1.0f, 0.15f, 1.0f);
    glVertex3f(0.9f, 0.15f, 1.0f);


    glVertex3f(0.9f, 1.0f, 1.0f); //Topo
    glVertex3f(0.9f, 1.0f, -1.0f);
    glVertex3f(1.0f, 1.0f, 1.0f);
    glVertex3f(1.0f, 1.0f, -1.0f);

    //Lado Z+
    glVertex3f(0.9f, 0.15f, 1.0f);
    glVertex3f(1.0f, 0.15f, 1.0f);
    glVertex3f(1.0f, 1.0f, 1.0f);
    glVertex3f(0.9f, 1.0f, 1.0f);

    // Lado Z-
    glVertex3f(0.9f, 0.15f,-1.0f);
    glVertex3f(1.0f, 0.15f, -1.0f);
    glVertex3f(1.0f, 1.0f, -1.0f);
    glVertex3f(0.9f, 1.0f, -1.0f);

    //Lado X+
    glVertex3f(1.0f, 0.15f, 1.0f);
    glVertex3f(1.0f, 1.0f,-1.0f);
    glVertex3f(1.0f, 0.15f, -1.0f);
    glVertex3f(1.0f, 1.0f, 1.0f);

    //Lado X-
    glVertex3f(0.9f, 0.15f, 1.0f);
    glVertex3f(0.9f, 1.0f, -1.0f);
    glVertex3f(0.9f, 0.15f, -1.0f);
    glVertex3f(0.9f, 1.0f, 1.0f);

    glEnd();
}

/*
 * FUNÇÃO PARA DESENHAR UM AMBIENTE (SUPERFÍCIE E PAREDE)
 */
void desenharAmbiente()
{
    desenharChao();
    desenharParedeA();
    desenharParedeL();
    /* glPushMatrix();
        definirMaterialObjeto(Rubi);
        glScalef(3, 0.25, 3);
        //glRotatef(x, 0, 1, 0);
        glutSolidCube(1.0f);
    glPopMatrix();

    glPushMatrix();
        definirMaterialObjeto(Branco);
        glScalef(5.0, 3.0, -0.1);
        glTranslatef(-0.05, 0.208, 15.0);
        glutSolidCube(0.5f);
    glPopMatrix();

    glPushMatrix();
        definirMaterialObjeto(Branco);
        glScalef(-0.1, 3.0, 0.5);
        glTranslatef(1.0, 0.208, 15.0);
        glutSolidCube(0.5f);
    glPopMatrix(); */
}

///////////////////////////////////////////////////////////////////

/*
 * FUNÇÃO PARA DESENHAR UMA ESFERA
 */
void desenharEsfera()
{
    glPushMatrix();
        definirMaterialObjeto(Branco);
        //glRotatef(x, 0, 1, 0);
        glTranslatef(0.75, 0.27, 0.0);
        glutSolidSphere(0.15, 40, 40);
    glPopMatrix();
}

/*
 * FUNÇÃO PARA DESENHAR UM BULE
 */
void desenharBule()
{
    glPushMatrix();
        definirMaterialObjeto(Turquesa);
        //glRotatef(x, 0, 1, 0);
        glTranslatef(-0.60, 0.39, 0.0);
        glutSolidTeapot(0.40f);
    glPopMatrix();
}

/*
 * FUNÇÃO PARA DESENHAR UM TORO (ROSCA)
 */
void desenharToro()
{
    glPushMatrix();
        definirMaterialObjeto(Ouro1);
        glTranslatef(0.30, 0.30, 0.0);
        glRotatef(90, 1, 0, 0);
        glutSolidTorus(0.05, 0.15, 40, 40);
    glPopMatrix();
}
