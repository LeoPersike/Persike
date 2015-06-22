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
    // Variavel auxiliar
    int aux_state = WAITING;

    // Inicia ambiente grafico
    if(graphic_init())
        printf("\nInterface grafica inicializada.");
    else
        {
        printf("\nProblema na inicializacao da interface grafica!");
        return -1;
        }

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
    }
    if(aux_state != EXIT)
        printf("Algum problema ocorreu!");

    fechajanela();
    printf("\nO software PK Cad V1.0 foi finalizado como sucesso.");
    return 0;
}
