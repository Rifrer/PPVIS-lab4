#pragma once

template<typename NODETYPE>
GraphNode<NODETYPE>::GraphNode(const NODETYPE& data){
    /*Intializes a node with the passed data*/
    this->data = data;
}

template<typename NODETYPE>
NODETYPE GraphNode<NODETYPE>::getData(){
    /*Returns the data from a node*/
    return data; 
}

template<typename NODETYPE>
void GraphNode<NODETYPE>::addNeighbor(GraphNode<NODETYPE>* neighbor){
    /*Receives GraphNode and adds it to the neighbors of the given node*/
    neighbors.push_back(neighbor);
}

template<typename NODETYPE>
std::vector<GraphNode<NODETYPE>*> GraphNode<NODETYPE>::getNeighbors(){
    /*Returns the vector of the neighboring nodes*/
    return neighbors;
}

template<typename NODETYPE>
void GraphNode<NODETYPE>::neighborsClear(){
    /*Removes all the neighbors from that node*/
    neighbors.clear();
}

template<typename NODETYPE>
void GraphNode<NODETYPE>::removeNeighbor(GraphNode<NODETYPE>& neighbor){
    /*Receives the GraphNode and removes it from the neighboring nodes*/
    auto neighborIter = find(neighbors.begin(), neighbors.end(), &neighbor);

    if(neighborIter != neighbors.end()) {
        neighbors.erase(neighborIter);
    }
}

template<typename NODETYPE>
typename std::vector<GraphNode<NODETYPE>*>::iterator GraphNode<NODETYPE>::neighborsBegin(){
    /*Returns the vector iterator to the beginning of the neighboring nodes vector*/
    return neighbors.begin();
}

template<typename NODETYPE>
typename std::vector<GraphNode<NODETYPE>*>::iterator GraphNode<NODETYPE>::neighborsEnd(){
    /*Returns the vector iterator to the end of the neighboring nodes*/
    return neighbors.end();
}

template<typename NODETYPE>
bool GraphNode<NODETYPE>::operator==(GraphNode<NODETYPE>& other){
    return (this->data == other.data) and (this->neighbors == other.neighbors);
}

template<typename NODETYPE>
bool GraphNode<NODETYPE>::operator!=(GraphNode<NODETYPE>& other){
    return (this->data != other.data) and (this->neighbors != other.neighbors);
}