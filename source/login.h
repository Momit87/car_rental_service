#include <bits/stdc++.h>
using namespace std;

//Login sytem for admin
string login_sys_admin()
{
    cout << "\n\nEnter password to login: ";
    string pass;
    char ch = getch();
    while (ch != 13)
    {
        cout << '*';
        pass += ch;
        ch = getch();
    }
    return pass;
}


//Login system for users
pair<string, string> login_sys_user()
{
    cin.ignore(); // Asiful
    cout << "\n\nEnter Username: ";
    string username;
    getline(cin, username);
    cout << "\nEnter Password: ";
    string pass;
    char ch = getch();
    while (ch != 13)
    {
        cout << '*';
        pass += ch;
        ch = getch();
    }
    pair<string, string> pair_str;
    pair_str.first = username;
    pair_str.second = pass;
    return pair_str;
}