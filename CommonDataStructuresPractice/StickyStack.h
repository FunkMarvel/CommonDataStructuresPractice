#pragma once

#include <algorithm>

template<typename T>
class StickyStack{
public:
    StickyStack();
    ~StickyStack();

    void CreateStack(int StackCapacity);
    void Push(T NewValue);
    T Pop();
    T Peek();

    [[nodiscard]] bool IsEmpty();
    [[nodiscard]] bool IsFull();
    [[nodiscard]] bool Contains(T ElementToCheck);

protected:
    T* Data{nullptr};

    int Top{};
    int Capacity{1};
    int Size{};

};

template<typename T>
StickyStack<T>::StickyStack() {
    CreateStack(Capacity);
}

template<typename T>
StickyStack<T>::~StickyStack() {
    delete[] Data;
}

template<typename T>
void StickyStack<T>::Push(T NewValue) {
    if (IsFull()) throw std::runtime_error("Stack overflow!");
    Data[Top++] = NewValue;
}

template<typename T>
T StickyStack<T>::Pop() {
    return nullptr;
}

template<typename T>
T StickyStack<T>::Peek() {
    return Data[Top];
}

template<typename T>
bool StickyStack<T>::IsEmpty() {
    return Size == 0;
}

template<typename T>
bool StickyStack<T>::IsFull() {
    return Size >= Capacity;
}

template<typename T>
void StickyStack<T>::CreateStack(int StackCapacity) {
    if (StackCapacity < 1) throw std::runtime_error("Stack Capacity must be positive, non-zero integer");
    Data = new T[StackCapacity];
    Top = 0;
}

template<typename T>
bool StickyStack<T>::Contains(T ElementToCheck) {

    T* FoundElement = std::find(std::begin(Data), std::end(Data), ElementToCheck);
    if (FoundElement != std::end(Data)) return true;

    return false;
}
