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
        cout << "-----------Driver List-----------"<<endl<<endl;
        ifstream in("driver_list.txt");
        string str;
        int cntr = 0;
        cout<<" N0 |  Name \n\n";
        while (getline(in, str))
        {cntr++;
            cout <<setw(3)<< cntr << " :  " << str << endl
                 << endl;
            
        }
        in.close();
        cout << "Number of driver's : " << cntr  << endl
             << endl;
    }
};