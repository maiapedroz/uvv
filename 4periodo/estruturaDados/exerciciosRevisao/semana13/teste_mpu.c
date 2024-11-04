/**
 * Arquivo: teste_mpu.c
 * Versão : 1.0
 * Data: 2024−11-04 16:35
 * −−−−−−−−−−−−−−−−−−−−−−−−−
 * Este programa implementa um cliente simples para demonstrar o uso de um tipo
 * abstrato de dado criados pelo usuário, o MPU.
 *
 * Aluno: Pedro Maia Dantas Nunes
 */
 
#include "mpuTAD.h"
#include <stdio.h>
#include <math.h>

int main(void) {
	// cria mpu
	MPU mpu = criar_MPU();
	
	// sets
	
	set_ax(mpu, 10000);
	set_ay(mpu, 20000);
	set_az(mpu, 30000);
	set_rx(mpu, 10000);
	set_ry(mpu, 20000);
	set_rz(mpu, 30000);
	
	set_confAceleracao(mpu, 1);
	set_confRotacao(mpu, 3);
	
	// gets
	printf("ax = %d, ay = %d, az = %d\n", get_ax(mpu), get_ay(mpu), get_az(mpu));
	printf("rx = %d, ry = %d, rz = %d\n", get_rx(mpu), get_ry(mpu), get_rz(mpu));
	
	printf("sensibilidade aceleração = %d\nsensibilidade rotação = %d\n", get_confAceleracao(mpu), get_confRotacao(mpu));
	
	
	printf("Aceleração (em g):\nax = %.2f, ay = %.2f, az = %.2f\n", get_tratado_ax(mpu), get_tratado_ay(mpu), get_tratado_az(mpu));
	printf("Rotação (em graus por segundo):\nrx = %.2f, ry = %.2f, rz = %.2f\n", get_tratado_rx(mpu), get_tratado_ry(mpu), get_tratado_rz(mpu));

}
