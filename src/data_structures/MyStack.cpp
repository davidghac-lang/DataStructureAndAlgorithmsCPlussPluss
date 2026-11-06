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
