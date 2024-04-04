#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "cena_2.h"

/*
 * FUNÇÃO PARA INICIAR O SISTEMA
 */
int main (int argc, char ** argv)
{
    int opcaoPrograma;

    printf("ESCOLHA UMA DAS OPCOES\n");
    printf("1 - Renderizacao da Cena 1 - Bule, Bola e Toro\n");
    printf("2 - Renderizacao da Cena 2 - 4 Viewports de um Bule 3D em Rotacao\n\n");
    printf("Digite a cena que quer: ");
    scanf("%d", &opcaoPrograma);
    printf("\n");

    switch(opcaoPrograma) {
        // RENDERIZAÇÃO DA CENA 1 - BULE, BOLA E TORO
        case 1:
            iniciarCena1(argc, argv);
            break;

        // RENDERIZAÇÃO DA CENA 2 - 4 VIEWPORTS DE UM BULE 3D EM ROTAÇÃO
        case 2:
            iniciarCena2(argc, argv);
            break;
        default:
            printf("OPCAO INVALIDA!");
    }

    return 0;
}
