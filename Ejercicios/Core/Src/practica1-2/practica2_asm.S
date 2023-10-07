.syntax unified
.thumb
.text

@ Simbolos exportados --> No olvidar de colocar los nombres de las funciones aquí
.global productoEscalar32_asm

@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@ Prototipo en "C":
@   void productoEscalar32_asm(uint32_t *vectorIn, uint32_t *vectorOut,
@		                       uint32_t longitud, uint32_t escalar)@
@
@ Parametros recibidos:
@   r0: firstOperand    // vin
@   r1: secondOperand  // vout
@	r2: thirdOperand   // longitud
@	r3: fourthOperand  // escalar
@
@ Output: None
productoEscalar32_asm:
    cmp r2, #0         @ Check if the length is zero
    beq .done

.loop:
    ldr r4, [r0]      @ Load the current element from vectorIn
    mul r4, r4, r3    @ Multiply the element by the scalar
    str r4, [r1]      @ Store the result in vectorOut

    add r0, r0, #4    @ Increment the input vector pointer (4 bytes per element)
    add r1, r1, #4    @ Increment the output vector pointer

    subs r2, r2, #1   @ Decrement the loop counter
    bne .loop

.done:
    bx lr              @ Return from the function
