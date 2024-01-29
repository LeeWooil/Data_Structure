#include <iostream>

const int SIZE = 8;

template<class ItemType>
void Merge(ItemType values[], int leftFirst, int leftLast, int rightFirst, int rightLast);

template<class ItemType>
void MergeSort(ItemType values[], int first, int last);

template<class ItemType>
void printArray(ItemType arr[], int size);

int main() {
	int arr[SIZE] = { 38, 27, 43, 3, 9, 82, 10, 1 };

	std::cout << "Original Array: ";
	printArray(arr, SIZE);

	MergeSort(arr, 0, SIZE - 1);

	std::cout << "Sorted Array: ";
	printArray(arr, SIZE);

	return 0;
}

template<class ItemType>
void Merge(ItemType values[], int leftFirst, int leftLast, int rightFirst, int rightLast) {
	ItemType tempArray[SIZE];
	int index = leftFirst;
	int saveFirst = leftFirst;

	while ((leftFirst <= leftLast) && (rightFirst <= rightLast)) {
		if (values[leftFirst] < values[rightFirst]) {
			tempArray[index] = values[leftFirst];
			leftFirst++;
		}
		else {
			tempArray[index] = values[rightFirst];
			rightFirst++;
		}
		index++;
	}

	while (leftFirst <= leftLast) {
		tempArray[index] = values[leftFirst];
		leftFirst++;
		index++;
	}

	while (rightFirst <= rightLast) {
		tempArray[index] = values[rightFirst];
		rightFirst++;
		index++;
	}

	for (index = saveFirst; index <= rightLast; index++) {
		values[index] = tempArray[index];
	}
}

template<class ItemType>
void MergeSort(ItemType values[], int first, int last) {
	if (first < last) {
		int middle = (first + last) / 2;
		MergeSort(values, first, middle);
		MergeSort(values, middle + 1, last);
		Merge(values, first, middle, middle + 1, last);
	}
}

template<class ItemType>
void printArray(ItemType arr[], int size) {
	for (int i = 0; i < size; i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
}