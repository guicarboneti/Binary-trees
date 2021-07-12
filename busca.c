/* Leon e Guilherme */

#include "arvore_a.h"
#include "arvore_b.h"
#include <stdio.h>

int main() {
    char string[15] = "(1(0)(3(2)(5))";
    int i = 0;

    t_no_B *arvoreB = montaArvoreB(string, &i);
    t_no_A *arvoreA = NULL;
    arvoreA = inclusao(arvoreA, arvoreB);

    emOrdemB(arvoreA->chave_arvore);
    valorIndexB(arvoreA->chave_arvore);

    return 0;
}