/*****************************************************
* Arquivo main.c - Exercicios utilizando arvore
*
* Engenharia Eletronica
* Semestre 2015-1
*
* Programador: Leonardo Persike Martins
* IFSC 2015
******************************************************/

#include <stdio.h>
#include <stdlib.h>

struct arv {
    char info;
    struct arv* esq;
    struct arv* dir;
};
typedef struct arv Arvore;

// Prototipos
Arvore* inicializa(void);
Arvore* cria(char c, Arvore* sae, Arvore* sad);
int vazia(Arvore* a);
void imprime (Arvore* a);
void imprime_estrutura (Arvore* a);


int main()
{
    Arvore* a = cria('a',
                cria('b',inicializa(),cria('d', inicializa(), inicializa())
                ),
                cria('c',cria('e', inicializa(), inicializa()),cria('f', inicializa(), inicializa())));
    imprime(a);
    printf("\n");
    imprime_estrutura(a);
    return 0;
}

/****************** Funcoes *******************/
// Funcao para inicializar uma arvore vazia
Arvore* inicializa(void)
{
    return NULL;
}

// Funcao para criar uma arvore com informacao e sub arvores
Arvore* cria(char c, Arvore* sae, Arvore* sad){
    Arvore* p=(Arvore*)malloc(sizeof(Arvore));
    p->info = c;
    p->esq = sae;
    p->dir = sad;
    return p;
}

// Funcao para checar se a lista esta vazia
int vazia(Arvore* a)
{
    return a==NULL;
}

// Funcao para imprimir o conteudo da arvore
void imprime(Arvore* a)
{
    if (!vazia(a))
    {
        printf("%c ", a->info);
        imprime(a->esq);
        imprime(a->dir);
    }
}

// Funcao para imprimir a arvore com a estrutura <<>><><><><>
void imprime_estrutura(Arvore* a)
{
    printf("<");
    if (!vazia(a))
    {
        printf("%c",a->info);
        if(!vazia(a->esq))
            imprime_estrutura(a->esq);
        else
            printf("<>");

        if(!vazia(a->dir))
            imprime_estrutura(a->dir);
        else
            printf("<>");
    }
    printf(">");
}
