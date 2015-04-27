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
    int quantidade_dados = 0;
    Lista* fila;

    push(&fila,10,&quantidade_dados);
    push(&fila,20,&quantidade_dados);
    push(&fila,30,&quantidade_dados);
    push(&fila,40,&quantidade_dados);
    imprime_fila(fila,quantidade_dados);

    printf("\nDando pop na fila: %.2f",pop(&fila,&quantidade_dados));
    printf("\nDando pop na fila: %.2f",pop(&fila,&quantidade_dados));
    imprime_fila(fila,quantidade_dados);

    return 0;
}


