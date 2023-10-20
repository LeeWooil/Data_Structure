#include "Linked_sorted_list.h"

using namespace std;

int main() {
	SortedType<int> sortedList;

    sortedList.InsertItem(40);
    sortedList.InsertItem(10);
    sortedList.InsertItem(30);
    sortedList.InsertItem(20);

    std::cout << "List Length: " << sortedList.LengthIs() << std::endl;

    int itemToFind = 30;
    bool found = false;
    sortedList.RetrieveItem(itemToFind, found);

    if (found) {
        std::cout << "Item " << itemToFind << " found in the list." << std::endl;
    }
    else {
        std::cout << "Item " << itemToFind << " not found in the list." << std::endl;
    }

    int itemToDelete = 10;
    sortedList.DeleteItem(itemToDelete);
    std::cout << "Item " << itemToDelete << " deleted." << std::endl;

    sortedList.ResetList();

    int nextItem;
    sortedList.GetNextItem(nextItem);
    std::cout << "Next Item: " << nextItem << std::endl;

    return 0;
}