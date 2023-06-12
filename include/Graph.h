#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <tuple>
#include <vector>
using namespace std;

class Graph
{
private:
   vector<tuple<int, vector<int>>> list;
  bool directed;

  bool isVertex(int data);

public:
  Graph(bool directed = false) : directed(directed) {}
  ~Graph() {}

  bool isEmpty();
  bool isDirected();
  void addVertex(int newVertex);
  void addEdge(int vert1, int vert2);
  void removeVertex(int vertToRemove);
  void removeEdge(int vert1, int vert2);

  int numVertices();
  int numEdges();
  int indegree(int vert);
  int outdegree(int vert);
  int degree(int vert);
  void neighbours(int vert);
  void neighbour(int vert1, int vert2);
};

#endif 
