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
    
  if (str[*i] == '(') {
        (*i)++;
        no = iniciaB(str[*i] - '0');    
        (*i)++;
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