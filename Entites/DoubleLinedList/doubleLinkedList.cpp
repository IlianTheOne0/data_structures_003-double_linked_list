#include "doubleLinkedList.h"

DoubleNode::DoubleNode(IItem& value)
	: Node(value), previousNode(nullptr)
{ }
DoubleNode::~DoubleNode() { }

DoubleLinkedList::DoubleLinkedList()
	: LinkedList(), tail(nullptr)
{ }

void DoubleLinkedList::insertValue(IItem& value)
{
	DoubleNode* newNode = new DoubleNode(value);

	if (head == nullptr) {
		head = newNode;
		tail = newNode;
	}
	else {
		tail->nextNode = newNode;
		newNode->previousNode = tail;
		tail = newNode;
	}
}
bool DoubleLinkedList::deleteValue(IItem* value)
{
	if (head == nullptr) { return false; }

	DoubleNode* currentNode = static_cast<DoubleNode*>(head);

	while (currentNode != nullptr && currentNode->data != value) { currentNode = static_cast<DoubleNode*>(currentNode->nextNode); }
	if (currentNode == nullptr) { return false; }

	if (currentNode->previousNode != nullptr) { currentNode->previousNode->nextNode = currentNode->nextNode; }
	else { head = currentNode->nextNode; }

	if (currentNode->nextNode != nullptr) { static_cast<DoubleNode*>(currentNode->nextNode)->previousNode = currentNode->previousNode; }
	else { tail = currentNode->previousNode; }

	delete currentNode;
	return true;
}