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

#endif