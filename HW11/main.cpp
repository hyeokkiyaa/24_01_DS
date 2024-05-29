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
};

int Contact::totalNum = 0;

Contact::Contact()
{
    list = nullptr;
    totalNum = 0;
}

Contact::~Contact()
{
    Node *temp = list;
    while (temp != nullptr)
    {
        Node *next = temp->next;
        delete temp;
        temp = next;
    }
}

Date Contact::str2date(const string strdate)
{
    // change string into suitable int values
    Date dist;
    dist.year = stoi(strdate.substr(0, 5));
    dist.month = stoi(strdate.substr(5, 2));
    dist.day = stoi(strdate.substr(7, 2));
    return dist;
}

void Contact::addContact(string infoLine)
{
    Person addPerson;
    string getValue;
    int index;

    // name
    index = infoLine.find(";");
    getValue = infoLine.substr(0, index);
    addPerson.name = getValue;
    infoLine = infoLine.substr(index + 1);

    // birthday
    index = infoLine.find(";");
    getValue = infoLine.substr(0, index);
    Date addDate = str2date(getValue);
    addPerson.dob = addDate;
    infoLine = infoLine.substr(index + 1);

    // email
    index = infoLine.find(";");
    getValue = infoLine.substr(1, index - 1);
    addPerson.email = getValue;
    infoLine = infoLine.substr(index + 2);

    // phone number
    addPerson.phone = infoLine;

    Node *add = new Node(addPerson);
    if (list == nullptr) // meaning no data inserted in
    {
        list = add;
    }
    else
    { // otherwise add to linked list
        Node *ptr = list;
        while (ptr->next != nullptr)
        {
            ptr = ptr->next;
        }
        ptr->next = add;
    }

    totalNum++; // incease total number of linked list
}

void Contact::deletion(){
    cout << "> Delete " << endl;
    cout << "> Type name to delete: ";
    string name;
    getline(cin, name);

    Node* prev;
    Node* curr = list;
    while(curr && curr->info.name.compare(name) !=0){
        prev= curr;
        curr = curr->next;
    }

    if(curr){
        if(curr == list) list = curr->next;
        else prev->next = curr->next;
        delete curr;
    }
}

void Contact::printFormat(Node *ptr)
{
    cout << ptr->info.name << " ";
    cout << ptr->info.dob.year << "-";
    cout << setfill('0') << setw(2) << ptr->info.dob.month << "-";
    cout << setfill('0') << setw(2) << ptr->info.dob.day << " ";
    cout << ptr->info.email << " ";
    cout << ptr->info.phone << endl;
}

void Contact::retrieve()
{
    int option = 0;
    while (option != 1 && option != 2)
    {
        cout << "By which you want to find contact? " << endl;
        cout << "1. Name" << endl;
        cout << "2. Email" << endl;
        cout << "-> ";
        cin >> option;
        if (option != 1 && option != 2)
        {
            cout << "Option must be either 1 or 2. Try again" << endl;
        }
    }
    cin.ignore();
    string value;
    if (option == 1)
    {
        cout << "Type name: ";
    }
    else
    {
        cout << "Type email: ";
    }

    getline(cin, value);

    Node *ptr = list;
    if (option == 1)
    {
        while (ptr != nullptr)
        {
            if (ptr->info.name == value)
            {
                printFormat(ptr);
                break;
            }
            ptr = ptr->next;
        }
    }
    else
    {
        while (ptr != nullptr)
        {
            // cout << ptr->info.email << endl;
            if (ptr->info.email == value)
            {
                printFormat(ptr);
                break;
            }
            ptr = ptr->next;
        }
    }
}

void Contact::checkPrint()
{
    Node *ptr = list;
    cout << ptr->info.name << endl;
    cout <<ptr->info.dob.year << endl;
    cout <<ptr->info.dob.month << endl;
    cout <<ptr->info.dob.day << endl;
    cout << ptr->info.email << endl;
    cout << ptr->info.phone << endl;
    
}

void Contact::load()
{
    string line;
    ifstream file("contactList.txt");
    if (!file.is_open()) // if file does not exist
    {
        cout << "NO data file!" << endl;
        return;
    }

    while (getline(file, line))
    {
        if (line == "") // if line is empty just stop getting file
        {
            break;
        }
        addContact(line); // otherwise add to the linked list
    }
    file.close();
    cout << ">" << totalNum << " loaded from data file!" << endl;
}

void Contact::save()
{
    ofstream writeFile; // to write into the file
    writeFile.open("contactList.txt");
    if (!writeFile.is_open()) // if file does not exist
    {
        cout << "Error-> Data file cannot be found!!!!" << endl;
        return;
    }

    Node *ptr = list;
    string input;
    while (ptr != nullptr) // write value into the textfile
    {
        writeFile << ptr->info.name << "; ";
        writeFile << ptr->info.dob.year;
        writeFile << setfill('0') << setw(2) << ptr->info.dob.month;
        writeFile << setfill('0') << setw(2) << ptr->info.dob.day << "; ";
        writeFile << ptr->info.email << "; ";
        writeFile << ptr->info.phone << endl;
        ptr = ptr->next;
    }
    writeFile.close();
}

void Contact::print() // printint result
{
    Node *ptr = list;
    while (ptr != nullptr)
    {
        printFormat(ptr);
        ptr = ptr->next;
    }
}

int main(void)
{
    Contact ct;
    ct.load();
    ct.deletion();
    ct.save();

    return 0;
}