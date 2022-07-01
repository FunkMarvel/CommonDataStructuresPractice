#pragma once

#include <algorithm>

template <typename T>
class Stack {
public:
    Stack();
    explicit Stack(int StackCapacity);
    Stack(int StackCapacity, T FirstElement);
    ~Stack();

    void CreateStack(int StackCapacity);
    void Push(T NewValue);
    T Pop();
    T Peek();
    [[nodiscard]] int GetSize() const;
    [[nodiscard]] int GetCapacity() const;

    [[nodiscard]] bool IsEmpty() const;
    [[nodiscard]] bool IsFull() const;
    [[nodiscard]] bool Contains(T ElementToCheck);

protected:
    T* Data_{nullptr};

    int Size_{};
    int Capacity_{};

};

template <typename T>
Stack<T>::Stack() {
    CreateStack(4);
}

template <typename T>
Stack<T>::~Stack() {
    delete[] Data_;
}

template <typename T>
void Stack<T>::Push(T NewValue) {
    if (IsFull()) throw std::runtime_error("Stack overflow!");
    Data_[Size_++] = NewValue;
}

template <typename T>
T Stack<T>::Pop() {
    if (IsEmpty()) throw std::runtime_error("Stack underflow!");
    return Data_[--Size_];
}

template <typename T>
T Stack<T>::Peek() {
    if (IsEmpty()) throw std::runtime_error("Stack underflow!");
    return Data_[Size_ - 1];
}

template <typename T>
bool Stack<T>::IsEmpty() const {
    return Size_ <= 0;
}

template <typename T>
bool Stack<T>::IsFull() const {
    return Size_ >= Capacity_;
}

template <typename T>
void Stack<T>::CreateStack(int StackCapacity) {
    if (StackCapacity < 1) throw std::runtime_error("Stack Capacity must be positive, non-zero integer");
    delete[] Data_;
    Data_ = new T[StackCapacity];
    Capacity_ = StackCapacity;
    Size_ = 0;
}

template <typename T>
bool Stack<T>::Contains(T ElementToCheck) {
    for (int I{}; I < Size_; ++I)
        if (Data_[I] == ElementToCheck) return true;

    return false;
}

template <typename T>
Stack<T>::Stack(int StackCapacity, T FirstElement) : Stack(StackCapacity) {
    Push(FirstElement);
}

template <typename T>
Stack<T>::Stack(const int StackCapacity) {
    CreateStack(StackCapacity);
}

template <typename T>
int Stack<T>::GetSize() const {
    return Size_;
}

template <typename T>
int Stack<T>::GetCapacity() const {
    return Capacity_;
}
