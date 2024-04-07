#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <iomanip>
#include "contact.h"

void Contact::load(string file_name)
{
    char c_str[1024];
    strcpy(c_str, file_name.c_str());

    // implement here
    string line;    //each line in the textfile
    ifstream file(c_str);   //file starts
    if (file.is_open()) //open if textfile exists
    {
        while (getline(file, line)) //loop until line does not exist anymore
        {
            Person new_person;  //struct
            stringstream ss(line);  //let ss be line
            string token;   //tokenizer

            getline(ss, token, ';');    //make token by ;
            strcpy(new_person.name, token.c_str()); //insert value

            getline(ss, token, ';');
            new_person.dob = str2date(token.c_str());   //str2date to separate year month and day

            getline(ss, token, ';');
            strcpy(new_person.email, token.c_str());

            getline(ss, token, ';');
            strcpy(new_person.phone, token.c_str());

            persons[total_num++] = new_person;
        }
        file.close();
    }
    else
    {
        cout << "File does not exist" << std::endl; //if textfile cannot be opened
    }
}

void Contact::print()
{
    for (int i = 0; i < total_num; ++i)
    {   //printing out result
        cout << "[" << persons[i].name <<"] ["<< persons[i].dob.year<<setw(2)<<setfill('0')<<persons[i].dob.month<<setw(2)<<setfill('0')<<persons->dob.day<<"] ["<< persons[i].email<<"] ["<<persons[i].phone<<"]"<<endl;
    }
}
