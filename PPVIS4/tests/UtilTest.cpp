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


    std::cout << "Graph's size " << testGraph.size() << std::endl;
    std::cout << "Graph's edges " << testGraph.edgesNumber() << std::endl;
    std::cout << "node1's power " << testGraph.power(testNode1) << std::endl;
    std::cout << "node5 is not here " << testGraph.nodeIsHere(testNode5) << std::endl;
    std::cout << "Edge node1 node2 is here " << testGraph.edgeIsHere(testNode1, testNode2) << std::endl;
    std::cout << "Empty " << testGraph.empty() << std::endl;
    testGraph.clear();

    std::vector<GraphNode<int>*> testVector = testNode1.getNeighbors();
    std::cout << testVector.size() << std::endl;

    return 0;
}