#pragma once

template<typename NODETYPE>
class VectorIterator {
public:
    NODETYPE* pos;

private:
    explicit VectorIterator();

    VectorIterator(const VectorIterator& other);

    VectorIterator(NODETYPE* pos);

    VectorIterator& operator=(const VectorIterator& other);

    VectorIterator& operator++();

    VectorIterator& operator++(int);

    bool operator==(const VectorIterator& it);

    bool operator!=(const VectorIterator& it);

    NODETYPE& operator*();

    NODETYPE* operator->();
};

#include "VectorIterator.ipp"