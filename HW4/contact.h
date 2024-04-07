#ifndef __CONTACT_H__
#define __CONTACT_H__
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

typedef struct
{
  int year;
  int month;
  int day;
} Date;

typedef struct
{
  char name[64];
  Date dob;
  char email[64];
  char phone[14];
} Person;

class Contact
{
private:
  Person *persons;
  int total_num;

  // no access to these functions from clients
  Person str2person(char *);

  /**
   * str2date is under private, so have to call in this class
  */
  Date str2date(const string &date_str)  
  {
    Date date;
    date.year = stoi(date_str.substr(0, 5));
    date.month = stoi(date_str.substr(5, 2));
    date.day = stoi(date_str.substr(7, 2));

    return date;
  }

  char *trim(char *);

public:
  Contact(int size)
  {
    total_num = 0;
    persons = new Person[size];
  }
  ~Contact() { delete persons; }

  void load(string);
  void print();
};

#endif
