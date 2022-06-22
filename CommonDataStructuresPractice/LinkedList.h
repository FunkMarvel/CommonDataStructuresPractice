#pragma once
#include <stdexcept>
#include <string>
#include <cmath>

#include "Node.h"

template <typename T>
class LinkedList
{
public:
    LinkedList();
    LinkedList(T HeadValue);

    ~LinkedList();

    void Append(T NewElement);
    void Insert(int Index, T NewElement);
    void Remove();
    void Remove(int Index);

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
LinkedList<T>::LinkedList(T HeadValue)
{
    Head = Tail = CurrentNode = new Node<T>(HeadValue);
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
    Head = Tail = CurrentNode = nullptr;
    Size = 0;
}

template <typename T>
void LinkedList<T>::Append(T NewElement)
{
    Tail->NextNode = new Node<T>(NewElement);
    Head->PrevNode = Tail;
    Size++;
}

template <typename T>
void LinkedList<T>::Insert(int Index, T NewElement)
{
    if (Index == Size || Index == -Size) Index = 0;
    CurrentNode = Head;
    Index = RolloverIndex(Index);
    for (int i = 1; i < Index - 1; ++i)
    {
            CurrentNode = CurrentNode->NextNode;
    }

    auto NewNode = new Node<T>(NewElement);
    auto TempNode = CurrentNode->NextNode;
    CurrentNode->NextNode = NewNode;

    NewNode->PrevNode = CurrentNode;
    NewNode->NextNode = TempNode;

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
    for (int i = 0; i < Index - 1; ++i)
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
