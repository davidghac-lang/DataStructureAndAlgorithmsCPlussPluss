#pragma once
#include "../Core/Node.h"
#include "../Core/SuperContainer.h"

template<typename TypeName>
class Stack : public SuperContainer<TypeName>
{
public:
    Stack() : SuperContainer<TypeName>() {}

    ~Stack()
    {
        Node<TypeName>* curr_node = this->head;
        while (curr_node != nullptr)
        {
            Node<TypeName>* next_node = curr_node->GetPointer1();
            delete curr_node;
            curr_node = next_node;
        }
        this->head = nullptr;
        this->current = nullptr;
        this->end = nullptr;
        this->count = 0;
    }

    virtual int Add(const TypeName& data, int where = 0) override
    {
        Node<TypeName>* new_node = new Node<TypeName>(data);

        if (this->head == nullptr)
        {
            this->head = new_node;
            this->current = this->head;
            this->end = this->head;
            this->count = 1;
        }
        else if (where == 0)
        {
            new_node->SetPointer1(this->head);
            this->head = new_node;
            this->current = this->head;
            this->count++;
        }
        else
        {
            delete new_node;
            return -1;
        }
        return 0;
    }

    virtual TypeName Remove(int where = 0) override
    {
        return Pop();
    }

    virtual bool IsEmpty() override { return this->head == nullptr; }

    virtual int Clear() override {
        Node<TypeName>* curr_node = this->head;
        while (curr_node) {
            Node<TypeName>* next_node = curr_node->GetPointer1();
            delete curr_node;
            curr_node = next_node;
        }
        this->head = this->current = this->end = nullptr;
        this->count = 0;
        return 0;
    }

    virtual TypeName Peek() override { return Top(); }
    virtual int Size() override { return this->count; }

    TypeName Pop()
    {
        if (this->head == nullptr) return TypeName();
        Node<TypeName>* top_node = this->head;
        TypeName top_data = top_node->GetData();
        this->head = this->head->GetPointer1();
        delete top_node;
        this->count--;
        this->current = this->head;
        if (this->head == nullptr) { this->end = nullptr; this->current = nullptr; }
        return top_data;
    }

    TypeName Top() const
    {
        if (this->head == nullptr) return TypeName();
        return this->head->GetData();
    }
};