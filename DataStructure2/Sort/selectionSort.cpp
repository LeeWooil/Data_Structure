template<class ItemType>
int MinIndex(ItemType values[], int startIndex, int endIndex) {
	int indexOfMin = startIndex;
	for (int index = startIndex + 1; index <= endIndex; index++)
		if (values[index] < values[indexOfMin])
			indexOfMin = index;
	return indexOfMin;
}

template <typename T>
void Swap(T& a, T& b) {
	T temp = a;
	a = b;
	b = temp;
}

template<class ItemType>
void SelectionSort(ItemType values[], int numValues) {
	int endIndex = numValues - 1;
	for (int current = 0; current < endIndex; current++)
		Swap(values[current], values[MinIndex(values, current, endIndex)]);
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
	SelectionSort(arr, size);

	std::cout << "���ĵ� �迭: ";
	printArray(arr, size);

	return 0;
}