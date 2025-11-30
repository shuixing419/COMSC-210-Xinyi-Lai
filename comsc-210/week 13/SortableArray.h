// Programmer: Zhou Jie
// Programmer's ID: 2047477

#ifndef SortableArray_h
#define SortableArray_h
#include <algorithm>
using namespace std;

template <typename V>
class SortableArray
{
    V* value;
    V dummy;
    int cap;

public:
    SortableArray(int = 2);
    SortableArray(const SortableArray<V>&); // copy constructor
    ~SortableArray() { delete[] value; } // destructor
    SortableArray<V>& operator=(const SortableArray<V>&); // assignment operator

    int capacity() const; // capacity getter
    void capacity(int); // capacity setter
    V operator[](int) const; // getter
    V& operator[](int); // setter

    void sort(int);
};

template<typename V>
SortableArray<V>::SortableArray(int c)
{
    V dummy = V();
    this->cap = c;
    value = new V[cap];
    for (int i = 0; i < cap; i++)
    {
        value[i] = dummy;
    }
}

template<typename V>
SortableArray<V>& SortableArray<V>::operator=(const SortableArray<V>& original)
{
    if (this != &original)
    {
        delete[] value;
        cap = original.cap;
        value = new V[cap];
        for (int i = 0; i < cap; i++)
            value[i] = original.value[i];
    }
    return *this;
}

template <typename V>
SortableArray<V>::SortableArray(const SortableArray<V>& original)
{
    cap = original.cap;
    value = new V[cap];
    for (int i = 0; i < cap; i++)
        value[i] = original.value[i];
}

template <typename V>
void SortableArray<V>::capacity(int newCap)
{
    V* temp = new V[newCap];
    int limit = min(newCap, cap);
    for (int i = 0; i < limit; i++)
        temp[i] = value[i];

    delete[] value;
    value = temp;
    cap = newCap;
}

template <typename V>
int SortableArray<V>::capacity() const
{
    return cap;
}

template <typename V>
V SortableArray<V>::operator[](int index) const
{
    if (index < 0 || index >= cap) return dummy;
    return value[index];
}

template <typename V>
V& SortableArray<V>::operator[](int index)
{
    if (index < 0) return dummy;
    if (index >= cap) capacity(2 * index);
    return value[index];
}

template <typename V>
void SortableArray<V>::sort(int end)
{
    for(int x = 1; x < end; x *= 2)
    {
        for (int i = 0; i < end; i += 2 * x)
        {
            int left = i;
            int leftMax = min(left + x, end);
            int right = leftMax;
            int rightMax = min(right + x, end);
            int* temp = new int[rightMax - left]; // Temporarily store elements to be sorted
            int index = 0;
            while (left < leftMax && right < rightMax)
            {
                if (value[right] < value[left])
                    temp[index++] = value[right++];
                else
                    temp[index++] = value[left++];
            }
            while (left < leftMax)
                temp[index++] = value[left++];
            while (right < rightMax)
                temp[index++] = value[right++];
            // Copy sorted elements back to original array
            index = 0;
            for (int j = i; j < rightMax; ++j)
                value[j] = temp[index++];
            delete[] temp;
        }
    }
}
#endif //SortableArray_h