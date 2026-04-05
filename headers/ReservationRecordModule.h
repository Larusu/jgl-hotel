#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void viewCustomerOrders();

void reservationRecordModule() {

    char choice;
    cout << "\n---- Reservation Record Module ----\n";
    cout << "[A] Create Food Selections Record\n";
    cout << "[B] Create Room Bookings Record\n";
    cout << "[C] View Orders Record\n";
    cout << "[X] Return\n";
    cout << "\nChoose an option: ";
    cin >> choice;
    cin.ignore();

    switch (choice) {
    case 'A':
    case 'a':
        displayMenu();
        break;
    case 'B':
    case 'b':
        displayRoom();
        break;
    case 'C':
    case 'c':
        viewCustomerOrders();
        break;
    case 'X':
    case 'x':
        navigationMenu();
        break;
    default: 
        cout << "Invalid input. Try again.\n";
    }
}

void viewCustomerOrders() {
    ifstream food("Customer_Orders.txt");
    ifstream room("Customer_Booking.txt");
    if (!food.is_open() || !room.is_open()) {
        cout << "No orders found.\n";
        return;
    }
    string line;

    cout << "\n----- Room Booking -----\n";
    while (getline(room, line)) {
        cout << line << endl;
    }

    cout << "\n----- Menu Order -----\n";
    while (getline(food, line)) {
        cout << line << endl;
    }
}