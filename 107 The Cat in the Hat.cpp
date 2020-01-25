#include <iostream>
#include<string>
#include <math.h>
int power =0;
bool calculatePower(int i, int n){
    power = 0;
    while(n%i==0){
        n /=i;
        power++;
    }

    return (n==1);
}

int main()
{
    long long workingCats, Height;
    while (true)
    {
        std::cin >> Height >> workingCats;
        if (workingCats == 0 && Height == 0)
            break;
        if(workingCats==1 && Height==1){
            std::cout << "0 1\n";
            continue;
        }

        for(int i = 2 ; i <= Height; i++)
        {
            if(calculatePower(i, Height) && pow(i-1,power) == workingCats){
                long long sumOfCats = 1;
                long long sumOfHeight = Height;
                long long currentAmount;
              // H(i) = 1/(n+1) * H(-1);  
                for(int iter = 1; iter < power; iter++){
                    currentAmount = std::pow(i-1,iter);
                    sumOfHeight +=(Height* currentAmount) / std::pow(i,iter);
                    sumOfCats += currentAmount;

                }
                std::cout << sumOfCats << ' ' << sumOfHeight+workingCats << "\n";
                break;
            }
        }  
      
      
      
        }
    return 0;
}
