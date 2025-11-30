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

void display(const SortableArray<double>&, const SortableArray<bool>&, int);

int main()
{
  SortableArray<double> index;
  SortableArray<bool> index2;
  int numbers =0;
  string buf1;
  string buf2;
  string buf3;
  string buf4;
  int a=0;
  double b=0;

  // programmer's identification
  cout << "Programmer: Jie Zhou\n";
  cout << "Programmer's ID: 2047477\n";
  cout << "File: " << __FILE__ << endl << endl;

  for(int x = 0; x < index2.capacity(); x++)
  {
    index2[x]=false;
  }

  while(true)
  {
    cout<<"Input an index and a value[Q to quit]";
    cin>>buf1;
    if(buf1=="q"||buf1=="Q")
      break;
    cin>>buf2;
    if(buf2=="q"||buf2=="Q")
      break;
    a=atoi(buf1.c_str());
    b=atof(buf2.c_str());

    if (a > (index.capacity() - 1))
    {
      for (int x = index.capacity(); x < (a* 2); x++)
      {
        index2[x] = false;
      }
      index[a] = b;
      index2[a] = true;
    }
    else
    {
      index[a] = b;
      index2[a] = true;
    }
  }

  for(int x=0; x<index.capacity(); x++)
  {
    if(index2[x]==true)
      numbers++;
  }

  cout<<"You stored this many values : "<<numbers<<endl;

  for(int x = 0; x < index.capacity(); x++)
  {
    if(index2[x]==true)
      cout<<"The index-value pairs are : "<<x<<"\t\t"<<index[x]<<endl;
  }

  //Sort
  cout << endl << "Enter the numbers of index you are going to sort :";
  cin >> buf4;
  index.sort(atoi(buf4.c_str()));

  cout << endl;
  cout << "Sorting......Done!" <<endl;
  cout << "Now the index-value pairs are:" <<endl;

  for(int x = 0; x < index.capacity(); x++)
  {
    if(index2[x]==true)
      cout<<"The index-value pairs are : "<<x<<"\t\t"<<index[x]<<endl;
  }

  while(true)
  {
    int position=0;
    cout<<"Input an index for me to look up[Q to quit]: ";
    cin>>buf3;
    if(buf3=="q"||buf3=="Q")
      break;
    position=atoi(buf3.c_str());
    display(index, index2, position);
  }

  return 0;
}


void display(const SortableArray<double>& index, const SortableArray<bool>& index2, int pos)
{
  if (index2[pos] && pos >= 0 && pos < index.capacity())
    cout<<"Found it---the index stored at "<<pos<< " is "<<index[pos]<<endl;
  else
    cout<<"I didn't find it "<<endl;
}
