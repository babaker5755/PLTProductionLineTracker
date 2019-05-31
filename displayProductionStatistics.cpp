//
// Created by Brandon Baker on 2019-05-30.
//

#include "main.h"
#include "displayProductionStatistics.h"

#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <sstream>


/**
 * For now, this function is only for serial number lookup.
 */
void displayProductionStatistics() {

    serialNumberLookup();

    showMenu();

}

/**
 * Asks user for serial number, looks for the serial number
 * anywhere in the "production.txt" file. If the serial
 * number is found, the function returns the production number
 * by locating it between the 20th index and the first index of
 * the string " Serial Number : "
 */
void serialNumberLookup() {
    string line;
    string foundLine = "";
    string serialNumber;

    cout << "Please Enter a serial number to lookup : ";
    cin >> serialNumber;
    ifstream productionFile("production.txt");
    while (getline(productionFile, line)) {
        if (line.find(serialNumber) != std::string::npos) {
            foundLine = line;
        }
    }
    if (foundLine != "") {
        int endIndex = foundLine.find(" Serial Number : ");
        string productionNumber = foundLine.substr(0, endIndex);
        cout << productionNumber << endl;
    } else {
        cout << "Unable to locate serial number.";
    }

}
