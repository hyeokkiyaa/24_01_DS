#include "DList.h"
using namespace std;

void DList::Print()
{
    list_node *cur = NULL;
    for (cur = head; cur != NULL; cur = cur->link)
    {
        cout << cur->data << endl;
    }
    delete cur;
}

void DList::Insert(Element data)
{
    list_node *new_node = new list_node;
    new_node->data = data;
    if (head->link == NULL)
    {
        head->link = new_node;
        new_node->link = NULL;
    }
    else
    {
        // add to the last
        list_node *cur = NULL;
        cur = head;
        while (cur->link != NULL)
        {
            cur = cur->link;
        }
        cur->link = new_node;
    }
}
DList::DList()
{
    head = new list_node;
    head->data = NULL;
    head->link = NULL;
}

DList::~DList()
{
    list_node *cur = NULL;
    for (cur = head; cur != NULL; cur = cur->link)
    {
        delete(cur);
    }
}
list_node DList::*Retrieve(Element data);
list_node DList::*Retrieve(int index);