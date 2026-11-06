#include <iostream>
#include "MyStack.h"

int main() {
    MyStack<int> st;

    st.push(10);
    st.push(20);
    st.push(10);
    st.push(30);
    st.push(10);

    std::cout << "Size: " << st.getSize() << std::endl; // 5
    std::cout << "Top: " << st.top() << std::endl; // 10

    std::cout << "isThere 20? " << st.isThere(20) << std::endl; // 1 = true
    std::cout << "isThere 99? " << st.isThere(99) << std::endl; // 0 = false

    MyStack<int> where = st.getWhere(10);
    std::cout << "Where is 10? positions (0=top): ";
    while (!where.isEmpty()) {
        std::cout << where.pop() << " ";
    }
    std::cout << std::endl;
    // Should print: 4 2 0  (10 is at top=0, middle=2, bottom=4)

    std::cout << "Pop all: ";
    while (!st.isEmpty()) {
        std::cout << st.pop() << " ";
    }
    std::cout << std::endl;

    return 0;
}