#include<stdio.h>
#include<string.h>
const char names[32][30] = {
        "negative", "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten",
"eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen",
"twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety", "hundred",
"thousand", "million"};
const int values[32] = {-1,0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,30,40,50,60,70,80,90,100,1000,1000000};
  
int value(char *number){
    int i = 0;
    for(;i < 32; ++i)
        if(strcmp(number,names[i]) == 0) break;
    return values[i];
}


int main(){
    char in[100000];
    
     while(fgets(in,10000,stdin) != NULL){
        int final_value = 0; 
        int conv[32];
        int size = 0;
        char *pch = strtok (in," \n");
        
        while(pch != NULL){
            conv[size] = value(pch);
            size++;
            pch = strtok ( NULL, " \n");
        }
        int i = 0;
        int temp = 0;
        if(conv[0] <= 0) ++i; 
        for(; i < size; i++){
            if(conv[i] > 100){
                final_value += temp * conv[i];
                temp = 0;
            }else if(conv[i] == 100) temp *= 100;
            else temp += conv[i];
        }
        final_value += temp;
        if(conv[0]==-1)final_value*=-1;
        printf("%d\n", final_value);
    }
        

    return 0;
}
