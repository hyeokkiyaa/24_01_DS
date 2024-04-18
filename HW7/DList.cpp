#include "DList.h"
using namespace std;



void DList::Print(){
    list_node *cur =NULL;
    for(cur = head; cur != NULL;cur = cur->link){
        cout << cur->data << endl;
    }
}

void DList::Insert(Element data){
    list_node *new_node = new list_node;
    new_node->data = data;
    new
}