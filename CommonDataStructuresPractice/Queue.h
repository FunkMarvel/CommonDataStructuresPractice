#pragma once

#include <initializer_list>
#include <stdexcept>

template<typename T>
class Queue {
public:
    Queue();
    explicit Queue(int QueueCapacity);
    Queue(int QueueCapacity, T FirstElement);
    ~Queue();

    void Push(T NewElement);
    T Pop();
    T PeekHead();
    T PeekTail();
    [[nodiscard]] bool IsEmpty();
    [[nodiscard]] bool IsFull();
    [[nodiscard]] bool Contains(T ElementToCheck);

    int GetSize();
    int GetCapacity();
    void CreateQueue(int QueueCapacity);

protected:
    T* Data{nullptr};
    int Capacity{};
    int Size{};
};

template<typename T>
Queue<T>::Queue() {
    Data = new T[4];
}

template<typename T>
Queue<T>::Queue(int QueueCapacity) {
    CreateQueue(QueueCapacity);
}

template<typename T>
Queue<T>::Queue(int QueueCapacity, T FirstElement) {
    CreateQueue(QueueCapacity);
    Push(FirstElement);
}

template<typename T>
Queue<T>::~Queue() {
    delete[] Data;
}

template<typename T>
void Queue<T>::Push(T NewElement) {
    if (IsFull()) throw std::runtime_error("Queue overflow!");
    Data[Size++] = NewElement;
}

template<typename T>
T Queue<T>::Pop() {
    if (IsEmpty()) throw std::runtime_error("Queue underflow!");
    return Data[--Size];
}

template<typename T>
T Queue<T>::PeekHead() {
    if (IsEmpty()) throw std::runtime_error("Queue underflow!");
    return Data[Size-1];
}

template<typename T>
T Queue<T>::PeekTail() {
    if (IsEmpty()) throw std::runtime_error("Queue underflow!");
    return Data[0];
}

template<typename T>
bool Queue<T>::IsEmpty() {
    return Size <= 0;
}

template<typename T>
bool Queue<T>::IsFull() {
    return Size >= Capacity;
}

template<typename T>
bool Queue<T>::Contains(T ElementToCheck) {
    for (int i = 0; i < Size; ++i) {
        if (Data[i] == ElementToCheck) return true;
    }

    return false;
}

template<typename T>
int Queue<T>::GetSize() {
    return Size;
}

template<typename T>
int Queue<T>::GetCapacity() {
    return Capacity;
}

template<typename T>
void Queue<T>::CreateQueue(int QueueCapacity) {
    Capacity = QueueCapacity;
    delete[] Data;
    Data = new T[Capacity];
}
