#include <stdio.h>
#include <stdlib.h>

void intializeArray(){
    int zeroArray[10] = {0}; // all zero values
    printf("Zero Array values: ");
    for(int i = 0; i < 10; i++){
        printf("%d ", zeroArray[i]);
    }
    printf("\n");

    // int someZero[10] = {0};
    int someZero[10] = {1, 2, 3}; // some values assigned
    printf("Some Zero Array values: ");
    for(int i = 0; i < 10; i++){
        printf("%d ", someZero[i]);
    }
    printf("\n");

    int indexValuearray[5] = {[2] = 5, [1] = 2, [4] = 9}; /* array is {0, 2, 5, 0, 9} */
    printf("Array values: ");
    for(int i = 0; i < 5; i++){
        printf("%d ", indexValuearray[i]);
    }
    printf("\n");

}

void lentghOfArray(){ // calculate the length of array
    int array[] = {1, 2, 3, 4, 5};
    int length = sizeof(array) / sizeof(array[0]);
    printf("Length of array: %d\n", length);
}

void initialize2DArrayDynamically(){
    int rows = 3, cols = 4;
    int **array = (int **)malloc(rows * sizeof(int *));
    for(int i = 0; i < rows; i++){
        array[i] = (int *)malloc(cols * sizeof(int));
    }

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            array[i][j] = i + j;
        }
    }

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }

    for(int i = 0; i < rows; i++){
        free(array[i]);
    }
    free(array);
}

int main(){
    intializeArray();
    lentghOfArray();
    initialize2DArrayDynamically();
    return 0;
}