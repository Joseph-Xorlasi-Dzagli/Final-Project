#include "Route.h"

using namespace std;

	Route::Route(const string &routeEntry)
	{
        stringstream s(routeEntry);
        string word;
        vector<string> attributes;
        while (getline(s, word, ',')) {
            attributes.push_back(word);
        }
        try {
            Airline = attributes[0];
            AirlineID = (attributes[1].find('N')) ? 0 : stoi(attributes[1]);
            SourceAirport = attributes[2];
            SourceAirportID = (attributes[3].find('N')) ? 0 : stoi(attributes[3]);
            DestinationAirport = attributes[4];
            DestinationAirportID = (attributes[5].find('N') ? 0 : stoi(attributes[5]));
            stops = stoi(attributes[7]);
        }catch(const NumberFormatException& e){
            e.what();
        }
	}

