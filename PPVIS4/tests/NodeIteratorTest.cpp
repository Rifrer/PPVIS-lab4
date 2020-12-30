#include <iostream>
#include <vector>
#include <set>

#include "UndirectedGraph.hpp"

int main(){
    UndirectedGraph<int> testGraph;
    
    GraphNode<int> testNode1(5);
    GraphNode<int> testNode2(2);
    GraphNode<int> testNode3(3);

    testGraph.insert(testNode1);
    testGraph.insert(testNode2);
    testGraph.insert(testNode3);

    for(auto it = testGraph.beginNode(); it != testGraph.endNode(); it++){
        std::cout << (**it).getData() << std::endl;

        if ((*it)->getData() == 5) {
            testGraph.deleteNode(it);
        }
    }

    std::cout << testGraph.size() << std::endl;

    return 0;
}