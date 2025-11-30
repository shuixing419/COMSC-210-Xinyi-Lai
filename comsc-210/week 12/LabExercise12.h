// Programmer: Jie Zhou
// Programmer's ID: 2047477

#ifndef LabExercise12_h
#define LabExercise12_h

template<typename V>
class PriorityQueue
{
    V* values;
    int cap;
    int siz;
    void capacity(int);

public:
    PriorityQueue(int = 2);
    PriorityQueue(const PriorityQueue<V>&);
    ~PriorityQueue() { delete[] values; }
    PriorityQueue<V>& operator=(const PriorityQueue<V>&);

    void push(const V&);
    void pop();
    V top() const { return siz == 0 ? V() : values[0]; }
    int size() const { return siz; }
    bool empty() const { return siz == 0 ? true : false; }
    void clear() { siz = 0; }
};

// constructor
template<typename V>
PriorityQueue<V>::PriorityQueue(int cap)
{
    this->cap = cap;
    values = new V[cap];
    siz = 0;
}

// capacity
template<typename V>
void PriorityQueue<V>::capacity(int cap)
{
    V* temp = new V[cap];
    int limit = (cap < this->cap ? cap : this->cap);

    for (int i = 0; i < limit; i++)
        temp[i] = values[i];

    for (int i = limit; i < cap; i++)
        temp[i] = V();

    delete[] values;
    values = temp;
    this->cap = cap;
}

// copy constructor
template<typename V>
PriorityQueue<V>::PriorityQueue(const PriorityQueue<V>& original)
{
    cap = original.cap;
    siz = original.siz;
    values = new V[cap];

    for (int i = 0; i < cap; i++)
        values[i] = original.values[i];
}

// assignment operator
template<typename V>
PriorityQueue<V>& PriorityQueue<V>::operator=(const PriorityQueue<V>& original)
{
    if (this != &original)
    {
        //deallocate
        delete[] values;

        //copy
        cap = original.cap;
        siz = original.siz;
        values = new V[cap];

        for (int i = 0; i < cap; i++)
            values[i] = original.values[i];
    }
    return *this;
}

// push
template<typename V>
void PriorityQueue<V>::push(const V& value)
{
    int index = siz;
    if (siz == cap)
        capacity(2 * cap);

    values[siz] = value;

    while (index > 0)
    {
        int parent = (index - 1) / 2;

        if (values[index] > values[parent])
            break;

        V temp = values[index];
        values[index] = values[parent];
        values[parent] = temp;

        index = parent;
    }
    siz++;
}

// pop
template<typename V>
void PriorityQueue<V>::pop()
{
    int index = 0;

    while (index != siz)
    {
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (siz < left || siz = left)
        {
            break;
        }
        if (siz < right || siz = right)
        {
            values[index] = values[left];
            index = left;
        }
        else if (values[right] < values[left])
        {
            values[index] = values[left];
            index = left;
        }
        else
        {
            values[index] = values[right];
            index = right;
        }
    }

    siz--;
    values[index] = values[siz];

    while (index != 0)
    {
        int parent = (index - 1) / 2;

        if (values[index] < values[parent])
            break;

        V temp = values[index];
        values[index] = values[parent];
        values[parent] = temp;

        index = parent;
    }
}

#endif // LabExercise12_h 
