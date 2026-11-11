//#pragma once
//
//template<class TypeName>
//class Node {
//private:
//    TypeName data;
//    Node* P1; // LevelNext / Next / Left
//    Node* P2; // LevelPrev / Prev / Right
//    Node* P3; // LeftChild / Current / Parent / End
//    int level_index; // NEW! For FAST search - LevelInfo
//    friend class ChristmasTree<TypeName>; // allow access
//
//public:
//    Node(TypeName input_data) : data(input_data), P1(nullptr), P2(nullptr), P3(nullptr), level_index(0) {}
//
//    TypeName GetData() { return data; }
//    Node* GetPointer1() { return P1; }
//    Node* GetPointer2() { return P2; }
//    Node* GetPointer3() { return P3; }
//
//    void SetPointer1(Node* n) { P1 = n; }
//    void SetPointer2(Node* n) { P2 = n; }
//    void SetPointer3(Node* n) { P3 = n; }
//
//    int GetLevel() { return level_index; }
//    void SetLevel(int l) { level_index = l; }
//
//    int GetLevel() { return level_index; }
//    void SetLevel(int l) { level_index = l; }
//};
#pragma once

template<class TypeName> class ChristmasTree; // forward declaration

template<class TypeName>
class Node {
private:
    TypeName data;
    Node* P1 = nullptr;
    Node* P2 = nullptr;
    Node* P3 = nullptr;
    int level_index = 0;

public:
    Node(TypeName input_data) : data(input_data) {}

    TypeName GetData() { return data; }

    Node* GetPointer1() { return P1; }
    Node* GetPointer2() { return P2; }
    Node* GetPointer3() { return P3; }

    void SetPointer1(Node* n) { P1 = n; }
    void SetPointer2(Node* n) { P2 = n; }
    void SetPointer3(Node* n) { P3 = n; }

    int GetLevel() { return level_index; }
    void SetLevel(int l) { level_index = l; }
};