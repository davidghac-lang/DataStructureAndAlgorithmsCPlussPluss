#include "../Core/Node.h"
#include "./ChristmasTree.h"
#include <iostream>

int main() {
    std::cout << "=== DAVID'S CHRISTMAS TREE 4 LEVELS ===\n";

    ChristmasTree<int> christmas_tree;

    Node<int>* root_node = christmas_tree.AddRoot(10);
    std::cout << "Root: [" << root_node->GetData() << "]\n";

    // Level 1 - Left / Right
    Node<int>* node_5 = christmas_tree.AddLeftChild(root_node, 5);
    Node<int>* node_15 = christmas_tree.AddRightChild(root_node, 15);

    // Level 2
    Node<int>* node_2 = christmas_tree.AddLeftChild(node_5, 2);
    Node<int>* node_7 = christmas_tree.AddRightChild(node_5, 7);
    Node<int>* node_12 = christmas_tree.AddLeftChild(node_15, 12);
    Node<int>* node_20 = christmas_tree.AddRightChild(node_15, 20);

    // Level 3
    christmas_tree.AddLeftChild(node_2, 1);
    christmas_tree.AddRightChild(node_2, 3);
    christmas_tree.AddLeftChild(node_7, 6);
    christmas_tree.AddRightChild(node_7, 8);
    christmas_tree.AddLeftChild(node_12, 11);
    christmas_tree.AddRightChild(node_12, 13);
    christmas_tree.AddLeftChild(node_20, 18);
    christmas_tree.AddRightChild(node_20, 25);

    christmas_tree.PrintTree();

    std::cout << "\nTotal levels: " << christmas_tree.GetTotalLevels() << "\n";

    // Test GetLevel - list not vector!
    for (int i = 0; i < christmas_tree.GetTotalLevels(); i++) {
        auto lvl = christmas_tree.GetLevel(i);
        std::cout << "Level " << i << " size " << lvl.size() << ": ";
        for (auto n : lvl) std::cout << "[" << n->GetData() << "] ";
        std::cout << "\n";
    }

    // Traverse via P1 - fix for list
    std::cout << "\nTraverse level 2 via P1: ";
    auto lvl2 = christmas_tree.GetLevel(2);
    Node<int>* curr = *lvl2.begin(); // list has no [0]
    while (curr) {
        std::cout << "[" << curr->GetData() << "] ";
        curr = curr->GetPointer1();
    }
    std::cout << "\n";

    std::cout << "\n=== SUCCESS 4 LEVELS LEFT/RIGHT! ===\n";
    return 0;
}