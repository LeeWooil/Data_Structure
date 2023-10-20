#pragma once
#include <iostream>

template<typename T>
struct NodeType;

template <typename T>
class UnsortedType
{
public:
	UnsortedType();
	~UnsortedType();
	void MakeEmpty();
	bool IsFull() const;
	int LengthIs() const;
	void RetrieveItem(T& item, bool& found);
	void InsertItem(T item);
	void DeleteItem(T item);
	void ResetList();
	void GetNextItem(T& item);
private:
	NodeType<T>* listData;
	int length;
	NodeType<T>* currentPos;
};

template<typename T>
struct NodeType
{
	T info;
	NodeType<T>* next;
};

template <typename T>
UnsortedType<T>::UnsortedType()
{
	length = 0;
	listData = nullptr;
}
template <class T>
UnsortedType<T>::~UnsortedType()

{
	MakeEmpty();
}

template<class T>
bool UnsortedType<T>::IsFull() const

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

template <class T>
void UnsortedType<T>::MakeEmpty()

{
	NodeType<T>* tempPtr;

	while (listData != nullptr)
	{
		tempPtr = listData;
		listData = listData->next;
		delete tempPtr;
	}
	length = 0;
}

template <typename T>
int UnsortedType<T>::LengthIs() const
{
	return length;
}

template <typename T>
void UnsortedType<T>::RetrieveItem(T& item, bool& found)
{
	bool moreTosearch;
	NodeType<T>* location;
	location = listData;
	found - false;
	moreTosearch = (location != nullptr);
	while (moreTosearch && !found)
	{
		if (item == location->info)
		{
			found = true;
			item = location->info;
		}
		else
		{
			location = location->next;
			moreTosearch = (location != nullptr);
		}
	}
}

template<typename T>
void UnsortedType<T>::InsertItem(T item)
{
	NodeType<T>* location;
	location = new NodeType<T>;
	location->info = item;
	location->next = listData;
	listData = location;
	length++;
}

template<typename T>
void UnsortedType<T>::DeleteItem(T item)
{
	NodeType<T>* location = listData;
	NodeType<T>* tempLocation;

	if (item == listData->info) {
		tempLocation = location;
		listData = listData->next;
	}
	else
	{
		while (!(item == (location->next)->info))
			location = location->next;

		tempLocation = location->next;
		location->next = (location->next)->next;
	}
	delete tempLocation;
	length--;
}

template <class T>
void UnsortedType<T>::ResetList()

{
	currentPos = nullptr;
}

template <class T>
void UnsortedType<T>::GetNextItem(T& item)

{
	if (currentPos == nullptr)
		currentPos = listData;
	else
		currentPos = currentPos->next;
	item = currentPos->info;
}