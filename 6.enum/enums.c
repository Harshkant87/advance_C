#include <stdio.h>

enum color{ RED, GREEN, BLUE };
enum Dupes
{
 Base, /* Takes 0 */
 One, /* Takes Base + 1 */
 Two, /* Takes One + 1 */
 Negative = -1,
 AnotherZero /* Takes Negative + 1 == 0, sigh */
};

void printColor(enum color chosenColor)
{
    const char *color_name = "Invalid color";
    switch (chosenColor)
    {
        case RED:
        color_name = "RED";
        break;

        case GREEN:
        color_name = "GREEN";
        break;

        case BLUE:
        color_name = "BLUE";
        break;
    }
    printf("%s\n", color_name);
}

void dupeEnums(){
    printf("Base = %d\n", Base);
    printf("One = %d\n", One);
    printf("Two = %d\n", Two);
    printf("Negative = %d\n", Negative);
    printf("AnotherZero = %d\n", AnotherZero);
}

int main(){
    printColor(1);
    dupeEnums();
}