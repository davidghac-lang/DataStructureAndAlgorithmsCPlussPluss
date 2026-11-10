//// Linear/DoubleLinkedList.h - Day 2
//#pragma once
//#include "../Core/SuperContainer.h"
//#include <iostream>
//
//template<class TypeName>
//class DoubleLinkedList : public SuperContainer<TypeName> {
//public:
//    DoubleLinkedList() : SuperContainer<TypeName>() {}
//
//    // YOUR MAPPING: P1=Next, P2=Prev, P3=current
//    Node<TypeName>* GetNext(Node<TypeName>* p) { return p->GetPointer1(); }
//    Node<TypeName>* GetPrev(Node<TypeName>* p) { return p->GetPointer2(); }
//
//    virtual int Add(const TypeName& data, int where) override {
//        Node<TypeName>* newNode = new Node<TypeName>(data);
//
//        if (this->head == nullptr) {
//            this->head = newNode;
//            this->end = newNode;
//            this->current = newNode;
//            newNode->SetPointer3(newNode); // P3 = current
//            this->count = 1;
//            return 0;
//        }
//
//        if (where == 0) { // Add at head
//            newNode->SetPointer1(this->head);
//            this->head->SetPointer2(newNode);
//            this->head = newNode;
//        }
//        else if (where >= this->count) { // Add at end
//            newNode->SetPointer2(this->end);
//            this->end->SetPointer1(newNode);
//            this->end = newNode;
//        }
//        else { // Add in middle
//            Node<TypeName>* curr = this->head;
//            for (int i = 0; i < where; i++) curr = curr->GetPointer1();
//            newNode->SetPointer1(curr);
//            newNode->SetPointer2(curr->GetPointer2());
//            if (curr->GetPointer2()) curr->GetPointer2()->SetPointer1(newNode);
//            curr->SetPointer2(newNode);
//        }
//
//        this->current = newNode;
//        newNode->SetPointer3(newNode);
//        this->count++;
//        return 0;
//    }
//
//    virtual int Remove(int where) override {
//        if (this->head == nullptr) return -1;
//
//        Node<TypeName>* toDelete = nullptr;
//        if (where == 0) {
//            toDelete = this->head;
//            this->head = this->head->GetPointer1();
//            if (this->head) this->head->SetPointer2(nullptr);
//            else this->end = nullptr;
//        }
//        else if (where >= this->count - 1) {
//            toDelete = this->end;
//            this->end = this->end->GetPointer2();
//            if (this->end) this->end->SetPointer1(nullptr);
//            else this->head = nullptr;
//        }
//        else {
//            toDelete = this->head;
//            for (int i = 0; i < where; i++) toDelete = toDelete->GetPointer1();
//            if (toDelete->GetPointer2()) toDelete->GetPointer2()->SetPointer1(toDelete->GetPointer1());
//            if (toDelete->GetPointer1()) toDelete->GetPointer1()->SetPointer2(toDelete->GetPointer2());
//        }
//
//        if (this->current == toDelete) this->current = this->head;
//        delete toDelete;
//        this->count--;
//        return 0;
//    }
//
//    virtual bool IsEmpty() override { return this->head == nullptr; }
//
//    virtual int Clear() override {
//        Node<TypeName>* curr = this->head;
//        while (curr != nullptr) {
//            Node<TypeName>* next = curr->GetPointer1();
//            delete curr;
//            curr = next;
//        }
//        this->head = nullptr;
//        this->end = nullptr;
//        this->current = nullptr;
//        this->count = 0;
//        return 0;
//    }
//
//    virtual TypeName Peek() override {
//        if (this->current) return this->current->GetData();
//        if (this->head) return this->head->GetData();
//        return TypeName();
//    }
//
//    virtual int Size() override { return this->count; }
//
//    void Print() {
//        Node<TypeName>* curr = this->head;
//        std::cout << "List: ";
//        while (curr != nullptr) {
//            std::cout << curr->GetData() << " ";
//            curr = curr->GetPointer1(); // P1 = Next
//        }
//        std::cout << std::endl;
//    }
//};
// PowerOfThreePointers/Linear/DoubleLinkedList.h - Day 2
// PowerOfThreePointers/Linear/DoubleLinkedList.h - Day 2 - Snake Style
//#pragma once
//#include "../Core/SuperContainer.h"
//#include <iostream>
//
//template<class TypeName>
//class DoubleLinkedList : public SuperContainer<TypeName> {
//private:
//    void clear() {
//        Node<TypeName>* curr_node = this->head;
//        while (curr_node != nullptr) {
//            Node<TypeName>* next_node = curr_node->GetPointer1();
//            delete curr_node;
//            curr_node = next_node;
//        }
//        this->head = nullptr;
//        this->end = nullptr;
//        this->current = nullptr;
//        this->count = 0;
//    }
//
//public:
//    DoubleLinkedList() : SuperContainer<TypeName>() {}
//
//    ~DoubleLinkedList() {
//        clear();
//    }
//
//    Node<TypeName>* GetNext(Node<TypeName>* p) {
//        return p->GetPointer1();
//    }
//
//    Node<TypeName>* GetPrev(Node<TypeName>* p) {
//        return p->GetPointer2();
//    }
//
//    virtual int Add(const TypeName& data, int where) override {
//        Node<TypeName>* new_node = new Node<TypeName>(data);
//
//        if (this->head == nullptr) {
//            this->head = new_node;
//            this->end = new_node;
//            this->current = new_node;
//            new_node->SetPointer3(new_node);
//            this->count = 1;
//            return 0;
//        }
//
//        if (where == 0) {
//            new_node->SetPointer1(this->head);
//            this->head->SetPointer2(new_node);
//            this->head = new_node;
//        }
//        else if (where >= this->count) {
//            new_node->SetPointer2(this->end);
//            this->end->SetPointer1(new_node);
//            this->end = new_node;
//        }
//        else {
//            Node<TypeName>* curr_node = this->head;
//            for (int i = 0; i < where; i++) {
//                curr_node = curr_node->GetPointer1();
//            }
//            new_node->SetPointer1(curr_node);
//            new_node->SetPointer2(curr_node->GetPointer2());
//            if (curr_node->GetPointer2()) {
//                curr_node->GetPointer2()->SetPointer1(new_node);
//            }
//            curr_node->SetPointer2(new_node);
//        }
//
//        this->current = new_node;
//        new_node->SetPointer3(new_node);
//        this->count++;
//        return 0;
//    }
//
//    virtual int Remove(int where) override {
//        if (this->head == nullptr) return -1;
//
//        Node<TypeName>* to_delete = nullptr;
//
//        if (where == 0) {
//            to_delete = this->head;
//            this->head = this->head->GetPointer1();
//            if (this->head) this->head->SetPointer2(nullptr);
//            else this->end = nullptr;
//        }
//        else if (where >= this->count - 1) {
//            to_delete = this->end;
//            this->end = this->end->GetPointer2();
//            if (this->end) this->end->SetPointer1(nullptr);
//            else this->head = nullptr;
//        }
//        else {
//            to_delete = this->head;
//            for (int i = 0; i < where; i++) {
//                to_delete = to_delete->GetPointer1();
//            }
//            if (to_delete->GetPointer2()) {
//                to_delete->GetPointer2()->SetPointer1(to_delete->GetPointer1());
//            }
//            if (to_delete->GetPointer1()) {
//                to_delete->GetPointer1()->SetPointer2(to_delete->GetPointer2());
//            }
//        }
//
//        if (this->current == to_delete) {
//            this->current = this->head;
//        }
//        delete to_delete;
//        this->count--;
//        return 0;
//    }
//
//    virtual bool IsEmpty() override {
//        return this->head == nullptr;
//    }
//
//    virtual int Clear() override {
//        clear();
//        return 0;
//    }
//
//    virtual TypeName Peek() override {
//        if (this->current) return this->current->GetData();
//        if (this->head) return this->head->GetData();
//        return TypeName();
//    }
//
//    virtual int Size() override {
//        return this->count;
//    }
//
//    void Print() {
//        Node<TypeName>* curr_node = this->head;
//        std::cout << "List: ";
//        while (curr_node != nullptr) {
//            std::cout << curr_node->GetData() << " ";
//            curr_node = curr_node->GetPointer1();
//        }
//        std::cout << std::endl;
//    }
//};
#pragma once
#include "../Core/SuperContainer.h"
#include <iostream>

template<class TypeName>
class DoubleLinkedList : public SuperContainer<TypeName> {
private:
    void clear() {
        Node<TypeName>* curr = this->head;
        while (curr != nullptr) {
            Node<TypeName>* next = curr->GetPointer1();
            delete curr;
            curr = next;
        }
        this->head = nullptr;
        this->end = nullptr;
        this->current = nullptr;
        this->count = 0;
    }

public:
    DoubleLinkedList() : SuperContainer<TypeName>() {}
    ~DoubleLinkedList() { clear(); }

    // P1 = Next, P2 = Prev - Clean Empire Mapping
    Node<TypeName>* GetNext(Node<TypeName>* p) { return p->GetPointer1(); }
    Node<TypeName>* GetPrev(Node<TypeName>* p) { return p->GetPointer2(); }

    virtual int Add(const TypeName& data, int where) override {
        Node<TypeName>* new_node = new Node<TypeName>(data);
        // P1,P2,P3 auto nullptr from Node constructor

        if (this->head == nullptr) {
            this->head = new_node;
            this->end = new_node;
            this->current = new_node;
            this->count = 1;
            return 0;
        }

        if (where == 0) { // Head
            new_node->SetPointer1(this->head);
            this->head->SetPointer2(new_node);
            this->head = new_node;
        }
        else if (where >= this->count) { // Tail
            new_node->SetPointer2(this->end);
            this->end->SetPointer1(new_node);
            this->end = new_node;
        }
        else { // Middle - insert before curr
            Node<TypeName>* curr = this->head;
            for (int i = 0; i < where; i++) curr = curr->GetPointer1();
            new_node->SetPointer1(curr);
            new_node->SetPointer2(curr->GetPointer2());
            if (curr->GetPointer2()) curr->GetPointer2()->SetPointer1(new_node);
            curr->SetPointer2(new_node);
        }

        this->current = new_node;
        this->count++;
        return 0;
    }

    virtual int Remove(int where) override {
        if (this->head == nullptr) return -1;

        Node<TypeName>* to_delete = nullptr;

        if (where == 0) {
            to_delete = this->head;
            this->head = this->head->GetPointer1();
            if (this->head) this->head->SetPointer2(nullptr);
            else this->end = nullptr;
        }
        else if (where >= this->count - 1) {
            to_delete = this->end;
            this->end = this->end->GetPointer2();
            if (this->end) this->end->SetPointer1(nullptr);
            else this->head = nullptr;
        }
        else {
            to_delete = this->head;
            for (int i = 0; i < where; i++) to_delete = to_delete->GetPointer1();
            if (to_delete->GetPointer2()) to_delete->GetPointer2()->SetPointer1(to_delete->GetPointer1());
            if (to_delete->GetPointer1()) to_delete->GetPointer1()->SetPointer2(to_delete->GetPointer2());
        }

        if (this->current == to_delete) this->current = this->head;
        delete to_delete;
        this->count--;
        return 0;
    }

    virtual bool IsEmpty() override { return this->head == nullptr; }
    virtual int Clear() override { clear(); return 0; }
    virtual TypeName Peek() override {
        if (this->current) return this->current->GetData();
        if (this->head) return this->head->GetData();
        return TypeName();
    }
    virtual int Size() override { return this->count; }

    void Print() {
        Node<TypeName>* curr = this->head;
        std::cout << "List: ";
        while (curr != nullptr) {
            std::cout << curr->GetData() << " ";
            curr = curr->GetPointer1();
        }
        std::cout << std::endl;
    }
};