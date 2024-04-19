#include "DList.h"
using namespace std;

void DList::Print()
{
    list_node *cur = NULL;
    for (cur = head; cur != NULL; cur = cur->link)
    {
        cout << cur->data << endl;
    }
}

void DList::Insert(Element data)
{
    list_node *new_node = new list_node;
    new_node->data = data;
    new_node->link = NULL;
    if (IsEmpty())
    {
        head = new_node;
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
    head = NULL;
}

DList::~DList()
{
    delete_list(head);
}

void DList::delete_list(list_node *node_ptr)
{
    list_node *curr = head, *next;
    while (curr)
    {
        next = curr->link;
        delete curr;
        curr = next;
    }
}

list_node *DList::Retrieve(Element data)
{
    list_node *cur = head;
    while (cur != NULL)
    {
        if (cur->data == data)
        {
            return cur;
        }
        cur = cur->link;
    }
    return NULL;
}

list_node *DList::Retrieve_index(int index)
{
    int count = 0;
    list_node *cur = head;
    while (cur != NULL)
    {
        if (count == index)
        {
            return cur;
        }
        count++;
        cur = cur->link;
    }
    return NULL;
}

bool DList::IsEmpty()
{
    return (head == NULL);
}

int DList::GetLength()
{
    int n = 0;
    list_node *cur = NULL;
    for (cur = head; cur != NULL; cur = cur->link){
        n++;
    }
    return n;
}

void DList::Invert(){
    if(IsEmpty()) return;
    list_node* cur = head, *next = head->link;
    while(cur){
        if(cur==head) cur->link = NULL;
        else {
            cur->link = head;
            head = cur;
        }
        cur =next;
        if(cur) next = next->link;
    }
}