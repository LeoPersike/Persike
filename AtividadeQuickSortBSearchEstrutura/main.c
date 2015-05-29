/*****************************************************
* Arquivo main.c - Ordenamento quicksort generico com
* ponteiro para funcao de comparacao
*
* Exercicios (separados por versao no GitHub):
* 1. Criar um vetor de elementos geométricos (círculo, na primeira versão). Círculo deve ser definido com uma estrutura.
* 2. Ordená-los pela coordenada do centro. Organizar como se fosse fazer a varredura da tela, ou seja, y tem prioridade
* sobre x e o eixo y cresce de cima para baixo. Exemplo, três círculos com centros (2,2), (20,10) e (5, 60) estão ordenados.
* 3. Buscar, usando bsearch, um elemento a partir da coordenada do centro.
* 4. Comparar, para diferentes tamanhos do conjunto de dados, bsearch com busca linear (que você deve implementar). Crie
* uma função para preencher o vetor. Teste com 50, 500 e 5000
* elementos. Use as funções em time.h para medir o tempo de processamento.
* 5. Incluir um campo nome (vetor de char) na estrutura do círculo.
* 6. Ordená-los por ordem alfabética do nome.
* 7. Fazer uma busca por nome do círculo.
*
* Engenharia Eletronica
* Semestre 2015-1
*
* Desenvolvedor: Leonardo Persike Martins
* IFSC 2015
******************************************************/

/***************** Includes *****************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/***************** Defines *****************/
#define N 5000
//#define MANUAL_INPUT

/***************** Definicao de estruturas *****************/
struct circulo {
    int cx;
    int cy;
};
typedef struct circulo Circle;

/***************** Prototipo de funcoes *****************/
int compara_centro(const void* p1,const void* p2);
int busca_linear(int num,const void* p1,const void* p2);
void preencher_vetor(int num,void* p1);

/***************** Main *****************/
int main()
{
    /* Variaveis para calculo de tempo nas funcoes*/
    clock_t start, end;
    double time_spent;
    /* Vetor de estrutura circulo */
    Circle circulos[N];
    /* Estrutura para ser utilizada como parametro de busca */
    Circle valor_busca;
    #ifdef MANUAL_INPUT // Busca circulo determinado
    valor_busca.cx = 70;
    valor_busca.cy = 100;
    #else // Busca o penultimo circulo (pois N-1 = circulo[4999] que e o ultimo
    valor_busca.cx = N-2;
    valor_busca.cy = N-2;
    #endif

    /* Adicionando os circulos */
    #ifdef MANUAL_INPUT
    //(40,60)
    circulos[0].cx = 40;
    circulos[0].cy = 60;
    //(200,200)
    circulos[1].cx = 200;
    circulos[1].cy = 100;
    //(70,100)
    circulos[2].cx = 70;
    circulos[2].cy = 100;
    //(30,80)
    circulos[3].cx = 30;
    circulos[3].cy = 80;
    //(150,45)
    circulos[4].cx = 150;
    circulos[4].cy = 45;
    #else
    preencher_vetor(N,circulos);
    #endif

    /* Organizando os circulos com qsort */
    qsort(circulos,N,sizeof(Circle),compara_centro);

    /* Buscar circulo pelo centro com bsearch */
    Circle* ptr;
    start = clock();
    ptr = bsearch(&valor_busca,circulos,N,sizeof(Circle),compara_centro);
    end = clock();
    time_spent = ((double) (end - start)) / CLOCKS_PER_SEC;
    if (ptr == NULL)
        printf("\nElemento nao encontrado com bsearch. Tempo gasto %f segundos.",time_spent);
    else
        printf("\nElemento encontrado com bsearch no indice %ld. Tempo gasto %f segundos.",ptr-circulos,time_spent);

    /* Buscar circulo com busca linear */
    int indice_encontrado;
    start = clock();
    indice_encontrado = busca_linear(N,&valor_busca,circulos);
    end = clock();
    time_spent = ((double) (end - start)) / CLOCKS_PER_SEC;
    if (indice_encontrado == -1)
        printf("\nElemento nao encontrado com busca linear. Tempo gasto %f segundos.",time_spent);
    else
        printf("\nElemento encontrado com busca linear no indice %d. Tempo gasto %f segundos.", indice_encontrado,time_spent);
    return 0;
}

/***************** Funcoes *****************/
/* Funcao de comparacao de centro para quicksorte e bsearch */
int compara_centro (const void* p1,const void* p2)
{
    Circle* c1 = (Circle*) p1;
    Circle* c2 = (Circle*) p2;

    if((c1->cy) < (c2->cy)) return -1; // Verifica Y
    else if((c1->cy) > (c2->cy)) return 1; // Verifica Y
    else if((c1->cx) < (c2->cx)) return -1; // Verifica X
    else if((c1->cx) > (c2->cx)) return 1; // Verifica X
    else return 0;
}

/* Funcao de busca linear de um circulo pelo centro */
int busca_linear(int num,const void* p1,const void* p2) // N = numero de dados, p1 = estrutura de comparacao, p2 = endereco do primeiro elemento do vetor
{
    Circle* comp = (Circle*) p1;
    Circle* circulos = (Circle*) p2;
    int aux;
    for(aux=0;aux<num;aux++)
    {
        if(circulos[aux].cx == comp->cx)
            if(circulos[aux].cy == comp->cy)
                return aux;
    }
    return -1;
}

/* Funcao para preencher vetor */
void preencher_vetor(int num,void* p1)
{
    Circle* circulos = (Circle*) p1;
    int aux;
    for(aux=0;aux<num;aux++)
    {
        circulos[aux].cx = aux;
        circulos[aux].cy = aux;
    }
}
