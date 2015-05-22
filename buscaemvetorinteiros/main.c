/*****************************************************
* Arquivo main.c - Exemplo com tipos de busca em vetor
* de inteiros
*
* Engenharia Eletronica
* Semestre 2015-1
*
* Desenvolvedor: Leonardo Persike Martins
* IFSC 2015
******************************************************/

#include <stdio.h>
#include <stdlib.h>

//Prototipos
int busca (int n, int* vet, int elem);
int busca_ord (int n, int* vet, int elem);
int busca_bin (int n, int* vet, int elem);
int busca_bin_rec (int n, int* vet, int elem);
int comp_int (const void* p1, const void* p2); // Funcao auxiliar do bsearch

#define N 10 // 10 elementos no vetor
int main()
{
    int vetor[10] = {8,4,9,6,3,1,2,0,5,7};
    int vetor_ord[10] = {0,1,2,3,4,5,6,7,8,9};
    printf("%d %d %d %d",busca(N,vetor,4),busca_ord(N,vetor_ord,7),busca_bin(N,vetor_ord,4),busca_bin_rec(N,vetor_ord,6));


    // Busca com bsearch da propria biblioteca do C
    int* p;
    int val = 7;
    p = (int*)bsearch(&val,vetor_ord,N,sizeof(int),comp_int);

    if (p == NULL)
        printf("\nElemento nao encontrado.\n");
    else
        printf("\nElemento encontrado no indice: %d\n",p-vetor_ord);

    return 0;
}

// Busca linear - Retorna o indice do vetor no qual o elemento foi encontrado
int busca (int n, int* vet, int elem)
{
    int i;
    for (i=0; i<n; i++) {
        if (elem == vet[i]) /* elemento encontrado */
            return i;
    }

    /* percorreu todo o vetor e não encontrou elemento */
    return -1;
}

// Busca assumindo que o vetor esta ordenado em ordem crescente - Retorna o indice do vetor no qual o elemento foi encontrado
int busca_ord (int n, int* vet, int elem)
{
    int i;
    for (i=0; i<n; i++) {
        if (elem == vet[i]) /* elemento encontrado */
            return i;
        else if (elem < vet[i]) /* interrompe busca */
            return -1;
    }

    /* percorreu todo o vetor e não encontrou elemento */
    return -1;
}

// Busca binaria - Retorna o indice do vetor no qual o elemento foi encontrado
int busca_bin (int n, int* vet, int elem)
{
    /* no inicio consideramos todo o vetor */
    int ini = 0;
    int fim = n-1;
    int meio;

    /* enquanto a parte restante for maior que zero */
    while (ini <= fim) {
        meio = (ini + fim) / 2;
        if (elem < vet[meio])
            fim = meio - 1; /* ajusta posicao final */
        else if (elem > vet[meio])
            ini = meio + 1; /* ajusta posicao inicial */
        else
            return meio;/* elemento encontrado */
    }

    /* não encontrou: restou parte de tamanho zero */
    return -1;
}

// Busca binaria recursiva - Retorna o indice do vetor no qual o elemento foi encontrado
int busca_bin_rec (int n, int* vet, int elem)
{
    /* testa condição de contorno: parte com tamanho zero */
    if (n <= 0)
        return -1;
    else {
        /* deve buscar o elemento entre os índices 0 e n-1 */
        int meio = (n - 1) / 2;

        if (elem < vet[meio])
            return busca_bin_rec(meio,vet,elem);
        else if (elem > vet[meio])
        {
            int r = busca_bin_rec(n-1-meio, &vet[meio+1],elem);
            if (r<0) return -1;
            else return meio+1+r;
        }
        else
        return meio;/* elemento encontrado */
    }
}

/* função de comparação de inteiros para o bsearch*/
int comp_int (const void* p1, const void* p2)
{
    /* converte ponteiros genéricos para ponteiros de int */
    int *i1 = (int*)p1;
    int *i2 = (int*)p2;
    /* dados os ponteiros de int, faz a comparação */
    if (*i1 < *i2) return -1;
    else if (*i1 > *i2) return 1;
    else return 0;
}
