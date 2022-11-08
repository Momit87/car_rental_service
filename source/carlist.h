#include <iostream>
#include <bits/stdc++.h>
#include <fstream>
#include <conio.h>
#include <unistd.h>

using namespace std;
class carlist
{
public:
    void show_car_list()
    {
        cout << "---------Car Details---------"<<endl<<endl;
        ifstream in("car_list.txt");
        string str;
        int cntr = 1;
        while (getline(in, str))
        {
            string str1;
            cout << "Car number : " << cntr << endl;
            getline(in, str1);
            cout << "Car name : " << str << endl;
            cout << "Car CC   : " << str1 << " CC" << endl
                 << endl;
            cntr++;
        }

        in.close();
    }
};