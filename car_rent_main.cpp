#include <iostream>
#include <bits/stdc++.h>
#include <fstream>
#include <conio.h>

// #include "./source/show_rent.h"
#include "./source/welcome.h"
#include "./source/carlist.h"
#include "./source/driverlist.h"

#include "./source/rent_car.h"

using namespace std;

int main()
{
    welcome obj1;
    obj1.welcome1();
    carlist obj2;
    obj2.show_car_list();
    driverlist obj3;
    obj3.show_driver_list();
    rent_car obj4;
    obj4.rent_car1();

    return 0;
}