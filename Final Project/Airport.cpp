#include "Airport.h"
#include <iostream>
#include <exception>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;
Airport::Airport(const string &airportEntry){
    stringstream s(airportEntry);
    string word;
    vector<string> attributes;
    while (getline(s, word, ',')) {
                attributes.push_back(word);
                }
    try
    {
        airportID = stoi(attributes[0]);
        airportName = attributes[1];
        City = attributes[2];
        Country = attributes[3];
        IATA = attributes[4];
        ICAO = attributes[5];
        Latitude = stof(attributes[6]);
        Longitude = stof(attributes[7]);
        Altitude = stoi(attributes[8]);
        DST = attributes[10][0];
    //  Timezone = Float.parseFloat(attributes[9]);
        DatabaseTimezone = attributes[11];
        Type = attributes[12];
        Source = attributes[13];
    }
    catch (const NumberFormatException& ex)
    {
        cout << "Exception occurred!" << endl;
    }

}


int Airport::getAirportID()
{
    return airportID;
}

void Airport::setAirportID(int airportID)
{
    this->airportID = airportID;
}

string Airport::getAirportName()
{
    return airportName;
}

void Airport::setAirportName(const string &airportName)
{
    this->airportName = airportName;
}

string Airport::getCity()
{
    return City;
}

void Airport::setCity(const string &city)
{
    City = city;
}

string Airport::getCountry()
{
    return Country;
}

void Airport::setCountry(const string &country)
{
    Country = country;
}

string Airport::getIATA()
{
    return IATA;
}

void Airport::setIATA(const string &IATA)
{
    this->IATA = IATA;
}

string Airport::getICAO()
{
    return ICAO;
}

void Airport::setICAO(const string &ICAO)
{
    this->ICAO = ICAO;
}

float Airport::getLatitude()
{
    return Latitude;
}

void Airport::setLatitude(float latitude)
{
    Latitude = latitude;
}

float Airport::getLongitude()
{
    return Longitude;
}

void Airport::setLongitude(float longitude)
{
    Longitude = longitude;
}

int Airport::getAltitude()
{
    return Altitude;
}

void Airport::setAltitude(int altitude)
{
    Altitude = altitude;
}

float Airport::getTimezone()
{
    return Timezone;
}

void Airport::setTimezone(float timezone)
{
    Timezone = timezone;
}

bool Airport::checkForAirport(const vector<Airport>& Airportvector) {
    for (auto & element : Airportvector)
        if(element.airportName == airportName){
            return true;
    }
    return false;
}

