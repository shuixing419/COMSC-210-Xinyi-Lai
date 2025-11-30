#include <iostream>
#include <cassert>
#include <sstream>
using namespace std;
template <typename T, int CAP>
class StaticArray
{
    T values[CAP]; // T datatype Cap compasity
    T dummy;

public:
    StaticArray();
    int capacity() const;
    T operator[](int) const; // getter
	T& operator[](int);    // setter
};

template <typename T, int CAP>
T &StaticArray<T, CAP>::operator[](int index)
{

    if (index < 0 || index >= CAP)
    {
        return dummy;
    }
    return values[index];
}

template <typename T, int CAP>
T StaticArray<T, CAP>::operator[](int index) const
{
    if (index < 0 || index >= CAP)
    {
        return dummy;
    }
    return values[index];
}

template <typename T, int CAP>
StaticArray<T, CAP>::StaticArray()
{
    dummy = T();
    for (int i = 0; i < CAP; i++)
        values[i] = T();
}
template <typename T, int CAP>
int StaticArray<T, CAP>::capacity() const
{
    return CAP;
}
int main()
{
    cout << "Programmer: Zhou Jie\n";
    cout << "Programmer's ID: 2047477\n";
    StaticArray<double, 100> a; // array of double values
    StaticArray<bool, 100> b;   // array of bool flags
    std::string input1, input2;
    int index;
    double value;
    int count = 0;

    std::cout << "Input an index and a value [Q to quit]: ";
    std::cin >> input1;
    while (input1 != "Q" && input1 != "q")
    {

        std::cin >> input2;
        index = atoi(input1.c_str());
        value = stod(input2.c_str());
        {
            if (index >= 0 && index < a.capacity())
            {
                a[index] = value;
                if (b[index] != true)
                {
                    count++;
                    b[index] = true;
                }
            }
            std::cout << "Input an index and a value [Q to quit]: ";
            std::cin >> input1;
        }
    }

    std::cout << "\nYou stored this many values: " << count << std::endl;
    std::cout << "The index-value pairs are:\n\n";
    for (int i = 0; i < a.capacity(); i++)
    {
        if (b[i] == true)
        {
            std::cout << i << " => " << a[i] << std::endl;
        }
    }
    do
    {
        int lookupIndex;
        cout << "\nInput an index for me to look up [Q to quit]: ";
        cin >> input1;

        if (input1 == "Q" || input1 == "q")
        {
            break;
        }

        lookupIndex = atoi(input1.c_str());

        if (b[lookupIndex] == true)
        {
            cout << "Found it -- the value stored at " << lookupIndex << " is " << a[lookupIndex] << "\n";
        }
        else
        {
            cout << "I didn't find it\n";
        }

    } while (true);
    return 0;
}

