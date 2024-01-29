template <typename T>
void Swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

template <typename T>
void Split(T values[], int first, int last, int& splitPoint) {
	T splitVal = values[first];
	int saveFirst = first;
	bool onCorrectSide;

	first++;
	do {
        onCorrectSide = true;
        while (onCorrectSide)         // Move first toward last.
            if (values[first] > splitVal)
                onCorrectSide = false;
            else
            {
                first++;
                onCorrectSide = (first <= last);
            }

        onCorrectSide = (first <= last);
        while (onCorrectSide)             // Move last toward first.
            if (values[last] <= splitVal)
                onCorrectSide = false;
            else
            {
                last--;
                onCorrectSide = (first <= last);
            }

        if (first < last)
        {
            Swap(values[first], values[last]);
            first++;
            last--;
        }
    } while (first <= last);

    splitPoint = last;
    Swap(values[saveFirst], values[splitPoint]);
}
template<typename T>
void QuickSort(T values[], int first, int last)
{
    if (first < last)
    {
        int splitPoint;

        Split(values, first, last, splitPoint);
        QuickSort(values, first, splitPoint - 1);
        QuickSort(values, splitPoint + 1, last);
    }
}