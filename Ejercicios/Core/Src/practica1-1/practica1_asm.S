.syntax unified
.thumb
.text

@ Simbolos exportados --> No olvidar de colocar los nombres de las funciones aquí
.global zeros_asm

@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@ Prototipo en "C":
@   void zeros_asm(uint32_t * vector, uint32_t longitud)@
@
@ Parametros recibidos:
@   r0: firstOperand
@   r1: secondOperand
@
@ Output: None
zeros_asm:
    @ Check if the length is zero (no elements to zero out)
    cmp r1, #0
    beq .done

    @ Initialize loop counter (i is r2)
    mov r2, #0

.loop:
    @ Load zero into a register
    mov r3, #0

    @ Store zero in the current element of the vector
    str r3, [r0]

    @ Increment the pointer to the next element
    add r0, r0, #4  @ Increment by 4 bytes (size of uint32_t)

    @ Increment the loop counter (i)
    add r2, r2, #1

    @ Compare the loop counter with the length
    cmp r2, r1
    bne .loop

.done:
    bx lr  @ Return from the function
