#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int MAX_CAPACITY = 100;
int readParkingStatus(string carNumbers[]) {
    ifstream inFile("parking_status.txt");
    int numCars = 0;
    if (inFile.is_open()) {
        inFile >> numCars;
        for (int i = 0; i < numCars; i++) {
            inFile >> carNumbers[i];
        }
        inFile.close();
    }
    return numCars;
}


void updateParkingStatus(int numCars, string carNumbers[]) {
    ofstream outFile("parking_status.txt");
    if (outFile.is_open()) {
        outFile << numCars << endl;
        for (int i = 0; i < numCars; i++) {
            outFile << carNumbers[i] << endl;
        }
        outFile.close();
    }
}

int main() {
    int numCars;
    string carNumbers[MAX_CAPACITY];
    numCars = readParkingStatus(carNumbers);

    int choice;
    string carNumber;

    while (true) {
        cout << "\nCar Parking System" << endl;
        cout << "==================" << endl;
        cout << "1. Park a Car" << endl;
        cout << "2. Remove a Car" << endl;
        cout << "3. Check Available Parking Spaces" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                if (numCars < MAX_CAPACITY) {
                    cout << "Enter the car number: ";
                    cin >> carNumber;
                    carNumbers[numCars] = carNumber;
                    numCars++;
                    cout << "Car parked successfully!" << endl;
                } else {
                    cout << "Parking is full. Cannot park a car." << endl;
                }
                break;
            case 2:
                if (numCars > 0) {
                    cout << "Enter the car number to remove: ";
                    cin >> carNumber;
                    bool found = false;
                    for (int i = 0; i < numCars; i++) {
                        if (carNumbers[i] == carNumber) {
                            carNumbers[i] = carNumbers[numCars - 1];
                            numCars--;
                            cout << "Car removed successfully!" << endl;
                            found = true;
                            break;
                        }
                    }
                    if (!found) {
                        cout << "Car number not found in the parking." << endl;
                    }
                } else {
                    cout << "No car parked. Cannot remove a car." << endl;
                }
                break;
            case 3:
                cout << "Available parking spaces: " << (MAX_CAPACITY - numCars) << endl;
                break;
            case 4:
                updateParkingStatus(numCars, carNumbers);
                cout << "Exiting Car Parking System. Have a nice day!" << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
