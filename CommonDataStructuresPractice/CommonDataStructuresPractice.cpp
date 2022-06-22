#include "ArrayList.h"
#include <iostream>

int main(int argc, char* argv[])
{
    ArrayList<int> IntArray{4, 1};
    
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
    
    return 0;
}
