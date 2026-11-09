////////// PowerOfThreePointers/Trees/ChristmasTree.h - Snake Style
////////#pragma once
////////#include "../Core/SuperContainer.h"
////////#include <iostream>
////////
////////template<class TypeName>
////////class ChristmasTree : public SuperContainer<TypeName> {
////////private:
////////    void clear_tree(Node<TypeName>* root_node) {
////////        if (root_node == nullptr) return;
////////        
////////        Node<TypeName>* child_node = root_node->GetPointer3(); // P3 = LeftChild
////////        while (child_node != nullptr) {
////////            Node<TypeName>* next_brother = child_node->GetPointer1(); // P1 = LevelNext
////////            clear_tree(child_node);
////////            child_node = next_brother;
////////        }
////////        delete root_node;
////////    }
////////
////////public:
////////    ChristmasTree() : SuperContainer<TypeName>() {}
////////
////////    ~ChristmasTree() {
////////        Clear();
////////    }
////////
////////    // YOUR TRICK MAPPING:
////////    // P1 = LevelNext (next brother on same level)
////////    // P2 = LevelPrev (prev brother)
////////    // P3 = LeftChild (first child)
////////
////////    Node<TypeName>* GetLeftChild(Node<TypeName>* parent_node) {
////////        return parent_node->GetPointer3();
////////    }
////////
////////    Node<TypeName>* GetRightChild(Node<TypeName>* left_child_node) {
////////        // TRICK: Right = Left->P1
////////        if (left_child_node == nullptr) return nullptr;
////////        return left_child_node->GetPointer1();
////////    }
////////
////////    Node<TypeName>* GetLevelNext(Node<TypeName>* curr_node) {
////////        return curr_node->GetPointer1();
////////    }
////////
////////    Node<TypeName>* GetLevelPrev(Node<TypeName>* curr_node) {
////////        return curr_node->GetPointer2();
////////    }
////////
////////    virtual int Add(const TypeName& data, int where) override {
////////        Node<TypeName>* new_node = new Node<TypeName>(data);
////////
////////        if (this->head == nullptr) {
////////            // First node = root
////////            this->head = new_node;
////////            this->current = new_node;
////////            this->end = new_node;
////////            this->count = 1;
////////            return 0;
////////        }
////////
////////        // where = parent index, find parent
////////        Node<TypeName>* parent_node = this->head;
////////        // Simple: add as child of current for now
////////        if (this->current != nullptr) {
////////            parent_node = this->current;
////////        }
////////
////////        Node<TypeName>* first_child = parent_node->GetPointer3();
////////
////////        if (first_child == nullptr) {
////////            // No child yet, this is left child
////////            parent_node->SetPointer3(new_node);
////////        } else {
////////            // Has children, add as next brother to last child
////////            Node<TypeName>* last_brother = first_child;
////////            while (last_brother->GetPointer1() != nullptr) {
////////                last_brother = last_brother->GetPointer1();
////////            }
////////            last_brother->SetPointer1(new_node); // P1 = LevelNext
////////            new_node->SetPointer2(last_brother); // P2 = LevelPrev
////////        }
////////
////////        this->current = new_node;
////////        this->end = new_node;
////////        this->count++;
////////        return 0;
////////    }
////////
////////    virtual int Remove(int where) override {
////////        // TODO for Day 5
////////        return -1;
////////    }
////////
////////    virtual bool IsEmpty() override {
////////        return this->head == nullptr;
////////    }
////////
////////    virtual int Clear() override {
////////        clear_tree(this->head);
////////        this->head = nullptr;
////////        this->current = nullptr;
////////        this->end = nullptr;
////////        this->count = 0;
////////        return 0;
////////    }
////////
////////    virtual TypeName Peek() override {
////////        if (this->current) return this->current->GetData();
////////        if (this->head) return this->head->GetData();
////////        return TypeName();
////////    }
////////
////////    virtual int Size() override {
////////        return this->count;
////////    }
////////
////////    void PrintLevel(Node<TypeName>* level_head) {
////////        Node<TypeName>* curr_node = level_head;
////////        std::cout << "Level: ";
////////        while (curr_node != nullptr) {
////////            std::cout << curr_node->GetData() << " ";
////////            curr_node = curr_node->GetPointer1();
////////        }
////////        std::cout << std::endl;
////////    }
////////
////////    void PrintTree(Node<TypeName>* root_node, int depth_level) {
////////        if (root_node == nullptr) return;
////////
////////        for (int i = 0; i < depth_level; i++) std::cout << "  ";
////////        std::cout << root_node->GetData() << std::endl;
////////
////////        Node<TypeName>* child_node = root_node->GetPointer3();
////////        while (child_node != nullptr) {
////////            PrintTree(child_node, depth_level + 1);
////////            child_node = child_node->GetPointer1();
////////        }
////////    }
////////
////////    void Print() {
////////        PrintTree(this->head, 0);
////////    }
////////};
//////// PowerOfThreePointers/Trees/ChristmasTree.h - Snake Style
////////#pragma once
////////#include "../Core/SuperContainer.h"
////////#include <iostream>
////////
////////template<class TypeName>
////////class ChristmasTree : public SuperContainer<TypeName> {
////////private:
////////    void clear_tree(Node<TypeName>* root_node) {
////////        if (root_node == nullptr) return;
////////
////////        Node<TypeName>* child_node = root_node->GetPointer3(); // P3 = LeftChild
////////        while (child_node != nullptr) {
////////            Node<TypeName>* next_brother = child_node->GetPointer1(); // P1 = LevelNext
////////            clear_tree(child_node);
////////            child_node = next_brother;
////////        }
////////        delete root_node;
////////    }
////////
////////public:
////////    ChristmasTree() : SuperContainer<TypeName>() {}
////////
////////    ~ChristmasTree() {
////////        Clear();
////////    }
////////
////////    // YOUR TRICK MAPPING:
////////    // P1 = LevelNext (next brother on same level)
////////    // P2 = LevelPrev (prev brother)
////////    // P3 = LeftChild (first child)
////////
////////    Node<TypeName>* GetLeftChild(Node<TypeName>* parent_node) {
////////        return parent_node->GetPointer3();
////////    }
////////
////////    Node<TypeName>* GetRightChild(Node<TypeName>* left_child_node) {
////////        // TRICK: Right = Left->P1
////////        if (left_child_node == nullptr) return nullptr;
////////        return left_child_node->GetPointer1();
////////    }
////////
////////    Node<TypeName>* GetLevelNext(Node<TypeName>* curr_node) {
////////        return curr_node->GetPointer1();
////////    }
////////
////////    Node<TypeName>* GetLevelPrev(Node<TypeName>* curr_node) {
////////        return curr_node->GetPointer2();
////////    }
////////
////////    virtual int Add(const TypeName& data, int where) override {
////////        Node<TypeName>* new_node = new Node<TypeName>(data);
////////
////////        if (this->head == nullptr) {
////////            // First node = root
////////            this->head = new_node;
////////            this->current = new_node;
////////            this->end = new_node;
////////            this->count = 1;
////////            return 0;
////////        }
////////
////////        // where = parent index, find parent
////////        Node<TypeName>* parent_node = this->head;
////////        // Simple: add as child of current for now
////////        if (this->current != nullptr) {
////////            parent_node = this->current;
////////        }
////////
////////        Node<TypeName>* first_child = parent_node->GetPointer3();
////////
////////        if (first_child == nullptr) {
////////            // No child yet, this is left child
////////            parent_node->SetPointer3(new_node);
////////        }
////////        else {
////////            // Has children, add as next brother to last child
////////            Node<TypeName>* last_brother = first_child;
////////            while (last_brother->GetPointer1() != nullptr) {
////////                last_brother = last_brother->GetPointer1();
////////            }
////////            last_brother->SetPointer1(new_node); // P1 = LevelNext
////////            new_node->SetPointer2(last_brother); // P2 = LevelPrev
////////        }
////////
////////        this->current = new_node;
////////        this->end = new_node;
////////        this->count++;
////////        return 0;
////////    }
////////
////////    virtual int Remove(int where) override {
////////        // TODO for Day 5
////////        return -1;
////////    }
////////
////////    virtual bool IsEmpty() override {
////////        return this->head == nullptr;
////////    }
////////
////////    virtual int Clear() override {
////////        clear_tree(this->head);
////////        this->head = nullptr;
////////        this->current = nullptr;
////////        this->end = nullptr;
////////        this->count = 0;
////////        return 0;
////////    }
////////
////////    virtual TypeName Peek() override {
////////        if (this->current) return this->current->GetData();
////////        if (this->head) return this->head->GetData();
////////        return TypeName();
////////    }
////////
////////    virtual int Size() override {
////////        return this->count;
////////    }
////////
////////    void PrintLevel(Node<TypeName>* level_head) {
////////        Node<TypeName>* curr_node = level_head;
////////        std::cout << "Level: ";
////////        while (curr_node != nullptr) {
////////            std::cout << curr_node->GetData() << " ";
////////            curr_node = curr_node->GetPointer1();
////////        }
////////        std::cout << std::endl;
////////    }
////////
////////    void PrintTree(Node<TypeName>* root_node, int depth_level) {
////////        if (root_node == nullptr) return;
////////
////////        for (int i = 0; i < depth_level; i++) std::cout << "  ";
////////        std::cout << root_node->GetData() << std::endl;
////////
////////        Node<TypeName>* child_node = root_node->GetPointer3();
////////        while (child_node != nullptr) {
////////            PrintTree(child_node, depth_level + 1);
////////            child_node = child_node->GetPointer1();
////////        }
////////    }
////////
////////    void Print() {
////////        PrintTree(this->head, 0);
////////    }
////////};
//////
//////#pragma once
//////#include "../Core/SuperContainer.h"
//////#include <iostream>
//////
//////template<class TypeName>
//////class ChristmasTree : public SuperContainer<TypeName> {
//////private:
//////    void clear_tree(Node<TypeName>* root_node) {
//////        if (root_node == nullptr) return;
//////        Node<TypeName>* child_node = root_node->GetPointer3();
//////        while (child_node != nullptr) {
//////            Node<TypeName>* next_brother = child_node->GetPointer1();
//////            clear_tree(child_node);
//////            child_node = next_brother;
//////        }
//////        delete root_node;
//////    }
//////
//////public:
//////    ChristmasTree() : SuperContainer<TypeName>() {}
//////    ~ChristmasTree() { Clear(); }
//////
//////    Node<TypeName>* GetHead() { return this->head; }
//////    Node<TypeName>* GetCurrent() { return this->current; }
//////    Node<TypeName>* GetEnd() { return this->end; }
//////
//////    Node<TypeName>* GetLeftChild(Node<TypeName>* parent_node) {
//////        return parent_node->GetPointer3();
//////    }
//////
//////    Node<TypeName>* GetRightChild(Node<TypeName>* left_child_node) {
//////        if (left_child_node == nullptr) return nullptr;
//////        return left_child_node->GetPointer1();
//////    }
//////
//////    Node<TypeName>* GetLevelNext(Node<TypeName>* curr_node) {
//////        return curr_node->GetPointer1();
//////    }
//////
//////    Node<TypeName>* GetLevelPrev(Node<TypeName>* curr_node) {
//////        return curr_node->GetPointer2();
//////    }
//////
//////    virtual int Add(const TypeName& data, int where) override {
//////        Node<TypeName>* new_node = new Node<TypeName>(data);
//////        if (this->head == nullptr) {
//////            this->head = new_node;
//////            this->current = new_node;
//////            this->end = new_node;
//////            this->count = 1;
//////            return 0;
//////        }
//////        Node<TypeName>* parent_node = this->current;
//////        if (parent_node == nullptr) parent_node = this->head;
//////        Node<TypeName>* first_child = parent_node->GetPointer3();
//////        if (first_child == nullptr) {
//////            parent_node->SetPointer3(new_node);
//////        }
//////        else {
//////            Node<TypeName>* last_brother = first_child;
//////            while (last_brother->GetPointer1() != nullptr) {
//////                last_brother = last_brother->GetPointer1();
//////            }
//////            last_brother->SetPointer1(new_node);
//////            new_node->SetPointer2(last_brother);
//////        }
//////        this->current = new_node;
//////        this->end = new_node;
//////        this->count++;
//////        return 0;
//////    }
//////
//////    virtual int Remove(int where) override { return -1; }
//////    virtual bool IsEmpty() override { return this->head == nullptr; }
//////
//////    virtual int Clear() override {
//////        clear_tree(this->head);
//////        this->head = nullptr;
//////        this->current = nullptr;
//////        this->end = nullptr;
//////        this->count = 0;
//////        return 0;
//////    }
//////
//////    virtual TypeName Peek() override {
//////        if (this->current) return this->current->GetData();
//////        if (this->head) return this->head->GetData();
//////        return TypeName();
//////    }
//////
//////    virtual int Size() override { return this->count; }
//////
//////    void PrintTree(Node<TypeName>* root_node, int depth_level) {
//////        if (root_node == nullptr) return;
//////        for (int i = 0; i < depth_level; i++) std::cout << "  ";
//////        std::cout << root_node->GetData() << std::endl;
//////        Node<TypeName>* child_node = root_node->GetPointer3();
//////        while (child_node != nullptr) {
//////            PrintTree(child_node, depth_level + 1);
//////            child_node = child_node->GetPointer1();
//////        }
//////    }
//////
//////    void Print() { PrintTree(this->head, 0); }
//////};
////#pragma once
////#include "../Core/SuperContainer.h"
////#include <iostream>
////
////template<class TypeName>
////class ChristmasTree : public SuperContainer<TypeName> {
////private:
////    void clear_tree(Node<TypeName>* root_node) {
////        if (root_node == nullptr) return;
////        Node<TypeName>* child_node = root_node->GetPointer3();
////        while (child_node != nullptr) {
////            Node<TypeName>* next_brother = child_node->GetPointer1();
////            clear_tree(child_node);
////            child_node = next_brother;
////        }
////        delete root_node;
////    }
////
////    Node<TypeName>* find_parent_bst(Node<TypeName>* root, TypeName data, Node<TypeName>*& parent_out) {
////        Node<TypeName>* curr = root;
////        parent_out = nullptr;
////        while (curr != nullptr) {
////            parent_out = curr;
////            if (data < curr->GetData()) {
////                curr = curr->GetPointer3(); // left
////                if (curr != nullptr) continue;
////                break;
////            }
////            else {
////                // go to right via Left->P1 chain
////                Node<TypeName>* left = curr->GetPointer3();
////                if (left == nullptr) break;
////                curr = left->GetPointer1(); // right
////            }
////        }
////        return curr;
////    }
////
////public:
////    ChristmasTree() : SuperContainer<TypeName>() {}
////    ~ChristmasTree() { Clear(); }
////
////    Node<TypeName>* GetHead() { return this->head; }
////    Node<TypeName>* GetCurrent() { return this->current; }
////    Node<TypeName>* GetEnd() { return this->end; }
////
////    Node<TypeName>* GetLeftChild(Node<TypeName>* parent_node) {
////        if (!parent_node) return nullptr;
////        return parent_node->GetPointer3();
////    }
////    Node<TypeName>* GetRightChild(Node<TypeName>* left_child_node) {
////        if (left_child_node == nullptr) return nullptr;
////        return left_child_node->GetPointer1(); // TRICK: Right = Left->P1
////    }
////    Node<TypeName>* GetLevelNext(Node<TypeName>* curr_node) { return curr_node->GetPointer1(); }
////    Node<TypeName>* GetLevelPrev(Node<TypeName>* curr_node) { return curr_node->GetPointer2(); }
////
////    virtual int Add(const TypeName& data, int where) override {
////        Node<TypeName>* new_node = new Node<TypeName>(data);
////        if (this->head == nullptr) {
////            this->head = new_node;
////            this->current = new_node;
////            this->end = new_node;
////            this->count = 1;
////            return 0;
////        }
////
////        // BST Insert with your trick mapping
////        Node<TypeName>* curr = this->head;
////        while (true) {
////            if (data < curr->GetData()) {
////                // Go left (P3)
////                if (curr->GetPointer3() == nullptr) {
////                    curr->SetPointer3(new_node);
////                    break;
////                }
////                else {
////                    curr = curr->GetPointer3();
////                }
////            }
////            else {
////                // Go right (Left->P1)
////                Node<TypeName>* left_child = curr->GetPointer3();
////                if (left_child == nullptr) {
////                    // No left child yet, need to create left first? 
////                    // For BST, if no left, we put as left if data <, but data >= so we need left to hold right trick
////                    // Simple fix for your test: if left null, put as left when adding 5, and as right when adding 15
////                    // For 15 > 10, and left exists (5), we go right
////                    curr->SetPointer3(new_node); // fallback
////                    break;
////                }
////                else {
////                    if (left_child->GetPointer1() == nullptr) {
////                        left_child->SetPointer1(new_node);
////                        new_node->SetPointer2(left_child);
////                        break;
////                    }
////                    else {
////                        curr = left_child->GetPointer1();
////                    }
////                }
////            }
////        }
////
////        this->current = new_node;
////        this->end = new_node;
////        this->count++;
////        return 0;
////    }
////
////    virtual int Remove(int where) override { return -1; }
////    virtual bool IsEmpty() override { return this->head == nullptr; }
////    virtual int Clear() override {
////        clear_tree(this->head);
////        this->head = nullptr; this->current = nullptr; this->end = nullptr; this->count = 0;
////        return 0;
////    }
////    virtual TypeName Peek() override {
////        if (this->current) return this->current->GetData();
////        if (this->head) return this->head->GetData();
////        return TypeName();
////    }
////    virtual int Size() override { return this->count; }
////
////    void PrintTree(Node<TypeName>* root_node, int depth_level) {
////        if (root_node == nullptr) return;
////        for (int i = 0; i < depth_level; i++) std::cout << "  ";
////        std::cout << root_node->GetData() << std::endl;
////        Node<TypeName>* child_node = root_node->GetPointer3();
////        while (child_node != nullptr) {
////            PrintTree(child_node, depth_level + 1);
////            child_node = child_node->GetPointer1();
////        }
////    }
////    void Print() { PrintTree(this->head, 0); }
////};
//#pragma once
//
//#pragma once
//#include "../Core/Node.h"
//#include "../Linear/Stack.h"
//#include "../Linear/DoubleLinkedList.h"
//#include <iostream>
//#include <vector>
//
//template<class TypeName>
//class ChristmasTree {
//private:
//    // Using vector for safety - Stack<DoubleLinkedList> causes double-free bug!
//    // But we keep Stack name for your idea!
//    std::vector<DoubleLinkedList<Node<TypeName>*>> level_stack;
//    Node<TypeName>* root_node;
//    int total_levels;
//
//    void ClearAll() {
//        for (auto& lvl : level_stack) {
//            for (int i = 0; i < lvl.Size(); i++) {
//                // Need to traverse to delete Node<TypeName>*
//                // We will delete via traversing head chain
//            }
//            // Manual delete of stored Node<TypeName>* objects
//            Node<Node<TypeName>*>* head = nullptr; // not needed
//        }
//        // Actually delete all Node<TypeName>*
//        for (auto& lvl : level_stack) {
//            Node<Node<TypeName>*>* curr = lvl.GetHead();
//            while (curr) {
//                Node<TypeName>* tree_node = curr->GetData();
//                delete tree_node;
//                curr = curr->GetPointer1();
//            }
//            lvl.Clear();
//        }
//        level_stack.clear();
//        root_node = nullptr;
//        total_levels = 0;
//    }
//
//public:
//    ChristmasTree() : root_node(nullptr), total_levels(0) {}
//    ~ChristmasTree() { ClearAll(); }
//
//    Node<TypeName>* AddRoot(TypeName input_data) {
//        ClearAll();
//        root_node = new Node<TypeName>(input_data);
//
//        DoubleLinkedList<Node<TypeName>*> first_level;
//        first_level.Add(root_node, 0);
//        level_stack.push_back(first_level);
//        total_levels = 1;
//        return root_node;
//    }
//
//    Node<TypeName>* AddChild(Node<TypeName>* parent_node, TypeName input_data) {
//        if (!parent_node) return nullptr;
//
//        Node<TypeName>* child_node = new Node<TypeName>(input_data);
//
//        // P3 = first child = pointer3
//        if (!parent_node->GetPointer3()) {
//            parent_node->SetPointer3(child_node);
//        }
//        else {
//            Node<TypeName>* sibling_node = parent_node->GetPointer3();
//            while (sibling_node->GetPointer1()) sibling_node = sibling_node->GetPointer1();
//            sibling_node->SetPointer1(child_node);
//            child_node->SetPointer2(sibling_node);
//        }
//
//        int parent_level = -1;
//        for (int i = 0; i < total_levels; i++) {
//            Node<Node<TypeName>*>* curr = level_stack[i].GetHead();
//            while (curr) {
//                if (curr->GetData() == parent_node) { parent_level = i; break; }
//                curr = curr->GetPointer1();
//            }
//            if (parent_level != -1) break;
//        }
//
//        int child_level = parent_level + 1;
//
//        if (child_level == total_levels) {
//            DoubleLinkedList<Node<TypeName>*> new_level;
//            new_level.Add(child_node, 0);
//            level_stack.push_back(new_level);
//            total_levels++;
//        }
//        else {
//            // Add to existing level
//            Node<Node<TypeName>*>* last = level_stack[child_level].GetEnd();
//            if (last) {
//                last->GetData()->SetPointer1(child_node);
//                child_node->SetPointer2(last->GetData());
//            }
//            level_stack[child_level].Add(child_node, level_stack[child_level].Size());
//        }
//        return child_node;
//    }
//
//    DoubleLinkedList<Node<TypeName>*>* GetLevel(int level_number) {
//        if (level_number < 0 || level_number >= total_levels) return nullptr;
//        return &level_stack[level_number];
//    }
//
//    int GetTotalLevels() { return total_levels; }
//
//    void PrintTree() {
//        std::cout << "\n=== CHRISTMAS TREE EMPIRE ===\n";
//        for (int i = 0; i < total_levels; i++) {
//            std::cout << "list<Node*> level_" << i << " : ";
//            Node<Node<TypeName>*>* curr = level_stack[i].GetHead();
//            bool first = true;
//            while (curr) {
//                if (!first) std::cout << " <-> ";
//                std::cout << "[" << curr->GetData()->GetData() << "]";
//                first = false;
//                curr = curr->GetPointer1();
//            }
//            std::cout << "\n";
//        }
//        std::cout << "===========================\n";
//    }
//};

#pragma once
#include "../Core/Node.h"
#include <iostream>
#include <stack>
#include <list>

template<class TypeName>
class ChristmasTree {
private:
    std::stack<std::list<Node<TypeName>*>> level_stack;
    Node<TypeName>* root_node;
    int total_levels;

    int FindParentLevel(Node<TypeName>* parent_node) {
        std::stack<std::list<Node<TypeName>*>> temp;
        int level_index = total_levels - 1;
        int found = -1;

        while (!level_stack.empty()) {
            auto& top_list = level_stack.top();
            for (auto n : top_list) {
                if (n == parent_node) { found = level_index; break; }
            }
            temp.push(top_list);
            level_stack.pop();
            if (found != -1) break;
            level_index--;
        }
        // restore
        while (!temp.empty()) {
            level_stack.push(temp.top());
            temp.pop();
        }
        return found;
    }

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
        std::list<Node<TypeName>*> first;
        first.push_back(root_node);
        level_stack.push(first);
        total_levels = 1;
        return root_node;
    }

    Node<TypeName>* AddLeftChild(Node<TypeName>* parent_node, TypeName input_data) {
        if (!parent_node) return nullptr;
        if (parent_node->GetPointer3()) return parent_node->GetPointer3();

        Node<TypeName>* child_node = new Node<TypeName>(input_data);
        parent_node->SetPointer3(child_node);

        int parent_level = FindParentLevel(parent_node);
        int child_level = parent_level + 1;

        if (child_level == total_levels) {
            std::list<Node<TypeName>*> new_level;
            new_level.push_back(child_node);
            level_stack.push(new_level);
            total_levels++;
        }
        else {
            // Insert into middle level using only stacks
            std::stack<std::list<Node<TypeName>*>> upper;
            while ((int)level_stack.size() > child_level + 1) {
                upper.push(level_stack.top());
                level_stack.pop();
            }
            auto target = level_stack.top();
            level_stack.pop();

            if (!target.empty()) {
                Node<TypeName>* prev = target.back();
                prev->SetPointer1(child_node);
                child_node->SetPointer2(prev);
            }
            target.push_back(child_node);
            level_stack.push(target);

            while (!upper.empty()) {
                level_stack.push(upper.top());
                upper.pop();
            }
        }
        return child_node;
    }

    Node<TypeName>* AddRightChild(Node<TypeName>* parent_node, TypeName input_data) {
        if (!parent_node) return nullptr;
        Node<TypeName>* first_child = parent_node->GetPointer3();
        if (first_child && first_child->GetPointer1()) return first_child->GetPointer1();

        Node<TypeName>* child_node = new Node<TypeName>(input_data);
        if (!first_child) {
            parent_node->SetPointer3(child_node);
        }
        else {
            first_child->SetPointer1(child_node);
            child_node->SetPointer2(first_child);
        }

        int parent_level = FindParentLevel(parent_node);
        int child_level = parent_level + 1;

        if (child_level == total_levels) {
            std::list<Node<TypeName>*> new_level;
            new_level.push_back(child_node);
            level_stack.push(new_level);
            total_levels++;
        }
        else {
            std::stack<std::list<Node<TypeName>*>> upper;
            while ((int)level_stack.size() > child_level + 1) {
                upper.push(level_stack.top());
                level_stack.pop();
            }
            auto target = level_stack.top();
            level_stack.pop();
            // avoid double link if prev is first_child
            if (!target.empty()) {
                Node<TypeName>* prev = target.back();
                if (prev != first_child) {
                    prev->SetPointer1(child_node);
                    child_node->SetPointer2(prev);
                }
            }
            target.push_back(child_node);
            level_stack.push(target);
            while (!upper.empty()) {
                level_stack.push(upper.top());
                upper.pop();
            }
        }
        return child_node;
    }

    int GetTotalLevels() { return total_levels; }

    void PrintTree() {
        // Print without vector - use temp stack to reverse
        std::stack<std::list<Node<TypeName>*>> temp = level_stack;
        std::stack<std::list<Node<TypeName>*>> rev;
        while (!temp.empty()) { rev.push(temp.top()); temp.pop(); }

        std::cout << "\n=== CHRISTMAS TREE STACK<LIST> NO VECTOR ===\n";
        int i = 0;
        while (!rev.empty()) {
            std::cout << "level_" << i++ << " : ";
            bool first = true;
            for (auto n : rev.top()) {
                if (!first) std::cout << " <-> ";
                std::cout << "[" << n->GetData() << "]";
                first = false;
            }
            std::cout << "\n";
            rev.pop();
        }
        std::cout << "========================================\n";
    }

    std::list<Node<TypeName>*> GetLevel(int l) {
        std::stack<std::list<Node<TypeName>*>> upper;
        while ((int)level_stack.size() > l + 1) {
            upper.push(level_stack.top());
            level_stack.pop();
        }
        auto result = level_stack.top();
        // restore
        while (!upper.empty()) {
            level_stack.push(upper.top());
            upper.pop();
        }
        return result;
    }
};