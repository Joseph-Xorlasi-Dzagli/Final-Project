#pragma once

#include <string>
#include <vector>
#include "tangible_exception_helper.h"
#include <memory>
#include <iostream>
#include <exception>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;
	class Route : public std::enable_shared_from_this<Route>
	{

	public:
		string Airline;
		int AirlineID;
		string SourceAirport;
		int SourceAirportID;
		string DestinationAirport;
		int DestinationAirportID;
		char Codeshare = '\0';
		int stops;

		explicit Route(const string &routeEntry);


	};

