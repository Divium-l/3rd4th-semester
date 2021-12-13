#pragma once

#include <vector>
#include <array>
#include <string>
#include <sstream>
#include "TouristTrip.hpp"

using namespace std;

class TouristTripUtils
{
private:
	TouristTrip* copy(TouristTrip* trips, size_t size);
public:
	TouristTrip* sortByPrice(TouristTrip* trips, size_t size);
};

