/**
 * Arquivo: labirinto.h
 * Versão : 1.0
 * Data   : 2024-09-08 23:45
 * -------------------------
 * Esta interface fornece uma biblioteca de operações primitivas para
 * simplificar a solução para o problema de encontrar a saída de um labirinto,
 * utilizando algoritmos recursivos de backtracking.
 *
 * Baseado em: Programming Abstractions in C, de Eric S. Roberts.
 *             Capítulo 6: Backtracking Algorithms (pg. 235-245).
 *
 * Prof.: Abrantes Araújo Silva Filho
 *        Computação Raiz:
 *            www.computacaoraiz.com.br
 *            www.youtube.com.br/computacaoraiz
 *            github.com/computacaoraiz
 *            twitter.com/ComputacaoRaiz
 *            www.linkedin.com/company/computacaoraiz
 *            www.abrantes.pro.br
 */

/* Inicia o boilerplate da interface: */
#ifndef _LABIRINTO_H
#define _LABIRINTO_H

#include "genlib.h"

/**
 * Tipo: pontoT
 * ------------
 * O tipo pontoT é usado para encapsular um par de inteiros que formam as
 * coordenadas x e y de um único ponto que indica uma posição no labirinto. A
 * separação da struct de seu typedef é feita por motivos didáticos.
 */
struct st_pontoT
{
    int x, y;
};

typedef struct st_pontoT pontoT;

/**
 * Tipo: direcaoT
 * --------------
 * O tipo direcaoT é usado para representar as quatro direções principais
 * da bússola, que são as direções que podemos nos mover a partir de um ponto
 * no labirinto. Implementado como uma enumeração. A separação da enum de seu
 * typedef é feita por motivos didáticos.
 */

enum en_direcaoT
{
    Norte, Leste, Sul, Oeste
};

typedef enum en_direcaoT direcaoT;

/**
 * Procedimento: ler_mapa_labirinto
 * Uso: ler_mapa_labirinto(arquivo);
 * ---------------------------------
 * Este procedimento lê o mapa de um labirinto a partir de um arquivo
 * específico passado como argumento, e armazena esse mapa em uma estrutura
 * de dados privada mantida por esta biblioteca. No arquivo com o mapa do
 * labirinto, os caracteres '+', '-' e '|' representam esquinas, paredes
 * verticais e paredes horizontais, respectivamente; espaços representam
 * passagens abertas. A posição inicial é indicada pelo caractere 'I'. Por
 * exemplo, o seguinte arquivo de dados define um mapa de um labirinto simples:
 *
 *        +-----+---+     A solução deve ser: andar 2 casas para cima, 4
 *        |     |         casas para direita, 2 casas para baixo, 2 casas
 *        + +-+ + +-+     para direita, 2 casas para cima, e 4 casas para
 *        |I  |     |     a direita (até sair do labirinto).
 *        +---+-----+
 *
 * As coordenadas são numeradas começando em (0, 0), no canto inferior esquerdo.
 * No exemplo acima, os 4 cantos do labirinto e o início estariam em:
 *        inf. esq. = ( 0, 0)
 *        inf. dir. = (10, 0)
 *        sup. esq. = ( 0, 4)
 *        sup. dir. = (10, 4)
 *        Início I  = ( 1, 1)
 */

void ler_mapa_labirinto (string arquivo);

/**
 * Função pegar_posicao_inicial
 * Uso: pt = pegar_posicao_inicial( );
 * -----------------------------------
 * Esta função retorna um pontoT indicando as coordenados do ponto de início.
 */

pontoT pegar_posicao_inicial (void);

/**
 * Predicado: saiu_do_labirinto
 * Uso: if (saiu_do_labirinto(pt)) ...
 * -----------------------------------
 * Este predicado retorna TRUE se o ponto especificado está fora do labirinto.
 */

bool saiu_do_labirinto (pontoT pt);

/**
 * Predicado: e_parede
 * Uso: if (e_parede(pt, dir)) ...
 * -------------------------------
 * Este predicado retorna TRUE se houver uma parede na direção (dir) indicada,
 * a partir do pontoT (pt) fornecido.
 */

bool e_parede (pontoT pt, direcaoT dir);

/**
 * Predicado: esta_marcado
 * Uso: if (esta_marcado(pt)) ...
 * ------------------------------
 * Este predicado retorna TRUE se o pontoT indicado por pt estiver marcado, ou
 * seja, já tiver sido visitado ao percorrer o labirinto.
 */

bool esta_marcado (pontoT pt);

/**
 * Procedimentos: marcar_ponto, desmarcar_ponto
 * Uso: marcar_ponto(pt);
 *      desmarcar_ponto(pt);
 * --------------------------------------------
 * Esses procedimentos marcam ou desmarcam o status de um pontoT (pt).
 */

void marcar_ponto (pontoT pt);
void desmarcar_ponto (pontoT pt);

/* Finaliza o boilerplate da interface: */
#endif
