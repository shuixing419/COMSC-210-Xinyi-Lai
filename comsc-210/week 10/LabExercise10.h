// Programmer: Jie Zhou
// Programmer's Id: 2047477
#ifndef AssociativeArray_h
#define AssociativeArray_h

#include <queue>
using namespace std;

template <typename K, typename V>
class AssociativeArray
{
    struct Node
    {
        K key;
        V value;
        Node* next;
    };

    Node* firstNode;
    int siz;


public:
    AssociativeArray() { firstNode = 0; siz = 0; }// default con
    AssociativeArray(const AssociativeArray&);// copy constructor
    AssociativeArray<K, V>& operator=(const AssociativeArray<K, V>&);
    ~AssociativeArray();//destructor
    V operator[ ](const K&)const;//or const V& as return type
    V& operator[ ](const K&);//setter
    bool containsKey(const K&)const;//getter
    void deleteKey(const K&);//setter
    queue<K> keys()const;
    int size() { return siz; }
    void clear();
};

// copy constructor
template <typename K, typename V>
AssociativeArray<K, V>::AssociativeArray(const AssociativeArray& other)
{
    firstNode = nullptr;
    siz = other.siz;
    Node* lastNode = nullptr;
    for (Node* p = other.firstNode; p; p = p->next)
    {
        Node* temp = new Node;
        temp->key = p->key;
        temp->value = p->value;
        temp->next = nullptr;
        if (lastNode)
            lastNode->next = temp;
        else
            firstNode = temp;
        lastNode = temp;
    }
}

// assignment operator
template <typename K, typename V>
AssociativeArray<K, V>& AssociativeArray<K, V>::operator=(const AssociativeArray<K, V>& other)
{
    if (this != &other)
    {
        while (firstNode)
        {
            Node* p = firstNode->next;
            delete firstNode;
            firstNode = p;
        }

        Node* lastNode = nullptr;
        for (Node* p = other.firstNode; p; p = p->next)
        {
            Node* temp = new Node;
            temp->key = p->key;
            temp->value = p->value;
            temp->next = nullptr;
            if (lastNode)
                lastNode->next = temp;
            else
                firstNode = temp;
            lastNode = temp;
        }
        siz = other.siz;
    }
    return *this;
}

// destructor
template <typename K, typename V>
AssociativeArray<K, V>::~AssociativeArray()
{
    while (firstNode)
    {
        Node* p = firstNode;
        firstNode = firstNode->next;
        delete p;
    }
}

// getter operator[]
template <typename K, typename V>
V AssociativeArray<K, V>::operator[](const K& key) const
{
    for (Node* p = firstNode; p; p = p->next)
        if (p->key == key)
            return p->value;
    return V(); // return default value if key not found
}

// setter operator[]
template <typename K, typename V>
V& AssociativeArray<K, V>::operator[](const K& key)
{
    for (Node* p = firstNode; p; p = p->next)
        if (p->key == key)
            return p->value;
    ++siz;
    Node* temp = new Node;
    temp->key = key;
    temp->next = firstNode;
    firstNode = temp;
    return firstNode->value;
}

// containsKey
template <typename K, typename V>
bool AssociativeArray<K, V>::containsKey(const K& key) const
{
    for (Node* p = firstNode; p; p = p->next)
        if (p->key == key)
            return true;
    return false;
}

// deleteKey
template <typename K, typename V>
void AssociativeArray<K, V>::deleteKey(const K& key)
{
    Node* p, * prev;
    for (p = firstNode, prev = nullptr; p; prev = p, p = p->next)
        if (p->key == key)
            break;

    if (p)
    {
        --siz;
        if (prev)
            prev->next = p->next;
        else
            firstNode = p->next;
        delete p;
    }
}

// keys
template <typename K, typename V>
queue<K> AssociativeArray<K, V>::keys() const
{
    queue<K> result;
    for (Node* p = firstNode; p; p = p->next)
        result.push(p->key);
    return result;
}

// clear
template <typename K, typename V>
void AssociativeArray<K, V>::clear()
{
    while (firstNode)
    {
        Node* p = firstNode;
        firstNode = firstNode->next;
        delete p;
        siz--;
    }
}

#endif
