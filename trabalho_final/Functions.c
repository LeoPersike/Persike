/************************************************************
* Arquivo Functions.c - Exercicio lista encadeada generica
*
* Engenharia Eletronica
* Semestre 2015-1
*
* Desenvolvedor: Leonardo Persike Martins
* IFSC 2015
************************************************************/

#include "Functions.h"

//******** Variaveis utilizadas para controle do ambiente grafico ***********//
const int LARGURA_TELA = 1280;
const int ALTURA_TELA = 720;
const int BOTAO_A = 50;
const int BOTAO_L = 50;
const int desloc =  0;

//********* Variaveis globais graficas **********//
ALLEGRO_DISPLAY *janela = NULL;
ALLEGRO_EVENT_QUEUE *fila_eventos = NULL;
ALLEGRO_FONT *font;
ALLEGRO_BITMAP *background = NULL;

// Botoes para programa detectar se deseja adicionar ou remover um item
ALLEGRO_BITMAP *button_add = NULL;
ALLEGRO_BITMAP *button_remove = NULL;
// Botoes para desenho
ALLEGRO_BITMAP *button_line = NULL;
ALLEGRO_BITMAP *button_triangle = NULL;
ALLEGRO_BITMAP *button_triangle_filled = NULL;
ALLEGRO_BITMAP *button_rectangle = NULL;
ALLEGRO_BITMAP *button_rectangle_filled = NULL;
ALLEGRO_BITMAP *button_rectangle_rounded = NULL;
ALLEGRO_BITMAP *button_rectangle_rounded_filled = NULL;
ALLEGRO_BITMAP *button_ellipse = NULL;
ALLEGRO_BITMAP *button_ellipse_filled = NULL;
ALLEGRO_BITMAP *button_circle = NULL;
ALLEGRO_BITMAP *button_circle_filled = NULL;
ALLEGRO_BITMAP *button_arc = NULL;
// Botoes para cores
ALLEGRO_BITMAP *BLACK = NULL;
ALLEGRO_BITMAP *BROWN = NULL;
ALLEGRO_BITMAP *RED = NULL;
ALLEGRO_BITMAP *ORANGE = NULL;
ALLEGRO_BITMAP *YELLOW = NULL;
ALLEGRO_BITMAP *GREEN = NULL;
ALLEGRO_BITMAP *BLUE = NULL;
ALLEGRO_BITMAP *VIOLET = NULL;
ALLEGRO_BITMAP *GRAY = NULL;
ALLEGRO_BITMAP *WHITE = NULL;

//Variavel para eventos do allegro
ALLEGRO_EVENT evento;

//********* Funcoes graficas ***********//
int graphic_init()
{
    if (!al_init())
    {
	  fprintf(stderr, "Falha ao inicializar a biblioteca Allegro.\n");
	  return 0;
    }

    if (!al_install_keyboard())
    {
        fprintf(stderr, "Falha ao inicializar teclado.\n");
        return 0;
    }

    if (!al_init_primitives_addon())
    {
	  fprintf(stderr, "Falha ao inicializar add-on de primitivas.\n");
	  return 0;
    }

    al_init_font_addon();//habilita o uso de fontes

    if (!al_init_ttf_addon())
    {
	  fprintf(stderr, "Falha ao inicializar add-on allegro_ttf.\n");
	  return 0;
    }

    font = al_load_font("arquivos/DejaVuSans.ttf", 20, 0);
    if (!font)
    {
	  fprintf(stderr, "Falha ao carregar a fonte.\n");
	  return 0;
    }

    janela = al_create_display(LARGURA_TELA, ALTURA_TELA);
    if (!janela)
    {
	  fprintf(stderr, "Falha ao criar janela.\n");
	  return 0;
    }
    al_set_window_title(janela, "PK Cad V1.0.");
    al_set_target_bitmap(al_get_backbuffer(janela));
    al_clear_to_color(al_map_rgb(255, 255, 0));

    //Mensagem de inicializacao
    //exibir_texto_centralizado("PK Cad V1.0 esta inicializando.");
    //al_flip_display();

    // Torna apto o uso de mouse na aplicação
    if (!al_install_mouse())
    {
	  fprintf(stderr, "Falha ao inicializar o mouse.\n");
	  al_destroy_display(janela);
	  return 0;
    }

    // Atribui o cursor padrão do sistema para ser usado
    if (!al_set_system_mouse_cursor(janela, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT))
    {
	  fprintf(stderr, "Falha ao atribuir ponteiro do mouse.\n");
	  al_destroy_display(janela);
	  return 0;
    }

    fila_eventos = al_create_event_queue();
    if (!fila_eventos)
    {
	  fprintf(stderr, "Falha ao inicializar o fila de eventos.\n");
	  al_destroy_display(janela);
	  return 0;
    }

    // Dizemos que vamos tratar os eventos vindos do mouse e do teclado
    al_register_event_source(fila_eventos, al_get_mouse_event_source());
    al_register_event_source(fila_eventos, al_get_keyboard_event_source());

    // Alocamos o background
    background = al_create_bitmap(LARGURA_TELA, ALTURA_TELA);
    if (!background) {
        fprintf(stderr, "Falha ao criar background.\n");
        al_destroy_bitmap(background);
        al_destroy_display(janela);
        return 0;
    }
    background = al_create_bitmap(LARGURA_TELA, ALTURA_TELA);

    // Alocacao dos botoes de add e remove
    button_add = al_create_bitmap(2*BOTAO_L, BOTAO_A);
    button_remove = al_create_bitmap(2*BOTAO_L, BOTAO_A);

    // Alocacao dos botoes de desenho
    button_line = al_create_bitmap(BOTAO_L, BOTAO_A);
    button_triangle = al_create_bitmap(BOTAO_L, BOTAO_A);
    button_triangle_filled = al_create_bitmap(BOTAO_L, BOTAO_A);
    button_rectangle = al_create_bitmap(BOTAO_L, BOTAO_A);
    button_rectangle_filled = al_create_bitmap(BOTAO_L, BOTAO_A);
    button_rectangle_rounded = al_create_bitmap(BOTAO_L, BOTAO_A);
    button_rectangle_rounded_filled = al_create_bitmap(BOTAO_L, BOTAO_A);
    button_ellipse = al_create_bitmap(BOTAO_L, BOTAO_A);
    button_ellipse_filled = al_create_bitmap(BOTAO_L, BOTAO_A);
    button_circle = al_create_bitmap(BOTAO_L, BOTAO_A);
    button_circle_filled = al_create_bitmap(BOTAO_L, BOTAO_A);
    button_arc = al_create_bitmap(BOTAO_L, BOTAO_A);

    // Alocacao dos botoes de cores
    BLACK = al_create_bitmap(BOTAO_L,BOTAO_A);
    BROWN = al_create_bitmap(BOTAO_L,BOTAO_A);
    RED = al_create_bitmap(BOTAO_L,BOTAO_A);
    ORANGE = al_create_bitmap(BOTAO_L,BOTAO_A);
    YELLOW = al_create_bitmap(BOTAO_L,BOTAO_A);
    GREEN = al_create_bitmap(BOTAO_L,BOTAO_A);
    BLUE = al_create_bitmap(BOTAO_L,BOTAO_A);
    VIOLET = al_create_bitmap(BOTAO_L,BOTAO_A);
    GRAY = al_create_bitmap(BOTAO_L,BOTAO_A);
    WHITE = al_create_bitmap(BOTAO_L,BOTAO_A);

    //if (!botao_sair || !botao_criar || !botao_salvar) {
    if(!button_line || !button_triangle || !button_triangle_filled || !button_rectangle || !button_rectangle_filled || !button_rectangle_rounded
     || !button_rectangle_rounded_filled || !button_ellipse || !button_ellipse_filled || !button_circle || !button_circle_filled || !button_arc
     || !BLACK || !BROWN || !RED || !ORANGE || !YELLOW || !GREEN || !BLUE || !VIOLET || !GRAY || !WHITE || !button_add || !button_remove)
    {
        fprintf(stderr, "Falha ao criar botoes.\n");
        // Deslocando botoes de add e remove
        al_destroy_bitmap(button_add);
        al_destroy_bitmap(button_remove);
        // Desalocando botoes de desenho
        al_destroy_bitmap(button_line);
        al_destroy_bitmap(button_triangle);
        al_destroy_bitmap(button_triangle_filled);
        al_destroy_bitmap(button_rectangle);
        al_destroy_bitmap(button_rectangle_filled);
        al_destroy_bitmap(button_rectangle_rounded);
        al_destroy_bitmap(button_rectangle_rounded_filled);
        al_destroy_bitmap(button_ellipse);
        al_destroy_bitmap(button_ellipse_filled);
        al_destroy_bitmap(button_circle);
        al_destroy_bitmap(button_circle_filled);
        al_destroy_bitmap(button_arc);
        // Desalocando botoes de cores
        al_destroy_bitmap(BLACK);
        al_destroy_bitmap(BROWN);
        al_destroy_bitmap(RED);
        al_destroy_bitmap(ORANGE);
        al_destroy_bitmap(YELLOW);
        al_destroy_bitmap(GREEN);
        al_destroy_bitmap(BLUE);
        al_destroy_bitmap(VIOLET);
        al_destroy_bitmap(GRAY);
        al_destroy_bitmap(WHITE);
        // Desalocando janela
        al_destroy_display(janela);
        return 0;
    }
    al_set_target_bitmap(background);
    al_clear_to_color(al_map_rgb(255, 255, 255));


    // Dando forma aos botoes de adicionar e remover
    al_set_target_bitmap(button_add);
    al_clear_to_color(al_map_rgb(255, 255, 255));
    al_draw_rectangle(0,0, 2*BOTAO_L, BOTAO_A, al_map_rgb(0,0,0),5);
    al_draw_text(font, al_map_rgb(0, 0, 0), 2*BOTAO_L / 2,(BOTAO_A - al_get_font_ascent(font)) / 2,ALLEGRO_ALIGN_CENTRE, "ADD");

    al_set_target_bitmap(button_remove);
    al_clear_to_color(al_map_rgb(255, 255, 255));
    al_draw_rectangle(0,0, 2*BOTAO_L, BOTAO_A, al_map_rgb(0,0,0),5);
    al_draw_text(font, al_map_rgb(0, 0, 0), 2*BOTAO_L / 2,(BOTAO_A - al_get_font_ascent(font)) / 2,ALLEGRO_ALIGN_CENTRE, "REMOVE");

    // Dando forma aos botoes de desenho
    al_set_target_bitmap(button_line);
    al_clear_to_color(al_map_rgb(255, 255, 255));
    al_draw_rectangle(0,0, BOTAO_L, BOTAO_A, al_map_rgb(0,0,0),5);
    al_draw_text(font, al_map_rgb(0, 0, 0), BOTAO_L / 2,(BOTAO_A - al_get_font_ascent(font)) / 2,ALLEGRO_ALIGN_CENTRE, "");

    al_set_target_bitmap(button_triangle);
    al_clear_to_color(al_map_rgb(255, 255, 255));
    al_draw_rectangle(0,0, BOTAO_L, BOTAO_A, al_map_rgb(0,0,0),5);
    al_draw_text(font, al_map_rgb(0, 0, 0), BOTAO_L / 2,(BOTAO_A - al_get_font_ascent(font)) / 2,ALLEGRO_ALIGN_CENTRE, "");

    al_set_target_bitmap(button_triangle_filled);
    al_clear_to_color(al_map_rgb(255, 255, 255));
    al_draw_rectangle(0,0, BOTAO_L, BOTAO_A, al_map_rgb(0,0,0),5);
    al_draw_text(font, al_map_rgb(0, 0, 0), BOTAO_L / 2,(BOTAO_A - al_get_font_ascent(font)) / 2,ALLEGRO_ALIGN_CENTRE, "");

    al_set_target_bitmap(button_rectangle);
    al_clear_to_color(al_map_rgb(255, 255, 255));
    al_draw_rectangle(0,0, BOTAO_L, BOTAO_A, al_map_rgb(0,0,0),5);
    al_draw_text(font, al_map_rgb(0, 0, 0), BOTAO_L / 2,(BOTAO_A - al_get_font_ascent(font)) / 2,ALLEGRO_ALIGN_CENTRE, "");

    al_set_target_bitmap(button_rectangle_filled);
    al_clear_to_color(al_map_rgb(255, 255, 255));
    al_draw_rectangle(0,0, BOTAO_L, BOTAO_A, al_map_rgb(0,0,0),5);
    al_draw_text(font, al_map_rgb(0, 0, 0), BOTAO_L / 2,(BOTAO_A - al_get_font_ascent(font)) / 2,ALLEGRO_ALIGN_CENTRE, "");

    al_set_target_bitmap(button_rectangle_rounded);
    al_clear_to_color(al_map_rgb(255, 255, 255));
    al_draw_rectangle(0,0, BOTAO_L, BOTAO_A, al_map_rgb(0,0,0),5);
    al_draw_text(font, al_map_rgb(0, 0, 0), BOTAO_L / 2,(BOTAO_A - al_get_font_ascent(font)) / 2,ALLEGRO_ALIGN_CENTRE, "");

    al_set_target_bitmap(button_rectangle_rounded_filled);
    al_clear_to_color(al_map_rgb(255, 255, 255));
    al_draw_rectangle(0,0, BOTAO_L, BOTAO_A, al_map_rgb(0,0,0),5);
    al_draw_text(font, al_map_rgb(0, 0, 0), BOTAO_L / 2,(BOTAO_A - al_get_font_ascent(font)) / 2,ALLEGRO_ALIGN_CENTRE, "");

    al_set_target_bitmap(button_ellipse);
    al_clear_to_color(al_map_rgb(255, 255, 255));
    al_draw_rectangle(0,0, BOTAO_L, BOTAO_A, al_map_rgb(0,0,0),5);
    al_draw_text(font, al_map_rgb(0, 0, 0), BOTAO_L / 2,(BOTAO_A - al_get_font_ascent(font)) / 2,ALLEGRO_ALIGN_CENTRE, "");

    al_set_target_bitmap(button_ellipse_filled);
    al_clear_to_color(al_map_rgb(255, 255, 255));
    al_draw_rectangle(0,0, BOTAO_L, BOTAO_A, al_map_rgb(0,0,0),5);
    al_draw_text(font, al_map_rgb(0, 0, 0), BOTAO_L / 2,(BOTAO_A - al_get_font_ascent(font)) / 2,ALLEGRO_ALIGN_CENTRE, "");

    al_set_target_bitmap(button_circle);
    al_clear_to_color(al_map_rgb(255, 255, 255));
    al_draw_rectangle(0,0, BOTAO_L, BOTAO_A, al_map_rgb(0,0,0),5);
    al_draw_text(font, al_map_rgb(0, 0, 0), BOTAO_L / 2,(BOTAO_A - al_get_font_ascent(font)) / 2,ALLEGRO_ALIGN_CENTRE, "");

    al_set_target_bitmap(button_circle_filled);
    al_clear_to_color(al_map_rgb(255, 255, 255));
    al_draw_rectangle(0,0, BOTAO_L, BOTAO_A, al_map_rgb(0,0,0),5);
    al_draw_text(font, al_map_rgb(0, 0, 0), BOTAO_L / 2,(BOTAO_A - al_get_font_ascent(font)) / 2,ALLEGRO_ALIGN_CENTRE, "");

    al_set_target_bitmap(button_arc);
    al_clear_to_color(al_map_rgb(255, 255, 255));
    al_draw_rectangle(0,0, BOTAO_L, BOTAO_A, al_map_rgb(0,0,0),5);
    al_draw_text(font, al_map_rgb(0, 0, 0), BOTAO_L / 2,(BOTAO_A - al_get_font_ascent(font)) / 2,ALLEGRO_ALIGN_CENTRE, "");

    // Dando forma aos botoes de cores
    al_set_target_bitmap(BLACK);
    al_clear_to_color(al_map_rgb(0,0,0));
    al_draw_rectangle(0,0, BOTAO_L, BOTAO_A, al_map_rgb(0,0,0),5);

    al_set_target_bitmap(BROWN);
    al_clear_to_color(al_map_rgb(94,28,13));
    al_draw_rectangle(0,0, BOTAO_L, BOTAO_A, al_map_rgb(0,0,0),5);

    al_set_target_bitmap(RED);
    al_clear_to_color(al_map_rgb(255,0,0));
    al_draw_rectangle(0,0, BOTAO_L, BOTAO_A, al_map_rgb(0,0,0),5);

    al_set_target_bitmap(ORANGE);
    al_clear_to_color(al_map_rgb(255,116,21));
    al_draw_rectangle(0,0, BOTAO_L, BOTAO_A, al_map_rgb(0,0,0),5);

    al_set_target_bitmap(YELLOW);
    al_clear_to_color(al_map_rgb(255,217,0));
    al_draw_rectangle(0,0, BOTAO_L, BOTAO_A, al_map_rgb(0,0,0),5);

    al_set_target_bitmap(GREEN);
    al_clear_to_color(al_map_rgb(0,255,0));
    al_draw_rectangle(0,0, BOTAO_L, BOTAO_A, al_map_rgb(0,0,0),5);

    al_set_target_bitmap(BLUE);
    al_clear_to_color(al_map_rgb(0,0,255));
    al_draw_rectangle(0,0, BOTAO_L, BOTAO_A, al_map_rgb(0,0,0),5);

    al_set_target_bitmap(VIOLET);
    al_clear_to_color(al_map_rgb(69,0,68));
    al_draw_rectangle(0,0, BOTAO_L, BOTAO_A, al_map_rgb(0,0,0),5);

    al_set_target_bitmap(GRAY);
    al_clear_to_color(al_map_rgb(117, 117, 117));
    al_draw_rectangle(0,0, BOTAO_L, BOTAO_A, al_map_rgb(0,0,0),5);

    al_set_target_bitmap(WHITE);
    al_clear_to_color(al_map_rgb(255, 255, 255));
    al_draw_rectangle(0,0, BOTAO_L, BOTAO_A, al_map_rgb(0,0,0),5);

    return 1;
}

void fechajanela(){
    /*Desaloca os recursos utilizados na aplicação*/
    al_destroy_display(janela);
    al_destroy_event_queue(fila_eventos);

	printf("\n Aplicacao encerrada.");
	//system("sleep 1");
}

void exibir_texto_centralizado(char msg[20]) {
        al_set_target_bitmap(al_get_backbuffer(janela));
        al_draw_text(font, al_map_rgb(0, 0, 0), LARGURA_TELA / 2,
                     (ALTURA_TELA - al_get_font_ascent(font)) / 2,
                     ALLEGRO_ALIGN_CENTRE, msg);
}

void atualiza_tela(bool *pause) {
        char msg[5];
        sprintf(msg, "%.1f", 1/((double) (end - begin) / CLOCKS_PER_SEC));
       // msg = (char[10])((double) (end - begin) / CLOCKS_PER_SEC);
        al_set_target_bitmap(al_get_backbuffer(janela));
        al_draw_bitmap(background, 0, 0, 0);
        // Botao linha simples
        al_draw_bitmap(button_line,LARGURA_TELA-BOTAO_L,ALTURA_TELA-1*BOTAO_A-desloc,0);
        al_draw_line(1240,696,1270,696,al_map_rgb(0,0,0),2);
        // Botao triangulo simples
        al_draw_bitmap(button_triangle,LARGURA_TELA-BOTAO_L,ALTURA_TELA-2*BOTAO_A-desloc,0);
        al_draw_triangle(1255,636,1244,652,1266,652,al_map_rgb(0,0,0),2);
        // Botap triangulo colorido
        al_draw_bitmap(button_triangle_filled,LARGURA_TELA-BOTAO_L,ALTURA_TELA-3*BOTAO_A-desloc,0);
        al_draw_filled_triangle(1255,586,1244,602,1266,602,al_map_rgb(255,0,0));
        // Botao retangulo simples
        al_draw_bitmap(button_rectangle,LARGURA_TELA-BOTAO_L,ALTURA_TELA - 4*BOTAO_A-desloc,0);
        al_draw_rectangle(1239,536,1270,555,al_map_rgb(0,0,0),2);
        // Botao retangulo colorido
        al_draw_bitmap(button_rectangle_filled,LARGURA_TELA-BOTAO_L,ALTURA_TELA-5*BOTAO_A-desloc,0);
        al_draw_filled_rectangle(1239,486,1270,505,al_map_rgb(0,255,0));
        // Botao retangulo arredondado
        al_draw_bitmap(button_rectangle_rounded, LARGURA_TELA-BOTAO_L,ALTURA_TELA-6*BOTAO_A-desloc,0);
        al_draw_rounded_rectangle(1239,436,1270,455,5,5,al_map_rgb(0,0,0),2);
        // Botao retangulo arredondado colorido
        al_draw_bitmap(button_rectangle_rounded_filled,LARGURA_TELA-BOTAO_L,ALTURA_TELA-7*BOTAO_A-desloc,0);
        al_draw_filled_rounded_rectangle(1239,386,1270,405,5,5,al_map_rgb(0,0,255));
        // Botao eclipse simples
        al_draw_bitmap(button_ellipse,LARGURA_TELA-BOTAO_L,ALTURA_TELA-8*BOTAO_A-desloc,0);
        al_draw_ellipse(1255,346,17,9,al_map_rgb(0,0,0),2);
        // Botao eclipse colorido
        al_draw_bitmap(button_ellipse_filled,LARGURA_TELA-BOTAO_L,ALTURA_TELA-9*BOTAO_A-desloc,0);
        al_draw_filled_ellipse(1255,296,17,9,al_map_rgb(255,255,0));
        // Botao circulo
        al_draw_bitmap(button_circle, LARGURA_TELA-BOTAO_L,ALTURA_TELA-10*BOTAO_A-desloc,0);
        al_draw_circle(1255,246,16,al_map_rgb(0,0,0),2);
        // Botao circulo coorido
        al_draw_bitmap(button_circle_filled,LARGURA_TELA-BOTAO_L,ALTURA_TELA-11*BOTAO_A-desloc,0);
        al_draw_filled_circle(1255,196,16,al_map_rgb(69,0,68));
        // Botao arco
        al_draw_bitmap(button_arc,LARGURA_TELA-BOTAO_L,ALTURA_TELA-12*BOTAO_A-desloc,0);
        al_draw_arc(1255,150,15,PI,PI,al_map_rgb(0,0,0),2);

        // Botoes de cores
        al_draw_bitmap(BLACK,LARGURA_TELA-2*BOTAO_L,ALTURA_TELA-1*BOTAO_A-desloc,0);
        al_draw_bitmap(BROWN,LARGURA_TELA-2*BOTAO_L,ALTURA_TELA-2*BOTAO_A-desloc,0);
        al_draw_bitmap(RED,LARGURA_TELA-2*BOTAO_L,ALTURA_TELA-3*BOTAO_A-desloc,0);
        al_draw_bitmap(ORANGE,LARGURA_TELA-2*BOTAO_L,ALTURA_TELA-4*BOTAO_A-desloc,0);
        al_draw_bitmap(YELLOW,LARGURA_TELA-2*BOTAO_L,ALTURA_TELA-5*BOTAO_A-desloc,0);
        al_draw_bitmap(GREEN,LARGURA_TELA-2*BOTAO_L,ALTURA_TELA-6*BOTAO_A-desloc,0);
        al_draw_bitmap(BLUE,LARGURA_TELA-2*BOTAO_L,ALTURA_TELA-7*BOTAO_A-desloc,0);
        al_draw_bitmap(VIOLET,LARGURA_TELA-2*BOTAO_L,ALTURA_TELA-8*BOTAO_A-desloc,0);
        al_draw_bitmap(GRAY,LARGURA_TELA-2*BOTAO_L,ALTURA_TELA-9*BOTAO_A-desloc,0);
        al_draw_bitmap(WHITE,LARGURA_TELA-2*BOTAO_L,ALTURA_TELA-9*BOTAO_A-desloc,0);

        // Botoes de add e remove
        al_draw_bitmap(button_remove,LARGURA_TELA-2*BOTAO_L,ALTURA_TELA-13*BOTAO_A-desloc,0);
        al_draw_bitmap(button_add,LARGURA_TELA-2*BOTAO_L,ALTURA_TELA-14*BOTAO_A-desloc,0);

        al_draw_text(font, al_map_rgb(255, 255, 255), 10, 10, 0 , *pause== 0?msg:"Pausado");
        //printf("FPS = %.2f\n",1/((double) (end - begin) / CLOCKS_PER_SEC));
        al_flip_display();
}

//********* Funcoes do programa *************//

//********* Funcao principal ****************//
int cad_system(void)
{
    int state = WAITING; // State
    // Variavel state configura uma maquina de estados - Definicoes em Functions.h
    bool pause = 0;
    int add_flag = 1; // Default: 1. Se flag = 1 ADD, se flag = 0 REMOVE
    while(state!=EXIT)
    {
        begin = clock();
        while (!al_is_event_queue_empty(fila_eventos))
        {
            al_wait_for_event(fila_eventos, &evento);
            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
                {
                    state = EXIT;
                    printf("%s\n", "KEY");
                }
            }
            else if (evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP)
            {
                printf("\nx:%d e y:%d",evento.mouse.x,evento.mouse.y);
                if (evento.mouse.x >= LARGURA_TELA - 2*BOTAO_L)
                {
                    // Botoes de formas
                    if (evento.mouse.x >= LARGURA_TELA - BOTAO_L)
                    {

                        if(evento.mouse.y <= ALTURA_TELA - 0*BOTAO_A - desloc && evento.mouse.y >= ALTURA_TELA - BOTAO_A -desloc)
                        {
                            state = WAITING;
                            printf("\nBotao linha simples");
                        }
                        if(evento.mouse.y <= ALTURA_TELA - 1*BOTAO_A - desloc && evento.mouse.y >= ALTURA_TELA - 2*BOTAO_A -desloc)
                        {
                            state = WAITING;
                            printf("\nBotao triangulo simples");
                        }
                        if(evento.mouse.y <= ALTURA_TELA - 2*BOTAO_A - desloc && evento.mouse.y >= ALTURA_TELA - 3*BOTAO_A -desloc)
                        {
                            state = WAITING;
                            printf("\nBotao triangulo colorido");
                        }
                        if(evento.mouse.y <= ALTURA_TELA - 3*BOTAO_A - desloc && evento.mouse.y >= ALTURA_TELA - 4*BOTAO_A -desloc)
                        {
                            state = WAITING;
                            printf("\nBotao retangulo simples");
                        }
                        if(evento.mouse.y <= ALTURA_TELA - 4*BOTAO_A - desloc && evento.mouse.y >= ALTURA_TELA - 5*BOTAO_A -desloc)
                        {
                            state = WAITING;
                            printf("\nBotao retangulo colorido");
                        }
                        if(evento.mouse.y <= ALTURA_TELA - 5*BOTAO_A - desloc && evento.mouse.y >= ALTURA_TELA - 6*BOTAO_A -desloc)
                        {
                            state = WAITING;
                            printf("\nBotao retangulo arredondado");
                        }
                        if(evento.mouse.y <= ALTURA_TELA - 6*BOTAO_A - desloc && evento.mouse.y >= ALTURA_TELA - 7*BOTAO_A -desloc)
                        {
                            state = WAITING;
                            printf("\nBotao retangulo arredondado colorido");
                        }
                        if(evento.mouse.y <= ALTURA_TELA - 7*BOTAO_A - desloc && evento.mouse.y >= ALTURA_TELA - 8*BOTAO_A -desloc)
                        {
                            state = WAITING;
                            printf("\nBotao elipse simples");
                        }
                        if(evento.mouse.y <= ALTURA_TELA - 8*BOTAO_A - desloc && evento.mouse.y >= ALTURA_TELA - 9*BOTAO_A -desloc)
                        {
                            state = WAITING;
                            printf("\nBotao elipse colorida");
                        }
                        if(evento.mouse.y <= ALTURA_TELA - 9*BOTAO_A - desloc && evento.mouse.y >= ALTURA_TELA - 10*BOTAO_A -desloc)
                        {
                            state = WAITING;
                            printf("\nBotao circulo simples");
                        }
                        if(evento.mouse.y <= ALTURA_TELA - 10*BOTAO_A - desloc && evento.mouse.y >= ALTURA_TELA - 11*BOTAO_A -desloc)
                        {
                            state = WAITING;
                            printf("\nBotao circulo colorido");
                        }
                        if(evento.mouse.y <= ALTURA_TELA - 11*BOTAO_A - desloc && evento.mouse.y >= ALTURA_TELA - 12*BOTAO_A -desloc)
                        {
                            state = WAITING;
                            printf("\nBotao arco");
                        }
                    }

                    // Botoes de ADD ou REMOVE
                    if (evento.mouse.x >= LARGURA_TELA - 2*BOTAO_L)
                    {
                        if(evento.mouse.y <= ALTURA_TELA - 12*BOTAO_A - desloc && evento.mouse.y >= ALTURA_TELA - 13*BOTAO_A -desloc)
                        {
                            state = WAITING;
                            add_flag = 0;
                            printf("\nBotao REMOVE");
                        }
                        if(evento.mouse.y <= ALTURA_TELA - 13*BOTAO_A - desloc && evento.mouse.y >= ALTURA_TELA - 14*BOTAO_A -desloc)
                        {
                            state = WAITING;
                            add_flag = 1;
                            printf("\nBotao ADD");
                        }
                    }

                    // Botoes de cores
                    if (evento.mouse.x >= LARGURA_TELA - 2*BOTAO_L && evento.mouse.x <= LARGURA_TELA - 1*BOTAO_L)
                    {

                        if(evento.mouse.y <= ALTURA_TELA - 0*BOTAO_A - desloc && evento.mouse.y >= ALTURA_TELA - BOTAO_A -desloc)
                        {
                            state = WAITING;
                            printf("\nCor: Preto.");
                        }
                        if(evento.mouse.y <= ALTURA_TELA - 1*BOTAO_A - desloc && evento.mouse.y >= ALTURA_TELA - 2*BOTAO_A -desloc)
                        {
                            state = WAITING;
                            printf("\nCor: Marrom");
                        }
                        if(evento.mouse.y <= ALTURA_TELA - 2*BOTAO_A - desloc && evento.mouse.y >= ALTURA_TELA - 3*BOTAO_A -desloc)
                        {
                            state = WAITING;
                            printf("\nCor: Vermelho");
                        }
                        if(evento.mouse.y <= ALTURA_TELA - 3*BOTAO_A - desloc && evento.mouse.y >= ALTURA_TELA - 4*BOTAO_A -desloc)
                        {
                            state = WAITING;
                            printf("\nCor: Laranja");
                        }
                        if(evento.mouse.y <= ALTURA_TELA - 4*BOTAO_A - desloc && evento.mouse.y >= ALTURA_TELA - 5*BOTAO_A -desloc)
                        {
                            state = WAITING;
                            printf("\nCor: Amarelo");
                        }
                        if(evento.mouse.y <= ALTURA_TELA - 5*BOTAO_A - desloc && evento.mouse.y >= ALTURA_TELA - 6*BOTAO_A -desloc)
                        {
                            state = WAITING;
                            printf("\nCor: Verde");
                        }
                        if(evento.mouse.y <= ALTURA_TELA - 6*BOTAO_A - desloc && evento.mouse.y >= ALTURA_TELA - 7*BOTAO_A -desloc)
                        {
                            state = WAITING;
                            printf("\nCor: Azul");
                        }
                        if(evento.mouse.y <= ALTURA_TELA - 7*BOTAO_A - desloc && evento.mouse.y >= ALTURA_TELA - 8*BOTAO_A -desloc)
                        {
                            state = WAITING;
                            printf("\nCor: Violeta");
                        }
                        if(evento.mouse.y <= ALTURA_TELA - 8*BOTAO_A - desloc && evento.mouse.y >= ALTURA_TELA - 9*BOTAO_A -desloc)
                        {
                            state = WAITING;
                            printf("\nCor: Branca");
                        }
                    }
                }
            }
        }

    while(((double) (end - begin) / CLOCKS_PER_SEC)<(1./FPS) && !pause) //define FPS maxima
        end = clock();

    atualiza_tela(&pause);
    }

    return state;
}

//*********** Funcoes de insercao e remocao de elementso ************//
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
