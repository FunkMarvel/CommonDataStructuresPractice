#pragma once
#include <stdexcept>
#include <string>
#include <cmath>
#include <initializer_list>

#include "Node.h"

template <typename T>
class LinkedList
{
public:
    LinkedList();
    LinkedList(std::initializer_list<T> ArgList);

    ~LinkedList();

    T& operator[](int Index);

    void Append(T NewElement);
    void Insert(int Index, T NewElement);
    void Remove();
    void Remove(int Index);

    int GetSize() { return Size; }

protected:
    Node<T>* Head{nullptr};
    Node<T>* Tail{nullptr};
    Node<T>* CurrentNode{nullptr};

    int Size{};
    int RolloverIndex(int Index);
};

template <typename T>
LinkedList<T>::LinkedList()
{
    Head = Tail = CurrentNode = new Node<T>();
    Size = 1;
}

template <typename T>
LinkedList<T>::~LinkedList()
{
    CurrentNode = Head;
    for (int i = 0; i < Size; ++i)
    {
        auto TempNode = CurrentNode->NextNode;
        delete CurrentNode;
        CurrentNode = TempNode;
    }
}

template <typename T>
void LinkedList<T>::Append(T NewElement)
{
    if (Size < 1) {
        Head = Tail = new Node<T>(NewElement);
        Head->NextNode = Head->PrevNode = Tail;
        Tail->NextNode = Tail->PrevNode = Head;
        Size++;
        return;
    }
    Tail->NextNode = new Node<T>(NewElement);
    Tail->NextNode->PrevNode = Tail;

    Tail = Tail->NextNode;
    Tail->NextNode = Head;
    Head->PrevNode = Tail;
    Size++;
}

template <typename T>
void LinkedList<T>::Insert(int Index, T NewElement)
{
    if (Size < 1) { Append(NewElement); return; }
    if (Index == Size || Index == -Size) Index = 0;
    CurrentNode = Head;
    Index = RolloverIndex(Index);
    for (int i = 0; i < Index; ++i)
    {
            CurrentNode = CurrentNode->NextNode;
    }

    auto TempNode = CurrentNode;
    CurrentNode = new Node<T>(NewElement);
    CurrentNode->NextNode = TempNode;
    CurrentNode->PrevNode = TempNode->PrevNode;
    CurrentNode->PrevNode->NextNode = CurrentNode;
    TempNode->PrevNode = CurrentNode;

    CurrentNode = nullptr;
    Size++;
}

template <typename T>
void LinkedList<T>::Remove()
{
    if(Size > 1)
    {
        auto TempNode = Tail->PrevNode;
        delete Tail;
        Tail = TempNode;
        Tail->NextNode = Head;
        Size--;
        return;
    }

    delete Head, Tail, CurrentNode;
    Head = Tail = CurrentNode = nullptr;
    Size = 0;
}

template <typename T>
void LinkedList<T>::Remove(int Index)
{
    if (Index == Size || Index == -Size) Index = 0;
    Index = RolloverIndex(Index);
    CurrentNode = Head;
    for (int i = 0; i < Index; ++i)
    {
        CurrentNode = CurrentNode->NextNode;
    }
    auto TempNode = CurrentNode->NextNode->NextNode;
    delete CurrentNode->NextNode;
    CurrentNode->NextNode = TempNode;
}

template <typename T>
int LinkedList<T>::RolloverIndex(int Index)
{
    if (Index == 0) return 0;
    if (Index > 0) return (Index % Size); 

    return Size - (std::abs(Index) % Size);
}

template<typename T>
T &LinkedList<T>::operator[](int Index) {
    if (Index == 0) return Head->Value;
    Index = RolloverIndex(Index);
    CurrentNode = Head;
    for (int i = 0; i < Index; ++i) {
        CurrentNode = CurrentNode->NextNode;
    }
    return CurrentNode->Value;
}

template<typename T>
LinkedList<T>::LinkedList(std::initializer_list<T> ArgList) {
    Size = ArgList.size();
    Head = Tail = CurrentNode = new Node<T>(*(ArgList.begin()));
    for (int i = 1; i < Size; ++i) {
        CurrentNode->NextNode = new Node<T>(*(ArgList.begin() + i));
        CurrentNode->NextNode->PrevNode = CurrentNode;
        CurrentNode = CurrentNode->NextNode;
    }
    Tail = CurrentNode;
    Tail->NextNode = Head;
    Head->PrevNode = Tail;
}
