/* Leon e Guilherme */

#include "arvore_b.h"
#include <stdio.h>
#include <stdlib.h>

t_no_B *iniciaB(int valor) {
    t_no_B *novo = (t_no_B *)malloc(sizeof(t_no_B));
    novo->chave = valor;
    novo->dir = NULL;
    novo->esq = NULL;

    return novo;
}

t_no_B* montaArvoreB(char *str, int *i){
    t_no_B *no = NULL;
    char aux[10];
    int j = 0;
    
    if (str[*i] == '(') {
        (*i)++;
        while ((str[*i] != ')') && (str[*i] != '(')) {
            aux[j] = str[*i];
            j++;
            (*i)++;
        }
        no = iniciaB(atoi(aux));
        no -> esq = montaArvoreB(str, i);
        no -> dir = montaArvoreB(str, i);            
        (*i)++;
    }
    return no;        
}

void emOrdemB(t_no_B *arvore) {
    if (arvore != NULL) {
        emOrdemB(arvore->esq);
        printf("%d\n", arvore->chave);
        emOrdemB(arvore->dir);
    }
}

int valorIndexB(t_no_B *arvore) {
    if (arvore != NULL) {
        int sum = arvore->chave;
        sum = sum + valorIndexB(arvore->esq) + valorIndexB(arvore->dir);
        return sum;
    }
    else {
        return 0;
    }
}

void imprimeB(t_no_B *arvore) {
    if (arvore == NULL) {
        // printf("()");
        return;
    }
    printf("(%d", arvore->chave);
    imprimeB(arvore->esq);
    imprimeB(arvore->dir);
    printf(")");
}

int comparaSubArvore(t_no_B *arvoreA_B, t_no_B *arvoreB) {
    if (arvoreA_B == NULL && arvoreB == NULL)
        return 1;

    if ( !(((arvoreA_B->dir == NULL && arvoreB->dir == NULL) && (arvoreA_B->esq == NULL && arvoreB->esq == NULL)) ||
        ((arvoreA_B->dir != NULL && arvoreB->dir != NULL) && (arvoreA_B->esq != NULL && arvoreB->esq != NULL))) )
        return 0;

    if (arvoreA_B->chave != arvoreB->chave)
        return 0;
    if (comparaSubArvore(arvoreA_B->esq, arvoreB->esq) 
        && comparaSubArvore(arvoreA_B->dir, arvoreB->dir))
        return 1;
    return 0;
}