#include <iostream>
#include <vector>
#include <map>
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


    std::vector<std::pair<GraphNode<int>*, GraphNode<int>*>> testVector = testGraph.getAllEdges();

    for(auto it = testVector.begin(); it != testVector.end(); it++){
        GraphNode<int>* first = it->first;
        GraphNode<int>* second = it->second;

        if (first->getData() == 1) {
            testGraph.deleteEdge(it);
        }

        // std::cout << first->getData() << " " << second->getData() << std::endl;
    }

    std::cout << testGraph.edgesNumber() << std::endl;
    return 0;
}