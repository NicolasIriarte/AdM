/*
 * practica1.c
 *
 *  Created on: Sep 16, 2023
 *      Author: nico
 */

#include <stdint.h>
#include "practica1-1/practica1.h"

void zeros_c(uint32_t *vector, uint32_t longitud) {
	for (int i = 0; i < longitud; ++i) {
		vector[i] = 0;
	}
}
