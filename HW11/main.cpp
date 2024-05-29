#include "contact.h"
using namespace std;

int main(void)
{
    Contact ct;
    cout << "CONTACT" << endl;
    ct.load();
    int option;
    while (1)
    {
        cout << "=> Choose Option" << endl;
        cout << "[1] INSERT" << endl;
        cout << "[2] DELETE" << endl;
        cout << "[3] FIND" << endl;
        cout << "[4] SORT" << endl;
        cout << "[5] PRINT" << endl;
        cout << "[6] SAVE" << endl;
        cout << "[0] EXIT" << endl;
        cout << "=> ";
        cin >> option;
        cout << endl;
        switch (option)
        {
        case 1:
            ct.getValue();
            break;

        case 2:
            ct.deletion();
            break;

        case 3:
            ct.retrieve();
            break;

        case 4:
            ct.sort();
            break;

        case 5:
            ct.print();
            break;

        case 6:
            ct.save();
            break;

        case 0:
            cout << "EXIT";
            return 0;
            break;
        }
    }
}