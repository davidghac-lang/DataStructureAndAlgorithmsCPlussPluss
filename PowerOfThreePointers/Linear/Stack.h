//#pragma once
//#include "../Core/Node.h"
//#include "../Core/SuperContainer.h"
//
//template<typename TypeName>
//class Stack : public SuperContainer<TypeName> {
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
//    Stack() : SuperContainer<TypeName>() {}
//
//    ~Stack() {
//        clear();
//    }
//
//    // YOUR MAPPING: P1=Next, P2=current, P3=end (top) - LIFO
//    virtual int Add(const TypeName& data, int where = 0) override {
//        if (where != 0) return -1;
//
//        Node<TypeName>* new_node = new Node<TypeName>(data);
//
//        // P1 = Next, P2 = current (self), P3 = end
//        new_node->SetPointer1(this->head);
//        new_node->SetPointer2(new_node);
//        new_node->SetPointer3(new_node);
//
//        if (this->head == nullptr) {
//            this->head = new_node;
//            this->end = new_node; // end = bottom, first node
//            this->current = new_node;
//            this->count = 1;
//        }
//        else {
//            this->head = new_node;
//            this->current = this->head;
//            this->count++;
//        }
//
//        return 0;
//    }
//
//    virtual int Remove(int where = 0) override {
//        if (where != 0) return -1;
//        if (this->head == nullptr) return -1;
//        Pop();
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
//        return Top();
//    }
//
//    virtual int Size() override {
//        return this->count;
//    }
//
//    TypeName Pop() {
//        if (this->head == nullptr) return TypeName();
//
//        Node<TypeName>* top_node = this->head;
//        TypeName top_data = top_node->GetData();
//
//        this->head = this->head->GetPointer1();
//        delete top_node;
//        this->count--;
//
//        this->current = this->head;
//        if (this->head == nullptr) {
//            this->end = nullptr;
//            this->current = nullptr;
//        }
//
//        return top_data;
//    }
//
//    TypeName Top() const {
//        if (this->head == nullptr) return TypeName();
//        return this->head->GetData();
//    }
//
//    void Print() const {
//        Node<TypeName>* curr_node = this->head;
//        std::cout << "Stack (top->bottom): ";
//        while (curr_node != nullptr) {
//            std::cout << curr_node->GetData() << " ";
//            curr_node = curr_node->GetPointer1();
//        }
//        std::cout << std::endl;
//    }
//};
#pragma once
#include "../Core/Node.h"

template<class TypeName>
class Stack {
private:
    Node<TypeName>* topNode;
    int count;
public:
    Stack() : topNode(nullptr), count(0) {}
    ~Stack() { Clear(); }

    void Push(TypeName data) {
        Node<TypeName>* newNode = new Node<TypeName>(data);
        newNode->SetPointer1(topNode); // p1 = next
        if (topNode) topNode->SetParent(newNode); // optional
        topNode = newNode;
        count++;
    }

    TypeName Pop() {
        if (!topNode) throw "Stack empty";
        Node<TypeName>* temp = topNode;
        TypeName data = temp->GetData();
        topNode = topNode->GetPointer1();
        if (topNode) topNode->SetParent(nullptr);
        delete temp;
        count--;
        return data;
    }

    TypeName Peek() {
        if (!topNode) throw "Stack empty";
        return topNode->GetData();
    }

    bool IsEmpty() { return topNode == nullptr; }
    int Size() { return count; }

    void Clear() {
        while (!IsEmpty()) Pop();
    }
};