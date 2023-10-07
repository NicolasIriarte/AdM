.syntax unified
.thumb
.text

@ Simbolos exportados --> No olvidar de colocar los nombres de las funciones aquí
.global productoEscalar12_asm

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
productoEscalar12_asm:
    cmp r2, #0         @ Check if the length is zero
    beq .done

.loop:
    ldrh r4, [r0]     @ Load a 16-bit value from vectorIn
    mul r4, r4, r3    @ Multiply the element by the scalar

    @ Saturate the result to 12 bits
    usat r4, #12, r4

    strh r4, [r1]     @ Store the saturated result in vectorOut

    add r0, r0, #2    @ Increment the input vector pointer (2 bytes per element)
    add r1, r1, #2    @ Increment the output vector pointer

    subs r2, r2, #1   @ Decrement the loop counter
    bne .loop

.done:
    bx lr             @ Return from the function
