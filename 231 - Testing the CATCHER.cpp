#include<iostream>
#include<vector>

int main(){
    int case_id = 0;
    std::vector<int>* input_data;
    int * length;
    int cin;
    while(std::cin >> cin){
        if(cin == -1) break;
        if(case_id != 0 ) std::cout << std::endl;
        input_data = new std::vector<int>;
        input_data->push_back(cin);
        //input zone;
        while(std::cin >> cin){
            if(cin == -1) break;
            else input_data->push_back(cin);
        }
        length = new int[input_data->size()];
        int interceptions = 0;
        for(int i = 0; i < input_data->size(); ++i){
            length[i] = 1;
            for(int e = i -1; e >= 0; --e){
                if(input_data->at(i) < input_data->at(e) && length[e]+1 > length[i])
                    length[i] = length[e] +1;
            }
            if(length[i] > interceptions) interceptions = length[i];
        }
        std::cout << "Test #" << ++case_id << ":\n  maximum possible interceptions: " << interceptions << "\n";


        delete input_data;
        delete[] length;
    }
    return EXIT_SUCCESS;
}
