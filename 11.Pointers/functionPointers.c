#include <stdio.h>
#include <stdlib.h>

/*    function pointers mnemonic --- returnType (*name)(parameters)      */

/* increment: take number, increment it by one, and return it */
int increment(int i)
{
    printf("increment %d by 1\n", i);
    return i + 1;
}

/* decrement: take number, decrement it by one, and return it */
int decrement(int i)
{
    printf("decrement %d by 1\n", i);
    return i - 1;
}

void basicOperations(){
    int addInt(int n, int m){
        return n+m;
    }

    void Print(void){
        printf("print with the help of function pointers!\n");
    }

    int (*functionPtrAdd)(int, int) = addInt; // or &addInt - the & is optional
    void (*functionPtrPrint)(void) = Print; // or &Print - the & is optional

    int sum = (*functionPtrAdd)(2, 3); //will assign 5 to sum
    printf("sum is %d\n", sum);
    (*functionPtrPrint)(); //will print the text in Print function


}

void ArrayOfFunctionPointers(){
    int addInt(int n, int m){
        return n+m;
    }

    int subInt(int n, int m){
        return n-m;
    } 

    int (*array[2]) (int x, int y); // can hold 2 function pointers of same signature
    array[0] = addInt;
    array[1] = subInt;

    printf("sum is %d\n", (*array[0])(2, 3)); //will assign 5 to sum
    printf("sub is %d\n", (*array[1])(2, 3)); //will assign -1 to sub

}

int main(void)
{
    int num = 0;        /* declare number to increment */
    int (*fp)(int);     /* declare a function pointer */
    fp = &increment;    /* set function pointer to increment function */
    num = (*fp)(num);   /* increment num */
    num = (*fp)(num);   /* increment num a second time */
    fp = &decrement;    /* set function pointer to decrement function */
    num = (*fp)(num);   /* decrement num */
    printf("num is now: %d\n", num);
    basicOperations();
    ArrayOfFunctionPointers();
    return 0;
}
