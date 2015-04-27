 /************************************************************
* Arquivo Functions.h - Exercicio lista duplamente encadeada generica
*
* Engenharia Eletronica
* Semestre 2015-1
*
* Desenvolvedor: Leonardo Persike Martins
* IFSC 2015
************************************************************/

//********* Definicoes utilizadas *************
#define RET 1
#define CIRC 2

//********* Definicao de dados *************
// Define o nó da estrutura
typedef struct listagen ListaGen; // Lista generica
struct listagen {
    int tipo; // 1 = Retangulo ; 2 = Circulo
    void *info; // Ponteiro que aponta para o retangulo ou circulo
    ListaGen* prox;
    ListaGen* ant;
};

// Define a estrutura retangulo
typedef struct rectangle retangulo;
struct rectangle {
    //(x1,y1) = upper left
    //(x2,y2) = lower right
    float x1;
    float y1;
    float x2;
    float y2;
    float colorR;
    float colorG;
    float colorB;
    float thickness; // 0 = hairline
};

// Define a estrutura circulo
typedef struct circle circulo;
struct circle {
    //(cx,cy) = center of the circle
    float cx;
    float cy;
    float r; // Radius
    float colorR;
    float colorG;
    float colorB;
    float thickness; // 0 = hairline
};

// Prototipagem das funcoes
void insere_retangulo(float x1,float y1,float x2,float y2,float corR,float corG,float corB,float thick,ListaGen** Lista);
void insere_circulo(float x,float y,float r,float corR,float corG,float corB,float thick,ListaGen** Lista);
void imprime_lista(ListaGen* Lista);
void imprime_lista_display(ListaGen* Lista);
