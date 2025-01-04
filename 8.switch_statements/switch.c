#include<stdlib.h>
#include<stdio.h>

void switchStatement(){

    int a = 1;
    switch (a) {
    case 1:
        puts("a is 1");
        break;
    case 2:
        puts("a is 2");
        break;
    default:
        puts("a is neither 1 nor 2");
        break;
    }

}

void absenceOfBreak(){
    int a = 1;
    switch (a) {
        case 1:
        case 2:
            puts("a is 1 or 2");
        case 3:
            puts("a is 1, 2 or 3");
            break;
        default:
            puts("a is neither 1, 2 nor 3");
            break;
    }
// cases 1, 2, and 3 will be executed
}

void switchWithEnum(){
    enum msg_type { ACK, PING, ERROR };
    enum msg_type t = ACK;

    switch (t) {
    case ACK:
        // do nothing
        puts("System gets the acknoledgement");
        break;
    case PING:
        // do something
        puts("System get the ping");
        break;
    case ERROR:
        // do something else
        puts("System get the error");
        break;
    }
}

int main(){
    switchStatement();
    absenceOfBreak();
    switchWithEnum();
    return 0;
}