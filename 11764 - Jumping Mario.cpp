#include <iostream>
#include<vector>


int main()
{
    int printer = 0;
    int cases, jumps, input;
    std::cin >> cases;
    while(cases--)
    {
        std::cin >> jumps;
        int data[jumps];
        for(int i = 0; i < jumps; ++i) std::cin >> data[i];
        int high = 0;
        int low = 0;
        for(int i = 1; i < jumps; ++i)
        {
            if(data[i-1] < data[i]) high++;
            if(data[i-1] > data[i]) low++;
        }
        std::cout << "Case " << ++printer << ": " << high << " " << low << std::endl;
    }
}
