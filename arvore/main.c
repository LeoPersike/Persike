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
typedef struct arv Arv;

// Prototipos
Arv* inicializa(void);
Arv* cria(char c, Arv* sae, Arv* sad);
int vazia(Arv* a);
void imprime (Arv* a);


int main()
{
    Arv* a = cria('a',
                cria('b',inicializa(),cria('d', inicializa(), inicializa())
                ),
                cria('c',cria('e', inicializa(), inicializa()),cria('f', inicializa(), inicializa())));
    imprime(a);
    return 0;
}

/****************** Funcoes *******************/

// Funcoes
Arv* inicializa(void)
{
    return NULL;
}

Arv* cria(char c, Arv* sae, Arv* sad){
    Arv* p=(Arv*)malloc(sizeof(Arv));
    p->info = c;
    p->esq = sae;
    p->dir = sad;
    return p;
}

int vazia(Arv* a)
{
    return a==NULL;
}

void imprime (Arv* a)
{
    if (!vazia(a))
    {
        printf("%c ", a->info);
        imprime(a->esq);
        imprime(a->dir);
    }
}
