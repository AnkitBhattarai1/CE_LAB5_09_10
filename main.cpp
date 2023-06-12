
#include <iostream>
#include "graphWithList.h"
using namespace std;

int main()
{


  GraphWithList graph(true);
  cout << "Graph is empty: " << graph.isEmpty() << endl;
  cout << "Graph is directed: " << graph.isDirected() << endl;
  graph.addVertex(1);
  graph.addVertex(2);
  graph.addVertex(3);
  graph.addVertex(4);
  graph.addEdge(1, 2);
  graph.addEdge(2, 3);
  graph.addEdge(3, 4);
  graph.addEdge(4, 1);
  cout << "Graph is empty: " << graph.isEmpty() << endl;
  cout << "List " << endl;
  for (int i = 0; i < graph.v.size(); i++)
  {
    cout << graph.v[i]->info << " ";
    graph.l[i].traverse();
  }


 

  cout << "Removing vertex 3" << endl;
  graph.removeVertex(3);
  

  cout << "List :" << endl;
  for (int i = 0; i < graph.v.size(); i++)
  {
    cout << graph.v[i]->info << " ";
    graph.l[i].traverse();
  }
  return 0;
}
