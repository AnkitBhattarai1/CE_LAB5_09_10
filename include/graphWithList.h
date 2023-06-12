#ifndef GRAPHWITHLIST_H
#define GRAPHWITHLIST_H

#include <iostream>
#include <vector>
#include "linkedlist.h"
using namespace std;
class GraphWithList
{
public:
    vector<LinkedList> l;
    vector<Node *> v;
    bool Directed;
    GraphWithList(bool isDirected);
    bool isEmpty();
    bool isDirected();
    void addVertex(int vertex);
    void addEdge(int vertex1, int vertex2);
    void removeVertex(int vertex);
    void removeEdge(int vertex1, int vertex2);
    int noOfVertices();
    int noOfEdges();
    int inDegree(int vertex);
    int outDegree(int vertex);
    int degree(int vertex);
    void neighbours(int vertex);
    bool isNeighbour(int vertex1, int vertex2);
    ~GraphWithList();
};

#endif // !GRAPHWITHLIST_H