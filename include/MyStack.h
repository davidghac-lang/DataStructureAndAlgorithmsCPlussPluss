#ifndef MYSTACK_H
#define MYSTACK_H
#include <stdexcept>

template<class TypeName>
class MyStack {
private:
    struct Node {
        TypeName data;
        Node* next;
    };
    Node* head;
    int size;
    void clear(Node* tail); // FIXED! Was Node<TypeName>*
public:
    MyStack();
    MyStack(const MyStack<TypeName>& other);
    ~MyStack();
    void push(TypeName data);
    TypeName pop();
    TypeName top();
    bool isEmpty();
    int getSize();
    bool isThere(const TypeName& something) const;
    MyStack<int> getWhere(const TypeName& something) const;
    void MakeEmpty();
};

#include "../src/data_structures/MyStack.cpp"

#endif