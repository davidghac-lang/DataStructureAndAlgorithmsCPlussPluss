#include <iostream>
#include "../include/MyVector.h"
int main() {
    MyVector<int> v;
    v.push_back(30);
    v.push_back(10);
    v.push_back(20);
    v.push_back(5);
    v.push_back(25);
    
    std::cout << "Before sort: ";
    for (size_t i=0;i<v.size();++i) std::cout << v[i] << " ";
    std::cout << "\n";
    
    v.sort(); // QuickSort!
    
    std::cout << "After QuickSort: ";
    for (size_t i=0;i<v.size();++i) std::cout << v[i] << " ";
    std::cout << "\n";
    
    std::cout << "find(20): " << v.find(20) << "\n";
    std::cout << "binarySearch(20): " << v.binarySearch(20) << "\n";
    std::cout << "find(100): " << v.find(100) << " (not found)\n";
    return 0;
}
