#include "TouristTripUtils.hpp"

TouristTrip* TouristTripUtils::copy(TouristTrip* trips, size_t size)
{
    TouristTrip* copyTrips = new TouristTrip[size];

    for (size_t i = 0; i < size; i++)
        copyTrips[i] = trips[i];

    return copyTrips;
}

TouristTrip* TouristTripUtils::sortByPrice(TouristTrip* trips, size_t size)
{
	TouristTrip* sortedTrips = copy(trips, size);

    for (size_t i = 0; i < size - 1; i++) 
        for (size_t j = 0; j < size - i - 1; j++) 
            if (sortedTrips[j] > sortedTrips[j + 1])
            {
                TouristTrip temp = sortedTrips[j];
                sortedTrips[j] = sortedTrips[j + 1];
                sortedTrips[j + 1] = temp;
            }

	return sortedTrips;
}

size_t TouristTripUtils::getByCountrySize(string& country, TouristTrip* trips, size_t size)
{
    size_t newSize = 0;

    for (size_t i = 0; i < size - 1; i++)
        if (trips[i].getCountry()._Equal(country))
            newSize++;

    return newSize;
}

TouristTrip* TouristTripUtils::getByCountry(string& country, TouristTrip* trips, size_t size)
{
    size_t newSize = getByCountrySize(country, trips, size);
    TouristTrip* cities = new TouristTrip[newSize];
    size_t k = 0;

    for (size_t i = 0; i < size - 1; i++)
        if (trips[i].getCountry()._Equal(country)) 
        {
            cities[k] = trips[i];
            k++;
        }
            

    return cities;
}