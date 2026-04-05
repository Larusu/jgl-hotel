#include "CustomerRecordModule.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void createCustomerRecord() {
    string name, contactNo, dateOfReservation, timeOfReservation, noOfGuest;
    char choice;

    do {
        cout << "\n------- Customer Record Form -------\n";
        cout << "Please enter your details.\n";

        cout << "\nName: ";
        getline(cin, name);

        cout << "Contact No: ";
        getline(cin, contactNo);

        cout << "Date of Reservation (mm-dd-yy): ";
        getline(cin, dateOfReservation);

        cout << "Time of Reservation (hh:mm AM/PM): ";
        getline(cin, timeOfReservation);

        cout << "No. of Guest: ";
        getline(cin, noOfGuest);

        ofstream file("Customer_Records.txt", ios::app);

        if (!file.is_open()) {
            cout << "Error opening the file.\n";
            return;
        }

        file << "\n------------ Customer ------------\n";
        file << "Name: " << name << "\n";
        file << "Contact No: " << contactNo << "\n";
        file << "Date of Reservation: " << dateOfReservation << "\n";
        file << "Time of Reservation: " << timeOfReservation << "\n";
        file << "No. of Guest: " << noOfGuest << "\n";
        file << "----------------------------------\n";

        file.close();

        cout << "Your record has been created successfully.\n";

        cout << "Do you want to add another customer record? (y/n): ";
        cin >> choice;
        cin.ignore();

    } while (choice == 'y' || choice == 'Y');
}

void viewCustomerRecords() {
    ifstream file("Customer_Records.txt");

    if (!file.is_open()) {
        cout << "Error opening the file.\n";
        return;
    }

    string line;
    cout << "\n------ Customer Records ------\n";
    while (getline(file, line)) {
        cout << line << endl;
    }

    file.close();
}

void updateCustomerRecord() {
    string nameToSearch, line, newInfo;
    bool found = false;

    cout << "Enter the name of the customer you want to update: ";
    getline(cin, nameToSearch);

    ifstream file("Customer_Records.txt");
    ofstream tempFile("temp.txt");

    if (!file.is_open() || !tempFile.is_open()) {
        cout << "Error opening the file.\n";
        return;
    }

    while (getline(file, line)) {
        if (line.find("Name: " + nameToSearch) != string::npos) {
            found = true;
            cout << "Customer found! Please enter new details.\n";

            cout << "New Name: ";
            getline(cin, newInfo);
            tempFile << "Name: " + newInfo << "\n";

            cout << "New Contact No: ";
            getline(cin, newInfo);
            tempFile << "Contact No: " + newInfo << "\n";

            cout << "New Date of Reservation: ";
            getline(cin, newInfo);
            tempFile << "Date of Reservation: " + newInfo << "\n";

            cout << "New Time of Reservation: ";
            getline(cin, newInfo);
            tempFile << "Time of Reservation: " + newInfo << "\n";

            cout << "New No. of Guests: ";
            getline(cin, newInfo);
            tempFile << "No. of Guest: " + newInfo << "\n";

            tempFile << "----------------------------------\n";

            while (getline(file, line) && line != "----------------------------------") {
            }

        }
        else {
            tempFile << line << "\n"; 
        }
    }

    file.close();
    tempFile.close();

    if (!found) {
        cout << "Customer with the name " << nameToSearch << " was not found.\n";
        remove("temp.txt");  
        return;
    }

    remove("Customer_Records.txt");
    rename("temp.txt", R"(Customer_Records.txt)");

    cout << "Customer record updated successfully.\n";
}

void customerRecordModule() {
    char choice;

    do {
        cout << "\n------ Customer Record Module ------\n";
        cout << "[A] Create Customer Record\n";
        cout << "[B] View Customer Records\n";
        cout << "[C] Update Customer Record\n";
        cout << "[X] Return\n";
        cout << "\nChoose an option: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 'A':
        case 'a':
            createCustomerRecord();
            break;
        case 'B':
        case 'b':
            viewCustomerRecords();
            break;
        case 'C':
        case 'c':
            updateCustomerRecord();
            break;
        case 'X':
        case 'x':
            return;
        default:
            cout << "Invalid option. Please try again.\n";
        }
    } while (choice != 'D' && choice != 'd');
}
