#include <iostream>
#include <string>
#include <vector>
#include "my_list.h++"
#include "my_queue.h++"
#include "my_graph.h++"

using namespace std;

int main() {
    Graph<string> my_graph;

    my_graph.readGraph("{0,0,0,3,3};{0,2,0,4,1};{0,0,0,0,0};{5,5,5,5,6};{3,3,3,3,3}");
    my_graph.printGraph();

    return 0;
}
