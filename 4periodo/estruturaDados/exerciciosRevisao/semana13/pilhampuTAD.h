/**
 * Arquivo: pilhampuTAD.h
 * Versão : 1.0
 * Data: 2024−11−04 16:44
 * −−−−−−−−−−−−−−−−−−−−−−−−−
 * Esta interface cria uma pilha para armazenar até 100 MPUs
 *
 * Aluno: Pedro Maia Dantas Nunes
 */
 
 
/* Inicia boilerplate da interface: */
#ifndef _PILHAMPUTAD_H
#define _PILHAMPUTAD_H

/*** Includes: ***/
#include "mpuTAD.h"

/*** Tipos de Dados: ***/

/* Seção 1: tipos concretos de dados */
/**
 * TIPO: elementoT
 * −−−−−−−−−−−−−−−
 * O tipo "elementoT" é utilizado nesta interface para indicar o tipo de dado
 * dos valores que serão armazenados no stack. Nesta interface, por padrão, 
 *	o tipo de dado armazenado é "MPU".
 *
 */
typedef MPU elementoT;


/* Seção 2: tipos abstratos de dados */

/**
 * TIPO ABSTRATO: stackTAD
 * −−−−−−−−−−−−−−−−−−−−−−−
 * O tipo stackTAD repersenta um tipo abstrato que é uma pilha, para armazenar
 * os elementos do tipo "elementoT". Como o stackTAD é definido apenas como um
 * ponteiro para uma estrutura concreta que não está definida nesta interface,
 * os clientes não têm acesso à implementação interna.
 */
typedef struct stackTCD *stackTAD;


/*** Declarações de Subprogramas: ***/

/**
 * FUNÇÃO: criar_stackTAD
 * Uso: stackTAD = criar_stackTAD();
 * −−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
 * Esta função aloca e retorna um novo stack, que está inicialmente vazio. Se
 * ocorrer algum erro na criação do stack, será retornado NULL.
 */
stackTAD criar_stackTAD();

/**
 * FUNÇÃO: apagar_stackTAD
 * Uso: apagar_stackTAD(&stackTAD);
 * −−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
 * Este procedimento libera o armazenamento alocado para o stackTAD. Note que o
 * argumento é um PONTEIRO para um stack.
 */
void apagar_stackTAD (stackTAD *stack);

/**
 * FUNÇÃO: push
 * Uso: push(stack, elemento);
 * −−−−−−−−−−−−−−−−−−−−−−−−−−−
 * Este procedimento coloca o elemento especificado no topo do stack.
 */
void push (stackTAD stack, elementoT elemento);

/**
 * FUNÇÃO: pop
 * Uso: elemento = pop(stack);
 * −−−−−−−−−−−−−−−−−−−−−−−−−−−
 * Esta função retira o elemento que está no topo da pilha e retorna esse
 * elemento. O valor a ser retirado é sempre o último que entrou na pilha por
 * último. Se o stack for null ou estiver vazio, é exibida uma mensagem de erro.
 *
 */
elementoT pop (stackTAD stack);

/**
 * PREDICADOS: vazia, cheia
 * Uso: if (vazia(stack)) . . .
 *		if (cheia(stack)) . . .
 * −−−−−−−−−−−−−−−−−−−−−−−−−−−−
 * Estes predicados retornam TRUE caso a pilha esteja vazia ou cheia,
 * respectivamente. Se o stack for dinâmico, ou seja, sem um tamanho máximo
 * pré−definido, o predicado "cheia" sempre retornará FALSE.
 */
int vazia (stackTAD stack);
int cheia (stackTAD stack);

/**
 * FUNÇÃO: tamanho
 * Uso: n = tamanho(stack);
 * −−−−−−−−−−−−−−−−−−−−−−−−
 * Esta função retorna o tamanho do stack, ou seja, quantos elementos este stack
 * pode armazenar.
 */
long int tamanho (stackTAD stack);

/*	Finaliza boilerplate:	*/

#endif
