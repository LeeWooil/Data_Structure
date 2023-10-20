#pragma once
#include "itemtype.h"

class FullStack
{};

class EmptyStack
{};

template<typename T>
struct NodeType;

template<typename T>
class StackType
{
public:
	StackType();
	~StackType();
	bool IsFull() const;
	bool IsEmpty() const;
	void Push(T item);
	void Pop(T item);
	T Top();
private:
	NodeType<T>* topPtr;
};
template<typename T>
struct NodeType
{
	T info;
	NodeType<T>* next;

	
};

#include <iostream>

template<typename T>
StackType<T>::StackType()
{
	topPtr = nullptr;
}

template<typename T>
StackType<T>::~StackType()
{
	NodeType<T>* tempPtr;
	while (topPtr != NULL)
	{
		tempPtr = topPtr;
		topPtr = topPtr->next;
		delete tempPtr;
	}
}

template<typename T>
bool StackType<T>::IsEmpty() const
{
	return (topPtr == nullptr);
}

template<typename T>
bool StackType<T>::IsFull() const
{
	NodeType<T>* location;
	try
	{
		location = new NodeType<T>;
		delete location;
		return false;
	}
	catch (std::bad_alloc exception)
	{
		return true;
	}
}

template<typename T>
void StackType<T>::Push(T newItem)
{
	if (IsFull())
		throw FullStack();
	NodeType<T>* location;
	location = new NodeType<T>;
	location->info = newItem;
	location->next = topPtr;
	topPtr = location;
}

template<typename T>
void StackType<T>::Pop(T newItem)
{
	if (IsEmpty())
		throw EmptyStack();
	else
	{
		NodeType<T>* tempPtr;
		tempPtr = topPtr;
		topPtr = topPtr->next;
		delete tempPtr;
	}
}

template<typename T>
T StackType<T>::Top()
{
	if (IsEmpty())
		throw EmptyStack();
	else
		return topPtr->info;
}
