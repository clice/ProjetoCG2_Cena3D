#include <stdio.h>
#include <stdlib.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/freeglut.h>
#include <GL/glut.h>

#include "cena_2.h"

/*
 * DECLARAÇÕES DOS MATERIAIS ESTÁTICOS
 */
Material Ouro2 = {
    {0.24725f, 0.1995f,0.0745f, 1.0f},
    {0.75164f, 0.60648f, 0.22648f, 1.0f},
    {0.628281f,0.555802f,0.366065f, 1.0f},
    0.4f * 50.0f
};

///////////////////////////////////////////////////////////////////

/*
 * FUNÇÃO PARA INICIAR A CENA 2 - 4 VIEWPORTS DE UM BULE 3D EM ROTAÇÃO
 */
int iniciarCena2(int argc, char ** argv)
{
    // Inicializando o OpenGL
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowPosition(200, 0);
    glutInitWindowSize(600, 600);

    glutCreateWindow("Renderizacao da Cena 2 - 4 Viewports de um Bule 3D em Rotacao");

    init();
    glutDisplayFunc(telaInicialCena2);  // Para mostrar elementos na tela rederizando os objetos
    glutTimerFunc(0, timer, 0);
    glutMainLoop();

    return 0;
}

/*
 * FUNÇÃO PARA CONFIGURAR A TELA INICIAL
 */
void telaInicialCena2()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);    // Limpa o buffer
    glMatrixMode(GL_MODELVIEW);                            // Define que a matriz é a de modelo
    atualizarObjetos();

    glLoadIdentity(); // Eixo XY
    glViewport(0, 300, 300, 300);
    gluLookAt(0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    desenharBules();

    glLoadIdentity(); // Eixo YZ
    glViewport(300, 300, 300, 300);
    gluLookAt(1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    desenharBules();

    glLoadIdentity(); // Eixo XZ
    glViewport(0, 0, 300, 300); // Janela de exibição
    gluLookAt(0.0, 1.0, 0.0, 0.0, 0.0, 0.0,0.0, 0.0, -1.0);//local da câmera
    desenharBules();

    glLoadIdentity();
    glViewport(300, 0, 300, 300); // Janela de exibição
    gluLookAt(1.0, 1.0, 0.7, 0.0, 0.0, 0.0,0.0, 1.0, 0.0); //local da câmera
    gluPerspective(40.0, 1.0, 1.0, 1.0); // Perspectiva
    desenharBules();
    
    glFlush();  // Desenha os comandos não executados

    glutSwapBuffers();
}

///////////////////////////////////////////////////////////////////

/*
 * FUNÇÃOO PARA DESENHAR OS BULES
 */
void desenharBules()
{
    glPushMatrix();
        definirMaterialObjeto(Ouro2);
        glTranslatef(0.0, 0.0, 0.0);
        glRotatef(0, 1, 0, 0); // centralizar o bule no eixo X
        glRotatef(0, 0, 1, 0); // centralizar o bule no eixo Y
        glRotatef(0, 0, 0, 1); // centralizar o bule no eixo Z
        glRotatef(x, 0, 1, 0); // aplicar rotação em torno de Y
        glutSolidTeapot(0.40f);
    glPopMatrix();
}