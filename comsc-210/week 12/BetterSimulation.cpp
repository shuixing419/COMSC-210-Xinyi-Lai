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

#include "Queue.h"
#include "DynamicArray.h"
#include "PriorityQueue.h"

struct Customer
{
  char IDtag;
  int arrivalTime;
  int serviceEndTime;
  Customer()
  {
    IDtag = '!';
    arrivalTime = 0;
    serviceEndTime = 0;
  }
  Customer(char IDtag, int arrivalTime, int serviceEndTime)
  {
    this->IDtag = IDtag;
    this->arrivalTime = arrivalTime;
    this->serviceEndTime = serviceEndTime;
  }
};

struct ServerInfo
{
  Customer customerInfo;
  bool status;
};

struct ServiceEvent
{
  int serverNumber;
  int endTime;
};

// prototypes
int getRandomNumberOfArrivals(double);
bool operator<(const ServiceEvent&, const ServiceEvent&);

int main()
{
  srand((unsigned)time(0)); rand();

  // identification
  cout << "Programmer: Jie Zhou\n";
  cout << "Programmer's ID: 2047477\n";
  cout << "File: " << __FILE__ << endl << endl;

  // read & input values from text file
  string data;
  string labels[5] = {"number of servers: ", "customer arrival rate: ",
    "maximum queue length: ", "minimum service time: ", "maximum service time: "};
  string values[6];

  ifstream fin("simulation.txt");
  if (!fin.good())
    cout << "Error: Unable to open file." << endl;

  for (int i = 0; i < 6; i++)
  {
    fin >> data;
    values[i] = data;
  }

  const unsigned int numServers = atoi(values[0].c_str());
  const double aveArrivalRate = atof(values[1].c_str());
  const unsigned int maxQueue = atoi(values[2].c_str());
  const unsigned int minServiceTime = atoi(values[3].c_str());
  const unsigned int maxServiceTime = atoi(values[4].c_str());
  const unsigned int customerStopTime = atoi(values[5].c_str());

  cout << left;
  cout << setw(27) << labels[0] << numServers << endl;
  cout << setw(27) << labels[1] << aveArrivalRate << " per minute, for " << customerStopTime << " minutes" << endl;
  cout << setw(27) << labels[2] << maxQueue << endl;
  cout << setw(27) << labels[3] << minServiceTime << " minutes" << endl;
  cout << setw(27) << labels[4] << maxServiceTime << " minutes" << endl << endl;

  fin.close();

  // declarations
  PriorityQueue<ServiceEvent> nowServing;   // array of customers being served
  DynamicArray<ServerInfo> servers;   // array of whether server is busy or free
  Queue<Customer> waitingLine; // wait queue

  // the clock time loop
  for (int time = 0;; time++) // the clock time
  {
    // handle all services scheduled to complete at this clock time
    while(!nowServing.empty() && nowServing.top().endTime == time)
    {
      servers[nowServing.top().serverNumber].status = false;
      nowServing.pop();
    }
    // handle new arrivals -- can be turned away if wait queue is at maximum length
    if (time < customerStopTime)
    {
      int randArrivals = getRandomNumberOfArrivals(aveArrivalRate);
      for (int i = 0; i < randArrivals; i++)
      {
        if (waitingLine.size() < maxQueue)
        {
          Customer c;
          static int name = 65;
          if (name == 91)
            name = 65;
          {
            c.IDtag = name;
            name++;
          }
          c.arrivalTime = time;
          waitingLine.push(c);
        }
      }
    }

    // for idle servers, move customer from wait queue and begin service for each server
    for (int i = 0; i < numServers; i++)
    {
      if (!servers[i].status && !waitingLine.empty())
      {
        servers[i].customerInfo = waitingLine.front();
        waitingLine.pop();

        servers[i].status = true;
        ServiceEvent temp;
        temp.serverNumber = i;

        temp.endTime = time + (minServiceTime + (rand() % maxServiceTime));
        nowServing.push(temp);
      }
    }

    // display the contents
    cout << "server | time for end-of-service\n"
    << "------ + -----------------------\n";

    for (PriorityQueue<ServiceEvent> temp = nowServing; !temp.empty(); temp.pop())
    {
        cout.width(4);
        cout << temp.top().serverNumber << "   |";
        cout.width(12);
        cout << temp.top().endTime << endl;
    }

    // output the summary
    cout << "Time: " << time << endl;
    cout << "---------------------------" << endl;
    cout << "server now serving wait queue" << endl;
    cout << "------ ----------- ----------" << endl;

    for (int i = 0; i < numServers; i++)
    {
      cout << setw(3) << right << i << setw(10);
      if (servers[i].status)
      {
        cout << servers[i].customerInfo.IDtag;

        if (i == 0 && !waitingLine.empty())
        {
          cout << setw(8);
          for (auto copyQ = waitingLine; !copyQ.empty(); copyQ.pop())
            cout << copyQ.front().IDtag;
        }
      }
      cout << endl;
    }

  // if the end of the simulation has been reached, break
    int numIdle = 0;

    for (int i = 0; i < numServers; i++)
      if (!servers[i].status)
        numIdle++;

    if (numIdle == numServers && time >= customerStopTime)
    {
      cout << "Done!" << endl;
      break;
    }
    do
    {
      cout << "---------------------------" << endl;
      cout << "Press ENTER to continue...";
    }
    while (cin.get() != '\n');

  }

  return 0;
}

int getRandomNumberOfArrivals(double averageArrivalRate)
{
  int arrivals = 0;
  double probOfnArrivals = exp(-averageArrivalRate);
  for (double randomValue = (double)rand( ) / RAND_MAX;
    (randomValue -= probOfnArrivals) > 0.0;
    probOfnArrivals *= averageArrivalRate / static_cast<double>(++arrivals));
  return arrivals;
}

bool operator<(const ServiceEvent& a, const ServiceEvent& b)
{
    return a.endTime < b.endTime ? false : true;
}
