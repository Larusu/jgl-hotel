#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

void handlePayment() {
	ifstream food("Customer_Orders.txt");
	ifstream room("Customer_Booking.txt");
	if (!food && !room) {
	    cout << "No orders found.\n";
	    return;
	}
	
	double room_total = 0, food_total = 0, final_total = 0;
	string name;
	int quantity = 0;
	double price = 0;
	string line;

	cout << "\nBooked room:\n";
	while (getline(room, line)) {
		if (line.find("Item: ") == 0) {
			name = line.substr(6);
		}
		else if (line.find("Price: ") == 0) {
			price = stod(line.substr(7));
			cout << name << " - P" << price << endl;
			room_total = price;
		}
	}
	cout << "\nOrdered Food:\n";
	while (getline(food, line)) {
		if (line.find("Item: ") == 0) {
			name = line.substr(6);
		}
		else if (line.find("Quantity: ") == 0) {
			quantity = stoi(line.substr(10));
		}
		else if (line.find("Price: ") == 0) {
			price = stod(line.substr(7));
			cout << name << " x" << quantity << " - P" << price * quantity << endl;
			food_total += price * quantity;
		}
	}
	
	final_total = room_total + food_total;
	food.close();
	room.close();
	
	double payment;
	do {
	    cout << "Total: P" << final_total << "\nEnter payment amount: P";
	    cin >> payment;
	
	    if (payment >= final_total) {
	        cout << "Payment successful! Your change is: P" << payment - final_total << endl;
			ofstream deleteroom("Customer_Booking.txt", ios::trunc);
			ofstream deletefood("Customer_Orders.txt", ios::trunc);
			exit(0);
	    }
	    else {
	        cout << "Insufficient payment. Please try again.\n";
	    }
	} while (payment < final_total);
}

