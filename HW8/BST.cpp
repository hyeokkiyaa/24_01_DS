#include "BST.h"
using namespace std;

BST::BST()
{
    root = NULL;
}

BST::~BST()
{
    free_tree(root);
    root = NULL;
}

void BST::free_tree(tree_node *ptr)
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

void BST::insert_node(int num, string data)
{
    tree_node *ptr = NULL, *parent = NULL;
    parent = search_insert(num);
    if (parent || IsEmpty())
    {
        ptr = new tree_node;
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

void BST::delete_node(int key)
{
    tree_node *temp;
    temp = search_delete(key);
    if (temp == NULL)
    {
        cout << to_string(key) << " is not in the tree" << endl;
        return;
    }
    if (IsEmpty())
    {
        cout << "BST is empty" << endl;
        return;
    }

    int checkRightOrLeft = 0; // right:0 left:1
    tree_node *left = temp->left_child;
    tree_node *right = temp->right_child;
    tree_node *beneath;
    if (right->key == key)
    {
        beneath = temp->right_child;
        checkRightOrLeft = 0;
    }
    else
    {
        beneath = temp->left_child;
        checkRightOrLeft = 1;
    }

    if (beneath->left_child == NULL && beneath->right_child == NULL)
    {
        delete beneath;
        if (checkRightOrLeft == 0)
        {
            temp->right_child = NULL;
        }
        else
        {
            temp->left_child = NULL;
        }
    }
    else if (beneath->left_child != NULL && beneath->right_child == NULL)
    {
        if (checkRightOrLeft == 0)
        {
            temp->right_child = beneath->left_child;
        }
        else
        {
            temp->left_child = beneath->left_child;
        }
        delete beneath;
    }
    else if (beneath->left_child == NULL && beneath->right_child != NULL)
    {
        if (checkRightOrLeft == 0)
        {
            temp->right_child = beneath->right_child;
        }
        else
        {
            temp->left_child = beneath->right_child;
        }
        delete beneath;
    } else {
        tree_node* beneathRight;
        

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

tree_node *BST::search_delete(int key)
{
    tree_node *tree = root;
    tree_node *left;
    tree_node *right;
    while (tree)
    {
        left = tree->left_child;
        right = tree->right_child;
        if (left->key == key || right->key == key)
        {
            return tree;
        }
        if (key < tree->key)
        {
            tree = tree->left_child;
        }
        else
        {
            tree = tree->right_child;
        }
    }
    return NULL;
}