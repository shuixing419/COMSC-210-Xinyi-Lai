#define _CRT_SECURE_NO_WARNINGS

#include <fstream>
#include <iostream>
#include <string>
#include "DynamicArray.h"
using namespace std;

#include <cstring> // for strtok and strcpy

struct subject
{
    string subjectCode;
    int count;
};

int main()
{
    cout << "Programmer: Jie Zhou\n";
    cout << "Programmer's ID: 2047477\n";
    cout << "File: " << __FILE__ << "\n\n" << endl;
    DynamicArray<string> nonDuplicateClasses(100);
    DynamicArray<subject> subjectCount(100);
    int count = 0;
    int duplicates = 0;
    int classIndex = 0;    // index for nonDuplicateClasses array
    int subjectIndex = 0;  // index for subjectCount array

    // for parsing the inputfile
    char* token;
    char buf[1000];
    const char* const tab = "\t";

    // open the input file
    ifstream fin;
    fin.open("dvc-schedule.txt");
    if (!fin.good())
        throw "I/0 error";

    // read the input file
    while (fin.good())
    {
        // read the line
        string line;
        getline(fin, line);
        strcpy(buf, line.c_str());

        if (buf[0] == 0)
            continue;

        //parse the line
        const string term(token = strtok(buf, tab));
        const string section((token = strtok(0, tab)) ? token : "");
        const string course((token = strtok(0, tab)) ? token : "");
        const string instructor((token = strtok(0, tab)) ? token : "");
        const string whenWhere((token = strtok(0, tab)) ? token : "");
        if (course.find('-') == string::npos)
            continue; // invalid line: no dash in course name
        const string subjectCode(course.begin(), course.begin() + course.find('-')); // invalid line: no dash in course name

        string classCode = term + "." + section;
        // if I get this far, then it's a valid record
    cout << term << '|' << section << '|'
      << course << '|' << instructor << '|'
      << whenWhere << '|' << subjectCode << endl;
        //duplicate check
        int i = 0;
        for (i = 0; i < classIndex; i++)
        {
            if (nonDuplicateClasses[i] == classCode)
                break;
        }

        if (i == classIndex)
        {
            // it is not duplicate
            nonDuplicateClasses[classIndex++] = classCode;
        }
        else
        {// it is a duplicate
            duplicates++;
            continue;
        }
        // find the subjectCode
        int s = 0;
        for (s = 0; s < subjectIndex; s++)
        {
            if (subjectCount[s].subjectCode == subjectCode)
            {//add one section to the count
                subjectCount[s].count++; // corrected the spelling
                break;
            }
        }

        if (s == subjectIndex)
        {// add a new subject object
            subjectCount[subjectIndex++] = { subjectCode, 1 };
        }

        count++;
    }


    for (int i = 0; i < subjectIndex; ++i)
    {
    cout << subjectCount[i].subjectCode << ", section: " << subjectCount[i].count << endl;
    }

    cout << "Total duplicates: " << duplicates << endl;
    cout << "Total counts " << count << endl;
    cout << "Total subjects: " << subjectIndex << endl;
    cout << "Program ended with exit code: 0" << endl;
    return 0;
}
