#include <iostream>
#include "ArrayList.h"
#include "LinkedList.h"
#include "Queue.h"
#include "Stack.h"

void ArrayTest() {
    ArrayList<int> IntArray(4, 1);

    for (int I{}; I < IntArray.GetSize(); ++I)
        std::cout << IntArray[I] << " ";
    std::cout << std::endl << "Size = " << IntArray.GetSize() << std::endl;
    std::cout << "Capacity = " << IntArray.GetCapacity() << std::endl;

    IntArray.Append(3);

    for (int I{}; I < IntArray.GetSize(); ++I)
        std::cout << IntArray[I] << " ";
    std::cout << std::endl << "Size = " << IntArray.GetSize() << std::endl;
    std::cout << "Capacity = " << IntArray.GetCapacity() << std::endl;

    IntArray.Insert(0, 11);

    for (int I{}; I < IntArray.GetSize(); ++I)
        std::cout << IntArray[I] << " ";
    std::cout << std::endl << "Size = " << IntArray.GetSize() << std::endl;
    std::cout << "Capacity = " << IntArray.GetCapacity() << std::endl;

    IntArray.Remove();

    for (int I{}; I < IntArray.GetSize(); ++I)
        std::cout << IntArray[I] << " ";
    std::cout << std::endl << "Size = " << IntArray.GetSize() << std::endl;
    std::cout << "Capacity = " << IntArray.GetCapacity() << std::endl;

    IntArray.Remove(0);

    for (int I{}; I < IntArray.GetSize(); ++I)
        std::cout << IntArray[I] << " ";
    std::cout << std::endl << "Size = " << IntArray.GetSize() << std::endl;
    std::cout << "Capacity = " << IntArray.GetCapacity() << std::endl;
}

void LinkedListTest() {
    LinkedList<int> IntList{2, 1};
    for (int I{}; I < IntList.GetSize(); ++I)
        std::cout << IntList[I] << " ";
    std::cout << std::endl << "Size: " << IntList.GetSize() << std::endl;

    IntList.Append(3);

    for (int I{}; I < IntList.GetSize(); ++I)
        std::cout << IntList[I] << " ";
    std::cout << std::endl << "Size: " << IntList.GetSize() << std::endl;

    IntList.Insert(-5, 0);

    for (int I{}; I < IntList.GetSize(); ++I)
        std::cout << IntList[I] << " ";
    std::cout << std::endl << "Size: " << IntList.GetSize() << std::endl;

    IntList.Remove();

    for (int I{}; I < IntList.GetSize(); ++I)
        std::cout << IntList[I] << " ";
    std::cout << std::endl << "Size: " << IntList.GetSize() << std::endl;

    IntList.Remove();

    for (int I{}; I < IntList.GetSize(); ++I)
        std::cout << IntList[I] << " ";
    std::cout << std::endl << "Size: " << IntList.GetSize() << std::endl;

    IntList.Remove();

    for (int I{}; I < IntList.GetSize(); ++I)
        std::cout << IntList[I] << " ";
    std::cout << std::endl << "Size: " << IntList.GetSize() << std::endl;

    IntList.Remove();

    for (int I{}; I < IntList.GetSize(); ++I)
        std::cout << IntList[I] << " ";
    std::cout << std::endl << "Size: " << IntList.GetSize() << std::endl;

    IntList.Insert(0, 11);

    for (int I{}; I < IntList.GetSize(); ++I)
        std::cout << IntList[I] << " ";
    std::cout << std::endl << "Size: " << IntList.GetSize() << std::endl;

    LinkedList<int> PintList{1, 2, 3, 4, 5, 6, 7};
    for (int I{-10}; I <= 10; ++I)
        std::cout << PintList[I] << " ";
    std::cout << std::endl << "Size: " << PintList.GetSize() << std::endl;
}

void StackTest() {

    Stack<char> SomeStack(5, '/');

    std::cout << SomeStack.Pop() << std::endl;
    SomeStack.Push('*');
    std::cout << SomeStack.Pop() << std::endl;

    SomeStack.Push('/');
    SomeStack.Push('*');
    SomeStack.Push('-');
    SomeStack.Push('+');

    std::cout << std::boolalpha << "Stack contains '+': " << SomeStack.Contains('+') << std::endl;
    std::cout << "Stack contains '/': " << SomeStack.Contains('/') << std::endl;
    std::cout << "Stack contains '-': " << SomeStack.Contains('-') << std::endl;
    std::cout << "Stack contains '0': " << SomeStack.Contains('0') << std::endl;

    for (int _{}; SomeStack.GetSize() > 0; ++_)
        std::cout << SomeStack.Pop() << " ";
    std::cout << std::endl;

    SomeStack.CreateStack(10);
}

void QueueTest() {

    Queue<char> SomeQueue(5, '/');

    std::cout << SomeQueue.Pop() << std::endl;
    SomeQueue.Push('*');
    std::cout << SomeQueue.Pop() << std::endl;

    SomeQueue.Push('/');
    SomeQueue.Push('*');
    SomeQueue.Push('-');
    SomeQueue.Push('+');

    std::cout << std::boolalpha << "Queue contains '+': " << SomeQueue.Contains('+') << std::endl;
    std::cout << "Queue contains '/': " << SomeQueue.Contains('/') << std::endl;
    std::cout << "Queue contains '-': " << SomeQueue.Contains('-') << std::endl;
    std::cout << "Queue contains '0': " << SomeQueue.Contains('0') << std::endl;

    for (int _{}; SomeQueue.GetSize() > 0; ++_)
        std::cout << SomeQueue.Pop() << " ";
    std::cout << std::endl;

    SomeQueue.CreateQueue(10);
}

int main() {
    std::cout << "ArrayList: " << std::endl;
    ArrayTest();

    std::cout << "LinkedList: " << std::endl;
    LinkedListTest();

    std::cout << "Stack: " << std::endl;
    StackTest();

    std::cout << "Queue: " << std::endl;
    QueueTest();

    std::cout << "Dictionary: " << std::endl;


    return 0;
}
