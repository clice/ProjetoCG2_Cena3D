#ifndef FUNCOES_H
#define FUNCOES_H

/*
 * VARIÁVEL
 */
extern float x = 0.0;

/*
 * ESTRUTURA MATERIAL CENA 1
 */
typedef struct Material
{
    float ka[4];
    float kd[4];
    float ks[4];
    float ns;
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
