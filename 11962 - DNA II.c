#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int valuer(char i){
    int val;
    switch(i){
        case 'A': val= 0;
        break;
        case 'C': val=1;
        break;
        case 'G': val=2;
        break;
        case 'T': val=3;
        break;
    }
    return val;
}

int main()
{
    int i = 0;
    int cases = 1;
    char tab[31];
    int tests = 0;
    scanf("%d",&tests);
    unsigned long long int value;
    unsigned long long int last_pow;
    while(tests--){
        scanf("%s",tab);
       value = 0;
       last_pow = 1;
       for(i = strlen(tab)-1; i >= 0; i--, last_pow *= 4){
        value += last_pow* valuer(tab[i]);
       }
       printf("Case %d: (%d:%llu)\n", cases++, strlen(tab),value);


    }
    return 0;
}
