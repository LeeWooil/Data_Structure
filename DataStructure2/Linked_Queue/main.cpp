#include "Linked_queue.h"
#include <iostream>

using namespace std;

int main() {
	QueType<int> queue;

	queue.Enqueue(10);
	queue.Enqueue(20);
	queue.Enqueue(30);

	if (queue.IsEmpty()) {
		std::cout << "ť�� ��� �ֽ��ϴ�." << std::endl;
	}
	else {
		std::cout << "ť�� ��� ���� �ʽ��ϴ�." << std::endl;
	}

	if (queue.IsFull()) {
		std::cout << "ť�� ���� á���ϴ�." << std::endl;
	}
	else {
		std::cout << "ť�� ���� ���� �ʾҽ��ϴ�." << std::endl;
	}

	int item;
	queue.Dequeue(item);
	std::cout << "Dequeue �� ������: " << item << std::endl;

	queue.MakeEmpty();
	if (queue.IsEmpty()) {
		std::cout << "ť�� ��� �ֽ��ϴ�." << std::endl;
	}
}