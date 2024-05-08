#include <iostream>
using namespace std;

typedef struct node
{
    int key;
    string name;
    struct node *left_child, *right_child;
} tree_node;

class BST
{
private:
    tree_node *root;

public:
    BST();                                  // constructor
    ~BST();                                 // deconstructor
    bool IsEmpty();                         // if binary tree is empty
    void insert_node(int num, string data); // insert node
    void delete_node(int num);              // delelete node
    void free_tree(tree_node *tree);        // free memory of nodes
    void inorder(tree_node *ptr);           // inorder system
    void Print();                           // printout result
    tree_node *search_insert(int key);      // set if value can be added
};