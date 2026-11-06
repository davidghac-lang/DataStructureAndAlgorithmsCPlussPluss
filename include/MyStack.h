#ifndef MYSTACK_H
#define MYSTACK_H
#include <stdexcept>

template<class TypeName>
class MyStack {
private:
    struct Node { TypeName data; Node* next; };
    Node* head;
    int size;
public:
    MyStack(){ head=nullptr; size=0; }
    ~MyStack(){ while(head!=nullptr){ Node* t=head; head=head->next; delete t; } }
    void push(TypeName d){ Node* n=new Node(); n->data=d; n->next=head; head=n; size++; }
    TypeName pop(){ if(isEmpty()) throw std::out_of_range("empty"); Node* t=head; TypeName v=head->data; head=head->next; delete t; size--; return v; }
    TypeName top(){ if(head!=nullptr) return head->data; throw std::out_of_range("empty"); }
    bool isEmpty(){ return head==nullptr; }
    int getSize(){ return size; }
    bool isThere(const TypeName& s) const { Node* c=head; while(c!=nullptr){ if(c->data==s) return true; c=c->next; } return false; }
    MyStack<int> getWhere(const TypeName& s) const { MyStack<int> r; Node* c=head; int i=0; while(c!=nullptr){ if(c->data==s) r.push(i); c=c->next; i++; } return r; }
};
#endif
