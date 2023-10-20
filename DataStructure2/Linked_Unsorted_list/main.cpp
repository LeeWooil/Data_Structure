#include "Linked_unsorted_list.h"

using namespace std;

int main() {
	UnsortedType<int> list;

    list.InsertItem(10);
    list.InsertItem(20);
    list.InsertItem(30);
    list.InsertItem(40);

    std::cout << "List Length: " << list.LengthIs() << std::endl;

    int itemToFind = 20;
    bool found = false;
    list.RetrieveItem(itemToFind, found);

    if (found) {
        std::cout << "Item " << itemToFind << " found in the list." << std::endl;
    }
    else {
        std::cout << "Item " << itemToFind << " not found in the list." << std::endl;
    }

    int itemToDelete = 30;
    list.DeleteItem(itemToDelete);
    std::cout << "Item " << itemToDelete << " deleted." << std::endl;

    list.ResetList();

    int nextItem;
    list.GetNextItem(nextItem);
    std::cout << "Next Item: " << nextItem << std::endl;

    return 0;
}