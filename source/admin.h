#include <iostream>
#include <fstream>
#include "carlist.h"
#include "driverlist.h"
using namespace std;

void shihab()
{
    cout << "\n----Admin Menu----\n\n";
    cout << "1.Car List" << endl;
    cout << "2.Driver List" << endl;
    cout << "3.Rent Details" << endl;
    cout << "4.Update your password." << endl;
    cout << "5.Car list Update." << endl;
    cout << "6.Driver List Update." << endl;
    cout << "7.Exit to Main Menu." << endl;
    cout << "---Select One: ";
}
string admin()
{

    while (1)
    {
    adminPanel:
        shihab();
        string choices;
        cin >> choices;
        if (choices == "1")
        {
            carlist obj1;
            obj1.show_car_list();
        }

        else if (choices == "2")
        {
            driverlist obj2;
            obj2.show_driver_list();
        }

        else if (choices == "3")
        {
            ifstream in("rent_details.txt");
            vector<string> v;
            string str;
            while (getline(in, str))
            {
                v.push_back(str);
            }
            in.close();

            string strcmp = "                  Rent details           ";
            long long int cntr = 1;
            for (auto u : v)
            {
                if (u == strcmp)
                {
                    cout << "\n\tRent details No : " << cntr << endl;
                    cntr++;
                }
                else
                {
                    cout << u << endl;
                }
            }
        }
        else if (choices == "4")
        {
            return "update_pass";
        }
        else if (choices == "5")
        {
            // car list update
        }
        else if (choices == "6")
        {
            // driver list update
        }
        else if (choices == "7")
        {
            return "false";
        }
        else
        {
            system("cls");
            cout << "\nInvalid Option!!";
            sleep(1);
            system("cls");
            goto adminPanel;
        }
    }
}