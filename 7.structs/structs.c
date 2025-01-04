#include <stdio.h>

void flexibleStructMembers(){
    struct ex1
    {
        size_t foo;
        int flex[];
    };

    struct ex2_header
    {
        int foo;
        char bar;
    };

    struct ex2
    {
        struct ex2_header hdr;
        int flex[];
    };

    /* Merged ex2_header and ex2 structures. */
    struct ex3
    {
        int foo;
        char bar;
        int flex[];
    };

    struct empty{
    };

    printf("%zu\n", sizeof(struct empty)); // 0

    /* Prints "8,8" on my machine, so there is no padding. */
    printf("%zu,%zu\n", sizeof(size_t), sizeof(struct ex1));

    /* Also prints "8,8" on my machine, so there is no padding in the ex2 structure itself. */
    printf("%zu,%zu\n", sizeof(struct ex2_header), sizeof(struct ex2));

    /* Prints "5,8" on my machine, so there are 3 bytes of padding. */
    printf("%zu,%zu\n", sizeof(int) + sizeof(char), sizeof(struct ex3));
}

void AccessingStructsUsingPointers(){
    struct ex1
    {
        int foo;
        char bar;
    };

    struct ex1 s = {1, 'a'};
    struct ex1 *p = &s;

    printf("%d\n", p->foo); // 1
    printf("%c\n", p->bar); // a
}

int main(){
    flexibleStructMembers();
    AccessingStructsUsingPointers();
    return 0;
}