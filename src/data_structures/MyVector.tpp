#include <stdexcept>

template <typename T>
MyVector<T>::MyVector() : data(nullptr), sz(0), cap(0) {}

template <typename T>
MyVector<T>::MyVector(size_t initial_capacity) : sz(0), cap(initial_capacity) {
    data = new T[cap];
}

template <typename T>
MyVector<T>::~MyVector() {
    delete[] data;
}

template <typename T>
void MyVector<T>::resize(size_t new_cap) {
    T* new_data = new T[new_cap];
    for (size_t i = 0; i < sz; ++i) {
        new_data[i] = data[i];
    }
    delete[] data;
    data = new_data;
    cap = new_cap;
}

template <typename T>
void MyVector<T>::push_back(const T& value) {
    if (sz == cap) {
        size_t new_cap = (cap == 0) ? 1 : cap * 2;
        resize(new_cap);
    }
    data[sz++] = value;
}

template <typename T>
void MyVector<T>::pop_back() {
    if (sz > 0) sz--;
}

template <typename T>
T& MyVector<T>::operator[](size_t index) {
    if (index >= sz) throw std::out_of_range("Index out of range");
    return data[index];
}

template <typename T>
const T& MyVector<T>::operator[](size_t index) const {
    if (index >= sz) throw std::out_of_range("Index out of range");
    return data[index];
}

template <typename T>
size_t MyVector<T>::size() const { return sz; }

template <typename T>
size_t MyVector<T>::capacity() const { return cap; }

template <typename T>
bool MyVector<T>::empty() const { return sz == 0; }

template <typename T>
void MyVector<T>::clear() { sz = 0; }

template <typename T>
int MyVector<T>::partition(int low, int high) {
    T pivot = data[high];
    int i = low - 1;
    for (int j = low; j < high; ++j) {
        if (data[j] <= pivot) {
            ++i;
            T tmp = data[i];
            data[i] = data[j];
            data[j] = tmp;
        }
    }
    T tmp = data[i + 1];
    data[i + 1] = data[high];
    data[high] = tmp;
    return i + 1;
}

template <typename T>
void MyVector<T>::quickSortHelper(int low, int high) {
    if (low < high) {
        int pi = partition(low, high);
        quickSortHelper(low, pi - 1);
        quickSortHelper(pi + 1, high);
    }
}

template <typename T>
void MyVector<T>::sort() {
    if (sz > 1) {
        quickSortHelper(0, static_cast<int>(sz) - 1);
    }
}

template <typename T>
void MyVector<T>::sortQuick() {
    sort();
}

template <typename T>
int MyVector<T>::find(const T& value) const {
    for (size_t i = 0; i < sz; ++i) {
        if (data[i] == value) return static_cast<int>(i);
    }
    return -1;
}

template <typename T>
int MyVector<T>::binarySearch(const T& value) const {
    int left = 0;
    int right = static_cast<int>(sz) - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (data[mid] == value) return mid;
        if (data[mid] < value) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}
