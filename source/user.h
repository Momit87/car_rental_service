#include <bits/stdc++.h>
/* #include "carlist.h"
#include "driverlist.h" */
#include "rent_car.h"
// #include "show_rent.h"
using namespace std;

void pinon()
{
    cout << "\n----User Menu----\n\n";
    cout << "1.Car List" << endl;
    cout << "2.Rent Details" << endl;
    cout << "3.Exit to Main Menu" << endl;
    cout << "---Select One: ";
}

bool user()
{
    while (1)
    {
    user_panel:
        pinon();
        int choices;
        cin >> choices;
        if (choices == 1)
        {
            carlist ob1;
            ob1.show_car_list();
            rent_car ob2;
            ob2.rent_car1();
        }

        else if (choices == 2)
        {
            cout << "Here we will show rent details!!!" << endl;
        }

        else if (choices == 3)
        {

            return false;
        }
        else
        {
            cout << "\nInvalid Option!!";
            sleep(1);
            system("cls");
            goto user_panel;
        }
    }
}