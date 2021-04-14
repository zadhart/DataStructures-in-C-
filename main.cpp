#include <iostream>
#include <string>
#include <vector>
#include "my_list.h++"
#include "my_queue.h++"

using namespace std;

template <typename T>
class Graph{
private:
    int size;

public:
    vector<T> allNodes;
    vector<vector<int>> neighbors;

    Graph(){
        size = 0;
    }

    void addVertex(T newData, int targetNode = -1){
        this->allNodes.push_back(newData);
        this->neighbors.push_back({targetNode});

        if(this->size != 0){
            this->neighbors[targetNode].push_back(this->size);
        }

        this->size++;
    }

};

int main() {
    Graph<string> my_graph;

    my_graph.addVertex("Greg");
    my_graph.addVertex("Marcos", 0);
    my_graph.addVertex("Higor", 0);
    my_graph.addVertex("Elaine", 0);
    my_graph.addVertex("Moises", 2);

    cout << my_graph.allNodes[0] << "\n";

    for(int i = 1; i < my_graph.neighbors[0].size(); i++){
        cout << "    " << my_graph.allNodes[my_graph.neighbors[0][i]] << "\n";
    }

    cout << my_graph.allNodes[2] << "\n";
    for(int i = 0; i < my_graph.neighbors[2].size(); i++){
        cout << "    " << my_graph.allNodes[my_graph.neighbors[2][i]] << "\n";
    }

    return 0;
}
