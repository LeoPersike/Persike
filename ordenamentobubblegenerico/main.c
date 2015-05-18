/*****************************************************
* Arquivo main.c - Ordenamento Bubble Generico com
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
void bolha_gen (void* v, int n, int tam, int(*cmp)(const void*,const void*));
void* acessa (void* v, int i, int tam);
void troca (void* a, void* b, int tam);
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
    bolha_gen(vec_float,N,sizeof(float),compara_float);
    bolha_gen(vec_int,N,sizeof(int),compara_int);
    bolha_gen(vec_char,N,sizeof(char),compara_char);
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

/* Ordenação bolha (genérica) */
void bolha_gen (void* v, int n, int tam, int(*cmp)(const void*,const void*))
{
    int i, j;
    for (i=n-1; i>0; i--) {
        int fez_troca = 0;
        for (j=0; j<i; j++) {
            void* p1 = acessa(v,j,tam);
            void* p2 = acessa(v,j+1,tam);
            if (cmp(p1,p2))
                troca(p1,p2,tam);
                fez_troca = 1;
            }
        if (fez_troca == 0) /* nao houve troca */
            return;
    }
}

void* acessa (void* v, int i, int tam)
{
    char* t = (char*)v;
    t += tam*i;
    return (void*)t;
}

void troca (void* a, void* b, int tam)
{
    char* v1 = (char*) a;
    char* v2 = (char*) b;
    int i;
    for (i=0; i<tam; i++) {
        char temp = v1[i];
        v1[i] = v2[i];
        v2[i] = temp;
    }
}

int compara_float (const void* a,const void* b)
{
    float* p1 = (float*) a;
    float* p2 = (float*) b;
    if (*p1 > *p2)
        return 1;
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
        return 0;
}

int compara_char (const void* a,const void* b)
{
    char* p1 = (char*) a;
    char* p2 = (char*) b;
    return strcmp(p1,p2);
}
