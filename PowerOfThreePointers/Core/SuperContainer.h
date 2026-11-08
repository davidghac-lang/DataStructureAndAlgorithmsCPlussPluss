// Core/SuperContainer.h - FIXED!
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

    virtual ~SuperContainer() {
        // FIXED! Don't call pure virtual Clear() from destructor!
        head = nullptr;
        current = nullptr;
        end = nullptr;
        count = 0;
    }

    virtual int Add(const TypeName& data, int where) = 0;
    virtual int Remove(int where) = 0;
    virtual bool IsEmpty() = 0;
    virtual int Clear() = 0;
    virtual TypeName Peek() = 0;
    virtual int Size() = 0;

    Node<TypeName>* GetHead() { return head; }
    Node<TypeName>* GetCurrent() { return current; }
    Node<TypeName>* GetEnd() { return end; }

    void SetHead(Node<TypeName>* h) { head = h; }
    void SetCurrent(Node<TypeName>* c) { current = c; }
    void SetEnd(Node<TypeName>* e) { end = e; }

    int GetCount() { return count; }
};