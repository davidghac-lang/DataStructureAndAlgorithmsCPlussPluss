#include <iostream>
#include "Linear/DoubleLinkedList.h"
#include "Trees/ChristmasTree.h"

int main() {
    std::cout << "=== EMPIRE TEST ===" << std::endl;

    DoubleLinkedList<int> my_list;
    my_list.Add(10, 0);
    my_list.Add(20, 1);
    my_list.Add(30, 1);
    my_list.Add(5, 0);
    my_list.Print();
    std::cout << "Size: " << my_list.Size() << std::endl;

    ChristmasTree<int> my_tree;
    my_tree.Add(10, 0);
    my_tree.Add(5, 0);
    my_tree.Add(15, 0);
    my_tree.Print();

    Node<int>* root_node = my_tree.GetHead();
    Node<int>* left_child = my_tree.GetLeftChild(root_node);
    Node<int>* right_child = my_tree.GetRightChild(left_child);

    std::cout << "Root P3 (LeftChild): " << left_child->GetData() << std::endl;
    std::cout << "RightChild via trick Left->P1: " << right_child->GetData() << std::endl;
    std::cout << "TRICK WORKS!" << std::endl;

    return 0;
}