#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
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
    void load();
    void print();
    void save();
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

void Contact::load()
{
    string line;
    ifstream file("contactList.txt");
    if (!file.is_open())
    {
        cout << "NO data file!" << endl;
        return;
    }

    while (getline(file, line))
    {
        if(line==""){
            break;
        }
        addContact(line);
    }
    file.close();
    cout << ">" << totalNum << " loaded from data file!" << endl;
}

void Contact::save()
{
    ofstream writeFile;
    writeFile.open("contactList.txt");
    if (!writeFile.is_open())
    {
        cout << "Error-> Data file cannot be found!!!!" << endl;
        return;
    }

    Node *ptr = list;
    string input;
    while (ptr != nullptr)
    {
        writeFile << ptr->info.name << "; ";
        writeFile << ptr->info.dob.year;
        writeFile << setfill('0') << setw(2) << ptr->info.dob.month;
        writeFile << setfill('0') << setw(2) << ptr->info.dob.day <<"; ";
        writeFile << ptr->info.email << "; ";
        writeFile << ptr->info.phone <<endl;
        ptr = ptr->next;
    }
    writeFile.close();
}

void Contact::print()
{
    Node *ptr = list;
    while (ptr != nullptr)
    {
        cout << ptr->info.name << " ";
        cout << ptr->info.dob.year << "-";
        cout << setfill('0') << setw(2) << ptr->info.dob.month << "-";
        cout << setfill('0') << setw(2) << ptr->info.dob.day << " ";
        cout << ptr->info.email << " ";
        cout << ptr->info.phone << endl;
        ptr = ptr->next;
    }
}

int main(void)
{
    Contact ct;
    ct.load();
    string newPerson;
    getline(cin, newPerson);
    ct.addContact(newPerson);
    ct.save();
    ct.print();

    return 0;
}