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

#define N 5 // Numero de elementos nos vetores

int main()
{
    Circulo circulos[N];

    return 0;
}