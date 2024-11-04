/**
 * Arquivo: pilhampuTAD.c
 * Versão : 1.0
 * Data: 2024−11-04 17:19
 * −−−−−−−−−−−−−−−−−−−−−−−−−
 * Este arquivo implementa a interface pilhampuTAD.h.
 *
 * Aluno: Pedro Maia Dantas Nunes
 */
 
/***	Includes:	***/
 

#include "mpuTAD.h"
#include "pilhampuTAD.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

 
/*** Constantes Simbólicas: ***/

/**
 * CONSTANTE: TAMMAX
 * −−−−−−−−−−−−−−−−−
 * Esta constante especifica o tamanho máximo de espaço a ser alocado para o
 * array que armazenará os elementos do stack. Se o usuário fizer um push de
 * elementos além deste limite, receberá um erro.
 */
#define TAMMAX 100
 
/***	Tipos abstratos de dados:	***/
 
/**
 * TIPO: stackTCD
 * −−−−−−−−−−−−−−
 * O tipo stackTCD é a representação concreta do tipo abstrato de dado stackTAD
 * definido na interface. Nesta implementação os elementos serão armazenados em
 * um array. Como a definição do stackTCD aparece apenas na implementação, e não
 * na interface, podemos alterar esta definição à vontade, desde que a interface
 * não seja alterada e o comportamento do stack seja mantido. A variável inteira
 * "contagem" manterá o número atual de elementos no stack.
 */


struct stackTCD{
	elementoT dados[TAMMAX];
	int contagem;
};

/*** Definições de Subprogramas (comportamentos): ***/

/**
 * FUNÇÃO: criar_stackTAD
 * Uso: stackTAD = criar_stackTAD( );
 * −−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
 * Aloca memória suficiente para um stackTCD e retorna um ponteiro para esse
 * objeto, através do tipo abstrato stackTAD. Retorna NULL se não for possível
 * alocar a memória.
 */


stackTAD criar_stackTAD(){
	stackTAD S = malloc(sizeof(struct stackTCD));
	if (S == NULL){
		fprintf(stderr, "Erro: não foi possível alocar o stack.\n");
		return NULL;
	}
	S->contagem = 0;
	return S;
}

/**
 * PROCEDIMENTO: apagar_stackTAD
 * Uso: apagar_stackTAD(&stackTAD);
 * −−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
 * Ao receber um PONTEIRO para um stackTAD, ou seja, um ponteiro para um
 * ponteiro para stackTCD, libera a memória alocada para o stackTCD e atribui
 * NULL para o ponteiro original (para evitar dangling pointer). Se o
 * ponteiro original já aponta para NULL, não faz nada.
 */
void apagar_stackTAD (stackTAD *stack){
	if (*stack != NULL){
		free(*stack);
		*stack = NULL;
	}
}

/**
 * PROCEDIMENTO: push
 * Uso: push(stack, elemento);
 * −−−−−−−−−−−−−−−−−−−−−−−−−−−
 * Este procedimento coloca o elemento especificado no topo do stack.
 */
void push (stackTAD stack, elementoT elemento){
	if (stack == NULL)
		fprintf(stderr, "Erro: push em stack null.\n");
	else if (cheia(stack))
		fprintf(stderr, "Erro: o stack está cheio.\n");
	else
		stack->dados[stack->contagem++] = elemento;
}
/**
 * FUNÇÃO: pop
 * Uso: elemento = pop(stack);
 * −−−−−−−−−−−−−−−−−−−−−−−−−−−
 * Retorna o elemento do topo da pilha, ou exibe uma mensagem de erro apropriada
 */
elementoT pop (stackTAD stack){
	if (stack == NULL){
		fprintf(stderr, "Erro: pop em stack null.\n");
		exit(1);
	}
	else if (vazia(stack)){
		fprintf(stderr, "Erro: stack vazio.\n");
		exit(1);
	}
	return stack->dados[--stack->contagem];
}

/**
 * PREDICADOS: vazia, cheia
 * Uso: if (vazia(stack)) . . .
 *		if (cheia(stack)) . . .
 * −−−−−−−−−−−−−−−−−−−−−−−−−−−−
 * Estes predicados retornam 1 caso a pilha esteja vazia ou cheia,
 * respectivamente. Se o stack for dinâmico, ou seja, sem um tamanho máximo
 * pré−definido, o predicado "cheia" sempre retornará 0.
 */
int vazia (stackTAD stack){
	if (stack == NULL){
		printf("Erro: stack null.\n");
		exit(1);
	}
	if(stack->contagem == 0){
		return 1;
	} else
		return 0;
}

int cheia (stackTAD stack){
	if (stack == NULL){
		printf("Erro: stack null.\n");
		exit(1);
	}
	if(stack->contagem == TAMMAX){
		return 1;
	} else
		return 0;
}

/**
 * FUNÇÃO: tamanho
 * Uso: n = tamanho(stack);
 * −−−−−−−−−−−−−−−−−−−−−−−−
 * Retorna o tamanho do stack.
 */
long int tamanho (stackTAD stack){
	if (stack == NULL){
		fprintf(stderr, "Erro: tamanho de stack null.\n");
		return -1;
	}
	return (long int) TAMMAX;
}

