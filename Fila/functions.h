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
typedef struct no No;
struct no {
    float info;
    No* prox;
};

typedef struct fila Fila;
struct fila {
    No* ini;
    No* fim;
};

// Prototipagem das funcoes
Fila* cria (void);
No* ins_fim (No* fim, float v);
No* ret_ini (No* ini);
void insere (Fila* f, float v);
float retira (Fila* f);
int vazia (Fila* f);
void libera (Fila* f);
void imprime (Fila* f);
