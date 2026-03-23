#pragma once
#ifndef MENU_H
#define MENU_H

/*
 * Menu.h
 * -------
 * Declares console menu helper functions.
 * These are separated from main.cpp to keep the main logic cleaner.
 */

 // Returns a validated integer menu choice (1–4). Loops until valid input.
int readMenuChoice();

#endif // MENU_H
