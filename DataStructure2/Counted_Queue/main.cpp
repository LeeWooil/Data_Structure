#include <iostream>
#include "Counted_queue.h" 

using namespace std;

int main() {
    CountedQueType<int> countedQueue(5);

    countedQueue.Enqueue(1);
    countedQueue.Enqueue(2);
    countedQueue.Enqueue(3);

    cout << "Queue length: " << countedQueue.LengthIs() << endl;

    int item;
    countedQueue.Dequeue(item);
    cout << "Dequeued item: " << item << endl;

    cout << "Queue length after dequeue: " << countedQueue.LengthIs() << endl;

    countedQueue.MakeEmpty();

    cout << "Queue length after MakeEmpty: " << countedQueue.LengthIs() << endl;

    return 0;
}
