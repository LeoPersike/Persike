/************************************************************
* Arquivo Functions.c - Exercicio fila com lista encadeada
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
void push(Lista** fila,float data,int* quant) // Adiciona item na pilha
{
    // Testa se a pilha esta cheia
    if((*quant) >= MAX_DATA)
    {
        printf("\n---------- Fila cheia ---------- ");
    }
    else
    {
        Lista* novo = (Lista*) malloc(sizeof(Lista));
        if (novo == NULL) exit(EXIT_FAILURE); // nao ha mais espaco na memoria

        (*quant)++;// +1 dado na pilha

        novo->dado = data;
        novo->prox = *fila;
        *fila = novo; // aponta para o novo item da lista
    }
}

float pop(Lista** fila,int* quant) // Retorna e remove item da pilha
{
    Lista* pointer = *fila;
    Lista* save = *fila;

    while(pointer->prox!=NULL) // Ultimo elemento
    {
        save = pointer; // Salva ultimo endereço para redirecionar como ultimo elemento
        pointer = pointer->prox;
    }

    // Armazena o dado desejado, desaloca o primeiro elemento, redireciona o ponteiro prox do elemento anterior para NULL (ele vira o primeiro da fila agora)
    float dado = pointer->dado;
    free(pointer);
    save->prox = NULL;
    (*quant)--; // -1 dado na pilha

    return dado;
}

void imprime_fila(Lista* fila,int quant)
{
    Lista* point = fila;
    while(point!=NULL)
    {
        printf("\nEndereco: %p | Item %d: %.2f | Endereco proximo: %p ",point,quant,point->dado,point->prox);
        point = point->prox; // Aponta para o proximo
        quant--;
    }
}
