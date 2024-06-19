#include <iostream>
#include "BST_Tree.h"
using namespace std;

int main() {
    bst_tree tree = bst_tree(5);

    cout << "Add: ";
    tree.add(3);
    tree.add(2);
    tree.add(4);
    tree.add(6);
    tree.add(7);
    tree.preorder_traversal();

    tree.remove(3);
    tree.preorder_traversal();
/*
    cout << "\nRemove: ";
    tree.remove(5);
    tree.preorder_traversal();
    tree.remove(8);
    tree.preorder_traversal(); // This line
    tree.remove(23);
    tree.preorder_traversal();
    tree.remove(1);
    tree.preorder_traversal();
    tree.remove(7);
    tree.preorder_traversal();
    tree.remove(10);
    tree.preorder_traversal();

    cout << "\nContains: ";
    cout << tree.contains(5);
    cout << tree.contains(97) << "\n";

    cout << "Pre-Order: ";
    tree.preorder_traversal();

    cout << "\nPost-Order: ";
    vector<int> temp = tree.postorder_traversal(tree.head);
    for (int i=0; i<temp.size(); i++) {
        cout << temp[i] << " ";
    }

    cout << "\n";
    cout << "Min: " << tree.find_min() << "\nMax: " << tree.find_max() << "\n";

    cout << "Is Empty: " << tree.is_empty();

    tree.make_empty();
    cout << "\nIs Empty Pt.2: " << tree.is_empty();*/
}
