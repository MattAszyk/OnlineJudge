#include <iostream>

int main(){
    int amount;
    while(std::cin >> amount){
        int *table = new int[amount];
        for(int* i = table; i < table+amount; ++i)
            std::cin >> *i;
        int operations = 0;
        for(int i = 1; i < amount; ++i){
            for(int j = 0; j<i; ++j){
                if(*(table+j) > *(table+i)){
                    ++operations;
                }
            }
        }

        std::cout << "Minimum exchange operations : " << operations << std::endl;
        delete[] table;
    }
  return 0;
}
