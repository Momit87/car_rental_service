#include <iostream>
#include <bits/stdc++.h>
#include <fstream>
#include <conio.h>
using namespace std;
void dr_add()
{
    ifstream in("driver_list.txt");
    string str;

    vector<string> v;
    while (getline(in, str))
    {
        v.push_back(str);
    }
    in.close();
    cout << "\nEnter drivers name : ";
    cin.ignore();
    getline(cin, str);
    v.push_back(str);
    ofstream out("driver_list.txt");
    for (auto u : v)
    {
        out << u << endl;
    }
    out.close();
}
void dr_del()
{
    driverlist objrem;
    objrem.show_driver_list();
    ifstream in("driver_list.txt");
    string str;
    long long int driver_count = 0;
    vector<string> v;
    while (getline(in, str))
    {
        v.push_back(str);
        driver_count++;
    }
    in.close();
    string driver_num_str;
    cout << "\nEnter the number of the driver you want to delete : ";
    cin >> driver_num_str;
    long long int driver_num_num = stoi(driver_num_str);
    if (driver_count < driver_num_num || driver_num_num < 1)
    {
        cout << "\tInvalid driver number \n";
        sleep(2);
        system("cls");
        dr_del();
    }
    else
    {
        ofstream out("driver_list.txt");
        for (int i = 0; i != v.size(); i++)
        {
            if (i != driver_num_num - 1)
            {
                out << v[i] << endl;
            }
        }
        out.close();
    }
}
void dr_up()
{
    string drstr;
    system("cls");
    cout << "\nPress '1' for Driver addition\n\n"
         << "Press Any key for Driver deletion\n\n"
         << "Your Choice : ";
    cin >> drstr;
    if (drstr == "1")
    {
        system("cls");
        dr_add();
    }
    else
    {
        system("cls");
        dr_del();
    }
}
