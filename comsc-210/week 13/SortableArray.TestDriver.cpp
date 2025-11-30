#include <iostream>
#include <string>
#include <ctime>
#include <cmath>
#include <cstdlib>
#include <cassert>
#include <fstream>
#include <cstring>
#include <queue>
#include <iomanip>
#include <map>
using namespace std;


#include "SortableArray.h"

struct testType
{
  double d;
};

int main()
{
  cout << "Programmer: Module 13\n"
       << "Programmer's ID: instructor solution file\n"
       << "file: " << __FILE__ << "\n\n";

  // Array::capacity
  SortableArray<testType> da(100);
  cout << "SortableArray test:\n"
       << "----------------------------";
  cout << "\nTesting Array::capacity\n";
  cout << "EXPECTED: 100\n";
  cout << "ACTUAL: " << da.capacity( ) << endl;
  assert(100 == da.capacity( ));
  cout << "Pass!\n";

  // Array::Array
  cout << "\nTesting Array::Array\n";
  for (int i = 0; i < da.capacity( ); i++)
    assert(da[i].d == double());
  cout << "Pass!\n";

  // Array::operator[ ] setter
  cout << "\nTesting the Array::operator[ ] setter\n";
  da[6].d = 6.6;
  cout << "EXPECTED: 6.6 for da[6]\n";
  cout << "ACTUAL: " << da[6].d << endl;
  assert(6.6 == da[6].d);
  da[-1000].d = 666.6; // dummy takes 666.6
  cout << "EXPECTED: 666.6 for da[-1000](dummy)\n";
  cout << "ACTUAL: " << da[-1000].d << endl; // dummy
  assert(6.6 == da[6].d);
  assert(666.6 == da[-6].d); // any out-of-range uses dummy
  assert(666.6 != da[99].d); // checks upper end of range
  assert(666.6 != da[0].d); // checks lower end of range
  cout << "Pass!\n";

  // Array::operator[ ] getter
  cout << "\nTesting the Array::operator[ ] getter\n";
  const SortableArray<testType> db = da;
  for (int i = 0; i < db.capacity(); i++)
    assert(da[i].d == db[i].d);
  cout << "Pass!\n";

  // const object test
  cout << "\nConst object test\n";
  const SortableArray<testType> dc(100); // if this compiles, Array::Array main constructor exists
  assert(dc.capacity( )); // if this compiles, Array::capacity is a getter
  assert(dc[0].d == dc[0].d); // if this compiles, there is an Array::operator[ ] getter
  cout << "Pass!\n";

  // object copy test
  cout << "\nObject copy test\n";
  SortableArray<testType> dd = da; // making a copy
  assert(da.capacity() == dd.capacity());
  for (int i = 0; i < da.capacity(); i++)
    assert(da[i].d == dd[i].d); // uses the setter version for both a and d
  cout << "Pass!\n";

  // object assignment test
  cout << "\nObject assignment test\n";
  SortableArray<testType> de; de = da;
  assert(da.capacity() == de.capacity());
  for (int i = 0; i < da.capacity(); i++)
    assert(da[i].d == de[i].d);

  return 0;
}
