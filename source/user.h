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
    
    cout << "2.Exit to Main Menu" << endl;
    cout << "---Select One: ";
}

bool user()
{
    while (1)
    {
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

            return false;
        }
    }
}