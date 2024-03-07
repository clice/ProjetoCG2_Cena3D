#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>

///////////////////////////////////////////////////////////////////

/*
 * VARIÁVEIS
 */
static int tela;

///////////////////////////////////////////////////////////////////

/*
 * LISTA DE FUNÇÕES
 */
int main(int argc, char ** argv);
void telaInicial();
void iluminação();

void definirMaterialObjeto();

void desenharAmbiente();
void desenharEsfera();
void desenharBule();
void desenharToro();

///////////////////////////////////////////////////////////////////

typedef struct Material
{
    float ka[4];
    float kd[4];
    float ks[4];
    float ns;
} Material;

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

Material Ouro = {
    {0.24725f, 0.1995f,0.0745f, 1.0f},
    {0.75164f, 0.60648f, 0.22648f, 1.0f},
    {0.628281f,0.555802f,0.366065f, 1.0f},
    0.4f * 50.0f
};

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

    // glutSpecialFunc(funcoesEspeciaisTeclado);   // Chamadas quando as teclas "especiais" do teclado são acionadas
    glutDisplayFunc(telaInicial);                  // Para mostrar elementos na tela rederizando os objetos
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

void iluminação()
{

}

///////////////////////////////////////////////////////////////////

/*
 * FUNÇÃO PARA DEFINIR A COLORAÇÃO DOS OBJETOS
 */


/*
 * FUNÇÃO PARA DEFINIR O MATERIAL DOS OBJETOS
 */
void definirMaterialObjeto()
{

}

///////////////////////////////////////////////////////////////////

/*
 * FUNÇÃO PARA DESENHAR UM AMBIENTE (SUPERFÍCIE E PAREDE)
 */
void desenharAmbiente()
{
    glPushMatrix();
        definirMaterialObjeto(Branco);
        glLoadIdentity();
        glRotatef(x, 0, 1, 0);
        glScalef(2, 0.25, 1);
        glutSolidCube(1.0f);
    glPopMatrix();

    glPushMatrix();
        definirMaterialObjeto(Amarelo);
        glLoadIdentity();
        glRotatef(x, 0, 1, 0);
        glScalef(4.0, 6.0, -0.1);
        glTranslatef(-0.002, -0.01, 5.0);
        glutSolidCube(0.5f);
    glPopMatrix();
}

/*
 * FUNÇÃO PARA DESENHAR UMA ESFERA
 */
void desenharEsfera()
{
    glPushMatrix();
        definirMaterialObjeto(Rubi);
        glLoadIdentity();
        glRotatef(x, 0, 1, 0);
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
        glLoadIdentity();
        glRotatef(x, 0, 1, 0);
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
        definirMaterialObjeto(Ouro);
        glLoadIdentity();
        glRotatef(x, 0, 1, 0);
        glTranslatef(0.30, 0.30, 0.0);
        glutSolidTorus(0.05, 0.15, 40, 40);
    glPopMatrix();
}