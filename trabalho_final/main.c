/*****************************************************
* Arquivo main.c - Trabalho final da disciplina de
* Programacao II - Professor Fernando Pacheco
*
* O trabalho consiste em desenvolver um CAD utilizando
* linguagem de programacao C e a biblioteca allegro5.
* Tambem devera ser utilizado o que foi aprendido sobre
* estrutura de dados na disciplina.
*
* Engenharia Eletronica
* Semestre 2015-1
*
* Desenvolvedor: Leonardo Persike Martins
* IFSC 2015
******************************************************/

//#define DEBUG

#include <stdio.h>
#include <stdlib.h>
#include "Functions.h"
#include <allegro5/allegro.h>

int main()
{
    // Cria ponteiro para lista com os elementos
    int aux_state = WAITING;
    ListaGen* Lista = NULL;

    // Inicia ambiente grafico
    if(graphic_init())
        printf("\nInterface grafica inicializada.");
    else
        {
        printf("\nProblema na inicializacao da interface grafica!");
        return -1;
        }

    // Insercao de figuras manual (para teste)
    insere_linha(500,500,630,630,0,255,0,5,&Lista);
    insere_triangulo(90,90,130,130,50,130,0,0,255,10,&Lista);
    insere_retangulo(40,55,250,250,5,5,255,0,255,5,&Lista);
    insere_elipse(500,500,50,30,150,150,150,5,&Lista);
    insere_circulo(300,300,50,100,50,10,5,&Lista);
    insere_arco(430,430,15,0,180,100,100,0,5,&Lista);

    #ifdef DEBUG
    printf("\nTamanho de um elemento Linha: %ld",sizeof(Linha));
    printf("\nTamanho de um elemento Triangulo: %ld",sizeof(Tri));
    printf("\nTamanho de um elemento Retangulo: %ld",sizeof(Ret));
    printf("\nTamanho de um elemento Elipse: %ld",sizeof(Elip));
    printf("\nTamanho de um elemento Circulo: %ld",sizeof(Circ));
    printf("\nTamanho de um elemento Arco: %ld",sizeof(Arco));
    imprime_lista(Lista); // Imprime lista no console
    #endif

    while(aux_state != EXIT)
    {
        aux_state = cad_system();
        switch (aux_state) {
            case EXIT: break;
            case WAITING: break;
            case DRAW_LINE: break;
            case DRAW_TRIANGLE: break;
            case DRAW_RECTANGLE: break;
            case DRAW_ELIPSE: break;
            case DRAW_CIRCLE: break;
            case DRAW_ARC: break;
            case DRAW_SPLINE: break;
            case DRAW_RIBBON: break;
            case REMOVE_LINE: break;
            case REMOVE_TRIANGLE: break;
            case REMOVE_RECTANGLE: break;
            case REMOVE_ELIPSE: break;
            case REMOVE_CIRCLE: break;
            case REMOVE_ARC: break;
            case REMOVE_SPLINE: break;
            case REMOVE_RIBBON: break;
            default: break;
        }
    }

    fechajanela();
    printf("\nO software PK Cad V1.0 foi finalizado como sucesso.");
    return 0;
}
