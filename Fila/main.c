/*****************************************************
* Arquivo main.c - Exercicio fila com lista encadeada
*
* Engenharia Eletronica
* Semestre 2015-1
*
* Desenvolvedor: Leonardo Persike Martins
* IFSC 2015
******************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main()
{
    Fila* f = cria();
    insere(f,20.0);
    insere(f,20.8);
    insere(f,21.2);
    insere(f,24.3);
    printf("Primeiro elemento: %.2f\n", retira(f));
    printf("Segundo elemento: %.2f\n", retira(f));
    printf("Configuracao da fila:\n");
    imprime(f);
    libera(f);

    return 0;
}
