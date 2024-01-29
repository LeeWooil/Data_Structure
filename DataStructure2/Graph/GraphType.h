#pragma once
#include "QueType.h"

const int NULL_EDGE = 0;
template <class ItemType>
class GraphType {
public:
	GraphType(int);
	~GraphType();
	void MakeEmpty();
	bool IsEmpty() const;
	bool IsFull() const;
	void AddVertex(ItemType);
	void AddEdge(ItemType, ItemType, int);
	int WeightIs(ItemType, ItemType);
	void GetToVertices(ItemType, QueType<ItemType>&);
	void ClearMarks();
	void MarkVertex(ItemType);
	bool IsMarked(ItemType) const;
private:
	int numVertices;
	int maxVertices;
	ItemType* vertices;
	int** edges;
	bool* marks;
};

template<class ItemType>
GraphType<ItemType>::GraphType(int maxV) {
	numVertices = 0;
	maxVertices = maxV;
	vertices = new ItemType[maxV];
	edges = new int* [maxV];
	for (int i = 0; i < maxV; i++) {
		edges[i] = new int[maxV];
		for (int j = 0; j < maxV; j++) {
			edges[i][j] = NULL_EDGE;
		}
	}

	marks = new bool[maxV];
}

template<class ItemType>
GraphType<ItemType>::~GraphType() {
	delete vertices;
	for (int i = 0; i < maxVertices; i++)
		delete edges[i];
	delete[] edges;
	delete[] marks;
}

template<class ItemType>
void GraphType<ItemType>::AddVertex(ItemType vertex) {
	vertices[numVertices] = vertex;
	for (int index = 0; index < numVertices; index++) {
		edges[numVertices][index] = NULL_EDGE;
		edges[index][numVertices] = NULL_EDGE;
	}
	numVertices++;
}

template<class ItemType>
int IndexIs(ItemType* vertices, ItemType vertex)
{
	int index = 0;

	while (!(vertex == vertices[index]))
		index++;
	return index;
}

template<class ItemType>
void GraphType<ItemType>::AddEdge(ItemType fromVertex, ItemType toVertex, int weight) {
	int row;
	int column;
	row = IndexIs(vertices, fromVertex);
	column = IndexIs(vertices, toVertex);
	edges[row][column] = weight;
}

template<class ItemType>
int GraphType<ItemType>::WeightIs
(ItemType fromVertex, ItemType toVertex)
{
	int row;
	int col;

	row = IndexIs(vertices, fromVertex);
	col = IndexIs(vertices, toVertex);
	return edges[row][col];
}

template<class ItemType>
void GraphType<ItemType>::GetToVertices(ItemType vertex,
	QueType<ItemType>& adjVertices)
{
	int fromIndex;
	int toIndex;

	fromIndex = IndexIs(vertices, vertex);
	for (toIndex = 0; toIndex < numVertices; toIndex++)
		if (edges[fromIndex][toIndex] != NULL_EDGE)
			adjVertices.Enqueue(vertices[toIndex]);
}

template<class ItemType>
void GraphType<ItemType>::MakeEmpty() {
	numVertices = 0;
}

template<class ItemType>
bool GraphType<ItemType>::IsEmpty() const {
	return numVertices == 0;
}

template<class ItemType>
bool GraphType<ItemType>::IsFull() const {
	return numVertices == maxVertices;
}

template<class ItemType>
void GraphType<ItemType>::ClearMarks() {
	for (int i = 0; i < numVertices; i++) {
		marks[i] = false;
	}
}

template<class ItemType>
void GraphType<ItemType>::MarkVertex(ItemType vertex) {
	int index = IndexIs(vertices, vertex);
	marks[index] = true;
}

template<class ItemType>
bool GraphType<ItemType>::IsMarked(ItemType vertex) const {
	int index = IndexIs(vertices, vertex);
	return marks[index];
}
