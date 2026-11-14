#pragma once
#include "../Core/Node.h"
#include <iostream>
#include <vector>
template<class TypeName>
class MemoryManager {
private:
    std::vector<Node<TypeName>*> all_nodes;
    int total_allocated=0, total_freed=0;
public:
    Node<TypeName>* Allocate(TypeName data){ auto n=new Node<TypeName>(data); all_nodes.push_back(n); total_allocated++; return n; }
    void PrintStats(){ std::cout<<"Alloc:"<<total_allocated<<" Freed:"<<total_freed<<" Leak:"<<(total_allocated-total_freed)<<"\n"; }
    ~MemoryManager(){ for(auto n:all_nodes) delete n; }
};
