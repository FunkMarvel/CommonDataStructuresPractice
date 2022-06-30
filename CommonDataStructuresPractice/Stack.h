#pragma once

#include <algorithm>

template<typename T>
class Stack{
public:
    Stack();
    explicit Stack(int StackCapacity);
    Stack(int StackCapacity, T FirstElement);
    ~Stack();

    void CreateStack(int StackCapacity);
    void Push(T NewValue);
    T Pop();
    T Peek();
    int GetSize();
    int GetCapacity();

    [[nodiscard]] bool IsEmpty();
    [[nodiscard]] bool IsFull();
    [[nodiscard]] bool Contains(T ElementToCheck);

protected:
    T* Data{nullptr};

    int Size{};
    int Capacity{};

};

template<typename T>
Stack<T>::Stack() {
    CreateStack(4);
}

template<typename T>
Stack<T>::~Stack() {
    delete[] Data;
}

template<typename T>
void Stack<T>::Push(T NewValue) {
    if (IsFull()) throw std::runtime_error("Stack overflow!");
    Data[Size++] = NewValue;
}

template<typename T>
T Stack<T>::Pop() {
    if(IsEmpty()) throw std::runtime_error("Stack underflow!");
    return Data[--Size];
}

template<typename T>
T Stack<T>::Peek() {
    if (IsEmpty()) throw std::runtime_error("Stack underflow!");
    return Data[Size - 1];
}

template<typename T>
bool Stack<T>::IsEmpty() {
    return Size <= 0;
}

template<typename T>
bool Stack<T>::IsFull() {
    return Size >= Capacity;
}

template<typename T>
void Stack<T>::CreateStack(int StackCapacity) {
    if (StackCapacity < 1) throw std::runtime_error("Stack Capacity must be positive, non-zero integer");
    delete[] Data;
    Data = new T[StackCapacity];
    Capacity = StackCapacity;
    Size = 0;
}

template<typename T>
bool Stack<T>::Contains(T ElementToCheck) {
    for (int i = 0; i < Size; ++i) {
        if (Data[i] == ElementToCheck) return true;
    }

    return false;
}

template<typename T>
Stack<T>::Stack(int StackCapacity, T FirstElement) : Stack(StackCapacity) {
    Push(FirstElement);
}

template<typename T>
Stack<T>::Stack(int StackCapacity) {
    CreateStack(StackCapacity);
}

template<typename T>
int Stack<T>::GetSize() {
    return Size;
}

template<typename T>
int Stack<T>::GetCapacity() {
    return Capacity;
}
