#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <ctime>
#include <cmath>
#include <cstdlib>
#include <cassert>
#include <fstream>
#include <cstring>

using namespace std;

int main()
{
  cout << "Programmer: Jie Zhou\n";
  cout << "Programmer's ID: 2047477\n";
  cout << "File: " << __FILE__ << "\n\n" << endl;

  srand(unsigned(time(0)));
  rand();

  // programmer customizations go here
  int n = 8000; // THE STARTING PROBLEM SIZE (MAX 250 MILLION)
  string bigOh = "O(n)"; // YOUR PREDICTION: O(n), O(n log n), or O(n squared)

  cout.setf(ios::fixed);
  cout.precision(4);
  double elapsedSecondsNorm = 0;
  double expectedSeconds = 0;

  for (int cycle = 0; cycle < 4; cycle++, n*= 2)
  {
    // start the timer, do something, and stop the timer
    clock_t startTime = clock( );

    // open input file & check access
    ifstream fin;
    fin.open("dvc-schedule.txt");
    if (!fin.is_open())
    {
      cout << "ERROR: Unable to open the file." << endl;
      return 1;
    }

    // used to parse input file
    char* token;
    char buf[1000];
    const char* const tab = "\t";

    // read input file
    for (int i = 0; i < n; i++)
    {
      string data;
      getline(fin, data);
      strcpy(buf, data.c_str());
      if(buf[0] == 0) continue; // skip blank lines

      // parse each line
      const string term(token = strtok(buf, tab));
      const string section((token = strtok(0, tab)) ? token : "");
      const string courseName((token = strtok(0, tab)) ? token : "");
      const string instructor((token = strtok(0, tab)) ? token : "");
      const string whenWhere((token = strtok(0, tab)) ? token : "");
      if(courseName.find('-') == string::npos) continue;
      const string subjectCode(courseName.begin(), courseName.begin() + courseName.find('-'));

    }
    fin.close();

    clock_t endTime = clock( ); // stop the virtual timer

    // compute timing results
    double elapsedSeconds = (double)(endTime - startTime) / CLOCKS_PER_SEC;
    double factor = pow(2.0, double(cycle));
    if (cycle == 0)
      elapsedSecondsNorm = elapsedSeconds;
    else if (bigOh == "O(n)")
      expectedSeconds = factor * elapsedSecondsNorm;
    else if (bigOh == "O(n log n)")
      expectedSeconds = factor * log(double(n)) / log(n / factor) * elapsedSecondsNorm;
    else if (bigOh == "O(n squared)")
      expectedSeconds = factor * factor * elapsedSecondsNorm;

    // reporting block
    cout << elapsedSeconds;
    if (cycle == 0) cout << " (expected " << bigOh << ')';
    else cout << " (expected " << expectedSeconds << ')';
    cout << " for n=" << n << endl;
  }
  return 0;
}
