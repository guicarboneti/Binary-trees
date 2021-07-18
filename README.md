# Trabalho árvores binárias
## Autores: Guilherme Carbonari Boneti e Leon Augusto Okida Gonçalves

## Árvore B: arvore_b.h e arvore_b.c
### Leitura: iniciaB e montaArvoreB
São as funções que montam a árvore B a partir da string recebida.  
A função montaArvoreB trata a string recebida e a iniciaB cria o nó.  
O if() presente no código da função montaArvoreB trata os casos de nós vazios e o while serve para ler os caracteres que serão a chave do nó.

### Impressão: emOrdemB e imprimeB
A função emOrdemB faz a impressão em ordem da árvore B. A função imprimeB imprime a árvore B em formato de parêntesis.  
Na imprimeB, caso um nó seja nulo e seu irmão também, eles não são impressos.

### Outros: valorIndexB
Calcula o valor de indexação da árvore B, percorrendo os nós e somando as chaves.

## Árvore A: arvore_a.h e arvore_a.c
### Inclusão: inclusao e criaNo
A função de inclusão recebe uma árvore B e a inclui na árvore A.  
Se a árvore A for vazia, é criado um nó raiz. Caso contrário, percorre-se a árvore A até encontrar um nó nulo em que a inclusão possa ser feita.  
A criação do novo nó a ser incluído é feita na função criaNo.

### Busca: busca
A busca é feita com a comparação de valores de indexação. Além disso, são impressos os nós percorridos e seus valores de indexação.

### Impressão: iniciaImpressao e imprimeArvore
A função iniciaImpressao encapsula e chama a função recursiva imprimeArvore.  
A função imprimeArvore percorre os nós da árvore A e imprime suas chaves B e seus valores de indexação. Caso um nó seja nulo e seu irmão também, eles não são impressos.

### Remoção: Placeholder
placeholder

## Aplicação principal: busca.c
### Função de leitura: main
É iniciado um loop que para somente quando é lido um EOF.  
Usa-se o fgetc para ler o comando e o fgets para ler o parâmetro. O tamanho máximo do parâmetro é definido pela constante MAX, no cabeçalho do arquivo.  
O switch controla a decisão a ser tomada a partir do comando lido.