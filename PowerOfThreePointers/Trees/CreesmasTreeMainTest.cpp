#include "ChristmasTree.h"
#include <iostream>

int main() {
    ChristmasTree<int> tree;

    // Level 0 - 1 node
    auto root = tree.AddRoot(1);
    std::cout << "Added root 1\n";

    // Level 1 - 2 nodes
    auto l1_1 = tree.AddLeftChild(root, 2);
    auto l1_2 = tree.AddRightChild(root, 3);
    std::cout << "Added level 1: 2, 3\n";

    // Level 2 - 4 nodes
    auto l2_1 = tree.AddLeftChild(l1_1, 4);
    auto l2_2 = tree.AddRightChild(l1_1, 5);
    auto l2_3 = tree.AddLeftChild(l1_2, 6);
    auto l2_4 = tree.AddRightChild(l1_2, 7);
    std::cout << "Added level 2: 4,5,6,7\n";

    // Level 3 - 8 nodes
    tree.AddLeftChild(l2_1, 8);
    tree.AddRightChild(l2_1, 9);
    tree.AddLeftChild(l2_2, 10);
    tree.AddRightChild(l2_2, 11);
    tree.AddLeftChild(l2_3, 12);
    tree.AddRightChild(l2_3, 13);
    tree.AddLeftChild(l2_4, 14);
    tree.AddRightChild(l2_4, 15);
    std::cout << "Added level 3: 8-15\n";

    std::cout << "\nTotal levels: " << tree.GetTotalLevels() << " (should be 4)\n";

    tree.PrintTree();

    // Test P1/P2/P3 connections
    std::cout << "\n=== TEST P1/P2/P3 ===\n";
    std::cout << "Root P3 (LeftChild) = " << root->GetPointer3()->GetData() << " (should be 2)\n";
    std::cout << "Node 2 P1 (LevelNext) = " << l1_1->GetPointer1()->GetData() << " (should be 3)\n";
    std::cout << "Node 3 P2 (LevelPrev) = " << l1_2->GetPointer2()->GetData() << " (should be 2)\n";
    std::cout << "Node 2 P3 (LeftChild) = " << l2_1->GetData() << " (should be 4)\n";

    std::cout << "\n=== CHRISTMAS TREE TEST PASSED! ===\n";
    return 0;
}