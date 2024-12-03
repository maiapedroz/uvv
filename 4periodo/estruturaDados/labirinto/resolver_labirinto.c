/**
 * Arquivo: resolver_labirinto.c
 * Versão : 1.0
 * Data   : 2024-11-25
 * -------------------------
 * Este é o programa cliente que utiliza a biblioteca "labirinto.h" para
 * encontrar a saída de um labirinto utilizando algoritmos recursivos de
 * backtracking.
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

#include "genlib.h"
#include "labirinto.h"
#include "simpio.h"

/* Declarações de subprogramas: */

bool resolver_labirinto (pontoT pt);
pontoT novo_ponto (pontoT pt, direcaoT dir);

/* Função Main: */

int main (void)
{
    ler_mapa_labirinto("arquivo.txt");

    if (resolver_labirinto(pegar_posicao_inicial()))
        printf("Os Xs levam a saída\n");
    else
        printf("Não existe saída.\n");
}

/* Definições de Subprogramas: */

/**
 * Predicado: resolver_labirinto
 * Uso: if (resolver_labirinto(pt)) ...
 * ------------------------------------
 * Este predicado implementa uma solução recursiva para o labirinto atual
 * a partir do ponto pt, utilizando algoritmos de backtracking. Retorna TRUE
 * se o labirinto (a partir daqui, do ponto pt) tem solução, e FALSE caso
 * contrário. Esta implementação utiliza recursão para resolver os
 * sub-labirintos que foram decompostos do labirinto atual a partir da
 * marcação da posição atual e movendo-se um passo ao longo de todas as
 * passagens abertas.
 */

bool resolver_labirinto (pontoT pt)
{
    direcaoT dir;

    if (saiu_do_labirinto(pt)) return TRUE;
    if (esta_marcado(pt)) return FALSE;

    marcar_ponto(pt);
    for (dir = Norte; dir <= Oeste; dir++)
    {
        if (!e_parede(pt, dir))
        {
            if (resolver_labirinto(novo_ponto(pt, dir)))
                return TRUE;
        }
    }
    desmarcar_ponto(pt);
    return FALSE;
}

/**
 * Função: novo_ponto
 * Uso: pt = novo_ponto(pt, dir);
 * ------------------------------
 * Esta função retorna um novo pontoT a partir de um ponto de partida (pt) e uma
 * direção (dir). Ela não "anda" no labirinto, apenas retorna as coordenadas do
 * ponto que será alcançado (novo_ponto) a partir do ponto atual (pt) se
 * seguirmos na direção indicada (dir).
 */

pontoT novo_ponto (pontoT pt, direcaoT dir)
{
    pontoT novo_ponto = pt;
    switch (dir)
    {
    case Norte: novo_ponto.y++; break;
    case Leste: novo_ponto.x++; break;
    case Sul:   novo_ponto.y--; break;
    case Oeste: novo_ponto.x--; break;
    }
    return novo_ponto;
}
