#include <iostream>
#include <string>
#include<vector>
unsigned int diff(std::string a, std::string b){
    unsigned int dif = 0;
    for(int i = 0; i < a.size(); ++i)
        if(a[i] != b[i]) dif++;
    return dif;
}

int main()
{
    std::string input;
    int a,b;
    while(std::cin >> a >> b){
        std::vector<std::string> _list(a);
        std::cin >> input;
        _list[0] = (input);
        std::cin >> input;
        _list[a-1] = input;
        for(int i = 1; i < a-1; ++i){
            std::cin >> input;
            _list[diff(_list[0],input)] = input;
        }
        for(int i = 0; i < _list.size(); ++i)
            std::cout << _list[i] << std::endl;
    }
    return 0;
}
