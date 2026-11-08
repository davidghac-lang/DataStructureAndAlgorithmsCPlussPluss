#pragma once

template<class TypeName>
class Node {
private:
    TypeName data;
    Node<TypeName>* pointer1;
    Node<TypeName>* pointer2;
    Node<TypeName>* pointer3;

public:
    Node() {
        data = TypeName();
        pointer1 = nullptr;
        pointer2 = nullptr;
        pointer3 = nullptr;
    }

    Node(const TypeName& new_data) {
        data = new_data;
        pointer1 = nullptr;
        pointer2 = nullptr;
        pointer3 = nullptr;
    }

    TypeName GetData() { return data; }
    Node<TypeName>* GetPointer1() { return pointer1; }
    Node<TypeName>* GetPointer2() { return pointer2; }
    Node<TypeName>* GetPointer3() { return pointer3; }

    void SetData(const TypeName& new_data) { data = new_data; }
    void SetPointer1(Node<TypeName>* new_p) { pointer1 = new_p; }
    void SetPointer2(Node<TypeName>* new_p) { pointer2 = new_p; }
    void SetPointer3(Node<TypeName>* new_p) { pointer3 = new_p; }
};