//#pragma once
//#include "Node.h"
//
//template<class TypeName>
//class SuperContainer {
//protected:
//    Node<TypeName>* head;
//    Node<TypeName>* current;
//    Node<TypeName>* end;
//    int count;
//
//public:
//    SuperContainer() {
//        head = nullptr;
//        current = nullptr;
//        end = nullptr;
//        count = 0;
//    }
//
//    virtual ~SuperContainer() {}
//
//    virtual int Add(const TypeName& data, int where) = 0;
//    virtual int Remove(int where) = 0;
//    virtual bool IsEmpty() = 0;
//    virtual int Clear() = 0;
//    virtual TypeName Peek() = 0;
//    virtual int Size() = 0;
//};
#pragma once
#include "Node.h"

template<class TypeName>
class SuperContainer {
protected:
    Node<TypeName>* head;
    Node<TypeName>* current;
    Node<TypeName>* end;
    int count;

public:
    SuperContainer() {
        head = nullptr;
        current = nullptr;
        end = nullptr;
        count = 0;
    }
    virtual ~SuperContainer() {}
    virtual int Add(const TypeName& data, int where) = 0;
    virtual int Remove(int where) = 0;
    virtual bool IsEmpty() = 0;
    virtual int Clear() = 0;
    virtual TypeName Peek() = 0;
    virtual int Size() = 0;

    Node<TypeName>* GetHead() { return head; }
    Node<TypeName>* GetCurrent() { return current; }
    Node<TypeName>* GetEnd() { return end; }
};