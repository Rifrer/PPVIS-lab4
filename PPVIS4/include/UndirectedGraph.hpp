#pragma once

#include <vector>
#include <algorithm>
#include <iterator>
#include <set>

#include "GraphNode.hpp"

template<typename NODETYPE>
class UndirectedGraph {
public:
    // standard typedefs
    typedef NODETYPE value_type;

    typedef value_type* pointer;
    typedef const pointer const_pointer;

    typedef value_type& reference;
    typedef const reference const_reference;

    typedef size_t size_type;
    typedef ptrdiff_t difference_type;
    ///

private:
    std::vector<GraphNode<value_type>*> nodes;

public:

    explicit UndirectedGraph(const std::vector<GraphNode<value_type>*>& nodes={});

    UndirectedGraph(UndirectedGraph<NODETYPE>& other);

    bool operator==(UndirectedGraph<NODETYPE>& other);

    bool operator!=(UndirectedGraph<NODETYPE>& other);

    void insert(GraphNode<value_type>& node);

    std::vector<GraphNode<value_type>*> getNodes();

    void setEdge(GraphNode<value_type>& node1, GraphNode<value_type>& node2);

    int size();

    int edgesNumber();

    int power(GraphNode<value_type>& node); 

    bool nodeIsHere(GraphNode<value_type>& node);

    bool edgeIsHere(GraphNode<value_type>& node1, GraphNode<value_type>& node2);

    bool empty();

    void clear();

    UndirectedGraph<NODETYPE>& operator=(UndirectedGraph<NODETYPE>& other);

    void deleteEdge(GraphNode<value_type>& node1, GraphNode<value_type>& node2);

    void deleteEdge(typename std::vector<std::pair<GraphNode<NODETYPE>*, GraphNode<NODETYPE>*>>::iterator& it);

    void deleteNode(GraphNode<value_type>& node);

    void deleteNode(typename std::vector<GraphNode<NODETYPE>*>::iterator& it);

    std::vector<std::pair<GraphNode<NODETYPE>*, GraphNode<NODETYPE>*>> getAllEdges();

    typename std::vector<GraphNode<NODETYPE>*>::iterator beginNode();
    
    typename std::vector<GraphNode<NODETYPE>*>::iterator endNode();
};

#include "UndirectedGraph.ipp"