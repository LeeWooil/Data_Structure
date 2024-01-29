#include <iostream>

const int SIZE = 8;

template <typename T>
void Swap(T& a, T& b);

template <class ItemType>
void Split(ItemType values[], int first, int last, int& splitPoint);

template <class ItemType>
void QuickSort(ItemType values[], int first, int last);

template<class ItemType>
void printArray(ItemType arr[], int size);

int main() {
	int arr[SIZE] = { 38, 27, 43, 3, 9, 82, 10, 1 };

	std::cout << "Original Array: ";
	printArray(arr, SIZE);

	QuickSort(arr, 0, SIZE - 1);

	std::cout << "Sorted Array: ";
	printArray(arr, SIZE);

	return 0;
}

template <typename T>
void Swap(T& a, T& b) {
	T temp = a;
	a = b;
	b = temp;
}

template <class ItemType>
void Split(ItemType values[], int first, int last, int& splitPoint) {
	ItemType splitVal = values[first];
	int saveFirst = first;
	bool onCorrectSide;

	first++;
	do {
		onCorrectSide = true;
		while (onCorrectSide) {
			if (values[first] > splitVal)
				onCorrectSide = false;
			else {
				first++;
				onCorrectSide = (first <= last);
			}
		}

		onCorrectSide = (first <= last);
		while (onCorrectSide) {
			if (values[last] <= splitVal)
				onCorrectSide = false;
			else {
				last--;
				onCorrectSide = (first <= last);
			}
		}

		if (first < last) {
			Swap(values[first], values[last]);
			first++;
			last--;
		}
	} while (first <= last);

	splitPoint = last;
	Swap(values[saveFirst], values[splitPoint]);
}

template <class ItemType>
void QuickSort(ItemType values[], int first, int last) {
	if (first < last) {
		int splitPoint;
		Split(values, first, last, splitPoint);
		QuickSort(values, first, splitPoint - 1);
		QuickSort(values, splitPoint + 1, last);
	}
}

template<class ItemType>
void printArray(ItemType arr[], int size) {
	for (int i = 0; i < size; i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
}