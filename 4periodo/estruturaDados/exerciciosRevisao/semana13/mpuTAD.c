/**
 * Arquivo: mpuTAD.c
 * Versão : 1.0
 * Data: 2024−10−30 15:25
 * −−−−−−−−−−−−−−−−−−−−−−−−−
 * Este arquivo implementa a interface mpuTAD.h.
 *
 * Aluno: Pedro Maia Dantas Nunes
 */
 
 /***	Includes:	***/
 
 #include "mpuTAD.h"
 #include <stdio.h>
 
 /***	Tipos abstratos de dados:	***/
 
 /**
  *	TIPO DE DADO:	MPU
  *	-------------------
  *	Implementação do tipo de dado MPU, que armazena os valores medidos e
  * tratados de aceleração e rotação entre os eixos X, Y e Z,
  *	além das configurações de sensibilidade.
  */
  
 struct st_MPU
 {
 	int ax;
 	int ay;
 	int az;
 	int rx;
 	int ry;
 	int rz;
 	int sensi_aceleracao;
 	int sensi_rotacao;
};

/**
 *	FUNÇÃO: criar_MPU
 *	Uso: criar_MPU();
 *	-----------------
 *	Um MPU é um ponteiro para uma st_MPU e, portanto, essa função
 *	retorna um ponteiro para essa struct.
 *	(indiretamente, através do retorno de um MPU)
 */

MPU criar_MPU(){
	MPU mpu = malloc(sizeof(struct st_MPU));
	if(mpu == NULL){
		printf("Nao foi possivel criar o MPU!\n");
		exit(1);
	}
	return mpu;
} 

/**
 *	FUNÇÃO: apagar_MPU
 *	Uso: apagar_MPU(&M);
 *	--------------------
 * Este procedimento recebe um PONTEIRO para um MPU como argumento e libera
 * a memória alocada para esse MPU, fazendo com que o MPU aponte para
 * NULL para evitar dangling pointer. É necessário utilizar um PONTEIRO para um
 * MPU pois, caso contrário, não seria possível atribuir o valor NULL ao
 * MPU que está sendo desalocado (ponteiros são passados por valor).
 */

void apagar_MPU(MPU *M){
	if (*M != NULL){
		free (*M);
		*M = NULL;
	}
}













