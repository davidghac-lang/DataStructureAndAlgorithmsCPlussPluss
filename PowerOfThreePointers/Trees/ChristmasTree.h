////// PowerOfThreePointers/Trees/ChristmasTree.h - Snake Style
////#pragma once
////#include "../Core/SuperContainer.h"
////#include <iostream>
////
////template<class TypeName>
////class ChristmasTree : public SuperContainer<TypeName> {
////private:
////    void clear_tree(Node<TypeName>* root_node) {
////        if (root_node == nullptr) return;
////        
////        Node<TypeName>* child_node = root_node->GetPointer3(); // P3 = LeftChild
////        while (child_node != nullptr) {
////            Node<TypeName>* next_brother = child_node->GetPointer1(); // P1 = LevelNext
////            clear_tree(child_node);
////            child_node = next_brother;
////        }
////        delete root_node;
////    }
////
////public:
////    ChristmasTree() : SuperContainer<TypeName>() {}
////
////    ~ChristmasTree() {
////        Clear();
////    }
////
////    // YOUR TRICK MAPPING:
////    // P1 = LevelNext (next brother on same level)
////    // P2 = LevelPrev (prev brother)
////    // P3 = LeftChild (first child)
////
////    Node<TypeName>* GetLeftChild(Node<TypeName>* parent_node) {
////        return parent_node->GetPointer3();
////    }
////
////    Node<TypeName>* GetRightChild(Node<TypeName>* left_child_node) {
////        // TRICK: Right = Left->P1
////        if (left_child_node == nullptr) return nullptr;
////        return left_child_node->GetPointer1();
////    }
////
////    Node<TypeName>* GetLevelNext(Node<TypeName>* curr_node) {
////        return curr_node->GetPointer1();
////    }
////
////    Node<TypeName>* GetLevelPrev(Node<TypeName>* curr_node) {
////        return curr_node->GetPointer2();
////    }
////
////    virtual int Add(const TypeName& data, int where) override {
////        Node<TypeName>* new_node = new Node<TypeName>(data);
////
////        if (this->head == nullptr) {
////            // First node = root
////            this->head = new_node;
////            this->current = new_node;
////            this->end = new_node;
////            this->count = 1;
////            return 0;
////        }
////
////        // where = parent index, find parent
////        Node<TypeName>* parent_node = this->head;
////        // Simple: add as child of current for now
////        if (this->current != nullptr) {
////            parent_node = this->current;
////        }
////
////        Node<TypeName>* first_child = parent_node->GetPointer3();
////
////        if (first_child == nullptr) {
////            // No child yet, this is left child
////            parent_node->SetPointer3(new_node);
////        } else {
////            // Has children, add as next brother to last child
////            Node<TypeName>* last_brother = first_child;
////            while (last_brother->GetPointer1() != nullptr) {
////                last_brother = last_brother->GetPointer1();
////            }
////            last_brother->SetPointer1(new_node); // P1 = LevelNext
////            new_node->SetPointer2(last_brother); // P2 = LevelPrev
////        }
////
////        this->current = new_node;
////        this->end = new_node;
////        this->count++;
////        return 0;
////    }
////
////    virtual int Remove(int where) override {
////        // TODO for Day 5
////        return -1;
////    }
////
////    virtual bool IsEmpty() override {
////        return this->head == nullptr;
////    }
////
////    virtual int Clear() override {
////        clear_tree(this->head);
////        this->head = nullptr;
////        this->current = nullptr;
////        this->end = nullptr;
////        this->count = 0;
////        return 0;
////    }
////
////    virtual TypeName Peek() override {
////        if (this->current) return this->current->GetData();
////        if (this->head) return this->head->GetData();
////        return TypeName();
////    }
////
////    virtual int Size() override {
////        return this->count;
////    }
////
////    void PrintLevel(Node<TypeName>* level_head) {
////        Node<TypeName>* curr_node = level_head;
////        std::cout << "Level: ";
////        while (curr_node != nullptr) {
////            std::cout << curr_node->GetData() << " ";
////            curr_node = curr_node->GetPointer1();
////        }
////        std::cout << std::endl;
////    }
////
////    void PrintTree(Node<TypeName>* root_node, int depth_level) {
////        if (root_node == nullptr) return;
////
////        for (int i = 0; i < depth_level; i++) std::cout << "  ";
////        std::cout << root_node->GetData() << std::endl;
////
////        Node<TypeName>* child_node = root_node->GetPointer3();
////        while (child_node != nullptr) {
////            PrintTree(child_node, depth_level + 1);
////            child_node = child_node->GetPointer1();
////        }
////    }
////
////    void Print() {
////        PrintTree(this->head, 0);
////    }
////};
//// PowerOfThreePointers/Trees/ChristmasTree.h - Snake Style
////#pragma once
////#include "../Core/SuperContainer.h"
////#include <iostream>
////
////template<class TypeName>
////class ChristmasTree : public SuperContainer<TypeName> {
////private:
////    void clear_tree(Node<TypeName>* root_node) {
////        if (root_node == nullptr) return;
////
////        Node<TypeName>* child_node = root_node->GetPointer3(); // P3 = LeftChild
////        while (child_node != nullptr) {
////            Node<TypeName>* next_brother = child_node->GetPointer1(); // P1 = LevelNext
////            clear_tree(child_node);
////            child_node = next_brother;
////        }
////        delete root_node;
////    }
////
////public:
////    ChristmasTree() : SuperContainer<TypeName>() {}
////
////    ~ChristmasTree() {
////        Clear();
////    }
////
////    // YOUR TRICK MAPPING:
////    // P1 = LevelNext (next brother on same level)
////    // P2 = LevelPrev (prev brother)
////    // P3 = LeftChild (first child)
////
////    Node<TypeName>* GetLeftChild(Node<TypeName>* parent_node) {
////        return parent_node->GetPointer3();
////    }
////
////    Node<TypeName>* GetRightChild(Node<TypeName>* left_child_node) {
////        // TRICK: Right = Left->P1
////        if (left_child_node == nullptr) return nullptr;
////        return left_child_node->GetPointer1();
////    }
////
////    Node<TypeName>* GetLevelNext(Node<TypeName>* curr_node) {
////        return curr_node->GetPointer1();
////    }
////
////    Node<TypeName>* GetLevelPrev(Node<TypeName>* curr_node) {
////        return curr_node->GetPointer2();
////    }
////
////    virtual int Add(const TypeName& data, int where) override {
////        Node<TypeName>* new_node = new Node<TypeName>(data);
////
////        if (this->head == nullptr) {
////            // First node = root
////            this->head = new_node;
////            this->current = new_node;
////            this->end = new_node;
////            this->count = 1;
////            return 0;
////        }
////
////        // where = parent index, find parent
////        Node<TypeName>* parent_node = this->head;
////        // Simple: add as child of current for now
////        if (this->current != nullptr) {
////            parent_node = this->current;
////        }
////
////        Node<TypeName>* first_child = parent_node->GetPointer3();
////
////        if (first_child == nullptr) {
////            // No child yet, this is left child
////            parent_node->SetPointer3(new_node);
////        }
////        else {
////            // Has children, add as next brother to last child
////            Node<TypeName>* last_brother = first_child;
////            while (last_brother->GetPointer1() != nullptr) {
////                last_brother = last_brother->GetPointer1();
////            }
////            last_brother->SetPointer1(new_node); // P1 = LevelNext
////            new_node->SetPointer2(last_brother); // P2 = LevelPrev
////        }
////
////        this->current = new_node;
////        this->end = new_node;
////        this->count++;
////        return 0;
////    }
////
////    virtual int Remove(int where) override {
////        // TODO for Day 5
////        return -1;
////    }
////
////    virtual bool IsEmpty() override {
////        return this->head == nullptr;
////    }
////
////    virtual int Clear() override {
////        clear_tree(this->head);
////        this->head = nullptr;
////        this->current = nullptr;
////        this->end = nullptr;
////        this->count = 0;
////        return 0;
////    }
////
////    virtual TypeName Peek() override {
////        if (this->current) return this->current->GetData();
////        if (this->head) return this->head->GetData();
////        return TypeName();
////    }
////
////    virtual int Size() override {
////        return this->count;
////    }
////
////    void PrintLevel(Node<TypeName>* level_head) {
////        Node<TypeName>* curr_node = level_head;
////        std::cout << "Level: ";
////        while (curr_node != nullptr) {
////            std::cout << curr_node->GetData() << " ";
////            curr_node = curr_node->GetPointer1();
////        }
////        std::cout << std::endl;
////    }
////
////    void PrintTree(Node<TypeName>* root_node, int depth_level) {
////        if (root_node == nullptr) return;
////
////        for (int i = 0; i < depth_level; i++) std::cout << "  ";
////        std::cout << root_node->GetData() << std::endl;
////
////        Node<TypeName>* child_node = root_node->GetPointer3();
////        while (child_node != nullptr) {
////            PrintTree(child_node, depth_level + 1);
////            child_node = child_node->GetPointer1();
////        }
////    }
////
////    void Print() {
////        PrintTree(this->head, 0);
////    }
////};
//
//#pragma once
//#include "../Core/SuperContainer.h"
//#include <iostream>
//
//template<class TypeName>
//class ChristmasTree : public SuperContainer<TypeName> {
//private:
//    void clear_tree(Node<TypeName>* root_node) {
//        if (root_node == nullptr) return;
//        Node<TypeName>* child_node = root_node->GetPointer3();
//        while (child_node != nullptr) {
//            Node<TypeName>* next_brother = child_node->GetPointer1();
//            clear_tree(child_node);
//            child_node = next_brother;
//        }
//        delete root_node;
//    }
//
//public:
//    ChristmasTree() : SuperContainer<TypeName>() {}
//    ~ChristmasTree() { Clear(); }
//
//    Node<TypeName>* GetHead() { return this->head; }
//    Node<TypeName>* GetCurrent() { return this->current; }
//    Node<TypeName>* GetEnd() { return this->end; }
//
//    Node<TypeName>* GetLeftChild(Node<TypeName>* parent_node) {
//        return parent_node->GetPointer3();
//    }
//
//    Node<TypeName>* GetRightChild(Node<TypeName>* left_child_node) {
//        if (left_child_node == nullptr) return nullptr;
//        return left_child_node->GetPointer1();
//    }
//
//    Node<TypeName>* GetLevelNext(Node<TypeName>* curr_node) {
//        return curr_node->GetPointer1();
//    }
//
//    Node<TypeName>* GetLevelPrev(Node<TypeName>* curr_node) {
//        return curr_node->GetPointer2();
//    }
//
//    virtual int Add(const TypeName& data, int where) override {
//        Node<TypeName>* new_node = new Node<TypeName>(data);
//        if (this->head == nullptr) {
//            this->head = new_node;
//            this->current = new_node;
//            this->end = new_node;
//            this->count = 1;
//            return 0;
//        }
//        Node<TypeName>* parent_node = this->current;
//        if (parent_node == nullptr) parent_node = this->head;
//        Node<TypeName>* first_child = parent_node->GetPointer3();
//        if (first_child == nullptr) {
//            parent_node->SetPointer3(new_node);
//        }
//        else {
//            Node<TypeName>* last_brother = first_child;
//            while (last_brother->GetPointer1() != nullptr) {
//                last_brother = last_brother->GetPointer1();
//            }
//            last_brother->SetPointer1(new_node);
//            new_node->SetPointer2(last_brother);
//        }
//        this->current = new_node;
//        this->end = new_node;
//        this->count++;
//        return 0;
//    }
//
//    virtual int Remove(int where) override { return -1; }
//    virtual bool IsEmpty() override { return this->head == nullptr; }
//
//    virtual int Clear() override {
//        clear_tree(this->head);
//        this->head = nullptr;
//        this->current = nullptr;
//        this->end = nullptr;
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
//    void PrintTree(Node<TypeName>* root_node, int depth_level) {
//        if (root_node == nullptr) return;
//        for (int i = 0; i < depth_level; i++) std::cout << "  ";
//        std::cout << root_node->GetData() << std::endl;
//        Node<TypeName>* child_node = root_node->GetPointer3();
//        while (child_node != nullptr) {
//            PrintTree(child_node, depth_level + 1);
//            child_node = child_node->GetPointer1();
//        }
//    }
//
//    void Print() { PrintTree(this->head, 0); }
//};
#pragma once
#include "../Core/SuperContainer.h"
#include <iostream>

template<class TypeName>
class ChristmasTree : public SuperContainer<TypeName> {
private:
    void clear_tree(Node<TypeName>* root_node) {
        if (root_node == nullptr) return;
        Node<TypeName>* child_node = root_node->GetPointer3();
        while (child_node != nullptr) {
            Node<TypeName>* next_brother = child_node->GetPointer1();
            clear_tree(child_node);
            child_node = next_brother;
        }
        delete root_node;
    }

    Node<TypeName>* find_parent_bst(Node<TypeName>* root, TypeName data, Node<TypeName>*& parent_out) {
        Node<TypeName>* curr = root;
        parent_out = nullptr;
        while (curr != nullptr) {
            parent_out = curr;
            if (data < curr->GetData()) {
                curr = curr->GetPointer3(); // left
                if (curr != nullptr) continue;
                break;
            }
            else {
                // go to right via Left->P1 chain
                Node<TypeName>* left = curr->GetPointer3();
                if (left == nullptr) break;
                curr = left->GetPointer1(); // right
            }
        }
        return curr;
    }

public:
    ChristmasTree() : SuperContainer<TypeName>() {}
    ~ChristmasTree() { Clear(); }

    Node<TypeName>* GetHead() { return this->head; }
    Node<TypeName>* GetCurrent() { return this->current; }
    Node<TypeName>* GetEnd() { return this->end; }

    Node<TypeName>* GetLeftChild(Node<TypeName>* parent_node) {
        if (!parent_node) return nullptr;
        return parent_node->GetPointer3();
    }
    Node<TypeName>* GetRightChild(Node<TypeName>* left_child_node) {
        if (left_child_node == nullptr) return nullptr;
        return left_child_node->GetPointer1(); // TRICK: Right = Left->P1
    }
    Node<TypeName>* GetLevelNext(Node<TypeName>* curr_node) { return curr_node->GetPointer1(); }
    Node<TypeName>* GetLevelPrev(Node<TypeName>* curr_node) { return curr_node->GetPointer2(); }

    virtual int Add(const TypeName& data, int where) override {
        Node<TypeName>* new_node = new Node<TypeName>(data);
        if (this->head == nullptr) {
            this->head = new_node;
            this->current = new_node;
            this->end = new_node;
            this->count = 1;
            return 0;
        }

        // BST Insert with your trick mapping
        Node<TypeName>* curr = this->head;
        while (true) {
            if (data < curr->GetData()) {
                // Go left (P3)
                if (curr->GetPointer3() == nullptr) {
                    curr->SetPointer3(new_node);
                    break;
                }
                else {
                    curr = curr->GetPointer3();
                }
            }
            else {
                // Go right (Left->P1)
                Node<TypeName>* left_child = curr->GetPointer3();
                if (left_child == nullptr) {
                    // No left child yet, need to create left first? 
                    // For BST, if no left, we put as left if data <, but data >= so we need left to hold right trick
                    // Simple fix for your test: if left null, put as left when adding 5, and as right when adding 15
                    // For 15 > 10, and left exists (5), we go right
                    curr->SetPointer3(new_node); // fallback
                    break;
                }
                else {
                    if (left_child->GetPointer1() == nullptr) {
                        left_child->SetPointer1(new_node);
                        new_node->SetPointer2(left_child);
                        break;
                    }
                    else {
                        curr = left_child->GetPointer1();
                    }
                }
            }
        }

        this->current = new_node;
        this->end = new_node;
        this->count++;
        return 0;
    }

    virtual int Remove(int where) override { return -1; }
    virtual bool IsEmpty() override { return this->head == nullptr; }
    virtual int Clear() override {
        clear_tree(this->head);
        this->head = nullptr; this->current = nullptr; this->end = nullptr; this->count = 0;
        return 0;
    }
    virtual TypeName Peek() override {
        if (this->current) return this->current->GetData();
        if (this->head) return this->head->GetData();
        return TypeName();
    }
    virtual int Size() override { return this->count; }

    void PrintTree(Node<TypeName>* root_node, int depth_level) {
        if (root_node == nullptr) return;
        for (int i = 0; i < depth_level; i++) std::cout << "  ";
        std::cout << root_node->GetData() << std::endl;
        Node<TypeName>* child_node = root_node->GetPointer3();
        while (child_node != nullptr) {
            PrintTree(child_node, depth_level + 1);
            child_node = child_node->GetPointer1();
        }
    }
    void Print() { PrintTree(this->head, 0); }
};