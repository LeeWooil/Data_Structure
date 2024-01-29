#include <iostream>
#include "BST.h"  // "TreeType" Ŭ������ ���õ� ��� ������ �����ؾ� �մϴ�.

using namespace std;

int main() {
    TreeType<int> tree;

    // Ʈ���� ��� �߰�
    tree.InsertItem(5);
    tree.InsertItem(3);
    tree.InsertItem(8);
    tree.InsertItem(2);
    tree.InsertItem(4);
    tree.InsertItem(7);
    tree.InsertItem(9);

    // Ʈ���� ���� ��� (Pre-order)
    cout << "Pre-order traversal: ";
    tree.ResetTree(PRE_ORDER);
    bool finished = false;
    int item;
    while (!finished) {
        tree.GetNextItem(item, PRE_ORDER, finished);
        cout << item << " ";
    }
    cout << endl;

    // Ʈ���� ���� ��� (In-order)
    cout << "In-order traversal: ";
    tree.ResetTree(IN_ORDER);
    finished = false;
    while (!finished) {
        tree.GetNextItem(item, IN_ORDER, finished);
        cout << item << " ";
    }
    cout << endl;

    // Ʈ���� ���� ��� (Post-order)
    cout << "Post-order traversal: ";
    tree.ResetTree(POST_ORDER);
    finished = false;
    while (!finished) {
        tree.GetNextItem(item, POST_ORDER, finished);
        cout << item << " ";
    }
    cout << endl;

    return 0;
}