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
        free_tree(ptr->left_child);
        free_tree(ptr->right_child);
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

void BST::delete_node(int key)
{
    tree_node *parent = search_delete(key);
    if (parent == NULL)
    {
        cout << to_string(key) << " is not in the tree" << endl;
        return;
    }

    tree_node *del = NULL;

    if (IsEmpty())
    {
        cout << "BST is empty" << endl;
        return;
    }

    int checkRightOrLeft = 0; // right:0 left:1
    if (parent->left_child && parent->left_child->key == key)
    {
        del = parent->left_child;
        checkRightOrLeft = 1;
    }
    else if (parent->right_child != NULL && parent->right_child->key==key)
    {
        del = parent->right_child;
    }

    if (del->left_child == NULL && del->right_child == NULL)
    {
        if (checkRightOrLeft == 0)
        {
            parent->left_child = NULL;
        }
        else
        {
            parent->right_child = NULL;
        }
        delete del;
    }
    else if (del->left_child != NULL && del->right_child == NULL)
    {
        if (checkRightOrLeft == 1)
        {
            parent->right_child = del->left_child;
        }
        else
        {
            parent->left_child = del->left_child;
        }
        delete del;
    }
    else if (del->left_child == NULL && del->right_child != NULL)
    {
        if (checkRightOrLeft == 1)
        {
            parent->right_child = del->right_child;
        }
        else
        {
            parent->left_child = del->right_child;
        }
        delete del;
    }
    else
    {
        tree_node *beneathChild = del->right_child;
        tree_node *beneath = del;

        while (beneathChild->left_child != NULL)
        {
            beneath = beneathChild;
            beneathChild = beneathChild->left_child;
        }

        if (checkRightOrLeft == 0)
        {
            parent->left_child = beneathChild;
        }
        else
        {
            parent->right_child = beneathChild;
        }

        beneath->left_child = beneathChild->right_child;

        beneathChild->left_child = del->left_child;
        beneathChild->right_child = del->right_child;
        delete del;
    }
}

tree_node *BST::search_delete(int key)
{
    tree_node *tree = root;
    tree_node *parent = NULL;
    while (tree)
    {
        if (tree->key == key)
        {
            return parent;
        }
        parent = tree;
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
