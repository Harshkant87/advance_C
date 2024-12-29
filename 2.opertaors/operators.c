#include <stdio.h>
#include <stdalign.h>

void myStructAccess(){
    struct MyStruct {
        int x;
        int y;
    };
    struct MyStruct myObject;
    struct MyStruct *p = &myObject;
    p->x = 42;
    p->y = 123;
    printf(".x = %i, .y = %i\n", p->x, p->y); /* Outputs ".x = 42, .y = 123". */
    printf(".x = %i, .y = %i\n", myObject.x, myObject.y); /* Also outputs ".x = 42, .y = 123". */
}

void addressAndDereference(){
    int x = 12;
    int *p = &x;
    printf("x = %i\n", x); /* Outputs "x = 42". */
    printf("x = %i\n", *p); /* Also outputs "x = 42". */

    int y = 42;
    int *q = &y;
    printf("y = %d, *q = %d\n", y, *q); /* Outputs "x = 42, *p = 42". */
    *q = 123;
    printf("y = %d, *q = %d\n", y, *q); /* Outputs "x = 123, *p = 123". */

}

void arrayIndexing(){
    int arr[] = { 1, 2, 3, 4, 5 };
    printf("arr[2] = %i\n", arr[2]); /* Outputs "arr[2] = 3". */
    printf("*(arr + 2) = %i\n", *(arr + 2)); /* Also outputs "arr[2] = 3". */
    printf("3[arr] = %i\n", 3[arr]); /* Outputs "3[arr] = 4". */
    printf("*(3 + arr) = %i\n", *(3 + arr)); /* Also outputs "*(3 + arr) = 4". */
}

void pointerToFunction(){
    int add(int a, int b){
        return a + b;
    }
    int (*p)(int, int) = &add;
    printf("p(2, 3) = %i\n", p(2, 3)); /* Outputs "p(2, 3) = 5". */

    int x = 4;
    int y = 3;
    int (*fn)(int, int) = &add;
    printf("(*fn)(%i, %i) = %i\n", x, y, (*fn)(x, y)); /* Outputs "fn(4, 3) = 7". */
}

void alignOfOperator(){
    // The alignof operator in C is used to determine the alignment requirement of a type. 
    // It returns the alignment, in bytes, required for any instance of the given type. 
    // This operator is part of the C11 standard and is defined in the <stdalign.h> header.
    // The alignment requirement is a positive integral power
    // of 2 representing the number of bytes between which two objects of the type may be allocated.

    printf("Alignment of char = %zu\n", alignof(char));
    printf("Alignment of int = %zu\n", alignof(int));
    printf("alignof(float[10]) = %zu\n", alignof(float[10]));
    printf("alignof(struct{char c; int n;}) = %zu\n",alignof(struct {char c; int n;})); 
}

int main(){
    myStructAccess();
    addressAndDereference();
    arrayIndexing();
    pointerToFunction();
    alignOfOperator();
    return 0;
}