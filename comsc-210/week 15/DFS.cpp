//Solution file for COMSC-210
//Module 15 - Graph Searches
//Lab Exercise 15 Part 2
//DFS.cpp (use a stack to build up the to-do list)

#include <fstream>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <string>
#include <vector>
using namespace std;

struct Node
{
  string name;

  bool isVisited;
  list<int> neighbors;
};

// DFS return a queue contains the indexes of all reachable nodes
queue<int> DFS(int iOriginNode, vector<Node>& database)
{
  queue<int> result; // return this queue of indices
  stack<int> toDo; // stack

  // initialization
  for(int i = 0; i < database.size(); i++)
  {
    database[i].isVisited = false;
  }

  // push start node to "to do"
  toDo.push(iOriginNode);
    
  while(!toDo.empty())
  {
    int i = toDo.top(); // peek 
    toDo.pop(); // pop

    // not yet visited
    if(!database[i].isVisited)
    {
      // mark
      database[i].isVisited = true;
      // push index
      result.push(i);
      
      // reverse order
      list<int> neighbors = database[i].neighbors;
      for(list<int>::reverse_iterator rit = neighbors.rbegin(); rit != neighbors.rend(); ++rit)
      {
        if(!database[*rit].isVisited)
        {
          toDo.push(*rit);
        }
      }
    }
  }
  //  return the result queue
  return result;
}

int main()
{
  cout << "Lab Exercise 15\n"
       << "Solution file (Part 2)\n"
       << "File: " << __FILE__ << "\n\n";

  ifstream fin;
  fin.open("cities.txt");
  if(!fin.good()) throw "I/O error";

  // process the input file to build up the database****
  vector<Node> database;
  while(fin.good()) // EOF loop
  {
    string fromCity, toCity;

    // read one edge
    getline(fin, fromCity);
    getline(fin, toCity);
    fin.ignore(1000, 10); // skip the line with distance
    fin.ignore(1000, 10); // skip the separator

    // add vertices for new cities included in the edge
    int iToNode = -1, iFromNode = -1, i;
    for(i = 0; i < database.size(); i++) // seek "to" city
      if(database[i].name == fromCity)
        break;
    if(i == database.size()) // not in database yet
    {
      // store the node if it is new
      Node fromNode = {fromCity};
      database.push_back(fromNode);
    }
    iFromNode = i;

    for(i = 0; i < database.size(); i++) // seek "from" city
      if(database[i].name == toCity)
        break;
    if(i == database.size()) // not in vector yet
    {
      // store the node if it is new
      Node toNode = {toCity};
      database.push_back(toNode);
    }
    iToNode = i;

    // store bi-directional edges
    database[iFromNode].neighbors.push_back(iToNode);
    database[iToNode].neighbors.push_back(iFromNode);
  }
  fin.close();
  cout << "Input file processed\n\n";
  // End of process the input file to build up the database****
    
  while(true)
  {
    // get the start city for the search
    string startCity;
    cout << "\nEnter the start city [blank to exit]: ";
    getline(cin, startCity);
    if(startCity.length() == 0) break;

    // find the start city
    int i;
    for(i = 0; i < database.size(); i++)
      if(database[i].name == startCity)
        break;

    // DFS result by copy-pop
    cout << "DFS";
    for(queue<int> q = DFS(i, database); !q.empty(); q.pop())
      cout  << '-'<< database[q.front()].name;
    cout << endl;
  }
}
