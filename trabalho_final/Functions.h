/************************************************************
* Arquivo Functions.h - Exercicio lista encadeada generica
*
* Engenharia Eletronica
* Semestre 2015-1
*
* Desenvolvedor: Leonardo Persike Martins
* IFSC 2015
************************************************************/

//*********** Includes de bibliotecas ****************//
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_ttf.h>

#define PI 3.14159265
#define FPS 60

//********* Variaveis para marcacao de tempo *************//
clock_t begin, end;
double time_spent1,time_spent2,time_spent3;


//********* Definicoes para insercao e remocao *************/
#define LINE 0
#define TRIANGLE 1
#define RECTANGLE 2
#define ELIPSE 3
#define CIRCLE 4
#define ARC 5
#define SPLINE 6
#define RIBBON 7

//******** Definicoes para controle de estado *************/
// Control states
#define EXIT 0
#define WAITING 1
// Draw states
#define DRAW_LINE 2
#define DRAW_TRIANGLE 3
#define DRAW_RECTANGLE 4
#define DRAW_ELIPSE 5
#define DRAW_CIRCLE 6
#define DRAW_ARC 7
#define DRAW_SPLINE 8
#define DRAW_RIBBON 9
// Remove states
#define REMOVE_LINE 10
#define REMOVE_TRIANGLE 11
#define REMOVE_RECTANGLE 12
#define REMOVE_ELIPSE 13
#define REMOVE_CIRCLE 14
#define REMOVE_ARC 15
#define REMOVE_SPLINE 16
#define REMOVE_RIBBON 17

//********* Funcoes allegro draw **************/
// As funcoes podem ser encontradas no manual do allegro 5, disponivel em https://www.allegro.cc/manual/5/primitives.html
/*  Lembrando que thickness = 0 -> hairline
    al_draw_line(float x1, float y1, float x2, float y2,ALLEGRO_COLOR color, float thickness);
    al_draw_triangle(float x1, float y1, float x2, float y2,float x3, float y3, ALLEGRO_COLOR color, float thickness);
    al_draw_filled_triangle(float x1, float y1, float x2, float y2,float x3, float y3, ALLEGRO_COLOR color);
    al_draw_rectangle(float x1, float y1, float x2, float y2,ALLEGRO_COLOR color, float thickness)
    al_draw_filled_rectangle(float x1, float y1, float x2, float y2,ALLEGRO_COLOR color)
    al_draw_rounded_rectangle(float x1, float y1, float x2, float y2,float rx, float ry, ALLEGRO_COLOR color, float thickness)
    al_draw_filled_rounded_rectangle((float x1, float y1, float x2, float y2,float rx, float ry, ALLEGRO_COLOR color)
    al_calculate_arc(float* dest, int stride, float cx, float cy,float rx, float ry, float start_theta, float delta_theta, float thickness,   int num_segments)
    al_draw_ellipse((float cx, float cy, float rx, float ry,ALLEGRO_COLOR color, float thickness);
    al_draw_filled_ellipse(float cx, float cy, float rx, float ry,   ALLEGRO_COLOR color)
    al_draw_circle(float cx, float cy, float r, ALLEGRO_COLOR color,float thickness)
    al_draw_filled_circle(float cx, float cy, float r, ALLEGRO_COLOR color)
    al_draw_arc(float cx, float cy, float r, float start_theta,float delta_theta, ALLEGRO_COLOR color, float thickness)
    al_calculate_spline(float* dest, int stride, float points[8],float thickness, int num_segments)
    al_draw_spline(float points[8], ALLEGRO_COLOR color, float thickness)
    al_calculate_ribbon(float* dest, int dest_stride, const float *points,int points_stride, float thickness, int num_segments)
    al_draw_ribbon(const float *points, int points_stride, ALLEGRO_COLOR color,float thickness, int num_segments)
*/


//********* Definicao de dados para usar com as funcoes DRAW do allegro5 ************/
// Define o nó da estrutura
typedef struct listagen ListaGen; // Lista generica
struct listagen {
    int tipo; // Valor listado no comeco do codigo
    void *info; // Ponteiro que aponta para o tipo desejado
    ListaGen* prox;
    //ListaGen* ant;
};

// Define a estrutura linha
typedef struct line Linha;
struct line {
    float x1;
    float y1;
    float x2;
    float y2;
    float colorR;
    float colorG;
    float colorB;
    float thickness; // 0 = hairline
};

// Define a estrutura triangulo
typedef struct triangle Tri;
struct triangle {
    float x1;
    float y1;
    float x2;
    float y2;
    float x3;
    float y3;
    float colorR;
    float colorG;
    float colorB;
    float thickness; // 0 = hairline
};

// Define a estrutura retangulo
typedef struct rectangle Ret;
struct rectangle {
    //(x1,y1) = upper left
    //(x2,y2) = lower right
    float x1;
    float y1;
    float x2;
    float y2;
    float rx; // Apenas para retangulo arredondado
    float ry; // Apenas para retangulo arredondado
    float colorR;
    float colorG;
    float colorB;
    float thickness; // 0 = hairline
};

// Define a estrutura elipse
typedef struct elipse Elip;
struct elipse {
    float cx;
    float cy;
    float rx;
    float ry;
    float colorR;
    float colorG;
    float colorB;
    float thickness; // 0 = hairline
};

// Define a estrutura circulo
typedef struct circle Circ;
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

// Define a estrutura circulo
typedef struct arc Arco;
struct arc {
    //(cx,cy) = center of the arc
    float cx;
    float cy;
    float r; // Radius
    float start_theta;
    float delta_theta;
    float colorR;
    float colorG;
    float colorB;
    float thickness; // 0 = hairline
};

// Definir a estrutura SPLINE
// Definir a estrutura RIBBON

//********* Funcoes graficas *************//
int graphic_init(void);
void fechajanela(void);
void exibir_texto_centralizado(char msg[20]);
void atualiza_tela(bool *pause);

//******** Funcao principal do program ***********//
int cad_system(void);

//********* Prototipagem das funcoes ************/
void insere_linha(float x1,float y1,float x2,float y2,float corR,float corG,float corB,float thick,ListaGen** Lista);
void insere_triangulo(float x1,float y1,float x2,float y2,float x3,float y3,float corR,float corG,float corB,float thick,ListaGen** Lista);
void insere_retangulo(float x1,float y1,float x2,float y2,float rx, float ry,float corR,float corG,float corB,float thick,ListaGen** Lista);
void insere_elipse(float cx,float cy,float rx,float ry,float corR,float corG,float corB,float thick,ListaGen** Lista);
void insere_circulo(float cx,float cy,float r,float corR,float corG,float corB,float thick,ListaGen** Lista);
void insere_arco(float cx,float cy,float r,float start_theta,float delta_theta,float corR,float corG,float corB,float thick,ListaGen** Lista);
void imprime_lista(ListaGen* Lista);
void imprime_lista_display(ListaGen* Lista);
