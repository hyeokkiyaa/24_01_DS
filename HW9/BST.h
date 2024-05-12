#include <iostream>
using namespace std;

typedef struct node
{
    string key;
    string value;
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
    void insert_node(string find, string data); // insert node
    void delete_node(string find);              // delelete node
    void free_tree(tree_node *tree);        // free memory of nodes
    void inorder(tree_node *ptr);           // inorder system
    void Print();                           // printout result
    tree_node *search_insert(string key);      // set if value can be added
    tree_node *search(string key);  
};