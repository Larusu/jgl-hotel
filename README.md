# 🏨 JGL Hotel

**JGL Hotel** is a console-based hotel management system developed as the **final project for Introduction to Programming 1**.

This program allows users to manage customer records, reservations, room bookings, food selections, and billing operations in a structured and organized way.

## 📖 Description

JGL Hotel simulates the basic workflow of a hotel management system.

Users can:
- Register customer details
- Reserve rooms
- Select food orders
- Generate bills
- Store booking information in files

This project demonstrates the use of **basic C++ programming**, **modular design**, and **file handling**.

## Collaborators

- [JhervisArevalo](https://github.com/JhervisArevalo)
- [Larusu](https://github.com/Larusu)
- [watercress](https://github.com/waterrcress)

## ✨ Features

- **Customer Record Module** - Create, view, and update customer information
- **Reservation Record Module** - Manage room bookings and food selections
- **Billing Module** - Process payments and calculate totals
- **File Storage** - Saves customer, booking, and order records into text files.

## 🛠️ Build and Run

### Linux

```bash
make
./hotel
```

Or use the shorthand:
```bash
make run
```

### Windows

Using Command Prompt or PowerShell:
```cmd
make
hotel
```

Or compile using your preferred IDE (Visual Studio, VS Code, etc.).

## 📂 File Structure

```
/
├── main.cpp              # Entry point
├── Makefile              # Build configuration
├── README.md             # This file
├── headers/              # Header files
│   ├── Header.h
│   ├── variable.h
│   ├── NavigationMenu.h
│   ├── CustomerRecordModule.h
│   ├── CustomerRecordModule.cpp
│   ├── BillingOutModule.h
│   ├── ReservationRecordModule.h
│   ├── RoomSelection.h
│   └── FoodSelections.h
└── data/                 # Data files 
    ├── Customer_Records.txt
    ├── Customer_Booking.txt
    └── Customer_Orders.txt
```

## 🧠 Concepts Demonstrated

This project demonstrates:

- Basic C++ programming
- Functions and modular programming
- File input/output
- Menu-driven console interfaces
- Data storage using text files

## 📝 Note

This is our first repository and programming project. It represents our early experience in building structured programs.
