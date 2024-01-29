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
// 배열 출력 함수
template<class ItemType>
void printArray(ItemType arr[], int size) {
	for (int i = 0; i < size; i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
}

int main() {
	const int size = 6;  // 배열 크기 지정 (필요에 따라 수정)
	int arr[size] = { 64, 25, 12, 22, 11, 35 };  // 배열 값 초기화 (필요에 따라 수정)

	std::cout << "원래 배열: ";
	printArray(arr, size);

	// 선택 정렬 함수 호출
	SelectionSort(arr, size);

	std::cout << "정렬된 배열: ";
	printArray(arr, size);

	return 0;
}