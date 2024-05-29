#include "contact.h"
using namespace std;
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

void Contact::getValue()
{
    cout << "--Add Contact--" << endl;
    cin.ignore();
    cout << "=> Type name: ";
    string name;
    getline(cin, name);
    cout << "=> Type DOB(eg. 20010505): ";
    string dob;
    getline(cin, dob);
    cout << "=> Type E-Mail: ";
    string email;
    getline(cin, email);
    cout << "=> Type phone number(eg. 010-1234-5678): ";
    string phone;
    getline(cin, phone);
    string infoline = name + "; " + dob + "; " + email + "; " + phone;
    addContact(infoline);
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

void Contact::deletion()
{
    cout << "--Delete Contact--" << endl;
    cout << "=> Type name to delete: ";
    cin.ignore();
    string name;
    getline(cin, name);

    Node *prev;
    Node *curr = list;
    while (curr && curr->info.name.compare(name) != 0)
    {
        prev = curr;
        curr = curr->next;
        if (curr == nullptr)
        {
            cout << "Name does not exist!!!!!" << endl
                 << endl;
            return;
        }
    }

    printFormat(curr);
    int option = 0;
    while (option != 1 && option != 2)
    {
        cout << "Are you sure you want to delete contact information above?" << endl;
        cout << "1. yes" << endl;
        cout << "2. no" << endl;
        cout << "=> ";
        cin >> option;
        if (option != 1 && option != 2)
        {
            cout << "Option must be either 1 or 2. Try again" << endl;
        }
    }
    if (option == 2)
    {
        cout << endl;
        return;
    }

    if (curr)
    {
        if (curr == list)
            list = curr->next;
        else
            prev->next = curr->next;
        delete curr;
    }

    totalNum--;
    cout << "Contact deleted!!!" << endl
         << endl;
}

void Contact::sort()
{
    cout << "--Sort Contact--" << endl;
    int option = 0;
    while (option != 1 && option != 2)
    {
        cout << "=> By which you want to sort contact? " << endl;
        cout << "1. Name" << endl;
        cout << "2. Date of Birth" << endl;
        cout << "=> ";
        cin >> option;
        if (option != 1 && option != 2)
        {
            cout << "Option must be either 1 or 2. Try again" << endl;
        }
    }
    mergeSort(list, option);
    cout << endl;
}

void Contact::mergeSort(Node *&head, int option)
{
    if (head == nullptr || head->next == nullptr)
    {
        return;
    }

    Node *middle = getMiddle(head);
    Node *nextToMiddle = middle->next;
    middle->next = nullptr;

    mergeSort(head, option);
    mergeSort(nextToMiddle, option);

    if (option == 1)
    {
        head = mergeName(head, nextToMiddle);
    }
    else
    {
        head = mergeDOB(head, nextToMiddle);
    }
}

Node *Contact::mergeName(Node *left, Node *right)
{
    Node *result = nullptr;
    if (left == nullptr)
        return right;
    if (right == nullptr)
        return left;

    if (left->info.name <= right->info.name)
    {
        result = left;
        result->next = mergeName(left->next, right);
    }
    else
    {
        result = right;
        result->next = mergeName(left, right->next);
    }
    return result;
}

Node *Contact::mergeDOB(Node *left, Node *right)
{
    Node *result = nullptr;
    if (left == nullptr)
        return right;
    if (right == nullptr)
        return left;

    if (left->info.dob.year < right->info.dob.year ||
        (left->info.dob.year == right->info.dob.year &&
         (left->info.dob.month < right->info.dob.month ||
          (left->info.dob.month == right->info.dob.month &&
           left->info.dob.day < right->info.dob.day))))
    {
        result = left;
        result->next = mergeDOB(left->next, right);
    }
    else
    {
        result = right;
        result->next = mergeDOB(left, right->next);
    }
    return result;
}

Node *Contact::getMiddle(Node *head)
{
    if (head == nullptr)
    {
        return head;
    }
    Node *first = head;
    Node *second = head->next;

    // one pointer to reach end by two list node
    // second pointer to reach end by moving 1 list
    // when first pointer reaches at the end it will
    while (second != nullptr)
    {
        second = second->next;
        if (second != nullptr)
        {
            first = first->next;
            second = second->next;
        }
    }

    return first;
}

void Contact::printFormat(Node *ptr)
{
    cout << ptr->info.name << " | ";
    cout << ptr->info.dob.year << "-";
    cout << setfill('0') << setw(2) << ptr->info.dob.month << "-";
    cout << setfill('0') << setw(2) << ptr->info.dob.day << " | ";
    cout << ptr->info.email << " | ";
    cout << ptr->info.phone << endl;
}

void Contact::retrieve()
{
    cout << "--Find Contact--" << endl;
    int option = 0;
    while (option != 1 && option != 2)
    {
        cout << "=> By which you want to find contact? " << endl;
        cout << "1. Name" << endl;
        cout << "2. Email" << endl;
        cout << "=> ";
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
        cout << "=> Type name: ";
    }
    else
    {
        cout << "=> Type email: ";
    }

    getline(cin, value);
    cout << endl;

    Node *ptr = list;
    if (option == 1)
    {
        while (ptr != nullptr)
        {

            if (ptr->info.name == value)
            {
                printFormat(ptr);
                cout << endl;
                break;
            }
            ptr = ptr->next;
            if (ptr == nullptr)
            {
                cout << "Name does not exist!!!" << endl
                     << endl;
                break;
            }
        }
    }
    else
    {
        while (ptr != nullptr)
        {

            if (ptr->info.email == value)
            {
                printFormat(ptr);
                cout << endl;
                break;
            }
            ptr = ptr->next;
            if (ptr == nullptr)
            {
                cout << "Email does not exist!!!" << endl
                     << endl;
                break;
            }
        }
    }
}

void Contact::checkPrint()
{
    Node *ptr = list;
    cout << ptr->info.name << endl;
    cout << ptr->info.dob.year << endl;
    cout << ptr->info.dob.month << endl;
    cout << ptr->info.dob.day << endl;
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
    cout << totalNum << " number of data saved!" << endl
         << endl;
}

void Contact::print() // printint result
{
    Node *ptr = list;
    int count = 1;
    cout << "=> Contact List" << endl;
    cout << endl;
    while (ptr != nullptr)
    {
        cout << count++ << ": ";
        printFormat(ptr);
        ptr = ptr->next;
    }
    cout << endl;
}
