#include "ArrayList.h"
#include "LinkedList.h"
#include "StickyStack.h"
#include <iostream>
#include <string>

void ArrayTest() {
    ArrayList<int> IntArray(4, 1);

    for (int i = 0; i < IntArray.GetSize(); ++i)
    {
        std::cout << IntArray[i] << " ";
    }
    std::cout << std::endl << "Size = " << IntArray.GetSize() << std::endl;
    std::cout << "Capacity = " << IntArray.GetCapacity() << std::endl;

    IntArray.Append(3);

    for (int i = 0; i < IntArray.GetSize(); ++i)
    {
        std::cout << IntArray[i] << " ";
    }
    std::cout << std::endl << "Size = " << IntArray.GetSize() << std::endl;
    std::cout << "Capacity = " << IntArray.GetCapacity() << std::endl;

    IntArray.Insert(0, 11);

    ArrayList<int> IntArrayCopy(IntArray);

    for (int i = 0; i < IntArray.GetSize(); ++i)
    {
        std::cout << IntArray[i] << " ";
    }
    std::cout << std::endl << "Size = " << IntArray.GetSize() << std::endl;
    std::cout << "Capacity = " << IntArray.GetCapacity() << std::endl;

    IntArray.Remove();

    for (int i = 0; i < IntArray.GetSize(); ++i)
    {
        std::cout << IntArray[i] << " ";
    }
    std::cout << std::endl << "Size = " << IntArray.GetSize() << std::endl;
    std::cout << "Capacity = " << IntArray.GetCapacity() << std::endl;

    IntArray.Remove(0);

    for (int i = 0; i < IntArray.GetSize(); ++i)
    {
        std::cout << IntArray[i] << " ";
    }
    std::cout << std::endl << "Size = " << IntArray.GetSize() << std::endl;
    std::cout << "Capacity = " << IntArray.GetCapacity() << std::endl;

    for (int i = 0; i < IntArrayCopy.GetSize(); ++i)
    {
        std::cout << IntArrayCopy[i] << " ";
    }
    std::cout << std::endl << "Size = " << IntArrayCopy.GetSize() << std::endl;
    std::cout << "Capacity = " << IntArrayCopy.GetCapacity() << std::endl;
}

void LinkedListTest() {
    LinkedList<int> IntList{2, 1};
    for (int i = 0; i < IntList.GetSize(); ++i) {
        auto Temp = IntList[i];
        std::cout << Temp << " ";
    }
    std::cout << std::endl << "Size: " << IntList.GetSize() << std::endl;

    IntList.Append(3);

    for (int i = 0; i < IntList.GetSize(); ++i) {
        auto Temp = IntList[i];
        std::cout << Temp << " ";
    }
    std::cout << std::endl << "Size: " << IntList.GetSize() << std::endl;

    IntList.Insert(-5, 0);

    for (int i = 0; i < IntList.GetSize(); ++i) {
        auto Temp = IntList[i];
        std::cout << Temp << " ";
    }
    std::cout << std::endl << "Size: " << IntList.GetSize() << std::endl;

    IntList.Remove();

    for (int i = 0; i < IntList.GetSize(); ++i) {
        auto Temp = IntList[i];
        std::cout << Temp << " ";
    }
    std::cout << std::endl << "Size: " << IntList.GetSize() << std::endl;

    IntList.Remove();

    for (int i = 0; i < IntList.GetSize(); ++i) {
        auto Temp = IntList[i];
        std::cout << Temp << " ";
    }
    std::cout << std::endl << "Size: " << IntList.GetSize() << std::endl;

    IntList.Remove();

    for (int i = 0; i < IntList.GetSize(); ++i) {
        auto Temp = IntList[i];
        std::cout << Temp << " ";
    }
    std::cout << std::endl << "Size: " << IntList.GetSize() << std::endl;

    IntList.Remove();

    for (int i = 0; i < IntList.GetSize(); ++i) {
        auto Temp = IntList[i];
        std::cout << Temp << " ";
    }
    std::cout << std::endl << "Size: " << IntList.GetSize() << std::endl;

    IntList.Insert(0,11);

    for (int i = 0; i < IntList.GetSize(); ++i) {
        auto Temp = IntList[i];
        std::cout << Temp << " ";
    }
    std::cout << std::endl << "Size: " << IntList.GetSize() << std::endl;

    LinkedList<int> PintList{1,2,3,4,5,6,7};
    for (int i = -10; i < 10; ++i) {
        std::cout <<  PintList[i] << " ";
    }
    std::cout << std::endl << "Size: " << PintList.GetSize() << std::endl;
}

void StackTest() {

    StickyStack<char> stack(5, '/');

    std::cout << stack.Pop() << std::endl;
    stack.Push('*');
    std::cout << stack.Pop() << std::endl;

    stack.Push('/');
    stack.Push('*');
    stack.Push('-');
    stack.Push('+');

    std::cout << std::boolalpha << "Stack contains '+': " << stack.Contains('+') << std::endl;
    std::cout << "Stack contains '/': " << stack.Contains('/') << std::endl;
    std::cout << "Stack contains '-': " << stack.Contains('-') << std::endl;
    std::cout << "Stack contains '0': " << stack.Contains('0') << std::endl;

    for (int _{}; stack.GetSize() > 0; ++_) {
        std::cout << stack.Pop() << " ";
    }
    std::cout << std::endl;

    stack.CreateStack(10);
}

int main(int argc, char* argv[])
{
    ArrayTest();
    LinkedListTest();
    StackTest();
    
    return 0;
}
