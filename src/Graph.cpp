
#include <iostream>
#include <tuple>
#include "graphWithList.h"

using namespace std;


GraphWithList::GraphWithList(bool isDirected)
{
  this->Directed = isDirected;
}
GraphWithList::~GraphWithList()
{
  for (int i = 0; i < v.size(); i++)
  {
    delete v[i];
  }
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
int GraphWithList ::noOfVertices()
{
  return v.size();
}
int GraphWithList ::noOfEdges()
{
  int edgeCount = 0;
  for (int i = 0; i < v.size(); i++)
  {
    Node *current = l[i].HEAD;
    while (current != nullptr)
    {
      edgeCount++;
      current = current->next;
    }
  }
  if (!isDirected())
  {
    edgeCount /= 2;
  }

  return edgeCount;
}
int GraphWithList ::outDegree(int vertex)
{
  if (isDirected())
  {
    int outCount = 0;
    for (int i = 0; i < v.size(); i++)
    {

      if (v[i]->info == vertex)
      {
        Node *current = l[i].HEAD;
        while (current != nullptr)
        {
          outCount++;
          current = current->next;
        }
        break;
      }
    }
    return outCount;
  }
  else
    return degree(vertex);
}
int GraphWithList ::inDegree(int vertex)
{
  if (isDirected())
  {
    int inCount = 0;

    for (int i = 0; i < v.size(); i++)
    {
      Node *current = l[i].HEAD;
      while (current != nullptr)
      {
        if (current->info == vertex)
        {
          inCount++;
        }
        current = current->next;
      }
    }
    return inCount;
  }
  else
    return degree(vertex);
}
int GraphWithList ::degree(int vertex)
{
  if (isDirected())
  {
    return (inDegree(vertex) + outDegree(vertex));
  }

  else
  {
    int degCount = 0;

    for (int i = 0; i < v.size(); i++)
    {
      if (v[i]->info == vertex)
      {
        Node *current = l[i].HEAD;
        while (current != nullptr)
        {
          degCount++;

          current = current->next;
        }
        break;
      }
    }
    return degCount;
  }
}
void GraphWithList ::neighbours(int vertex)
{
  for (int i = 0; i < v.size(); i++)
  {
    if (v[i]->info == vertex)
    {
      l[i].traverse();
      break;
    }
  }
}
bool GraphWithList ::isNeighbour(int vertex1, int vertex2)
{
  for (int i = 0; i < v.size(); i++)
  {
    if (v[i]->info == vertex1)
    {
      Node *current = l[i].HEAD;
      while (current != nullptr)
      {
        if (current->info == vertex2)
        {
          return true;
        }
        current = current->next;
      }
      break;
    }
  }
  return false;
}
