/*
The typedef mechanism allows the creation of aliases for other types. 
It does not create new types. People often use typedef to improve the portability of code, 
to give aliases to structure or union types, or to create aliases for
function (or function pointer) types.

In the C standard, typedef is classified as a 'storage class' for convenience; 
it occurs syntactically where storage classes such as static or extern could appear.
 However, typedef is not a storage class in the same sense as static
*/

#include<stdio.h>

typedef long long ll;

typedef struct Person {
    char name[32];
    int age;
    struct Person *next;
} Person;

typedef union Float Float;
union Float
{
 float f;
 char b[sizeof(float)];
};

int main()
{
    Person p1;
    p1.age = 20;
    printf("Age: %d\n", p1.age);

    Float f;
    f.f = 3.14;
    printf("Float: %f\n", f.f);

    ll x = 1000000000000000000;
    printf("Long long: %lld\n", x);

    return 0;
}
   