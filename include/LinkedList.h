#ifndef _LinkedList_h_
#define _LinkedList_h_

class Node
{
public:
    int info;
    Node *next;

    Node() {}
    Node(int data)
    {
        info = data;
        next = nullptr;
    }

    Node(int data, Node *point)
    {
        info = data;
        next = point;
    }

    ~Node() {}
};
class LinkedList
{
public:
    Node *HEAD;
    Node *TAIL;
    LinkedList()
    {
        HEAD = nullptr;
        TAIL = nullptr;
    }
    bool isEmpty();
    void add(int data, Node *predecessor);
    void addToHead(int data);
    void addToTail(int data);
    void removeFromHead();
    void remove(int data);
    Node *retrive(int data, Node *outputNodePointer);
    bool search(int data);
    void traverse();
    void removeFromTail();
};

#endif // !_LinkedList_h_