////#pragma once
////#include "../Core/Node.h"
////#include "../Core/SuperContainer.h"
////
////template<typename TypeName>
////class Queue : public SuperContainer<TypeName>
////{
////public:
////    Queue() : SuperContainer<TypeName>() {}
////
////    ~Queue()
////    {
////        Node<TypeName>* curr_node = this->head;
////        while (curr_node != nullptr)
////        {
////            Node<TypeName>* next_node = curr_node->GetPointer1();
////            delete curr_node;
////            curr_node = next_node;
////        }
////        this->head = nullptr;
////        this->current = nullptr;
////        this->end = nullptr;
////        this->count = 0;
////    }
////
////    virtual int Add(const TypeName& data, int where = 0) override
////    {
////        Node<TypeName>* new_node = new Node<TypeName>(data);
////
////        if (this->head == nullptr)
////        {
////            this->head = new_node;
////            this->end = new_node;
////            this->current = this->head;
////            this->count = 1;
////        }
////        else
////        {
////            // Add to END (back of queue)
////            this->end->SetPointer1(new_node);
////            this->end = new_node;
////            this->count++;
////        }
////        return 0;
////    }
////
////    virtual TypeName Remove(int where = 0) override
////    {
////        return Dequeue();
////    }
////
////    virtual bool IsEmpty() override { return this->head == nullptr; }
////
////    virtual int Clear() override {
////        Node<TypeName>* curr_node = this->head;
////        while (curr_node) {
////            Node<TypeName>* next_node = curr_node->GetPointer1();
////            delete curr_node;
////            curr_node = next_node;
////        }
////        this->head = this->current = this->end = nullptr;
////        this->count = 0;
////        return 0;
////    }
////
////    virtual TypeName Peek() override { return Front(); }
////    virtual int Size() override { return this->count; }
////
////    TypeName Dequeue()
////    {
////        if (this->head == nullptr) return TypeName();
////
////        Node<TypeName>* front_node = this->head;
////        TypeName front_data = front_node->GetData();
////
////        this->head = this->head->GetPointer1();
////        delete front_node;
////        this->count--;
////        this->current = this->head;
////
////        if (this->head == nullptr) {
////            this->end = nullptr;
////            this->current = nullptr;
////        }
////        return front_data;
////    }
////
////    TypeName Front() const
////    {
////        if (this->head == nullptr) return TypeName();
////        return this->head->GetData();
////    }
////};
//#pragma once
//#include "../Core/Node.h"
//#include "../Core/SuperContainer.h"
//
//template<typename TypeName>
//class Queue : public SuperContainer<TypeName> {
//private:
//    void clear() {
//        Node<TypeName>* curr = this->head;
//        while (curr != nullptr) {
//            Node<TypeName>* next = curr->GetPointer1();
//            delete curr;
//            curr = next;
//        }
//        this->head = nullptr;
//        this->current = nullptr;
//        this->end = nullptr;
//        this->count = 0;
//    }
//
//public:
//    Queue() : SuperContainer<TypeName>() {}
//    ~Queue() { clear(); }
//
//    virtual int Add(const TypeName& data, int where = 0) override {
//        Node<TypeName>* new_node = new Node<TypeName>(data);
//        if (this->head == nullptr) {
//            this->head = new_node;
//            this->end = new_node;
//            this->current = this->head;
//            this->count = 1;
//        }
//        else {
//            this->end->SetPointer1(new_node); // P1 = Next
//            this->end = new_node;
//            this->count++;
//        }
//        return 0;
//    }
//
//    virtual int Remove(int where = 0) override {
//        if (IsEmpty()) return -1;
//        Dequeue();
//        return 0;
//    }
//
//    virtual bool IsEmpty() override { return this->head == nullptr; }
//    virtual int Clear() override { clear(); return 0; }
//    virtual TypeName Peek() override { return Front(); }
//    virtual int Size() override { return this->count; }
//
//    TypeName Dequeue() {
//        if (this->head == nullptr) return TypeName();
//        Node<TypeName>* front = this->head;
//        TypeName data = front->GetData();
//        this->head = this->head->GetPointer1();
//        delete front;
//        this->count--;
//        this->current = this->head;
//        if (this->head == nullptr) {
//            this->end = nullptr;
//            this->current = nullptr;
//        }
//        return data;
//    }
//
//    TypeName Front() const {
//        if (this->head == nullptr) return TypeName();
//        return this->head->GetData();
//    }
//};
#pragma once
#include "../Core/Node.h"

template<class TypeName>
class Queue {
private:
    Node<TypeName>* frontNode;
    Node<TypeName>* rearNode;
    int count;
public:
    Queue() : frontNode(nullptr), rearNode(nullptr), count(0) {}
    ~Queue() { Clear(); }

    void Enqueue(TypeName data) {
        Node<TypeName>* newNode = new Node<TypeName>(data);
        if (!rearNode) {
            frontNode = rearNode = newNode;
        }
        else {
            rearNode->SetPointer1(newNode); // p1 = next
            newNode->SetParent(rearNode);
            rearNode = newNode;
        }
        count++;
    }

    TypeName Dequeue() {
        if (!frontNode) throw "Queue empty";
        Node<TypeName>* temp = frontNode;
        TypeName data = temp->GetData();
        frontNode = frontNode->GetPointer1();
        if (frontNode) frontNode->SetParent(nullptr);
        else rearNode = nullptr;
        delete temp;
        count--;
        return data;
    }

    TypeName Front() { return frontNode->GetData(); }
    bool IsEmpty() { return frontNode == nullptr; }
    int Size() { return count; }
    void Clear() { while (!IsEmpty()) Dequeue(); }
};