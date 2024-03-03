#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>

/*
 * LISTA DE FUNÇÕES
 */
int main(int argc, char ** argv);
void telaInicial();

///////////////////////////////////////////////////////////////////

/*
 * FUNÇÃO PARA INICIAR O SISTEMA
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
    glEnable(GL_DEPTH_TEST);            // Remoção de superfície oculta
    glMatrixMode(GL_PROJECTION);        // Define que a matriz é de projeção
    glLoadIdentity();                   // Carrega a matriz identidade
    glOrtho(-5, 5, -5, 5, -5, 5);       // Define uma projeção ortográfica

    glutSpecialFunc(funcoesEspeciaisTeclado);   // Chamadas quando as teclas "especiais" do teclado são acionadas
    glutDisplayFunc(telaInicial);               // Para mostrar elementos na tela rederizando os objetos
    glutMainLoop();

    return 0;
}

/*
 * FUNÇÃO PARA CONFIGURAR A TELA INICIAL
 */
void telaInicial()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);    // Limpa o buffer

    glMatrixMode(GL_MODELVIEW);                            // Define que a matriz é a de modelo
    glLoadIdentity();                                      // Carrega a matriz identidade

    glFlush();                                             // Desenha os comandos não executados
}
