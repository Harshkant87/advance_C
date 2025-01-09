#include <stdio.h>
#include <stdlib.h>

void modify(int* v) { // v is a pointer to an integer
    printf("modify 1: %d\n", *v); /* 0 is printed */
    *v = 42;
    printf("modify 2: %d\n", *v); /* 42 is printed */
}

void getListOfFriends(size_t size, int *friend_indexes) {
    size_t i = 0;
    for (; i < size; i++) {
        friend_indexes[i] = i;
    }
}

int main(void) {
    // pass variable to the function and modify it, pass by reference
    int v = 0;
    printf("main 1: %d\n", v); /* 0 is printed */
    modify(&v);
    printf("main 2: %d\n", v); /* 42 is printed */

    // pass dynain array to the function
    int size = 5;
    int *friend_indexes = (int*)malloc(size * sizeof(int));
    getListOfFriends(size, friend_indexes);
    for (int i = 0; i < size; i++) {
        printf("friend_indexes[%d]: %d\n", i, friend_indexes[i]);
    }
    free(friend_indexes); // free memory

    //pass static array to the function
    int friends[5];
    getListOfFriends(5, friends);
    for (int i = 0; i < 5; i++) {
        printf("friends[%d]: %d\n", i, friends[i]);
    }

    return 0;
}