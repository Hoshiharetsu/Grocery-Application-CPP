#pragma once
#ifndef GROCERY_TRACKER_H
#define GROCERY_TRACKER_H

#include <map>
#include <string>

/*
 * GroceryTracker
 * --------------
 * Loads item names from a text file and counts their frequencies.
 * Provides queries (frequency of a specific item), and prints all counts
 * as either a list or a histogram.
 * Also writes a "backup" frequency file titled "frequency.dat".
 *
 * Design Notes:
 * - Inputs are normalized to lowercase and stripped of all characters
 *   except letters and dashes.
 * - Title casing is applied only to user-facing output (not internal keys).
 */

class GroceryTracker {
public:
    explicit GroceryTracker(std::string in = "CS210_Project_Three_Input_File.txt",
        std::string out = "frequency.dat");

    bool load();
    [[nodiscard]] bool writeBackup() const;
    [[nodiscard]] int countOf(std::string item) const;

    void printAll() const;
    void printHistogram(char symbol = '*') const;

private:
    std::map<std::string, int> freq;  // normalized item -> count
    std::string inputFile;            // source text file
    std::string backupFile;           // output frequency file

    static void normalize(std::string& s);
    static std::string titleCase(const std::string& s);
};

#endif // GROCERY_TRACKER_H
