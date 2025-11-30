#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED
// Programmer: Jie Zhou;
// Programmer's ID: 2047477;
template <typename V>
class Queue {
    struct node {
        V value;
        node* next;
    };

    int siz;
    node* firstNode;
    node* lastNode;
    V dummy;

public:
    Queue();
    Queue(const Queue<V>&); // copy constructor
    Queue<V>& operator=(const Queue<V>&);
    ~Queue();
    void push(const V&);
    const V& front() const; // return an immutable reference to the oldest node
    const V& back() const;  // return an immutable reference to the newest node
    void pop();             // remove the oldest node
    int size() const { return siz; }
    bool empty() const { return siz == 0; }
    void clear();
};

template <typename V>
Queue<V>::Queue() : siz(0), firstNode(nullptr), lastNode(nullptr), dummy() {}

template <typename V>
Queue<V>::Queue(const Queue<V>& other) : siz(0), firstNode(nullptr), lastNode(nullptr), dummy() 
{
    node* temp = other.firstNode;
    while (temp)
    {
        push(temp->value);
        temp = temp->next;
    }
}

template <typename V>
Queue<V>& Queue<V>::operator=(const Queue<V>& other)
{
    if (this != &other) 
    {
        clear();
        node* temp = other.firstNode;
        while (temp)
        {
            push(temp->value);
            temp = temp->next;
        }
    }
    return *this;
}

template <typename V>
Queue<V>::~Queue() 
{
    clear();
}

template <typename V>
void Queue<V>::push(const V& value)
{
    node* temp = new node;
    temp->value = value;
    temp->next = nullptr;
    if (siz == 0)
    {
        firstNode = lastNode = temp;
    }
    else 
    {
        lastNode->next = temp;
        lastNode = temp;
    }
    ++siz;
}

template <typename V>
const V& Queue<V>::front() const
{
    if (siz == 0)
    {
        return dummy;
    }
    return firstNode->value;
}

template <typename V>
const V& Queue<V>::back() const
{
    if (siz == 0) 
    {
        return dummy;
    }
    return lastNode->value;
}

template <typename V>
void Queue<V>::pop() 
{
    if (siz == 0) 
    {
        return;
    }
    node* temp = firstNode;
    firstNode = firstNode->next;
    delete temp;
    --siz;
    if (siz == 0) {
        lastNode = nullptr;
    }
}

template <typename V>
void Queue<V>::clear() 
{
    while (firstNode) 
    {
        node* temp = firstNode;
        firstNode = firstNode->next;
        delete temp;
    }
    siz = 0;
    lastNode = nullptr;
}
#endif //QUEUE_H_INCLUDED