#pragma once

#include <vector>
#include <iomanip>
#include <string>
#include <sstream>
#include "TouristTrip.hpp"

class TouristTripPrinter
{
private:
	string COUNTRY_NAME = "Название страны";
	string CITY_NAME = "Название города";
	string DAYS_COUNT = "Количество дней";
	string HOTEL_TYPE = "Тип отеля";
	string TRIP_COST = "Стоимость поездки";

	string getHeader();
	string getShortHeader();

	string getFooter();
	string getShortFooter();
public:
	string getTable(TouristTrip* trips, size_t size);
	string getShortTable(TouristTrip* trips, size_t size);
};

