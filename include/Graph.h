#ifndef GRAPH_H
#define GRAPH_H

#include<vector>
#include<LinkedList.h>

template<class T>
class graph
{
private:
public:
    vector<LinkedList<T>> l;
    vector<Node<T>*> v;
    bool Directed;
    graph(bool isDirected);
    bool isEmpty();
    bool isDirected();
    void addVertex(int vertex);
    void addEdge(int vertex1, int vertex2);
    void removeVertex(int vertex);
    void removeEdge(int vertex1, int vertex2);
    int noOfVertices();
   
};


#include"Graph.cpp"
#endif