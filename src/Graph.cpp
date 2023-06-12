
#include <iostream>
#include <tuple>
#include "graphWithList.h"

using namespace std;


GraphWithList::GraphWithList(bool isDirected)
{
  this->Directed = isDirected;
}
bool GraphWithList ::isDirected()
{
  return Directed;
}
bool GraphWithList ::isEmpty()
{
  return (v.empty());
}
void GraphWithList ::addVertex(int vertex)
{
  Node *newVertex = new Node(vertex);
  v.push_back(newVertex);
  LinkedList newList;
  l.push_back(newList);
}
void GraphWithList ::addEdge(int vertex1, int vertex2)
{
  if (!isDirected())
  {
    for (int i = 0; i < v.size(); i++)
    {
      if (v[i]->info == vertex1)
      {
        if (!(l[i].search(vertex2)))
        {
          l[i].addToHead(vertex2);
          v[i]->next = l[i].HEAD;
        }
        else
          cout << "already exists" << endl;
      }
      if (v[i]->info == vertex2)
      {
        if (!(l[i].search(vertex1)))
        {
          l[i].addToHead(vertex1);
          v[i]->next = l[i].HEAD;
        }
      }
    }
  }
  else
  {
    for (int i = 0; i < v.size(); i++)
    {
      if (v[i]->info == vertex1)
      {
        if (!(l[i].search(vertex2)))
        {
          l[i].addToHead(vertex2);
          v[i]->next = l[i].HEAD;
        }
        else
          cout << "already exists" << endl;
      }
    }
  }
}
void GraphWithList ::removeVertex(int vertex)
{
  int indexToRemove = -1;
  for (int i = 0; i < v.size(); i++)
  {
    if (v[i]->info == vertex)
    {
      indexToRemove = i;
    }
  }
  if (indexToRemove != -1)
  {
    delete v[indexToRemove];
    v.erase(v.begin() + indexToRemove);
    l.erase(l.begin() + indexToRemove);
    for (int i = 0; i < l.size(); i++)
    {
      l[i].remove(vertex);
    }
  }
}
void GraphWithList ::removeEdge(int vertex1, int vertex2)
{
  if (!isDirected())
  {
    for (int i = 0; i < l.size(); i++)
    {
      if (v[i]->info == vertex1)
      {
        l[i].remove(vertex2);
      }
      if (v[i]->info == vertex2)
      {
        l[i].remove(vertex1);
      }
    }
  }
  else
  {
    for (int i = 0; i < v.size(); i++)
    {
      if (v[i]->info == vertex1)
      {
        l[i].remove(vertex2);
      }
    }
  }
}

