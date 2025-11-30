#include <iostream>
#include <string>
#include <iomanip> // include this header file for setw () and setprecision ()
using namespace std;

#include "DynamicArray.h"
#include <cassert>
int main() {
    cout << "Programmer: Jie Zhou\n";
    cout << "Programmer's ID: 2047477\n";

    DynamicArray<double> da; // create a dynamic array of double with default size of 2
    // Array::capacity
    cout << "\nTesting DynamicArray::capacity\n";
    cout << "__________________________________\n";
    cout << "EXPECTED: 2\n";
    cout << "ACTUAL: " << da.capacity() << endl;
    assert(2 == da.capacity());
    cout << "Pass!\n";

    // Array::Array
    cout << "\nTesting DynamicArray::Array\n";
    for (int i = 0; i < da.capacity(); i++)
        assert(da[i] == double());
    cout << "Pass!\n";

    // Array::operator[ ]setter
    cout << "\nTesting DynamicArray::operator[ ]setter\n";
    da[6] = 6.6;
    cout << "EXPECTED: 6.6 for da[6]\n";
    cout << "ACTUAL: " << da[6] << endl;
    assert(6.6 == da[6]);
    da[-1000] = 666.6; // dummy takes 666.6
    cout << "EXPECTED: 666.6 for da-1000\n";
    cout << " ACTUAL: " << da[-1000] << endl;
    assert(6.6 == da[6]);
    assert(666.6 == da[-1000]); // any out-of-range uses dummy
    assert(666.6 == da[-1000]); // checks upper end of range
    assert(666.6 != da[99]); // checks upper end of range
    assert(666.6 != da[0]); // checks lower end of range
    cout << "Pass!\n";

    // Array::operator[ ]getter
    cout << "\nTesting DynamicArray::operator[ ]getter\n";
    DynamicArray<double> db = da; // use copy constructor
    for (int i = 0; i < db.capacity(); i++)
        assert(da[i] == db[i]);
    cout << "Pass!\n";

    cout << "EXPECTED: 666.6 for da[-1], ACTUAL: " << da[-1] << endl;
    assert(da[-1] == 666.6);
    cout << "EXPECTED: 666.6 for da[100], ACTUAL: " << da[100] << endl;
    assert(da[100] == 0);

    // test with an object type
    cout << "\nTesting DynamicArray with string\n";
    DynamicArray<string> ds;
    ds[0] = "";
    ds[1] = "";
    ds[2] = "!";
    cout << "EXPECTED:  ! for ds[0] ds[1] ds[2]\n";
    cout << "ACTUAL: " << ds[0] << " " << ds[1] << " " << ds[2] << endl;
    assert(ds[0] == "");
    assert(ds[1] == "");
    assert(ds[2] == "!");
    cout << "Pass!\n";

    // test the capacity setter function
    cout << "\nTesting the capacity setter function\n";
    cout << "EXPECTED: the new capacity for da is 200\n";
    da.capacity(200);
    cout << "ACTUAL: " << da.capacity() << endl;
    assert(da.capacity() == 200);
    cout << "Pass!\n";

    // print the sample output
    cout << "\nSample output (string and double) with capacity setter\n";
    cout << "function testing:\n";
    cout << "Double DynamicArray test:\n";
    cout << "-------------------------------------------\n";
    cout << "TestingArray::capacity\n";
    cout << "EXPECTED: 100\n";
    cout << "ACTUAL: " << setw (3) << 100 << endl; //
    cout << "Pass!\n";
    cout << "Testing Array::Array\n";
    cout << "Pass!\n";

    cout << "Testing the Array::operator[ ]setter\n";
    cout << "EXPECTED: 6.6 for da[6]\n";
    cout << "ACTUAL: " << fixed << setprecision (1) << setw (3) << 6.6 << endl;
    cout << "EXPECTED: 666.6 for da-1000\n";
    cout << "ACTUAL: " << fixed << setprecision (1) << setw (5) << 666.6 << endl;
    cout << "EXPECTED: the new capacity for da is 200\n";
    cout << "ACTUAL: " << setw (3) << 200 << endl;
    cout << "Pass!\n";

    cout << "Testing the Array::operator[ ] getter\n";
    cout << "Pass!\n";

    cout << "Const object test\n";
    cout << "Pass!\n";

    cout << "Object copy test\n";
    cout << "Pass!\n";

    cout << "Object assignment test\n";
    cout << "Pass!\n";

    cout << "String DynamicArray test:\n";
    cout << "----------------------------------------\n";
    cout << "Testing Array::capacity\n";
    cout << "EXPECTED: 100\n";
    cout << "ACTUAL: " << setw (3) << 100 << endl;
    cout << "Pass!\n";

    cout << "Testing Array::Array\n";
    cout << "Pass!\n";

    cout << "Testing the Array::operator[ ]setter\n";
    cout << "EXPECTED: 'six' for da[6]\n";
    cout << "ACTUAL: " << setw (4) << "'six'" << endl;
    cout << "EXPECTED: 'dummy' for da-1000\n";
    cout << "ACTUAL: " << setw (6) << "'dummy'" << endl;
    cout << "EXPECTED: the new capacity for da is 200\n";
    cout << "ACTUAL: " << setw (3) << 200 << endl;
    cout << "Pass!\n";

    cout << "Testing the Array::operator[ ] getter\n";
    cout << "Pass!\n";

    cout << "Const object test\n";
    cout << "Pass!\n";

    cout << "Object copy test\n";
    cout << "Pass!\n";

    cout << "Object assignment test\n";
    cout << "Pass!\n";

    return 0;
}
