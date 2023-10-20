#pragma once

#include <iostream>

template<typename T>
struct NodeType;

template <typename T>
void FindItem(NodeType<T>* listData, T item,
	NodeType<T>*& location, bool& found)
{
	bool moreTosearch = true;

	location = listData;
	found = false;

	while (moreTosearch && !found) 
	{
		if (item < location->info)
			moreTosearch = false;
		else if (item == location->info)
			found = true;
		else {
			if (location->next == nullptr)
				moreTosearch = false;
			else
				location = location->next;
		}
	}
}

template <typename T>
class SortedType
{
public:
	SortedType();
	~SortedType();
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
	NodeType<T>* back;
};

template <class T>
SortedType<T>::SortedType()
{
	length = 0;
	listData = nullptr;
}

template <class T>
SortedType<T>::~SortedType()
{
	MakeEmpty();
}

template <class T>
void SortedType<T>::MakeEmpty()
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

template <class T>
bool SortedType<T>::IsFull() const
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
int SortedType<T>::LengthIs() const {
	return length;
}

template <class T>
void SortedType<T>::RetrieveItem(T& item, bool& found)
{
	NodeType<T>* location;
	found = false;

	FindItem(listData, item, location, found);

	if (found) {
		item = location->info;
	}
}


template <typename T>
void SortedType<T>::InsertItem(T item)
{
	NodeType<T>* newNode = new NodeType<T>;
	newNode->info = item;
	newNode->back = nullptr;
	newNode->next = nullptr;

	NodeType<T>* location = listData;
	NodeType<T>* predLoc = nullptr;

	// Find the correct position to insert the item
	while (location != nullptr && location->info < item)
	{
		predLoc = location;
		location = location->next;
	}

	if (predLoc == nullptr)
	{
		// Insert at the beginning of the list
		if (listData != nullptr) {
			newNode->next = listData;
			listData->back = newNode;
		}
		listData = newNode;
	}
	else
	{
		// Insert in the middle or end of the list
		newNode->next = location;
		newNode->back = predLoc;
		predLoc->next = newNode;
		if (location != nullptr) {
			location->back = newNode;
		}
	}

	length++;
}



template <class T>
void SortedType<T>::DeleteItem(T item)
{
	NodeType<T>* location;
	bool found;

	// Find the item in the list
	FindItem(listData, item, location, found);

	if (found) {
		if (location->back != nullptr) {
			(location->back)->next = location->next;
		}
		else {
			listData = location->next;
		}

		if (location->next != nullptr) {
			(location->next)->back = location->back;
		}

		delete location;
		length--;
	}
}

template <class T>
void SortedType<T>::ResetList()

{
	currentPos = nullptr;
}

template <class T>
void SortedType<T>::GetNextItem(T& item)

{
	if (currentPos == nullptr) {
		currentPos = listData;
	}
	else {
		currentPos = currentPos->next;
	}

	if (currentPos != nullptr) {
		item = currentPos->info;
	}
}