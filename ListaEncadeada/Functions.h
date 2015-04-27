/*****************************************************
* Arquivo Functions.h - Exercicio lista encadeada
*
* Engenharia Eletronica
* Semestre 2015-1
*
* Desenvolvedor: Leonardo Persike Martins
* IFSC 2015
******************************************************/

//********* Definicao de dados *************
typedef struct lista Lista;
struct lista {
    int dado;
    Lista* prox;
};

// Prototipos
void insere(int dado,Lista** lst); // Insere um elemento na lista
void insere_ord(int value,Lista** lst); // Insere um ordenadamente
void libera(Lista* lst); // Libera a lista (esvazia a memoria alocada dinamicamente)
void imprime(Lista* lst); // Imprime a lista
void imprime_rec (Lista* lst); // Imprime a lista recursivamente
Lista* busca(int value,Lista* lst); // Retorna o endereco do elemento
void retira(int v,Lista** lst); // Busca e retira o elemento da lista
void leArquivo(char url[],Lista** lst); // Le o arquivo e salva na lista
