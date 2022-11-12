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
    ofstream out("driver_list.txt");
    vector<string>::iterator it, it1;
    it = find(v.begin(), v.end(), str);
    bool flag = false;
    if (it == v.end())
    {
        cout << "\n\nDriver not found !!\n";
        for (auto u : v)
    {
        out << u << endl;
    }
    }
    else
    {
        cout << "\nDriver removed succesfully !!\n";
        for (auto u : v)
        {
            if (*it == u && flag == false)
            {
                flag=true;
            }
            else
            {

                out << u << endl;
            }
        }
    }
    out.close();
}
void dr_up()
{
    string drstr;
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
