/*****************************************************
* Arquivo main.c - Ordenamento quicksort generico com
* ponteiro para funcao de comparacao
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

// Prototipos
int compara_float (const void* a,const void* b);
int compara_int (const void* a,const void* b);
int compara_char (const void* a,const void* b);

#define N 10 // Numero de elementos nos vetores

int main()
{
    int aux;
    // Vetores teste
    int vec_int[10] = {2,5,3,4,9,8,5,4,1,3};
    float vec_float[10] = {2.3,4.3,6.7,1.2,2.9,3.0,3.6,9.4,2.5,7.8};
    char vec_char[10] = {'b','t','h','d','a','f','l','e','n','m'};
    printf("\nVetores desordenados:\n\tInteiros:\n ");
    // Imprimindo vetores
    for(aux=0;aux<10;aux++)
    {
        printf("%d ",vec_int[aux]);
    }
    printf("\n\tReais\n ");
    for(aux=0;aux<10;aux++)
    {
        printf("%.1f ",vec_float[aux]);
    }
    printf("\n\tCaracteres\n ");
    for(aux=0;aux<10;aux++)
    {
        printf("%c ",vec_char[aux]);
    }

    // Ordenando
    qsort(vec_float,N,sizeof(float),compara_float);
    qsort(vec_int,N,sizeof(int),compara_int);
    qsort(vec_char,N,sizeof(char),compara_char);
    // Imprimindo vetores
    printf("\nVetores ordenados:\n\tInteiros:\n ");
    for(aux=0;aux<10;aux++)
    {
        printf("%d ",vec_int[aux]);
    }
    printf("\n\tReais\n ");
    for(aux=0;aux<10;aux++)
    {
        printf("%.1f ",vec_float[aux]);
    }
    printf("\n\tCaracteres\n ");
    for(aux=0;aux<10;aux++)
    {
        printf("%c ",vec_char[aux]);
    }

    return 0;
}

// Funcoes de comparacao
int compara_float (const void* a,const void* b)
{
    float* p1 = (float*) a;
    float* p2 = (float*) b;
    if (*p1 > *p2)
        return 1;
    else
        if(*p1 < *p2)
            return -1;
        else
            return 0;
}

int compara_int (const void* a,const void* b)
{
    int* p1 = (int*) a;
    int* p2 = (int*) b;
    if (*p1 > *p2)
        return 1;
    else
        if(*p1 < *p2)
            return -1;
        else
            return 0;
}

int compara_char (const void* a,const void* b)
{
    char* p1 = (char*) a;
    char* p2 = (char*) b;
    return strcmp(p1,p2); // Retorna 1 para maior, 0 para igual e -1 para menor (primeira letra diferente)
}
