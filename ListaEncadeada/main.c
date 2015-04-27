/*****************************************************
* Arquivo main.c - Exercicio lista encadeada
*
* Engenharia Eletronica
* Semestre 2015-1
*
* Desenvolvedor: Leonardo Persike Martins
* IFSC 2015
******************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "Functions.h"

int main()
{
    printf("Tamanho de um elemento da lista: %ld\n",sizeof(Lista));
    char url[] = "dados.txt";

    Lista* lst = NULL; // Cria um ponteiro que aponta para o primeiro elemento da lista (ultimo adicionado) -- Ultimo elemento da lista aponta para NULL

    printf("\nLeitura do arquivo\n");
    leArquivo(url,&lst);
    imprime(lst);

    printf("\nInserindo 47 ordenadamente\n");
    insere_ord(47,&lst);
    imprime(lst);

    printf("\nRetirando 50\n");
    retira(50,&lst);
    imprime(lst);

    printf("\nBuscando endereco que possui elemento 492.\n");
    printf("%p",busca(492,lst));

    printf("\nImprimindo de forma recursiva.\n");
    imprime_rec(lst);

    libera(lst);

    return 0;
}


