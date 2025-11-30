#include <iostream>
#include <string>
#include <ctime>
#include <cmath>
#include <cstdlib>
#include <cassert>
#include <fstream>
#include <cstring>
#include <queue>
#include "DynamicArray.h"
#include "AssociativeArray.h"

using namespace std;

int main()
{
    cout << "Programmer: Jie Zhou\n";
    cout << "Programmer's ID: 2047477\n";
    cout << "File: " << __FILE__ << endl << endl;


    ifstream fin;
    fin.open("dvc-schedule.txt");
    if (!fin.good())
    {
        cout << "Error. Unable to open the file." << endl;
        return 1;
    }

    // Initialize seen and courseCount with default values
    AssociativeArray<string, AssociativeArray<string, bool>> seen;
    AssociativeArray<string, AssociativeArray<string, int>> courseCount;

    int duplicates = 0;
    int total = 0;

    // Process each line in the file
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
        if (course.find('-') == string::npos) continue;
        const string subjectCode(course.begin(), course.begin() + course.find('-'));

        // Total and check for duplicates
        total++;
        if (seen[term].containsKey(section))
        {
            duplicates++;
            continue;
        }
        else
        {
            seen[term][section] = true;
            if (!courseCount[subjectCode].containsKey(course))
            {
                courseCount[subjectCode][course] = 0;
            }
            courseCount[subjectCode][course]++;
        }
    }
    fin.close();

    // Output the results
    cout << "The number of duplicates is: " << duplicates << '\n';
    cout << "The total is: " << total << '\n';

    // Create a sorted array of courses
    AssociativeArray<int, string> courseArray;
    queue<string> courseQueue = courseCount.keys();

    // Copy courseQueue to courseArray
    for (int i = 0; !courseQueue.empty(); i++)
    {
        courseArray[i] = courseQueue.front();
        courseQueue.pop();
    }

    // Sort courseArray
    for (int i = 0; i < courseArray.size(); i++)
        for (int j = i + 1; j < courseArray.size(); j++)
            if (courseArray[i] > courseArray[j])
                swap(courseArray[i], courseArray[j]);

    // Output the courses and their counts
    for (int i = 0; i < courseCount.size(); i++)
    {
        AssociativeArray<int, string> subjectArray;
        queue<string> subjectQueue = courseCount[courseArray[i]].keys();

        // Copy subjectQueue to subjectArray
        for (int j = 0; !subjectQueue.empty(); j++)
        {
            subjectArray[j] = subjectQueue.front();
            subjectQueue.pop();
        }

        // Sort subjectArray
        for (int k = 0; k < subjectArray.size(); k++)
            for (int m = k + 1; m < subjectArray.size(); m++)
                if (subjectArray[k] > subjectArray[m])
                    swap(subjectArray[k], subjectArray[m]);

        // Output the subjects and their section counts
        AssociativeArray<int, string> outputs;

        for (int n = 0; n < subjectArray.size(); n++)
        {
            string s = "  " + subjectArray[n] + ", " + to_string(courseCount[courseArray[i]][subjectArray[n]]) + " section(s)";
            outputs[n] = s;
        }

        if (courseArray[i] != "" && (courseCount[courseArray[i]].size()) > 0)
            cout << courseArray[i] << ", " << courseCount[courseArray[i]].size() << " course(s)" << endl;

        for (int p = 0; p < outputs.size(); p++)
            cout << outputs[p] << endl;
    }

    return 0;
}
