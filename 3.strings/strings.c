#include <stdio.h>
#include <string.h>

void useOfstrtok(){
    // The function strtok breaks a string into a smaller strings, 
    // or tokens, using a set of delimiters.

    int toknum = 0;
    char src[] = "Hello,, world!";
    const char delimiters[] = ", !";
    char *token = strtok(src, delimiters);
    while (token != NULL)
    {
    printf("%d: [%s]\n", ++toknum, token);
    token = strtok(NULL, delimiters);
    }

    // strtok is neither thread safe nor re-entrant because it uses a static buffer while parsing. 
    // This means that if a function calls strtok, no function that it calls while it is using 
    // strtok can also use strtok, and it cannot be called by any function that is itself using strtok. 
    // If you need to use strtok in a multithreaded program, you should use strtok_r.
}

void constStringLiterls(){
    // char *foo = "hello";
    // foo[0] = 'y'; /* Undefined behavior - BAD! */

    const char *foo1 = "hello";
    /* GOOD: can't modify the string pointed to by foo */
    printf("%s\n", foo1);

    char *foo2 = "hello";
    foo2 = "World!"; /* OK - we're just changing what foo points to */
    printf("%s\n", foo2);


    // The initializer simply designates the length and initial contents of the array. 
    // In particular, the elements are modifiable if not explicitly declared const
    char foo3[] = "hello";
    foo3[0] = 'y'; /* OK! */
    printf("%s\n", foo3);

}

void strlenAndSizeof(){
    // The strlen function returns the length of a string, 
    // not including the null terminator. 
    // The sizeof operator returns the size of the array, 
    // including the null terminator.
    char str[] = "hello";
    printf("strlen(str) = %zu\n", strlen(str)); // 5
    printf("sizeof(str) = %zu\n", sizeof(str)); // 6

     char asciiString[50] = "Hello world!";
    char utf8String[50] = "Γειά σου Κόσμε!"; /* "Hello World!" in Greek */
    printf("asciiString has %zu bytes in the array\n", sizeof(asciiString));
    printf("utf8String has %zu bytes in the array\n", sizeof(utf8String));
    printf("%s is %d bytes\n", asciiString, strlen(asciiString));
    printf("%s is %d bytes\n", utf8String, strlen(utf8String));

}

void useOfstrcpy(){
    char a[] = "abc";
    char b[8];
    // b = a; /* compile error, you can't assign pointer to an array*/
    // printf("%s\n", b);

    strcpy(b, a); /* think "b special equals a" */
    printf("%s\n", b); /* "abc" will be printed */

    // To avoid buffer overrun, snprintf() may be used. It is not the best solution performance-wise 
    // since it has to parse the template string, but it is the only buffer limit-safe function 
    // for copying strings readily-available in standard library, that can be used without any extra steps.


    char a1[] = "01234567890";
    char b1[4];
    #if 0
    strcpy(b, a); /* causes buffer overrun (undefined behavior), so do not execute this here! */
    #endif
    snprintf(b1, sizeof(b1), a1); /* does not cause buffer overrun */
    printf("%s\n", b1); /* "0123" will be printed, if not think why? hint: b is not terminated*/

    strncpy(b, a, sizeof(b)); /* the third parameter is destination buffer size */
    b[sizeof(b)/sizeof(*b) - 1] = '\0'; /* terminate the string */
    printf("%s\n", b); /* "0123456" will be printed */

}

void useOfstrncat(){

//     better performance, is to use strncat() (a buffer overflow checking version of strcat()) - it
//     takes a third argument that tells it the maximum number of bytes to copy
    char dst[24] = "Clownfish: ";
    char src[] = "Marvin and Nemo";
    size_t len = strlen(dst);
    strncat(dst, src, sizeof(dst) - len - 1);
    printf("%zu: [%s]\n", strlen(dst), dst);

// If you append to or from or copy from an existing string, ensure it is NUL-terminated!
}

void compareStrings(){
    char *const lhs = "hello";
    char *const rhs = "world";

    int result = strcasecmp(lhs, rhs); // compute case-insensitive comparison once
    // int result = strcasecmp(lhs, rhs); // compute case-insensitive comparison once
    // int result = strncmp(lhs, rhs, n); // compute comparison once

    if (result < 0) {
    printf("%s comes before %s\n", lhs, rhs);
    } else if (result == 0) {
    printf("%s equals %s\n", lhs, rhs);
    } else { // last case: result > 0
    printf("%s comes after %s\n", lhs, rhs);
    }

}

int main(){
    useOfstrtok();
    constStringLiterls();
    strlenAndSizeof();
    useOfstrcpy();
    useOfstrncat();
    return 0;
}