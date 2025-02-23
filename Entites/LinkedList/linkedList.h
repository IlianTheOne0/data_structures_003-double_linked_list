#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "../../lib.h"
#include "../Item/item.h"

class Node
{
public:
	IItem* data;
	Node* nextNode;

	Node(IItem& value);
	virtual ~Node();
};

class LinkedList
{
protected:
	Node* head;
public:
	LinkedList();
	virtual ~LinkedList();

	virtual void insertValue(IItem& value);
	virtual bool deleteValue(IItem* value);

	virtual void clear();
	virtual bool isEmpty() const;
	virtual void show() const;
};

#endif