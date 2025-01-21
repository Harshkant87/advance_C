#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

/*

Parameter                    Details
expression                   expression of scalar type.
message                      string literal to be included in the diagnostic message.

Description:
An assertion is a predicate that the presented condition must be true at the moment 
the assertion is encountered by the software. Most common are simple assertions, 
which are validated at execution time. However, static assertions are checked at compile time.

 */

void assertExample(int value){
    int x = value;
    assert(x >= 0); // if x is negative, the program will terminate
    printf("x = %d\n", x); 
}

void assertExampleWithMsg(int value){
    int x = value;
    assert(x >= 0 && "Value is negative");
    printf("x = %d\n", x); 
}

// A static assertion is one that is checked at compile time, not run time.

void staticAssertExample(){
    _Static_assert(sizeof(int) == 4, "int is not 4 bytes"); // try to compile with int as 8 bytes
}

int main(){
    assertExample(1);
    assertExampleWithMsg(10);
    staticAssertExample();

    return 0;
}
