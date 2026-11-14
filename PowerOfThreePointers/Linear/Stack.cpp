// test_stack.cpp - Test Linear Empire Stack
#include <iostream>
#include "Stack.h"

int main() {
    Stack<int> my_stack;

    std::cout << "=== STACK TEST - TWO BROTHERS EMPIRE ===\n";

    // Test 1: Push 3 items
    std::cout << "\n[1] Push 10, 20, 30:\n";
    my_stack.Add(10);
    my_stack.Add(20);
    my_stack.Add(30);
    my_stack.Print(); // Should: 30 20 10
    std::cout << "Size: " << my_stack.Size() << " (expect 3)\n";
    std::cout << "Top: " << my_stack.Top() << " (expect 30)\n";

    // Test 2: Pop
    std::cout << "\n[2] Pop():\n";
    int val = my_stack.Pop();
    std::cout << "Popped: " << val << " (expect 30)\n";
    my_stack.Print(); // Should: 20 10
    std::cout << "Size: " << my_stack.Size() << " (expect 2)\n";

    // Test 3: Peek
    std::cout << "\n[3] Peek():\n";
    std::cout << "Peek: " << my_stack.Peek() << " (expect 20)\n";

    // Test 4: IsEmpty, Clear
    std::cout << "\n[4] Clear():\n";
    my_stack.Clear();
    std::cout << "IsEmpty: " << my_stack.IsEmpty() << " (expect 1)\n";
    std::cout << "Size: " << my_stack.Size() << " (expect 0)\n";

    // Test 5: Where check
    std::cout << "\n[5] Add with where=1 (should fail):\n";
    int result = my_stack.Add(100, 1);
    std::cout << "Result: " << result << " (expect -1)\n";

    std::cout << "\n=== STACK TEST PASSED! EMPIRE STRONG! ===\n";
    return 0;
}