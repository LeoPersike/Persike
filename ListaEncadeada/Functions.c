/*****************************************************
* Arquivo Functions.c - Exercicio lista encadeada
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

//********* Funcoes *************

//********* Insere *************
void insere(int dado,Lista** lst)
{
    Lista* novo = (Lista*) malloc(sizeof(Lista));
    if (novo == NULL) exit(EXIT_FAILURE); // nao ha mais espaco na memoria
    novo->dado = dado;
    novo->prox = *lst; // recebe para onde o ponteiro lst estava apontando
    *lst = novo; // aponta para o novo item da lista
}

//********* Insere  ordenadamente *************
void insere_ord(int value,Lista** lst)
{
    Lista* novo = (Lista*) malloc(sizeof(Lista));
    if (novo == NULL) exit(EXIT_FAILURE); // nao ha mais espaco na memoria

    Lista* ant = NULL;
    Lista* p = *lst;

    // procura posicao que ira o elemento, guardando anterior
    while (p != NULL && p->dado > value)
    {
        ant = p;
        p = p->prox;
    }

    novo->dado = value;
    novo->prox = p;
    ant->prox = novo;

}

//********* Libera *************
void libera(Lista* lst)
{
    Lista* p = lst;
    while(p != NULL)
    {
        Lista* t=p->prox;
        free(p);
        p = t;
    }
}

//********* Imprime *************
void imprime(Lista* lst)
{
    Lista *p;
    int k=0;
    for(p=lst; p!=NULL; p=p->prox)
    {
        printf("Item: %d | END: %p | Dado: %5d | Prox: %p\n",k,p,p->dado,p->prox);
        k++;
    }
}

/* Função imprime recursiva */
void imprime_rec(Lista* lst)
{
    if(lst == NULL)
        return;
    // imprime primeiro elemento
    printf("info: %d\n",lst->dado);
    // imprime sub-lista
    imprime_rec(lst->prox);
}

//********* Busca *************
Lista* busca(int value,Lista* lst)
{
    Lista *p;
    for(p=lst; p!=NULL; p=p->prox)
    {
        if(value == p->dado)
            break;
    }
    return p;
}


//********* Funcao retira elemento da lista *************
void retira(int v,Lista** lst)
{
    Lista* ant = NULL;
    Lista* p = *lst;

    // procura elemento na lista, guardando anterior
    while (p != NULL && p->dado != v)
    {
        ant = p;
        p = p->prox;
    }

    // retira elemento
    if (ant == NULL)
    {
        // retira elemento do inicio
        *lst = p->prox;
    }
    else
    {
        // retira elemento do meio da lista
        ant->prox = p->prox;
    }

    free(p);
}

//********* leArquivo *************
void leArquivo(char url[],Lista** lst)
{
    FILE *arq;
    int aux;

    arq = fopen(url, "r");
	if(arq == NULL)
	    printf("Erro, nao foi possivel abrir o arquivo\n");
	else
        while((fscanf(arq,"%d\n",&aux))!=EOF)
        {
            insere(aux,lst);
        }
	fclose(arq);
}
