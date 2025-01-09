#include<stdio.h>
#include<stdlib.h>

void pointerUsage(){
    int value = 10;
    int *pointer = &value;
    printf("Value from pointer: %d\n", *pointer);
    printf("Value of pointer: %d\n", pointer);
    printf("Address of value variable: %d\n", &value);
    /* Value from pointer: 10 */
}

void sizeOfPointers(){
    // Although pointer must be of a specific type, the memory allocated 
    // for each type of pointer is equal to the memory
    // used by the environment to store addresses, rather than the size of the type that is pointed to.

    printf("Size of int pointer: %zu\n", sizeof (int*)); /* size 8 bytes */
    printf("Size of int variable: %zu\n", sizeof (int)); /* size 4 bytes */
    printf("Size of char pointer: %zu\n", sizeof (char*)); /* size 8 bytes */
    printf("Size of char variable: %zu\n", sizeof (char)); /* size 1 bytes */
    printf("Size of short pointer: %zu\n", sizeof (short*)); /* size 8 bytes */
    printf("Size of short variable: %zu\n", sizeof (short)); /* size 2 bytes */
    printf("Size of void pointer: %zu\n", sizeof (void*)); /* machine dependent, 8 on my machine */
    printf("Size of void variable: %zu\n", sizeof (void)); /* size 1 bytes */
}

void pointersAndArray(){
    int a[5] = {1, 2, 3, 4, 5};
    int *p = a;
    printf("p[0] = %d\n", p[0]); // prints 1
    printf("p[1] = %d\n", p[1]); // prints 2
    printf("p[2] = %d\n", p[2]); // prints 3
    printf("p[3] = %d\n", p[3]); // prints 4
    printf("p[4] = %d\n", p[4]); // prints 5
    printf("a[0] = %d\n", *a); // prints 1
    printf("a[1] = %d\n", *(a + 1)); // prints 2
}

void dereferencingStructs(){
    struct MY_STRUCT
    {
    int my_int;
    float my_float;
    };
    struct MY_STRUCT my_struct;
    struct MY_STRUCT *p = &my_struct;
    p->my_int = 10;
    p->my_float = 3.14159;
    printf("my_int = %d\n", p->my_int); // with arrow operator
    printf("my_float = %f\n", p->my_float);
    printf("my_int = %d\n", (*p).my_int); // with dot operator
    printf("my_float = %f\n", (*p).my_float);
}

void constPointers(){
    int b;
    int* p;
    p = &b; /* OK */
    *p = 100; /* OK */

// The pointer can point to different integers but the int's 
// value can't be changed through the pointer.
    int a;
    const int* q;
    // q = &a; /* OK */
    // *q = 100; /* Compiler Error */
    // b = 100; /* OK */

// The pointer can only point to one int and the int can not be changed through the pointer

    // int a, b;
    // const int* const p = &b; /* OK as initialisation, no assignment */
    // p = &a; /* Compiler Error */
    // *p = 100; /* Compiler Error */

}

void pointerToPointer(){
    int a = 10;
    int *p = &a;
    int **q = &p;
    printf("a = %d\n", a); // prints 10
    printf("*p = %d\n", *p); // prints 10
    printf("**q = %d\n", **q); // prints 10

    int A = 42;
    int* pA = &A;
    int** ppA = &pA;
    int*** pppA = &ppA;
    printf("%d\n", ***pppA); /* prints 42 */
}

void functionPointers(){
    int add(int a, int b)
    {
        return a + b;
    }
    int (*p)(int, int) = &add;
    printf("add(2, 3) = %d\n", p(2, 3)); // prints 5
}

int main(){
    pointerUsage();
    sizeOfPointers();
    pointersAndArray(); 
    dereferencingStructs();
    pointerToPointer();
    functionPointers();

    return 0;  
}