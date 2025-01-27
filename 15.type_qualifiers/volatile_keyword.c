/*
The volatile keyword tells the compiler that the value of the variable may change at any time as a result of
external conditions, not only as a result of program control flow.

*/

#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>

volatile int foo; /* Different ways to declare a volatile variable */
int volatile foo;

volatile uint8_t * pReg; /* Pointers to volatile variable */
uint8_t volatile * pReg;

volatile int quit = false; // compiler will not optimize this variable

void interrupt_handler(void)
{
    printf("Interrupt handler\n");
    quit = !quit;
}

void main()
{

 while (!quit) {
 // Do something that does not modify the quit variable
    interrupt_handler();
    interrupt_handler();
 }

}



