#include <iostream>
#include <string>
using namespace std;

typedef struct
{
    int year;
    int month;
    int day;
} Date;

typedef struct
{
    string name;
    Date dob;
    string email;
    string phone;
} Person;

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

class Contact
{
private:
    Node *list;
    static int totalNum;
    Date str2date(const string strdate);

public:
    Contact();
    ~Contact();
    void addContact(string infoLine);
    void print();
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
    Date dist;
    dist.year = stoi(strdate.substr(0, 5));
    dist.month = stoi(strdate.substr(4, 2));
    dist.day = stoi(strdate.substr(6, 2));
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
    getValue = infoLine.substr(0, index);
    addPerson.email = getValue;
    infoLine = infoLine.substr(index + 1);

    // phone number
    addPerson.phone = infoLine;

    Node *add = new Node(addPerson);
    if (list == nullptr)
    {
        list = add;
    }
    else
    {
        Node *ptr = list;
        while (ptr->next != nullptr)
        {
            ptr = ptr->next;
        }
        ptr->next = add;
    }

    totalNum++;
}

void Contact::print()
{
    Node *ptr = list;
    while (ptr != nullptr)
    {
        cout << ptr->info.name << " ";
        cout << ptr->info.dob.year << "-";
        cout << ptr->info.dob.month << "-";
        cout << ptr->info.dob.day << " ";
        cout << ptr->info.email << " ";
        cout << ptr->info.phone << endl;
        ptr = ptr->next;
    }
}

int main(void)
{
    Contact ct;
    string exampleString = "henry choi; 20190303; hchoi@handong.edu; 010-1234-5678";
    ct.addContact(exampleString);
    ct.print();

    return 0;
}