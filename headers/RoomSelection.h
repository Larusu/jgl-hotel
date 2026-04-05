#pragma once
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct Room {
    string name;
    int price;
};

void displayRoom();
void displayCategory(const string& categoryName, Room rooms[], int size);
void saveOrder(Room orderedRooms[], int orderCount);
void processOrder(Room rooms[], int size, Room orderedRooms[], int& orderCount);

void displayRoom() {
    Room rooms[] = { {"Standard Room", 8000}, {"Premium Room", 12000}, {"Deluxe Room", 20000} };
    Room orderedRooms[10]; 
    int orderCount = 0;    

    char orderChoice;
    do {
        cout << "\n----- Room Booking Selection -----\n[A] Booking\n[B] Finish Booking\n[X] Exit\n";
        cout << "\nChoose an option: ";
        cin >> orderChoice;
        cout << '\n';

        switch (orderChoice) { 
        case 'a':
        case 'A':
            processOrder(rooms, 3, orderedRooms, orderCount);
            break;
        case 'b':
        case 'B':
            saveOrder(orderedRooms, orderCount);
            break;
        case 'x':
        case 'X':
            reservationRecordModule();
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (tolower(orderChoice) != 'x');
}

void processOrder(Room rooms[], int size, Room orderedRooms[], int& orderCount) {
    int choice;
    displayCategory("Available", rooms, size);
    cout << "Select a room by number: ";
    cin >> choice;
    cout << "\nRoom booked successfully.\n\n";


    if (choice < 1 || choice > size) {
        cout << "Invalid choice. Try again.\n";
        return;
    }
    orderedRooms[orderCount] = rooms[choice - 1]; 
    orderCount++;
}

void displayCategory(const string& categoryName, Room rooms[], int size) {
    cout << categoryName << " Rooms:\n";
    for (int i = 0; i < size; i++) {
        cout << i + 1 << ". " << rooms[i].name << " - P" << rooms[i].price << endl;
    }
}

void saveOrder(Room orderedRooms[], int orderCount) {
    ofstream file("data/Customer_Booking.txt");
    if (!file) {
        cout << "Error saving order.\n";
        return;
    }

    file << "Booked Rooms:\n";
    for (int i = 0; i < orderCount; i++) {
        file << "Item: " << orderedRooms[i].name << "\n"
            << "Price: " << orderedRooms[i].price << "\n";
    }

    file.close();
}
