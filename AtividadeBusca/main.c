/*****************************************************
* Arquivo main.c - Ordenamento quicksort generico com
* ponteiro para funcao de comparacao
*
* Exercicios (separados por versao no GitHub):
* 1. Criar um vetor de elementos geométricos (círculo, na primeira versão). Círculo deve ser definido com uma estrutura.
* 2. Ordená-los pela coordenada do centro. Organizar como se fosse fazer a varredura da tela, ou seja, y tem prioridade sobre x e o eixo y cresce de cima para baixo. Exemplo,
* três círculos com centros (2,2), (20,10) e (5, 60) estão ordenados.
* 3. Buscar, usando bsearch, um elemento a partir da coordenada do centro.
* 4. Comparar, para diferentes tamanhos do conjunto de dados, bsearch com busca linear (que você deve implementar). Crie uma função para preencher o vetor. Teste com 50, 500 e 5000
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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definicao de estrutura
struct circulo {
    int cx;
    int cy;
};
typedef struct circulo Circulo;

// Prototipos
int compara_centro (const void* a,const void* b);

#define N 5 // Numero de elementos

int main()
{
    Circulo circulos[N];
    int aux;
    // Adicionando os circulos
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

    // Imprimindo os circulos
    printf("\nImpressao sem ordenamento");
    for(aux=0;aux<N;aux++)
        printf("\n Circulo %d. Centro em (%d,%d).",aux+1,circulos[aux].cx,circulos[aux].cy);
    // Ordenando os circulos
    qsort(circulos,N,sizeof(Circulo),compara_centro);
    printf("\nImpressao depois de ordenamento generico quicksort");
    for(aux=0;aux<N;aux++)
        printf("\n Circulo %d. Centro em (%d,%d).",aux+1,circulos[aux].cx,circulos[aux].cy);

    return 0;
}


int compara_centro (const void* a,const void* b)
{
    Circulo* c1 = (Circulo*) a;
    Circulo* c2 = (Circulo*) b;

    if(c1->cy < c2->cy) // Nao precisa trocar pois y1 < y2
        return 0;
    else if (c1->cy == c2->cy) // Se os y sao iguais verificar o x
    {
        if (c1->cx < c2->cx) // Nao precisa trocar pois y1 = y2 e x1 < x2
            return 0;
        else             // Troca pois y1 = y2 e x1 > x2
            return 1;
    }
    else return 1; // Troca pois y1 > y2

}
