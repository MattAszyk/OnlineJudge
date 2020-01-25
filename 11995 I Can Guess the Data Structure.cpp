#include <iostream>
#include <stack>
#include <queue>

int main()
{
    int x;
    while(std::cin >> x){
        std::stack<int> stacker;
        std::queue<int> queuer;
        std::priority_queue<int> priority_queuer;
        int action, value;
        bool _stacker = true, _querer = true, _priority_queuer = true;
        for(int i = 0 ; i < x ; ++i){
            std::cin >> action >> value;
            if(action == 1){
                //add
                if(_stacker) stacker.push(value);
                if(_querer) queuer.push(value);
                if(_priority_queuer) priority_queuer.push(value);
            }
            else{
                if(stacker.empty())  _stacker = false;
                if( value != stacker.top()) _stacker = false;
                if(_stacker) stacker.pop();
                if(queuer.empty()) _querer = false;
                if(queuer.front() != value) _querer = false;
                if(_querer) queuer.pop();
                if(priority_queuer.empty()) _priority_queuer = false;
                if( priority_queuer.top() != value) _priority_queuer = false;
                if(_priority_queuer) priority_queuer.pop();
                }
        }

        if((int)_stacker+(int)_querer+(int)_priority_queuer > 1) std::cout << "not sure\n";
        else if((int)_stacker+(int)_querer+(int)_priority_queuer == 0) std::cout << "impossible\n";
        else if(_stacker) std::cout << "stack\n";
        else if(_priority_queuer) std::cout << "priority queue\n";
        else if(_querer) std::cout << "queue\n";


    }
    return 0;
}
