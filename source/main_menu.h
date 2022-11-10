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
void forgot_pass_user();
bool check_user(pair<string, string> &str);
void admin_login()
{
    cout << "\nPress 1 to login or press 2 in case of you forgot your password.\n";
    int choice;
    cin >> choice;
    if (choice == 1)
    {
        system("cls");
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
                bool flag = admin();
                if (!flag)
                {
                    system("cls");
                    main_menu();
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
    else
    {
        forgot_pass_admin();
    }
}
void user_login()
{
    int chances = 0;
    bool flag = false;
    cout << "\n Press 1 to register or press 2 for login\n";
    int choice;
    cin >> choice;
    if (choice == 1)
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
    else
    {
        string username, pass, confirm_pass;
        system("cls");
        cin.ignore();
        cout << "\nEnter Username: ";
        getline(cin, username);
        cout << "\nForgot password???? Press 1 or press 2 to proceed to login\n";
        int choice;
        cin >> choice;
        if (choice == 1)
        {
            system("cls");
            forgot_pass_user();
        }
        else
        {
            pair<string, string> uname_pass = login_sys_user();
            bool chk_user = check_user(uname_pass);
            if (chk_user)
            {
                system("cls");
                cout << "\n   Login Successful!!";
                sleep(1);
                system("cls");
                bool u_flag = user();
                if (!u_flag)
                {
                    system("cls");
                    main_menu();
                }
            }
        }
    }
    while (chances != 3)
    {
        int pass;
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
menu_panel:
    cout << "\n\n\n---------Main Menu-----------" << endl;
    cout << "1.Admin" << endl;
    cout << "2.User" << endl;
    cout << "3.Exit" << endl;
    cout << "----Chose One: ";
    int choice;
    cin >> choice;
    if (choice == 1)
    {
        system("cls");
        admin_login();
    }
    else if (choice == 2)
    {
        system("cls");
        user_login();
    }
    else if (choice == 3)
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
        goto menu_panel;
    }
}
// Forgot Password function for admin
void forgot_pass_admin()
{
    string new_pass, confirm_pass;
    system("cls");
    cout << "New Password: ";
    char ch = getch();
    while (ch != 13)
    {
        cout << '*';
        new_pass += ch;
        ch = getch();
    }
    cout << "\n\nConfirm Password: ";
    int chances = 0;
    bool confirmed = false;
    while (chances != 2)
    {
    confirm_pass:
        char ch = getch();
        while (ch != 13)
        {
            cout << '*';
            confirm_pass += ch;
            ch = getch();
        }
    check_pass:
        if (new_pass == confirm_pass)
        {
            confirmed = true;
            system("cls");
            cout << "\n\nPassword has been updated!!!";
            ofstream out("./admin_pass.txt");
            out << new_pass;
            out.close();
            sleep(1);
            system("cls");
            bool flag = admin();
            if (!flag)
            {
                system("cls");
                main_menu();
            }
        }
        else
        {
            chances++;
            cout << "\nDidn't Match!!!";
            cout << "\nPlease re-confirm your password: ";
            confirmed = false;
            goto confirm_pass;
        }
    }
    if (!confirmed)
    {
        system("cls");
        cout << "\nPlease try again!!";
        sleep(1);
        system("cls");
        main_menu();
    }
}

void forgot_pass_user()
{

    cout << "matha nosto re mama!!!!" << endl;
    return;
}

bool check_user(pair<string, string> &str)
{
    string username, pass;
    ifstream in("./user_cred.txt");

    while (getline(in, username) and in >> pass)
    {
        if (username == str.first and pass == str.second)
            return true;
    }
    return false;
}