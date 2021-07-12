/* Leon e Guilherme */
#ifndef __ARVORE_A__
#define __ARVORE_A__

#include "arvore_b.h"

/*
Nó da árvore A
*/
typedef struct t_no_A t_no_A;
struct t_no_A {
    t_no_B *chave_arvore;
    t_no_A *esq, *dir, *pai;
};

t_no_A * criaNo(t_no_B *noB);

/*
Inclusão de novo nó na árvore A.
*/
t_no_A * inclusao(t_no_A * noA, t_no_B * noB);
int busca(t_no_A *arvoreA, t_no_B *arvoreB);
int comparaSubArvore(t_no_B *arvoreA_B, t_no_B *arvoreB);
void imprimeB(t_no_B *arvore);

#endif