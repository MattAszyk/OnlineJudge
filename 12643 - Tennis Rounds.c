#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main()
{
    int fround, rounds,idf,ids, id;
    while(scanf("%d %d %d", &rounds, &idf,&ids) != EOF){
        fround = 0;
        while(idf != ids){
            if(idf%2 != 0) idf++;
            if(ids%2 != 0) ids++;
            idf /=2;
            ids /=2; fround++;
        }
        printf("%d\n",fround);
    }


    return 0;
}
