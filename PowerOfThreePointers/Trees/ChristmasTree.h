#pragma once
#include "../Core/Node.h"
#include "LevelInfo.h"
#include <iostream>
#include <stack>
#include <list>

template<class TypeName>
class ChristmasTree {
private:
    std::stack<std::list<Node<TypeName>*>> level_stack;
    Node<TypeName>* root_node;
    int total_levels;
public:
    ChristmasTree() : root_node(nullptr), total_levels(0) {}

    Node<TypeName>* AddRoot(TypeName data) {
        while (!level_stack.empty()) { level_stack.pop(); }
        root_node = new Node<TypeName>(data);
        root_node->SetLevel(0);
        root_node->SetPointer1(nullptr);
        root_node->SetPointer2(nullptr);
        root_node->SetPointer3(nullptr);
        root_node->SetParent(nullptr);
        std::list<Node<TypeName>*> first; first.push_back(root_node);
        level_stack.push(first);
        total_levels = 1;
        return root_node;
    }

    Node<TypeName>* AddLeftChild(Node<TypeName>* parent_node, TypeName data) {
        if (!parent_node || parent_node->GetPointer3()) return parent_node ? parent_node->GetPointer3() : nullptr;
        Node<TypeName>* child = new Node<TypeName>(data);
        child->SetLevel(parent_node->GetLevel()+1);
        child->SetParent(parent_node);
        child->SetPointer1(nullptr);
        child->SetPointer2(nullptr);
        child->SetPointer3(nullptr);
        parent_node->SetPointer3(child);
        if (child->GetLevel() == total_levels) {
            std::list<Node<TypeName>*> new_level; new_level.push_back(child);
            level_stack.push(new_level); total_levels++;
        } else {
            std::stack<std::list<Node<TypeName>*>> upper;
            while ((int)level_stack.size() > child->GetLevel()+1) { upper.push(level_stack.top()); level_stack.pop(); }
            auto target = level_stack.top(); level_stack.pop();
            if (!target.empty()) {
                Node<TypeName>* prev = target.back();
                prev->SetPointer1(child);
                child->SetPointer2(prev);
            }
            target.push_back(child);
            level_stack.push(target);
            while (!upper.empty()) { level_stack.push(upper.top()); upper.pop(); }
        }
        return child;
    }

    Node<TypeName>* AddRightChild(Node<TypeName>* parent_node, TypeName data) {
        if (!parent_node) return nullptr;
        Node<TypeName>* first = parent_node->GetPointer3();
        if (!first) return AddLeftChild(parent_node, data);
        if (first->GetPointer1() && first->GetPointer1()->GetParent() == parent_node) return first->GetPointer1();
        Node<TypeName>* child = new Node<TypeName>(data);
        child->SetLevel(parent_node->GetLevel()+1);
        child->SetParent(parent_node);
        child->SetPointer1(nullptr);
        child->SetPointer3(nullptr);
        child->SetPointer2(first);
        first->SetPointer1(child);
        std::stack<std::list<Node<TypeName>*>> upper;
        while ((int)level_stack.size() > child->GetLevel()+1) { upper.push(level_stack.top()); level_stack.pop(); }
        auto target = level_stack.top(); level_stack.pop();
        target.push_back(child);
        level_stack.push(target);
        while (!upper.empty()) { level_stack.push(upper.top()); upper.pop(); }
        return child;
    }

    void PrintFancyTree() {
        std::stack<std::list<Node<TypeName>*>> temp = level_stack, rev;
        while (!temp.empty()) { rev.push(temp.top()); temp.pop(); }
        std::cout << "\n=== CHRISTMAS TREE V3 FINAL ===\n";
        int i=0;
        while (!rev.empty()) {
            std::cout << "level_" << i << ": ";
            bool first=true;
            for (auto n : rev.top()) {
                if (!first) std::cout << " <-> ";
                std::cout << "[" << n->GetData() << "]";
                first=false;
            }
            std::cout << "\n"; rev.pop(); i++;
        }
        std::cout << "================================\n";
    }

    void PrintPathToRoot(Node<TypeName>* node) {
        std::cout << "Path: ";
        Node<TypeName>* cur=node;
        while (cur) { std::cout << "[" << cur->GetData() << "]"; cur=cur->GetParent(); if (cur) std::cout << " -> "; }
        std::cout << " -> ROOT!\n";
    }

    Node<TypeName>* GetRoot(){return root_node;}
    int GetTotalLevels(){return total_levels;}
};
