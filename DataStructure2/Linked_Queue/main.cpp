#include "Linked_queue.h"
#include <iostream>

using namespace std;

int main() {
	QueType<int> queue;

	queue.Enqueue(10);
	queue.Enqueue(20);
	queue.Enqueue(30);

	if (queue.IsEmpty()) {
		std::cout << "큐가 비어 있습니다." << std::endl;
	}
	else {
		std::cout << "큐가 비어 있지 않습니다." << std::endl;
	}

	if (queue.IsFull()) {
		std::cout << "큐가 가득 찼습니다." << std::endl;
	}
	else {
		std::cout << "큐가 가득 차지 않았습니다." << std::endl;
	}

	int item;
	queue.Dequeue(item);
	std::cout << "Dequeue 된 아이템: " << item << std::endl;

	queue.MakeEmpty();
	if (queue.IsEmpty()) {
		std::cout << "큐가 비어 있습니다." << std::endl;
	}
}