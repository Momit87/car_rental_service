#include <bits/stdc++.h>
#include "login.h"
#include "admin.h"
#include "user.h"
#include "register.h"
using namespace std;

void main_menu();
void admin_login();
void user_login();
void forgot_pass_admin();

bool check_user(pair<string, string> &str);
void admin_login()
{

    int chances = 0;
    bool flag = false;
    ifstream in("./admin_pass.txt");
    string og_pass;
    in >> og_pass;
    in.close();
    while (chances != 3)
    {
        string pass = login_sys_admin();
        if (pass == og_pass)
        {

            flag = true;
            system("cls");
            cout << "\n    Succesfully Logged in as admin!!!";
            sleep(1);
            system("cls");
            string flag = admin();
            if (flag == "false")
            {
                system("cls");
                main_menu();
            }
            else if (flag == "update_pass")
            {
                system("cls");
                forgot_pass_admin();
            }
            return;
        }

        else
        {
            system("cls");

            cout << "\n    You have entered wrong password" << endl;
            cout << "\n    Please try again!!" << endl;
            chances++;
            flag = false;
            sleep(1);
            system("cls");
        }
    }
    if (!flag)
    {
        system("cls");

        cout << "\nSorry you are out of chances!!!\n\n";
        sleep(1);
        system("cls");
        main_menu();
    }
}
void user_login()
{
    int chances = 0;
    bool flag = false;
user_login_panel:
    cout << "\n Press 1 to register or press 2 for login\n";
    string choice;
    cin >> choice;
    if (choice == "1")
    {
        system("cls");
        bool reg = user_register();
        if (!reg)
        {

            system("cls");
            cout << "\nUnsuccessful registration!!!";
            sleep(1);
            system("cls");
            main_menu();
        }
        else
        {
            system("cls");
            cout << "\nSuccessful Registration!!!!";
            sleep(1);
            system("cls");
            bool u = user();
            if (!u)
            {
                system("cls");
                main_menu();
            }
        }
    }
    else if (choice == "2")
    {
        system("cls");

        pair<string, string> uname_pass = login_sys_user();
        bool chk_user = check_user(uname_pass);
        if (chk_user)
        {
            system("cls");
            cout << "\n   Login Successful!!";
            sleep(1);
            system("cls");
            rent_car ob2;
            ob2.rent_car1(uname_pass.first);

            bool u_flag = user();
            if (!u_flag)
            {
                system("cls");
                main_menu();
            }
        }

        else
        {
            system("cls");
            cout << "\n\nUser Not Found!!!";
            sleep(1);
            system("cls");
            main_menu();
        }
    }
    else
    {
        system("cls");
        cout << "\n\nInvalid Option!!!";
        sleep(1);
        system("cls");
        goto user_login_panel;
    }
}
void main_menu()
{
    welcome obj1;
    obj1.welcome1();
    cout << "\n\n\n---------Main Menu-----------" << endl;
    cout << "1.Admin" << endl;
    cout << "2.User" << endl;
    cout << "3.Exit" << endl;
    cout << "----Chose One: ";
    string choice;
    cin >> choice;
    if (choice == "1")
    {
        system("cls");
        admin_login();
    }
    else if (choice == "2")
    {
        system("cls");
        user_login();
    }
    else if (choice == "3")
    {
        system("cls");
        cout << "\n\n--------Thank you for being with us-----------\n";

        return;
    }
    else
    {
        system("cls");
        cout << "\nInvalid Option!!!";
        sleep(1);
        system("cls");
        main_menu();
    }
}

void forgot_pass_admin()
{
    string new_pass, confirm_pass;
    string old_pass;
    ifstream in("./admin_pass.txt");
    getline(in, old_pass);
    in.close();
    system("cls");
    cout << "New Password: ";
    char ch1 = getch();
    while (ch1 != 13)
    {
        cout << '*';
        new_pass += ch1;
        ch1 = getch();
    }
    cout << "\n\nConfirm Password: ";

    char ch2 = getch();
    while (ch2 != 13)
    {
        cout << '*';
        confirm_pass += ch2;
        ch2 = getch();
    }

    if (new_pass == confirm_pass)
    {

        system("cls");
        if (new_pass == old_pass)
        {
            system("cls");
            cout << "\nThe entered password is same as the current one!!!!\n\nPlease try again!!!";
            sleep(1);
            system("cls");
            forgot_pass_admin();
            return;
        }
        cout << "\n\nPassword has been updated!!!";
        ofstream out("./admin_pass.txt");
        out << new_pass;
        out.close();
        sleep(1);
        system("cls");
        string flag = admin();
        if (flag == "false")
        {
            system("cls");
            main_menu();
        }
        else if (flag == "update_pass")
        {
            system("cls");
            forgot_pass_admin();
        
        }
    }
    else
    {
        system("cls");
        cout << "\nPlease try again!!";
        sleep(1);
        system("cls");
        forgot_pass_admin();
        return;
    }
}

bool check_user(pair<string, string> &str)
{
    string username, pass;
    ifstream in("./user_cred.txt");

    while (getline(in, username) and getline(in, pass))
    {
        if (username == str.first and pass == str.second)
            return true;
    }
    return false;
}