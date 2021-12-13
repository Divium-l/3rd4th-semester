#include "TouristTripPrinter.hpp"

string TouristTripPrinter::getFooter()
{
	stringstream buffer;

	size_t length = COUNTRY_NAME.length() + CITY_NAME.length() + DAYS_COUNT.length()
		+ HOTEL_TYPE.length() + TRIP_COST.length() + 5;

	for (size_t i = 0; i < length; i++)
		buffer << "-";

	buffer << endl;

	return buffer.str();
}

string TouristTripPrinter::getShortFooter()
{
	stringstream buffer;

	size_t length = CITY_NAME.length() + DAYS_COUNT.length()
		+ HOTEL_TYPE.length() + TRIP_COST.length() + 4;

	for (size_t i = 0; i < length; i++)
		buffer << "-";

	buffer << endl;

	return buffer.str();
}

string TouristTripPrinter::getHeader()
{
	stringstream buffer;

	buffer << "|" << setw(COUNTRY_NAME.length()) << COUNTRY_NAME << "|"
		<< setw(CITY_NAME.length()) << CITY_NAME << "|"
		<< setw(DAYS_COUNT.length()) << DAYS_COUNT << "|"
		<< setw(HOTEL_TYPE.length()) << HOTEL_TYPE << "|"
		<< setw(TRIP_COST.length()) << TRIP_COST << "|" << endl;

	return buffer.str();
}

string TouristTripPrinter::getShortHeader()
{
	stringstream buffer;

	buffer << "|" << setw(CITY_NAME.length()) << CITY_NAME << "|"
		<< setw(DAYS_COUNT.length()) << DAYS_COUNT << "|"
		<< setw(HOTEL_TYPE.length()) << HOTEL_TYPE << "|"
		<< setw(TRIP_COST.length()) << TRIP_COST << "|" << endl;

	return buffer.str();
}

string TouristTripPrinter::getTable(TouristTrip* trips, size_t size)
{
	stringstream buffer;

	buffer << getHeader() << getFooter();

	for (size_t i = 0; i < size; i++)
	{
		buffer << "|" << setw(COUNTRY_NAME.length()) << trips[i].getCountry() << "|"
			<< setw(CITY_NAME.length()) << trips[i].getCity() << "|"
			<< setw(DAYS_COUNT.length()) << trips[i].getDays() << "|"
			<< setw(HOTEL_TYPE.length()) << trips[i].getHotelType() << "|"
			<< setw(TRIP_COST.length()) << trips[i].getCost() << "|" << endl;

		buffer << getFooter();
	}

	return buffer.str();
}

string TouristTripPrinter::getShortTable(TouristTrip* trips, size_t size)
{
	stringstream buffer;

	buffer << getShortHeader() << getShortFooter();

	for (size_t i = 0; i < size; i++)
	{
		buffer << "|" << setw(CITY_NAME.length()) << trips[i].getCity() << "|"
			<< setw(DAYS_COUNT.length()) << trips[i].getDays() << "|"
			<< setw(HOTEL_TYPE.length()) << trips[i].getHotelType() << "|"
			<< setw(TRIP_COST.length()) << trips[i].getCost() << "|" << endl;

		buffer << getShortFooter();
	}

	return buffer.str();
}