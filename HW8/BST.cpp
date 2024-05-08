#include "BST.h"
using namespace std;

//Constructor of class
BST::BST()  
{
    root = NULL;
}

//Deconstrctoor of class
BST::~BST()
{
    free_tree(root);
    root = NULL;
}

//call recursively to free the memory that was allocated dynamically
void BST::free_tree(tree_node *ptr)
{
    if (ptr)
    {
        free_tree(ptr->left_child);
        free_tree(ptr->right_child);
        delete (ptr);
    }
}

//checking if bst is empty
bool BST::IsEmpty()
{
    return (root == NULL);
}

//inserting node
void BST::insert_node(int num, string data)
{
    tree_node *ptr = NULL, *parent = NULL;  //ptr to pointing current node, parent node as the top node where node will be added
    parent = search_insert(num);    //finding parentnode to add in
    if (parent || IsEmpty())    //if parent is NULL or binary tree is empty meaning ready to add
    {
        ptr = new tree_node;    //give memory
        //handle case when memory is full
        if (ptr == NULL)    
        {
            cerr << "The memory is full" << endl;
            exit(1);
        }
    }
    else if (!parent)
    {
        cout << to_string(num) << " is already in the tree" << endl;
        return;
    }

    ptr->key = num;
    ptr->name = data;
    ptr->left_child = ptr->right_child = NULL;

    if (IsEmpty())
    {
        root = ptr;
    }
    else
    {
        if (num < parent->key)
            parent->left_child = ptr;
        else
            parent->right_child = ptr;
    }
}

void BST::inorder(tree_node *ptr)
{
    if (ptr)
    {
        inorder(ptr->left_child);
        cout << "[" << ptr->key << "] ";
        cout << ptr->name << endl;
        inorder(ptr->right_child);
    }
}

void BST::Print()
{
    if (IsEmpty())
    {
        cout << "Empty" << endl;
        return;
    }
    inorder(root);
    cout << endl;
}

tree_node *BST::search_insert(int key)
{
    tree_node *tree = root;
    while (tree)
    {
        if (key == tree->key)
            return NULL;
        else if (key < tree->key)
        {
            if (tree->left_child == NULL)
                return tree;
            else
                tree = tree->left_child;
        }
        else
        {
            if (tree->right_child == NULL)
                return tree;
            else
                tree = tree->right_child;
        }
    }
    return NULL;
}

void BST::delete_node(int key) {
    tree_node *parent = NULL;
    tree_node *now = root;
    int isDirection = 0; // 0 for left, 1 for right

    while (now != NULL && now->key != key) {
        parent = now;
        if (key < now->key) {
            now = now->left_child;
            isDirection = 0;
        } else {
            now = now->right_child;
            isDirection = 1;
        }
    }

    if (now == NULL) {
        cout << to_string(key) << " is not in the tree" << endl;
        return;
    }

    if (now->left_child == NULL && now->right_child == NULL) {
        if (now == root) {
            root = NULL;
        } else {
            if (isDirection == 0) {
                parent->left_child = NULL;
            } else {
                parent->right_child = NULL;
            }
        }
        delete now;
    } else if (now == root) {
        if (now->left_child == NULL) {
            root = now->right_child;
        } else if (now->right_child == NULL) {
            root = now->left_child;
        } else {
            tree_node* beneath = now->right_child;
            tree_node* beneathParent = now;

            while (beneath->left_child != NULL) {
                beneathParent = beneath;
                beneath = beneath->left_child;
            }

            beneath->left_child = now->left_child;
            if (beneathParent != now) {
                beneathParent->left_child = beneath->right_child;
                beneath->right_child = now->right_child;
            }

            root = beneath;
        }
        delete now;
    } else {
        if (now->left_child == NULL) {
            if (isDirection == 0) {
                parent->left_child = now->right_child;
            } else {
                parent->right_child = now->right_child;
            }
        } else if (now->right_child == NULL) {
            if (isDirection == 0) {
                parent->left_child = now->left_child;
            } else {
                parent->right_child = now->left_child;
            }
        } else {
            tree_node* beneath = now->right_child;
            tree_node* beneathParent = now;

            while (beneath->left_child != NULL) {
                beneathParent = beneath;
                beneath = beneath->left_child;
            }

            beneath->left_child = now->left_child;
            if (beneathParent != now) {
                beneathParent->left_child = beneath->right_child;
                beneath->right_child = now->right_child;
            }

            if (isDirection == 0) {
                parent->left_child = beneath;
            } else {
                parent->right_child = beneath;
            }
            delete now;
        }
    }
}
