#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include "tangible_exception_helper.h"
#include <memory>
using namespace std;

{
	class Main : public enable_shared_from_this<Main>
	{

	public:
		static string Directory;

		static string Request();

		static vector<string> ProcessRequest(const string &filepath);


		//    Code assistance from https://www.w3resource.com/java-exercises/basic/java-basic-exercise-36.php
		//static double Heuristic(shared_ptr<Airport> SourceAirport, shared_ptr<Airport> DestinationAirport);


		static shared_ptr<Airport> findAirportClass(const string &City, const string &Country);



}
static shared_ptr<Airport> findDAirportClass(const string &City, const string &Country);


static shared_ptr<Airport> findAirportClass(int AirportID);

static shared_ptr<Airport> findAirportClass(const string &AirportName);


static shared_ptr<vector<shared_ptr<Airport>>> findAllDestinationAirports(shared_ptr<Airport> SourceAirportID);

}
public:
shared_ptr<return> Destination;
}
static string printResults(vector<string> &route, const string &Scity, const string &Dcity);


static vector<string> findroute();

min = Destinations->get(i);
Explored->add(min);


}
}
}
j = j + 1;
public:
route[j] = min::getAirportName();
}

shared_ptr<return> route;


}

static void main(vector<string> &args);
}

