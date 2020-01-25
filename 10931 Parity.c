#include <stdio.h>
#include <stdlib.h>

void print(int input){
    if(input == 0) return;
    print(input/2);
    printf("%d", (input % 2 == 1 ? 1 : 0));
}


int main()
{
    int ones,input,copy;
    while(scanf("%d", &input)){
        if(input == 0) break;
        copy = input;
        ones = 0;
        while(copy != 0){
            if(copy & 1) ones++;
            copy = copy >> 1;
        }
        printf("The parity of ");
        print(input);
        printf(" is %d (mod 2).\n", ones);

    }
    return 0;
}
