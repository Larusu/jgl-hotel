#pragma once
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct Item {
    string name;
    double price;
};
void displayMenu();
void displayCategory(const string& categoryName, Item items[], int size);
void processOrder(Item items[], int size, Item orderedItems[], int quantities[], int& itemCount);
void saveOrder(Item orderedItems[], int quantities[], int itemCount);

void displayMenu() {
    Item meals[] = { {"Seared Salmon", 500.00}, {"Steak", 1100.00}, {"Roasted Chicken", 400.00}, {"Pasta", 750.00}, {"Fillet Mignon", 1200.00} };
    Item drinks[] = { {"Iced Tea", 120.00}, { "Red Wine", 200.00}, {"Soda", 80.00}, {"Beer", 150.00}, {"Pineapple Juice", 120.00 } };
    Item desserts[] = { {"Banana Split", 200.00}, {"Halo-halo", 200.00}, { "Cake", 150.00 }, {"Pie", 150.00}, {"Ice Cream", 120.00} };
    Item sidedish[] = { {"French Fries", 200.00}, {"Coleslaw Salad", 180.00}, {"Mashed Potato", 150.00}, {"Caesar Salad", 180.00}, {"Mozzarella Stick", 200.00} };
    Item bundle[] = { {"Bundle 1", 4500.00 }, {"Bundle 2", 1500.00}, {"Bundle 3", 2000.00}, {"Bundle 4", 600.00}, {"Bundle 5", 1800.00} };

    Item orderedItems[10];
    int quantities[10], itemCount = 0;

    char orderChoice;
    do {
        cout << "\n----- Food Selections Record -----\n[A] Meals Menu\n[B] Drinks Menu\n[C] Desserts Menu\n[D] Side Dish Menu\n[E] Bundles Menu\n[F] Finish Order\n[X] Return\n";
        cout << "\nSelect option: ";
        cin >> orderChoice;
        cout << '\n';

        switch (orderChoice) {
        case 'A':
        case 'a': 
            processOrder(meals, 5, orderedItems, quantities, itemCount); 
            break;
        case 'B':
        case 'b': 
            processOrder(drinks, 5, orderedItems, quantities, itemCount); 
            break;
        case 'C':
        case 'c': 
            processOrder(desserts, 5, orderedItems, quantities, itemCount); 
            break;
        case 'D':
        case 'd': 
            processOrder(sidedish, 5, orderedItems, quantities, itemCount); 
            break;
        case 'E':
        case 'e': 
            processOrder(bundle, 5, orderedItems, quantities, itemCount); 
            break;
        case 'F':
        case 'f': 
            saveOrder(orderedItems, quantities, itemCount); 
            break; 
        case 'x':
        case 'X': 
            reservationRecordModule(); 
            break;
        default: 
            cout << "Invalid choice. Try again.\n";
        }
    } while (orderChoice != 'F');
}

void displayCategory(const string& categoryName, Item items[], int size) {
    cout << categoryName << " Menu:\n";
    for (int i = 0; i < size; i++) {
        cout << i + 1 << ". " << items[i].name << " - P" << items[i].price << endl;
    }
}

void processOrder(Item items[], int size, Item orderedItems[], int quantities[], int& itemCount) {
    if (itemCount >= 10) {
        cout << "Order limit reached. Cannot add more items.\n";
        return;
    }
    int choice, quantity;
    displayCategory("Selected", items, size);
    cout << "Choose an item (1-" << size << "): ";
    cin >> choice;
    if (choice < 1 || choice > size) {
        cout << "Invalid choice. Try again.\n";
        return;
    }
    cout << "Enter quantity: ";
    cin >> quantity;
    if (quantity <= 0) {
        cout << "Invalid quantity. Try again.\n";
        return;
    }
    orderedItems[itemCount] = items[choice - 1];
    quantities[itemCount++] = quantity;
}

void saveOrder(Item orderedItems[], int quantities[], int itemCount) {
    ofstream file("Customer_Orders.txt");
    if (!file) {
        cout << "Error saving order.\n";
        return;
    }

    file << "Ordered food: \n";
    for (int i = 0; i < itemCount; i++) {
        file << "Item: " << orderedItems[i].name << endl
            << "Quantity: " << quantities[i] << endl
            << "Price: " << orderedItems[i].price << endl << endl;
    }
    cout << "Order saved successfully!\n";
    file.close();
}
