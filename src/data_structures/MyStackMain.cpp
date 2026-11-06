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
public:
    MyStack();
    ~MyStack();
    void push(TypeName data);
    TypeName pop();
    TypeName top();
    bool isEmpty();
    int getSize();
    bool isThere(const TypeName& something) const;
    MyStack<int> getWhere(const TypeName& something) const;
};

#include "../src/data_structures/MyStackMain.cpp"
#endif