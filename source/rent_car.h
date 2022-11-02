#include <iostream>
#include <bits/stdc++.h>
#include <fstream>
#include <conio.h>
#include "show_rent.h"


#include <unistd.h>

using namespace std;
class rent_car
{
public:
    void rent_car1()
    {
        ifstream in("car_list.txt");
        string str;
        vector<string> v1, v2;
        int cntr = 0;
        while (getline(in, str))
        {
            v1.push_back(str);

            string str1;

            getline(in, str1);
            v2.push_back(str1);
            cntr++;
        }

        in.close();
        string customer_name;
        cout<<"Enter your name : ";getline(cin,customer_name);
        cout<<endl<<endl;

        int car_num;
        cout << "Enter the number of the car that you are willing to rent : ";
        cin >> car_num;
        cout << endl
             << endl;

        if (car_num > cntr)
        {
            cout << "\t\t Invalid\n\n";
            rent_car1();
        }
        else
        {
            int num_days;
            cout << "Enter the number of days that you are willing to rent : ";
            cin >> num_days;
            cout << endl
                 << endl;
            if (num_days <= 10 && num_days >= 1)
            {
                int cc = stoi(v2[car_num - 1]);
                Showing_rent_info(customer_name,car_num,v1[car_num - 1], v2[car_num - 1], cc, num_days);
            }
            else
            {
                cout << "\t\t Invalid\n\n";
                cout << "Any one can rent a car for\n"
                     << "                            Maximum of 10 days\n"
                     << "                            Minimum of 1 days\n";
                rent_car1();
            }
        }
    }
};