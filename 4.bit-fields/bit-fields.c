#include<stdio.h>

void bitfieldsAsSmallInt(){
    /* define a small bit-field that can hold values from 0 .. 7 */
    struct
    {
    unsigned int uint3: 3;
    } small;

    /* extract the right 3 bits from a value */
    unsigned int value = 255 - 2; /* Binary 11111101 */
    small.uint3 = value; /* Binary 101 */
    printf("%d", small.uint3);

    /* This is in effect an infinite loop */
    // for (small.uint3 = 0; small.uint3 < 8; small.uint3++)
    // {
    // printf("%d\n", small.uint3);
    // }

}

/*

1. Arrays of bit-fields, pointers to bit-fields and functions returning bit-fields are not allowed.
2. The address operator (&) cannot be applied to bit-field members.
3. The data type of a bit-field must be wide enough to contain the size of the field.
4. The sizeof() operator cannot be applied to a bit-field.
5. There is no way to create a typedef for a bit-field in isolation (though you can certainly create a typedef for a
structure containing bit-fields) 

*/

// typedef struct mybitfield
// {
//  unsigned char c1 : 20; /* incorrect, see point 3 */
//  unsigned char c2 : 4; /* correct */
//  unsigned char c3 : 1;
//  unsigned int x[10]: 5; /* incorrect, see point 1 */
// } A;

// int SomeFunction(void)
// {
//  // Somewhere in the code
//  A a = { … };
//  printf("Address of a.c2 is %p\n", &a.c2); /* incorrect, see point 2 */
//  printf("Size of a.c2 is %zu\n", sizeof(a.c2)); /* incorrect, see point 4 */
// }


int main(){
    bitfieldsAsSmallInt();
    return 0;
}