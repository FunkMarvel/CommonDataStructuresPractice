#pragma once

#include <stdexcept>

/**
 * \brief Queue.
 * \tparam T chosen datatype.
 */
template <typename T>
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
    [[nodiscard]] bool IsEmpty() const;
    [[nodiscard]] bool IsFull() const;
    [[nodiscard]] bool Contains(T ElementToCheck);

    [[nodiscard]] int GetSize() const;
    [[nodiscard]] int GetCapacity() const;
    void CreateQueue(int QueueCapacity);

protected:
    T* Data_{nullptr};
    int Capacity_{};
    int Size_{};
};

template <typename T>
Queue<T>::Queue() {
    Data_ = new T[4];
}

template <typename T>
Queue<T>::Queue(const int QueueCapacity) {
    CreateQueue(QueueCapacity);
}

template <typename T>
Queue<T>::Queue(const int QueueCapacity, T FirstElement) {
    CreateQueue(QueueCapacity);
    Push(FirstElement);
}

template <typename T>
Queue<T>::~Queue() {
    delete[] Data_;
}

template <typename T>
void Queue<T>::Push(T NewElement) {
    if (IsFull()) throw std::runtime_error("Queue overflow!");
    Data_[Size_++] = NewElement;
}

template <typename T>
T Queue<T>::Pop() {
    if (IsEmpty()) throw std::runtime_error("Queue underflow!");
    auto PoppedElement = Data_[0];
    for (auto I{1}; I < Size_; ++I)
        Data_[I - 1] = Data_[I];
    Size_--;
    return PoppedElement;
}

template <typename T>
T Queue<T>::PeekHead() {
    if (IsEmpty()) throw std::runtime_error("Queue underflow!");
    return Data_[Size_ - 1];
}

template <typename T>
T Queue<T>::PeekTail() {
    if (IsEmpty()) throw std::runtime_error("Queue underflow!");
    return Data_[0];
}

template <typename T>
bool Queue<T>::IsEmpty() const {
    return Size_ <= 0;
}

template <typename T>
bool Queue<T>::IsFull() const {
    return Size_ >= Capacity_;
}

template <typename T>
bool Queue<T>::Contains(T ElementToCheck) {
    for (int I{}; I < Size_; ++I)
        if (Data_[I] == ElementToCheck) return true;

    return false;
}

template <typename T>
int Queue<T>::GetSize() const {
    return Size_;
}

template <typename T>
int Queue<T>::GetCapacity() const {
    return Capacity_;
}

template <typename T>
void Queue<T>::CreateQueue(const int QueueCapacity) {
    Capacity_ = QueueCapacity;
    delete[] Data_;
    Data_ = new T[Capacity_];
}
