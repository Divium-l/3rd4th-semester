#pragma execution_character_set( "utf-8" )

#include <iostream>
#include <vector>
#include <Windows.h>
#include <conio.h>
#include <sstream>
#include "TouristTrip.hpp"
#include "TouristTripPrinter.hpp"
#include "TouristTripUtils.hpp"

#define N 3

using namespace std;

void clrscr();

string renderUpperPart(vector<string>& options, const size_t selected);

void displayMenu(vector<string>& options, TouristTrip* trips);

string getResult(const size_t selected, TouristTrip* trips);

int main()
{
    //setlocale(LC_ALL, "utf-8");
    //SetConsoleOutputCP(65001);
    //SetConsoleCP(65001);

    vector<string> options;
    options.push_back("Показать полную таблицу");     //0
    options.push_back("Отсортировать по стране");     //1
    options.push_back("Отсортировать по стоимости");  //2
    
    TouristTrip* trips = new TouristTrip[N];
    trips[0] = TouristTrip("Russia", "Moscow", 7, "4 star", 12999);
    trips[1] = TouristTrip("Ukarin", "Kiev", 4, "3 star", 9999);
    trips[2] = TouristTrip("Australia", "Sydney", 12, "5 star", 97999);

    displayMenu(options, trips);

    delete[] trips;
}

void clrscr()
{
    system("CLS");
}

string renderUpperPart(vector<string>& options, const size_t selected)
{
    stringstream buffer;

    for (size_t i = 0; i < options.size(); i++)
    {
        if (selected == i)
            buffer << "> " << options.at(i) << "\n";
        else
            buffer << "  " << options.at(i) << "\n";
    }

    buffer << "Navigation - ARROWS | Exit - ESC | Select - ENTER\n\n";

    return buffer.str();
}

void displayMenu(vector<string>& options, TouristTrip* trips)
{
    bool exit = false;
    size_t selected = 0;
    string result = "";

    clrscr();
    cout << renderUpperPart(options, selected);
    cout << result << "\n\n";

    while (!exit)
    {
        bool update = false;

        if (_kbhit())
        {
            update = true;

            switch (_getch())
            {
            case 72: //up
                if (selected == 0)
                    break;

                selected--;
                break;

            case 80: //down
                if (selected == 2)
                    break;

                selected++;
                break;
            case 13: //Enter
                result = getResult(selected, trips);
                break;

            case 27: //ESC
                exit = true;
                break;

            default:
                break;
            }

        }

        if (update)
        {
            clrscr();
            cout << renderUpperPart(options, selected);
            cout << result << "\n\n";
        }
    }
}

string getResult(const size_t selected, TouristTrip* trips)
{
    TouristTripPrinter printer = TouristTripPrinter();
    TouristTripUtils utils = TouristTripUtils();
    stringstream buffer;

    switch (selected)
    {
    case 0:
    {
        buffer << printer.getTable(trips, N);
        break;
    }

    case 1:
    {
        cout << u8"Страна: ";
        string country;
        cin >> country;

        size_t newSize = utils.getByCountrySize(country, trips, N);
        TouristTrip* cities = utils.getByCountry(country, trips, N);

        buffer << printer.getShortTable(cities, newSize);

        delete[] cities;
        break;
    }

    case 2:
    {
        TouristTrip* sortedTrips = utils.sortByPrice(trips, N);
        buffer << printer.getTable(sortedTrips, N);
        delete[] sortedTrips;
        break;
    }

    default:
        break;
    }

    return buffer.str();
}