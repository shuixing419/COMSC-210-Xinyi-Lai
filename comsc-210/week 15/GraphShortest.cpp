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

pair<stack<int>, double> getShortestRoute(int iStart, int iEnd, vector<Node>& database)
{
    pair<stack<int>, double> result;
    list<pair<int, double> >::iterator it;  // to iterate over neighbors
  // TO DO -- write this function
    //initialization
    for (unsigned int i = 0; i < database.size(); i++)
    {
        database[i].isVisited = false;
        database[i].prev = -1;
        database[i].cost = 0;
    }


    queue<int> todo;
    //mark start node
    database[iStart].isVisited = true;
    todo.push(iStart);

    while (!todo.empty())
    {
        int NodeUnderCons = todo.front();
        todo.pop();
        for (it = database[NodeUnderCons].neighbors.begin(); it != database[NodeUnderCons].neighbors.end(); it++)
        {
            if (database[(*it).first].isVisited) continue;
            database[(*it).first].cost = 1 + database[NodeUnderCons].cost;
            database[(*it).first].prev = NodeUnderCons;
            todo.push((*it).first);
            database[(*it).first].isVisited = true;
            if ((*it).first == iEnd)
            {
                int size = todo.size();
                for (int i = 0; i < size; i++)
                {
                    todo.pop();
                }
                break;
            }
        }
    }

    //the route's cost equals the end node's cost
    result.second = database[iEnd].cost;

    //build a stack of entries, starting from the end node, back towards the start
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
    cout << "Shorest Route\n";
    cout << "File: " << __FILE__ << endl;

    ifstream fin;
    fin.open("cities.txt");
    if (!fin.good()) throw "I/O error";



    vector<Node> database;
    while (fin.good())
    {
        string fromCity, toCity, cost;

        // read one edge
        getline(fin, fromCity);
        getline(fin, toCity);
        getline(fin, cost);
        fin.ignore(1000, 10);// skip the separator

       // add nodes for new cities included in the edge
       int iToNode = -1, iFromNode = -1, i;
        for (i = 0; i < database.size(); i++)// seek "to" city
            if (database[i].name == fromCity)
                break;
        if (i == database.size()) // not in database yet
        {

            Node fromNode = {fromCity};
            database.push_back(fromNode);
        }
        iFromNode = i;

        for (i = 0; i < database.size(); i++)// seek "from" city
            if (database[i].name == toCity)
                break;
        if (i == database.size())// not in vector yet
        {
            // store the node if it is new
            Node toNode = { toCity };
            database.push_back(toNode);
        }
        iToNode = i;

        // store bi-directional edges
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
        int iTo;
        for (iTo = 0; iTo < database.size(); iTo++)
            if (database[iTo].name == toCity)
                break;

        cout << "Route";
        pair<stack<int>, double> result = getShortestRoute(iFrom, iTo, database);
        for (; !result.first.empty(); result.first.pop())
            cout << '-' << database[result.first.top()].name;
        cout << "Total edges: " << result.second;
        cout << endl;
    }
}
