/**
 * Arquivo: labirinto.c
 * Versão : 1.0
 * Data   : 2024-11-25
 * Autor  : Pedro Maia Dantas Nunes
 * Turma  : CC4M - Estrutura de Dados I
 * -------------------------
 * Implementação da interface definida em labirinto.h para resolver
 * problemas de labirintos utilizando backtracking.
 */

/*** Includes e Constantes simbólicas ***/

#include "labirinto.h"
#include "genlib.h"
#include <stdio.h>
#include <stdlib.h>

/*** Estrutura privada para armazenar o mapa do labirinto ***/

static char *mapa;
static int largura, altura;
static pontoT posicao_inicial;

/*** Funções internas ***/

/**
 * Função interna: indice
 * Uso: indice(x, y)
 * ---------------------------------
 * Essa função é utilizada para traduzir uma coordenada em um índice
 * para acessar o elemento correspondente do mapa, seguindo a lógica
 * de row-major order.
 */
static int indice(int x, int y) {
    y = altura - 1 - y;
    return (y * (largura + 1)) + x;
}

/*** Funções exportadas ***/

/**
 * Procedimento: ler_mapa_labirinto
 * Uso: ler_mapa_labirinto(arquivo)
 * ---------------------------------
 * Lê o mapa de um labirinto de um arquivo especificado e armazena as informações
 * em uma estrutura interna.
 */
void ler_mapa_labirinto(string arquivo) {
    FILE *arq = fopen(arquivo, "r");
    if (!arq) {
        printf("Erro ao abrir o arquivo: %s\n", arquivo);
        exit(1);
    }

    // Ir para o final do arquivo para obter o tamanho:
    fseek(arq, 0, SEEK_END);
    long tamanho = ftell(arq);
    rewind(arq); // Volta ao início do arquivo

    // Aloca o mapa:
    mapa = (char *)malloc((tamanho + 1) * sizeof(char));
    if (mapa == NULL) {
        printf("Erro ao alocar memória para o mapa.");
        exit(1);
    }

    // Ler o arquivo inteiro e acrescenta '\0' no final:
    fread(mapa, sizeof(char), tamanho, arq);
    mapa[tamanho] = '\0';

    int idxi; // Variável que armazena o indice da posicao inicial.
    altura = 0;
    for (int i = 0; mapa[i] != '\0'; i++) {
        if (mapa[i] == '\n')
            altura++;
        if (mapa[i] == 'I')
            idxi = i;
    }
    largura = (tamanho + 1 - altura) / altura;

    // Define a posição inicial através do índice do caractere 'I':
    posicao_inicial.x = idxi % (largura + 1);
    posicao_inicial.y = (altura - 1) - ( idxi / (largura + 1));

    printf("Mapa:\n%s\n", mapa);

    fclose(arq);
}

/**
 * Função: pegar_posicao_inicial
 * Uso: pt = pegar_posicao_inicial();
 * ------------------------------
 * Retorna as coordenadas do ponto inicial no labirinto.
 */
pontoT pegar_posicao_inicial(void) {
    return posicao_inicial;
}

/**
 * Predicado: saiu_do_labirinto
 * Uso: if ( saiu_do_labirinto(pt) )
 * ----------------------------
 * Retorna TRUE se o ponto especificado está fora do labirinto.
 */
bool saiu_do_labirinto(pontoT pt) {
    if (pt.x < 0 || pt.x >= largura || pt.y < 0 || pt.y >= altura) {
        mapa[indice(posicao_inicial.x, posicao_inicial.y)] = 'I';
        printf("Resolução:\n%s", mapa);

        // Libera o mapa da memória:
        free(mapa);
        mapa = NULL;

        return TRUE;
    }
    return FALSE;
}

/**
 * Predicado: e_parede
 * Uso: if ( e_parede(pt, dir) )
 * --------------------
 * Retorna TRUE se houver uma parede na direção indicada a partir do ponto especificado.
 */
bool e_parede(pontoT pt, direcaoT dir) {
    pontoT destino = pt;

    // Atualiza o destino com base na direção.
    switch (dir) {
        case Norte: 
            destino.y++; 
            break;
        case Sul: 
            destino.y--; 
            break;
        case Leste: 
            destino.x++; 
            break;
        case Oeste: 
            destino.x--; 
            break;
    }
    
    // Verifica se é parede.
    return (mapa[indice(destino.x, destino.y)] == '+' || mapa[indice(destino.x, destino.y)] == '-' || mapa[indice(destino.x, destino.y)] == '|');
}

/**
 * Predicado: esta_marcado
 * Uso: if ( esta_marcado(pt) )
 * ------------------------
 * Retorna TRUE se o ponto especificado estiver marcado.
 */
bool esta_marcado(pontoT pt) {

    return (mapa[indice(pt.x, pt.y)] == 'X');
}

/**
 * Procedimento: marcar_ponto
 * Uso: marcar_ponto(pt);
 * ---------------------------
 * Marca o ponto especificado como visitado.
 */
void marcar_ponto(pontoT pt) {
    
    mapa[indice(pt.x, pt.y)] = 'X';
}

/**
 * Procedimento: desmarcar_ponto
 * Uso: desmarcar_ponto(pt);
 * ------------------------------
 * Desmarca o ponto especificado, indicando que não foi visitado.
 */
void desmarcar_ponto(pontoT pt) {
    
    mapa[indice(pt.x, pt.y)] = ' ';
}
