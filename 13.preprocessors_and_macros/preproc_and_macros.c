#include<stdio.h>
#include<stdlib.h>

// use the preprocessor to define a macro that uses predefined macros prints the file name and line number
// date and time

#define debug_print(msg) printf("%s:%d %s %s %s", __FILE__, __LINE__, msg, __DATE__, __TIME__)

// use the preprocessor to define a macro that calculates the power of a number

#define POW(X, Y) \
({\
    int i, r = 1; \
    for (i = 0; i < Y; ++i) \
    r *= X; \
    r;\
})

#if 0
/* #if 0 evaluates to false, so everything between here and the #endif are
 * removed by the preprocessor. */
int myUnusedFunction(void)
{
 int i = 5;
 return i;
}
#endif


int main()
{
    printf("Hello, World!\n");
    int result = POW(2, 3);
    printf("2^3 = %d\n", result);

    debug_print("Hello, World!\n");
    return 0;
}
