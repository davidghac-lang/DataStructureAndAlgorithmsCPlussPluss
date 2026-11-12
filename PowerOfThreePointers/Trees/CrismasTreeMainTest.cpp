//#include "ChristmasTree.h"
//#include <iostream>
//
//int main() {
//    ChristmasTree<int> tree;
//
//    // Level 0 - 1 node
//    auto root = tree.AddRoot(1);
//    std::cout << "Added root 1\n";
//
//    // Level 1 - 2 nodes
//    auto l1_1 = tree.AddLeftChild(root, 2);
//    auto l1_2 = tree.AddRightChild(root, 3);
//    std::cout << "Added level 1: 2, 3\n";
//
//    // Level 2 - 4 nodes
//    auto l2_1 = tree.AddLeftChild(l1_1, 4);
//    auto l2_2 = tree.AddRightChild(l1_1, 5);
//    auto l2_3 = tree.AddLeftChild(l1_2, 6);
//    auto l2_4 = tree.AddRightChild(l1_2, 7);
//    std::cout << "Added level 2: 4,5,6,7\n";
//
//    // Level 3 - 8 nodes
//    tree.AddLeftChild(l2_1, 8);
//    tree.AddRightChild(l2_1, 9);
//    tree.AddLeftChild(l2_2, 10);
//    tree.AddRightChild(l2_2, 11);
//    tree.AddLeftChild(l2_3, 12);
//    tree.AddRightChild(l2_3, 13);
//    tree.AddLeftChild(l2_4, 14);
//    tree.AddRightChild(l2_4, 15);
//    std::cout << "Added level 3: 8-15\n";
//
//    std::cout << "\nTotal levels: " << tree.GetTotalLevels() << " (should be 4)\n";
//
//    tree.PrintTree();
//
//    // Test P1/P2/P3 connections
//    std::cout << "\n=== TEST P1/P2/P3 ===\n";
//    std::cout << "Root P3 (LeftChild) = " << root->GetPointer3()->GetData() << " (should be 2)\n";
//    std::cout << "Node 2 P1 (LevelNext) = " << l1_1->GetPointer1()->GetData() << " (should be 3)\n";
//    std::cout << "Node 3 P2 (LevelPrev) = " << l1_2->GetPointer2()->GetData() << " (should be 2)\n";
//    std::cout << "Node 2 P3 (LeftChild) = " << l2_1->GetData() << " (should be 4)\n";
//
//    std::cout << "\n=== CHRISTMAS TREE TEST PASSED! ===\n";
//    return 0;
//}
#include <iostream>
#include "ChristmasTree.h"
#include "../Core/Node.h"

int main() {
    ChristmasTree<int> tree;

    std::cout << "=== Testing ChristmasTree V2 FAST ===\n";

    // [1](ROOT)
    auto* root = tree.AddRoot(1);
    std::cout << "Root: [" << root->GetData() << "] level=" << root->GetLevel() << "\n";

    // Level 1: [2] <-> [3]
    auto* n2 = tree.AddLeftChild(root, 2);
    auto* n3 = tree.AddRightChild(root, 3);

    std::cout << "\nLevel 1 creation:\n";
    std::cout << "n2=" << n2->GetData() << " n3=" << n3->GetData() << "\n";
    std::cout << "root->P3(first child): " << root->GetPointer3()->GetData() << "\n";
    std::cout << "n2->P1(next): " << (n2->GetPointer1() ? std::to_string(n2->GetPointer1()->GetData()) : "null") << " -> expect 3\n";
    std::cout << "n3->P2(prev): " << (n3->GetPointer2() ? std::to_string(n3->GetPointer2()->GetData()) : "null") << " -> expect 2\n";

    // Level 2: [4]<->[5] <-> [6]<->[7]
    auto* n4 = tree.AddLeftChild(n2, 4);
    auto* n5 = tree.AddRightChild(n2, 5);
    auto* n6 = tree.AddLeftChild(n3, 6);
    auto* n7 = tree.AddRightChild(n3, 7);

    std::cout << "\nLevel 2 creation:\n";
    std::cout << "n4=" << n4->GetData() << " n5=" << n5->GetData() << " n6=" << n6->GetData() << " n7=" << n7->GetData() << "\n";

    // Check full level DLL chain
    std::cout << "\nLevel 2 DLL chain check:\n";
    Node<int>* cur = n4;
    std::cout << "Chain: ";
    while (cur) {
        std::cout << "[" << cur->GetData() << "]";
        if (cur->GetPointer1()) std::cout << " <-> ";
        cur = cur->GetPointer1();
    }
    std::cout << "\nExpect: [4] <-> [5] <-> [6] <-> [7]\n";

    // Print via tree method
    tree.PrintTree();

    // Test GetLevel
    std::cout << "\nGetLevel tests:\n";
    for (int i = 0; i < tree.GetTotalLevels(); i++) {
        auto lvl = tree.GetLevel(i);
        std::cout << "Level " << i << " (" << lvl.size() << " nodes): ";
        for (auto* n : lvl) std::cout << n->GetData() << " ";
        std::cout << "\n";
    }

    std::cout << "\nVisual:\n";
    std::cout << "[1](ROOT)\n / \\\n[2] <-> [3]\n / \\   / \\\n[4]<->[5] <-> [6]<->[7]\n";

    std::cout << "\n=== TEST DONE ===\n";
    return 0;
}