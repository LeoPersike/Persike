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

#define DEBUG

#include <stdio.h>
#include <stdlib.h>
#include "Functions.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

int main()
{
    // Cria ponteiro para lista com os elementos
    ListaGen* Lista = NULL;

    // Inicializacao da janela do Allegro
    ALLEGRO_DISPLAY *janela = NULL;
    if (!al_init())
    {
        fprintf(stderr, "Falha ao inicializar a Allegro 5\n");
        return -1;
    }

    janela = al_create_display(1280, 720);
    if (!janela)
    {
        fprintf(stderr, "Falha ao criar a janela\n");
        return -1;
    }

    // Inicializando primitives para impressao na tela
    al_init_primitives_addon();


    // Insercao de figuras
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
    #endif
    imprime_lista(Lista);

    // Imprime desenhos na tela e aguarda 10 segundos
    imprime_lista_display(Lista);
    al_flip_display(); // Atualiza tela
    al_rest(10.0);
    al_destroy_display(janela);

    return 0;
}
