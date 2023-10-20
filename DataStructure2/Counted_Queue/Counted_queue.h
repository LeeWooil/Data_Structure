#pragma once
#include "Dynamic_queue.h"

template<typename T>
class CountedQueType : public QueType<T>
{
public:
    CountedQueType(int max);
    void Enqueue(T newItem);
    void Dequeue(T& item);
    int LengthIs() const;
    void MakeEmpty();

private:
    int length;
};

template<typename T>
void CountedQueType<T>::Enqueue(T newItem)
{
    QueType<T>::Enqueue(newItem);
    length++;
}
template<typename T>
void CountedQueType<T>::Dequeue(T& item)
{
    QueType<T>::Dequeue(item);
    length--;
}
template<typename T>
int CountedQueType<T>::LengthIs() const
{
    return length;
}
template<typename T>
CountedQueType<T>::CountedQueType(int max) : QueType<T>(max)
{
    length = 0;
}

template<typename T>
void CountedQueType<T>::MakeEmpty() {
    QueType<T>::MakeEmpty();
    length = 0;
}