#include "Airline.h"
#include <iostream>
#include <exception>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;


	Airline::Airline(const string &AirlineEntry)
	{
		stringstream s(AirlineEntry);
        string word;
        vector<string> attributes;
        while (getline(s, word, ',')) {
            attributes.push_back(word);
        }
        try
        {
		AirlineID = stoi(attributes[0]);
		Name = attributes[1];
		Alias = attributes[2];
		IATA = attributes[3];
		ICAO = attributes[4];
		Callsign = attributes[5];
		Country = attributes[6];
		Active = attributes[7][0];}
        catch (const NumberFormatException& ex)
        {
            cout << "Exception occurred!" << endl;
        }

	}

	int Airline::getAirlineID()
	{
		return AirlineID;
	}

	void Airline::setAirlineID(int airlineID)
	{
		AirlineID = airlineID;
	}

	string Airline::getName()
	{
		return Name;
	}

	void Airline::setName(const string &name)
	{
		Name = name;
	}

	string Airline::getAlias()
	{
		return Alias;
	}

