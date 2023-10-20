#include <iostream>
#include "Linked_stack.h"
using namespace std;

int main() {
	StackType<int> stack;
	stack.Push(10);
	stack.Push(20);
	stack.Push(30);

	if (stack.IsEmpty()) {
		std::cout << "스택이 비어 있습니다." << std::endl;
	}
	else {
		std::cout << "스택이 비어 있지 않습니다." << std::endl;
	}

	if (stack.IsFull()) {
		std::cout << "스택이 가득 찼습니다." << std::endl;
	}
	else {
		std::cout << "스택이 가득 차지 않았습니다." << std::endl;
	}

	int item = 1;
	stack.Pop(item);
	std::cout << "Pop된 아이템: " << item << std::endl;

	int topItem = stack.Top();
	std::cout << "Top 아이템: " << topItem << std::endl;

	stack.Push(40);
}