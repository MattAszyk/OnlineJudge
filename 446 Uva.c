#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void print(int input, int dp){
    if(dp==13) return;
    print(input >> 1, dp +1);
    printf("%d",input&1);
}
int main()
{
   int cases, a,b;char mode, zeros, i;
   scanf("%d",&cases);
   while(cases--){
        scanf("%X %c %X", &a,&mode,&b);
        if(mode == '-'){
            if(b > a){
                a ^= b;
                b ^= a;
                a ^= b;
            }
        }

        print(a,0);
        printf(" %c ", mode);
        print(b,0);
        printf(" = %d\n", (mode == '-' ? a - b : a + b));

   }



    return 0;
}
