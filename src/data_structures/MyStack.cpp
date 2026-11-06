#include "MyStack.h"

template<class TypeName>
MyStack<TypeName>::MyStack() { head = nullptr; size = 0; }

template<class TypeName>
MyStack<TypeName>::~MyStack() { while (head != nullptr) { Node* temp = head; head = head->next; delete temp; } }

template<class TypeName>
void MyStack<TypeName>::push(TypeName data) { Node* new_node = new Node(); new_node->data = data; new_node->next = head; head = new_node; size++; }

template<class TypeName>
TypeName MyStack<TypeName>::pop() { if (isEmpty()) throw std::out_of_range("Stack is empty"); Node* temp = head; TypeName d = head->data; head = head->next; delete temp; size--; return d; }

template<class TypeName>
TypeName MyStack<TypeName>::top() { if (head != nullptr) return head->data; throw std::out_of_range("Stack is empty"); }

template<class TypeName>
bool MyStack<TypeName>::isEmpty() { return head == nullptr; }

template<class TypeName>
int MyStack<TypeName>::getSize() { return size; }

template<class TypeName>
bool MyStack<TypeName>::isThere(const TypeName& something) const { Node* current = head; while (current != nullptr) { if (current->data == something) return true; current = current->next; } return false; }

template<class TypeName>
MyStack<int> MyStack<TypeName>::getWhere(const TypeName& something) const { MyStack<int> result; Node* current = head; int index = 0; while (current != nullptr) { if (current->data == something) result.push(index); current = current->next; index++; } return result; }
template<class TypeName>
MyStack<TypeName>::template <typename TypeName>
MyStack<TypeName>::MyStack(const MyStack<TypeName>& other) {
    head = nullptr;
    size = 0;

    if (other.head == nullptr) {
        return; // other stack is empty, nothing to copy
    }

    // 1. Copy first node - this will be our head forever
    head = new Node<TypeName>();
    head->data = other.head->data;
    head->next = nullptr;
    size = 1;

    // 2. Two pointers: one to read from 'other', one to write in 'this'
    Node<TypeName>* other_current = other.head->next; // read
    Node<TypeName>* my_tail = head; // write - tail moves, head stays!

    // 3. Copy rest of nodes one by one
    while (other_current != nullptr) {
        Node<TypeName>* new_node = new Node<TypeName>();
        new_node->data = other_current->data;
        new_node->next = nullptr;

        my_tail->next = new_node; // link new node to our list
        my_tail = new_node; // move tail forward, HEAD NEVER MOVES!

        other_current = other_current->next;
        size++;
    }
}
template<class TypeName>
void MyStack<TypeName>::clear(Node<TypeName> *tail) {
    if (tail != nullptr) {
        clear(tail->next);
    }
    if (tail != nullptr) {
        delete tail;
    }
}
template<class TypeName>
void MyStack<TypeName>::MakeEmpty() {
    clear(head);
    head = nullptr;
    size = 0;
}