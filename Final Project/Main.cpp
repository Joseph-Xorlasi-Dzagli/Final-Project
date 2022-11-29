/**
Author1: Joseph Dzagli(joseph.dzagli@ashesi.edu.gh)
Author2: Sean Ofori Addo
Date:    29/11/2022
Course:  Intermediate Computer Programming

This code finds the series of Airports, routes, an Airlines from a given Source Airport to a final destination Airport.
It takes the search request in the form of a txt file and produces an output text file containing the solution
*/

#include <iostream>
#include <iterator>
#include "Airport.cpp"
#include "Airline.cpp"
#include "Route.cpp"
#include <cmath>

#include <cstdio>
using namespace std;

string printResults(vector<string> &route, const string &Scity, const string &Dcity);
vector<string> findroute(string requestfile);


/**
% Function   : ProcessRequest
%
% Description: Accepts the request text file and returns the City and Country of both the Source and destination Airport in a list
%
% Parameters : requestfile              - The file name
%
% Return     : Data = [Source City, Source Country, Destination City, Destination Country]
 */

vector<string> ProcessRequest(const string& requestfile)
{
    fstream request;
    request.open(requestfile);
    vector<string> Data;
    vector<string> temp;


    string line, word;
    while(request.peek()!=EOF){
        getline(request, line);
        stringstream stream(line);
        while (getline(stream, word, ',')) {
            Data.push_back(word);



        }
    }

    return Data; //
}

/**
% Function   : toRadians
%
% Description: Converts a degree to radians
%
% Parameters : degree    - degree as a double value
%
% Return     : radian as a double value
 */
double toRadians(double degree)
{
    double pi = 3.14159265359;
    return (degree * (pi / 180));
}



/**
Function   : Heuristic

Description: Calculates the distance between two Airports

Parameters : SourceAirport    - An airport class of the source Airport
               DestinationAirport    - An airport class of the destination Airport

Return     : the distance between both Airports as a double
 */

double Heuristic(Airport &SourceAirport, Airport &DestinationAirport)
{
    double lat1 = toRadians(SourceAirport.getLatitude());
    double lon1 = toRadians(SourceAirport.getLongitude());
    double lat2 = toRadians(DestinationAirport.getLatitude());
    double lon2 = toRadians(DestinationAirport.getLongitude());

    double earthRadius = 6371.01; //Kilometers

    double distance = earthRadius * acos(sin(lat1) * sin(lat2) + cos(lat1) * cos(lat2) * cos(lon1 - lon2));
    return distance;
}


//The search procedure is implemented here
int main() {
    findroute( "Accra_Winnipeg.txt");
    return 0;
}



/**
Function   : findAirportClass

Description: Finds an tuple within airport.csv with entry matching the given city and country and creates an Airport object

Parameters : City    - City name as a string
             Country    - Country name as a string

Return     : An airport objects of the Airport located in that city and country
 */

Airport findAirportClass(const string &City, const string &Country) {
    string line, word;

    try {
        ifstream airportcsv;
        airportcsv.open("Airports.csv");

        while (airportcsv.peek() != EOF) {
            getline(airportcsv, line);
            stringstream stream(line);
            vector<string> attributes;

            while (getline(stream, word, ',')) {
                attributes.push_back(word);
            }
            if (attributes[2] == City && attributes[3] == Country) {
                break;
            }
        }
    }catch(const exception& fioex){
        fioex.what();
    }
    Airport locus(line);
    return locus;
}


/**
Function   : CheckDestinationAirport

Description: Checks if the given destination airport can be found as a destination in route

Parameters : Destination - Takes  a destination airport as an airport object

Return     : true if the destination Airport exists as a destination in route.csv
 */
bool CheckDestinationAirport(Airport Destination) {
    try{ifstream routescsv;
    routescsv.open("routes.csv");
    string s;
    string line, word;
    while (routescsv.peek() != EOF) {
        getline(routescsv, line);
        stringstream stream(line);
        vector<string> attributes;
        while (getline(stream, word, ',')) {
            attributes.push_back(word);
        }
        if (attributes[4]==Destination.getIATA() || attributes[4]==Destination.getICAO()){return true;}
    }
}catch(const exception& fioex){
    fioex.what();
}
    return false;
}

/**
Function   : findDestinationAirport

Description: Finds an tuple within airport.csv with entry matching the given city and country and creates an Airport object. This method is used only for creating an object for the destination airport

Parameters : Destination - Takes  a destination airport as an airport object

Return     : An airport objects of the Airport located in that city and country
 */
Airport findDestinationAirport(const string &City, const string &Country) {
    string line, word;


    try{ ifstream airportcsv;
    airportcsv.open("Airports.csv");
    while (airportcsv.peek() != EOF){
        vector<string> attributes;
        getline(airportcsv, line);
        stringstream stream(line);
        while (getline(stream, word, ',')) {
            attributes.push_back(word);
        }

        if (attributes[2]==City && attributes[3]==Country) {
            Airport locus(line);
            if(CheckDestinationAirport(locus)){return locus;}
        }
    }
}catch(const exception& fioex){
    fioex.what();
}

}

/**
Function   : findAirportClass

Description: Finds an tuple within airport.csv with entry matching the given Airport name and creates an Airport object

Parameters : AirportName - takes the name of the Airport as a string

Return     : An airport objects of the Airport located in that city and country
 */


Airport findAirportClass(string &AirportName){
    string line, word;

    ifstream airportcsv;
    airportcsv.open("Airports.csv");
try {
    while (airportcsv.peek() != EOF) {
        vector<string> attributes;
        getline(airportcsv, line);
        stringstream stream(line);
        while (getline(stream, word, ',')) {
            attributes.push_back(word);
        }

        if (attributes[1] == AirportName) {
            break;
        }
    }
    }catch(const exception &fioex){
        fioex.what();
    }
    Airport locus(line);

    return locus;
}

/**
Function   : findAirportClass

Description: Finds an tuple within airport.csv with entry matching the given AirportID and creates an Airport object

Parameters : AirportID - takes the AirportID of the Airport as an int value

Return     : An airport objects of the Airport located in that city and country
 */


Airport findAirportClass(int AirportID) {
    string line, word;

    try{ ifstream airportcsv;
    airportcsv.open("Airports.csv");
    while (airportcsv.peek() != EOF) {
        vector<string> attributes;
        getline(airportcsv, line);
        stringstream stream(line);
        while (getline(stream, word, ',')) {
            attributes.push_back(word);
        }

        if (stoi(attributes[0]) == AirportID) {
            Airport locus(line);

            return locus;
        }
    }
}catch(const exception &fioex){
    fioex.what();
}
}

/**
Function   : findAllDestinationAirports

Description: Finds all destination airports from a given airport. It does this by looping through routs.csv and finding all tuples were the given airport matches the source airport entry

Parameters : AirportID - takes the AirportID of the Airport as an Airport object

Return     : An airport vector containing all the destinations you can visit from the given airport
 */
vector<Airport> findAllDestinationAirports(Airport SourceAirport) {
    string line, word;

    try {
        ifstream routescsv;
        routescsv.open("routes.csv");

        vector<Airport> Destinations;
        string s;
        while (routescsv.peek() != EOF) {

            getline(routescsv, line);
            stringstream stream(line);
            vector<string> attributes;
            while (getline(stream, word, ',')) {
                attributes.push_back(word);
            }
//
            try {
                if (attributes[5] != "\N" && attributes[2] == SourceAirport.getIATA() ||
                    attributes[2] == SourceAirport.getICAO()) {

                    Destinations.push_back(findAirportClass(stoi(attributes[5])));
                }

            }
            catch (const NumberFormatException &nFe) {
                nFe.what();
            }
        }
        routescsv.close();
        return Destinations;
    }
    catch(const exception &fioex){
        fioex.what();
    }

    }


/**
Function   : findroute

Description: This code finds the series of Airports, routes, an Airlines from a given Source Airport to a final destination Airport.
It takes the search request in the form of a txt file and produces an output text file containing the solution

Parameters : requestfile - takes the file name of the request file as a string

Return     : solution route of the series of aiports to the destination as a string vector
 */
vector<string> findroute(string requestfile) {

    vector<string> Data = ProcessRequest(requestfile);//# Data - String Array - contains the Source city, source country, destination city, destination country

    vector<string> route;//# Route - String Array - contains the steps of airport from the source airport to the destination airport

    vector<Airport> Explored;//# Explored - list of Airports contains all airports that have airport that have been explored



    Airport SourceAirport = findAirportClass(Data[0], Data[1]);//# SourceAirport - Airport object - Is the Airport object of the source airport

    Airport DestinationAirport = findDestinationAirport(Data[2], Data[3]);//# DestinationAirport - Airport object - Is the Airport object of the destination airport

    Airport min = SourceAirport;//# min - Airport - the airport closest to the destination airport


    route.push_back(min.getAirportName());//# Add sourceAirport to route

    Explored.push_back(min);//# Add sourceAirport to Explored


    while (min.getAirportName() != DestinationAirport.getAirportName()) {
        vector<Airport> Destinations = findAllDestinationAirports(min);

        min = Destinations[0];

        for (auto & element : Destinations) {
////        # if min is the destination airport:
            if (element.getAirportName()==DestinationAirport.getAirportName()) {



                cout << "Found Solution!" << endl;
                route.push_back(element.getAirportName());
                printResults(route, Data[0], Data[2]);
//                cout << "\nThe Solution route is : \n\n";
//                for (auto & item: route){
//                    cout<<item<<endl;
//                }

                return route;

////        # if min is not the destination airport:
                } else if (!min.checkForAirport(Explored) && Heuristic(element, DestinationAirport) < Heuristic(min, DestinationAirport)) {
                min = element;
                route.push_back(min.getAirportName());
            }
            }
        }

    return route;
}

/**
Function   : printResults

Description: Writes the results of the search unto an output file

Parameters : route - takes the solution route as a string vector
             Scity - the start city as a string
             DCity - the destinationn city as a string

Return     : the filename of the output file as a string
 */

string printResults(vector<string> &route, const string &Scity, const string &Dcity)
{
vector<Airport> Airports;
vector<Route> Routes;
string element_o;
int count = 0;

    for (auto & element : route) {

        Airports.push_back(findAirportClass(element));
    ifstream routescsv;
    routescsv.open("routes.csv");
    string s;
    string line, word;
    if (count > 0) {
        while (routescsv.peek() != EOF) {
            vector<string> attributes;
            getline(routescsv, line);
            stringstream s(line);
            while (getline(s, word, ',')) {
                attributes.push_back(word);
            }
//            cout<<attributes[2]<<endl;
            if ((attributes[2]==Airports[count - 1].getIATA()||
                 attributes[2]==Airports[count - 1].getICAO() )&&(
                 attributes[4]==Airports[count].getIATA()||
                  attributes[4]==Airports[count].getICAO())) {
                Routes.emplace_back(line);
            }
        }
    }

    count++;
}

string filename = Scity +"_" + Dcity + "_output.txt";
cout<<filename<<endl;
int totalstops = 0;
//    route[0] +"_" + route[count-1] +?
ofstream outputfile( filename);
//outputfile.open;

cout<<count<<endl;
for ( int c = 0; c+1< count;c++)
{
    cout<<Airports[c].getAirportName()<<endl;
//int c = 1;
    string line = to_string(c+1) + ". " + Routes[c].Airline + " from " + Airports[c].getIATA() + " to " + Airports[c+1].getIATA() + " " + to_string(Routes[c].stops) + " stops\n";
    outputfile << line<< endl;
    totalstops = totalstops + Routes[c].stops;
    if (c == count){
        break;
    }
}

outputfile<<"Total flights: " + to_string(count-1) + "\n";
outputfile<<"Total Additional Stops: " + to_string(totalstops);
outputfile.close();
return filename;
}
