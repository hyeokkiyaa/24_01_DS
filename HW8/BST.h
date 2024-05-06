#include <iostream>
using namespace std;

typedef struct node {
    int key;
    string name;
    struct node *left_child, *right_child;
} tree_node;

class BST{
    private:
        tree_node* root;
    public:
        BST();
        ~BST();
        bool IsEmpty();
        void insert_node(int num,string data);
        void delete_tree(tree_node* tree);
        void inorder(tree_node* ptr);
        void Print();
        //BST
        tree_node* search(int key);
        
};