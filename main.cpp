#include <iostream>
#include <string>
#include <vector>
#include "my_list.h++"
#include "my_queue.h++"

using namespace std;

template <typename T>
class Graph{
private:
    int graphSize;

public:
    vector<T> allNodesData;
    vector<vector<int>> neighbors;

    Graph(){
        this->graphSize = 0;
    }

    void addEdge(int vertex1, int vertex2, int weight = 1){
        this->neighbors[vertex1][vertex2] = weight;
        this->neighbors[vertex2][vertex1] = weight;
    }

    void removeEdge(int vertex1, int vertex2){
        this->neighbors[vertex1][vertex2] = 0;
        this->neighbors[vertex2][vertex1] = 0;
    }

    void addVertex(T newData = NULL, vector<int> targetNodes = {}){
        this->allNodesData.push_back(newData);
        this->neighbors.push_back(vector<int>(this->allNodesData.size()));

        if(allNodesData.size() != 0){
            //create the edges
            for(int i = 0; i < this->allNodesData.size() - 1; i++){
                this->neighbors[i].push_back(0);
            }
        }
    }

    void readGraph(string g) {

        //The code above find the number of vertex of a given graph
        int y = 0;
        for (int i = 0; i < g.size(); i++) {
            if (g[i] == ';') {
                y++;
            }
        }
        y++;
        cout << y << "\n";

        cout << "g size: " << g.size() << "\n";

        int init = 0;
        int last = 9;

        for(int i = 0; i < y; i++){
            cout << "init: " << init << " last: " << last << "\n";
            cout << g.substr(init, last) << "\n";
            init = last + 1;
            last = last + 10;
        }
    }
};

int main() {
    Graph<string> my_graph;
    my_graph.readGraph("{0,0,0,3};{0,2,0,4};{0,0,0,0};{5,5,5,5}");

    /*
    my_graph.addVertex("Greg");
    my_graph.addVertex("Moises");
    my_graph.addVertex("Rafa");
    my_graph.addVertex("Perninha");
    my_graph.addVertex("Ricardo");

    my_graph.addEdge(2,3);
    my_graph.addEdge(4,0);
    my_graph.addEdge(3,1);

    for(int i = 0; i < my_graph.allNodesData.size(); i++){
        cout << my_graph.allNodesData[i] << " ";
    }
    cout << "\n";

    for(int i = 0; i < my_graph.neighbors.size(); i++){
        for(int x = 0; x < my_graph.neighbors[i].size(); x++){
            cout << my_graph.neighbors[i][x] << " ";
        }
        cout << "\n";
    }

    cout << "\n";

    my_graph.removeEdge(3, 1);



    for(int i = 0; i < my_graph.neighbors.size(); i++){
        for(int x = 0; x < my_graph.neighbors[i].size(); x++){
            cout << my_graph.neighbors[i][x] << " ";
        }
        cout << "\n";
    }
     */
    /*
    string g = "{0,0,0,0,1},{0,0,0,0,4},{0,0,0,4,2}";

    for(int i = 0; i < g.size(); i++){
        if(g[i] != '{'){
            if(g[i] != '}'){
                cout << g[i] << " ";
            }
        }
    }
    */

    return 0;
}
