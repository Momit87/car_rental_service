#include <iostream>
#include <bits/stdc++.h>
#include <fstream>
#include <conio.h>

#include <unistd.h>

using namespace std;
class driverlist
{
public:
    void show_driver_list()
    {
        cout << "**********************************DRIVER NAME***********************************\n\n";
        ifstream in("driver_list.txt");
        string str;
        int cntr = 1;
        while (getline(in, str))
        {
            cout << cntr << " : " << str << endl
                 << endl;
            cntr++;
        }
        in.close();
        cout << "Total Number of driver : " << cntr - 1 << endl
             << endl;
    }
};