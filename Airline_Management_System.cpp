#include <iostream>
#include <string>
using namespace std;

class Airlines {
public:
    string Airline_name;
    string Airline_code;
    int Year_founded;
    string Branch_Country;

    Airlines() {
        Airline_name = "Emirates";
        Airline_code = "EK120";
        Year_founded = 1998;
        Branch_Country = "Dubai";
    }

    void display() {
        cout << "Airline name: " << Airline_name << endl;
        cout << "Airline code: " << Airline_code << endl;
        cout << "Year founded: " << Year_founded << endl;
        cout << "Main branch of the Airline: " << Branch_Country << endl << endl;
    }
};

class Arrival {
public:
    int gate;
    int collection;
    string destination;
    float time;

    Arrival(int Arrival_gate = 7, int baggage_collection = 3, string arrival_destination = "Dubai", float arrival_time = 22.15) {
        gate = Arrival_gate;
        collection = baggage_collection;
        destination = arrival_destination;
        time = arrival_time;
    }

    Arrival& operator++() {
        ++gate;
        ++collection;
        time += 0.5;
        return *this;
    }

    Arrival operator+(const Arrival& other) {
        return Arrival(gate + other.gate, collection + other.collection, destination, time);
    }

    void display() {
        cout << "Arrival Details:" << endl;
        cout << "Gate: " << gate << endl;
        cout << "Baggage Collection: " << collection << endl;
        cout << "Destination: " << destination << endl;
        cout << "Time: " << time << endl << endl;
    }
};

class Departure {
public:
    string passengerName;
    string seatNumber;
    string destination;
    float time;

    Departure(string pname = "Rosine Maria", string seat = "7A", string dest = "Dubai", float t = 22.10) {
        passengerName = pname;
        seatNumber = seat;
        destination = dest;
        time = t;
    }

    void display() {
        cout << "Departure Details:" << endl;
        cout << "Passenger Name: " << passengerName << endl;
        cout << "Seat Number: " << seatNumber << endl;
        cout << "Destination: " << destination << endl;
        cout << "Time: " << time << endl << endl;
    }
};

class FlightDetails {
protected:
    string flightNumber;
    string origin;
    string destination;
public:
    void setFlightDetails() {
        cout << "Enter Flight Number: ";
        cin >> flightNumber;
        cout << "Enter Origin: ";
        cin >> origin;
        cout << "Enter Destination: ";
        cin >> destination;
    }
    virtual void displayDetails() {
        cout << "Flight Number: " << flightNumber << endl;
        cout << "Origin: " << origin << endl;
        cout << "Destination: " << destination << endl << endl;
    }
};

class CrewDetails {
protected:
    string pilotName;
    int crewCount;
public:
    void setCrewDetails() {
        cout << "Enter Pilot Name: ";
        cin >> pilotName;
        cout << "Enter Crew Count: ";
        cin >> crewCount;
    }
    virtual void displayDetails() {
        cout << "Pilot Name: " << pilotName << endl;
        cout << "Crew Count: " << crewCount << endl << endl;
    }
};

class AircraftDetails {
protected:
    string aircraftType;
    int capacity;
public:
    void setAircraftDetails() {
        cout << "Enter Aircraft Type: ";
        cin >> aircraftType;
        cout << "Enter Capacity: ";
        cin >> capacity;
    }
    virtual void displayDetails() {
        cout << "Aircraft Type: " << aircraftType << endl;
        cout << "Capacity: " << capacity << endl << endl;
    }
};

class AirlineManagement : public FlightDetails, public CrewDetails, public AircraftDetails {
public:
    void setAllDetails() {
        setFlightDetails();
        setCrewDetails();
        setAircraftDetails();
    }
    void displayDetails() override {
        cout << "--- Airline Management Info ---" << endl;
        FlightDetails::displayDetails();
        CrewDetails::displayDetails();
        AircraftDetails::displayDetails();
    }
};

class Passenger : public FlightDetails {
public:
    string passengerName;
    string seatNumber;
    string ticketClass;

    Passenger(string pname = "Rosine", string seat = "12A", string tclass = "Economy") {
        passengerName = pname;
        seatNumber = seat;
        ticketClass = tclass;
    }

    void setPassengerFlightDetails() {
        setFlightDetails();
    }

    void display() {
        cout << "--- Passenger Info ---" << endl;
        cout << "Passenger Name: " << passengerName << endl;
        cout << "Seat Number: " << seatNumber << endl;
        cout << "Ticket Class: " << ticketClass << endl;
        FlightDetails::displayDetails();
    }
};

int main() {
    Airlines airline;
    Arrival arrival1;
    Departure departure;
    Arrival arrival2(5, 2, "London", 23.45);
    AirlineManagement management;
    Passenger passenger;

    int choice;
    do {
        cout << "\n--- Airline Management Menu ---" << endl;
        cout << "1. Display Airline Details" << endl;
        cout << "2. Display Arrival Details" << endl;
        cout << "3. Display Updated Arrival Details (delay)" << endl;
        cout << "4. Display Combined Arrival Details" << endl;
        cout << "5. Display Departure Details" << endl;
        cout << "6. Set and Display Flight, Crew, Aircraft Details" << endl;
        cout << "7. Set and Display Passenger Details" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                airline.display();
                break;
            case 2:
                arrival1.display();
                break;
            case 3:
                ++arrival1;
                cout << "(Updated Arrival after delay)" << endl;
                arrival1.display();
                break;
            case 4: {
                Arrival sumArrival = arrival1 + arrival2;
                cout << "Final Arrival Info (Sum):" << endl;
                sumArrival.display();
                break;
            }
            case 5:
                departure.display();
                break;
            case 6:
                management.setAllDetails();
                management.displayDetails();
                break;
            case 7:
                passenger.setPassengerFlightDetails();
                passenger.display();
                break;
            case 0:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 0);

    return 0;
}
