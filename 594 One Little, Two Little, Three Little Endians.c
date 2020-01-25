#include <stdio.h>
#include <stdlib.h>

union number{
    int value;
    char table[4];
};

int main()
{
    int input; char temp;
    union number data;

    while(scanf("%d", &input) != EOF){
        printf("%d converts to ", input);
        data.value = input;
        temp = data.table[0];
        data.table[0] = data.table[3];
        data.table[3] = temp;
        temp = data.table[1];
        data.table[1] = data.table[2];
        data.table[2] = temp;
        printf("%d\n", data.value);

    }
    return 0;
}
