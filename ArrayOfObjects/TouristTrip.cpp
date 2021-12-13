#include "TouristTrip.hpp"

TouristTrip::TouristTrip()
{
	this->destanationCountry = "unspecified country";
	this->destanationCity = "unspecified city";
	this->days = 0;
	this->hotelType = "unspecified hotel type";
	this->cost = 0;
}

TouristTrip::TouristTrip(string country, string city, int days, string hotelType, double cost)
{
	this->destanationCountry = country;
	this->destanationCity = city;
	this->days = days;
	this->hotelType = hotelType;
	this->cost = cost;
}

TouristTrip::TouristTrip(TouristTrip& trip)
{
	this->destanationCountry = trip.getCountry();
	this->destanationCity = trip.getCity();
	this->days = trip.getDays();
	this->hotelType = trip.getHotelType();
	this->cost = trip.getCost();
}

string TouristTrip::getCountry() { return destanationCountry; }
string TouristTrip::getCity() { return destanationCity; }
int TouristTrip::getDays() { return days; }
string TouristTrip::getHotelType() { return hotelType; }
double TouristTrip::getCost() { return cost; }

void TouristTrip::setCountry(string destanationCountry) { this->destanationCountry = destanationCountry; }
void TouristTrip::setCity(string destanationCity) { this->destanationCity = destanationCity; }
void TouristTrip::setDays(int days) { this->days = days; }
void TouristTrip::setHotelType(string hotelType) { this->hotelType = hotelType; }
void TouristTrip::setCost(double cost) { this->cost = cost; }

bool operator<(const TouristTrip& trip1, const TouristTrip& trip2)
{
	return trip1.cost < trip2.cost;
}

bool operator>(const TouristTrip& trip1, const TouristTrip& trip2)
{
	return trip1.cost > trip2.cost;
}