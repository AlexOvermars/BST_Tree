#include "BST_Tree.h"
#include <stdexcept>
#include <vector>
#include <iostream>
using namespace std;

bst_tree::bst_tree() {
    head = nullptr;
}

bst_tree::bst_tree(int head_val) {
    struct node* n = new node{head_val, nullptr, nullptr};
    head = n;
}

void bst_tree::add(int val) {
    struct node* n = new node{val, nullptr, nullptr};
    if (head == nullptr) {
        head = n;
        return;
    }
    struct node* currentNode = head;
    while (true) {
        if (val >= currentNode->data) {
            if (currentNode->rightNode == nullptr) {
                currentNode->rightNode = n;
                break;
            }
            else {
                currentNode = currentNode->rightNode;
            }
        }
        else {
            if (currentNode->leftNode == nullptr) {
                currentNode->leftNode = n;
                break;
            }
            else {
                currentNode = currentNode->leftNode;
            }
        }
    }
}

bool bst_tree::remove(int val) {
    if (head == nullptr) {
        return false;
    }
    struct node* beforeRemoveNode = nullptr;
    struct node* removeNode = head;
    while (removeNode != nullptr) {
        if (removeNode->data > val) {
            beforeRemoveNode = removeNode;
            removeNode = removeNode->leftNode;
        }
        else if (removeNode->data < val) {
            beforeRemoveNode = removeNode;
            removeNode = removeNode->rightNode;
        }
        else {
            break;
        }
    }
    if (removeNode == nullptr) {
        return false;
    }

    if ((removeNode->leftNode == nullptr) && (removeNode->rightNode == nullptr)) {
        if (removeNode == head) {
            head = nullptr;
            delete removeNode;
        }
        else if (removeNode->data > beforeRemoveNode->data) {
            beforeRemoveNode->rightNode = nullptr;
            delete removeNode;
        }
        else {
            beforeRemoveNode->leftNode = nullptr;
            delete removeNode;
        }
    }
    else if ((removeNode->leftNode != nullptr) && (removeNode->rightNode == nullptr)) {
        if (removeNode == head) {
            head = removeNode->leftNode;
            delete removeNode;
        }
        else if (removeNode->data > beforeRemoveNode->data) {
            beforeRemoveNode->rightNode = removeNode->leftNode;
            delete removeNode;
        }
        else {
            beforeRemoveNode->leftNode = removeNode->leftNode;
            delete removeNode;
        }
    }
    else if ((removeNode->leftNode == nullptr) && (removeNode->rightNode != nullptr)) {
        if (removeNode == head) {
            head = removeNode->rightNode;
            delete removeNode;
        }
        else if (removeNode->data > beforeRemoveNode->data) {
            beforeRemoveNode->rightNode = removeNode->rightNode;
            delete removeNode;
        }
        else {
            beforeRemoveNode->leftNode = removeNode->rightNode;
            delete removeNode;
        }
    }
    else if ((removeNode->leftNode != nullptr) && (removeNode->rightNode != nullptr)) {
        struct node* beforeReplacementNode = removeNode;
        struct node* replacementNode = removeNode->rightNode;
        while (replacementNode->leftNode != nullptr) {
            beforeReplacementNode = replacementNode;
            replacementNode = replacementNode->leftNode;
        }

        if (removeNode == head) {
            head = replacementNode;
            if (removeNode != beforeReplacementNode) {
                if (replacementNode->rightNode != nullptr) {
                    beforeReplacementNode->leftNode = replacementNode->rightNode;
                } else {
                    beforeReplacementNode->leftNode = nullptr;
                }
            }
            if (removeNode->rightNode != replacementNode) {
                replacementNode->rightNode = removeNode->rightNode;
            }
            if (removeNode->leftNode != replacementNode) {
                replacementNode->leftNode = removeNode->leftNode;
            }
            delete removeNode;
            return true;
        }

        if (beforeReplacementNode == removeNode) {
            beforeReplacementNode = beforeRemoveNode;
        }

        if (beforeRemoveNode->rightNode == removeNode) {
            beforeRemoveNode->rightNode = replacementNode;
            replacementNode->leftNode = removeNode->leftNode;
            if (beforeReplacementNode != beforeRemoveNode) {
                beforeReplacementNode->leftNode = replacementNode->rightNode;
            }
            if (removeNode->rightNode != replacementNode) {
                replacementNode->rightNode = removeNode->rightNode;
            }
            delete removeNode;

        }
        if (beforeRemoveNode->leftNode == removeNode) {
            beforeRemoveNode->leftNode = replacementNode;
            replacementNode->leftNode = removeNode->leftNode;
            if (beforeReplacementNode != beforeRemoveNode) {
                beforeReplacementNode->leftNode = replacementNode->rightNode;
            }
            if (removeNode->rightNode != replacementNode) {
                replacementNode->rightNode = removeNode->rightNode;
            }
            delete removeNode;
        }
    }
    return true;
}

bool bst_tree::contains(int val) {
    struct node* currentNode = head;
    while (true) {
        if (currentNode->data == val) {
            return true;
        }
        if ((currentNode->data > val) && (currentNode->leftNode != nullptr)) {
            currentNode = currentNode->leftNode;
        }
        else if ((currentNode->data < val) && (currentNode->rightNode != nullptr)) {
            currentNode = currentNode->rightNode;
        }
        else {
            return false;
        }
    }
}

vector<int> bst_tree::inorder_traversal(struct node* root) {
    vector<int> nums;
    if (root != nullptr) {
        vector<int> leftNodeVect = inorder_traversal(root->leftNode);
        for (int i=0; i<leftNodeVect.size(); i++) {
            nums.push_back(leftNodeVect[i]);
        }
        nums.push_back(root->data);
        vector<int> rightNodeVect = inorder_traversal(root->rightNode);
        for (int i=0; i<rightNodeVect.size(); i++) {
            nums.push_back(rightNodeVect[i]);
        }
    }
    return nums;
}

vector<int> bst_tree::preorder_traversal_recur(struct node* root) {
    vector<int> nums;
    if (root != nullptr) {
        nums.push_back(root->data);
        vector<int> leftNodeVect = preorder_traversal_recur(root->leftNode);
        for (int i=0; i<leftNodeVect.size(); i++) {
            nums.push_back(leftNodeVect[i]);
        }
        vector<int> rightNodeVect = preorder_traversal_recur(root->rightNode);
        for (int i=0; i<rightNodeVect.size(); i++) {
            nums.push_back(rightNodeVect[i]);
        }
    }
    return nums;
}

vector<int> bst_tree::postorder_traversal(struct node* root) {
    vector<int> nums;
    if (root != nullptr) {
        vector<int> leftNodeVect = postorder_traversal(root->leftNode);
        for (int i=0; i<leftNodeVect.size(); i++) {
            nums.push_back(leftNodeVect[i]);
        }
        vector<int> rightNodeVect = postorder_traversal(root->rightNode);
        for (int i=0; i<rightNodeVect.size(); i++) {
            nums.push_back(rightNodeVect[i]);
        }
        nums.push_back(root->data);
    }
    return nums;
}

int bst_tree::find_min() {
    if (head == nullptr) {
        throw std::invalid_argument("Unable to find minimum of an empty tree");
    }
    struct node* currentNode = head;
    while (currentNode->leftNode != nullptr) {
        currentNode = currentNode->leftNode;
    }
    return currentNode->data;
}

int bst_tree::find_max() {
    if (head == nullptr) {
        throw std::invalid_argument("Unable to find maximum of an empty tree");
    }
    struct node* currentNode = head;
    while (currentNode->rightNode != nullptr) {
        currentNode = currentNode->rightNode;
    }
    return currentNode->data;
}

bool bst_tree::is_empty() {
    if (head == nullptr) {
        return true;
    }
    return false;
}

void bst_tree::make_empty_recur(struct node* root) {
    if (root == nullptr) {
        return;
    }
    if (root->leftNode != nullptr) {
        make_empty_recur(root->leftNode);
        root->leftNode = nullptr;
    }
    if (root->rightNode != nullptr) {
        make_empty_recur(root->rightNode);
    }
    delete root;
    root = nullptr;
}

void bst_tree::make_empty() {
    make_empty_recur(head);
    head = nullptr;
}

void bst_tree::preorder_traversal() {
    vector<int> temp = preorder_traversal_recur(head);
    for (int i=0; i<temp.size(); i++) {
        cout << temp[i] << " ";
    }
    cout << "\n";
}