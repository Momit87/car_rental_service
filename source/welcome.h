#include <iostream>
#include <bits/stdc++.h>
#include <fstream>
#include <conio.h>

#include <unistd.h>

using namespace std;

class welcome 
{
public:
    void welcome1()
    {
        ifstream in("welcome.txt"); 
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