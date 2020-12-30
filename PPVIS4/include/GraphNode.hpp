#pragma once

#include <vector>
#include <algorithm>

template <typename NODETYPE>
class GraphNode {
private:
    NODETYPE data;
    std::vector<GraphNode<NODETYPE>*> neighbors;

public:
    explicit GraphNode(const NODETYPE& data);

    NODETYPE getData();

    bool operator==(GraphNode<NODETYPE>& other);

    bool operator!=(GraphNode<NODETYPE>& other);

    void addNeighbor(GraphNode<NODETYPE>* neighbor);

    std::vector<GraphNode<NODETYPE>*> getNeighbors();

    void neighborsClear();

    void removeNeighbor(GraphNode<NODETYPE>& neighbor);

    typename std::vector<GraphNode<NODETYPE>*>::iterator neighborsBegin();

    typename std::vector<GraphNode<NODETYPE>*>::iterator neighborsEnd();
};

#include "GraphNode.ipp"