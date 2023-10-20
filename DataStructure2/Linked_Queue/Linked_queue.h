#pragma once

#include "itemtype.h"
#include <iostream>

template<typename T>
struct NodeType;

template<typename T>
class QueType {
public:
	QueType();
	~QueType();
	bool IsEmpty() const;
	bool IsFull() const;
	void Enqueue(T item);
	void Dequeue(T& item);
	void MakeEmpty();
private:
	NodeType<T>* qFront;
	NodeType<T>* qRear;
};

template<typename T>
struct NodeType
{
	T info;
	NodeType<T>* next;
};

template<typename T>
QueType<T>::QueType()
{
	qFront = nullptr;
	qRear = nullptr;
}

template<typename T>
QueType<T>::~QueType()
{
	MakeEmpty();
}

template <typename T>
void QueType<T>::MakeEmpty()
{
	NodeType<T>* tempPtr;

	while (qFront != nullptr)
	{
		tempPtr = qFront;
		qFront = qFront->next;
		delete tempPtr;
	}
	qRear = nullptr;
}


template<typename T>
bool QueType<T>::IsFull() const
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
bool QueType<T>::IsEmpty() const
{
	return (qFront == nullptr);
}

template<typename T>
void QueType<T>::Enqueue(T newItem)
{
	NodeType<T>* ptr;
	ptr = new NodeType<T>;
	ptr->info = newItem;
	ptr->next = nullptr;
	if (qRear == nullptr)
		qFront = ptr;
	else
		qRear->next = ptr;
	qRear = ptr;
}

template<typename T>
void QueType<T>::Dequeue(T& item)
{
	NodeType<T>* tempPtr;
	
	tempPtr = qFront;
	item = qFront->info;
	qFront = qFront->next;
	if (qFront == nullptr)
		qRear = nullptr;
	delete tempPtr;
}