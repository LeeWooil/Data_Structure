template <typename T>
void Swap(T& a, T& b) {
	T temp = a;
	a = b;
	b = temp;
}

template<class ItemType>
void InsertItem(ItemType values[], int startIndex, int endIndex) {
	bool finished = false;
	int current = endIndex;
	bool moreToSearch = (current != startIndex);

	while (moreToSearch && !finished) {
		if (values[current] < values[current - 1]) {
			Swap(values[current], values[current - 1]);
			current--;
			moreToSearch = (current != startIndex);
		}
		else finished = true;
	}
}

template<class ItemType>
void InsertionSort(ItemType values[], int numValues) {
	for (int count = 0; count < numValues; count++)
		InsertItem(values, 0, count);
}

#include <iostream>
template<class ItemType>
void printArray(ItemType arr[], int size) {
	for (int i = 0; i < size; i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
}

int main() {
	const int size = 6;  // �迭 ũ�� ���� (�ʿ信 ���� ����)
	int arr[size] = { 64, 25, 12, 22, 11, 35 };  // �迭 �� �ʱ�ȭ (�ʿ信 ���� ����)

	std::cout << "���� �迭: ";
	printArray(arr, size);

	// ���� ���� �Լ� ȣ��
	InsertionSort(arr, size);

	std::cout << "���ĵ� �迭: ";
	printArray(arr, size);

	return 0;
}