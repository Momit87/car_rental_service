#include <iostream>
#include <bits/stdc++.h>
#include <fstream>
#include <conio.h>

using namespace std;
void Showing_rent_info(string customer_name, int car_num, string str1, string str2, int cc, int num_days)
{
    
    int the_rent = (cc * 1.5) * num_days;
    ifstream in("driver_list.txt");
    string str;
    vector<string> v;
    while (getline(in, str))
    {
        v.push_back(str);
    }
    in.close();
    ifstream in1("rent_details.txt");
    string strshow;
    vector<string> v2;
    while (getline(in1, strshow))
    {
        v2.push_back(strshow);
    }
    in1.close();

    ofstream out("rent_details.txt");
    long long int show_count = 1;
    for (auto u : v2)
    {

        out << u << endl;
    }

    out << "                  Rent details           \n\n\n";
    out << "Customer name                : " << customer_name << endl;
    out << "Car name                     : " << str1 << "\n";
    out << "Car CC                       : " << str2 << "CC\n";
    out << "Number of days               : " << num_days << endl;
    if(v[car_num - 1] != *v.end()){
    out << "Driver name                  : " << v[car_num - 1] << endl;}
    else{
        out << "Driver name                  : " << v[v.size()-1] << endl;
    }
    out << "------------------------------------------------\n";
    out << "Total cost                   : " << the_rent << " taka only \n";
    out << endl
        << "      Thanks for being with us" << endl;
    out << endl
        << "----------Treat it like yours----------\n\t";
    out.close();
    cout << "                  Rent details           \n\n\n";
    cout << "Customer name                : " << customer_name << endl;
    cout << "Car name                     : " << str1 << "\n";
    cout << "Car CC                       : " << str2 << "CC\n";
    cout << "Number of days               : " << num_days << endl;
   if(v[car_num - 1] != *v.end()){
    cout << "Driver name                  : " << v[car_num - 1] << endl;}
    else{
        cout << "Driver name                  : " << v[v.size()-1] << endl;
    }
    cout << "------------------------------------------------\n";
    cout << "Total cost                   : " << the_rent << " taka only \n";
    cout << endl
         << "      Thanks for being with us" << endl;
    cout << endl
         << "----------Treat it like yours----------\n\t";
}