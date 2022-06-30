#pragma once

#include <algorithm>

template<typename T>
class StickyStack{
public:
    StickyStack();
    explicit StickyStack(int StackCapacity);
    StickyStack(int StackCapacity, T FirstElement);
    ~StickyStack();

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
StickyStack<T>::StickyStack() {
    CreateStack(4);
}

template<typename T>
StickyStack<T>::~StickyStack() {
    delete[] Data;
}

template<typename T>
void StickyStack<T>::Push(T NewValue) {
    if (IsFull()) throw std::runtime_error("Stack overflow!");
    Size++;
    Data[Size-1] = NewValue;
}

template<typename T>
T StickyStack<T>::Pop() {
    if(IsEmpty()) throw std::runtime_error("Stack underflow!");
    T PoppedElement{Data[Size-1]};
    Size--;
    return PoppedElement;
}

template<typename T>
T StickyStack<T>::Peek() {
    if (IsEmpty()) throw std::runtime_error("Stack underflow!");
    return Data[Size - 1];
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
    delete[] Data;
    Data = new T[StackCapacity];
    Capacity = StackCapacity;
    Size = 0;
}

template<typename T>
bool StickyStack<T>::Contains(T ElementToCheck) {

    for (int i = 0; i < Size; ++i) {
        if (Data[i] == ElementToCheck) return true;
    }

    return false;
}

template<typename T>
StickyStack<T>::StickyStack(int StackCapacity, T FirstElement) : StickyStack(StackCapacity) {
    Push(FirstElement);
}

template<typename T>
StickyStack<T>::StickyStack(int StackCapacity) {
    CreateStack(StackCapacity);
}

template<typename T>
int StickyStack<T>::GetSize() {
    return Size;
}

template<typename T>
int StickyStack<T>::GetCapacity() {
    return Capacity;
}
