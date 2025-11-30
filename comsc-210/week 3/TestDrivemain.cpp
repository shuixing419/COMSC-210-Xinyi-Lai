// Programmer: Jie Zhou
// Programmer's ID: 2047477

#include <iostream>
#include <string>
using namespace std;

#include "StaticArray.h"
#include "StaticArray.h"// ifndef test
#include <cassert>
int main() {
    cout << "Programmer: Jie Zhou\n";
    cout << "Programmer's ID: 2047477\n";

    StaticArray<double, 100> da;
    // Array::capacity
    cout << "\nTesting StaticArray::capacity\n";
    cout << "__________________________________\n";
    cout << "EXPECTED: 100\n";
    cout << "ACTUAL: " << da.capacity() << endl;
    assert(100 == da.capacity());
    cout << "Pass!\n";

    // Array::Array
    cout << "\nTesting Array::Array\n";
    for (int i = 0; i < da.capacity( ); i++)
        assert(da[i] == double());
    cout << "Pass!\n";

    // Array::operator[ ]setter
    cout << "\nTesting Array::operator[ ]setter\n";
    da[6] = 6.6;
    cout << "EXPECTED: 6.6 for da[6]\n";
    cout << "ACTUAL: " << da[6] << endl;
    assert(6.6 == da[6]);
    da[-1000] = 666.6;//dummy takes 666.6
    cout << "EXPECTED: 666.6 for da[-1000](dummy)\n";
    cout << " ACTUAL: " << da[-1000] << endl;
    assert(6.6 == da[6]);
    assert(666.6 == da[-6]);// any out-of-range uses dummy
    assert(666.6 == da[100]);// checks upper end of range
    assert(666.6 != da[99]);// checks upper end of range
    assert(666.6 != da[0]);// checks lower end of range
    cout << "Pass!\n";

    // Array::operator[ ]getter
    cout << "\nTesting Array::operator[ ]getter\n";
    StaticArray<double,100> db = da;
    for (int i =0; i < 100; i++)
        assert(da[i]==db[i]);
    cout << "Pass!\n";

    cout << "EXPECTED: 0 for da[-1], ACTUAL: " << db[-1] << endl;
    assert(db[-1] == 666.6);
    cout << "EXPECTED: 0 for da[100], ACTUAL: " << db[100] << endl;
    assert(db[100] == 666.6);
    cout << "Pass!\n";
    //for (int i =0; i < 100; i++)
        //assert(db[i] == double());
    //cout << "Pass!\n";


    // const object test
    cout << "\nConst object test\n";
    const StaticArray<double, 100> dc;
    assert(dc.capacity( ));
    assert(dc[0] == dc[0]);
    assert(dc[-1] == dc[-1]);
    cout << "Pass!\n";

    StaticArray<string, 100> sa;

    // Array::capacity
    cout << "\nTesting StaticArray::capacity\n";
    cout << "__________________________________";
    cout << "EXPECTED: 100\n";
    cout << "ACTUAL: " << sa.capacity() << endl;
    assert(100 == sa.capacity());
    cout << "Pass!\n";

    // Array::Array
    cout << "\nTesting Array::Array\n";
    for (int i = 0; i < da.capacity( ); i++)
        assert(sa[i] == string());
    cout << "Pass!\n";


    // Array::operator[ ]setter
    cout << "\nTesting Array::operator[ ]setter\n";
    sa[6] = "six";
    cout << "EXPECTED: 'six' for da[6]\n";
    cout << "ACTUAL: " << sa[6] << endl;
    assert("six" == sa[6]);
    string dummy = "dummy";
    sa[-1000] = dummy;//dummy takes dummy
    cout << "EXPECTED: 'dummy' for da[-1000](dummy)\n";
    cout << " ACTUAL: " << sa[-1000] << endl;
    sa[6] = "six";
    assert("dummy"== sa[-6]);// any out-of-range uses dummy
    assert("dummy" == sa[100]);// checks upper end of range
    assert("dummy" != sa[99]);// checks upper end of range
    assert("dummy" != sa[0]);// checks lower end of range
    cout << "Pass!\n";

    // Array::operator[ ]getter
    cout << "\nTesting Array::operator[ ]getter\n";
    StaticArray<string,100> sb = sa;
    for (int i =0; i < 100; i++)
        assert(sa[i]==sb[i]);
    cout << "Pass!\n";


    // const object test
    cout << "\nConst object test\n";
    const StaticArray<string, 100> sc;
    assert(sc.capacity( ));
    assert(sc[0] == sc[0]);
    assert(sc[-1] == sc[-1]);
    cout << "Pass!\n";


    StaticArray<int, 100> intArray;

    // Array::capacity
    cout << "\nTesting StaticArray::capacity\n";
    cout << "__________________________________\n";
    cout << "EXPECTED: 100\n";
    cout << "ACTUAL: " << intArray.capacity() << endl;
    assert(100 == intArray.capacity());
    cout << "Pass!\n";

    // Array::Array
    cout << "\nTesting Array::Array\n";
    for (int i = 0; i < intArray.capacity(); i++)
        assert(intArray[i] == int());
    cout << "Pass!\n";

    // Array::operator[ ]setter
    cout << "\nTesting Array::operator[ ]setter\n";
    intArray[6] = 6;
    cout << "EXPECTED: 6 for intArray[6]\n";
    cout << "ACTUAL: " << intArray[6] << endl;
    assert(6 == intArray[6]);
    intArray[-1000] = 666; // Dummy takes 666
    cout << "EXPECTED: 666 for intArray[-1000]\n";
    cout << "ACTUAL: " << intArray[-1000] << endl;
    assert(6 == intArray[6]);
    assert(666 == intArray[-6]); // Any out-of-range uses dummy
    assert(666 == intArray[100]); // Checks upper end of range
    assert(666 != intArray[99]); // Checks upper end of range
    assert(666 != intArray[0]); // Checks lower end of range
    cout << "Pass!\n";

    // Array::operator[ ]getter
    cout << "\nTesting Array::operator[ ]getter\n";
    StaticArray<int,100> intArrayB = intArray;
    for (int i = 0; i < 100; i++)
        assert(intArray[i] == intArrayB[i]);
    cout << "Pass!\n";

    cout << "EXPECTED: 0 for intArray[-1], ACTUAL: " << intArray[-1] << endl;
    assert(666 == intArray[-1]);
    cout << "EXPECTED: 0 for intArray[100], ACTUAL: " << intArray[100] << endl;
    assert( 666 == intArray[100]);
    cout << "Pass!\n";

    // Const object test
    cout << "\nConst object test\n";
    const StaticArray<int, 100> intArrayC;
    assert(intArrayC.capacity());
    assert(intArrayC[0] == intArrayC[0]);
    assert(intArrayC[-1] == intArrayC[-1]);
    cout << "Pass!\n";


    StaticArray<char, 100> charArray;

    // Array::capacity
    cout << "\nTesting StaticArray::capacity\n";
    cout << "__________________________________\n";
    cout << "EXPECTED: 100\n";
    cout << "ACTUAL: " << charArray.capacity() << endl;
    assert(100 == charArray.capacity());
    cout << "Pass!\n";

    // Array::Array
    cout << "\nTesting Array::Array\n";
    for (int i = 0; i < charArray.capacity(); i++)
        assert(charArray[i] == char());
    cout << "Pass!\n";

    // Array::operator[ ]setter
    cout << "\nTesting Array::operator[ ]setter\n";
    charArray[6] = 'a';
    cout << "EXPECTED: 'a' for charArray[6]\n";
    cout << "ACTUAL: " << charArray[6] << endl;
    assert('a' == charArray[6]);
    charArray[-1000] = 'z'; // Dummy takes 'z'
    cout << "EXPECTED: 'z' for charArray[-1000]\n";
    cout << "ACTUAL: " << charArray[-1000] << endl;
    assert('a' == charArray[6]);
    assert('z' == charArray[-6]); // Any out-of-range uses dummy
    assert('z' == charArray[100]); // Checks upper end of range
    assert('z' != charArray[99]); // Checks upper end of range
    assert('z' != charArray[0]); // Checks lower end of range
    cout << "Pass!\n";

    // Array::operator[ ]getter
    cout << "\nTesting Array::operator[ ]getter\n";
    StaticArray<char,100> charArrayB = charArray;
    for (int i = 0; i < 100; i++)
        assert(charArray[i] == charArrayB[i]);
    cout << "Pass!\n";

    cout << "EXPECTED: '\\0' for charArray[-1], ACTUAL: " << charArray[-1] << endl;
    assert('z' == charArray[-1]);
    cout << "EXPECTED: '\\0' for charArray[100], ACTUAL: " << charArray[100] << endl;
    assert('z' == charArray[100]);
    cout << "Pass!\n";

    // Const object test
    cout << "\nConst object test\n";
    const StaticArray<char, 100> charArrayC;
    assert(charArrayC.capacity());
    assert(charArrayC[0] == charArrayC[0]);
    assert(charArrayC[-1] == charArrayC[-1]);
    cout << "Pass!\n";

    return 0;
}

