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
void imprime_preordem(Arvore* a);
void imprime_simetrico(Arvore* a);
void imprime_posordem(Arvore* a);
int altura(Arvore* a);
int busca (Arvore* a, char c);

int main()
{
    char var_busca = 'd';
    Arvore* a = cria('a',
                cria('b',inicializa(),cria('d', inicializa(), inicializa())
                ),
                cria('c',cria('e', inicializa(), inicializa()),cria('f', inicializa(), inicializa())));
    printf("Impressao normal.\n");
    imprime(a);
    printf("Pre-ordem\n");
    imprime_preordem(a);
    printf("Simetrico\n");
    imprime_simetrico(a);
    printf("Pos-Ordem\n");
    imprime_posordem(a);
    printf("\nA altura da arvore e: %d.",altura(a));
    printf("\nElemento a ser buscado %c. ",var_busca);
    if(busca(a,var_busca))
        printf("Elemento encontrado.");
    else
        printf("Elemento nao encontrado.");

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

// Funcao para imprimir a arvore com a estrutura em ordem raiz-esquerda-direita (Pre-Ordem)
void imprime_preordem(Arvore* a)
{
    printf("<");
    if (!vazia(a))
    {
        printf("%c",a->info);
        if(!vazia(a->esq))
            imprime_preordem(a->esq);
        else
            printf("<>");

        if(!vazia(a->dir))
            imprime_preordem(a->dir);
        else
            printf("<>");
    }
    printf(">");
}

// Funcao para imprimir a arvore com a estrutura em ordem esquerda-raiz-direita (Ordem Simetrica)
void imprime_simetrico(Arvore* a)
{
    printf("<");
    if (!vazia(a))
    {
        if(!vazia(a->esq))
            imprime_simetrico(a->esq);
        else
            printf("<>");

        printf("%c",a->info);

        if(!vazia(a->dir))
            imprime_simetrico(a->dir);
        else
            printf("<>");
    }
    printf(">");
}

// Funcao para imprimir a arvore com a estrutura em ordem esquerda-direita-raiz (Pos-Ordem)
void imprime_posordem(Arvore* a)
{
    printf("<");
    if (!vazia(a))
    {
        if(!vazia(a->esq))
            imprime_simetrico(a->esq);
        else
            printf("<>");

        if(!vazia(a->dir))
            imprime_simetrico(a->dir);
        else
            printf("<>");

         printf("%c",a->info);
    }
    printf(">");
}

// Funcao que retorna a altura de uma arvore
int altura(Arvore* a)
{
    if (vazia(a))
        return 0;
    else
    {
        int alt_esq = altura(a->dir);
        int alt_dir = altura(a->esq);

        if(alt_esq > alt_dir)
            return alt_esq + 1;
        else
            return alt_dir + 1;
    }
}

// Funcao que busca um elemento na arvore - Retorna 1 para encontrado e 0 para nao encontrado
int busca (Arvore* a, char c){
    if (vazia(a)) /* árvore vazia: não encontrou */
        return 0;
    else
        return a->info==c || busca(a->esq,c) || busca(a->dir,c);
}
