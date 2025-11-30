#define _CRT_SECURE_NO_WARNINGS

#include <fstream>
#include <iostream>
#include <string>
using namespace std;

#include <cstring> // for strtok and strcpy


int main()
{
  cout <<"Programmer:Jie Zhou\n"; //
  cout <<"Programmer's ID:2047477\n";
  cout << "File: " <<__FILE__ << "\n\n" << endl;
  // for parsing the inputfile
  char* token;
  char buf[1000];
  const char* const tab = "\t";

  // open the input file
  ifstream fin;
  fin.open("123123.txt");
  if (!fin.good())
    cout << "I/O error. File can't find!\n";

  int linesProcessed = 0; // Counter for total lines processed
  // read the input file
  while (fin.good())
  {
    // read the line
    string line;
    getline(fin, line);
    strcpy(buf, line.c_str());

    if (buf[0] == 0) continue; // skip blank lines

    //parse the line
    const string term(token = strtok(buf, tab));
    const string section((token = strtok(0, tab)) ? token : "");
    const string course((token = strtok(0, tab)) ? token : "");
    const string instructor((token = strtok(0, tab)) ? token : "");
    const string whenWhere((token = strtok(0, tab)) ? token : "");
    if (course.find('-') == string::npos) continue; // invalid line: no dash in course name
    const string subjectCode(course.begin(), course.begin() + course.find('-'));

    // if I get this far, then it's a valid record
    cout << term << '|' << section << '|'
      << course << '|' << instructor << '|'
      << whenWhere << '|' << subjectCode << endl;
    // increment the linesProcessed variable
    linesProcessed++;

  }
  fin.close();
  cout << "Total lines processed: " << linesProcessed << endl;

    return 0;
}


