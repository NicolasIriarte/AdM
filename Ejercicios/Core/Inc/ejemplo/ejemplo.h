#pragma once

#include <stdint.h>

void asm_svc(void);

uint32_t sum_asm(uint32_t firstOperand, uint32_t secondOperand);
uint32_t sum_c(uint32_t firstOperand, uint32_t secondOperand);
