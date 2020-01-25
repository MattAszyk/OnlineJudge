#include <iostream>
#include<vector>
#include<map>
#include<list>
#include <climits>
class Vertex{
public:
    bool visited = false;
    int id = INT_MAX;
    Vertex *superior = nullptr;
    std::vector<Vertex*> nexts;
    Vertex();
    ~Vertex(){};

};

Vertex::Vertex() {
    superior = nullptr;
}

void check_rec(Vertex *vertex){
   // std::cout << "CHECK REC: " << vertex->id <<" " << vertex->visited << std::endl;
    if(vertex->visited){
        vertex->visited = false;
        return;
    }else vertex->visited = true;
    for(int i = 0; i < vertex->nexts.size(); ++i){
        check_rec(vertex->nexts[i]);
    }
    //std::cout << "CHECK REC2: " << vertex->id <<" " << vertex->visited << std::endl;

}


int main()
{
    int x,y, kase = 0;
    while(std::cin >> x >> y) {
        if(x == 0 && y == 0){
            std::cout << "Case " << ++kase << " is a tree." << std::endl;
            continue;
        }
        bool continue_checking = true;
        std::map<int, Vertex> data;
        if (x == -1 && y == -1) return 0;
        while (x != 0 && y != 0) {
            if (x == 0 && y == 0) break;
            //CHECK IF EXIST
            data[x].id = x;
            data[y].id = y;
            //SET SUPERIOR POINTER, IF EXIST THIS IS NOT A TREE
            if (data[y].superior == nullptr) data[y].superior = &data[x];
            else continue_checking = false;
            data[x].nexts.push_back(&data[y]);
            if (x == y) continue_checking = false; // cycle
            std::cin >> x >> y;
        }
        Vertex *root;
        if(continue_checking){
            int roots = 0;
            for(std::map<int,Vertex>::iterator it = data.begin(); it != data.end(); ++it)
                if(it->second.superior == nullptr){ ++roots; root = &it->second;}
                if(roots != 1) continue_checking = false;
               // std::cout << "roots: " << roots << "\n";
        }


        if(continue_checking){
            check_rec(root);
            for(std::map<int,Vertex>::iterator it = data.begin(); it != data.end(); ++it){
                Vertex vertex = it->second;
                //std::cout << "ID " <<  vertex.id << " BOOL: " << vertex.visited << "\n";
                if(!vertex.visited){
                    continue_checking = false;
                    break;
                }
            }
        }


        std::cout << "Case " << ++kase << " is" << (continue_checking ? "" : " not") << " a tree." << std::endl;
    }

    return 0;
}
