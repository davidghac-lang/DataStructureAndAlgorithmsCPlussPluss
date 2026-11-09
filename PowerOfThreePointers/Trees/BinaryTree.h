#pragma once
#include "../Core/SuperContainer.h"
#include <iostream>

template<typename TypeName>
class BinaryTree : public SuperContainer<TypeName> {
public:
    BinaryTree() {
        this->head = nullptr;
        this->current = nullptr;
        this->count = 0;
    }

    // SuperContainer overrides - REQUIRED!
    virtual int Add(const TypeName& data, int where = 0) override {
        AddNode(data);
        return this->count;
    }

    virtual int Remove(int where) override {
        // Simple: not implemented for BST, just return
        return this->count;
    }

    virtual bool IsEmpty() override {
        return this->head == nullptr;
    }

    virtual int Clear() override {
        this->head = nullptr;
        this->current = nullptr;
        this->count = 0;
        return 0;
    }

    virtual TypeName Peek() override {
        if (this->head) return this->head->GetData();
        return TypeName();
    }

    virtual int Size() override {
        return this->count;
    }

    // Your real logic
    void AddNode(TypeName data) {
        Node<TypeName>* new_node = new Node<TypeName>(data);

        if (!this->head) {
            this->head = new_node;
            this->count++;
            return;
        }

        Node<TypeName>* curr = this->head;
        Node<TypeName>* parent = nullptr;

        while (curr) {
            parent = curr;
            if (data < curr->GetData()) {
                curr = curr->GetPointer1(); // P1 = Left
            }
            else {
                curr = curr->GetPointer2(); // P2 = Right
            }
        }

        new_node->SetPointer3(parent); // P3 = Parent

        if (data < parent->GetData()) {
            parent->SetPointer1(new_node);
        }
        else {
            parent->SetPointer2(new_node);
        }

        this->count++;
    }

    bool Search(TypeName data) {
        Node<TypeName>* curr = this->head;
        while (curr) {
            if (data == curr->GetData()) return true;
            if (data < curr->GetData()) curr = curr->GetPointer1();
            else curr = curr->GetPointer2();
        }
        return false;
    }

    Node<TypeName>* GetHead() { return this->head; }
    Node<TypeName>* GetLeftChild(Node<TypeName>* node) {
        return node ? node->GetPointer1() : nullptr;
    }
    Node<TypeName>* GetRightChild(Node<TypeName>* node) {
        return node ? node->GetPointer2() : nullptr;
    }
    Node<TypeName>* GetParent(Node<TypeName>* node) {
        return node ? node->GetPointer3() : nullptr;
    }

    void PrintTree(Node<TypeName>* node, int depth) {
        if (!node) return;
        PrintTree(node->GetPointer2(), depth + 1);
        for (int i = 0; i < depth; i++) std::cout << "   ";
        std::cout << node->GetData() << std::endl;
        PrintTree(node->GetPointer1(), depth + 1);
    }

    void Print() {
        PrintTree(this->head, 0);
    }
};