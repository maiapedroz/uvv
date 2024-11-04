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
 #include <math.h>
 #include <stdlib.h>
 
 /***	Defines:	***/
 
 #define S_ACEL 2048		// constante relacionada a sensibilidade de aceleração
 #define S_ROT 16.4			// constante relacionada a sensibilidade de rotação
 #define S_ROT_2 65.5		// constante bugada relacionada a sensibildiade de rotação
 
 /***	Tipos abstratos de dados:	***/
 
 /**
  *	TIPO DE DADO:	MPU
  *	-------------------
  *	Implementação do tipo de dado MPU, que armazena os valores medidos e
  * tratados de aceleração e rotação entre os eixos X, Y e Z,
  * além das configurações de sensibilidade.
  */
  
 struct st_MPU
 {
 	int acelX;
 	int acelY;
 	int acelZ;
 	int rotX;
 	int rotY;
 	int rotZ;
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

/**
 * FUNÇÃO: set_ax
 * Uso: set_ax(MPU mpu, int ax);
 * -----------------
 * Verifica se o MPU não é nulo e atribui aceleração ax no eixo X.
 */

void set_ax(MPU mpu, int ax){
	if (mpu == NULL){
		printf("Erro ao atribuir a aceleração no sensor especificado.\n");
		exit(1);
	}
	mpu->acelX = ax;
}

/**
 * FUNÇÃO: set_ay
 * Uso: set_ay(MPU mpu, int ay);
 * -----------------
 * Verifica se o MPU não é nulo e atribui aceleração ay no eixo Y.
 */
void set_ay(MPU mpu, int ay){
	if (mpu == NULL){
		printf("Erro ao atribuir a aceleração no sensor especificado.\n");
		exit(1);
	}
	mpu->acelY = ay;
}

/**
 * FUNÇÃO: set_az
 * Uso: set_az(MPU mpu, int az);
 * -----------------
 * Verifica se o MPU não é nulo e atribui aceleração az no eixo Z.
 */
void set_az(MPU mpu, int az){
	if (mpu == NULL){
		printf("Erro ao atribuir a aceleração no sensor especificado.\n");
		exit(1);
	}
	mpu->acelZ = az;
}

/**
 * FUNÇÃO: set_rx
 * Uso: set_rx(MPU mpu, int rx);
 * -----------------
 * Verifica se o MPU não é nulo e atribui rotação rx no eixo X.
 */
void set_rx(MPU mpu, int rx){
	if (mpu == NULL){
		printf("Erro ao atribuir a rotação no sensor especificado.\n");
		exit(1);
	}
	mpu->rotX = rx;
}

/**
 * FUNÇÃO: set_ry
 * Uso: set_ry(MPU mpu, int ry);
 * -----------------
 * Verifica se o MPU não é nulo e atribui rotação ry no eixo Y.
 */
void set_ry(MPU mpu, int ry){
	if (mpu == NULL){
		printf("Erro ao atribuir a rotação no sensor especificado.\n");
		exit(1);
	}
	mpu->rotY = ry;
}

/**
 * FUNÇÃO: set_rz
 * Uso: set_rz(MPU mpu, int rz);
 * -----------------
 * Verifica se o MPU não é nulo e atribui rotação rz no eixo Z.
 */
void set_rz(MPU mpu, int rz){
	if (mpu == NULL){
		printf("Erro ao atribuir a rotação no sensor especificado.\n");
		exit(1);
	}
	mpu->rotZ = rz;
}

/**
 * FUNÇÃO: get_ax
 * Uso: int ax = get_ax(MPU mpu);
 * -----------------
 * Verifica se o MPU não é nulo e retorna a aceleração no eixo X.
 */
int get_ax(MPU mpu){
	if (mpu == NULL){
		printf("Erro ao obter a aceleração no sensor especificado.\n");
		exit(1);
	}
	return mpu->acelX;
}

/**
 * FUNÇÃO: get_ay
 * Uso: int ay = get_ay(MPU mpu);
 * -----------------
 * Verifica se o MPU não é nulo e retorna a aceleração no eixo Y.
 */
int get_ay(MPU mpu){
	if (mpu == NULL){
		printf("Erro ao obter a aceleração no sensor especificado.\n");
		exit(1);
	}
	return mpu->acelY;
}

/**
 * FUNÇÃO: get_az
 * Uso: int az = get_az(MPU mpu);
 * -----------------
 * Verifica se o MPU não é nulo e retorna a aceleração no eixo Z.
 */
int get_az(MPU mpu){
	if (mpu == NULL){
		printf("Erro ao obter a aceleração no sensor especificado.\n");
		exit(1);
	}
	return mpu->acelZ;
}

/**
 * FUNÇÃO: get_rx
 * Uso: int rx = get_rx(MPU mpu);
 * -----------------
 * Verifica se o MPU não é nulo e retorna a rotação no eixo X.
 */
int get_rx(MPU mpu){
	if (mpu == NULL){
		printf("Erro ao obter a rotação no sensor especificado.\n");
		exit(1);
	}
	return mpu->rotX;
}

/**
 * FUNÇÃO: get_ry
 * Uso: int ry = get_ry(MPU mpu);
 * -----------------
 * Verifica se o MPU não é nulo e retorna a rotação no eixo Y.
 */
int get_ry(MPU mpu){
	if (mpu == NULL){
		printf("Erro ao obter a rotação no sensor especificado.\n");
		exit(1);
	}
	return mpu->rotY;
}

/**
 * FUNÇÃO: get_rz
 * Uso: int rz = get_rz(MPU mpu);
 * -----------------
 * Verifica se o MPU não é nulo e retorna a rotação no eixo Z.
 */
int get_rz(MPU mpu){
	if (mpu == NULL){
		printf("Erro ao obter a rotação no sensor especificado.\n");
		exit(1);
	}
	return mpu->rotZ;
}

/**
 * FUNÇÃO: set_confAceleracao
 * Uso: set_confAceleracao(MPU mpu, int sensibilidade);
 * -----------------
 * Verifica se o MPU não é nulo e atribui a sensibilidade de aceleração.
 */
void set_confAceleracao(MPU mpu, int sensibilidade){
	if (mpu == NULL){
		printf("Erro ao atribuir a sensibilidade no sensor especificado.\n");
		exit(1);
	}
	if (sensibilidade < 1 || sensibilidade > 4) {
        printf("Sensibilidade deve estar entre 0 e 5.\n");
        exit(1);
    }
	mpu->sensi_aceleracao = sensibilidade;
}

/**
 * FUNÇÃO: set_confRotacao
 * Uso: set_confRotacao(MPU mpu, int sensibilidade);
 * -----------------
 * Verifica se o MPU não é nulo e atribui a sensibilidade de rotação.
 */
void set_confRotacao(MPU mpu, int sensibilidade){
	if (mpu == NULL){
		printf("Erro ao atribuir a sensibilidade no sensor especificado.\n");
		exit(1);
	}
	if (sensibilidade < 1 || sensibilidade > 4) {
        printf("Sensibilidade deve estar entre 0 e 5.\n");
        exit(1);
    }
	mpu->sensi_rotacao = sensibilidade;
}

/**
 * FUNÇÃO: get_confAceleracao
 * Uso: int sensibilidade = get_confAceleracao(MPU mpu);
 * -----------------
 * Verifica se o MPU não é nulo e retorna a sensibilidade de aceleração.
 */
int get_confAceleracao(MPU mpu){
	if (mpu == NULL){
		printf("Erro ao obter a sensibilidade do sensor especificado.\n");
		exit(1);
	}
	return mpu->sensi_aceleracao;
}

/**
 * FUNÇÃO: get_confRotacao
 * Uso: int sensibilidade = get_confRotacao(MPU mpu);
 * -----------------
 * Verifica se o MPU não é nulo e retorna a sensibilidade de rotação.
 */
int get_confRotacao(MPU mpu){
	if (mpu == NULL){
		printf("Erro ao obter a sensibilidade do sensor especificado.\n");
		exit(1);
	}
	return mpu->sensi_rotacao;
}

/**
 * FUNÇÃO: get_tratado_ax
 * Uso: double ax_tratado = get_tratado_ax(MPU mpu);
 * -----------------
 * Verifica se o MPU não é nulo e retorna a leitura tratada da aceleração no eixo X.
 */
double get_tratado_ax(MPU mpu){
	if (mpu == NULL){
		printf("Erro ao obter a leitura tratada do sensor especificado.\n");
		exit(1);
	}
	int fator_escala;
	fator_escala = S_ACEL * pow(2, 4 - mpu->sensi_aceleracao);
	
	return (mpu->acelX)/fator_escala;
}

/**
 * FUNÇÃO: get_tratado_ay
 * Uso: double ay_tratado = get_tratado_ay(MPU mpu);
 * -----------------
 * Verifica se o MPU não é nulo e retorna a leitura tratada da aceleração no eixo Y.
 */
double get_tratado_ay(MPU mpu){
	if (mpu == NULL){
		printf("Erro ao obter a leitura tratada do sensor especificado.\n");
		exit(1);
	}
	int fator_escala;
	fator_escala = S_ACEL * pow(2, 4 - mpu->sensi_aceleracao);
	
	return (mpu->acelY)/fator_escala;
}

/**
 * FUNÇÃO: get_tratado_az
 * Uso: double az_tratado = get_tratado_az(MPU mpu);
 * -----------------
 * Verifica se o MPU não é nulo e retorna a leitura tratada da aceleração no eixo Z.
 */
double get_tratado_az(MPU mpu){
	if (mpu == NULL){
		printf("Erro ao obter a leitura tratada do sensor especificado.\n");
		exit(1);
	}
	int fator_escala;
	fator_escala = S_ACEL * pow(2, 4 - mpu->sensi_aceleracao);
	
	return (mpu->acelZ)/fator_escala;
}

/**
 * FUNÇÃO: get_tratado_rx
 * Uso: double rx_tratado = get_tratado_rx(MPU mpu);
 * -----------------
 * Verifica se o MPU não é nulo e retorna a leitura tratada da rotação no eixo X.
 */
double get_tratado_rx(MPU mpu){
	if (mpu == NULL){
		printf("Erro ao obter a leitura tratada do sensor especificado.\n");
		exit(1);
	}
	int fator_escala;
	if (mpu->sensi_aceleracao < 3){
		fator_escala = S_ROT * pow(2, 4 - mpu->sensi_rotacao);
	} else{
		fator_escala = S_ROT_2 * pow(2, mpu->sensi_rotacao - 3);
	}
	
	return (mpu->rotX)/fator_escala;
}

/**
 * FUNÇÃO: get_tratado_ry
 * Uso: double ry_tratado = get_tratado_ry(MPU mpu);
 * -----------------
 * Verifica se o MPU não é nulo e retorna a leitura tratada da rotação no eixo Y.
 */
double get_tratado_ry(MPU mpu){
	if (mpu == NULL){
		printf("Erro ao obter a leitura tratada do sensor especificado.\n");
		exit(1);
	}
	int fator_escala;
	if (mpu->sensi_aceleracao < 3){
		fator_escala = S_ROT * pow(2, 4 - mpu->sensi_rotacao);
	} else{
		fator_escala = S_ROT_2 * pow(2, mpu->sensi_rotacao - 3);
	}
	
	return (mpu->rotY)/fator_escala;
}

/**
 * FUNÇÃO: get_tratado_rz
 * Uso: double rz_tratado = get_tratado_rz(MPU mpu);
 * -----------------
 * Verifica se o MPU não é nulo e retorna a leitura tratada da rotação no eixo Z.
 */
double get_tratado_rz(MPU mpu){
	if (mpu == NULL){
		printf("Erro ao obter a leitura tratada do sensor especificado.\n");
		exit(1);
	}
	int fator_escala;
	if (mpu->sensi_aceleracao < 3){
		fator_escala = S_ROT * pow(2, 4 - mpu->sensi_rotacao);
	} else{
		fator_escala = S_ROT_2 * pow(2, mpu->sensi_rotacao - 3);
	}
	
	return (mpu->rotZ)/fator_escala;
}

