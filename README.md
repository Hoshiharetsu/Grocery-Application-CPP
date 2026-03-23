# Grocery Tracking Application (C++)

## Overview
This project is a console-based application designed to process and analyze grocery inventory data. The program reads an unstructured input file containing produce items, organizes the data, and presents it in a structured and user-friendly format.

The application allows users to search for specific items and view frequency data, including a histogram representation of item occurrences.

---

## Features
- Reads and processes data from an external input file
- Counts frequency of grocery items
- Outputs processed data to a `.dat` file
- Displays item frequency in a histogram format
- Allows users to search for specific grocery items
- Provides a menu-driven interface for interaction

---

## Technologies and Concepts
- C++
- File input/output (reading and writing files)
- Object-oriented programming (classes and methods)
- Data processing and transformation
- Control structures and loops
- Console-based user interface

---

## Development Approach
This project was designed using a modular approach, separating responsibilities into different classes and functions. The program reads raw data, processes it into a structured format, and then presents it through a user interface.

Emphasis was placed on organizing logic so that the application can be easily extended or adapted to different datasets.

---

## Challenges and Problem Solving
One of the main challenges was working with file input/output across different development environments (CLion and Visual Studio). Differences in how file paths and project structures are handled required careful troubleshooting.

Another key challenge was designing the logic to:
- Read unstructured data
- Count item occurrences accurately
- Output results in both file and visual (histogram) formats

These challenges were addressed by breaking the problem into smaller steps and validating each stage of data processing.

---

## What I Learned
- How to read and write files in C++
- Techniques for processing and organizing raw data
- How to generate and display frequency-based histograms
- The importance of modular design when handling multi-step logic
- Differences in file handling across development environments

---

## Future Improvements
- Add support for different categories of inventory (e.g., meats, frozen foods)
- Improve user interface beyond console interaction
- Integrate a database for persistent storage and querying
- Enhance search functionality with partial matches or filtering options

---

## How to Run
Compile and run using a C++ compiler:

```bash
g++ main.cpp -o grocery_app
./grocery_app
