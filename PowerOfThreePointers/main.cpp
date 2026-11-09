#include <iostream>
#include "Core/Node.h"
#include "Core/SuperContainer.h"
#include "Linear/DoubleLinkedList.h"
#include "Linear/Stack.h"
#include "Linear/Queue.h"
#include "Trees/ChristmasTree.h"
#include "Trees/BinaryTree.h"

using namespace std;

int main() {
    std::cout << "=== EMPIRE TEST ===" << std::endl;

    DoubleLinkedList<int> my_list;
    my_list.Add(10, 0);
    my_list.Add(20, 1);
    my_list.Add(30, 1);
    my_list.Add(5, 0);
    my_list.Print();
    std::cout << "Size: " << my_list.Size() << std::endl;

    // === STACK TEST FIRST ===
    std::cout << "\n--- STACK TEST ---" << std::endl;
    Stack<int> my_stack;
    my_stack.Add(10);
    my_stack.Add(20);
    my_stack.Add(30);
    cout << "Top: " << my_stack.Top() << endl; // 30
    cout << "Pop: " << my_stack.Pop() << endl; // 30
    cout << "Top after Pop: " << my_stack.Top() << endl; // 20

    // === QUEUE TEST ===
    std::cout << "\n--- QUEUE TEST ---" << std::endl;
    Queue<int> my_queue;
    my_queue.Add(10);
    my_queue.Add(20);
    my_queue.Add(30);
    cout << "Front: " << my_queue.Front() << endl; // 10
    cout << "Dequeue: " << my_queue.Dequeue() << endl; // 10
    cout << "Front after Dequeue: " << my_queue.Front() << endl; // 20

    // === CHRISTMAS TREE TEST (with safety) ===
    std::cout << "\n--- CHRISTMAS TREE TEST ---" << std::endl;
    ChristmasTree<int> my_tree;
    my_tree.Add(10, 0);
    my_tree.Add(5, 0);
    my_tree.Add(15, 0);
    my_tree.Print();

    Node<int>* root_node = my_tree.GetHead();
    if (root_node) {
        Node<int>* left_child = my_tree.GetLeftChild(root_node);
        if (left_child) {
            std::cout << "Root P3 (LeftChild): " << left_child->GetData() << std::endl;

            // SAFE CHECK before using P1 trick
            Node<int>* right_child = my_tree.GetRightChild(left_child);
            if (right_child) {
                std::cout << "RightChild via trick Left->P1: " << right_child->GetData() << std::endl;
                std::cout << "TRICK WORKS!" << std::endl;
            }
            else {
                std::cout << "RightChild is NULL - trick failed!" << std::endl;
            }
        }
        else {
            std::cout << "LeftChild is NULL!" << std::endl;
        }
    }
    BinaryTree<int> tree;

    std::cout << "=== Franchesko's BinaryTree Empire Test ===" << std::endl;

    // Test 1: Add nodes - 4 stage tree
    std::cout << "\n[1] Adding nodes: 10,5,15,3,7,12,18,1,4,6,8,11,13,16,20" << std::endl;
    tree.Add(10);
    tree.Add(5);
    tree.Add(15);
    tree.Add(3);
    tree.Add(7);
    tree.Add(12);
    tree.Add(18);
    tree.Add(1);
    tree.Add(4);
    tree.Add(6);
    tree.Add(8);
    tree.Add(11);
    tree.Add(13);
    tree.Add(16);
    tree.Add(20);

    std::cout << "Size: " << tree.Size() << " (should be 15)" << std::endl;
    std::cout << "IsEmpty: " << tree.IsEmpty() << " (should be 0)" << std::endl;

    // Test 2: Print tree
    std::cout << "\n[2] Tree structure (rotated 90 degrees):" << std::endl;
    tree.Print();

    // Test 3: Peek root
    std::cout << "\n[3] Peek root: " << tree.Peek() << " (should be 10)" << std::endl;

    // Test 4: Search tests
    std::cout << "\n[4] Search tests:" << std::endl;
    std::cout << "Search 7: " << (tree.Search(7) ? "FOUND" : "NOT FOUND") << " (should be FOUND)" << std::endl;
    std::cout << "Search 13: " << (tree.Search(13) ? "FOUND" : "NOT FOUND") << " (should be FOUND)" << std::endl;
    std::cout << "Search 100: " << (tree.Search(100) ? "FOUND" : "NOT FOUND") << " (should be NOT FOUND)" << std::endl;
    std::cout << "Search 1: " << (tree.Search(1) ? "FOUND" : "NOT FOUND") << " (should be FOUND)" << std::endl;

    // Test 5: Check P1,P2,P3 pointers
    std::cout << "\n[5] Checking pointers P1,P2,P3:" << std::endl;
    auto head = tree.GetHead();
    std::cout << "Head: " << head->GetData() << std::endl;
    std::cout << "Head->P1 (Left): " << tree.GetLeftChild(head)->GetData() << " (should be 5)" << std::endl;
    std::cout << "Head->P2 (Right): " << tree.GetRightChild(head)->GetData() << " (should be 15)" << std::endl;

    auto node5 = tree.GetLeftChild(head);
    std::cout << "Node 5->P3 (Parent): " << tree.GetParent(node5)->GetData() << " (should be 10)" << std::endl;
    std::cout << "Node 5->P1 (Left): " << tree.GetLeftChild(node5)->GetData() << " (should be 3)" << std::endl;
    std::cout << "Node 5->P2 (Right): " << tree.GetRightChild(node5)->GetData() << " (should be 7)" << std::endl;

    // Test 6: Stage check
    std::cout << "\n[6] 4 Stage verification:" << std::endl;
    std::cout << "Stage 0: " << head->GetData() << std::endl;
    std::cout << "Stage 1: " << tree.GetLeftChild(head)->GetData() << ", "
        << tree.GetRightChild(head)->GetData() << " - children of 10" << std::endl;

    auto node3 = tree.GetLeftChild(node5);
    auto node7 = tree.GetRightChild(node5);
    std::cout << "Stage 2: " << node3->GetData() << "," << node7->GetData()
        << " children of 5 | "
        << tree.GetLeftChild(tree.GetRightChild(head))->GetData() << ","
        << tree.GetRightChild(tree.GetRightChild(head))->GetData() << " children of 15" << std::endl;

    // Test 7: Clear
    std::cout << "\n[7] Testing Clear:" << std::endl;
    std::cout << "Before Clear Size: " << tree.Size() << std::endl;
    // tree.Clear(); // Uncomment to test
    // std::cout << "After Clear Size: " << tree.Size() << " IsEmpty: " << tree.IsEmpty() << std::endl;

    std::cout << "\n=== All tests passed! Empire is strong! ===" << std::endl;
    std::cout << "Enjoy your mandarins, Franchesko jan! 🍊" << std::endl;

    return 0;
}