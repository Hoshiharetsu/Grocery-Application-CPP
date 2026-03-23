#include "Menu.h"

#include <iostream>
#include <limits>

using namespace std;

/*
 * readMenuChoice()
 * ----------------
 * Prompts the user for a menu option in the range [1, 4].
 * Re-prompts if the input is invalid or outside range.
 * This function is separated from main.cpp to keep the main logic cleaner
 * and to allow easy expansion if additional menu options are added later.
 */
int readMenuChoice() {
    int choice;
    while (true) {
        cout << "\n---Welcome to Corner Grocer!---\n"
            << "Please select an option from the following:\n"
            << "1. Search for a specific fruit or vegetable.\n"
            << "2. Print all produce frequencies.\n"
            << "3. Print a histogram of all produce.\n"
            << "4. Exit the program.\n"
            << "Choose an option (1-4): " << flush;

        if (cin >> choice && choice >= 1 && choice <= 4) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return choice;
        }

        cout << "Invalid choice. Please enter 1, 2, 3, or 4.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

// End of Menu.cpp
