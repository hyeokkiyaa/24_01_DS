#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;



// for date variable
typedef struct
{
    int year;
    int month;
    int day;
} Date;

// for person variable
typedef struct
{
    string name;
    Date dob;
    string email;
    string phone;
} Person;

// class Node for linked list
class Node
{
public:
    Person info;
    Node *next;
    Node(Person newInfo)
    {
        this->info = newInfo;
        this->next = nullptr;
    }
};

// class Contact main class for this assignment
class Contact
{
private:
    Node *list;                          // linked list dynamically set memory
    static int totalNum;                 // for checking number of data set
    Date str2date(const string strdate); // change string into suitable date format
    void mergeSort(Node *&head, int option);
    Node *mergeName(Node *left, Node *right);
    Node *mergeDOB(Node *left, Node *right);
    Node *getMiddle(Node *head);

public:
    Contact();                        // constructor set list as nullptr
    ~Contact();                       // deconstructor (delete memory)
    void addContact(string infoLine); // add contact into list
    void load();                      // load contactList.txt which saves all the contacts
    void print();                     // printout contact numbers
    void save();                      // save into contactList.txt
    void retrieve();                  // get value by email or name
    void printFormat(Node *ptr);
    void checkPrint();
    void deletion();
    void sort();
    void getValue();
};