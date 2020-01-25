#include <iostream>
#include <string>

char tab[101][101];
int num = 0;
void check(int sx, int sy, int x,int y, bool add)
{
    if(x<0 || x >= sx || y < 0 || y >= sy) return;
    if(tab[x][y]=='*') return;
    if(add) num++;
    tab[x][y] = '*';
    check(sx,sy , x - 1, y + 1, 0);
	check(sx,sy , x - 1, y, 0);
	check(sx,sy , x - 1, y - 1, 0);

	check(sx,sy , x, y - 1, 0);
	check(sx,sy , x, y + 1, 0);

	check(sx,sy , x + 1, y - 1, 0);
	check(sx,sy , x + 1, y, 0);
	check(sx,sy , x + 1, y + 1, 0);
}


int main()
{
    int m,n;
    while(std::cin >> m >> n)
    {
        num = 0;
        if(m == 0) break;
        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; j++)
                std::cin >> tab[i][j];
        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; j++)
                check(m,n,i,j,true);
        std::cout << num << "\n";
    }
    return 0;
}
