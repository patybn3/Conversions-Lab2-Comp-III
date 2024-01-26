//
//  main.cpp
//  Lab2
//
//  Created by Patricia Antlitz on 2/6/23.
//
#include <iostream>
#include <string>
using namespace std;

const int oz_to_pound = 16;
const int grams_to_kilo = 1000;
double conversion_number = .45359237;

void conversion(int pounds, double ounces, int& kilograms, double& grams);
void get_input(int& pounds, double& ounces);
void output_values(int pounds, double ounces, int kg, double grams);

int main(int argc, const char* argv[])
{
    cout.setf(ios::fixed);
    cout.precision(8);
    
    int pounds, kg;
    double ounces, grams;
    
    get_input(pounds, ounces);
    conversion(pounds, ounces, kg, grams);
    output_values(pounds, ounces, kg, grams);
}

void get_input(int& pounds, double& ounces)
{
    while (true)
    {
        cout << "Please enter the number of pounds: ";
        cin >> pounds;
        
        if (cin.fail() || pounds < 0)
        {
            cin.clear();
            
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            
            cout << "That's not a number greater than or equal to 0! Please try again..." << endl;
        }
        else
            break;
    }
    
    while (true)
    {
        cout << "Please enter the number of ounces: ";
        cin >> ounces;
        
        if (cin.fail() || ounces <= 0 || ounces >= 16)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            
            cout << "That's not a number greater than or equal to 0, and less than 16! Please try again..." << endl;
        }
        else
            break;
    }
}

void conversion(int pounds, double ounces, int& kg, double& grams)
{
    
    double weight = pounds + ounces / oz_to_pound;
    weight *= conversion_number;
    kg = weight;
    grams = (weight - kg) * grams_to_kilo;
}

void output_values(int pounds, double ounces, int kg, double grams)
{
    cout << pounds << " pounds and " << ounces << " ounces converts to" << endl;
    cout << kg << " kilograms and " << grams << " grams" << endl;
}
