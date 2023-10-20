#include "DoubleLinked_list.h"

using namespace std;

int main() {
	SortedType<int> sortedList;

    sortedList.InsertItem(10);
    sortedList.InsertItem(5);
    sortedList.InsertItem(20);
    sortedList.InsertItem(15);

    std::cout << "Sorted List: ";
    sortedList.ResetList();
    int item;
    for (int i = 0; i < sortedList.LengthIs(); i++)
    {
        sortedList.GetNextItem(item);
        cout << item << " ";
    }
    std::cout << std::endl;

    int searchItem = 15;
    bool found = false;
    sortedList.RetrieveItem(searchItem, found);
    if (found)
    {
        std::cout << searchItem << " found in the list." << std::endl;
    }
    else
    {
        std::cout << searchItem << " not found in the list." << std::endl;
    }

    int deleteItem = 5;
    sortedList.DeleteItem(deleteItem);

    std::cout << "Updated List: ";
    sortedList.ResetList();
    
    std::cout << std::endl;
    for (int i = 0; i < sortedList.LengthIs(); i++)
    {
        sortedList.GetNextItem(item);
        cout << item << " ";
    }

    return 0;

}