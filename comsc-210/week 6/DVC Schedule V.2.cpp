#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include "DynamicArray.h"
#include "StaticArray.h"
#include <cstring> // for strtok and strcpy

using namespace std;

struct subject {
    string subjectCode;
    int count;
};

struct SectionForTerm {
    string term;
    int numberOFSectionsSeen;
    DynamicArray<string> seenSectionNumber;
};

// Comparator function for sorting subjects alphabetically by subject code
bool compareSubjects(const subject& a, const subject& b)
{
    return a.subjectCode < b.subjectCode;
}

int main() {
    cout << "Programmer: Jie Zhou\n";
    cout << "Programmer's ID: 2047477\n";
    cout << "File: " << __FILE__ << "\n\n";

    StaticArray<SectionForTerm, 100> alreadySeen;
    DynamicArray<subject> subjectCount(100);
    int count = 0;
    int duplicates = 0;
    int numberOFTerm = 0;
    int subjectIndex = 0;

    char* token;
    char buf[1000];
    const char* const tab = "\t";

    ifstream fin;
    fin.open("dvc-schedule.txt");
    if (!fin.good())
        throw "I/O error";

    while (fin.good()) {
        string line;
        getline(fin, line);
        strcpy(buf, line.c_str());

        if (buf[0] == 0)
            continue;

        const string term(token = strtok(buf, tab));
        const string section((token = strtok(0, tab)) ? token : "");
        const string course((token = strtok(0, tab)) ? token : "");
        const string instructor((token = strtok(0, tab)) ? token : "");
        const string whenWhere((token = strtok(0, tab)) ? token : "");
        if (course.find('-') == string::npos)
            continue;
        const string subjectCode(course.begin(), course.begin() + course.find('-'));

        string classCode = term + "." + section;

        int i = 0, j = 0;
        bool d_check = false;
        for (i = 0; i < numberOFTerm; i++) {
            if (alreadySeen[i].term == term) {
                break;
            }
        }

        if (i == numberOFTerm) {
            alreadySeen[i] = {term, 1, DynamicArray<string>(100)};
            alreadySeen[i].seenSectionNumber[0] = section;
            alreadySeen[i].numberOFSectionsSeen++;
            numberOFTerm++;
        } else {
            for (j = 0; j < alreadySeen[i].numberOFSectionsSeen; j++) {
                if (alreadySeen[i].seenSectionNumber[j] == section) {
                    d_check = true;
                    duplicates++;
                    break;
                }
            }

            if (j == alreadySeen[i].numberOFSectionsSeen) {
                alreadySeen[i].seenSectionNumber[j] = section;
                alreadySeen[i].numberOFSectionsSeen++;
            }
        }

        if (d_check)
            continue;

        int s = 0;
        for (s = 0; s < subjectIndex; s++) {
            if (subjectCount[s].subjectCode == subjectCode) {
                subjectCount[s].count++;
                break;
            }
        }

        if (s == subjectIndex) {
            subjectCount[subjectIndex++] = { subjectCode, 1 };
        }

        count++;
    }

    fin.close();

    cout << "Finish!\n";
    // Print subject counts
    sort(subjectCount.begin(), subjectCount.begin() + subjectIndex, compareSubjects);
    for (int i = 0; i < subjectIndex; ++i)
    {
        cout << subjectCount[i].subjectCode << ", " << subjectCount[i].count << " section\n";
    }

    cout << "Total duplication: " << duplicates << endl;
    cout << "Total counts: " << count << endl;
    cout << "Total subjects: " << subjectIndex << endl;
    cout << "Program ended with exit code: 0" << endl;

    return 0;
}
