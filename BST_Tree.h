#ifndef BST_TREE_BST_TREE_H
#define BST_TREE_BST_TREE_H
#include <vector>

class bst_tree {
private:
    struct node {
        int data;
        struct node* leftNode;
        struct node* rightNode;
    };

public:
    struct node* head;
    bst_tree();
    bst_tree(int head_val);
    void add(int val);
    bool remove(int val);
    bool contains(int val);
    std::vector<int> inorder_traversal(struct node* root);
    std::vector<int> preorder_traversal_recur(struct node* root);
    std::vector<int> postorder_traversal(struct node* root);

    int find_min();
    int find_max();
    bool is_empty();
    void make_empty_recur(struct node* root);
    void make_empty();
    void preorder_traversal();
};

#endif
