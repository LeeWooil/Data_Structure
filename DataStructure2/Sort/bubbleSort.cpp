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

	// 버블 정렬 함수 호출
	BubbleSort(arr, size);

	std::cout << "정렬된 배열: ";
	printArray(arr, size);

	return 0;
}