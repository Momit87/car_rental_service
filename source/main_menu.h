#include <bits/stdc++.h>
#include "login.h"
#include "admin.h"
#include "user.h"
using namespace std;

void main_menu();
void admin_login();
void user_login();
void admin_login()
{
    int chances = 0;
    bool flag = false;
    while (chances != 3)
    {
        int pass = login_sys();
        if (pass == 1234)
        {
            flag = true;
            bool flag = admin();
            if (!flag)
                main_menu();
            break;
        }
        else
        {

            cout << "You have entered wrong password" << endl;
            cout << "Please try again!!" << endl;
            chances++;
            flag = false;
        }
    }
    if (!flag)
    {
        cout << "\nSorry you are out of chances!!!\n\n";
        main_menu();
    }
}
void user_login()
{
    int chances = 0;
    bool flag = false;
    while (chances != 3)
    {
        int pass = login_sys();
        if (pass == 5678)
        {
            flag = true;
            bool flag = user();
            if (!flag)
                main_menu();
            break;
        }
        else
        {

            cout << "You have entered wrong password" << endl;
            cout << "Please try again!!" << endl;
            chances++;
            flag = false;
        }
    }
    if (!flag)
    {
        cout << "\nSorry you are out of chances!!!\n\n";
        main_menu();
    }
}
void main_menu()
{
    cout << "---------Main Menu-----------" << endl;
    cout << "1.Admin" << endl;
    cout << "2.User" << endl;
    cout << "3.Exit" << endl;
    cout << "----Chose One: ";
    int choice;
    cin >> choice;
    if (choice == 1)
    {
        admin_login();
    }
    else if (choice == 2)
    {
        user_login();
    }
    else if (choice == 3)
    {
        cout << "\n\nThank you for being with us\n";
        return;
    }
}
