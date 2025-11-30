// Programmer: Jie Zhou
// Programmer's Id: 2047477
#ifndef DYNAMICARRAY_H_INCLUDED
#define DYNAMICARRAY_H_INCLUDED

template <typename T>
class DynamicArray
{
    T* value; // T datatype CAP capacity
    int cap;
    T dummy;

public:
    DynamicArray(int = 2); // constructor // default=2
    DynamicArray(const DynamicArray<T>&); // copy constructor
    ~DynamicArray() { delete[ ] value; }  // destructor
    DynamicArray<T>& operator=(const DynamicArray<T>&); // assignment operator
    int capacity() const { return cap; }
    void capacity(int); // setter
    T operator[](int) const; // getter
    T& operator[](int);      // setter
};

template <typename T>
DynamicArray<T>::DynamicArray(int cap)
{
    dummy = T();
    this->cap = cap;
    value = new T[cap];
    for (int i = 0; i < cap; ++i)
    {
        value[i] = T(); // default value
    }
}

template <typename T>
DynamicArray<T>::DynamicArray(const DynamicArray<T>& original)
{
    this->cap = original.cap;
    this->value = new T[cap];
    for (int i = 0; i < cap; ++i)
    {
        value[i] = original.value[i];
    }
    dummy = original.dummy; // not necessary
}

template <typename T>
DynamicArray<T>& DynamicArray<T>::operator=(const DynamicArray<T>& original)
{
    if (this != &original) // not self-copy
    {
        delete[] value;

        this->cap = original.cap;
        this->value = new T[cap];
        for (int i = 0; i < cap; ++i)

            value[i] = original.value[i];

        dummy = original.dummy; // not necessary
    }
    return *this;
}

template <typename T>
T DynamicArray<T>::operator[](int index) const //getter
{
    if (index < 0 || index >= cap) return dummy;
    return value[index];
}


template <typename T>
T& DynamicArray<T>::operator[](int index) // setter
{
    if (index < 0) return dummy;
    if (index >= cap) capacity(2 * index);
    return value[index];
}

template <typename T>
void DynamicArray<T>::capacity(int cap)
{
    T* temp = new T[cap];
    // copy the old content
    int limit = cap < this->cap ? cap : this->cap;

    for (int i = 0; i < limit; i++)
        temp[i] = value[i];
    for (int i = limit; i < cap; i++)
        temp[i] = T();

    delete[] value; // deallocate the original array

    value = temp; // assign the date attribute to the new array

    this->cap = cap;

}
#endif // DYNAMICARRAY_H_INCLUDED
