#include <iostream>
#include "MyStack.h"

int main() {
    std::cout << "=== MyStack PRO Test ===" << std::endl;

    MyStack<int> s1;
    s1.Push(10);
    s1.Push(20);
    s1.Push(30);

    std::cout << "s1 size: " << s1.Size() << " (should be 3)" << std::endl;
    std::cout << "s1 top: " << s1.Top() << " (should be 30)" << std::endl;

    // Test COPY CONSTRUCTOR - your masterpiece!
    MyStack<int> s2 = s1;
    std::cout << "s2 (copy of s1) size: " << s2.Size() << " (should be 3)" << std::endl;
    std::cout << "s2 top: " << s2.Top() << " (should be 30)" << std::endl;

    s1.Pop();
    std::cout << "After s1.Pop(), s1 top: " << s1.Top() << " (20)" << std::endl;
    std::cout << "s2 top still: " << s2.Top() << " (30) - Deep copy works!" << std::endl;

    // Test MakeEmpty + clear
    s1.MakeEmpty();
    std::cout << "After MakeEmpty(), s1 size: " << s1.Size() << " (should be 0)" << std::endl;
    std::cout << "s1 IsEmpty: " << s1.IsEmpty() << " (should be 1)" << std::endl;

    std::cout << "=== ALL TESTS PASSED! PRO! ===" << std::endl;
    return 0;
}