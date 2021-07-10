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

/*
Inicia árvore
*/
t_no_B *iniciaB(int valor);

/*
Monta a árvore
*/
t_no_B *montaArvoreB(char *str, int *i);

/*
Impressão em ordem da árvore
*/
void emOrdemB(t_no_B *arvore);

/*
Calcula valor de indexação da árvore
*/
int valorIndexB(t_no_B *arvore);

#endif