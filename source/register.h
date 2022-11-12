#include <bits/stdc++.h>
#include <conio.h>
using namespace std;
string get_pass();
bool user_register();
bool user_register()
{
    cin.ignore();
    cout << "Enter Username: ";
    string username, user_pass, confirm_user_pass;
    getline(cin, username);
    cout << "\nEnter Password: ";
    user_pass = get_pass();

    cout << "\n\nConfirm Your Password: ";
    int chances = 0;

    while (chances != 2)
    {
        confirm_user_pass = get_pass();
        if (user_pass == confirm_user_pass)
        {

            ofstream out("./user_cred.txt", ios::app);
            out << "\n";
            out << username;
            out << "\n";
            out << user_pass;
            rent_car ob2;
            ob2.rent_car1(username);
            // mahir
            // mahir
            // mahir
            return true;
        }
        else
        {
            system("cls");
            cout << "\nDidn't match!!!";
            cout << "\nPlease re-confirm your password: ";
            chances++;
            continue;
        }
    }
    return false;
}

string get_pass()
{
    string str;
    char ch = getch();
    while (ch != 13)
    {
        cout << '*';
        str += ch;
        ch = getch();
    }
    return str;
}