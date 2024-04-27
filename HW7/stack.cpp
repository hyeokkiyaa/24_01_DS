#include "stack.h"

using namespace std;

//top as a shift method

Linked_Stack::Linked_Stack()    //constr for Linked_Stack class
{
    top = NULL;     
}

Linked_Stack::~Linked_Stack()   //free the memory
{
    list_node *new_node;    // temp
    while (top != NULL) //as moving one by one 
    {
        new_node = top;
        top = top->link;
        delete new_node;    //free the node
    }
}

void Linked_Stack::Push(Element item) // inserting value in stack
{
    //top to shift right side as push in the stack
    list_node *new_node = new list_node;    //new node to add 
    if (new_node == NULL)   //if memory is full then nothing
        return;
    new_node->data = item;  //item
    new_node->link = top;   //link to set as top
    top = new_node; //top is then new node
}

Element Linked_Stack::Pop() // retrieve item from stack
{
    Element e;
    list_node *del; //temp node to free the memory
    if (IsEmpty())//if stack is Empty
    {
        throw out_of_range("Stack is empty"); // since Element is somewhat value, just cannot return. new function found on Internet
    }

    e = top->data;  // return value saved from top->data
    del = top;      // del to be top
    top = top->link;    //top to be the next value
    delete del; //free the memory which was at the top before this function
    return e;   //return value
}

Element Linked_Stack::Peek()
{
    return top->data;   //just value to be returned
}

//Load file and put the value in the stack
void Linked_Stack::Load(string filename)
{
    string line;// one line in the textfile
    ifstream file(filename);    //file value
    if (file.is_open()) //open 
    {
        while (getline(file, line)) //one line to be retrieved
        {
            Element new_person; //call variable
            int index;  //for tokenizer of ","
            index = Tokenizer(line);    //call tokenizer function
            new_person.name = line.substr(0, index);    //the name to be retrieved
            line = line.substr(index + 1);  //cut line for convenience
            index = Tokenizer(line);    
            new_person.id = stoi(line.substr(0, index));    //id retrieved
            line = line.substr(index + 2);
            new_person.email = line;    
            Push(new_person);   //push the value in the stack
        }
        file.close();
    }
    else    //if file does not exit
    {
        cout << "File does not exist" << endl;
    }
}

int Linked_Stack::Tokenizer(string st)  //for finding , in the line and return index of it
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

void Linked_Stack::Print()  //printout result with format
{
    Element e;
    while(!IsEmpty())
    {
        e = Pop();  //pop the value from the stack
        cout << e.id<<", "+e.name<<", "+e.email<<endl; 
    }
}

bool Linked_Stack::IsEmpty(){   //if top is null, meaning stack is empty
    return (top==NULL);
}
