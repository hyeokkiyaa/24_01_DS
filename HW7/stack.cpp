#include "stack.h"

using namespace std;

Linked_Stack::Linked_Stack()
{
    top = NULL;
}

Linked_Stack::~Linked_Stack()
{
    list_node *new_node;
    while (top != NULL)
    {
        new_node = top;
        top = top->link;
        delete new_node;
    }
}

void Linked_Stack::Push(Element item) // inserting value in stack
{
    list_node *new_node = new list_node;
    if (new_node == NULL)
        return;
    new_node->data = item;
    new_node->link = top;
    top = new_node;
}

Element Linked_Stack::Pop() // retrieve item from stack
{
    Element e;
    list_node *del;
    if (top == NULL)
    {
        throw out_of_range("Stack is empty");
    }
    e = top->data;
    del = top;
    top = top->link;
    delete del;
    return e;
}

Element Linked_Stack::Peek()
{
    return top->data;
}

void Linked_Stack::Load(string filename)
{
    string line;
    ifstream file(filename);
    if (file.is_open())
    {
        while (getline(file, line))
        {
            Element new_person;
            int index;
            index = Tokenizer(line);
            new_person.name = line.substr(0, index);
            line = line.substr(index + 1);
            index = Tokenizer(line);
            new_person.id = stoi(line.substr(0, index));
            line = line.substr(index + 2);
            new_person.email = line;
            Push(new_person);
        }
        file.close();
    }
    else
    {
        cout << "File does not exist" << endl;
    }
}

int Linked_Stack::Tokenizer(string st)
{
    int length = st.length();
    int index = -1;
    for (int i = 0; i < length; i++)
    {
        if (st[i] == ',')
        {
            index = i;
            break;
        }
    }
    return index;
}

void Linked_Stack::Print()
{
    Element e;
    while(!IsEmpty())
    {
        e = Pop();
        cout << e.id<<", "+e.name<<", "+e.email<<endl; 
    }
}

bool Linked_Stack::IsEmpty(){
    return (top==NULL);
}
