#include <iostream>
#include<vector>


int main()
{
    int cases; std::cin >> cases;
    while(cases--)
    {
        int x,y;
        std::cin >> x >> y;
        x -=2;
        y -=2;
        if(x%3) x = x/3 + 1;
        else x = x/3;
        if(y%3)  y = y/3 +1;
        else y = y/3;
        std::cout << x * y << std::endl;
    }

    return 0;
}
