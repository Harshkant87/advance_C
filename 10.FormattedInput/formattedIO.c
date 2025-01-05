/*Conversion
Specifier    Type of Argument      Description
i, d         int                   prints decimal
u            unsigned int          prints decimal
o            unsigned int          prints octal
x            unsigned int          prints hexadecimal, lower-case
X            unsigned int          prints hexadecimal, upper-case
f            double                prints float with a default precision of 6, if no precision is given (lower-case used
                                   for special numbers nan and inf or infinity)
F            double                prints float with a default precision of 6, if no precision is given (upper-case
                                   used for special numbers NAN and INF or INFINITY)
e            double                prints float with a default precision of 6, if no precision is given, using scientific
                                   notation using mantissa/exponent; lower-case exponent and special numbers
E            double                prints float with a default precision of 6, if no precision is given, using scientific
                                   notation using mantissa/exponent; upper-case exponent and special numbers
g            double                uses either f or e 
G            double                uses either F or E 
a            double                prints hexadecimal, lower-case
A            double                prints hexadecimal, upper-case
c            char                  prints single character
s            char*                 prints string of characters up to a NUL terminator, or truncated to length given
                                   by precision, if specified
p            void*                 prints void-pointer value; a nonvoid-pointer should be explicitly converted
                                   ("cast") to void*; pointer to object only, not a function-pointer
%            n/a                   prints the % character
n            int *                 write the number of bytes printed so far into the int pointed at.

*/
#include<stdio.h>
#include<stdio.h>

void ioFormatsSpecifier(){
    int i = 10;
    double d = 3.14159;
    char c = 'A';
    char s[] = "Hello, World!";
    void *p = &i;
    printf("i = %d\n", i);
    printf("d = %f\n", d);
    printf("c = %c\n", c);
    printf("s = %s\n", s);
    printf("p = %p\n", p);
}

void differenceOfPointers(){
    int a[2];
    int * p1 = &a[0], * p2 = &a[1];
    ptrdiff_t pd = p2 - p1;
    printf("p1 = %p\n", (void*) p1);
    printf("p2 = %p\n", (void*) p2);
    printf("p2 - p1 = %td\n", pd); // prints 1
    int size = (char*) p2 - (char*) p1;
    printf("size = %d\n", size); // prints 4

}

int main(){
    ioFormatsSpecifier();
    differenceOfPointers(); // determine the size of datatype without using sizeof operator
    return 0;
}