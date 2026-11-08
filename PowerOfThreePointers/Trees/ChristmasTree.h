// Trees/ChristmasTree.h
#pragma once
#include "../Core/SuperContainer.h"
#include <queue>
#include <iostream>

template<class TypeName>
class LevelInfo {
private:
    int levelNumber;
    Node<TypeName>* levelHead;
    Node<TypeName>* levelEnd;
    int levelCount;
public:
    LevelInfo(int level) {
        levelNumber = level;
        levelHead = nullptr;
        levelEnd = nullptr;
        levelCount = 0;
    }
    Node<TypeName>* GetLevelHead() { return levelHead; }
    Node<TypeName>* GetLevelEnd() { return levelEnd; }
    int GetLevelCount() { return levelCount; }
    void SetLevelHead(Node<TypeName>* h) { levelHead = h; }
    void SetLevelEnd(Node<TypeName>* e) { levelEnd = e; }
    void IncCount() { levelCount++; }
};

template<class TypeName>
class ChristmasTree : public SuperContainer<TypeName> {
private:
    LevelInfo<TypeName>** levels;
    int maxLevel;
    int treeHeight;

    Node<TypeName>* FindNode(const TypeName& data) {
        if (this->head == nullptr) return nullptr;
        std::queue<Node<TypeName>*> q;
        q.push(this->head);
        while (!q.empty()) {
            Node<TypeName>* curr = q.front(); q.pop();
            if (curr->GetData() == data) return curr;
            Node<TypeName>* child = curr->GetPointer3();
            while (child != nullptr) {
                q.push(child);
                child = child->GetPointer1();
            }
        }
        return nullptr;
    }

public:
    ChristmasTree() : SuperContainer<TypeName>() {
        maxLevel = 100;
        levels = new LevelInfo<TypeName>*[maxLevel];
        for (int i = 0;i < maxLevel;i++) levels[i] = nullptr;
        treeHeight = 0;
        levels[0] = new LevelInfo<TypeName>(0);
    }

    virtual int Add(const TypeName& data, int where) override { return 0; }
    virtual int Remove(int where) override { return 0; }
    virtual bool IsEmpty() override { return this->head == nullptr; }
    virtual int Clear() override { return 0; }
    virtual TypeName Peek() override { return this->head->GetData(); }
    virtual int Size() override { return this->count; }

    // YOUR MAPPING: P1=LevelNext, P2=LevelPrev, P3=LeftChild
    Node<TypeName>* GetLeftChild(Node<TypeName>* p) { return p->GetPointer3(); }
    Node<TypeName>* GetRightChild(Node<TypeName>* p) {
        Node<TypeName>* left = p->GetPointer3();
        if (!left) return nullptr;
        return left->GetPointer1(); // TRICK: Right = Left->P1
    }

    int AddRoot(const TypeName& data) {
        Node<TypeName>* n = new Node<TypeName>(data);
        this->head = n; this->end = n; this->current = n; this->count = 1;
        levels[0]->SetLevelHead(n); levels[0]->SetLevelEnd(n); levels[0]->IncCount();
        return 0;
    }

    int AddChild(const TypeName& parentData, const TypeName& childData) {
        Node<TypeName>* parent = FindNode(parentData);
        if (!parent) return -1;
        Node<TypeName>* n = new Node<TypeName>(childData);
        if (parent->GetPointer3() == nullptr) parent->SetPointer3(n);
        else {
            Node<TypeName>* last = parent->GetPointer3();
            while (last->GetPointer1() != nullptr) last = last->GetPointer1();
            last->SetPointer1(n); n->SetPointer2(last);
        }
        this->count++;
        return 0;
    }

    void PrintTree() {
        if (!this->head) return;
        std::queue<Node<TypeName>*> q; q.push(this->head);
        while (!q.empty()) {
            Node<TypeName>* curr = q.front(); q.pop();
            std::cout << curr->GetData() << " -> children: ";
            Node<TypeName>* child = curr->GetPointer3();
            while (child) { std::cout << child->GetData() << " "; q.push(child); child = child->GetPointer1(); }
            std::cout << std::endl;
        }
    }
};