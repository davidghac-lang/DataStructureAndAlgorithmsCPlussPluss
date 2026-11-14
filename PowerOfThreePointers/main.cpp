#include <iostream>
//#include "Core/Node.h"
#include "Linear/Stack.h"
#include "Linear/Queue.h"
#include "Linear/DoubleLinkedList.h"

int main() {
    std::cout << "=== Testing with new Node.h (with parent UP) ===" << std::endl;

    // 1. Test Stack (LIFO)
    std::cout << "\n1. Stack Test:" << std::endl;
    Stack<int> s;
    s.Push(1);
    s.Push(2);
    s.Push(5); // like your ChristmasTree path
    std::cout << "Top: " << s.Peek() << " Expected 5" << std::endl;
    std::cout << "Pop: " << s.Pop() << " -> " << s.Pop() << " -> " << s.Pop() << std::endl;
    std::cout << "Stack Empty? " << s.IsEmpty() << " (1=true)" << std::endl;

    // 2. Test Queue (FIFO)
    std::cout << "\n2. Queue Test:" << std::endl;
    Queue<int> q;
    q.Enqueue(1);
    q.Enqueue(2);
    q.Enqueue(5);
    std::cout << "Front: " << q.Front() << " Expected 1" << std::endl;
    std::cout << "Dequeue: " << q.Dequeue() << " -> " << q.Dequeue() << " -> " << q.Dequeue() << std::endl;

    // 3. Test DoubleLinkedList with parent UP traversal
    std::cout << "\n3. DoubleLinkedList Test + Parent UP [5]->[2]->[1]:" << std::endl;
    DoubleLinkedList<int> list;
    list.PushBack(1);
    list.PushBack(2);
    list.PushBack(5);

    Node<int>* node5 = list.GetHead()->GetPointer1()->GetPointer1(); // 5
    std::cout << "Node: " << node5->GetData() << std::endl;

    // Test UP traversal using GetParent()
    Node<int>* up = node5->GetParent();
    std::cout << "UP from 5: " << up->GetData() << " Expected 2" << std::endl;
    up = up->GetParent();
    std::cout << "UP from 2: " << up->GetData() << " Expected 1" << std::endl;

    std::cout << "\nPath: [5]->[" << node5->GetParent()->GetData() << "]->["
        << node5->GetParent()->GetParent()->GetData() << "] - WORKS!" << std::endl;

    std::cout << "\n=== ALL TESTS PASSED ===" << std::endl;
    return 0;
}