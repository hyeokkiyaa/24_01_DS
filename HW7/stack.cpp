#include "stack.h"

using namespace std;

Linked_Stack::Linked_Stack(){
    top = NULL;
}

Linked_Stack::~Linked_Stack(){
    list_node* new_node;
    while(top!=NULL){
        new_node = top;
        top = top->link;
        delete new_node;
    }
}

void Linked_Stack::Push(Element item) // inserting value in stack
{
    list_node *new_node = new list_node;
    if(new_node == NULL) return;
    new_node->data = item;
    new_node->link = top;
    top = new_node;
}

Element Linked_Stack::Pop() // retrieve item from stack
{
    Element e;
    list_node *del;
    if(top==NULL){
        return (Element)0;
    }
    e=top->data;
    del = top;
    top = top->link;
    delete del;
    return e;
}

Element Linked_Stack::Peek(){
    return top->data;
}

