#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
using namespace std;

void navigationMenu() {

    char choice;

    do {
        cout << "\n============ JGL Hotel ============\n";
        cout << "\n[A] Customer Record Module\n";
        cout << "[B] Reservation Record Module\n";
        cout << "[C] Billout Module\n";
        cout << "[X] Exit\n";
        cout << "\nChoose an option: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 'A':
        case 'a':
           customerRecordModule();
            break;
        case 'B':
        case 'b':
            reservationRecordModule();
            break;
        case 'C':
        case 'c':
            handlePayment();
            break;
        case 'X':
        case 'x':
            cout << "Exiting the program.\n";
            exit(0);
        default:
            cout << "Invalid option. Please try again.\n";
        }
    } while (choice != 'D' && choice != 'd');
}