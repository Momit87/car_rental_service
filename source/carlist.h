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
        cout << "---------Car Details---------" << endl
             << endl;
        ifstream in("car_list.txt");
        string str;
        int cntr = 0;
        cout << " No  |    CC      |        NAME\n\n";
        while (getline(in, str))
        {
            string str1;
            cntr++;
            getline(in, str1);
            cout << setw(3)<<cntr << setw(10) << str1 <<"CC      "<<str<<endl
                
                 << endl;
            
        }
        cout<< "Number of cars we have "<<cntr<<endl;

        in.close();
    }
};