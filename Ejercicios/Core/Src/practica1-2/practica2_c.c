/*
 * practica1.c
 *
 *  Created on: Sep 16, 2023
 *      Author: nico
 */

#include <stdint.h>
#include "practica1-2/practica2.h"

void productoEscalar32_c(uint32_t *vectorIn, uint32_t *vectorOut,
		uint32_t longitud, uint32_t escalar){
	for(int i = 0; i < longitud; ++i){
		vectorOut[i] = vectorIn[i] * escalar;
	}
}
