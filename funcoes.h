#ifndef FUNCOES_H
#define FUNCOES_H

/*
 * VARIÁVEL
 */
extern float x;

/*
 * ESTRUTURA MATERIAL CENA 1
 */
typedef struct Material
{
    // Reflexão ambiente para a cor do objeto, quando não iluminado diretamente pela fonte de luz
    float kAmbiente[4];   
    float kDifusa[4];     
    float kEspecular[4];  
    float nBrilhosidade;
} Material;

///////////////////////////////////////////////////////////////////

/*
 * DECLARAÇÕES DAS FUNÇÕES
 */
void init();
void iluminacao();
void timer(int extra);
void atualizarObjetos();
void definirMaterialObjeto(Material material);

#endif // FUNCOES_H
