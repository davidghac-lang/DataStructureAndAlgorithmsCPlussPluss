#ifndef MY_VECTOR_H
#define MY_VECTOR_H
#include <cstddef>
template <typename T> class MyVector {
private:
    T* data;
    size_t sz;
    size_t cap;
    void resize(size_t new_cap);
    int partition(int low, int high);
    void quickSortHelper(int low, int high);
public:
    MyVector();
    explicit MyVector(size_t initial_capacity);
    ~MyVector();
    void push_back(const T& value);
    void pop_back();
    T& operator[](size_t index);
    const T& operator[](size_t index) const;
    size_t size() const;
    size_t capacity() const;
    bool empty() const;
    void clear();
    int find(const T& value) const;
    int binarySearch(const T& value) const;
    void sort();
    void sortQuick();
};
#include "../src/data_structures/MyVector.tpp" 
#endif