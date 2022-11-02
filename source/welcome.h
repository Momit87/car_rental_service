#include <iostream>
#include <bits/stdc++.h>
#include <fstream>
#include <conio.h>

#include <unistd.h>

using namespace std;

class welcome // welcome class
{
public:
    void welcome1()
    {
        ifstream in("welcome.txt"); // created usinng some random website
        for (int i = 0; i < 8; i++)
        {
            string str;
            getline(in, str);
            cout << str << endl;
        }
        in.close();
        cout << "\n\n\n\n";
    }
};