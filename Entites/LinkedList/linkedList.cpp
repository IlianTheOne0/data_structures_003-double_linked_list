#include "linkedList.h"

Node::Node(IItem& value)
	: data(&value), nextNode(nullptr)
{}
Node::~Node()
{ }

LinkedList::LinkedList()
	: head(nullptr)
{ }
LinkedList::~LinkedList()
{ clear(); }

void LinkedList::insertValue(IItem& value)
{
	Node* newNode = new Node(value);

	if (head == nullptr) { head = newNode; return; }

	Node* currentNode = head;
	while (currentNode->nextNode != nullptr) { currentNode = currentNode->nextNode; }
	currentNode->nextNode = newNode;
}
bool LinkedList::deleteValue(IItem* value)
{
	if (!head) { return false; }

	if (head->data == value) { Node* nodeToDelete = head; head = head->nextNode; delete nodeToDelete; return true; }

	Node* currentNode = head;
	while (currentNode->nextNode != nullptr && currentNode->nextNode->data != value) { currentNode = currentNode->nextNode; }
	if (!currentNode->nextNode) { return false; }

	Node* nodeToDelete = currentNode->nextNode;
	currentNode->nextNode = nodeToDelete->nextNode;
	delete nodeToDelete;
	return true;
}

void LinkedList::clear()
{
	Node* currentNode = head;

	while (currentNode != nullptr) { Node* next = currentNode->nextNode; delete currentNode; currentNode = next; }

	head = nullptr;
}
bool LinkedList::isEmpty() const { return head == nullptr; }
void LinkedList::show() const
{
	Node* currentNode = head;

	while (currentNode != nullptr) {
		if (currentNode->data != nullptr) { currentNode->data->printValue(); cout << "; "; } currentNode = currentNode->nextNode;
	}
}