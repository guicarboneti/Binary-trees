/* Leon e Guilherme */

#include "arvore_a.h"
#include "arvore_b.h"
#include <stdlib.h>
#include <stdio.h>

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

int busca(t_no_A *arvoreA, t_no_B *arvoreB) {
    if (arvoreA == NULL)
        return 0;

    /* Imprime árvore acessada */
    imprimeB(arvoreA->chave_arvore);
    printf(" : %d\n", valorIndexB(arvoreA->chave_arvore));

    if (valorIndexB(arvoreA->chave_arvore) == valorIndexB(arvoreB)) {
        return 1;
    }
    else {
        if (valorIndexB(arvoreA->chave_arvore) > valorIndexB(arvoreB)) {
            return busca(arvoreA->esq, arvoreB);
        }
        else {
            return busca(arvoreA->dir, arvoreB);
        }
    }
}

void iniciaImpressao(t_no_A * arvoreA) {
    printf("[\n");
    imprimeArvore(arvoreA);
    printf("]\n]\n");
}

void imprimeArvore(t_no_A * arvoreA) {
    printf("[");
    if (arvoreA == NULL) {
        return;
    }
    imprimeB(arvoreA->chave_arvore);
    printf(" : %d\n", valorIndexB(arvoreA->chave_arvore));
    imprimeArvore(arvoreA->esq);
    printf("]\n");
    imprimeArvore(arvoreA->dir);
    printf("]\n");
}