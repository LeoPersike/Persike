/*****************************************************
* Arquivo main.c - Exercicio lista encadeada
*
* Engenharia Eletronica
* Semestre 2015-1
*
* Desenvolvedor: Leonardo Persike Martins
* IFSC 2015
******************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "Functions.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

int main()
{
    // Cria ponteiro para lista
    ListaGen* Lista = NULL;

    // Inicializacao da janela do Allegro
    ALLEGRO_DISPLAY *janela = NULL;
    if (!al_init())
    {
        fprintf(stderr, "Falha ao inicializar a Allegro 5\n");
        return -1;
    }

    janela = al_create_display(640, 480);
    if (!janela)
    {
        fprintf(stderr, "Falha ao criar a janela\n");
        return -1;
    }

    // Inicializando primitives
    al_init_primitives_addon();

    // Insercao de retangulos
    insere_retangulo(40,55,250,250,255,0,255,5,&Lista);
    // Insercao de circulos
    insere_circulo(300,300,50,100,50,10,5,&Lista);

    printf("Tamanho de um elemento retangulo: %ld\n",sizeof(retangulo));
    printf("Tamanho de um elemento circulo: %ld\n",sizeof(circulo));
    imprime_lista(Lista);

    // Imprime desenhos na tela e aguarda 10 segundos
    imprime_lista_display(Lista);
    al_flip_display();
    al_rest(10.0);
    al_destroy_display(janela);

    return 0;
}

