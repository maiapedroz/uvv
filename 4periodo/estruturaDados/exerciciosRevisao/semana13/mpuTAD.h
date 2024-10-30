/**
 * Arquivo: mpuTAD.h
 * Versão : 1.0
 * Data: 2024−10−30 15:25
 * −−−−−−−−−−−−−−−−−−−−−−−−−
 * Esta interface cria um TAD, o MPU, que representa o sensor MPU-6050,
 * um sensor muito utilizado na robótica que detecta aceleração e rotação
 *
 * Aluno: Pedro Maia Dantas Nunes
 */
 
 
/* Inicia boilerplate da interface: */
#ifndef _MPUTAD_H
#define _MPUTAD_H

/*** Includes: ***/

/*** Tipos Abstratos de Dados: ***/

typedef struct st_MPU *MPU;

/*** Declarações de subprogramas: ***/

/**
 *	FUNÇÃO: criar_MPU
 *	Uso: criar_MPU();
 *	-----------------
 *	Esta função cria um MPU, um dado pronto para receber valores brutos de 
 *	aceleração em X, Y e Z (ax, ay, az), rotação em X, Y, e Z (rx, ry, rz) e 
 *	configurações a respeito de como tratar esses valores brutos.
 *
 *	Depois de criado o MPU precisa ser apagado com o procedimento
 *	"apagar_MPU", antes da finalização do programa.
 */

MPU criar_MPU();

/**
 *	FUNÇÃO: apagar_MPU
 *	Uso: apagar_MPU(&M);
 *	--------------------
 *	Esta função recebe um PONTEIRO para um MPU como argumento e libera 
 *	a memória alocada para esse MPU, fazendo que o MPU aponte para NULL
 * 	para evitar dangling pointer.
 */

void apagar_MPU(MPU *M);

/**
 *	FUNÇÃO: set_ax;
 *	Uso: set_ax(MPU mpu, int ax);
 *	--------------------------------
 *	Esta função recebe como argumento um MPU mpu e um valor int
 *	correspondendo a aceleração no eixo X, e atribui esse valor como aceleração
 *	no eixo X.
 */

void set_ax(MPU mpu, int ax);

/**
 *	FUNÇÃO: set_ay;
 *	Uso: set_ay(MPU mpu, int ay);
 *	--------------------------------
 *	Esta função recebe como argumento um MPU mpu e um valor int
 *	correspondendo a aceleração no eixo Y, e atribui esse valor como aceleração
 *	no eixo Y.
 */
 
void set_ay(MPU mpu, int ay);

/**
 *	FUNÇÃO: set_az;
 *	Uso: set_az(MPU mpu, int az);
 *	--------------------------------
 *	Esta função recebe como argumento um MPU mpu e um valor int
 *	correspondendo a aceleração no eixo Z, e atribui esse valor como aceleração
 *	no eixo Z.
 */
 
void set_az(MPU mpu, int az);

/**
 *	FUNÇÃO: set_rx;
 *	Uso: set_rx(MPU mpu, int rx);
 *	--------------------------------
 *	Esta função recebe como argumento um MPU mpu e um valor int
 *	correspondendo a rotação no eixo X, e atribui esse valor como rotação
 *	no eixo X.
 */
 
void set_rx(MPU mpu, int rx);

/**
 *	FUNÇÃO: set_ry;
 *	Uso: set_ry(MPU mpu, int ry);
 *	--------------------------------
 *	Esta função recebe como argumento um MPU mpu e um valor int
 *	correspondendo a rotação no eixo Y, e atribui esse valor como rotação
 *	no eixo Y.
 */

void set_ry(MPU mpu, int ry);

/**
 *	FUNÇÃO: set_rz;
 *	Uso: set_rz(MPU mpu, int rz);
 *	--------------------------------
 *	Esta função recebe como argumento um MPU mpu e um valor int
 *	correspondendo a rotação no eixo Z, e atribui esse valor como rotação
 *	no eixo Z.
 */

void set_rz(MPU mpu, int rz);

/**
 *	FUNÇÃO: get_ax;
 *	Uso: get_ax(MPU mpu);
 *	--------------------------------
 *	Esta função recebe como argumento um MPU mpu e retorna o valor bruto 
 *	armazenado da aceleração no eixo X, como um valor int.
 */

int get_ax(MPU mpu);

/**
 *	FUNÇÃO: get_ay;
 *	Uso: get_ay(MPU mpu);
 *	--------------------------------
 *	Esta função recebe como argumento um MPU mpu e retorna o valor bruto 
 *	armazenado da aceleração no eixo Y, como um valor int.
 */

int get_ay(MPU mpu);

/**
 *	FUNÇÃO: get_az;
 *	Uso: get_az(MPU mpu);
 *	--------------------------------
 *	Esta função recebe como argumento um MPU mpu e retorna o valor armazenado
 *	da aceleração no eixo Z, como um valor int.
 */
 
int get_az(MPU mpu);

/**
 *	FUNÇÃO: get_ax;
 *	Uso: get_ax(MPU mpu);
 *	--------------------------------
 *	Esta função recebe como argumento um MPU mpu e retorna o valor bruto 
 *	armazenado da rotação no eixo X, como um valor int.
 */

int get_rx(MPU mpu);

/**
 *	FUNÇÃO: get_ay;
 *	Uso: get_ay(MPU mpu);
 *	--------------------------------
 *	Esta função recebe como argumento um MPU mpu e retorna o valor bruto 
 *	armazenado da rotação no eixo Y, como um valor int.
 */

int get_ry(MPU mpu);

/**
 *	FUNÇÃO: get_az;
 *	Uso: get_az(MPU mpu);
 *	--------------------------------
 *	Esta função recebe como argumento um MPU mpu e retorna o valor bruto 
 *	armazenado da rotação no eixo Z, como um valor int.
 */
 
int get_rz(MPU mpu);

/**
 *	FUNÇÃO: set_confAceleracao;
 *	Uso: set_confAceleracao(MPU mpu, int sensibilidade);
 *	--------------------------------
 *	Esta função recebe como argumento um MPU mpu e um valor int que representa
 *	a sensibilidade do acelerômetro, e atribui esse valor como a nova
 *	sensibilidade do acelerômetro.
 *
 *	Valores aceitos: (1, 2, 3, 4)
 *	sensibilidade 	|	escala dos valores medidos (g)
 *		1			|			-2 a +2
 *		2			|			-4 a +4
 *		3			|			-8 a +8
 *		4			|			-16 a +16
 */

void set_confAceleracao(MPU mpu, int sensibilidade);

/**
 *	FUNÇÃO: set_confRotacao;
 *	Uso: set_confRotacao(MPU mpu, int sensibilidade);
 *	--------------------------------
 *	Esta função recebe como argumento um MPU mpu e um valor int que representa
 *	a sensibilidade do giroscópio, e atribui esse valor como a nova
 *	sensibilidade do giroscópio.
 *
 *	Valores aceitos: (1, 2, 3, 4)
 *	sensibilidade 	|	escala dos valores medidos (ºs⁻¹)
 *		1			|			-250 a +250
 *		2			|			-500 a +500
 *		3			|			-1000 a +1000
 *		4			|			-2000 a +2000
 */
 
void set_confRotacao(MPU mpu, int sensibilidade);

/**
 *	FUNÇÃO: get_confAceleracao;
 *	Uso: get_confAceleracao(MPU mpu);
 *	--------------------------------
 *	Esta função recebe como argumento um MPU mpu e retorna o valor armazenado 
 *	da sensibilidade no acelerômetro, como um valor int.
 */

int get_confAceleracao(MPU mpu);

/**
 *	FUNÇÃO: get_confRotacao;
 *	Uso: get_confRotacao(MPU mpu);
 *	--------------------------------
 *	Esta função recebe como argumento um MPU mpu e retorna o valor armazenado 
 *	da sensibilidade no giroscópio, como um valor int.
 */
 
int get_confRotaco(MPU mpu);

/**
 *	FUNÇÃO: get_tratado_ax;
 *	Uso: get_tratado_ax(MPU mpu);
 *	--------------------------------
 *	Esta função recebe como argumento um MPU mpu e retorna o valor tratado 
 *	armazenado da aceleração no eixo X, como um valor int.
 */

int get_tratado_ax(MPU mpu);

/**
 *	FUNÇÃO: get_tratado_ay;
 *	Uso: get_tratado_ay(MPU mpu);
 *	--------------------------------
 *	Esta função recebe como argumento um MPU mpu e retorna o valor tratado 
 *	armazenado da aceleração no eixo Y, como um valor int.
 */
int get_tratado_ay(MPU mpu);

/**
 *	FUNÇÃO: get_tratado_az;
 *	Uso: get_tratado_az(MPU mpu);
 *	--------------------------------
 *	Esta função recebe como argumento um MPU mpu e retorna o valor tratado 
 *	armazenado da aceleração no eixo Z, como um valor int.
 */
 
int get_tratado_az(MPU mpu);

/**
 *	FUNÇÃO: get_tratado_rx;
 *	Uso: get_tratado_rx(MPU mpu);
 *	--------------------------------
 *	Esta função recebe como argumento um MPU mpu e retorna o valor tratado 
 *	armazenado da rotação no eixo X, como um valor int.
 */

int get_tratado_rx(MPU mpu);

/**
 *	FUNÇÃO: get_tratado_ry;
 *	Uso: get_tratado_ry(MPU mpu);
 *	--------------------------------
 *	Esta função recebe como argumento um MPU mpu e retorna o valor tratado 
 *	armazenado da rotação no eixo Y, como um valor int.
 */

int get_tratado_ry(MPU mpu);

/**
 *	FUNÇÃO: get_tratado_rz;
 *	Uso: get_tratado_rz(MPU mpu);
 *	--------------------------------
 *	Esta função recebe como argumento um MPU mpu e retorna o valor tratado 
 *	armazenado da rotação no eixo Z, como um valor int.
 */

int get_tratado_rz(MPU mpu);

/*	Finaliza boilerplate:	*/

#endif
