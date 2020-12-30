#include <iostream>
#include <vector>
#include <set>

#include "UndirectedGraph.hpp"

int main(){
    UndirectedGraph<int> testGraph;
    
    GraphNode<int> testNode1(1);
    GraphNode<int> testNode2(2);
    GraphNode<int> testNode3(3);
    GraphNode<int> testNode4(4);
    GraphNode<int> testNode5(5);

    testGraph.insert(testNode1);
    testGraph.insert(testNode2);
    testGraph.insert(testNode3);
    testGraph.insert(testNode4);

    testGraph.setEdge(testNode1, testNode2);
    testGraph.setEdge(testNode1, testNode3);
    testGraph.setEdge(testNode1, testNode4);

    testGraph.deleteEdge(testNode1, testNode2);
    testGraph.deleteNode(testNode4);

    std::vector<GraphNode<int>*> testVector = testNode1.getNeighbors();

    for(auto &x:testVector){
        std::cout << x->getData() << std::endl;
    }

    return 0;
}