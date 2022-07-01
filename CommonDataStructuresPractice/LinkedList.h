#pragma once
#include <cmath>
#include <initializer_list>

#include "Node.h"

/**
 * \brief Doubly linked, looping list.
 * \tparam T Chosen datatype.
 */
template <typename T>
class LinkedList {
public:
    LinkedList();
    LinkedList(std::initializer_list<T> ArgList);

    ~LinkedList();

    T& operator[](int Index);

    void Append(T NewElement);
    void Insert(int Index, T NewElement);
    void Remove();
    void Remove(int Index);

    [[nodiscard]] int GetSize() const;

protected:
    Node<T>* Head_{nullptr};
    Node<T>* Tail_{nullptr};
    Node<T>* CurrentNode_{nullptr};

    int Size_{};
    [[nodiscard]] int RolloverIndex(int Index) const;
};

template <typename T>
LinkedList<T>::LinkedList() {
    Head_ = Tail_ = CurrentNode_ = new Node<T>();
    Size_ = 1;
}

template <typename T>
LinkedList<T>::~LinkedList() {
    CurrentNode_ = Head_;
    for (int I{}; I < Size_; ++I) {
        auto TempNode = CurrentNode_->NextNode;
        delete CurrentNode_;
        CurrentNode_ = TempNode;
    }
}

template <typename T>
void LinkedList<T>::Append(T NewElement) {
    if (Size_ < 1) {
        Head_ = Tail_ = new Node<T>(NewElement);
        Head_->NextNode = Head_->PrevNode = Tail_;
        Tail_->NextNode = Tail_->PrevNode = Head_;
        Size_++;
        return;
    }
    Tail_->NextNode = new Node<T>(NewElement);
    Tail_->NextNode->PrevNode = Tail_;

    Tail_ = Tail_->NextNode;
    Tail_->NextNode = Head_;
    Head_->PrevNode = Tail_;
    Size_++;
}

template <typename T>
void LinkedList<T>::Insert(int Index, T NewElement) {
    if (Size_ < 1) {
        Append(NewElement);
        return;
    }
    if (Index == Size_ || Index == -Size_) Index = 0;
    CurrentNode_ = Head_;
    Index = RolloverIndex(Index);
    for (int I{}; I < Index; ++I)
        CurrentNode_ = CurrentNode_->NextNode;

    auto TempNode = CurrentNode_;
    CurrentNode_ = new Node<T>(NewElement);
    CurrentNode_->NextNode = TempNode;
    CurrentNode_->PrevNode = TempNode->PrevNode;
    CurrentNode_->PrevNode->NextNode = CurrentNode_;
    TempNode->PrevNode = CurrentNode_;

    CurrentNode_ = nullptr;
    Size_++;
}

template <typename T>
void LinkedList<T>::Remove() {
    if (Size_ > 1) {
        auto TempNode = Tail_->PrevNode;
        delete Tail_;
        Tail_ = TempNode;
        Tail_->NextNode = Head_;
        Size_--;
        return;
    }

    delete Head_;
    Head_ = Tail_ = CurrentNode_ = nullptr;
    Size_ = 0;
}

template <typename T>
void LinkedList<T>::Remove(int Index) {
    if (Index == Size_ || Index == -Size_) Index = 0;
    Index = RolloverIndex(Index);
    CurrentNode_ = Head_;
    for (int I{}; I < Index; ++I)
        CurrentNode_ = CurrentNode_->NextNode;
    auto TempNode = CurrentNode_->NextNode->NextNode;
    delete CurrentNode_->NextNode;
    CurrentNode_->NextNode = TempNode;
}

template <typename T>
int LinkedList<T>::GetSize() const { return Size_; }

template <typename T>
int LinkedList<T>::RolloverIndex(const int Index) const {
    if (Index == 0) return 0;
    if (Index > 0) return (Index % Size_);

    return Size_ - (std::abs(Index) % Size_);
}

template <typename T>
T& LinkedList<T>::operator[](int Index) {
    if (Index == 0) return Head_->Value;
    Index = RolloverIndex(Index);
    CurrentNode_ = Head_;
    for (int I{}; I < Index; ++I)
        CurrentNode_ = CurrentNode_->NextNode;
    return CurrentNode_->Value;
}

template <typename T>
LinkedList<T>::LinkedList(std::initializer_list<T> ArgList) {
    Size_ = static_cast<int>(ArgList.size());
    Head_ = Tail_ = CurrentNode_ = new Node<T>(*(ArgList.begin()));
    for (int I{}; I < Size_; ++I) {
        CurrentNode_->NextNode = new Node<T>(*(ArgList.begin() + I));
        CurrentNode_->NextNode->PrevNode = CurrentNode_;
        CurrentNode_ = CurrentNode_->NextNode;
    }
    Tail_ = CurrentNode_;
    Tail_->NextNode = Head_;
    Head_->PrevNode = Tail_;
}
