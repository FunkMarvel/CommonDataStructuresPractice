#pragma once

template<typename T>
struct Node
{
    Node* NextNode{nullptr};
    Node* PrevNode{nullptr};
    T Value{};

    Node();
    Node(T NewValue);
};

template <typename T>
Node<T>::Node()
{
    Value = T();
}

template <typename T>
Node<T>::Node(T NewValue)
{
    Value = NewValue;
}
