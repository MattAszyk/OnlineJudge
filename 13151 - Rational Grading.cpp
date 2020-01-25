#include <iostream>
#include <string>
#include<math.h>

int HexToDecimal(std::string hexValue)
{
    int length = hexValue.length()-1;

    int value=0;
    for(int i= 2;i<= length; i++)
    {

        switch(hexValue.at(i)){
        case '0':value += 0*pow(16,length-i);break;
        case '1':value += 1*pow(16,length-i);break;
        case '2':value += 2*pow(16,length-i);break;
        case '3':value += 3*pow(16,length-i);break;
        case '4':value += 4*pow(16,length-i);break;
        case '5':value += 5*pow(16,length-i);break;
        case '6':value += 6*pow(16,length-i);break;
        case '7':value += 7*pow(16,length-i);break;
        case '8':value += 8*pow(16,length-i);break;
        case '9':value += 9*pow(16,length-i);break;
        case 'A':value += 10*pow(16,length-i);break;
        case 'B':value += 11*pow(16,length-i);break;
        case 'C':value += 12*pow(16,length-i);break;
        case 'D':value += 13*pow(16,length-i);break;
        case 'E':value += 14*pow(16,length-i);break;
        case 'F':value += 15*pow(16,length-i);break;


        }

    }

    return value;
}


int OctToDec(std::string oct){
    int value = 0;
    int current_exp = 0;
    for(int i = oct.size()-1; i >= 0; --i){
        value += (oct[i]-'0') * pow(8,current_exp++);
    }
    return value;
}
int main()
{
    std::string snumber, oper;
    int number, test_number, test_cases,good;
    while(std::cin >> snumber >> test_cases){
        good = 0;
        if(snumber[1] == 'x') number = HexToDecimal(snumber);
        else if(snumber[0] == '0') number = OctToDec(snumber);
        else number = std::stoi( snumber );
        if(test_cases == 0 && number == 0) break;
        while(test_cases--){
            std::cin >> oper >> test_number;
            if(oper == "i"){
                good += (test_number == number ? 1 : 0);
                if(test_number != number) number = test_number;
            }
            else  if(oper == "i++"){
                good += (test_number == number ? 1 : 0);
                if(test_number != number) number = test_number;
                number++;
            }
            else  if(oper == "i--"){
                good += (test_number == number ? 1 : 0);
                if(test_number != number) number = test_number;
                number--;
            }

            else if(oper == "--i"){
                --number;
                good += (test_number == number ? 1 : 0);
                if(test_number != number) number = test_number;
            }
            else if(oper == "++i"){
                ++number;
                good += (test_number == number ? 1 : 0);
                if(test_number != number) number = test_number;
            }

        }
        std::cout << good << std::endl;
    }
    return 0;
}
