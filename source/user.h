#include <bits/stdc++.h>
/* #include "carlist.h"
#include "driverlist.h" */
#include "rent_car.h"
// #include "show_rent.h"
using namespace std;

void pinon()
{
    cout << "\n----User Menu----\n\n";
    cout << "1.Car Rent" << endl;

    cout << "2.Exit to Main Menu" << endl;
    cout << "---Select One: ";
}

bool user()
{
    while (1)
    {
    user_panel:
        pinon();
        string choices;
        cin >> choices;
        if (choices == "1")
        {
            system("cls");

            carlist ob1;

            ob1.show_car_list();
            rent_car ob2;

            ob2.rent_car_num();
            ob2.rent_car_days();
        }

        else if (choices == "2")
        {

            return false;
        }
        else
        {
            system("cls");
            cout << "\nInvalid Option!!";
            sleep(1);
            system("cls");
            goto user_panel;
        }
    }
}