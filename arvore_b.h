/* Leon e Guilherme */
#ifndef __ARVORE_B__
#define __ARVORE_B__

/*
Nó da árvore B
*/
typedef struct t_no_B t_no_B;
struct t_no_B {
    int chave;
    t_no_B *esq, *dir;
};

#endif