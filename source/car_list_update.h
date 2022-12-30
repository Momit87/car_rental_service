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
    carlist objrem;
    objrem.show_car_list();
    long long int car_num_re=0;
    ifstream in("car_list.txt");
    string car_name, cc;
    vector<string> vet, vet1;
    while (getline(in, car_name))
    {
        getline(in, cc);
        vet.push_back(car_name);
        vet1.push_back(cc);
        car_num_re++;
    }
    in.close();
    string car_num_str;
    
    cout<<"\nEnter the number of the car you want to delete : ";cin>>car_num_str;
    long long int car_num_num=stoi(car_num_str);
    if(car_num_re<car_num_num||car_num_num<1){
        cout<<"\tInvalid car number \n";
        sleep(2);
        system("cls");
        carname_remove();

    }else{
        ofstream out("car_list.txt");
        for(int i=0;i!=vet.size();i++){
            if(i!=car_num_num-1){
                out<<vet[i]<<endl<<vet1[i]<<endl;

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
