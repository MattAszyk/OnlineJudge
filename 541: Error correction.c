#include <stdio.h>
#include <stdlib.h>
int matrix[101][101];

void clean(){
    int i, j;
     for(i = 0; i < 101; ++i){
        for(j = 0; j < 101; ++j){
            matrix[i][j] = 0;
        }
    }
}

int main()
{
   int n,i,j,temp, col, row, colid, rowid,a,b,cola,rowb;
   while(scanf("%d",&n) != EOF){
    if(n==0) return 0;
    clean();
    col = 0; row = 0;cola=0;rowb=0;
    rowid = -1; rowid = -1;
    for(i = 0; i < n; ++i){
        for(j = 0; j < n; ++j){
            scanf("%d", &matrix[i][j]);
        }
    }
    for(i = 0; i < n; ++i){
        temp = 0;
        for(j = 0; j < n; ++j){
           matrix[i][n] += matrix[i][j];
        }
    }
    for(i = 0; i < n; ++i){
        for(j = 0; j < n; ++j){
           matrix[n][i] += matrix[j][i];
        }
    }


    for(i = 0; i < n; ++i){
            col += matrix[n][i];
            if(matrix[n][i] % 2 != 0){ colid = i; cola++; }
    }

    for(i = 0 ;i < n; ++i){
            row += matrix[i][n];
            if(matrix[i][n] % 2 != 0){ rowid = i; rowb++; }
    }


    if(rowb > 1 || cola > 1) printf("Corrupt\n");
    else if(col != row ) printf("Corrupt\n");
    else if(rowb == 1 && cola == 1) printf("Change bit (%d,%d)\n", rowid+1,colid+1);
    else printf("OK\n");

   }

    return 0;
}
