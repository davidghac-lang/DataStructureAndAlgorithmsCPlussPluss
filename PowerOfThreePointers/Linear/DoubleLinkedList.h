// Linear/DoubleLinkedList.h - Day 2
#pragma once
#include "../Core/SuperContainer.h"
#include <iostream>

template<class TypeName>
class DoubleLinkedList : public SuperContainer<TypeName> {
public:
    DoubleLinkedList() : SuperContainer<TypeName>() {}

    // YOUR MAPPING: P1=Next, P2=Prev, P3=current
    Node<TypeName>* GetNext(Node<TypeName>* p) { return p->GetPointer1(); }
    Node<TypeName>* GetPrev(Node<TypeName>* p) { return p->GetPointer2(); }

    virtual int Add(const TypeName& data, int where) override {
        Node<TypeName>* newNode = new Node<TypeName>(data);

        if (this->head == nullptr) {
            this->head = newNode;
            this->end = newNode;
            this->current = newNode;
            newNode->SetPointer3(newNode); // P3 = current
            this->count = 1;
            return 0;
        }

        if (where == 0) { // Add at head
            newNode->SetPointer1(this->head);
            this->head->SetPointer2(newNode);
            this->head = newNode;
        }
        else if (where >= this->count) { // Add at end
            newNode->SetPointer2(this->end);
            this->end->SetPointer1(newNode);
            this->end = newNode;
        }
        else { // Add in middle
            Node<TypeName>* curr = this->head;
            for (int i = 0; i < where; i++) curr = curr->GetPointer1();
            newNode->SetPointer1(curr);
            newNode->SetPointer2(curr->GetPointer2());
            if (curr->GetPointer2()) curr->GetPointer2()->SetPointer1(newNode);
            curr->SetPointer2(newNode);
        }

        this->current = newNode;
        newNode->SetPointer3(newNode);
        this->count++;
        return 0;
    }

    virtual int Remove(int where) override {
        if (this->head == nullptr) return -1;

        Node<TypeName>* toDelete = nullptr;
        if (where == 0) {
            toDelete = this->head;
            this->head = this->head->GetPointer1();
            if (this->head) this->head->SetPointer2(nullptr);
            else this->end = nullptr;
        }
        else if (where >= this->count - 1) {
            toDelete = this->end;
            this->end = this->end->GetPointer2();
            if (this->end) this->end->SetPointer1(nullptr);
            else this->head = nullptr;
        }
        else {
            toDelete = this->head;
            for (int i = 0; i < where; i++) toDelete = toDelete->GetPointer1();
            if (toDelete->GetPointer2()) toDelete->GetPointer2()->SetPointer1(toDelete->GetPointer1());
            if (toDelete->GetPointer1()) toDelete->GetPointer1()->SetPointer2(toDelete->GetPointer2());
        }

        if (this->current == toDelete) this->current = this->head;
        delete toDelete;
        this->count--;
        return 0;
    }

    virtual bool IsEmpty() override { return this->head == nullptr; }

    virtual int Clear() override {
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
        return 0;
    }

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
            curr = curr->GetPointer1(); // P1 = Next
        }
        std::cout << std::endl;
    }
};