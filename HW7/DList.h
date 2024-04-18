#ifndef __DLIST_H__
#define __DLIST_H__

#include <iostream>

using namespace std;

typedef string Element;

typedef struct t_list_node
{
    Element data;
    struct t_list_node *link;
} list_node;

class DList
{
private:
    list_node *head;

public:
    DList();
    ~DList();
    void delete_list(list_node *node_ptr);
    list_node *Retrieve(Element data);
    list_node *Retrieve(int index);
    void Insert(Element data);
    void Delete(Element data);
    void Invert();
    void Print();
    bool IsEmpty();
};

#endif