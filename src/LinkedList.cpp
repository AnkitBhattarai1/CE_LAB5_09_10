#include "LinkedList.h"

#include <iostream>
using namespace std;

bool LinkedList::isEmpty()
{
    return HEAD == nullptr;
}
void LinkedList::addToHead(int data)
{
    Node *newNode = new Node(data);
    newNode->next = HEAD;
    if (isEmpty())
    {
        HEAD = newNode;
        TAIL = newNode;
    }
    else
        HEAD = newNode;
}

void LinkedList::addToTail(int data)
{
    Node *newNode = new Node(data);
    newNode->next = NULL;
    if (isEmpty())
    {
        HEAD = newNode;
        TAIL = newNode;
    }
    else
    {
        TAIL->next = newNode;
        TAIL = newNode;
    }
}
void LinkedList::add(int data, Node *predecessor)
{
    Node *newNode = new Node(data);
    newNode->next = predecessor->next;
    predecessor->next = newNode;
}
void LinkedList::removeFromHead()
{
    if (!isEmpty())
    {
        if (!isEmpty())
        {
            if (HEAD == TAIL)
            {
                HEAD = TAIL = NULL;
            }
            else
            {
                Node *nodeToDelete = new Node();
                nodeToDelete = HEAD;
                HEAD = nodeToDelete->next;
                delete nodeToDelete;
            }
        }
    }
}

void LinkedList::remove(int data)
{
    if (!isEmpty())
    {
        if (HEAD->info == data)
        {
            removeFromHead();
        }
        else
        {
            Node *temp = HEAD->next;
            Node *prev = HEAD;
            while (temp != nullptr)
            {

                if (temp->info == data)
                {
                    prev->next = temp->next;
                    temp = temp->next;

                    if (temp == TAIL)
                    {
                        TAIL = prev;
                        TAIL->next = nullptr;
                    }
                }
                else
                {
                    prev = prev->next;
                    temp = temp->next;
                }
            }
        }
    }
    else
    {
        cout << "list is empty" << endl;
    }
}
void LinkedList ::removeFromTail()
{
    if (!isEmpty())
    {

        if (HEAD == TAIL)
        {
            HEAD = TAIL = NULL;
        }
        else
        {
            Node *nodeToDelete = new Node();
            nodeToDelete = TAIL;
            Node *temp = new Node();
            temp = HEAD;
            while (temp->next != TAIL)
            {
                temp = temp->next;
            }

            TAIL = temp;
            TAIL->next = NULL;
            delete nodeToDelete;
        }
    }
}
Node *LinkedList::retrive(int data, Node *outputNodePointer)
{
    outputNodePointer = HEAD;
    while (outputNodePointer != NULL && outputNodePointer->info != data)
    {
        outputNodePointer = outputNodePointer->next;
    }
    return outputNodePointer;
}

bool LinkedList::search(int data)
{
    if (!isEmpty())
    {
        Node *search = HEAD;
        while (search != NULL && search->info != data)
        {
            search = search->next;
        }
        return (search != NULL);
    }
    return false;
}

void LinkedList::traverse()
{
    if (isEmpty())
    {
        cout << "List is empty" << endl;
        return;
    }

    else
    {
        Node *print = HEAD;

        while (print != NULL)
        {
            cout << print->info << "->";
            print = print->next;
        }
    }

    cout << endl;
}