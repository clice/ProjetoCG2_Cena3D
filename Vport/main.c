#include <windows.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <gl/gl.h>
#include <gl/glu.h>
#include <GL/freeglut.h>
#include <GL/glut.h>



///////////////////////////////////////////////////////////////////

/*
 * VARIÁVEIS
 */
static int tela;
float x = 0.0;

///////////////////////////////////////////////////////////////////

/*
 * ESTRUTURA MATERIAL
 */
typedef struct material
{
    float ka[4];
    float kd[4];
    float ks[4];
    float ns;
} Material;

Material amarelo = {
    {0.05f, 0.05f, 0.0f, 1.0f},
    {0.5f, 0.5f, 0.4f, 1.0f},
    {0.7f, 0.7f, 0.4f, 1.0f},
    0.5f * 50.0f
};

Material rubi = {
    {0.1745f, 0.05175f, 0.05175f, 1.0f},
    {0.61424f, 0.04136f, 0.04136f, 1.0f},
    {0.727811f, 0.626959f, 0.626959f, 1.0f},
    0.2f * 128.0f
};

Material turquesa = {
    {0.1f, 0.18725f,0.1745f, 1.0f},
    {0.396f, 0.74151f, 0.69102f, 1.0f},
    {0.297254f,0.30829f, 0.306678f, 1.0f},
    0.8f * 128.0f
};

Material branco = {
    {0.0f, 0.0f,0.0f, 1.0f},
    {0.55f, 0.55f, 0.55f, 1.0f},
    {0.7f,0.7f, 0.7f, 1.0f},
    0.5f * 50.0f
};

Material ouro = {
    {0.24725f, 0.1995f,0.0745f, 1.0f},
    {0.75164f, 0.60648f, 0.22648f, 1.0f},
    {0.628281f,0.555802f,0.366065f, 1.0f},
    0.4f * 50.0f
};

///////////////////////////////////////////////////////////////////

/*
 * LISTA DE FUNÇÕES
 */
int main(int argc, char ** argv);
int init();
void telaInicial();
void iluminacao();
void timer(int extra);

void atualizarObjetos();
void definirMaterialObjeto(Material material);

void desenharBule();

///////////////////////////////////////////////////////////////////

int init(){
    glClearColor(0.5f, 0.5f, 0.5f, 1.0f);   // Cor do background
    glEnable(GL_DEPTH_TEST);                // Remoção de superfície oculta
    glMatrixMode(GL_MODELVIEW);             // Define que a matriz é de modelo
    glLoadIdentity();                       // Carrega a matriz identidade
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-2.0, 2.0, -2.0, 2.0, -2.0, 2.0);           // Define uma projeção ortográfica
    iluminacao();
}

/*
 * FUNÇÃO PARA INICIAR O SISTEMA
 */
int main (int argc, char ** argv)
{
    // Inicializando o OpenGL
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowPosition(200, 0);
    glutInitWindowSize(400, 400);

    tela = glutCreateWindow("Renderizacao de uma Cena 3D - Computacao Grafica");

    init();
    glutDisplayFunc(telaInicial);                  // Para mostrar elementos na tela rederizando os objetos
    glutTimerFunc(0, timer, 0);
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
    atualizarObjetos();

    glLoadIdentity();//Eixo XY
    glViewport(0, 300, 300, 300);
    gluLookAt(0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    desenharBule();

    glLoadIdentity();//Eixo YZ
    glViewport(300, 300, 300, 300);
    gluLookAt(1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    desenharBule();

    glLoadIdentity();// Eixo XZ
    glViewport(0, 0, 300, 300); // Janela de exibição
    gluLookAt(0.0, 1.0, 0.0, 0.0, 0.0, 0.0,0.0, 0.0, -1.0);//local da câmera
    desenharBule();

    glLoadIdentity();
    glViewport(300, 0, 300, 300); // Janela de exibição
    gluLookAt(1.0, 1.0, 0.7, 0.0, 0.0, 0.0,0.0, 1.0, 0.0); //local da câmera
    gluPerspective(40.0, 1.0, 1.0, 1.0); // Perspectiva
    desenharBule();



    // glLoadIdentity();                                      // Carrega a matriz identidade
    glFlush();                                             // Desenha os comandos não executados

    glutSwapBuffers();
}

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

/*
Função para atualizar o eixo de rotação
*/
void atualizarObjetos()
{
    x = x + 1;
}

///////////////////////////////////////////////////////////////////

/*
 * FUNÇÃO PARA DEFINIR A COLORAÇÃO DOS OBJETOS
 */


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

///////////////////////////////////////////////////////////////////

/*
 * FUNÇÃO PARA DESENHAR UM BULE
 */
void desenharBule()
{
    glPushMatrix();
        definirMaterialObjeto(ouro);
        glTranslatef(0.0, 0.0, 0.0);
        glRotatef(0, 1, 0, 0); //centralizar o bule no eixo X
        glRotatef(0, 0, 1, 0); //centralizar o bule no eixo Y
        glRotatef(0, 0, 0, 1); //centralizar o bule no eixo Z
        glRotatef(x, 0, 1, 0); //aplicar rotação em torno de Y
        glutSolidTeapot(0.40f);
    glPopMatrix();
}


