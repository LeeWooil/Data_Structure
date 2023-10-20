#pragma once
#include <iostream>

template<typename T>
struct NodeType;

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

	location = listData;
	found = false;
	while ((location != nullptr) && !found)
	{
		if (location->info < item)
			location = location->next;
		else if (location->info == item) {
			found = true;
			item = location->info;
		}
		else
			location = nullptr;
	}
}

template <class T>
void SortedType<T>::InsertItem(T item)
{
	NodeType<T>* newNode;
	NodeType<T>* predLoc;
	NodeType<T>* location;
	bool moreToSearch;

	location = listData;
	predLoc = nullptr;
	moreToSearch = (location != nullptr);

	while (moreToSearch)
	{
		if (location->info < item)
		{
			predLoc = location;
			location = location->next;
			moreToSearch = (location != nullptr);
		}
		else
			moreToSearch = false;
	}

	newNode = new NodeType<T>;
	newNode->info = item;
	if (predLoc == nullptr)
	{
		newNode->next = listData;
		listData = newNode;
	}
	else
	{
		newNode->next = location;
		predLoc->next = newNode;
	}
	length++;
}

template <class T>
void SortedType<T>::DeleteItem(T item)
{
	NodeType<T>* location = listData;
	NodeType<T>* tempLocation;

	if (item == listData->info)
	{
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
void SortedType<T>::ResetList()

{
	currentPos = nullptr;
}

template <class T>
void SortedType<T>::GetNextItem(T& item)

{
	if (currentPos == nullptr)
		currentPos = listData;
	else
		currentPos = currentPos->next;
	item = currentPos->info;
}