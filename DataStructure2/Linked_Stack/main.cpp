#include <iostream>
#include "Linked_stack.h"
using namespace std;

int main() {
	StackType<int> stack;
	stack.Push(10);
	stack.Push(20);
	stack.Push(30);

	if (stack.IsEmpty()) {
		std::cout << "������ ��� �ֽ��ϴ�." << std::endl;
	}
	else {
		std::cout << "������ ��� ���� �ʽ��ϴ�." << std::endl;
	}

	if (stack.IsFull()) {
		std::cout << "������ ���� á���ϴ�." << std::endl;
	}
	else {
		std::cout << "������ ���� ���� �ʾҽ��ϴ�." << std::endl;
	}

	int item = 1;
	stack.Pop(item);
	std::cout << "Pop�� ������: " << item << std::endl;

	int topItem = stack.Top();
	std::cout << "Top ������: " << topItem << std::endl;

	stack.Push(40);
}