#include <iostream>
#include <string>
#include <ctime>
#include <cmath>
#include <cstdlib>
#include <cassert>
#include <fstream>
#include <cstring>
#include <iomanip>
#include<set>
#include <map>
using namespace std;

string searchSemester(int);

int main()
{
    // programmer's identification
   cout << "Programmer: Jie Zhou\n";
   cout << "Programmer's ID: 2047477\n";
   cout << "File: " << __FILE__ << endl << endl;

	map<string, set<string>> allKeys;

	char* token;
	char buf[1000];
	const char* const tab = "\t";

	ifstream fin;
	fin.open("dvc-schedule.txt");
	if (!fin.good()) throw "I/O error";

	while (fin.good())
	{
		string line;
		getline(fin, line);
		strcpy(buf, line.c_str());

		if (buf[0] == 0) continue;

		const string term(token = strtok(buf, tab));
		const string section((token = strtok(0, tab)) ? token : " ");
		const string course((token = strtok(0, tab)) ? token : " ");
		const string instructor((token = strtok(0, tab)) ? token : " ");
		const string whenWhere((token = strtok(0, tab)) ? token : " ");
		if (course.find('-') == string::npos) continue;
		const string subjectCode(course.begin(), course.begin() + course.find('-'));

		const string termSection = term + "-" + section;

		allKeys[termSection].insert(course);

	}

	fin.close();

	map<string, set<string>>::iterator it;
	set<string>::iterator ite;

	for (it = allKeys.begin(); it != allKeys.end(); it++)
	{
		if (it->second.size() > 1)
		{
			cout << "Multiple courses found for key (term-section) - " << it->first << ":\n";
			for (ite = it->second.begin(); ite != it->second.end(); ite++)
				cout << *(ite) << endl;
		}

	}
	return 0;
}
