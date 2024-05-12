#include "BST.h"
using namespace std;

// Constructor of class
BST::BST()
{
    root = NULL;
}

// Deconstrctoor of class
BST::~BST()
{
    free_tree(root);
    root = NULL;
}

// call recursively to free the memory that was allocated dynamically
void BST::free_tree(tree_node *ptr)
{
    if (ptr)
    {
        free_tree(ptr->left_child);
        free_tree(ptr->right_child);
        delete (ptr);
    }
}

// checking if bst is empty
bool BST::IsEmpty()
{
    return (root == NULL);
}

// inserting node
void BST::insert_node(string find, string data)
{
    tree_node *ptr = NULL, *parent = NULL; // ptr to pointing current node, parent node as the top node where node will be added
    parent = search_insert(find);           // finding parentnode to add in
    if (parent || IsEmpty())               // if parent is NULL or binary tree is empty meaning ready to add
    {
        ptr = new tree_node; // give memory
        // handle case when memory is full
        if (ptr == NULL)
        {
            cerr << "The memory is full" << endl;
            exit(1);
        }
    }
    // if it exists, NULL is not returned
    else if (!parent)
    {
        cout << find << " is already in the tree" << endl;
        return;
    }

    // setting node
    ptr->key = find;
    ptr->value = data;
    ptr->left_child = ptr->right_child = NULL;

    if (IsEmpty()) // if binary tree was empty, then add to root
    {
        root = ptr;
    }
    else // otherwise add to corret node(if value is bigger then on right side. Same for other way around)
    {
        if (find < parent->key)
            parent->left_child = ptr;
        else
            parent->right_child = ptr;
    }
}

void BST::inorder(tree_node *ptr) // inorder system
{
    if (ptr)
    {
        inorder(ptr->left_child);
        cout << "[" << ptr->key << "] ";
        cout << ptr->value << endl;
        inorder(ptr->right_child);
    }
}

void BST::Print() // printout result
{
    if (IsEmpty())
    {
        cout << "Empty" << endl;
        return;
    }
    cout << "In inorder System:" << endl;
    inorder(root);
    cout << endl;
}

// return what computer has found
tree_node *BST::search_insert(string key)
{
    tree_node *tree = root; // starting from root node
    while (tree)            // until tree exists
    {
        if (key == tree->key)     // if found value
            return NULL;          // return to NULL meaning ready to add
        else if (key < tree->key) // if finding value is smaller then left_child to go through
        {
            if (tree->left_child == NULL) // if leftchild is NULL meaning could not find value
                return tree;
            else
                tree = tree->left_child; // otherwise left_child to be connected
        }
        // same as above
        else
        {
            if (tree->right_child == NULL)
                return tree;
            else
                tree = tree->right_child;
        }
    }
    return NULL; // empty case
}

void BST::delete_node(string find)
{
    tree_node *parent = NULL; // parent node where del node is
    tree_node *del = root;    // deltion node
    int isDirection = 0;      // 0 for left, 1 for right

    // finding parent node which is for del node
    while (del != NULL && del->key != find) // del is not NULL and del key is not equal to key from user
    {
        parent = del; // parent to del at first is root node
        // isDirection is for left or right from parent node view
        if (find < del->key)
        {
            del = del->left_child;
            isDirection = 0;
        }
        else
        {
            del = del->right_child;
            isDirection = 1;
        }
    }

    // del to NULL mean value does not exist in the binary tree
    if (del == NULL)
    {
        cout << find << " is not in the tree" << endl;
        return;
    }

    // 1st: del node does not have any child node
    if (del->left_child == NULL && del->right_child == NULL)
    {
        if (del == root) // if del node is root node then just simply make root to NULL
        {
            root = NULL;
        }
        else
        {
            // if left_child from parent node of del node
            if (isDirection == 0)
            {
                // simply make left to NULL
                parent->left_child = NULL;
            } // other way around
            else
            {
                parent->right_child = NULL;
            }
        }
        delete del; // free memory of del node
    }
    // del node is root node and 2nd 3rd 4th
    else if (del == root)
    {
        // 2nd: only left child is NULL
        if (del->left_child == NULL) // if del node's left child is null
        {
            root = del->right_child; // change root node to root's right_child
        }
        // 3rd: otherway around
        else if (del->right_child == NULL)
        {
            root = del->left_child;
        }
        // 4th: if both children nodes exists
        else
        {
            tree_node *beneath = del->right_child; // will shift
            tree_node *beneathParent = del;        // will shift with beneath, but will always above

            // finding the smallest value(always left_child because of the characteristic of binary tree)
            while (beneath->left_child != NULL)
            {
                beneathParent = beneath;
                beneath = beneath->left_child;
            }

            // abstarctly switch smallest node with del node
            beneath->left_child = del->left_child;

            // if smallest node's parent does not equal to del node
            if (beneathParent != del)
            {
                beneathParent->left_child = beneath->right_child; // the smallest node's place then change for its right child
                beneath->right_child = del->right_child;          // set smallest node as the del node
            }

            root = beneath; // root is then becomes the smallest node
        }
        delete del; // free del node's memory
    }
    // del node is not root node and 2nd 3rd 4th
    else
    {
        // 2nd: only left child is null
        if (del->left_child == NULL)
        {
            // always check direction 0 is left
            if (isDirection == 0)
            {
                parent->left_child = del->right_child; // del's parent node's left_child is now del's right_child
            }
            else
            {
                parent->right_child = del->right_child; // always right_child since left_child is NULL
            }
        }
        // 3rd: only right child is NULL
        // same as above but other way around
        else if (del->right_child == NULL)
        {
            if (isDirection == 0)
            {
                parent->left_child = del->left_child;
            }
            else
            {
                parent->right_child = del->left_child;
            }
        }
        // 4th: two children nodes exist same as root but with small changes -> will show by comments
        else
        {
            tree_node *beneath = del->right_child;
            tree_node *beneathParent = del;

            while (beneath->left_child != NULL)
            {
                beneathParent = beneath;
                beneath = beneath->left_child;
            }

            beneath->left_child = del->left_child;
            if (beneathParent != del)
            {
                beneathParent->left_child = beneath->right_child;
                beneath->right_child = del->right_child;
            }

            // only changes since it will have to decide which new nodes will be added into(0 for left 1 for right)
            if (isDirection == 0)
            {
                parent->left_child = beneath;
            }
            else
            {
                parent->right_child = beneath;
            }
            delete del;
        }
    }
}
