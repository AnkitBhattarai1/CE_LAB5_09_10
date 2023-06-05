#include <LinkedList.h>
#include <iostream>
using namespace std;

template <class T>
Node<T>::Node()
{
}

template <class T>
void Node<T>::setinfo(T data)
{ // sets the info of the node
	this->info = data;
}

template <class T>
void Node<T>::setnext(Node<T>* next)
{ // sets the next pointer to next Node of the Node.
	this->next = next;
}

template <class T>
Node<T>* Node<T>::getnext()
{ // returns the pointer to the next Node .
	return next;
}

template <class T>
T Node<T>::getData()
{ // returns the data stored in the node.
	return info;
}

/*-----LinkedList------LinkedList--------*/
template <class T>
LinkedList<T>::LinkedList()
{ // Initializes an empty LinkedList.
	HEAD = NULL;
}

template <class T>
bool LinkedList<T>::isEmpty()
{ // checks if the LinkedList is empty or not.
	if (HEAD == NULL)
		return true;
	else
		return false;
}

template <class T>
bool LinkedList<T>::hasOneElement()
{ // checks if the LinkedList has only one element.
	if (HEAD == TAIL)
		return true;
	else
		return false;
}

// adds a node to the head of the LinkedList
template <class T>
Node<T>* LinkedList<T>::addToHead(T data)
{
	Node<T>* newnode = new Node<T>();
	newnode->setinfo(data);

	// sets the HEAD and TAIL to the new Node added. And,the next element of the only node to null
	if (isEmpty())
	{
		HEAD = newnode;
		TAIL = newnode;
		newnode->setnext(NULL);
	}

	// if the list is not empty , set the next of newnode to the HEAD then  the HEAD to the newnode
	else
	{
		newnode->setnext(HEAD);
		HEAD = newnode;
	}
	return newnode;
}

// adds a newnode to the Tail of the LinkedList.
template <class T>
Node<T>* LinkedList<T>::addToTail(T data)
{
	Node<T>* newnode = new Node<T>();
	newnode->setinfo(data);

	// if the list is empty, sets the HEAD and TAIL to the newnode i.e, newly added NOde
	if (isEmpty())
	{
		HEAD = newnode;
		TAIL = newnode;
		newnode->setnext(NULL);
	}
	// if the list is not empty, sets the next of newnode to NULL, next of present TAIL to newnode and TAIL to newnode
	else
	{
		newnode->setnext(NULL);
		this->TAIL->setnext(newnode);
		TAIL = newnode;
	}
	return newnode;
}

template <class T>
Node<T>* LinkedList<T>::add(T data, Node<T>* node)
{

	Node<T>* newnode = new Node<T>();
	newnode->setinfo(data);

	if (node == TAIL)
		return addToTail(data);

	else if (node == HEAD)
	{
		newnode->setnext(HEAD->getnext());
		HEAD->setnext(newnode);
		return newnode;
	}

	else
	{
		newnode->setnext(node->getnext());
		node->setnext(newnode);
		return newnode;
	}
}

template <class T>
T LinkedList<T>::removeFromHead()
{
	if (isEmpty())
	{
		cout << "The List is empty nothing to remove\n";
	}

	else
	{
		Node<T>* nodeToDelete = new Node<T>();
		nodeToDelete = HEAD;
		T data = nodeToDelete->getData();

		if (hasOneElement())
			HEAD = NULL;
		else
			HEAD = HEAD->getnext();
		delete nodeToDelete;
		return data;
	}
}

template <class T>
T LinkedList<T>::removeFromTail()
{
	if (isEmpty())
	{
		cout << "There is nothing to remove from the list" << endl;
	}
	else
	{
		Node<T>* nodeToDelete = TAIL;
		T data = TAIL->getData();
		if (hasOneElement())
			HEAD = NULL;

		else
		{
			Node<T>* temp;
			temp = findprev(TAIL);
			TAIL = temp;
			temp->setnext(NULL);
			delete nodeToDelete;
			return data;
		}
	}
}

template <class T>
T LinkedList<T>::remove(Node<T>* node)
{

	if (node == HEAD)
		return removeFromHead();
	else if (node == TAIL)
		return removeFromTail();

	else
	{
		Node<T>* nodeToDelete = node;
		T data = nodeToDelete->getData();

		Node<T>* prev = findprev(node);

		prev->setnext(nodeToDelete->getnext());

		delete nodeToDelete;
		return data;
	}
}

template <class T>
T LinkedList<T>::remove(T data)
{
	Node<T>* nodeToDelete = retrive(data);

	return remove(nodeToDelete);
}

template <class T>
void LinkedList<T>::traverse()
{
	Node<T>* temp = HEAD;

	while (temp != NULL)
	{
		cout << temp->getData() << endl;
		temp = temp->getnext();
	}
}

template <class T>
Node<T>* LinkedList<T>::findprev(Node<T>* node)
{
	Node<T>* temp = HEAD;

	while ((temp->getnext()) != node)
	{
		temp = temp->getnext();
	}
	return temp;
}

template <class T>
Node<T>* LinkedList<T>::retrive(T data)
{

	for (Node<T>* temp = HEAD; temp != NULL; temp = temp->getnext())
	{
		if (temp->getData() == data)
			return temp;
	}

	return NULL;
}

template <class T>
bool LinkedList<T>::search(T data)
{
	if ((retrive(data)) != NULL)
		return true;
	else
		return false;
}
