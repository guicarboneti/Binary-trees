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

    if (!((arvoreA->esq == NULL) && (arvoreA->dir == NULL))) {
        imprimeArvore(arvoreA->esq);
        printf("]\n");
        imprimeArvore(arvoreA->dir);
        printf("]\n");
    }
}

t_no_A *buscaArvB(t_no_A *arvoreA, t_no_B *arvoreB) {
    if (arvoreA == NULL)
        return NULL;

    if (valorIndexB(arvoreA->chave_arvore) == valorIndexB(arvoreB)) {
        return arvoreA;
    }
    else {
        if (valorIndexB(arvoreA->chave_arvore) > valorIndexB(arvoreB)) {
            return buscaArvB(arvoreA->esq, arvoreB);
        }
        else {
            return buscaArvB(arvoreA->dir, arvoreB);
        }
    }
}

t_no_A *min(t_no_A *no) {
    if (no->esq == NULL) return no;
    else
        return min(no->esq);
}

t_no_A *sucessor (t_no_A *no) {
    t_no_A *s = NULL;
    if (!(no->dir == NULL)) return min(no->dir);
    else {
        s = no->pai;
        while (!(s == NULL) && no == s->dir) {
            no = s;
            s = s->pai;
        }        
    }
    return s;
}

void ajustaNoPai(t_no_A *no, t_no_A *novo) {
    if (!(no->pai == NULL)) {
        if (no->pai->esq == no)
            no->pai->esq = novo;
        else {
            no->pai->dir = novo;
        }
        if (!(novo == NULL))
            novo->pai = no->pai;
    }
}

t_no_A* exclui (t_no_A *raiz, t_no_B *arvoreB) {
    t_no_A *no = buscaArvB(raiz, arvoreB);
    t_no_A *s, *novaRaiz = raiz;

    if (no == raiz && no->esq == NULL && no->dir == NULL) {
        free(raiz);
        no = NULL;
        return no;
    }

    if (no->esq == NULL) {
        ajustaNoPai(no, no->dir);
        if (no->pai == NULL)
            novaRaiz = no->dir;
        free(no);
    } else {
        if (no->dir == NULL){
            ajustaNoPai(no, no->esq);
            if (no->pai == NULL)
                novaRaiz = no->esq;
            free(no);
        }
        else {
            s = sucessor(no);
            ajustaNoPai(s, s->dir);
            s->esq = no->esq;
            s->dir = no->dir;
            ajustaNoPai(no, s);
            if (no == raiz) novaRaiz = s;
            free(no);
        }
    }
    return novaRaiz;
}