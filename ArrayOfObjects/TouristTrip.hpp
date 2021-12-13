#pragma once

#include <string>

using namespace std;

class TouristTrip
{
private:
	string destanationCountry;
	string destanationCity;
	int days;
	string hotelType;
	double cost;

public:
	TouristTrip();
	TouristTrip(string country, string city, int days, string hotelType, double cost);
	TouristTrip(TouristTrip& trip);

	string getCountry();
	string getCity();
	int getDays();
	string getHotelType();
	double getCost();

	void setCountry(string destanationCountry);
	void setCity(string destanationCity);
	void setDays(int days);
	void setHotelType(string hotelType);
	void setCost(double cost);

	friend bool operator<(const TouristTrip& trip1, const TouristTrip& trip2);
	friend bool operator>(const TouristTrip& trip1, const TouristTrip& trip2);
};

