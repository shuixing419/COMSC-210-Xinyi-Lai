#ifndef STACKTEMPLATE_H_INCLUDED
#define STACKTEMPLATE_H_INCLUDED
// Programmer: Jie Zhou
// Programmer's ID: 2047477

template <typename V>
class Stack
{
    V* values;
    int cap;
    int siz;
    void capacity(int);

public:
    Stack();
    Stack(const Stack<V>&);
    ~Stack() { delete[] values; }
    Stack<V>& operator=(Stack<V> other);
    void push(const V&);
    V& peek();
    void pop();
    void clear() { siz = 0; }
    int size() const { return siz; }
    bool empty() const { return siz == 0; }
};

// default constructor
template <typename V>
Stack<V>::Stack()
{
    cap = 2;
    siz = 0;
    values = new V[cap];
}

// copy constructor
template <typename V>
Stack<V>::Stack(const Stack<V>& other)
{
    cap = other.cap; // copy the capacity
    siz = other.siz; // copy the size
    values = new V[cap];
    for (int i = 0; i < siz; i++) // copy the values
    {
        values[i] = other.values[i];
    }
}


template <typename V>
Stack<V>& Stack<V>::operator=(Stack<V> other)
{
    std::swap(cap, other.cap);
    std::swap(siz, other.siz);
    std::swap(values, other.values);
    return *this;
}


template <typename V>
void Stack<V>::capacity(int newCap)
{
    V* temp = new V[newCap];
    int limit = newCap > cap ? cap : newCap;
    for (int i = 0; i < limit; i++)
    {
        temp[i] = values[i];
    }
    delete[] values;
    values = temp;
    cap = newCap;
}


template <typename V>
void Stack<V>::push(const V& val)
{
    if (siz == cap)
    {
        capacity(2 * cap);
    }
    values[siz] = val;
    siz++;
}

// return the top value of the stack
template <typename V>
V& Stack<V>::peek()
{
    if (siz > 0) // check if the stack is not empty
    {
        return values[siz - 1];
    }
    else
    {
        throw std::logic_error("Stack is empty");
    }
}

// pop the top value of the stack
template <typename V>
void Stack<V>::pop()
{
    if (siz > 0) // check if the stack is not empty
    {
        siz--;
    }
    else
    {
        throw std::logic_error("Stack is empty");
    }
}

#endif //STACKTEMPLATE_H_INCLUDED
