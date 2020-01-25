#include <iostream>
#include<vector>
#include <algorithm>
#include <queue>
struct Edge{
    int x;
    int y;
    int length;
};

bool edge_sort(const Edge &a, const Edge &b){
    return  a.length < b.length;
}


class Graph{
public:
    int get_length();
    Graph(std::vector<Edge>,int);
    ~Graph(){
        delete[] parent;
    };

private:
    int verticles;
    int* parent;
    std::vector<Edge> edges, minimal;
    std::queue<Edge> queue;
    int find(int);
    void make_union(int,int);
    void generate();

};

Graph::Graph(std::vector<Edge> input, int vert) {
    edges = input;
    verticles = vert;
    parent = new int[vert];
    for(int i = 0; i < vert; ++i) parent[i] = i;
    generate();
}

void Graph::generate() {
    for(int i = 0; i < edges.size(); ++i)
        queue.push(edges[i]);
    int it = 0;
    while(it < verticles - 1){
        Edge edge = queue.front();
        queue.pop();
        int x_par = find(edge.x);
        int y_par = find(edge.y);
        if(x_par != y_par){
            minimal.push_back(edge);
            it++;
            make_union(x_par,y_par);
        }
    }


}

void Graph::make_union(int x, int y) {
    int x_par = find(x);
    int y_par = find(y);
    parent[y_par] = x_par;
}

int Graph::find(int id) {
    return (parent[id] == id ? id : find(parent[id]));
}

int Graph::get_length() {
    int value = 0;
    for(int i = 0; i < minimal.size(); ++i)
        value += minimal[i].length;
    return value;
}

int main(){
    int m,n;
    int x,y,z;
    while(std::cin >> m >> n){
        int all_roads = 0;
        if(m == 0 && n == 0) break;
        std::vector<Edge> edge(n);
        for(int i = 0; i < n; ++i){
            std::cin >> x >> y >> z;
            edge[i] = Edge{x,y,z};
            all_roads += z;
        }
        std::sort(edge.begin(),edge.end(),edge_sort);
        Graph calc(edge,m);
        std::cout << all_roads - calc.get_length() << std::endl;
    }

    return 0;
}
