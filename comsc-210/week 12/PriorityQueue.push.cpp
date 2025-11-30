#include <iostream>
#include <string>
#include <ctime>
#include <cmath>
#include <cstdlib>
#include <cassert>
#include <fstream>
#include <cstring>
#include <queue>

#include "PriorityQueue.h"
using namespace std;

int main()
{
    cout << "Programmer: Jie Zhou\n";
    cout << "Programmer's ID: 2047477\n";
    cout << "File: " << __FILE__ << endl << endl;

    srand(unsigned(time(0))); rand();

    int n = 10000000;
    const int reps = n / 100;

    cout.setf(ios::fixed);
    cout.precision(4);
    double elapsedSecondsNorm = 0;
    double expectedSeconds = 0;

    for (int cycle = 0; cycle < 4; cycle++, n *= 2)
    {
        PriorityQueue<int> time_queue(n * 2);

        for (int i = 0; i < n; i++)
            time_queue.push(i);

        assert(time_queue.size() == n);

        PriorityQueue<int> test_queue = time_queue;
        while (!test_queue.empty())
        {
            int temp = test_queue.top();
            test_queue.pop();
            assert(temp >= test_queue.top());
        }

        // start timer
        clock_t startTime = clock();

        for (int rep = 0; rep < reps; rep++)
            time_queue.push(rand());

        // stop timer
        clock_t endTime = clock();

        assert(time_queue.size() == n + reps);
        test_queue = time_queue;

        while (!test_queue.empty())
        {
            int temp2 = test_queue.top();
            test_queue.pop();
            assert(temp2 >= test_queue.top());
        }

        // compute timing results
        double elapsedSeconds = (double)(endTime - startTime) / CLOCKS_PER_SEC;
        double factor = pow(2.0, double(cycle));

        if (cycle == 0)
            elapsedSecondsNorm = elapsedSeconds;

        expectedSeconds = log(double(n)) / log(n / factor) * elapsedSecondsNorm;

        // output section
        cout << expectedSeconds;
        if (cycle == 0)
            cout << " (expected O(log n))";
        else
            cout << " (expected: " << expectedSeconds << ')';
        cout << " for n=" << n << endl;
    }

    return 0;
}
