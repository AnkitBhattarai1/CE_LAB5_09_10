
#include <iostream>
#include "graphWithList.h"
using namespace std;

int main()
{
  /*
  Graph graph;

  // Adding vertices
  graph.addVertex(1);
  graph.addVertex(2);
  graph.addVertex(3);
  graph.addVertex(4);

  // Adding edges
  graph.addEdge(1, 2);
  graph.addEdge(2, 3);
  graph.addEdge(3, 4);
  graph.addEdge(4, 1);

  // Removing a vertex
  graph.removeVertex(3);

  // Removing an edge
  graph.removeEdge(1, 2);

  // Displaying information about the graph
  cout << "Graph Information:" << std::endl;
  cout << "Is the graph empty? " << (graph.isEmpty() ? "Yes" : "No") << std::endl;
  cout << "Is the graph directed? " << (graph.isDirected() ? "Yes" : "No") << std::endl;
  */

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

  cout << "Number of vertices: " << graph.noOfVertices() << endl;
  cout << "Number of edges: " << graph.noOfEdges() << endl;
  cout << "In degree of vertex 1: " << graph.inDegree(1) << endl;
  cout << "Out degree of vertex 1: " << graph.outDegree(1) << endl;
  cout << "Degree of vertex 1: " << graph.degree(1) << endl;
  cout << "Neighbours of vertex 1: ";
  graph.neighbours(1);
  cout << "Is 1 a neighbour of 2: " << graph.isNeighbour(1, 2) << endl;

  cout << "Removing vertex 3" << endl;
  graph.removeVertex(3);
  cout << "Number of vertices: " << graph.noOfVertices() << endl;

  cout << "List :" << endl;
  for (int i = 0; i < graph.v.size(); i++)
  {
    cout << graph.v[i]->info << " ";
    graph.l[i].traverse();
  }
  return 0;
}
