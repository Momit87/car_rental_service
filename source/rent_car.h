#include <iostream>
#include <bits/stdc++.h>
#include <fstream>
#include <conio.h>
#include "show_rent.h"

#include <unistd.h>
using namespace std;
void main_menu();
long long int cntrcar=0;
long long int cntrday=0;
long long int cntr = 0;
long long int car_num;
vector<string> v1, v2;

string customer_name;


class rent_car
{
public:
    void rent_car1(string cus_name)
    {
        customer_name = cus_name;
        ifstream in("car_list.txt");
        string str;

        while (getline(in, str))
        {
            v1.push_back(str);

            string str1;

            getline(in, str1);
            v2.push_back(str1);
            cntr++;
        }
        in.close();
    }







    void rent_car_num()
    {


        string car_str ;
        cout << "\nEnter the number of the car that you are willing to rent : ";
        cin >> car_str;

        car_num=stoi(car_str);
        // cout<< car_num<<"\n";
        cin.ignore();
        cout << endl
             << endl;

        if (car_num > cntr||car_num<1)
        {
            cout << "\t\t Invalid car Number sir \n\n";
            rent_car_num();

        }

    }

    void rent_car_days()
    {
        string num_str;
        int num_days;
        cout << "Enter the number of days that you are willing to rent : ";
        cin>>num_str;
        num_days=stoi(num_str);
        cin.ignore();
        cout << endl
             << endl;

        if (num_days <= 10 && num_days >= 1)
        {
            int cc = stoi(v2[car_num - 1]);

            Showing_rent_info(customer_name, car_num, v1[car_num - 1], v2[car_num - 1], cc, num_days);
        }
        else
        {
            cout << "                                Invalid\n\n";
            cout << "                         Any one can rent a car for\n\n"
                 << "                            Maximum of 10 days\n\n"
                 << "                            Minimum of 1 days\n\n";
            rent_car_days();
        }

    }
};
