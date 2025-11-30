// Demo file for COMSC-210
// Module 15 - Graph Searches
// Reading from the text file, cities.txt to build out the link database
// databaseBuild.cpp

#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <list>
using namespace std;

struct Node
{
  string name;

  bool isVisited;
  list<int> neighbors;
};

int main()
{
  cout << "Module 15\n"
       << "Demo file - Build up the database\n"
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
    for ( i = 0; i < database.size(); i++) // seek "to" city
      if (database[i].name == fromCity)
        break;
    if ( i == database.size()) // not in database yet
    {
      // store the node if it is new
      Node fromNode = {fromCity};
      database.push_back(fromNode);
    }
    iFromNode = i;

    for ( i = 0; i < database.size(); i++) // seek "from" city
      if ( database[i].name == toCity)
        break;
    if ( i == database.size()) // not in vector yet
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
    
  cout << "==Display All Nodes with the Index and the City Name==" << endl;
  for (int i = 0; i < database.size(); i++)
  {
    cout << "Index = " << i << "; City Name: " << database[i].name << endl;
    list<int>::const_iterator it;
    cout << "Neighbors: Index     City Name" << endl;
    for (it = database[i].neighbors.begin(); it != database[i].neighbors.end(); it++)
    {
      cout << setw(15) << *it;
      cout << setw(15) << database[*it].name << endl;
    }
    cout << endl;
  }
}
