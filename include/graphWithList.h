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
};

#endif 