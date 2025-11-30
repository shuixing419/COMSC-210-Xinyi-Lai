template <typename T>
class DynamicArray
{
    T* values; // T datatype CAP capacity
    int cap;
    T dummy = T ( );

public:
    DynamicArray(int = 2); // constructor // default=2
    DynamicArray(const DynamicArray<T>&); // copy constructor
    ~DynamicArray() { delete[] value; }  // destructor
    DynamicArray<T>& operator=(const DynamicArray<T>&); // assignment operator
    int capacity() const {return cap;}
    void capacity(int); // setter
    T operator[](int) const; // getter
    T& operator[](int);      // setter
};

template <typename T>
DynamicArray<T>::DynamicArray(int = cap)
{
    dummy = T();
    this -> cap = cap;
    value = new T[cap];
    for (int i = 0; i < cap; ++i)
    {
        value[i] = T(); // default value
    }
}

template <typename T>
DynamicArray<T>::DynamicArray(const DynamicArray<T>& orignal)
{
    this->cap = original.cap;
    this->value = new T[cap];
    for (int i = 0; i < cap; ++i)
    {
        value[i] = orignal.value[i];
    }
    dummy = original.dummy; // not necessary
}

template <typename T>
DynamicArray<T>& DynamicArray<T>::operator=(const DynamicArray<T>& orignal)
{
    {
        if (this != &original) // not self-copy
    }
    delete [] value;

    this->cap = original.cap;
    this->value = new T[cap];
    for (int i = 0; i < cap; ++i)
    {
        value[i] = orignal.value[i];
    }
    dummy = original.dummy; // not necessary
    return *this;
}

