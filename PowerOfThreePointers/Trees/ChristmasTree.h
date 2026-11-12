////
////#pragma once
////#include "../Core/Node.h"
////#include <iostream>
////#include <stack>
////#include <list>
////
////template<class TypeName>
////class ChristmasTree {
////private:
////    std::stack<std::list<Node<TypeName>*>> level_stack;
////    Node<TypeName>* root_node;
////    int total_levels;
////
////    int FindParentLevel(Node<TypeName>* parent_node) {
////        std::stack<std::list<Node<TypeName>*>> temp;
////        int level_index = total_levels - 1;
////        int found = -1;
////
////        while (!level_stack.empty()) {
////            auto& top_list = level_stack.top();
////            for (auto n : top_list) {
////                if (n == parent_node) { found = level_index; break; }
////            }
////            temp.push(top_list);
////            level_stack.pop();
////            if (found != -1) break;
////            level_index--;
////        }
////        // restore
////        while (!temp.empty()) {
////            level_stack.push(temp.top());
////            temp.pop();
////        }
////        return found;
////    }
////
////public:
////    ChristmasTree() : root_node(nullptr), total_levels(0) {}
////
////    ~ChristmasTree() {
////        while (!level_stack.empty()) {
////            for (auto n : level_stack.top()) delete n;
////            level_stack.pop();
////        }
////    }
////
////    Node<TypeName>* AddRoot(TypeName input_data) {
////        while (!level_stack.empty()) {
////            for (auto n : level_stack.top()) delete n;
////            level_stack.pop();
////        }
////        root_node = new Node<TypeName>(input_data);
////        std::list<Node<TypeName>*> first;
////        first.push_back(root_node);
////        level_stack.push(first);
////        total_levels = 1;
////        return root_node;
////    }
////
////    Node<TypeName>* AddLeftChild(Node<TypeName>* parent_node, TypeName input_data) {
////        if (!parent_node) return nullptr;
////        if (parent_node->GetPointer3()) return parent_node->GetPointer3();
////
////        Node<TypeName>* child_node = new Node<TypeName>(input_data);
////        parent_node->SetPointer3(child_node);
////
////        int parent_level = FindParentLevel(parent_node);
////        int child_level = parent_level + 1;
////
////        if (child_level == total_levels) {
////            std::list<Node<TypeName>*> new_level;
////            new_level.push_back(child_node);
////            level_stack.push(new_level);
////            total_levels++;
////        }
////        else {
////            // Insert into middle level using only stacks
////            std::stack<std::list<Node<TypeName>*>> upper;
////            while ((int)level_stack.size() > child_level + 1) {
////                upper.push(level_stack.top());
////                level_stack.pop();
////            }
////            auto target = level_stack.top();
////            level_stack.pop();
////
////            if (!target.empty()) {
////                Node<TypeName>* prev = target.back();
////                prev->SetPointer1(child_node);
////                child_node->SetPointer2(prev);
////            }
////            target.push_back(child_node);
////            level_stack.push(target);
////
////            while (!upper.empty()) {
////                level_stack.push(upper.top());
////                upper.pop();
////            }
////        }
////        return child_node;
////    }
////
////    Node<TypeName>* AddRightChild(Node<TypeName>* parent_node, TypeName input_data) {
////        if (!parent_node) return nullptr;
////        Node<TypeName>* first_child = parent_node->GetPointer3();
////        if (first_child && first_child->GetPointer1()) return first_child->GetPointer1();
////
////        Node<TypeName>* child_node = new Node<TypeName>(input_data);
////        if (!first_child) {
////            parent_node->SetPointer3(child_node);
////        }
////        else {
////            first_child->SetPointer1(child_node);
////            child_node->SetPointer2(first_child);
////        }
////
////        int parent_level = FindParentLevel(parent_node);
////        int child_level = parent_level + 1;
////
////        if (child_level == total_levels) {
////            std::list<Node<TypeName>*> new_level;
////            new_level.push_back(child_node);
////            level_stack.push(new_level);
////            total_levels++;
////        }
////        else {
////            std::stack<std::list<Node<TypeName>*>> upper;
////            while ((int)level_stack.size() > child_level + 1) {
////                upper.push(level_stack.top());
////                level_stack.pop();
////            }
////            auto target = level_stack.top();
////            level_stack.pop();
////            // avoid double link if prev is first_child
////            if (!target.empty()) {
////                Node<TypeName>* prev = target.back();
////                if (prev != first_child) {
////                    prev->SetPointer1(child_node);
////                    child_node->SetPointer2(prev);
////                }
////            }
////            target.push_back(child_node);
////            level_stack.push(target);
////            while (!upper.empty()) {
////                level_stack.push(upper.top());
////                upper.pop();
////            }
////        }
////        return child_node;
////    }
////
////    int GetTotalLevels() { return total_levels; }
////
////    void PrintTree() {
////        // Print without vector - use temp stack to reverse
////        std::stack<std::list<Node<TypeName>*>> temp = level_stack;
////        std::stack<std::list<Node<TypeName>*>> rev;
////        while (!temp.empty()) { rev.push(temp.top()); temp.pop(); }
////
////        std::cout << "\n=== CHRISTMAS TREE STACK<LIST> NO VECTOR ===\n";
////        int i = 0;
////        while (!rev.empty()) {
////            std::cout << "level_" << i++ << " : ";
////            bool first = true;
////            for (auto n : rev.top()) {
////                if (!first) std::cout << " <-> ";
////                std::cout << "[" << n->GetData() << "]";
////                first = false;
////            }
////            std::cout << "\n";
////            rev.pop();
////        }
////        std::cout << "========================================\n";
////    }
////
////    std::list<Node<TypeName>*> GetLevel(int l) {
////        std::stack<std::list<Node<TypeName>*>> upper;
////        while ((int)level_stack.size() > l + 1) {
////            upper.push(level_stack.top());
////            level_stack.pop();
////        }
////        auto result = level_stack.top();
////        // restore
////        while (!upper.empty()) {
////            level_stack.push(upper.top());
////            upper.pop();
////        }
////        return result;
////    }
////};
//#pragma once
//#include "../Core/Node.h"
//#include "LevelInfo.h"
//#include <iostream>
//#include <stack>
//#include <list>
//
//template<class TypeName>
//class ChristmasTree {
//private:
//    std::stack<std::list<Node<TypeName>*>> level_stack;
//    Node<TypeName>* root_node;
//    int total_levels;
//
//public:
//    ChristmasTree() : root_node(nullptr), total_levels(0) {}
//    ~ChristmasTree() {
//        while (!level_stack.empty()) {
//            for (auto n : level_stack.top()) delete n;
//            level_stack.pop();
//        }
//    }
//
//    Node<TypeName>* AddRoot(TypeName input_data) {
//        while (!level_stack.empty()) {
//            for (auto n : level_stack.top()) delete n;
//            level_stack.pop();
//        }
//        root_node = new Node<TypeName>(input_data);
//        root_node->SetLevel(0);
//        std::list<Node<TypeName>*> first;
//        first.push_back(root_node);
//        level_stack.push(first);
//        total_levels = 1;
//        return root_node;
//    }
//    // For old test compatibility - get level list by index
//    std::list<Node<TypeName>*> GetLevel(int l) {
//        std::stack<std::list<Node<TypeName>*>> upper;
//        while ((int)level_stack.size() > l + 1) {
//            upper.push(level_stack.top());
//            level_stack.pop();
//        }
//        auto result = level_stack.top();
//        while (!upper.empty()) {
//            level_stack.push(upper.top());
//            upper.pop();
//        }
//        return result;
//    }
//
//
//    Node<TypeName>* AddLeftChild(Node<TypeName>* parent_node, TypeName input_data) {
//        if (!parent_node) return nullptr;
//        if (parent_node->GetPointer3()) return parent_node->GetPointer3();
//
//        Node<TypeName>* child_node = new Node<TypeName>(input_data);
//        child_node->SetLevel(parent_node->GetLevel() + 1);
//        parent_node->SetPointer3(child_node);
//
//        int child_level = child_node->GetLevel();
//        if (child_level == total_levels) {
//            std::list<Node<TypeName>*> new_level;
//            new_level.push_back(child_node);
//            level_stack.push(new_level);
//            total_levels++;
//        }
//        else {
//            std::stack<std::list<Node<TypeName>*>> upper;
//            while ((int)level_stack.size() > child_level + 1) {
//                upper.push(level_stack.top()); level_stack.pop();
//            }
//            auto target = level_stack.top(); level_stack.pop();
//            if (!target.empty()) {
//                Node<TypeName>* prev = target.back();
//                prev->SetPointer1(child_node);
//                child_node->SetPointer2(prev);
//            }
//            target.push_back(child_node);
//            level_stack.push(target);
//            while (!upper.empty()) { level_stack.push(upper.top()); upper.pop(); }
//        }
//        return child_node;
//    }
//
//    Node<TypeName>* AddRightChild(Node<TypeName>* parent_node, TypeName input_data) {
//        if (!parent_node) return nullptr;
//        Node<TypeName>* first_child = parent_node->GetPointer3();
//        if (first_child && first_child->GetPointer1()) return first_child->GetPointer1();
//
//        Node<TypeName>* child_node = new Node<TypeName>(input_data);
//        child_node->SetLevel(parent_node->GetLevel() + 1);
//
//        if (!first_child) {
//            parent_node->SetPointer3(child_node);
//        }
//        else {
//            first_child->SetPointer1(child_node);
//            child_node->SetPointer2(first_child);
//        }
//
//        int child_level = child_node->GetLevel();
//        if (child_level == total_levels) {
//            std::list<Node<TypeName>*> new_level;
//            new_level.push_back(child_node);
//            level_stack.push(new_level);
//            total_levels++;
//        }
//        else {
//            std::stack<std::list<Node<TypeName>*>> upper;
//            while ((int)level_stack.size() > child_level + 1) {
//                upper.push(level_stack.top()); level_stack.pop();
//            }
//            auto target = level_stack.top(); level_stack.pop();
//            if (!target.empty()) {
//                Node<TypeName>* prev = target.back();
//                if (prev != first_child) {
//                    prev->SetPointer1(child_node);
//                    child_node->SetPointer2(prev);
//                }
//            }
//            target.push_back(child_node);
//            level_stack.push(target);
//            while (!upper.empty()) { level_stack.push(upper.top()); upper.pop(); }
//        }
//        return child_node;
//    }
//
//    int GetTotalLevels() { return total_levels; }
//
//    void PrintTree() {
//        std::stack<std::list<Node<TypeName>*>> temp = level_stack;
//        std::stack<std::list<Node<TypeName>*>> rev;
//        while (!temp.empty()) { rev.push(temp.top()); temp.pop(); }
//        std::cout << "\n=== CHRISTMAS TREE V2 FAST (stack<list>) ===\n";
//        int i = 0;
//        while (!rev.empty()) {
//            LevelInfo info(i, rev.top().size());
//            std::cout << "level_" << info.level_number << " (" << info.nodes_count << " nodes): ";
//            bool first = true;
//            for (auto n : rev.top()) {
//                if (!first) std::cout << " <-> ";
//                std::cout << "[" << n->GetData() << "]";
//                first = false;
//            }
//            std::cout << "\n";
//            rev.pop(); i++;
//        }
//        std::cout << "===========================================\n";
//    }
//};
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
    ~ChristmasTree() {
        while (!level_stack.empty()) {
            for (auto n : level_stack.top()) delete n;
            level_stack.pop();
        }
    }

    Node<TypeName>* AddRoot(TypeName input_data) {
        while (!level_stack.empty()) {
            for (auto n : level_stack.top()) delete n;
            level_stack.pop();
        }
        root_node = new Node<TypeName>(input_data);
        root_node->SetLevel(0);
        root_node->SetPointer1(nullptr);
        root_node->SetPointer2(nullptr);
        root_node->SetPointer3(nullptr);
        std::list<Node<TypeName>*> first;
        first.push_back(root_node);
        level_stack.push(first);
        total_levels = 1;
        return root_node;
    }

    // For old test compatibility
    std::list<Node<TypeName>*> GetLevel(int l) {
        std::stack<std::list<Node<TypeName>*>> upper;
        while ((int)level_stack.size() > l + 1) {
            upper.push(level_stack.top());
            level_stack.pop();
        }
        auto result = level_stack.top();
        while (!upper.empty()) {
            level_stack.push(upper.top());
            upper.pop();
        }
        return result;
    }

    Node<TypeName>* AddLeftChild(Node<TypeName>* parent_node, TypeName input_data) {
        if (!parent_node) return nullptr;
        if (parent_node->GetPointer3()) return parent_node->GetPointer3();

        Node<TypeName>* child_node = new Node<TypeName>(input_data);
        child_node->SetLevel(parent_node->GetLevel() + 1);
        child_node->SetPointer1(nullptr);
        child_node->SetPointer2(nullptr);
        child_node->SetPointer3(nullptr);
        parent_node->SetPointer3(child_node); // P3 = first child

        int child_level = child_node->GetLevel();
        if (child_level == total_levels) {
            std::list<Node<TypeName>*> new_level;
            new_level.push_back(child_node);
            level_stack.push(new_level);
            total_levels++;
        }
        else {
            std::stack<std::list<Node<TypeName>*>> upper;
            while ((int)level_stack.size() > child_level + 1) {
                upper.push(level_stack.top()); level_stack.pop();
            }
            auto target = level_stack.top(); level_stack.pop();
            if (!target.empty()) {
                Node<TypeName>* prev = target.back();
                prev->SetPointer1(child_node); // P1 = next
                child_node->SetPointer2(prev); // P2 = prev
            }
            target.push_back(child_node);
            level_stack.push(target);
            while (!upper.empty()) { level_stack.push(upper.top()); upper.pop(); }
        }
        return child_node;
    }

    Node<TypeName>* AddRightChild(Node<TypeName>* parent_node, TypeName input_data) {
        if (!parent_node) return nullptr;
        Node<TypeName>* first_child = parent_node->GetPointer3();
        if (first_child && first_child->GetPointer1()) return first_child->GetPointer1();

        Node<TypeName>* child_node = new Node<TypeName>(input_data);
        child_node->SetLevel(parent_node->GetLevel() + 1);
        child_node->SetPointer1(nullptr);
        child_node->SetPointer2(nullptr);
        child_node->SetPointer3(nullptr);

        if (!first_child) {
            parent_node->SetPointer3(child_node);
        }
        else {
            first_child->SetPointer1(child_node); // P1 = next
            child_node->SetPointer2(first_child); // P2 = prev
        }

        int child_level = child_node->GetLevel();
        if (child_level == total_levels) {
            std::list<Node<TypeName>*> new_level;
            new_level.push_back(child_node);
            level_stack.push(new_level);
            total_levels++;
        }
        else {
            std::stack<std::list<Node<TypeName>*>> upper;
            while ((int)level_stack.size() > child_level + 1) {
                upper.push(level_stack.top()); level_stack.pop();
            }
            auto target = level_stack.top(); level_stack.pop();
            if (!target.empty()) {
                Node<TypeName>* prev = target.back();
                if (prev != first_child) {
                    prev->SetPointer1(child_node);
                    child_node->SetPointer2(prev);
                }
            }
            target.push_back(child_node);
            level_stack.push(target);
            while (!upper.empty()) { level_stack.push(upper.top()); upper.pop(); }
        }
        return child_node;
    }

    int GetTotalLevels() { return total_levels; }
    Node<TypeName>* GetRoot() { return root_node; }

    void PrintTree() {
        std::stack<std::list<Node<TypeName>*>> temp = level_stack;
        std::stack<std::list<Node<TypeName>*>> rev;
        while (!temp.empty()) { rev.push(temp.top()); temp.pop(); }
        std::cout << "\n=== CHRISTMAS TREE V2 FAST (stack<list>) ===\n";
        int i = 0;
        while (!rev.empty()) {
            LevelInfo info(i, rev.top().size());
            std::cout << "level_" << info.level_number << " (" << info.nodes_count << " nodes): ";
            bool first = true;
            for (auto n : rev.top()) {
                if (!first) std::cout << " <-> ";
                std::cout << "[" << n->GetData() << "]";
                first = false;
            }
            std::cout << "\n";
            rev.pop(); i++;
        }
        std::cout << "===========================================\n";
    }
};