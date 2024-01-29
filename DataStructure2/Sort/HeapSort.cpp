#include <iostream>

template <typename T>
void Swap(T& a, T& b);

template <class ItemType>
void ReheapDown(ItemType elements[], int root, int bottom);

template <class ItemType>
void HeapSort(ItemType values[], int numValues);

template<class ItemType>
void printArray(ItemType arr[], int size);

int main() {
	const int SIZE = 8;
	int arr[SIZE] = { 38, 27, 43, 3, 9, 82, 10, 1 };

	std::cout << "Original Array: ";
	
	printArray(arr, SIZE);

	HeapSort(arr, SIZE);

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
void ReheapDown(ItemType elements[], int root, int bottom) {
	int maxChild;
	int rightChild;
	int leftChild;

	leftChild = root * 2 + 1;
	rightChild = root * 2 + 2;
	if (leftChild <= bottom) {
		if (leftChild == bottom)
			maxChild = leftChild;
		else {
			if (elements[leftChild] <= elements[rightChild])
				maxChild = rightChild;
			else
				maxChild = leftChild;
		}
		if (elements[root] < elements[maxChild]) {
			Swap(elements[root], elements[maxChild]);
			ReheapDown(elements, maxChild, bottom);
		}
	}
}

template <class ItemType>
void HeapSort(ItemType values[], int numValues) {
	int index;

	for (index = numValues / 2 - 1; index >= 0; index--)
		ReheapDown(values, index, numValues - 1);
	for (index = numValues - 1; index >= 1; index--) {
		Swap(values[0], values[index]);
		ReheapDown(values, 0, index - 1);
	}
}

template<class ItemType>
void printArray(ItemType arr[], int size) {
	for (int i = 0; i < size; i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
}
