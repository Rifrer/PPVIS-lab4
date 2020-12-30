#include <iostream>
#include <vector>
#include <set>

#include "UndirectedGraph.hpp"

int main(){
    UndirectedGraph<int> testGraph;
    
    GraphNode<int> testNode1(1);
    GraphNode<int> testNode2(2);
    GraphNode<int> testNode3(3);

    testGraph.insert(testNode1);
    testGraph.insert(testNode2);
    testGraph.insert(testNode3);

    testGraph.setEdge(testNode1, testNode2);

    std::vector<GraphNode<int>*> testNeighbors = testNode1.getNeighbors();

    for(auto &x:testNeighbors) {
        std::cout << x->getData() << std::endl;
    }

    return 0;
}