// Node.h
template<class TypeName>
class Node {
private:
    TypeName data;
    Node<TypeName>* pointer1; // Next / Left / LevelNext
    Node<TypeName>* pointer2; // Prev / Right / LevelPrev
    Node<TypeName>* pointer3; // Current / End / Parent / LeftChild

public:
    Node(const TypeName& data) {
        this->data = data;
        this->pointer1 = nullptr;
        this->pointer2 = nullptr;
        this->pointer3 = nullptr;
    }

    TypeName GetData() { return data; }
    Node<TypeName>* GetPointer1() { return pointer1; }
    Node<TypeName>* GetPointer2() { return pointer2; }
    Node<TypeName>* GetPointer3() { return pointer3; }

    void SetPointer1(Node<TypeName>* p) { pointer1 = p; }
    void SetPointer2(Node<TypeName>* p) { pointer2 = p; }
    void SetPointer3(Node<TypeName>* p) { pointer3 = p; }
};