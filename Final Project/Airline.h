#pragma once
#include "tangible_exception_helper.h"

#include <string>
#include <vector>
#include <memory>
using namespace std;

	class Airline : public std::enable_shared_from_this<Airline>
	{
	private:
		int AirlineID = 0;
		string Name;
		string Alias;
		string IATA;
		string ICAO;
		string Callsign;
		string Country;
		wchar_t Active = L'\0';


	public:
		Airline(const string &AirlineEntry);

		virtual int getAirlineID();

		virtual void setAirlineID(int airlineID);

		virtual string getName();

		virtual void setName(const string &name);

		virtual string getAlias();
	};


