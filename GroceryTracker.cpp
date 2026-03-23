#include "GroceryTracker.h"

#include <algorithm>
#include <cctype>
#include <fstream>
#include <iostream>
#include <string>
#include <utility>

using namespace std;

// Constructor
GroceryTracker::GroceryTracker(string in, string out)
    : inputFile(std::move(in)), backupFile(std::move(out)) {
} // leave std:: to avoid ambiguity

// Return frequency count of a given item name
int GroceryTracker::countOf(std::string item) const {
    normalize(item);
    auto it = freq.find(item);
    return (it == freq.end()) ? 0 : it->second;
}

/*
 * load()
 * ------
 * Stream tokens from inputFile, normalize each token, and increment freq map.
 * Error handling: prints a message and returns false if the file can't be opened.
 */
bool GroceryTracker::load() {
    ifstream fin(inputFile);
    if (!fin) {
        cerr << "Error: Could not open input file: " << inputFile << "\n";
        return false;
    }

    string word;
    while (fin >> word) {
        normalize(word);
        if (!word.empty()) {
            ++freq[word];
        }
    }
    return true;
}

/*
 * writeBackup()
 * -------------
 * Write "Name Count" lines to the backup file.
 * Added title-casing so the output is more user-friendly and readable.
 */
bool GroceryTracker::writeBackup() const {
    ofstream fout(backupFile);
    if (!fout) {
        cerr << "Error: Could not create backup file: " << backupFile << "\n";
        return false;
    }
    for (const auto& p : freq) {
        fout << titleCase(p.first) << " " << p.second << "\n";
    }
    return true;
}

/*
 * normalize()
 * ------------
 * Lowercases the string and removes all non-letter/dash characters.
 */
void GroceryTracker::normalize(std::string& s) {
    s.erase(remove_if(s.begin(), s.end(),
        [](unsigned char c) { return !(isalpha(c) || c == '-'); }),
        s.end());

    transform(s.begin(), s.end(), s.begin(),
        [](unsigned char c) { return static_cast<char>(tolower(c)); });
}

/*
 * printAll()
 * ----------
 * Prints each "Name Count" pair to cout.
 */
void GroceryTracker::printAll() const {
    if (freq.empty()) {
        cout << "(no items loaded)\n";
        return;
    }
    for (const auto& p : freq) {
        cout << titleCase(p.first) << " " << p.second << "\n";
    }
}

/*
 * printHistogram()
 * ----------------
 * Prints "Name *****" where the number of symbols equals the count.
 */
void GroceryTracker::printHistogram(char symbol) const {
    if (freq.empty()) {
        cout << "(no items loaded)\n";
        return;
    }
    cout << "\n";
    for (const auto& p : freq) {
        cout << titleCase(p.first) << " ";
        for (int i = 0; i < p.second; ++i) {
            cout << symbol;
        }
        cout << "\n";
    }
}

/*
 * titleCase()
 * -----------
 * Capitalizes the first letter of each dash-separated segment.
 */
string GroceryTracker::titleCase(const string& s) {
    if (s.empty()) return s;

    string t = s;
    bool newWord = true;

    for (auto& ch : t) {
        if (isalpha(static_cast<unsigned char>(ch))) {
            if (newWord) {
                ch = static_cast<char>(toupper(static_cast<unsigned char>(ch)));
                newWord = false;
            }
        }
        else if (ch == '-') {
            newWord = true;
        }
    }
    return t;
}

// End of GroceryTracker.cpp
