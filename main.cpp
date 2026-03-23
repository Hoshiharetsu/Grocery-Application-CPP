/*
 * Program: Grocery Tracker Application
 * Author: Rebecca DuPont
 * Version: 1.0
 * Date: October 2025
 *
 * Program Overview:
 * Uses a provided list of produce items to count and display how many of each are carried.
 *
 * main.cpp Overview:
 * Constructs the core objects.
 * Orchestrates the application workflow and user interaction.
 *
 * Notes:
 * Core logic is implemented in GroceryTracker.cpp.
 * Menu input handling is abstracted into Menu.cpp.
 */

#include "GroceryTracker.h"
#include "Menu.h"

#include <iostream>
#include <string>

using namespace std;

int main() {
    GroceryTracker tracker;  // uses default input + backup file names

    // Load data once at startup; exit on failure
    if (!tracker.load()) {
        cout << "Press Enter to exit...";
        cin.get();
        return 1;
    }

    // Core program loop that responds to user until they choose to exit
    while (true) {
        switch (readMenuChoice()) {
        case 1: {
            cout << "Enter item to look for: " << flush;
            string item;
            getline(cin, item);

            int amount = tracker.countOf(item);
            cout << "Frequency of \"" << item << "\": " << amount << "\n";
            break;
        }
        case 2:
            tracker.printAll();
            break;
        case 3:
            tracker.printHistogram('*');
            break;
        case 4:
            if (!tracker.writeBackup()) { //In case there is an error.
                cerr << "Warning: Could not create frequency.dat file.\n";
            }

            cout << "Thank you for using our app. Good bye!\n";
            return 0;
        }
    }

    return 0; // (safety fallback)
}
