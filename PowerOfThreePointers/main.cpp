#include <iostream>
#include "Core/Node.h"
#include "Core/SuperContainer.h"
#include "Linear/DoubleLinkedList.h"
#include "Linear/Stack.h"
#include "Linear/Queue.h"
#include "Trees/ChristmasTree.h"

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

    return 0;
}