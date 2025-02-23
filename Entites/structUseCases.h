#ifndef DOUBLE_LINKEDLIST_USECASES_H
#define DOUBLE_LINKEDLIST_USECASES_H

#include "../Entites/struct.h"
#include <string>
using std::string;

template<typename TValue>
class DoubleLinkedListUseCases
	: public DoubleLinkedList<TValue>
{
private:
	DoubleLinkedList<TValue>* _head;
	DoubleLinkedList<TValue>* _tail;
public:
	DoubleLinkedListUseCases() : _head(nullptr), _tail(nullptr) {}
	DoubleLinkedListUseCases(const TValue& value) : DoubleLinkedList<TValue>(value) { _head = _tail = new DoubleLinkedList<TValue>(value); }
	~DoubleLinkedListUseCases() override { clear(); delete _head; delete _tail; }

	bool isEmpty() { return _head == nullptr; }

	void insertInHead(const TValue& value)
	{
		DoubleLinkedList<TValue>* newData = new DoubleLinkedList<TValue>(value);

		if (isEmpty()) { _head = _tail = newData; return; }
		newData->_next = _head;
		_head->_previous = newData;
		_head = newData;
	}
	void insertInTail(const TValue& value)
	{
		DoubleLinkedList<TValue>* newData = new DoubleLinkedList<TValue>(value);

		if (isEmpty()) { _head = _tail = newData; return; }
		newData->_previous = _tail;
		_tail->_next = newData;
		_tail = newData;
	}

	TValue deleteHead()
	{
		if (isEmpty()) { return TValue(); }

		TValue temp = _head->_data;

		if (_head == _tail) { _head = _tail = nullptr; return temp; }
		_head = _head->_next;
		_head->_previous = nullptr;
		return temp;
	}
	TValue deleteTail()
	{
		if (isEmpty()) { return TValue(); }

		TValue temp = _tail->_data;

		if (_head == _tail) { _head = _tail = nullptr; return temp; }
		_tail = _tail->_previous;
		_tail->_next = nullptr;
		return temp;
	}

	void clear() { while (!isEmpty()) { deleteHead(); } }
	string getList() const
	{
		DoubleLinkedList<TValue>* ptr = _head;
		string result;

		while (ptr != nullptr) { result += to_string(ptr->_data) + " "; ptr = ptr->_next; }

		return result;
	}

	DoubleLinkedList<TValue>* getHead() { return _head; }
	DoubleLinkedList<TValue>* getTail() { return _tail; }
};

#endif