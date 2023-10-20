#pragma once
template<typename T>
class QueType {
public:
	QueType();
	QueType(int max);
	~QueType();
	void MakeEmpty();
	bool IsEmpty() const;
	bool IsFull() const;
	void Enqueue(T newitem);
	void Dequeue(T& item);
private:
	int front;
	int rear;
	T* items;
	int maxQue;
};

template<typename T>
QueType<T>::QueType() {
	maxQue = 501;
	front = maxQue - 1;
	rear = maxQue - 1;
	items = new T[maxQue];
}

template<typename T>
QueType<T>::QueType(int max) {
	maxQue = max + 1;
	front = maxQue - 1;
	rear = maxQue - 1;
	items = new T[maxQue];
}

template<typename T>
QueType<T>::~QueType() {
	delete[] items;
}

template<typename T>
void QueType<T>::MakeEmpty() {
	front = maxQue - 1;
	rear = maxQue - 1;
}

template<typename T>
bool QueType<T>::IsEmpty() const {
	return(rear == front);
}

template<typename T>
bool QueType<T>::IsFull() const {
	return((rear + 1) % maxQue == front);
}

template<typename T>
void QueType<T>::Enqueue(T newitem) {
	rear = (rear + 1) % maxQue;
	items[rear] = newitem;
}

template<typename T>
void QueType<T>::Dequeue(T& item) {
	front = (front + 1) % maxQue;
	item = items[front];
}