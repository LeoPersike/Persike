Estrutura do Código

A princípio será desenvolvido um software com formas geométricas básicas. Conforme o desenvolvimento do projeto serão adicionadas formas geométricas mais complexas, caso haja tempo.

As formas geométricas (e suas estruturas definidas pela biblioteca Allegro5) estão listadas a seguir:

Estrutura linha simples
Conteúdo: Coordenadas (x1,y1) (x2,y2)
	  Cor R, Cor G, Cor B (0-255)
	  Largura da linha	
	
Estrutura triangulo
Conteúdo: Vertices (x1,y1) (x2,y2) (x3,y3)
	  Cor R, Cor G, Cor B (0-255)
	  Largura da linha	
	  Campo para identificacao se a figura e colorida ou se é apenas a linha em volta.

Estrutura retangulo
Conteúdo: Coordenadas superior esquerdo (x1,y1) e inferior direito (x2,y2)
	  Arredondamento da borda (rx,ry)
	  Cor R, Cor G, Cor B (0-255)
	  Largura da linha
	  Campo para identificacao se a figura e colorida ou se é apenas a linha em volta.	

Estrutura elipse
Conteúdo: Coordenadas do centro (cx,cy)
	  Raios X e Y (rx,ry)
	  Cor R, Cor G, Cor B (0-255)
	  Largura da linha	
	  Campo para identificacao se a figura e colorida ou se é apenas a linha em volta.

Estrutura circulo
Conteúdo: Coordenadas do centro (cx,cy)
	  Raio do circulo (r)
	  Cor R, Cor G, Cor B (0-255)
	  Largura da linha	
	  Campo para identificacao se a figura e colorida ou se é apenas a linha em volta.

Estrutura arco
Conteúdo: Coordenadas do centro (cx,cy)
	  Raio do circulo (r)
	  Angulo inicial (start_theta) e delta (delta_theta)
	  Cor R, Cor G, Cor B (0-255)
	  Largura da linha	


As funcoes e propotipos utilizadas pelo programa estão listadas abaixo:
Funcao principal que ira controlar o CAD
cad_system(void);

Funcao para inserir uma linha na lista:
void insere_linha_allegro(const float corR,const float corG,const float corB,ListaGen** Lista);

Funcao para inserir um triangulo na lista:
void insere_triangulo_allegro(const float corR,const float corG,const float corB,const int filled,ListaGen** Lista);

Funcao para inserir uma retangulo na lista:
void insere_retangulo_allegro(const float corR,const float corG,const float corB,const int rounded,const int filled,ListaGen** Lista);

Funcao para inserir uma elipse na lista:
void insere_elipse_allegro(const float corR,const float corG,const float corB,const int filled,ListaGen** Lista);

Funcao para inserir um circulo na lista:
void insere_circulo_allegro(const float corR,const float corG,const float corB,const int filled,ListaGen** Lista);

Funcao para inserir um arco na lista:
void insere_arco_allegro(const float corR,const float corG,const float corB,ListaGen** Lista);

Funcao para remover desenhos
void remove_draw(const int type,const int filled,const int rounded,ListaGen** Lista);

Funcao para mostrar a lista no console:
void imprime_lista(ListaGen* Lista);


As funcoes para a interface grafica estao listadas abaixo:
Funcao responsavel por fazer todas as inicializacoes do allegro e criacao da janela principal
graphic_init(void);

Funcao responsavel por fechar a janela e eventos do allegro
void fechajanela(void);

Funcao responsavel por atualizar a interface grafica
void atualiza_tela(bool* pause);


