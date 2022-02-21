#pragma once

#include <vector>
#include <iomanip>
#include <string>
#include <sstream>
#include "TouristTrip.hpp"

class TouristTripPrinter
{
private:
	string COUNTRY_NAME = "Country name";
	string CITY_NAME = "City name";
	string DAYS_COUNT = "Number of days";
	string HOTEL_TYPE = "Hotel type";
	string TRIP_COST = "Cost  ";

	string getHeader();
	string getShortHeader();

	string getFooter();
	string getShortFooter();
public:
	string getTable(TouristTrip* trips, size_t size);
	string getShortTable(TouristTrip* trips, size_t size);
};

