#include <iostream>
#include "BST.h"  // "TreeType" 클래스와 관련된 헤더 파일을 포함해야 합니다.

using namespace std;

int main() {
    TreeType<int> tree;

    // 트리에 요소 추가
    tree.InsertItem(5);
    tree.InsertItem(3);
    tree.InsertItem(8);
    tree.InsertItem(2);
    tree.InsertItem(4);
    tree.InsertItem(7);
    tree.InsertItem(9);

    // 트리의 상태 출력 (Pre-order)
    cout << "Pre-order traversal: ";
    tree.ResetTree(PRE_ORDER);
    bool finished = false;
    int item;
    while (!finished) {
        tree.GetNextItem(item, PRE_ORDER, finished);
        cout << item << " ";
    }
    cout << endl;

    // 트리의 상태 출력 (In-order)
    cout << "In-order traversal: ";
    tree.ResetTree(IN_ORDER);
    finished = false;
    while (!finished) {
        tree.GetNextItem(item, IN_ORDER, finished);
        cout << item << " ";
    }
    cout << endl;

    // 트리의 상태 출력 (Post-order)
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