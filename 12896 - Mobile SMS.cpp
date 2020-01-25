#include <iostream>
#include <string>

struct val
{
    int val;
    char n;
};

int main()
{
    std::string tab[] = {" ",".,?\"","abc","def","ghi","jkl","mno", "pqrs","tuv", "wxyz"};
    int tests;
    std::cin >> tests;
    while(tests--){
        int length;
        std::cin >> length;
        int num[length];
        int how_much[length];
        for(int i = 0; i < length; ++i)
        {
            std::cin >> num[i];
        }
       for(int i = 0; i < length; ++i)
        {
            std::cin >> how_much[i];
        }
        for(int i = 0; i < length; ++i)
        {
            std::cout << tab[num[i]][how_much[i]-1];
        }
        std::cout << "\n";
    }
    return 0;
}
