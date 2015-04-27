/************************************************************
* Arquivo Functions.c - Exercicio pilha com lista encadeada
*
* Engenharia Eletronica
* Semestre 2015-1
*
* Desenvolvedor: Leonardo Persike Martins
* IFSC 2015
************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

// Maxima quantidade de dados na pilha
#define MAX_DATA 20

// Funcoes
void push(Lista** pilha,float data,int* quant) // Adiciona item na pilha
{
    // Testa se a pilha esta cheia
    if((*quant) >= MAX_DATA)
    {
        printf("\n---------- Pilha cheia ---------- ");
    }
    else
    {
        Lista* novo = (Lista*) malloc(sizeof(Lista));
        if (novo == NULL) exit(EXIT_FAILURE); // nao ha mais espaco na memoria

        (*quant)++;// +1 dado na pilha

        novo->dado = data;
        novo->prox = *pilha;
        *pilha = novo; // aponta para o novo item da lista
    }
}

float pop(Lista** pilha,int* quant) // Retorna e remove item da pilha
{
    Lista* pointer = *pilha;
    float dado = (*pilha)->dado;

    *pilha = (*pilha)->prox;
    (*quant)--; // -1 dado na pilha

    free(pointer);
    return dado;
}

void imprime_pilha(Lista* pilha,int quant)
{
    Lista* point = pilha;
    while(point!=NULL)
    {
        printf("\nEndereco: %p | Item %d: %.2f | Endereco proximo: %p ",point,quant,point->dado,point->prox);
        point = point->prox; // Aponta para o proximo
        quant--;
    }
}
