#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <fstream>
#include "Queue.h"
#include "DynamicArray.h"

using namespace std;

struct Customer
{
    char id;
    int arrivalTime;
    int endTime;
};

int getRandomNumberOfArrivals(double);
char getNewCustomerId();


int customerCounter = 0;

int main()
{
    cout << "Programmer: Jie Zhou\n";
    cout << "Programmer's ID: 2047477\n";

    ifstream inputF;
    inputF.open("simulation.txt");
    if (!inputF.good())
    {
        cout << "I/O Error: File not found\n";
        return 1;
    }

    srand(time(0));

    int serversNum = 4;
    double rate = 2.5;
    int waitLength = 8;
    int minTime = 3;
    int maxTime = 10;
    int totalTime = 35;


    // Display the initialized values
    cout << "Number of servers: " << serversNum << endl;
    cout << "Customer arrival rate: " << rate << " per minute, for " << totalTime << " minutes" << endl;
    cout << "Maximum queue length: " << waitLength << endl;
    cout << "Minimum service time: " << minTime << " minutes" << endl;
    cout << "Maximum service time: " << maxTime << " minutes" << endl;

    Queue<Customer> waitQueue;
    DynamicArray<Customer> nowServing(serversNum);
    DynamicArray<bool> serverStatus(serversNum);

    // Initialize server status to false
    for (int i = 0; i < serversNum; ++i)
    {
        serverStatus[i] = false;
    }

    // Main simulation loop
    for (int time = 0;; time++)
    {
        // Update server status
        for (int i = 0; i < serversNum; i++)
        {
            if (serverStatus[i] && nowServing[i].endTime == time)
            {
                serverStatus[i] = false; // Server becomes
            }
        }

        // Handle new arrivals
        if (time < totalTime)
      {
            int arrivalNum = (time == 0) ? 1 : getRandomNumberOfArrivals(rate); // Add only one customer if time is 0
            for (int i = 0; i < arrivalNum; i++)
            {
                if (waitQueue.size() <= waitLength)
                {
                    Customer newCustomer;
                    newCustomer.id = getNewCustomerId(); // Get a new unique customer ID
                    newCustomer.arrivalTime = time;
                    waitQueue.push(newCustomer);
                }

            }
        }

        // Assign customers to servers
        for (int i = 0; i < serversNum; i++)
        {
            if (!serverStatus[i] && !waitQueue.empty() && time > 0)
            {
                nowServing[i] = waitQueue.front();
                waitQueue.pop();

                int serviceTime = minTime + rand() % (maxTime - minTime +1) ;
                nowServing[i].endTime = time + serviceTime;
                serverStatus[i] = true;
            }
        }

        // Display current time and server status
        cout << "Time: " << time << endl;
        cout << "-----------------------------------" << endl;
        cout << "server     now serving         wait line" << endl;
        cout << "------   ---------------    --------------" << endl;
        for (int i = 0; i < serversNum; i++)
        {
            cout << "  " << i << "        " << "     ";//Initial line

            if (serverStatus[i] == false) {
                if (i == 0) {//Output the wait line
                    cout << "                ";
                    Queue<Customer> copy = waitQueue;
                    for (int i = 0; i < waitQueue.size(); i++)
                    {
                        cout << copy.front().id;
                        copy.pop();
                    }
                }
                cout << "\n";
            }
            else
            {
                cout << nowServing[i].id << "     ";
                if (i == 0) {//Output the wait line
                    cout << "       ";
                    Queue<Customer> copy = waitQueue;
                    for (int i = 0; i < waitQueue.size(); i++)
                    {
                        cout << copy.front().id;
                        copy.pop();
                    }
                }
                cout << "\n";
            }
        }

        // Check for simulation end
        bool end = true;
        if (!waitQueue.empty() || time < totalTime)
        {
            end = false;
        }
        for (int i = 0; i < serversNum; i++)
        {
            if (serverStatus[i])
            {
                end = false;
                break;
            }
        }
        if (end)
        {
            cout << "\nSimulation end!\n";
            break;
        }

        // Pause for user input to continue
        cout << "Press enter to continue....\n";
        cin.get();
    }

    return 0;
}

// Function to get a random number of arrivals
int getRandomNumberOfArrivals(double averageArrivalRate)
{
    int arrivals = 0;
    double probOfnArrivals = exp(-averageArrivalRate);
    for (double randomValue = (double)rand() / RAND_MAX; (randomValue -= probOfnArrivals) > 0.0; probOfnArrivals *= averageArrivalRate / static_cast<double>(++arrivals));
    return arrivals;
}

// Function to generate a new customer ID
char getNewCustomerId()
{
    return 'A' + (customerCounter++ % 26);
}
