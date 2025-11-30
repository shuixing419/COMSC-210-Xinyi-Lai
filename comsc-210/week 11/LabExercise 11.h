// Programmer: Jie Zhou
// Programmer's ID: 2047477


#ifndef LabExercise11_h
#define LabExercise11_h

#include <list>
#include <queue>
#include <algorithm>

template <typename K, typename V, int CAP>
class HashTable
{
    struct Node
    {
        K key;
        V value;
    };

    list<Node> data[CAP]; // chaining
    int(*hashCode)(const K&); // ptr to hasCode function
    int siz;

public:
    HashTable(int(*)(const K&) = 0); // = 0 for a default constructor
    double loadFactor() const { return 1.0 * siz / CAP; }
    V operator[](const K&) const; // getter
    V& operator[](const K&); // setter
    bool containsKey(const K&) const; // getter
    void deleteKey(const K&); // setter
    queue<K> keys() const;
    int size() const { return siz; }
    void clear();
};

// constructor
template <typename K, typename V, int CAP>
HashTable<K, V, CAP>::HashTable(int(*hashCode)(const K&))
{
    this->hashCode = hashCode;
    siz = 0;
}

// [] getter
template <typename K, typename V, int CAP>
V HashTable<K, V, CAP>::operator[](const K& key) const
{
    int index = hashCode(key) % CAP;
    if (index < 0) index += CAP;

    // find value @ index
    typename list<Node>::const_iterator it;
    for (it = data[index].begin(); it != data[index].end(); it++)
    {
        if (it->key == key)
        {
            return it->value;
        }
    }

    V dummy = V();
    return dummy;
}

// [] setter
template <typename K, typename V, int CAP>
V& HashTable<K, V, CAP>::operator[](const K& key)
{
    int index = hashCode(key) % CAP;
    if (index < 0) index += CAP;

    // find value @ index
    typename list<Node>::iterator it;
    for (it = data[index].begin(); it != data[index].end(); it++)
    {
        if (it->key == key)
        {
            return it->value;
        }
    }

    // add value if it does not already exist
    siz++;
    Node temp;
    temp.key = key;
    temp.value = V();
    data[index].push_back(temp);
    return data[index].back().value;
}

// contains key
template <typename K, typename V, int CAP>
bool HashTable<K, V, CAP>::containsKey(const K& key) const
{
    int index = hashCode(key) % CAP;
    if (index < 0) index += CAP;

    // check if value exist
    typename list<Node>::const_iterator it;
    for (it = data[index].begin(); it != data[index].end(); it++)
    {
        if (it->key == key)
        {
            return true;
        }
    }
    return false;
}

// delete key
template <typename K, typename V, int CAP>
void HashTable<K, V, CAP>::deleteKey(const K& key)
{
    int index = hashCode(key) % CAP;
    if (index < 0) index += CAP;

    typename list<Node>::iterator it;
    for (it = data[index].begin(); it != data[index].end(); it++)
    {
        if (it->key == key)
        {
            delete data[index];
            siz--;
        }
    }
}

// keys
template <typename K, typename V, int CAP>
Queue<K> HashTable<K, V, CAP>::keys() const
{
    Queue<K> dataQ;
    typename list<Node>::const_iterator it;

    for (int i = 0; i < CAP; i++)
    {
        for (it = data[i].begin(); it != data[i].end(); ++it)
        {
            if (!data[i].empty())
            {
                dataQ.push(it->key);
            }
        }
    }
    return dataQ;
}

// clear
template <typename K, typename V, int CAP>
void HashTable<K, V, CAP>::clear()
{
    for (int i = 0; i < siz; i++)
        data[i].clear();
    siz = 0;
}

#endif /* LabExercise11_h */