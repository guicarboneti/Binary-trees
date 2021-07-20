/* Leon e Guilherme */

#include "arvore_a.h"
#include "arvore_b.h"
#include <stdio.h>
#include <string.h>

#define MAX 50

int main() {
    int i = 0;
    int resultBusca;
    char op;
    char entrada[MAX];
    t_no_B *arvoreB = NULL;
    t_no_A *arvoreA = NULL;

    printf("Insira o próximo comando:\n");
    do {
        /* Leitura da entrada até EOF */
        op = fgetc(stdin);
        if (feof(stdin)) {
            break;
        }
        fgetc(stdin); /* Pula espaço */
        fgets(entrada, MAX, stdin); /* Lê a string da árvore B */
        entrada[strcspn (entrada, "\n")] = '\0' ; /* Remove \n do fim da string */

        /* Monta a árvore B */
        arvoreB = montaArvoreB(entrada, &i);

        /* Comandos */
        switch(op) {

            /* Inserção */
            case 'i':
                arvoreA = inclusao(arvoreA, arvoreB);
                iniciaImpressao(arvoreA);
                printf("\n");
            break;

            /* Busca */
            case 'b':
                resultBusca = busca(arvoreA, arvoreB);
                if (resultBusca) {
                    printf("Árvore equivalente encontrada.\n");
                }
                else {
                    printf("Árvore equivalente não encontrada.\n");
                }
                printf("\n");
            break;

            /* Remoção */
            case 'r':
                arvoreA = exclui(arvoreA, arvoreB);
                iniciaImpressao(arvoreA);
                printf("\n");
            break;

            default:
                printf("Comando desconhecido.\n");
            break;

        }

        i = 0;
        arvoreB = NULL;
        printf("Insira o próximo comando:\n");

    } while (1);

    liberaArvA(arvoreA);

    return 0;
}