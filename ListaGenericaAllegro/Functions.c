/************************************************************
* Arquivo Functions.c - Exercicio lista encadeada generica
*
* Engenharia Eletronica
* Semestre 2015-1
*
* Desenvolvedor: Leonardo Persike Martins
* IFSC 2015
************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "Functions.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

#define PI 3.14159265
//********* Funcoes *************
void insere_retangulo(float x1,float y1,float x2,float y2,float corR,float corG,float corB,float thick,ListaGen** Lista) // Insere um retangulo na lista
{
    ListaGen* novo = (ListaGen*) malloc(sizeof(ListaGen));
    if (novo == NULL) exit(EXIT_FAILURE); // nao ha mais espaco na memoria

    retangulo* retnovo = (retangulo*) malloc(sizeof(retangulo));
    if (retnovo == NULL) exit(EXIT_FAILURE); // nao ha mais espaco na memoria

    retnovo->x1 = x1;
    retnovo->y1 = y1;
    retnovo->x2 = x2;
    retnovo->y2 = y2;
    retnovo->colorR = corR;
    retnovo->colorG = corG;
    retnovo->colorB = corB;
    retnovo->thickness = thick;

    novo->tipo = RET; // 1 = Retangulo
    novo->info = retnovo;
    novo->prox = *Lista;
    *Lista = novo; // aponta para o novo item da lista
}

void insere_circulo(float x,float y,float r,float corR,float corG,float corB,float thick,ListaGen** Lista)
{
    ListaGen* novo = (ListaGen*) malloc(sizeof(ListaGen));
    if (novo == NULL) exit(EXIT_FAILURE); // nao ha mais espaco na memoria

    circulo* circnovo = (circulo*) malloc(sizeof(circulo));
    if (circnovo == NULL) exit(EXIT_FAILURE); // nao ha mais espaco na memoria

    circnovo->cx = x;
    circnovo->cy = y;
    circnovo->r = r;
    circnovo->colorR = corR;
    circnovo->colorG = corG;
    circnovo->colorB = corB;
    circnovo->thickness = thick;

    novo->tipo = CIRC; // 1 = Retangulo
    novo->info = circnovo;
    novo->prox = *Lista;
    *Lista = novo; // aponta para o novo item da lista
}

void imprime_lista(ListaGen* Lista)
{
    ListaGen* pointList = Lista;
    retangulo* pointRet;
    circulo* pointCirc;
    while(pointList!=NULL)
    {
        if(pointList->tipo == RET)
        {
            pointRet = pointList->info;
            printf("\nRetangulo: Coordenadas inferior esquerda (%.2f,%.2f) e superior direita (%.2f,%.2f)",pointRet->x1,pointRet->y1,pointRet->x2,pointRet->y2);
            printf("\nCor R: %.1f - G: %.1f - B: %.2f --- Thickness: %.2f\n",pointRet->colorR,pointRet->colorG,pointRet->colorB,pointRet->thickness);
        }


        if(pointList->tipo == CIRC)
        {
            pointCirc = pointList->info;
            printf("\nCirculo: Coordenada do centro (%.2f,%.2f), raio %.2f",pointCirc->cx,pointCirc->cy,pointCirc->r);
            printf("\nCor R: %.1f - G: %.1f - B: %.2f --- Thickness: %.2f\n",pointCirc->colorR,pointCirc->colorG,pointCirc->colorB,pointCirc->thickness);
        }

        pointList = pointList->prox; // Aponta para o proximo
    }
}

void imprime_lista_display(ListaGen* Lista)
{
    ListaGen* pointList = Lista;
    retangulo* pointRet;
    circulo* pointCirc;
    while(pointList!=NULL)
    {
        if(pointList->tipo == RET)
        {
            pointRet = pointList->info;
            al_draw_rectangle(pointRet->x1,pointRet->y1,pointRet->x2,pointRet->y2,al_map_rgb(pointRet->colorR,pointRet->colorG,pointRet->colorB),pointRet->thickness);
        }


        if(pointList->tipo == CIRC)
        {
            pointCirc = pointList->info;
            al_draw_circle(pointCirc->cx,pointCirc->cy,pointCirc->r,al_map_rgb(pointCirc->colorR,pointCirc->colorG,pointCirc->colorB),pointCirc->thickness);
        }

        pointList = pointList->prox; // Aponta para o proximo
    }
}
