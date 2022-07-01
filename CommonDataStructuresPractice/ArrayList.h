#pragma once
#include <initializer_list>
#include <stdexcept>
#include <string>

/**
 * \brief Dynamic, contiguous array class
 * \tparam T datatype of elements
 */
template <typename T>
class ArrayList {
public:
    ArrayList();
    explicit ArrayList(int NumElements, bool Uninitialized = false);
    ArrayList(int NumElements, T ElementToFill, bool Uninitialized = false);
    ArrayList(std::initializer_list<T> ArgList);

    ~ArrayList();

    T operator[](int Index);
    ArrayList& operator=(ArrayList OtherList);
    ArrayList& operator=(ArrayList&& OtherList) noexcept;

    [[nodiscard]] int GetSize() const;
    [[nodiscard]] int GetCapacity() const;

    void Append(T ElementToAppend);
    void Insert(int Index, T ElementToInsert);
    void Remove();
    void Remove(int Index);
    void Reserve(int NewCapacity);

protected:
    int GrowthFactor_{2};
    int Capacity_{1};
    int Size_{0};

    T* Data_{nullptr};

    void ReallocateData();
    void Resize();
    void ShrinkToFit();
};

/**
 * \brief Creates empty ArrayList.
 */
template <typename T>
ArrayList<T>::ArrayList() {
    Data_ = new T[Capacity_];
    Size_ = 0;
}

template <typename T>
ArrayList<T>::ArrayList(const int NumElements, const bool Uninitialized) {
    Capacity_ = Size_ = NumElements;
    Data_ = new T[Capacity_];
    if (Uninitialized) return;

    for (int I{}; I < Size_; ++I)
        Data_[I] = T();
}

template <typename T>
ArrayList<T>::ArrayList(int NumElements, T ElementToFill, bool Uninitialized) : ArrayList<T>(NumElements) {
    for (int I{}; I < Size_; ++I)
        Data_[I] = ElementToFill;
}

template <typename T>
ArrayList<T>::~ArrayList() {
    delete[] Data_;
}

template <typename T>
T ArrayList<T>::operator[](int Index) {
    if (Index >= Size_ || Index < 0)
        throw std::runtime_error("Index " + std::to_string(Index) + " out of range!");
    return Data_[Index];
}

template <typename T>
ArrayList<T>& ArrayList<T>::operator=(ArrayList OtherList) {
    Capacity_ = OtherList.Capacity_;
    Size_ = OtherList.Size_;
    delete[] Data_;
    Data_ = new T[Capacity_];
    for (auto I{}; I < Size_; ++I)
        Data_[I] = OtherList.Data_[I];
    return *this;
}

template <typename T>
ArrayList<T>& ArrayList<T>::operator=(ArrayList&& OtherList) noexcept {
    if (this == OtherList) return *this;
    Capacity_ = OtherList.Capacity_;
    Size_ = OtherList.Size_;
    delete[] Data_;
    Data_ = OtherList.Data_;
    return *this;
}

template <typename T>
int ArrayList<T>::GetSize() const { return Size_; }

template <typename T>
int ArrayList<T>::GetCapacity() const { return Capacity_; }

template <typename T>
void ArrayList<T>::Append(T ElementToAppend) {
    if (Capacity_ < Size_ + 1) {
        Capacity_ *= GrowthFactor_;
        ReallocateData();
    }
    Data_[Size_++] = ElementToAppend;
    ShrinkToFit();
}

template <typename T>
void ArrayList<T>::Insert(int Index, T ElementToInsert) {
    if (Index > Size_) throw std::runtime_error("Index " + std::to_string(Index) + " out of range!");
    if (Index == Size_) Append(ElementToInsert);
    if (Capacity_ < Size_ + 1)
        Capacity_ *= GrowthFactor_;

    T* TempData = new T[Capacity_];
    for (int I{}; I < Index; ++I)
        TempData[I] = Data_[I];
    TempData[Index] = ElementToInsert;
    for (int I = Index; I < Size_; ++I)
        TempData[I + 1] = Data_[I];
    Size_++;
    delete[] Data_;
    Data_ = TempData;
    ShrinkToFit();
}

template <typename T>
void ArrayList<T>::Remove() {
    Size_--;
    ShrinkToFit();
}

template <typename T>
void ArrayList<T>::Remove(const int Index) {
    if (Index >= Size_) throw std::runtime_error("Index " + std::to_string(Index) + " out of range!");
    if (Index == Size_ - 1) Remove();

    T* TempData = new T[Capacity_];
    for (int I{}; I < Index; ++I)
        TempData[I] = Data_[I];
    for (int I = Index; I < Size_ - 1; ++I)
        TempData[I] = Data_[I + 1];
    delete[] Data_;
    Data_ = TempData;
    Size_--;
    ShrinkToFit();
}

template <typename T>
void ArrayList<T>::ReallocateData() {
    T* TempData = new T[Capacity_];
    for (int I{}; I < Size_; ++I)
        TempData[I] = Data_[I];
    delete[] Data_;
    Data_ = TempData;
}

template <typename T>
void ArrayList<T>::Resize() {
    Capacity_ *= GrowthFactor_;
    ReallocateData();
}

template <typename T>
void ArrayList<T>::ShrinkToFit() {
    if (Size_ > Capacity_ / 2) return;
    Capacity_ /= 2;
    ReallocateData();
}

template <typename T>
void ArrayList<T>::Reserve(const int NewCapacity) {
    if (Capacity_ >= NewCapacity) return;
    Capacity_ = NewCapacity;
    ReallocateData();
}

template <typename T>
ArrayList<T>::ArrayList(std::initializer_list<T> ArgList) : ArrayList(ArgList.size()) {
    std::copy(ArgList.begin(), ArgList.end(), Data_);
}
