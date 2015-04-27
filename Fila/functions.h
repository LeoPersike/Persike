/************************************************************
* Arquivo Functions.h - Exercicio fila com lista encadeada
*
* Engenharia Eletronica
* Semestre 2015-1
*
* Desenvolvedor: Leonardo Persike Martins
* IFSC 2015
************************************************************/

//********* Definicao de dados *************
typedef struct lista Lista; // Lista generica
struct lista {
    float dado;
    Lista* prox;
};

// Prototipagem das funcoes
void push(Lista** fila,float data,int* quant);
float pop(Lista** fila,int* quant);
void imprime_fila(Lista* fila,int quant);
