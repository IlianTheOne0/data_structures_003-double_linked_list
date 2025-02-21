#ifndef DOUBLE_LINKEDLIST_H
#define DOUBLE_LINKEDLIST_H

template<typename TValue>
class DoubleLinkedList
{
public:
	TValue _data;

	DoubleLinkedList* _next;
	DoubleLinkedList* _previous;

	DoubleLinkedList(const TValue& value)
		: _data(value), _next(nullptr), _previous(nullptr)
	{ }
	virtual ~DoubleLinkedList() = default;
};

#endif