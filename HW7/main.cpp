#include "stack.h"
#include <iostream>
using namespace std;

int main(void){
    Linked_Stack st;
    
    st.Push(10);
    st.Push(20);
    st.Push(30);
    
    cout <<" "<<endl;

    cout <<st.Pop()<<endl;
}
