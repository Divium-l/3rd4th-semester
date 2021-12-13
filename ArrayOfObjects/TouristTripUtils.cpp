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