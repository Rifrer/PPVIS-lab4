#include <iostream>
#include <vector>

#include "GraphNode.hpp"

int main(){
    GraphNode<int> testNode1(1);
    GraphNode<int> testNode2(2);
    GraphNode<int> testNode3(3);

    testNode1.addNeighbor(&testNode2);
    testNode1.addNeighbor(&testNode3);

    std::vector<GraphNode<int>*> testVector = testNode1.getNeighbors();

    for(auto &x:testVector){
        std::cout << x->getData() << std::endl;
    }

    for(auto it = testNode1.neighborsBegin(); it != testNode1.neighborsEnd(); it++){
        std::cout << (**it).getData() << std::endl;
    }

    return 0;
}