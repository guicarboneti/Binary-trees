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

/*
Busca uma árvore B dentro de uma árvore A.
*/
int busca(t_no_A *arvoreA, t_no_B *arvoreB);

/*
Inicia impressão da árvore A. Encapsula a função de recursão que imprime a árvore A.
*/

void iniciaImpressao(t_no_A * arvoreA);

/*
Imprime descrição da árvore A recursivamente.
*/
void imprimeArvore(t_no_A * arvoreA);

#endif