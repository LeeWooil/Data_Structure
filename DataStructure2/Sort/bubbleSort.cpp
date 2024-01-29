template <typename T>
void Swap(T& a, T& b) {
	T temp = a;
	a = b;
	b = temp;
}

template<class ItemType>
void BubbleUp(ItemType values[], int startIndex, int endIndex) {
	for (int index = endIndex; index > startIndex; index--)
		if (values[index] < values[index - 1])
			Swap(values[index], values[index - 1]);
}

template<class ItemType>
void BubbleSort(ItemType values[], int numValues) {
	int current = 0;
	
	while (current < numValues - 1) {
		BubbleUp(values, current, numValues - 1);
		current++;
	}
}

#include <iostream>
// �迭 ��� �Լ�
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
	BubbleSort(arr, size);

	std::cout << "���ĵ� �迭: ";
	printArray(arr, size);

	return 0;
}