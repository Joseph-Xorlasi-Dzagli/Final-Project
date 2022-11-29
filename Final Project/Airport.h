#pragma once
#include <string>
#include <vector>
#include "tangible_exception_helper.h"
#include <memory>
using namespace std;



class Airport : public std::enable_shared_from_this<Airport>
	{
	private:
		int airportID = 0;
		string airportName;
		string City;
		string Country;
		string IATA;
		string ICAO;
		float Latitude = 0.0F;
		float Longitude = 0.0F;
		int Altitude = 0;
		float Timezone = 0.0F;
		wchar_t DST = L'\0';
		string DatabaseTimezone;
		string Type;
		string Source;

	public:
		Airport(const string &airportEntry);
        bool checkForAirport(const vector<Airport>& Airportvector);

	//    void print(){
	//        String[] attributes = [airportName, City, getCountry()];
	//        System.out.print(getAirportName());
	//
	//    }

		virtual int getAirportID();

		virtual void setAirportID(int airportID);

		virtual string getAirportName();

		virtual void setAirportName(const string &airportName);

		virtual string getCity();

		virtual void setCity(const string &city);

		virtual string getCountry();

		virtual void setCountry(const string &country);

		virtual string getIATA();

		virtual void setIATA(const string &IATA);

		virtual string getICAO();

		virtual void setICAO(const string &ICAO);

		virtual float getLatitude();

		virtual void setLatitude(float latitude);

		virtual float getLongitude();

		virtual void setLongitude(float longitude);

		virtual int getAltitude();

		virtual void setAltitude(int altitude);

		virtual float getTimezone();

		virtual void setTimezone(float timezone);
	};











	//(int airportID, String airportName, String City, String Country, String IATA, String ICAO, int Latitude, int Longitude, int Altitude, char DST, int Timezone, String DatabaseTimezone, String Type, String Source)

