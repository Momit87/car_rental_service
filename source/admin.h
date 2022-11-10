#include <iostream>
#include <fstream>
#include "carlist.h"
#include "driverlist.h"
using namespace std;

void shihab()
{
    cout << "\n----Admin Menu----\n\n";
    cout << "1.Car List" << endl;
    cout << "2.Driver List & Details" << endl;
    cout << "3.Rent Details" << endl;
    cout << "4.Exit to Main Menu" << endl;
    cout << "---Select One: ";
}
bool admin()
{

    while (1)
    {
    admin_panel:
        shihab();
        int choices;
        cin >> choices;
        if (choices == 1)
        {
            carlist obj1;
            obj1.show_car_list();
        }

        else if (choices == 2)
        {
            driverlist obj2;
            obj2.show_driver_list();
        }

        else if (choices == 3)
        {
            cout << "Rent Details" << endl;
        }
        else if (choices == 4)
        {
            return false;
        }
        else
        {
            system("cls");
            cout << "\nInvalid Option!!";
            sleep(1);
            system("cls");
            goto admin_panel;
        }
    }
}