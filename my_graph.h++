//
// Created by zadhart on 19/04/2021.
//

#ifndef DATASTRUCTURES_MY_GRAPH_H
#define DATASTRUCTURES_MY_GRAPH_H

#endif //DATASTRUCTURES_MY_GRAPH_H

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

    //This function add an edge between two vertex
    void addEdge(int vertex1, int vertex2, int weight = 1){
        this->neighbors[vertex1][vertex2] = weight;
        this->neighbors[vertex2][vertex1] = weight;
    }

    //This funcion removes an edge between two vertex
    void removeEdge(int vertex1, int vertex2){
        this->neighbors[vertex1][vertex2] = 0;
        this->neighbors[vertex2][vertex1] = 0;
    }

    //This function add a vertex to the graph
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

    /*
     * This function read a graph from a string
     * with the format: "{0,0,0,0};{0,1,1,0};{0,1,1,1};{1,1,1,1}"
     */
    void readGraph(string g) {
        vector<int> nodes;
        for(int i = 0; i < g.size(); i++){
            if(g[i] == ';' || i == g.size() - 1){
                this->allNodesData.push_back("None");
                this->neighbors.push_back(nodes);
                nodes.clear();
            }
            else{
                if(g[i] != ',' && g[i] != '{' && g[i] != '}'){
                    //Convert an char to a int and push it on the vector
                    nodes.push_back(g[i] - '0');
                }
            }
        }
    }

    //This funtion print the adjacency matrix of the graph
    void printGraph(){
        for(int i = 0; i < this->neighbors.size(); i++){
            for(int x = 0; x < this->neighbors[i].size(); x++){
                cout << this->neighbors[i][x] << " ";
            }
            cout << "\n";
        }
    }
};

//Example of reading a graph from a string:
/*
my_graph.readGraph("{0,0,0,3,3};{0,2,0,4,1};{0,0,0,0,0};{5,5,5,5,6};{3,3,3,3,3}");
my_graph.printGraph();
*/

//Example of usage:
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

my_graph.printGraph();

my_graph.removeEdge(3, 1);

my_graph.printGraph();
*/