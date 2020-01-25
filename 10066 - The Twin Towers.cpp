#include<iostream>

int main(){
    int tower=0,first,second;
    while(std::cin >> first >> second && first && second){
        int tab[first+1][second+1] = {};
        int first_tab[first], second_tab[second];
        for(int i = 0; i < first; ++i) std::cin >> first_tab[i];
        for(int i = 0; i < second; ++i) std::cin >> second_tab[i];
        for(int i = 0; i <first; ++i){
            for(int j = 0; j <second; ++j){
                tab[i+1][j+1] = ( first_tab[i] == second_tab[j] ? tab[i][j]+1 : std::max(tab[i+1][j],tab[i][j+1]));
            }
        }
        std::cout << "Twin Towers #" << ++tower << std::endl <<
        "Number of Tiles : " << tab[first][second] << std::endl;
        }

    return 0;
}
