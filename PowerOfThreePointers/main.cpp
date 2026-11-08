#include <iostream>
#include "Trees/ChristmasTree.h"

int main() {
    ChristmasTree<int> tree;
    tree.AddRoot(10);
    tree.AddChild(10, 5);
    tree.AddChild(10, 15);
    tree.AddChild(5, 2);
    tree.AddChild(5, 7);

    std::cout << "=== ChristmasTree Test ===" << std::endl;
    tree.PrintTree();

    Node<int>* root = tree.GetHead();
    std::cout << "Root P3 (LeftChild): " << root->GetPointer3()->GetData() << std::endl;
    std::cout << "RightChild via trick Left->P1: " << tree.GetRightChild(root)->GetData() << std::endl;
    std::cout << "TRICK WORKS!" << std::endl;
    return 0;
}