//Time taken: About pure 6 to 7 hours
#include "stack.h"
#include <iostream>
using namespace std;

int main(void){
    Linked_Stack st;
    string filename;

    cout<<"Enter Filename: ";
    cin >> filename;
    st.Load(filename);

    cout <<"\nHere Result"<<endl;
    cout <<"==========="<<endl;
    st.Print();


    return 0;
}
