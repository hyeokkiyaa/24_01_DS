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
    new_node->link = nullptr;
    if (head== nullptr)
    {
        head = new_node;
    }
    else
    {
        // add to the last
        list_node *cur = nullptr;
        cur = head;
        while (cur->link != nullptr)
        {
            cur = cur->link;
        }
        cur->link = new_node;
    }
}
DList::DList()
{
    head =nullptr;
}

DList::~DList()
{
    delete_list(head);
}

void DList::delete_list(list_node *node_ptr){
    while(node_ptr!=nullptr){
        list_node* temp = node_ptr;
        node_ptr = node_ptr->link;
        delete temp;
    }
}

list_node* DList::Retrieve(Element data){
    list_node* cur =head;
    while(cur!=NULL){
        if(cur->data == data){
            return cur;
        }
        cur = cur -> link;
    }
    return nullptr;
}

list_node* DList::Retrieve_index(int index){
    int count =0;
    list_node* cur = head;
    while(cur!=NULL){
        if(count == index)
        {
            return cur;
        }
        count++;
        cur = cur->link;
    }
    return nullptr;
}