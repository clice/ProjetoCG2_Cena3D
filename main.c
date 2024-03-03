#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>

/*
 * LISTA DE FUN��ES
 */
int main(int argc, char ** argv);
void telaInicial();

///////////////////////////////////////////////////////////////////

/*
 * FUN��O PARA INICIAR O SISTEMA
 */
int main (int argc, char ** argv)
{
    // Inicializando o OpenGL
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);

    tela = glutCreateWindow("Renderizacao de uma Cena 3D - Computacao Grafica");

    glClearColor(0.0, 0.0, 0.0, 0.0);   // Cor do background
    glEnable(GL_DEPTH_TEST);            // Remo��o de superf�cie oculta
    glMatrixMode(GL_PROJECTION);        // Define que a matriz � de proje��o
    glLoadIdentity();                   // Carrega a matriz identidade
    glOrtho(-5, 5, -5, 5, -5, 5);       // Define uma proje��o ortogr�fica

    glutSpecialFunc(funcoesEspeciaisTeclado);   // Chamadas quando as teclas "especiais" do teclado s�o acionadas
    glutDisplayFunc(telaInicial);               // Para mostrar elementos na tela rederizando os objetos
    glutMainLoop();

    return 0;
}

/*
 * FUN��O PARA CONFIGURAR A TELA INICIAL
 */
void telaInicial()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);    // Limpa o buffer

    glMatrixMode(GL_MODELVIEW);                            // Define que a matriz � a de modelo
    glLoadIdentity();                                      // Carrega a matriz identidade

    glFlush();                                             // Desenha os comandos n�o executados
}
