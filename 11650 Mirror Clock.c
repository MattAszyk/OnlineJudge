#include <stdio.h>
#include <stdlib.h>

int main()
{
    int tests, h,m,fm,rm, real_h,real_m; char a,b;
    scanf("%d",&tests);
    while(tests--){
        scanf("%d:%d",&h,&m);
        fm = 60*h + m;
        rm = 60*12 - fm;
        if(rm < 0) rm+= 60*12;
        real_h = rm/60;
        if(real_h == 0) real_h = 12;
        real_m = rm%60;
        if(real_h < 10 && real_m > 9)
            printf("0%d:%d", real_h,real_m);
         if(real_h < 10 && real_m < 10)
            printf("0%d:0%d", real_h,real_m);
         if(real_h > 9 && real_m < 10)
            printf("%d:0%d", real_h,real_m);
        if(real_h > 9 && real_m > 9)
            printf("%d:%d", real_h,real_m);
        printf("\n");
    }
    return 0;
}
