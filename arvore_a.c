/* Leon e Guilherme */

#include "arvore_a.h"
#include <stdlib.h>

t_no_A * criaNo(t_no_B *noB) {
    t_no_A *novo = (t_no_A *)malloc (sizeof (t_no_A));

    novo->chave_arvore = noB;
    novo->esq = NULL;
    novo->dir = NULL;
    novo->pai = NULL;
    return novo;
}

t_no_A * inclusao(t_no_A * noA, t_no_B * noB) {
    if (noA == NULL) 
        return criaNo(noB);
    if (valorIndexB(noB) < valorIndexB(noA->chave_arvore)) {
        noA->esq = inclusao(noA->esq, noB);
        noA->esq->pai = noA;
    }
    else {
        noA->dir = inclusao(noA->dir, noB);
        noA->dir->pai = noA;
    }
    return noA;
}