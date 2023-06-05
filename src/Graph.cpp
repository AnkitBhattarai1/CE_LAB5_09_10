#include<iostream>
#include<Graph.h>
using namespace std;




template<class T>
graph<T>::graph(bool isDirected)
{
    this->Directed = isDirected;
}

template<class T>
bool graph<T>::isDirected()
{
    return Directed;
}
template<class T>
bool graph<T>::isEmpty()
{
    return (v.empty());
}

template<class T>
void graph<T>::addVertex(int vertex)
{
    Node<T>* newVertex = new Node<T>();
    newVertex->setinfo(vertex);
    v.push_back(newVertex);
    LinkedList<T> newList;
    l.push_back(newList);
}

template<class T>
void graph<T>::addEdge(int vertex1, int vertex2)
{
    if (!isDirected())
    {
        for (int i = 0; i < v.size(); i++)
        {
            if (v[i]->getData() == vertex1)
            {
                if (!(l[i].search(vertex2)))
                {
                    l[i].addToHead(vertex2);
                    v[i]->getnext()->setnext(l[i].getHead());

                }
                else cout << "already exists" << endl;

            }
            if (v[i]->getData() == vertex2)
            {
                if (!(l[i].search(vertex1)))
                {
                    l[i].addToHead(vertex1);
                    v[i]->getnext()->setnext(l[i].getHead());
                }

            }
        }
    }
    else
    {
        for (int i = 0; i < v.size(); i++)
        {
            if (v[i]->getData() == vertex1)
            {
                if (!(l[i].search(vertex2)))
                {
                    l[i].addToHead(vertex2);
                    v[i]->getnext()->setnext(l[i].getHead());
                }
                else cout << "already exists" << endl;
            }
        }
    }
}

template<class T>
void graph<T>::removeVertex(int vertex)
{
    int indexToRemove = -1;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i]->getData() == vertex)
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

template<class T>
void graph<T>::removeEdge(int vertex1, int vertex2)
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

template<class T>
int graph<T>::noOfVertices()
{
    return v.size();
}


