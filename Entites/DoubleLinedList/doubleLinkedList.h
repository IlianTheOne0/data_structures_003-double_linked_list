#ifndef DOUBLE_LINKED_LIST
#define DOUBLE_LINKED_LIST

#include "../LinkedList/linkedList.h"

class DoubleNode
	: public Node
{
public:
	DoubleNode* previousNode;

	DoubleNode(IItem& value);
	~DoubleNode() override;
};

class DoubleLinkedList
	: public LinkedList
{
protected:
	DoubleNode* tail;
public:
	DoubleLinkedList();
	~DoubleLinkedList() override = default;

	virtual void insertValue(IItem& value) override;
	virtual bool deleteValue(IItem* value) override;

	bool isEmpty() const override { return head == nullptr; }
};

#endif