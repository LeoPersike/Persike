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

void atualiza_tela(bool *pause,ListaGen* Lista) {
        char msg[5];
        sprintf(msg, "%.1f", 1/((double) (end - begin) / CLOCKS_PER_SEC));
       // msg = (char[10])((double) (end - begin) / CLOCKS_PER_SEC);
        al_set_target_bitmap(al_get_backbuffer(janela));
        al_draw_bitmap(background, 0, 0, 0);

        // Desenhando formas
        ListaGen* pointList = Lista;
        Linha* pointLinha;
        Tri* pointTri;
        Ret* pointRet;
        Elip* pointElip;
        Circ* pointCirc;
        Arco* pointArco;

        while(pointList!=NULL)
        {
            switch(pointList->tipo)
            {
                case LINE:
                    pointLinha = pointList->info;
                    al_draw_line(pointLinha->x1,pointLinha->y1,pointLinha->x2,pointLinha->y2,al_map_rgb(pointLinha->colorR,pointLinha->colorG,pointLinha->colorB),pointLinha->thickness);
                    break;
                case TRIANGLE:
                    pointTri = pointList->info;
                    if(pointTri->filled)
                        al_draw_filled_triangle(pointTri->x1,pointTri->y1,pointTri->x2,pointTri->y2,pointTri->x3,pointTri->y3,al_map_rgb(pointTri->colorR,pointTri->colorG,pointTri->colorB));
                    else
                        al_draw_triangle(pointTri->x1,pointTri->y1,pointTri->x2,pointTri->y2,pointTri->x3,pointTri->y3,al_map_rgb(pointTri->colorR,pointTri->colorG,pointTri->colorB),pointTri->thickness);
                    break;
                case RECTANGLE:
                    pointRet = pointList->info;
                    if(pointRet->filled)
                        al_draw_filled_rounded_rectangle(pointRet->x1,pointRet->y1,pointRet->x2,pointRet->y2,pointRet->rx,pointRet->ry,al_map_rgb(pointRet->colorR,pointRet->colorG,pointRet->colorB));
                    else
                        al_draw_rounded_rectangle(pointRet->x1,pointRet->y1,pointRet->x2,pointRet->y2,pointRet->rx,pointRet->ry,al_map_rgb(pointRet->colorR,pointRet->colorG,pointRet->colorB),pointRet->thickness);
                    break;
                case ELIPSE:
                    pointElip = pointList->info;
                    if(pointElip->filled)
                        al_draw_filled_ellipse(pointElip->cx,pointElip->cy,pointElip->rx,pointElip->ry,al_map_rgb(pointElip->colorR,pointElip->colorG,pointElip->colorB));
                    else
                        al_draw_ellipse(pointElip->cx,pointElip->cy,pointElip->rx,pointElip->ry,al_map_rgb(pointElip->colorR,pointElip->colorG,pointElip->colorB),pointElip->thickness);
                    break;
                case CIRCLE:
                    pointCirc = pointList->info;
                    if(pointCirc->filled)
                        al_draw_filled_circle(pointCirc->cx,pointCirc->cy,pointCirc->r,al_map_rgb(pointCirc->colorR,pointCirc->colorG,pointCirc->colorB));
                    else
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
        al_draw_bitmap(WHITE,LARGURA_TELA-2*BOTAO_L,ALTURA_TELA-10*BOTAO_A-desloc,0);

        // Botoes de add e remove
        al_draw_bitmap(button_remove,LARGURA_TELA-2*BOTAO_L,ALTURA_TELA-13*BOTAO_A-desloc,0);
        al_draw_bitmap(button_add,LARGURA_TELA-2*BOTAO_L,ALTURA_TELA-14*BOTAO_A-desloc,0);

        //al_draw_text(font, al_map_rgb(255, 255, 255), 10, 10, 0 , *pause== 0?msg:"Pausado");
        //printf("FPS = %.2f\n",1/((double) (end - begin) / CLOCKS_PER_SEC));

        al_flip_display();
}

void le_valor_teclado(float* valor)
{
    float resultado = 0;
    int state = WAITING;
    printf("\n");
    while(state!=EXIT)
    {
        while (!al_is_event_queue_empty(fila_eventos))
        {
            al_wait_for_event(fila_eventos, &evento);
            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    state = EXIT;
                }
                else if (evento.keyboard.keycode == ALLEGRO_KEY_0)
                {
                    state = WAITING;
                    resultado = resultado*10;
                    resultado = resultado +0;
                }
                else if (evento.keyboard.keycode == ALLEGRO_KEY_1)
                {
                    state = WAITING;
                    resultado = resultado*10;
                    resultado = resultado+1;
                }
                else if (evento.keyboard.keycode == ALLEGRO_KEY_2)
                {
                    state = WAITING;
                    resultado = resultado*10;
                    resultado = resultado+2;
                }
                else if (evento.keyboard.keycode == ALLEGRO_KEY_3)
                {
                    state = WAITING;
                    resultado = resultado*10;
                    resultado = resultado+3;
                }
                else if (evento.keyboard.keycode == ALLEGRO_KEY_4)
                {
                    state = WAITING;
                    resultado = resultado*10;
                    resultado = resultado+4;
                }
                else if (evento.keyboard.keycode == ALLEGRO_KEY_5)
                {
                    state = WAITING;
                    resultado = resultado*10;
                    resultado = resultado+5;
                }
                else if (evento.keyboard.keycode == ALLEGRO_KEY_6)
                {
                    state = WAITING;
                    resultado = resultado*10;
                    resultado = resultado+6;
                }
                else if (evento.keyboard.keycode == ALLEGRO_KEY_7)
                {
                    state = WAITING;
                    resultado = resultado*10;
                    resultado = resultado+7;
                }
                else if (evento.keyboard.keycode == ALLEGRO_KEY_8)
                {
                    state = WAITING;
                    resultado = resultado*10;
                    resultado = resultado+8;
                }
                else if (evento.keyboard.keycode == ALLEGRO_KEY_9)
                {
                    state = WAITING;
                    resultado = resultado*10;
                    resultado = resultado+9;
                }
            }
        }
    }
    *valor = resultado;
}
//********* Funcoes do programa *************//

//********* Funcao principal ****************//
int cad_system(void)
{
    // Variavel state configura uma maquina de estados - Definicoes em Functions.h
    int state = WAITING; // State

    // Lista generica com os desenhos
    ListaGen* Lista = NULL; // Lista com os desenhos

    // Variaveis utilizadas
    bool pause = 0;
    int corR=0,corG=0,corB=0; // Black = Default
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
                            if(add_flag)
                                insere_linha_allegro(corR,corG,corB,&Lista);
                            printf("\nBotao linha simples");
                        }
                        else if(evento.mouse.y <= ALTURA_TELA - 1*BOTAO_A - desloc && evento.mouse.y >= ALTURA_TELA - 2*BOTAO_A -desloc)
                        {
                            if(add_flag)
                                insere_triangulo_allegro(corR,corG,corB,NOT_FILLED,&Lista);
                            printf("\nBotao triangulo simples");
                        }
                        else if(evento.mouse.y <= ALTURA_TELA - 2*BOTAO_A - desloc && evento.mouse.y >= ALTURA_TELA - 3*BOTAO_A -desloc)
                        {
                            if(add_flag)
                                insere_triangulo_allegro(corR,corG,corB,FILLED,&Lista);
                            printf("\nBotao triangulo colorido");
                        }
                        else if(evento.mouse.y <= ALTURA_TELA - 3*BOTAO_A - desloc && evento.mouse.y >= ALTURA_TELA - 4*BOTAO_A -desloc)
                        {
                            if(add_flag)
                                insere_retangulo_allegro(corR,corG,corB,NOT_ROUNDED,NOT_FILLED,&Lista);
                            printf("\nBotao retangulo simples");
                        }
                        else if(evento.mouse.y <= ALTURA_TELA - 4*BOTAO_A - desloc && evento.mouse.y >= ALTURA_TELA - 5*BOTAO_A -desloc)
                        {
                            if(add_flag)
                                insere_retangulo_allegro(corR,corG,corB,NOT_ROUNDED,FILLED,&Lista);
                            printf("\nBotao retangulo colorido");
                        }
                        else if(evento.mouse.y <= ALTURA_TELA - 5*BOTAO_A - desloc && evento.mouse.y >= ALTURA_TELA - 6*BOTAO_A -desloc)
                        {
                            if(add_flag)
                                insere_retangulo_allegro(corR,corG,corB,ROUNDED,NOT_FILLED,&Lista);
                            printf("\nBotao retangulo arredondado");
                        }
                        else if(evento.mouse.y <= ALTURA_TELA - 6*BOTAO_A - desloc && evento.mouse.y >= ALTURA_TELA - 7*BOTAO_A -desloc)
                        {
                            if(add_flag)
                                insere_retangulo_allegro(corR,corG,corB,ROUNDED,FILLED,&Lista);
                            printf("\nBotao retangulo arredondado colorido");
                        }
                        else if(evento.mouse.y <= ALTURA_TELA - 7*BOTAO_A - desloc && evento.mouse.y >= ALTURA_TELA - 8*BOTAO_A -desloc)
                        {
                            if(add_flag)
                                insere_elipse_allegro(corR,corG,corB,NOT_FILLED,&Lista);
                            printf("\nBotao elipse simples");
                        }
                        else if(evento.mouse.y <= ALTURA_TELA - 8*BOTAO_A - desloc && evento.mouse.y >= ALTURA_TELA - 9*BOTAO_A -desloc)
                        {
                            if(add_flag)
                                insere_elipse_allegro(corR,corG,corB,FILLED,&Lista);
                            printf("\nBotao elipse colorida");
                        }
                        else if(evento.mouse.y <= ALTURA_TELA - 9*BOTAO_A - desloc && evento.mouse.y >= ALTURA_TELA - 10*BOTAO_A -desloc)
                        {
                            if(add_flag)
                                insere_circulo_allegro(corR,corG,corB,NOT_FILLED,&Lista);
                            printf("\nBotao circulo simples");
                        }
                        else if(evento.mouse.y <= ALTURA_TELA - 10*BOTAO_A - desloc && evento.mouse.y >= ALTURA_TELA - 11*BOTAO_A -desloc)
                        {
                            if(add_flag)
                                insere_circulo_allegro(corR,corG,corB,FILLED,&Lista);
                            printf("\nBotao circulo colorido");
                        }
                        else if(evento.mouse.y <= ALTURA_TELA - 11*BOTAO_A - desloc && evento.mouse.y >= ALTURA_TELA - 12*BOTAO_A -desloc)
                        {
                            if(add_flag)
                                insere_arco(corR,corG,corB,&Lista);
                            printf("\nBotao arco");
                        }
                    }

                    // Botoes de ADD ou REMOVE
                    if (evento.mouse.x >= LARGURA_TELA - 2*BOTAO_L)
                    {
                        if(evento.mouse.y <= ALTURA_TELA - 12*BOTAO_A - desloc && evento.mouse.y >= ALTURA_TELA - 13*BOTAO_A -desloc)
                        {
                            add_flag = 0;
                            printf("\nBotao REMOVE");
                        }
                        else if(evento.mouse.y <= ALTURA_TELA - 13*BOTAO_A - desloc && evento.mouse.y >= ALTURA_TELA - 14*BOTAO_A -desloc)
                        {
                            add_flag = 1;
                            printf("\nBotao ADD");
                        }
                    }

                    // Botoes de cores
                    if (evento.mouse.x >= LARGURA_TELA - 2*BOTAO_L && evento.mouse.x <= LARGURA_TELA - 1*BOTAO_L)
                    {

                        if(evento.mouse.y <= ALTURA_TELA - 0*BOTAO_A - desloc && evento.mouse.y >= ALTURA_TELA - BOTAO_A -desloc)
                        {
                            corR = 0; corG = 0; corB = 0;
                            printf("\nCor: Preto.");
                        }
                        else if(evento.mouse.y <= ALTURA_TELA - 1*BOTAO_A - desloc && evento.mouse.y >= ALTURA_TELA - 2*BOTAO_A -desloc)
                        {
                            corR = 94; corG = 28; corB = 13;
                            printf("\nCor: Marrom");
                        }
                        else if(evento.mouse.y <= ALTURA_TELA - 2*BOTAO_A - desloc && evento.mouse.y >= ALTURA_TELA - 3*BOTAO_A -desloc)
                        {
                            corR = 255; corG = 0; corB = 0;
                            printf("\nCor: Vermelho");
                        }
                        else if(evento.mouse.y <= ALTURA_TELA - 3*BOTAO_A - desloc && evento.mouse.y >= ALTURA_TELA - 4*BOTAO_A -desloc)
                        {
                            corR = 255; corG = 116; corB = 21;
                            printf("\nCor: Laranja");
                        }
                        else if(evento.mouse.y <= ALTURA_TELA - 4*BOTAO_A - desloc && evento.mouse.y >= ALTURA_TELA - 5*BOTAO_A -desloc)
                        {
                            corR = 255; corG = 217; corB = 0;
                            printf("\nCor: Amarelo");
                        }
                        else if(evento.mouse.y <= ALTURA_TELA - 5*BOTAO_A - desloc && evento.mouse.y >= ALTURA_TELA - 6*BOTAO_A -desloc)
                        {
                            corR = 0; corG = 255; corB = 0;
                            printf("\nCor: Verde");
                        }
                        else if(evento.mouse.y <= ALTURA_TELA - 6*BOTAO_A - desloc && evento.mouse.y >= ALTURA_TELA - 7*BOTAO_A -desloc)
                        {
                            corR = 0; corG = 0; corB = 255;
                            printf("\nCor: Azul");
                        }
                        else if(evento.mouse.y <= ALTURA_TELA - 7*BOTAO_A - desloc && evento.mouse.y >= ALTURA_TELA - 8*BOTAO_A -desloc)
                        {
                            corR = 69; corG = 0; corB = 68;
                            printf("\nCor: Violeta");
                        }
                        else if(evento.mouse.y <= ALTURA_TELA - 8*BOTAO_A - desloc && evento.mouse.y >= ALTURA_TELA - 9*BOTAO_A -desloc)
                        {
                            corR = 117; corG = 117; corB = 117;
                            printf("\nCor: Cinza");
                        }
                        else if(evento.mouse.y <= ALTURA_TELA - 9*BOTAO_A - desloc && evento.mouse.y >= ALTURA_TELA - 10*BOTAO_A -desloc)
                        {
                            corR = 255; corG = 255; corB = 255;
                            printf("\nCor: Branca");
                        }
                    }
                }
            }
        }

    while(((double) (end - begin) / CLOCKS_PER_SEC)<(1./FPS) && !pause) //define FPS maxima
        end = clock();

    atualiza_tela(&pause,Lista);
    }
    return state;
}

//*********** Funcoes de insercao e remocao de elementso ************//
void insere_linha_allegro(const float corR,const float corG,const float corB,ListaGen** Lista)
{
    ListaGen* novo = (ListaGen*) malloc(sizeof(ListaGen));
    if (novo == NULL) exit(EXIT_FAILURE); // nao ha mais espaco na memoria

    Linha* linhanovo = (Linha*) malloc(sizeof(Linha));
    if (linhanovo == NULL) exit(EXIT_FAILURE); // nao ha mais espaco na memoria

    float value;
    linhanovo->colorR = corR;
    linhanovo->colorG = corG;
    linhanovo->colorB = corB;

    al_show_native_message_box(NULL,"Linha","","Digite a coordenada x1 e tecle <ENTER>.",NULL,NULL);
    le_valor_teclado(&value);
    linhanovo->x1 = value;
    al_show_native_message_box(NULL,"Linha","","Digite a coordenada y1 e tecle <ENTER>.",NULL,NULL);
    le_valor_teclado(&value);
    linhanovo->y1 = value;
    al_show_native_message_box(NULL,"Linha","","Digite a coordenada x2 e tecle <ENTER>.",NULL,NULL);
    le_valor_teclado(&value);
    linhanovo->x2 = value;
    al_show_native_message_box(NULL,"Linha","","Digite a coordenada y2 e tecle <ENTER>.",NULL,NULL);
    le_valor_teclado(&value);
    linhanovo->y2 = value;
    al_show_native_message_box(NULL,"Linha","","Digite a espessura da linha e tecle <ENTER>.",NULL,NULL);
    le_valor_teclado(&value);
    linhanovo->thickness = value;

    novo->tipo = LINE;
    novo->info = linhanovo;
    novo->prox = *Lista;
    *Lista = novo; // aponta para o novo item da lista
}

void insere_triangulo_allegro(const float corR,const float corG,const float corB,const int filled,ListaGen** Lista)
{
    ListaGen* novo = (ListaGen*) malloc(sizeof(ListaGen));
    if (novo == NULL) exit(EXIT_FAILURE); // nao ha mais espaco na memoria

    Tri* trinovo = (Tri*) malloc(sizeof(Tri));
    if (trinovo == NULL) exit(EXIT_FAILURE); // nao ha mais espaco na memoria

    float value;
    trinovo->colorR = corR;
    trinovo->colorG = corG;
    trinovo->colorB = corB;
    trinovo->filled = filled;

    al_show_native_message_box(NULL,"Triangulo","","Digite a coordenada x1 e tecle <ENTER>.",NULL,NULL);
    le_valor_teclado(&value);
    trinovo->x1 = value;
    al_show_native_message_box(NULL,"Triangulo","","Digite a coordenada y1 e tecle <ENTER>.",NULL,NULL);
    le_valor_teclado(&value);
    trinovo->y1 = value;
    al_show_native_message_box(NULL,"Triangulo","","Digite a coordenada x2 e tecle <ENTER>.",NULL,NULL);
    le_valor_teclado(&value);
    trinovo->x2 = value;
    al_show_native_message_box(NULL,"Triangulo","","Digite a coordenada y2 e tecle <ENTER>.",NULL,NULL);
    le_valor_teclado(&value);
    trinovo->y2 = value;
    al_show_native_message_box(NULL,"Triangulo","","Digite a coordenada x3 e tecle <ENTER>.",NULL,NULL);
    le_valor_teclado(&value);
    trinovo->x3 = value;
    al_show_native_message_box(NULL,"Triangulo","","Digite a coordenada y3 e tecle <ENTER>.",NULL,NULL);
    le_valor_teclado(&value);
    trinovo->y1 = value;
    if(!filled)
    {
        al_show_native_message_box(NULL,"Triangulo","","Digite a espessura da linha e tecle <ENTER>.",NULL,NULL);
        le_valor_teclado(&value);
        trinovo->thickness = value;
    }
    else
        trinovo->thickness = 0;

    novo->tipo = TRIANGLE;
    novo->info = trinovo;
    novo->prox = *Lista;
    *Lista = novo; // aponta para o novo item da lista
}

void insere_retangulo_allegro(const float corR,const float corG,const float corB,const int rounded,const int filled,ListaGen** Lista)
{
    ListaGen* novo = (ListaGen*) malloc(sizeof(ListaGen));
    if (novo == NULL) exit(EXIT_FAILURE); // nao ha mais espaco na memoria

    Ret* retnovo = (Ret*) malloc(sizeof(Ret));
    if (retnovo == NULL) exit(EXIT_FAILURE); // nao ha mais espaco na memoria

    float value;
    retnovo->colorR = corR;
    retnovo->colorG = corG;
    retnovo->colorB = corB;
    retnovo->filled = filled;

    al_show_native_message_box(NULL,"Retangulo","","Digite a coordenada x1 e tecle <ENTER>.",NULL,NULL);
    le_valor_teclado(&value);
    retnovo->x1 = value;
    al_show_native_message_box(NULL,"Retangulo","","Digite a coordenada y1 e tecle <ENTER>.",NULL,NULL);
    le_valor_teclado(&value);
    retnovo->y1 = value;
    al_show_native_message_box(NULL,"Retangulo","","Digite a coordenada x2 e tecle <ENTER>.",NULL,NULL);
    le_valor_teclado(&value);
    retnovo->x2 = value;
    al_show_native_message_box(NULL,"Retangulo","","Digite a coordenada y2 e tecle <ENTER>.",NULL,NULL);
    le_valor_teclado(&value);
    retnovo->y2 = value;

    if(rounded)
    {
        al_show_native_message_box(NULL,"Retangulo","","Digite o raio do arredondamento em X e tecle <ENTER>.",NULL,NULL);
        le_valor_teclado(&value);
        retnovo->rx = value;
        al_show_native_message_box(NULL,"Retangulo","","Digite o raio do arredondamento em Y e tecle <ENTER>.",NULL,NULL);
        le_valor_teclado(&value);
        retnovo->ry = value;
    }
    else
    {
        retnovo->rx = 0;
        retnovo->ry = 0;
    }
    if(!filled)
    {
        al_show_native_message_box(NULL,"Retangulo","","Digite a espessura da linha e tecle <ENTER>.",NULL,NULL);
        le_valor_teclado(&value);
        retnovo->thickness = value;
    }
    else
        retnovo->thickness = 0;

    novo->tipo = RECTANGLE;
    novo->info = retnovo;
    novo->prox = *Lista;
    *Lista = novo; // aponta para o novo item da lista
}

void insere_elipse_allegro(const float corR,const float corG,const float corB,const int filled,ListaGen** Lista)
{
    ListaGen* novo = (ListaGen*) malloc(sizeof(ListaGen));
    if (novo == NULL) exit(EXIT_FAILURE); // nao ha mais espaco na memoria

    Elip* elipnovo = (Elip*) malloc(sizeof(Elip));
    if (elipnovo == NULL) exit(EXIT_FAILURE); // nao ha mais espaco na memoria

    float value;
    elipnovo->colorR = corR;
    elipnovo->colorG = corG;
    elipnovo->colorB = corB;
    elipnovo->filled = filled;

    al_show_native_message_box(NULL,"Elipse","","Digite a coordenada do centro X e tecle <ENTER>.",NULL,NULL);
    le_valor_teclado(&value);
    elipnovo->cx = value;
    al_show_native_message_box(NULL,"Elipse","","Digite a coordenada do centro Y e tecle <ENTER>.",NULL,NULL);
    le_valor_teclado(&value);
    elipnovo->cy = value;
    al_show_native_message_box(NULL,"Elipse","","Digite o raio em X e tecle <ENTER>.",NULL,NULL);
    le_valor_teclado(&value);
    elipnovo->rx = value;
    al_show_native_message_box(NULL,"Elipse","","Digite o raio em Y e tecle <ENTER>.",NULL,NULL);
    le_valor_teclado(&value);
    elipnovo->ry = value;
    if(!filled)
    {
        al_show_native_message_box(NULL,"Elipse","","Digite a espessura da linha e tecle <ENTER>.",NULL,NULL);
        le_valor_teclado(&value);
        elipnovo->thickness = value;
    }
    else
        elipnovo->thickness = 0;

    novo->tipo = ELIPSE;
    novo->info = elipnovo;
    novo->prox = *Lista;
    *Lista = novo; // aponta para o novo item da lista
}

void insere_circulo_allegro(const float corR,const float corG,const float corB,const int filled,ListaGen** Lista)
{
    ListaGen* novo = (ListaGen*) malloc(sizeof(ListaGen));
    if (novo == NULL) exit(EXIT_FAILURE); // nao ha mais espaco na memoria

    Circ* circnovo = (Circ*) malloc(sizeof(Circ));
    if (circnovo == NULL) exit(EXIT_FAILURE); // nao ha mais espaco na memoria

    float value;
    circnovo->colorR = corR;
    circnovo->colorG = corG;
    circnovo->colorB = corB;
    circnovo->filled = filled;

    al_show_native_message_box(NULL,"Circulo","","Digite a coordenada do centro X e tecle <ENTER>.",NULL,NULL);
    le_valor_teclado(&value);
    circnovo->cx = value;
    al_show_native_message_box(NULL,"Circulo","","Digite a coordenada do centro Y e tecle <ENTER>.",NULL,NULL);
    le_valor_teclado(&value);
    circnovo->cy = value;
    al_show_native_message_box(NULL,"Circulo","","Digite o raio e tecle <ENTER>.",NULL,NULL);
    le_valor_teclado(&value);
    circnovo->r = value;
    if(!filled)
    {
        al_show_native_message_box(NULL,"Circulo","","Digite a espessura da linha e tecle <ENTER>.",NULL,NULL);
        le_valor_teclado(&value);
        circnovo->thickness = value;
    }
    else
        circnovo->thickness = 0;

    novo->tipo = CIRCLE;
    novo->info = circnovo;
    novo->prox = *Lista;
    *Lista = novo; // aponta para o novo item da lista
}

void insere_arco(const float corR,const float corG,const float corB,ListaGen** Lista)
{
    ListaGen* novo = (ListaGen*) malloc(sizeof(ListaGen));
    if (novo == NULL) exit(EXIT_FAILURE); // nao ha mais espaco na memoria

    Arco* arconovo = (Arco*) malloc(sizeof(Arco));
    if (arconovo == NULL) exit(EXIT_FAILURE); // nao ha mais espaco na memoria

    float value;
    arconovo->colorR = corR;
    arconovo->colorG = corG;
    arconovo->colorB = corB;

    al_show_native_message_box(NULL,"Arco","","Digite a coordenada do centro X e tecle <ENTER>.",NULL,NULL);
    le_valor_teclado(&value);
    arconovo->cx = value;
    al_show_native_message_box(NULL,"Arco","","Digite a coordenada do centro Y e tecle <ENTER>.",NULL,NULL);
    le_valor_teclado(&value);
    arconovo->cy = value;
    al_show_native_message_box(NULL,"Arco","","Digite o raio e tecle <ENTER>.",NULL,NULL);
    le_valor_teclado(&value);
    arconovo->r = value;
    al_show_native_message_box(NULL,"Arco","","Digite o angulo inicial e tecle <ENTER>.",NULL,NULL);
    le_valor_teclado(&value);
    arconovo->start_theta = value*0.0174532925;
    al_show_native_message_box(NULL,"Arco","","Digite o intervalo do angulo (delta) e tecle <ENTER>.",NULL,NULL);
    le_valor_teclado(&value);
    arconovo->delta_theta = value*0.0174532925;
    al_show_native_message_box(NULL,"Arco","","Digite a espessura da linha e tecle <ENTER>.",NULL,NULL);
    le_valor_teclado(&value);
    arconovo->thickness = value;

    novo->tipo = ARC;
    novo->info = arconovo;
    novo->prox = *Lista;
    *Lista = novo; // aponta para o novo item da lista
}

// Imprime a lista no console
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
