#include <iostream>
#include <string>
#include <ctime>
#include <cmath>
#include <cstdlib>
#include <cassert>
#include <fstream>
#include <cstring>
#include <iomanip>
#include <queue>
#include <stack>
#include <list>
#include <vector>
#include <utility>
using namespace std;

struct Node
{
    string name;

    bool isVisited;
    list<pair<int, double> > neighbors;
    int prev;
    double cost;
};


struct Terminus  // the path to a node and the cost of that path
{
    int index;  // the node's index in the database array
    int prev;  // the index of the preceding node in the path
    double cost;  // the cost of getting to index's node from prev's node
};

bool operator < (const Terminus& a, const Terminus& b)
{
    return b.cost < a.cost;  //reverse logic for lo-to-hi
}

pair<stack<int>, double> getCheapestRoute(int iStart, int iEnd, vector<Node>& database)
{
    pair<stack<int>, double> result;
    list<pair<int, double> >::iterator it;
  // TO DO -- write this function
    for (unsigned int i = 0; i < database.size(); i++)
    {
        database[i].cost = 0;
        database[i].prev = -1;
        database[i].isVisited = false;
    }


    priority_queue<Terminus> todo;

    Terminus startNode;
    startNode.index = iStart;
    startNode.cost = 0;
    startNode.prev = -1;

    todo.push(startNode);

    while (!todo.empty())
    {
        Terminus NodeUnderCons = todo.top();
        todo.pop();
        if (database[NodeUnderCons.index].isVisited) continue;
        database[NodeUnderCons.index].isVisited = true;
        database[NodeUnderCons.index].cost = NodeUnderCons.cost;
        database[NodeUnderCons.index].prev = NodeUnderCons.prev;
        if (NodeUnderCons.index == iEnd) break;
        for (it = database[NodeUnderCons.index].neighbors.begin(); it != database[NodeUnderCons.index].neighbors.end(); it++)
        {
            Terminus neighbor;
            neighbor.index = (*it).first;
            neighbor.prev = NodeUnderCons.index;
            neighbor.cost = (*it).second + NodeUnderCons.cost;
            todo.push(neighbor);
        }
    }


    result.second = database[iEnd].cost;


    for (int endNode = iEnd; endNode >= 0; endNode = database[endNode].prev)
    {
        result.first.push(endNode);
    }

    return result;
}

int main()
{
    // Programmer's Identification
    cout << "Programmer: Jie Zhou\n";
    cout << "Programmer's ID: 2047477\n";
    cout << "Cheapest Route\n";
    cout << "File: " << __FILE__ << endl;

    ifstream fin;
    fin.open("cities.txt");
    if (!fin.good()) throw "I/O error";


    vector<Node> database;
    while (fin.good())
    {
        string fromCity, toCity, cost;

        getline(fin, fromCity);
        getline(fin, toCity);
        getline(fin, cost);
        fin.ignore(1000, 10);


        unsigned int iToNode = -1, iFromNode = -1, i;
        for (i = 0; i < database.size(); i++)
            if (database[i].name == fromCity)
                break;
        if (i == database.size())
        {

            Node fromNode;
            fromNode.name = fromCity;
            database.push_back(fromNode);
        }
        iFromNode = i;

        for (i = 0; i < database.size(); i++)
            if (database[i].name == toCity)
                break;
        if (i == database.size())
        {

            Node toNode;
            toNode.name = toCity;
            database.push_back(toNode);
        }
        iToNode = i;


        double edgeCost = atof(cost.c_str());
        database[iFromNode].neighbors.push_back(pair<int, double>(iToNode, edgeCost));
        database[iToNode].neighbors.push_back(pair<int, double>(iFromNode, edgeCost));
    }
    fin.close();
    cout << "Input file processed\n\n";

    while (true)
    {
        string fromCity, toCity;

        cout << "\nEnter the source city [blank to exit]: ";
        getline(cin, fromCity);
        if (fromCity.length() == 0) break;

        // find the from city
        unsigned int iFrom;
        for (iFrom = 0; iFrom < database.size(); iFrom++)
            if (database[iFrom].name == fromCity)
                break;

        cout << "Enter the destination city [blank to exit]: ";
        getline(cin, toCity);
        if (toCity.length() == 0) break;

        // find the destination city
        unsigned int iTo;
        for (iTo = 0; iTo < database.size(); iTo++)
            if (database[iTo].name == toCity)
                break;

        cout << "Route";
        pair<stack<int>, double> result = getCheapestRoute(iFrom, iTo, database);
        for (; !result.first.empty(); result.first.pop())
            cout << '-' << database[result.first.top()].name;
        cout << "Total miles: " << result.second;
        cout << endl;
    }
}
