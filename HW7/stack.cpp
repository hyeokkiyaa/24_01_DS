#include "stack.h"

using namespace std;



void Stack::Push(Element item) // inserting value in stack
{
    list.Insert(item);
}

Element Stack::Pop() // retrieve item from stack
{
    if(list.IsEmpty()){
        return (Element)0;
    }
    Element top_element = list.Retrieve_index(0)->data;

    list.Delete(top_element);
    return top_element;
}

Element Stack::Peek(){
    if(list.IsEmpty()){
        return (Element)0;
    }
    Element e;
    e = list.Retrieve_index(0)->data;
    return e;
}

