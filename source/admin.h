#include <iostream>
#include <fstream>
#include "carlist.h"
#include "driverlist.h"
#include "car_list_update.h"
#include "driver_list_update.h"

using namespace std;
void show_booked_driver_list()
    {
        cout << "-----------Booked Driver List-----------"<<endl<<endl;
        ifstream in("booked_driver_list.txt");
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
void booked_list_to_driver_list_update()
{

    
    vector<string> bv1, bv2, bv3, bv4;
    ifstream inb("booked_driver_list.txt");
    string str;

    while (getline(inb, str))
    {
        bv1.push_back(str);

       
    }
    inb.close();
    if(bv1.empty()){
        return;
    }
    string choice_str;
    cout << "\nSelect the number of the driver You want to remove from here : ";
    cin >> choice_str;
    int drup = stoi(choice_str);
    ofstream outb("booked_driver_list.txt");
    for (int i = 0; i != bv1.size(); i++)
    {
        if (i != drup - 1)
        {
            outb << bv1[i] << endl;
            
        }
    }

    outb.close();
    ifstream in("driverlist.txt");

    while (getline(in, str))
    {
        bv3.push_back(str);

        
    }
    in.close();
    ofstream out("driverlist.txt");
    for (int i = 0; i != bv3.size(); i++)
    {

        out << bv3[i] << endl;
        
    }
    out << bv1[drup - 1] << endl;
   

    out.close();
}
void booked_car_list()
{
    system("cls");
    cout << "---------Booked Car Details---------" << endl
         << endl;
    ifstream in("booked.txt");
    string str;
    int cntr = 0;
    cout << " No  |    CC      |        NAME\n\n";
    while (getline(in, str))
    {
        string str1;
        cntr++;
        getline(in, str1);
        cout << setw(3) << cntr << setw(10) << str1 << "CC      " << str << endl

             << endl;
    }
    cout << "Number of cars booked " << cntr << endl;

    in.close();
}
void booked_list_to_car_list_update()
{

    
    vector<string> bv1, bv2, bv3, bv4;
    ifstream inb("booked.txt");
    string str;

    while (getline(inb, str))
    {
        bv1.push_back(str);

        string str1;

        getline(inb, str1);
        bv2.push_back(str1);
    }
    inb.close();
    if(bv1.empty()||bv2.empty()){
        return;
    }
    string choice_str;
    cout << "\nSelect the of the car You want to remove from here : ";
    cin >> choice_str;
    int carup = stoi(choice_str);
    ofstream outb("booked.txt");
    for (int i = 0; i != bv1.size(); i++)
    {
        if (i != carup - 1)
        {
            outb << bv1[i] << endl;
            outb << bv2[i] << endl;
        }
    }

    outb.close();
    ifstream in("car_list.txt");

    while (getline(in, str))
    {
        bv3.push_back(str);

        string str1;

        getline(in, str1);
        bv4.push_back(str1);
    }
    in.close();
    ofstream out("car_list.txt");
    for (int i = 0; i != bv3.size(); i++)
    {

        out << bv3[i] << endl;
        out << bv4[i] << endl;
    }
    out << bv1[carup - 1] << endl;
    out << bv2[carup - 1] << endl;

    out.close();
}
void shihab()
{
    cout << "\n----Admin Menu----\n\n";
    cout << "1.Available Car List." << endl;
    cout << "2.Available Driver List." << endl;
    cout << "3.Rent Details." << endl;
    cout << "4.Update your password." << endl;
    cout << "5.Car list Update." << endl;
    cout << "6.Driver List Update." << endl;
    cout << "7.Show booked car list." << endl;
    cout << "8.Remove cars from booked list." << endl;
    cout << "9.Show booked drivers list."<<endl;
    cout << "10.Remove drivers from booked list."<<endl;
    cout << "11.Exit to Main Menu." << endl;
    cout << "---Select One: ";
}
string admin()
{

    while (1)
    {

    adminPanel:
        shihab();
        string choices;
        cin >> choices;
        system("cls");
        if (choices == "1")
        {
            carlist obj1;
            obj1.show_car_list();
        }

        else if (choices == "2")
        {
            driverlist obj2;
            obj2.show_driver_list();
        }

        else if (choices == "3")
        {
            ifstream in("rent_details.txt");
            vector<string> v;
            string str;
            while (getline(in, str))
            {
                v.push_back(str);
            }
            in.close();

            string strcmp = "                  Rent details           ";
            long long int cntr = 1;
            for (auto u : v)
            {
                if (u == strcmp)
                {
                    cout << "\n\tRent details No : " << cntr << endl;
                    cntr++;
                }
                else
                {
                    cout << u << endl;
                }
            }
        }
        else if (choices == "4")
        {
            return "update_pass";
        }
        else if (choices == "5")
        {
            // car list update
            car_list_update();
        }
        else if (choices == "6")
        {
            // driver list update
            dr_up();
        }
        else if (choices == "7")
        {
            booked_car_list();
        }
        else if (choices == "8")
        {
            booked_car_list();

            booked_list_to_car_list_update();
        }
        else if(choices == "9"){
            show_booked_driver_list();

        }
        else if(choices == "10"){
                show_booked_driver_list();
                booked_list_to_driver_list_update();
        }
        else if (choices == "11")
        {
            return "false";
        }
        else
        {
            system("cls");
            cout << "\nInvalid Option!!";
            sleep(1);
            system("cls");
            goto adminPanel;
        }
    }
}