#pragma once

template<typename NODETYPE>
UndirectedGraph<NODETYPE>::UndirectedGraph(const std::vector<GraphNode<value_type>*>& nodes){
    /*Intitialzizes the graph with the passed nodes set or empty otherwise*/
    this->nodes = nodes;
}

template<typename NODETYPE>
void UndirectedGraph<NODETYPE>::insert(GraphNode<value_type>& node){
    /*Receives GraphNode and inserts it to the graph*/
    nodes.push_back(&node);
}

template<typename NODETYPE>
std::vector<GraphNode<NODETYPE>*> UndirectedGraph<NODETYPE>::getNodes(){
    /*Returns the set of the graph nodes*/
    return nodes;
}

template<typename NODETYPE>
void UndirectedGraph<NODETYPE>::setEdge(GraphNode<value_type>& node1, GraphNode<value_type>& node2){
    /*Receives two GraphNode types and inserts an edge between them*/
    auto nodeIter1 = std::find(nodes.begin(), nodes.end(), &node1);
    auto nodeIter2 = std::find(nodes.begin(), nodes.end(), &node2);

    if (nodeIter1 != nodes.end() and nodeIter2 != nodes.end()) {
        (*nodeIter1)->addNeighbor(&node2);
        (*nodeIter2)->addNeighbor(&node1);
    }  
}

template<typename NODETYPE>
int UndirectedGraph<NODETYPE>::size(){
    /*Returns the size of the given graph*/
    return nodes.size();
}


template<typename NODETYPE>
int UndirectedGraph<NODETYPE>::edgesNumber(){
    /*Returns the number of edges in the graph*/
    int edgesNum = 0;

    for(auto &node:nodes) {
        std::vector<GraphNode<value_type>*> nodeNeighbors = node->getNeighbors();
        edgesNum += nodeNeighbors.size(); 
    }
        
    return edgesNum;
}


template<typename NODETYPE>
int UndirectedGraph<NODETYPE>::power(GraphNode<NODETYPE>& node) {
    /*Receives GraphNode type 
    returns the power of the given node if the graph contains it
    and -1 if it's not*/
    auto nodeIter = std::find(nodes.begin(), nodes.end(), &node);

    if (nodeIter != nodes.end()) {
        std::vector<GraphNode<NODETYPE>*> nodeNeighbors = (*nodeIter)->getNeighbors();
        return nodeNeighbors.size();
    }

    return -1;
}


template<typename NODETYPE>
bool UndirectedGraph<NODETYPE>::nodeIsHere(GraphNode<NODETYPE>& node) {
    /*Returns true if the graph contains the passed GraphNode and false if not*/
    auto nodeIter = std::find(nodes.begin(), nodes.end(), &node);

    return nodeIter != nodes.end();
}

template<typename NODETYPE>
bool UndirectedGraph<NODETYPE>::edgeIsHere(GraphNode<NODETYPE>& node1, GraphNode<NODETYPE>& node2){
    /*Receives two GraphNode types, returns true
    if the edge exists between them and false if not*/
    auto nodeIter1 = std::find(nodes.begin(), nodes.end(), &node1);
    auto nodeIter2 = std::find(nodes.begin(), nodes.end(), &node2);

    if (nodeIter1 != nodes.end() and nodeIter2 != nodes.end()) {
        std::vector<GraphNode<NODETYPE>*> nodeNeighbors1 = node1.getNeighbors();
        auto foundIter = find(nodeNeighbors1.begin(), nodeNeighbors1.end(), &node2);

        return foundIter != nodeNeighbors1.end();
    }      
    else {
        return false;
    }  
}

template<typename NODETYPE>
bool UndirectedGraph<NODETYPE>::empty() {
    /*Returns true if the graph is empty and false if it is not*/
    return nodes.size() == 0;
}

template<typename NODETYPE>
void UndirectedGraph<NODETYPE>::clear(){
    /*Removes all of the elements in the graph and it's edges*/
    for (auto &node:nodes) node->neighborsClear();
    nodes.clear();
}

template<typename NODETYPE>
void UndirectedGraph<NODETYPE>::deleteEdge(GraphNode<NODETYPE>& node1, GraphNode<NODETYPE>& node2) {
    /*Receives two GraphNode types and deletes the edge between them*/
    if(this->edgeIsHere(node1, node2)){
        node1.removeNeighbor(node2);
        node2.removeNeighbor(node1);
    }
}

template<typename NODETYPE>
void UndirectedGraph<NODETYPE>::deleteNode(GraphNode<NODETYPE>& node) {
    /*Receives the GraphNode type and deletes it and its edges from the graph*/
    auto nodeIter = std::find(nodes.begin(), nodes.end(), &node);

    if (nodeIter != nodes.end()) {
        nodes.erase(nodeIter);

        for (auto &graphNode:nodes) {
            graphNode->removeNeighbor(node);
        }
    }
}

template<typename NODETYPE>
void UndirectedGraph<NODETYPE>::deleteNode(typename std::vector<GraphNode<NODETYPE>*>::iterator& it) {
    /*Receives the iterator and removes the node by its iterator*/
    this->deleteNode(**it);
}

template<typename NODETYPE>
void UndirectedGraph<NODETYPE>::deleteEdge(typename std::vector<std::pair<GraphNode<NODETYPE>*, GraphNode<NODETYPE>*>>::iterator& it) {
    /*Receives the iterator to the pair of nodes and deletes the edge between them*/
    GraphNode<NODETYPE>* node1 = it->first;
    GraphNode<NODETYPE>* node2 = it->second;

    this->deleteEdge(*node1, *node2);
}

template<typename NODETYPE>
std::vector<std::pair<GraphNode<NODETYPE>*, GraphNode<NODETYPE>*>> UndirectedGraph<NODETYPE>::getAllEdges(){
    /*Returns all of the edges in the graph*/

    std::vector<std::pair<GraphNode<NODETYPE>*, GraphNode<NODETYPE>*>> allEdges;

    for(auto &node:nodes) {
        std::vector<GraphNode<NODETYPE>*> nodeNeighbors = node->getNeighbors();

        for(auto neighbor:nodeNeighbors) {
            std::pair<GraphNode<NODETYPE>*, GraphNode<NODETYPE>*> nodePair;

            nodePair.first = node;
            nodePair.second = neighbor;
            allEdges.push_back(nodePair);
        }
    }

    return allEdges;
}

template<typename NODETYPE>
typename std::vector<GraphNode<NODETYPE>*>::iterator UndirectedGraph<NODETYPE>::beginNode() {
    /*Returns the iterator to the beginning of the nodes set*/
    return nodes.begin();
}

template<typename NODETYPE>
typename std::vector<GraphNode<NODETYPE>*>::iterator  UndirectedGraph<NODETYPE>::endNode() {
    /*Returns the iterator to the end of the nodes set*/
    return nodes.end();
}

template<typename NODETYPE>
UndirectedGraph<NODETYPE>& UndirectedGraph<NODETYPE>::operator=(UndirectedGraph<NODETYPE>& other){
    this->nodes = other.nodes;
}

template<typename NODETYPE>
UndirectedGraph<NODETYPE>::UndirectedGraph(UndirectedGraph<NODETYPE>& other){
    this->nodes = other.nodes;
}

template<typename NODETYPE>
bool UndirectedGraph<NODETYPE>::operator==(UndirectedGraph<NODETYPE>& other){
    return this->nodes == other.nodes;
}

template<typename NODETYPE>
bool UndirectedGraph<NODETYPE>::operator!=(UndirectedGraph<NODETYPE>& other){
    return this->nodes != other.nodes;
}