#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

class EventOrganizer {
private:
    string eventName;
    string firstName, lastName;
    int numGuests, numMinutes;
    
    // Constants for cost calculations
    const double COST_PER_HOUR = 18.50;
    const double COST_PER_MINUTE = 0.40;
    const double COST_OF_DINNER = 20.70;

public:
   
    void getEventDetails() {
        cout << "Enter the name of the event: ";
        cin.ignore(); 
        getline(cin, eventName);
        
        cout << "Enter your first name: ";
        cin >> firstName;
        cout << "Enter your last name: ";
        cin >> lastName;
        
        cout << "Enter the number of guests: ";
        cin >> numGuests;
        cout << "Enter the event duration in minutes: ";
        cin >> numMinutes;
    }

 
    void calculateAndDisplayCost() {
       
        int numServers = ceil(static_cast<double>(numGuests) / 20);
        
      
        double costForOneServer = ((numMinutes / 60) * COST_PER_HOUR) + ((numMinutes % 60) * COST_PER_MINUTE);
        
    
        double totalFoodCost = numGuests * COST_OF_DINNER;
        
        double totalCost = totalFoodCost + (costForOneServer * numServers);
        
        
        double depositAmount = totalCost * 0.25;
        
        
        double avgCostPerPerson = totalFoodCost / numGuests;
        
        
        displayCostSummary(numServers, costForOneServer, totalFoodCost, avgCostPerPerson, totalCost, depositAmount);
    }

    void displayCostSummary(int numServers, double costForOneServer, double totalFoodCost, double avgCost, double totalCost, double deposit) {
        cout << fixed << setprecision(2); 
        cout << "\nEvent Summary:" << endl;
        cout << "Event Name: " << eventName << endl;
        cout << "Organizer: " << firstName << " " << lastName << endl;
        cout << "Number of Guests: " << numGuests << endl;
        cout << "Number of Servers Required: " << numServers << endl;
        cout << "Cost for One Server: $" << costForOneServer << endl;
        cout << "Total Food Cost: $" << totalFoodCost << endl;
        cout << "Average Cost per Person: $" << avgCost << endl;
        cout << "Total Event Cost: $" << totalCost << endl;
        cout << "Deposit Amount (25%): $" << deposit << endl;
    }
};

int main() {
    EventOrganizer event;
    event.getEventDetails();
    event.calculateAndDisplayCost();
    return 0;
}

