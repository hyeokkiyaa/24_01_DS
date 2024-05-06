#include "BST.h"
using namespace std;

BST::BST()
{
    root = NULL;
}

BST::~BST()
{
    delete_tree(root);
    root = NULL;
}

void BST::delete_tree(tree_node *ptr)
{
    if (ptr)
    {
        delete_tree(ptr->left_child);
        delete_tree(ptr->right_child);
        delete (ptr);
    }
}

bool BST::IsEmpty()
{
    return (root == NULL);
}

void BST::insert_node(int num,string data){
    tree_node *ptr = NULL, *parent = NULL;
    parent = search(num);
    if(parent || IsEmpty()){
        ptr = new tree_node;
    } else if (!parent){
        cout << to_string(num) << " is already in the tree" << endl;
    }

    
    
    if(ptr == NULL){
        cerr << "The memory is full" << endl;
        exit(1);
    }
    ptr->key = num;
    ptr->name = data;
    ptr->left_child = ptr->right_child = NULL;

    if(IsEmpty()){
        root = ptr;
    } else {
        if (num < parent->key) parent->left_child = ptr;
        else parent->right_child = ptr;
    }
}

void BST::inorder(tree_node *ptr)
{
    if (ptr)
    {
        inorder(ptr->left_child);
        cout << "[" << ptr->name << "]";
        inorder(ptr->right_child);
    }
}

void BST::Print()
{
    inorder(root);
    cout << endl;
}

tree_node* BST::search(int key){
    tree_node *tree = root;
    while (tree)
    {
        if(key==tree->key) return NULL;
        else if (key < tree->key){
            if(tree->left_child == NULL) return tree;
            else tree = tree ->left_child;
        }else {
            if(tree->right_child == NULL) return tree;
            else tree = tree->right_child;
        }
    }
    return NULL;
    
}