/* Leon e Guilherme */

#include "arvore_a.h"
#include "arvore_b.h"
#include <stdio.h>

int main() {
    char string[15] = "(1(0)(3(2)(10))";
    char string2[15] = "(12(1))";
    char string3[15] = "(12)";
    int i = 0;

    t_no_B *arvoreB = montaArvoreB(string, &i);

    i=0;
    t_no_B *arvoreB2 = montaArvoreB(string2, &i);

    i=0;
    t_no_B *arvoreB3 = montaArvoreB(string3, &i);

    t_no_A *arvoreA = NULL;
    arvoreA = inclusao(arvoreA, arvoreB);
    iniciaImpressao(arvoreA);
    printf("\n");

    arvoreA = inclusao(arvoreA, arvoreB2);
    iniciaImpressao(arvoreA);
    printf("\n");

    arvoreA = inclusao(arvoreA, arvoreB3);
    iniciaImpressao(arvoreA);
    printf("\n");

    busca(arvoreA, arvoreB3);

    return 0;
}