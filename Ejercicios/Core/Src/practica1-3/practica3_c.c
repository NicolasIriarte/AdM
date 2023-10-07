/*
 * practica1.c
 *
 *  Created on: Sep 16, 2023
 *      Author: nico
 */

#include <stdint.h>
#include "practica1-3/practica3.h"

void productoEscalar16_c(uint16_t *vectorIn, uint16_t *vectorOut,
		uint32_t longitud, uint16_t escalar){
	for(int i = 0; i < longitud; ++i){
		vectorOut[i] = vectorIn[i] * escalar;
	}
}
