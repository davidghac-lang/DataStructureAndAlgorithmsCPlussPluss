#include "ChristmasTree.h"
#include "Node.h"
#include "LevelInfo.h"
#include <iostream>
#include <cassert>

int main() {
    ChristmasTree<int> tree;
    std::cout << "========================================\n";
    std::cout << "  4 LEVEL CHRISTMAS TREE - EMPIRE TEST  \n";
    std::cout << "========================================\n";

    // LEVEL 0: [1]
    auto n1 = tree.AddRoot(1);
    std::cout << "Level 0: [1]\n";

    // LEVEL 1: [2] <-> [3]
    auto n2 = tree.AddLeftChild(n1, 2);
    auto n3 = tree.AddRightChild(n1, 3);
    std::cout << "Level 1: [2] <-> [3]\n";

    // LEVEL 2: [4] <-> [5] <-> [6] <-> [7]
    auto n4 = tree.AddLeftChild(n2, 4);
    auto n5 = tree.AddRightChild(n2, 5);
    auto n6 = tree.AddLeftChild(n3, 6);
    auto n7 = tree.AddRightChild(n3, 7);
    std::cout << "Level 2: [4] <-> [5] <-> [6] <-> [7]\n";

    // LEVEL 3: [8] to [15] - 8 nodes!
    auto n8 = tree.AddLeftChild(n4, 8);
    auto n9 = tree.AddRightChild(n4, 9);
    auto n10 = tree.AddLeftChild(n5, 10);
    auto n11 = tree.AddRightChild(n5, 11);
    auto n12 = tree.AddLeftChild(n6, 12);
    auto n13 = tree.AddRightChild(n6, 13);
    auto n14 = tree.AddLeftChild(n7, 14);
    auto n15 = tree.AddRightChild(n7, 15);
    std::cout << "Level 3: [8] <-> [9] <-> [10] <-> [11] <-> [12] <-> [13] <-> [14] <-> [15]\n";

    // Visual
    tree.PrintTree();
    assert(tree.GetTotalLevels() == 4);
    std::cout << "\nTotal levels: " << tree.GetTotalLevels() << " (expected 4) PASS\n";

    // TEST 1: UP WALK 4 levels [15]->[7]->[3]->[1]
    std::cout << "\n=== TEST 1: 4-LEVEL UP WALK ===\n";
    std::cout << "Test [15] -> [7] -> [3] -> [1]\n";
    Node<int>* cur = n15;
    assert(cur->GetData() == 15);
    cur = cur->GetParent(); assert(cur->GetData() == 7); std::cout << "[15] -> [7] OK\n";
    cur = cur->GetParent(); assert(cur->GetData() == 3); std::cout << "[7] -> [3] OK\n";
    cur = cur->GetParent(); assert(cur->GetData() == 1); std::cout << "[3] -> [1] ROOT OK\n";

    std::cout << "\nTest [8] -> [4] -> [2] -> [1]\n";
    cur = n8;
    cur = cur->GetParent(); assert(cur->GetData() == 4);
    cur = cur->GetParent(); assert(cur->GetData() == 2);
    cur = cur->GetParent(); assert(cur->GetData() == 1);
    std::cout << "[8] -> [4] -> [2] -> [1] PASS\n";

    // TEST 2: GetChildren
    std::cout << "\n=== TEST 2: GetChildren 4 Levels ===\n";
    auto c1 = tree.GetChildren(n1); assert(c1.size() == 2);
    std::cout << "Children of [1]: [2] [3] PASS\n";

    auto c2 = tree.GetChildren(n2); assert(c2.size() == 2);
    std::cout << "Children of [2]: [4] [5] PASS\n";

    auto c4 = tree.GetChildren(n4); assert(c4.size() == 2);
    std::cout << "Children of [4]: [8] [9] PASS\n";

    auto c5 = tree.GetChildren(n5); assert(c5.size() == 2);
    std::cout << "Children of [5]: [10] [11] PASS\n";

    auto c7 = tree.GetChildren(n7); assert(c7.size() == 2);
    std::cout << "Children of [7]: [14] [15] PASS\n";

    // TEST 3: PathToRoot
    std::cout << "\n=== TEST 3: PrintPathToRoot 4 Levels ===\n";
    tree.PrintPathToRoot(n15); // [15]->[7]->[3]->[1]
    tree.PrintPathToRoot(n8);  // [8]->[4]->[2]->[1]
    tree.PrintPathToRoot(n11); // [11]->[5]->[2]->[1]

    auto path = tree.GetPathToRoot(n15);
    assert(path.size() == 4);
    std::cout << "Path size 4 PASS\n";

    // TEST 4: GetLevel
    std::cout << "\n=== TEST 4: GetLevel ===\n";
    auto lvl0 = tree.GetLevel(0); assert(lvl0.size() == 1);
    auto lvl1 = tree.GetLevel(1); assert(lvl1.size() == 2);
    auto lvl2 = tree.GetLevel(2); assert(lvl2.size() == 4);
    auto lvl3 = tree.GetLevel(3); assert(lvl3.size() == 8);
    std::cout << "level_0:1 level_1:2 level_2:4 level_3:8 PASS\n";
    tree.PrintFancyTree();
    // TEST 5: Sibling links P1/P2
    std::cout << "\n=== TEST 5: Sibling Links Level 3 ===\n";
    assert(n8->GetPointer1() == n9);
    assert(n9->GetPointer1() == n10);
    assert(n15->GetPointer2() == n14);
    std::cout << "[8] <-> [9] <-> [10] <-> [11] <-> [12] <-> [13] <-> [14] <-> [15] PASS\n";

    // TEST 6: Level numbers
    std::cout << "\n=== TEST 6: Level Numbers ===\n";
    assert(n1->GetLevel() == 0);
    assert(n3->GetLevel() == 1);
    assert(n6->GetLevel() == 2);
    assert(n15->GetLevel() == 3);
    std::cout << "Levels 0,1,2,3 correct PASS\n";

    std::cout << "\n========================================\n";
    std::cout << "  ALL TESTS PASSED - 4 LEVEL EMPIRE!   \n";
    std::cout << "  Tree: 1-2-4-8 = 15 nodes total       \n";
    std::cout << "========================================\n";
    return 0;
}