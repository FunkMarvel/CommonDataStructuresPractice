#pragma once
#include <stdexcept>
#include <initializer_list>
#include <string>

/**
 * \brief Dynamic, contiguous array class
 * \tparam T datatype of elements
 */
template <typename T>
class ArrayList
{
public:
    ArrayList();
    explicit ArrayList(int NumElements, bool Uninitialized = false);
    ArrayList(int NumElements, T ElementToFill, bool Uninitialized = false);
    ArrayList(const ArrayList &OldObj);
    ArrayList(const ArrayList &&OldObj) noexcept;
    ArrayList(std::initializer_list<T> ArgList);

    ~ArrayList();

    T operator[](int Index);
    ArrayList& operator=(ArrayList OtherList);
    ArrayList& operator=(ArrayList&& OtherList) noexcept;
    
    int GetSize() const {return Size;}
    int GetCapacity() const {return Capacity;}

    void Append(T ElementToAppend);
    void Insert(int Index, T ElementToInsert);
    void Remove();
    void Remove(int Index);
    void Reserve(int NewCapacity);

protected:
    int GrowthFactor{2};
    int Capacity{1};
    int Size{0};

    T* Data{nullptr};

    void ReallocateData();
    void Resize();
    void ShrinkToFit();
};

/**
 * \brief Creates empty ArrayList.
 */
template <typename T>
ArrayList<T>::ArrayList()
{
    Data = new T[Capacity];
    Size = 0;
}

template <typename T>
ArrayList<T>::ArrayList(const int NumElements, bool Uninitialized)
{
    Capacity = Size = NumElements;
    Data = new T[Capacity];
    if (Uninitialized) return;
    
    for (int i = 0; i < Size; ++i)
    {
        Data[i] = T();
    }
}

template <typename T>
ArrayList<T>::ArrayList(int NumElements, T ElementToFill, bool Uninitialized) : ArrayList<T>(NumElements)
{
    for (int i = 0; i < NumElements; ++i)
    {
        Data[i] = ElementToFill;
    }
}

template <typename T>
ArrayList<T>::ArrayList(const ArrayList& OldObj)
{
    Capacity = OldObj.Capacity;
    Size = OldObj.Size;
    Data = new T[Capacity];
    
    for (int i = 0; i < Size; ++i)
    {
        Data[i] = OldObj.Data[i];
    }
}

template <typename T>
ArrayList<T>::ArrayList(const ArrayList&& OldObj) noexcept
{
    Capacity = OldObj.Capacity;
    Size = OldObj.Size;
    Data = OldObj.Data;

    OldObj.Capacity = 1;
    OldObj.Size = 0;
    OldObj.Data = nullptr;
}

template <typename T>
ArrayList<T>::~ArrayList()
{
    delete[] Data;
}

template <typename T>
T ArrayList<T>::operator[](int Index)
{
    if (Index >= Size || Index < 0)
    {
        throw std::runtime_error("Index " + std::to_string(Index) + " out of range!");
    }
    return Data[Index];
}

template <typename T>
ArrayList<T>& ArrayList<T>::operator=(ArrayList OtherList)
{
    Capacity = OtherList.Capacity;
    Size = OtherList.Size;
    delete[] Data;
    Data = new T[Capacity];
    for (int i = 0; i < Size; ++i)
    {
        Data[i] = OtherList.Data[i];
    }
    return *this;
}

template <typename T>
ArrayList<T>& ArrayList<T>::operator=(ArrayList&& OtherList) noexcept
{
    if (this == OtherList) return *this;
    Capacity = OtherList.Capacity;
    Size = OtherList.Size;
    delete[] Data;
    Data = OtherList.Data;
    return *this;
}

template <typename T>
void ArrayList<T>::Append(T ElementToAppend)
{
    if (Capacity < Size + 1)
    {
        Capacity *= GrowthFactor;
        ReallocateData();
    }
    Data[Size++] = ElementToAppend;
    ShrinkToFit();
}

template <typename T>
void ArrayList<T>::Insert(int Index, T ElementToInsert)
{
    if (Index > Size) throw std::runtime_error("Index " + std::to_string(Index) + " out of range!");
    if (Index == Size) Append(ElementToInsert);
    if (Capacity < Size + 1)
    {
        Capacity *= GrowthFactor;
    }

    T* TempData = new T[Capacity];
    for (int i = 0; i < Index; ++i)
    {
        TempData[i] = Data[i];
    }
    TempData[Index] = ElementToInsert;
    for (int i = Index; i < Size; ++i)
    {
        TempData[i + 1] = Data[i];
    }
    Size++;
    delete[] Data;
    Data = TempData;
    ShrinkToFit();
}

template <typename T>
void ArrayList<T>::Remove()
{
    Size--;
    ShrinkToFit();
}

template <typename T>
void ArrayList<T>::Remove(int Index)
{
    if (Index >= Size) throw std::runtime_error("Index " + std::to_string(Index) + " out of range!");
    if (Index == Size - 1) Remove();

    T* TempData = new T[Capacity];
    for (int i = 0; i < Index; ++i)
    {
        TempData[i] = Data[i];
    }
    for (int i = Index; i < Size - 1; ++i)
    {
        TempData[i] = Data[i + 1];
    }
    delete[] Data;
    Data = TempData;
    Size--;
    ShrinkToFit();
}

template <typename T>
void ArrayList<T>::ReallocateData()
{
    T* TempData = new T[Capacity];
    for (int i = 0; i < Size; ++i)
    {
        TempData[i] = Data[i];
    }
    delete[] Data;
    Data = TempData;
}

template <typename T>
void ArrayList<T>::Resize()
{
    Capacity *= GrowthFactor;
    ReallocateData();
}

template <typename T>
void ArrayList<T>::ShrinkToFit()
{
    if (Size > Capacity / 2) return;
    Capacity /= 2;
    ReallocateData();
}

template <typename T>
void ArrayList<T>::Reserve(int NewCapacity)
{
    if (Capacity >= NewCapacity) return;
    Capacity = NewCapacity;
    ReallocateData();
}

template<typename T>
ArrayList<T>::ArrayList(std::initializer_list<T> ArgList) : ArrayList(ArgList.size()) {
    std::copy(ArgList.begin(), ArgList.end(), Data);
}
