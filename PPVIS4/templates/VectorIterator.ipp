#pragma once

template<typename NODETYPE>
VectorIterator<NODETYPE>::VectorIterator(){
    this->pos = nullptr;
}

template<typename NODETYPE>
VectorIterator<NODETYPE>::VectorIterator(const VectorIterator& other){
    this->pos = other.pos;
}

template<typename NODETYPE>
VectorIterator<NODETYPE>::VectorIterator(NODETYPE* pos){
    this->pos = pos;
}

template<typename NODETYPE>
VectorIterator<NODETYPE>& VectorIterator<NODETYPE>::operator=(const VectorIterator& other){
    this->pos = other.pos;
}

template<typename NODETYPE>
VectorIterator<NODETYPE>& VectorIterator<NODETYPE>::operator++(){
    ++pos;
    return *this;
}

template<typename NODETYPE>
VectorIterator<NODETYPE>& VectorIterator<NODETYPE>::operator++(int){
    VectorIterator tmp(*this);
    pos++;
    return tmp;
}

template<typename NODETYPE>
bool VectorIterator<NODETYPE>::operator==(const VectorIterator& it){
    return this->pos == it.pos;
}

template<typename NODETYPE>
bool VectorIterator<NODETYPE>::operator!=(const VectorIterator& it){
    return this->pos != it.pos;
}

template<typename NODETYPE>
NODETYPE& VectorIterator<NODETYPE>::operator*(){
    return *pos;
}

template<typename NODETYPE>
NODETYPE* VectorIterator<NODETYPE>::operator->(){
    return pos;
}