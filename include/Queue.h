#ifndef MYQUEUE_H
#define MYQUEUE_H
#include <stdexcept>
#include "MyStack.h"

template <class TypeName>
class Queue {
private:
    struct Node {
        Node* next;
        TypeName data;
        static Node* CreateItem(TypeName& data) {
            Node* node = new Node(); // local fresh variable, not member!
            node->data = data;
            node->next = nullptr; // not null, nullptr
            return node;
        }
    };

    Node* head;
    int size;

    void clear();

public:
    Queue();
    Queue(const Queue& copy_from);
    Queue(const MyStack<TypeName>& copy_from_stack);
    ~Queue();

    int PushBack(TypeName& data);
    TypeName PopFront();
    TypeName GetFront();

    int GetWhere(TypeName& data);
    TypeName GetWhere(int index);
    TypeName GetNext(int index);

    bool IsEmpty();
    void MakeEmpty();
    int Size();
};
#endif
