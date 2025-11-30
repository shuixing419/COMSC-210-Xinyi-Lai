#include <iostream>
#include <string>
#include <ctime>
#include <cmath>
#include <cstdlib>
#include <cassert>
#include <fstream>
#include <cstring>
#include <queue>
#include <map>
using namespace std;

#include "HashTable.h"

int hashCode(const string&);
map<int,string> sorting(queue<string>);


int main()
{
    // identification
    cout << "Programmer:Jie Zhou \n";
    cout << "Programmer's ID: 2047477\n";
    cout << "File: " << __FILE__ <<endl;



    // declarations
    HashTable<string, bool, 7500> seen(hashCode);
    HashTable<string, int, 200> subclass(hashCode);
    int duplicates = 0;
    int total = 0;

    clock_t startTime = clock(); // Start timing

    ifstream fin;
    fin.open("dvc-schedule.txt");
    if(!fin.good()) throw "I/O error";
    while (fin.good())
    {
        char *token;
        char buf[1000];
        const char *const tab = "\t";
        string line;
        getline(fin, line);
        strcpy(buf, line.c_str());
        if (buf[0] == 0) continue;

        const string term(token = strtok(buf, tab));
        const string section(token = strtok(0, tab));
        const string course((token = strtok(0, tab)) ? token : "");
        const string instructor((token = strtok(0, tab)) ? token : "");
        const string whenWhere((token = strtok(0, tab)) ? token : "");
        if (course.find('-') == string::npos)
            continue;
        const string subjectCode(course.begin(), course.begin() + course.find('-'));
        const string classCode = term + section;

        if (seen[classCode])
        {
            duplicates++;
        }
        else
        {
            seen[classCode] = true;
            subclass[subjectCode]++;
        }

        total++;

    }
    fin.close();
    clock_t endTime = clock(); // End timing


    double elapsedSeconds = (double)(endTime - startTime) / CLOCKS_PER_SEC;


    cout << "\nFinished!" << endl;
    cout << "hashTable CAP = 88888/200" << endl;
    cout << "Total runtime: " << elapsedSeconds << " second(s)" << endl;
    cout << "The load factor for the duplication checking: " << seen.loadFactor() <<endl;
    cout << "The average list size for the duplication checking: " << (double)seen.size() / total << std::endl;
    cout << "The load factor for the subject code: " << subclass.loadFactor() << endl;
    cout << "Total duplication: " << duplicates << endl;
    cout << "Total records: " << total << endl;
    cout << "Total subjects: " << subclass.size() <<endl;

    queue<string> coursesKeys;
    coursesKeys = subclass.keys();
    map<int,string>  courseArray = sorting(coursesKeys);
    for (int i = 0; i < subclass.size(); i++)
    {
        cout << courseArray[i] << ", " << subclass[courseArray.at(i)] << " course(s)" << endl;
    }




    return 0;
}

int hashCode(const string& key)
{
    int index = 0;
    for (int i = 0; i < key.size(); i++)
        index = (index * 31 + key[i]) % 90000;
    return index;
}

map<int,string> sorting(queue<string> q )
{
    map<int,string> Array;
    for (int i = 0; !q.empty(); i++)
    {
        Array[i] = q.front();
        q.pop();
    }

    for (int i = 0; i < Array.size(); i++)
        for (int j = i + 1; j < Array.size(); j++)
            if (Array[i] > Array[j])
                swap(Array[i], Array[j]);

    return Array;
}
