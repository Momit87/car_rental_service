#include <iostream>
#include <bits/stdc++.h>
#include <fstream>
#include <conio.h>
using namespace std;

void carlist_update()
{
    ifstream in("car_list.txt");
    string car_name, cc;
    vector<string> vet, vet1;
    while (getline(in, car_name))
    {
        getline(in, cc);
        vet.push_back(car_name);
        vet1.push_back(cc);
    }
    in.close();
    cout<<"\nEnter car name : ";
    cin.ignore();
    getline(cin, car_name);
    cout<<"\nEnter cc of the car : ";
    
    getline(cin, cc);
    vet.push_back(car_name);
    vet1.push_back(cc);
    ofstream out("car_list.txt");
    for (long long int i = 0; i < vet.size(); i++)
    {
        out << vet[i] << endl
            << vet1[i] << endl;
    }
    out.close();
}
void carname_remove()
{
    ifstream in("car_list.txt");
    string car_name, cc;
    vector<string> vet, vet1;
    while (getline(in, car_name))
    {
        getline(in, cc);
        vet.push_back(car_name);
        vet1.push_back(cc);
    }
    in.close();
    cout<<"\nEnter car name : ";
    cin.ignore();
    getline(cin, car_name);
    
    cout<<"\nEnter cc of the car : ";
   
    getline(cin, cc);
    vector<string>::iterator it, it1;
    it = find(vet.begin(), vet.end(), car_name);
    it1 = find(vet1.begin(), vet1.end(), cc);
    

    bool flag =false;
    if (it == vet.end() || it1 == vet1.end())
    {
        ofstream out("car_list.txt");
        cout << "\nCar Not Found!!!" << endl;
        for (long long int i = 0; i < vet.size(); i++)
        {
            
           
                out << vet[i] << endl
                   << vet1[i] << endl;
            
        }
        out.close();
    }
    else
    {
        cout<<"\nCar removed succesfully \n";
        ofstream out("car_list.txt");
        for (long long int i = 0; i < vet.size(); i++)
        {
            
            if(vet[i] == car_name && vet1[i] == cc&&flag==false){
                flag=true;
            }
            else{
                out << vet[i] << endl
                   << vet1[i] << endl;
            }

        }
        out.close();
    }
}
void car_list_update()
{
    string carstr;
    cout << "\nPress '1' for car addition\n\n"
         << "Press Any key for car deletion\n\n"
         << "Your Choice : ";
    cin >> carstr;
    if (carstr == "1")
    {
        system("cls");
        carlist_update();
    }
    else
    {
        system("cls");
        carname_remove();
    }
    return;
}
