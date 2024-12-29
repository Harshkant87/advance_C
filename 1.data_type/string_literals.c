#include <stdio.h>

int main(){
    char* str = "hello, world"; /* string literal */
    printf("value of str: %s\n", str);

/* string literals can be used to initialize arrays */
    char a1[] = "abc"; /* a1 is char[4] holding {'a','b','c','\0'} */
    char a2[4] = "abc"; /* same as a1 */
    char a3[3] = "abc"; /* a1 is char[3] holding {'a','b','c'}, missing the '\0' */

    printf("a1: %s\n", a1);
    printf("a2: %s\n", a2);
    printf("a3: %s\n", a3); // this may cause undefined value

    char* s = "foobar"; // not modifiable
    s[0] = 'F'; /* undefined behaviour */
    /* it's good practice to denote string literals as such, by using `const` */
    char const* s1 = "foobar";
    // s1[0] = 'F'; /* compiler error! */
    return 0;
}