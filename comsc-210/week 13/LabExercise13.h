// Programmer: Zhou Jie
// Programmer's ID: 2047477
#ifndef LabExercise13_h
#define LabExercise13_h

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
    cap = c;
    value = new V[cap];
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
    int* temp = new int[end];
    for (int x = 1; x < end; x *= 2)
    {
        int index = 0;
        for (int i = 0; i < end; i++) temp[i] = value[i]; 
        for (int i = 0; i < end; i += 2 * x)
        {
            int left = i;
            int leftMax = min(left + x, end);
            int right = leftMax;
            int rightMax = min(right + x, end);
            while (true)
            {
                if (left == leftMax && right == rightMax) break;
                if (left == leftMax) value[index++] = temp[right++]; 
                else if (right == rightMax) value[index++] = temp[left++];
                else if (temp[right] < temp[left]) value[index++] = temp[right++]; 
                else value[index++] = temp[left++]; 
            }
        }
    }
}

#endif // LabExercise13_h
