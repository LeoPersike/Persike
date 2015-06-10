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
void insere_linha(float x1,float y1,float x2,float y2,float corR,float corG,float corB,float thick,ListaGen** Lista)
{
    ListaGen* novo = (ListaGen*) malloc(sizeof(ListaGen));
    if (novo == NULL) exit(EXIT_FAILURE); // nao ha mais espaco na memoria

    Linha* linhanovo = (Linha*) malloc(sizeof(Linha));
    if (linhanovo == NULL) exit(EXIT_FAILURE); // nao ha mais espaco na memoria

    linhanovo->x1 = x1;
    linhanovo->y1 = y1;
    linhanovo->x2 = x2;
    linhanovo->y2 = y2;
    linhanovo->colorR = corR;
    linhanovo->colorG = corG;
    linhanovo->colorB = corB;
    linhanovo->thickness = thick;

    novo->tipo = LINE; // 1 = Retangulo
    novo->info = linhanovo;
    novo->prox = *Lista;
    *Lista = novo; // aponta para o novo item da lista
}

void insere_triangulo(float x1,float y1,float x2,float y2,float x3,float y3,float corR,float corG,float corB,float thick,ListaGen** Lista)
{
    ListaGen* novo = (ListaGen*) malloc(sizeof(ListaGen));
    if (novo == NULL) exit(EXIT_FAILURE); // nao ha mais espaco na memoria

    Tri* trinovo = (Tri*) malloc(sizeof(Tri));
    if (trinovo == NULL) exit(EXIT_FAILURE); // nao ha mais espaco na memoria

    trinovo->x1 = x1;
    trinovo->y1 = y1;
    trinovo->x2 = x2;
    trinovo->y2 = y2;
    trinovo->x3 = x3;
    trinovo->y3 = y3;
    trinovo->colorR = corR;
    trinovo->colorG = corG;
    trinovo->colorB = corB;
    trinovo->thickness = thick;

    novo->tipo = TRIANGLE; // 1 = Retangulo
    novo->info = trinovo;
    novo->prox = *Lista;
    *Lista = novo; // aponta para o novo item da lista
}

void insere_retangulo(float x1,float y1,float x2,float y2,float rx,float ry,float corR,float corG,float corB,float thick,ListaGen** Lista) // Insere um retangulo na lista
{
    ListaGen* novo = (ListaGen*) malloc(sizeof(ListaGen));
    if (novo == NULL) exit(EXIT_FAILURE); // nao ha mais espaco na memoria

    Ret* retnovo = (Ret*) malloc(sizeof(Ret));
    if (retnovo == NULL) exit(EXIT_FAILURE); // nao ha mais espaco na memoria

    retnovo->x1 = x1;
    retnovo->y1 = y1;
    retnovo->x2 = x2;
    retnovo->y2 = y2;
    retnovo->rx = rx;
    retnovo->ry = ry;
    retnovo->colorR = corR;
    retnovo->colorG = corG;
    retnovo->colorB = corB;
    retnovo->thickness = thick;

    novo->tipo = RECTANGLE; // 1 = Retangulo
    novo->info = retnovo;
    novo->prox = *Lista;
    *Lista = novo; // aponta para o novo item da lista
}

void insere_elipse(float cx,float cy,float rx,float ry,float corR,float corG,float corB,float thick,ListaGen** Lista)
{
    ListaGen* novo = (ListaGen*) malloc(sizeof(ListaGen));
    if (novo == NULL) exit(EXIT_FAILURE); // nao ha mais espaco na memoria

    Elip* elipnovo = (Elip*) malloc(sizeof(Elip));
    if (elipnovo == NULL) exit(EXIT_FAILURE); // nao ha mais espaco na memoria

    elipnovo->cx = cx;
    elipnovo->cy = cy;
    elipnovo->rx = rx;
    elipnovo->ry = ry;
    elipnovo->colorR = corR;
    elipnovo->colorG = corG;
    elipnovo->colorB = corB;
    elipnovo->thickness = thick;

    novo->tipo = ELIPSE;
    novo->info = elipnovo;
    novo->prox = *Lista;
    *Lista = novo; // aponta para o novo item da lista
}

void insere_circulo(float cx,float cy,float r,float corR,float corG,float corB,float thick,ListaGen** Lista)
{
    ListaGen* novo = (ListaGen*) malloc(sizeof(ListaGen));
    if (novo == NULL) exit(EXIT_FAILURE); // nao ha mais espaco na memoria

    Circ* circnovo = (Circ*) malloc(sizeof(Circ));
    if (circnovo == NULL) exit(EXIT_FAILURE); // nao ha mais espaco na memoria

    circnovo->cx = cx;
    circnovo->cy = cy;
    circnovo->r = r;
    circnovo->colorR = corR;
    circnovo->colorG = corG;
    circnovo->colorB = corB;
    circnovo->thickness = thick;

    novo->tipo = CIRCLE;
    novo->info = circnovo;
    novo->prox = *Lista;
    *Lista = novo; // aponta para o novo item da lista
}

void insere_arco(float cx,float cy,float r,float start_theta,float delta_theta,float corR,float corG,float corB,float thick,ListaGen** Lista)
{
    ListaGen* novo = (ListaGen*) malloc(sizeof(ListaGen));
    if (novo == NULL) exit(EXIT_FAILURE); // nao ha mais espaco na memoria

    Arco* arconovo = (Arco*) malloc(sizeof(Arco));
    if (arconovo == NULL) exit(EXIT_FAILURE); // nao ha mais espaco na memoria

    arconovo->cx = cx;
    arconovo->cy = cy;
    arconovo->r = r;
    // A multiplicacao e feita para que o usuario entre com o angulo em graus e a funcao al_draw utiliza radianos
    arconovo->start_theta = start_theta*0.0174532925;
    arconovo->delta_theta = delta_theta*0.0174532925;
    arconovo->colorR = corR;
    arconovo->colorG = corG;
    arconovo->colorB = corB;
    arconovo->thickness = thick;

    novo->tipo = ARC;
    novo->info = arconovo;
    novo->prox = *Lista;
    *Lista = novo; // aponta para o novo item da lista
}

void imprime_lista(ListaGen* Lista)
{
    // Pontiero para a lista
    ListaGen* pointList = Lista;
    // Ponteiros para impressao
    Linha* pointLinha;
    Tri* pointTri;
    Ret* pointRet;
    Elip* pointElip;
    Circ* pointCirc;
    Arco* pointArco;

    // Percorre a lista
    while(pointList!=NULL)
    {
        switch(pointList->tipo)
        {
            case LINE:
                pointLinha = pointList->info;
                printf("\nLinha: Coordenadas (%.2f,%.2f) e (%.2f,%.2f)",pointLinha->x1,pointLinha->y1,pointLinha->x2,pointLinha->y2);
                printf("\nCor R: %.1f - G: %.1f - B: %.2f - Thickness: %.2f\n",pointLinha->colorR,pointLinha->colorG,pointLinha->colorB,pointLinha->thickness);
                break;
            case TRIANGLE:
                pointTri = pointList->info;
                printf("\nTriangulo: Coordenadas (%.2f,%.2f),(%.2f,%.2f) e (%.2f,%.2f).",pointTri->x1,pointTri->y1,pointTri->x2,pointTri->y2,pointTri->x3,pointTri->y3);
                printf("\nCor R: %.1f - G: %.1f - B: %.2f - Thickness: %.2f\n",pointTri->colorR,pointTri->colorG,pointTri->colorB,pointTri->thickness);
                break;
            case RECTANGLE:
                pointRet = pointList->info;
                printf("\nRetangulo: Coordenadas inferior esquerda (%.2f,%.2f) e superior direita (%.2f,%.2f)",pointRet->x1,pointRet->y1,pointRet->x2,pointRet->y2);
                printf("\nCor R: %.1f - G: %.1f - B: %.2f - Arredondamento Rx: %.2f Ry: %.2f - Thickness: %.2f\n",pointRet->colorR,pointRet->colorG,pointRet->colorB,pointRet->rx,pointRet->ry,pointRet->thickness);
                break;
            case ELIPSE:
                pointElip = pointList->info;
                printf("\nElipse: Coordenadas do centro (%.2f,%.2f).",pointElip->cx,pointElip->cy);
                printf("\nCor R: %.1f - G: %.1f - B: %.2f - Rx: %.2f Ry: %.2f - Thickness: %.2f\n",pointElip->colorR,pointElip->colorG,pointElip->colorB,pointElip->rx,pointElip->ry,pointElip->thickness);
                break;
            case CIRCLE:
                pointCirc = pointList->info;
                printf("\nCirculo: Coordenada do centro (%.2f,%.2f), raio %.2f",pointCirc->cx,pointCirc->cy,pointCirc->r);
                printf("\nCor R: %.1f - G: %.1f - B: %.2f - Thickness: %.2f\n",pointCirc->colorR,pointCirc->colorG,pointCirc->colorB,pointCirc->thickness);
                break;
            case ARC:
                pointArco = pointList->info;
                printf("\nArco: Coordenada do centro (%.2f,%.2f), raio %.2f",pointArco->cx,pointArco->cy,pointArco->r);
                printf("\nCor R: %.1f - G: %.1f - B: %.2f - Start theta: %.2f e Delta Theta: %.2f - Thickness: %.2f\n",pointArco->colorR,pointArco->colorG,pointArco->colorB,pointArco->start_theta,pointArco->delta_theta,pointArco->thickness);
                break;
            case SPLINE: break;
            case RIBBON: break;
            default:
                printf("\nErro: formato descohecido.");

        }
        pointList = pointList->prox; // Aponta para o proximo
    }
}

void imprime_lista_display(ListaGen* Lista)
{
    // Pontiero para lista
    ListaGen* pointList = Lista;
    // Ponteiros para impressao
    Linha* pointLinha;
    Tri* pointTri;
    Ret* pointRet;
    Elip* pointElip;
    Circ* pointCirc;
    Arco* pointArco;

    // Percorre a lista
    while(pointList!=NULL)
    {   switch(pointList->tipo)
        {
            case LINE:
                pointLinha = pointList->info;
                al_draw_line(pointLinha->x1,pointLinha->y1,pointLinha->x2,pointLinha->y2,al_map_rgb(pointLinha->colorR,pointLinha->colorG,pointLinha->colorB),pointLinha->thickness);
                break;
            case TRIANGLE:
                pointTri = pointList->info;
                al_draw_triangle(pointTri->x1,pointTri->y1,pointTri->x2,pointTri->y2,pointTri->x3,pointTri->y3,al_map_rgb(pointTri->colorR,pointTri->colorG,pointTri->colorB),pointTri->thickness);
                break;
            case RECTANGLE:
                pointRet = pointList->info;
                al_draw_rectangle(pointRet->x1,pointRet->y1,pointRet->x2,pointRet->y2,al_map_rgb(pointRet->colorR,pointRet->colorG,pointRet->colorB),pointRet->thickness);
                break;
            case ELIPSE:
                pointElip = pointList->info;
                al_draw_ellipse(pointElip->cx,pointElip->cy,pointElip->rx,pointElip->ry,al_map_rgb(pointElip->colorR,pointElip->colorG,pointElip->colorB),pointElip->thickness);
                break;
            case CIRCLE:
                pointCirc = pointList->info;
                al_draw_circle(pointCirc->cx,pointCirc->cy,pointCirc->r,al_map_rgb(pointCirc->colorR,pointCirc->colorG,pointCirc->colorB),pointCirc->thickness);
                break;
            case ARC:
                pointArco = pointList->info;
                al_draw_arc(pointArco->cx,pointArco->cy,pointArco->r,pointArco->start_theta,pointArco->delta_theta,al_map_rgb(pointArco->colorR,pointArco->colorG,pointArco->colorB),pointArco->thickness);
                break;
            default:
                printf("\nErro Allegro5: Tipo nao reconhecido.");
       }
        pointList = pointList->prox; // Aponta para o proximo
    }
}
