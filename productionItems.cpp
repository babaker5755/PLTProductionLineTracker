//
// Created by Brandon Baker on 2019-05-29.
//

#include "productionItems.h"
#include <iostream>
#include "main.h"
#include <fstream>
#include <string>
#include <vector>

using namespace std;

/**
 * Builds production item info from user input.
 * Adds new production item to productionItems.txt file
 * Shows main menu when done
 */
void addProductionItem() {

    string manufacturer = getManufacturer();

    string name = getName();

    int itemNumber = getItemType();

    writeNewItemToFile(manufacturer, name, itemNumber);

    showMenu();
}

/**
 * Asks and gets manufacturer from user input.
 * @return Full manufacturer name.
 */
string getManufacturer() {
    string manufacturer;
    do {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Please enter the manufacturer name : " << flush;
        if (!cin) {
            cin.clear();    // Restore input stream to working state
            cin.ignore(100, '\n'); // ignores extra input
        }
        getline(cin, manufacturer);
    } while (!cin || manufacturer.length() < 3);

    return manufacturer;
}

/**
 * Asks and gets product name from user input.
 * @return Full item name.
 */
string getName() {
    string name;
    do {
        cout << "Please enter the product name : " << " ";
        if (!cin) {
            cin.clear();    // Restore input stream to working state
            cin.ignore(100, '\n'); // ignores extra input
        }
        getline(cin, name);
    } while (!cin);
    return name;
}

/**
 * Presents menu for item type and gets itemNumber from user input.
 * @return Number representing item type.
 */
int getItemType() {
    cout << "1. Audio" << endl;
    cout << "2. Visual" << endl;
    cout << "3. Audio Mobile" << endl;
    cout << "4. Visual Mobile" << endl;
    int itemNumber;
    do {
        cout << "Please select the item type from the menu above : " << " ";
        if (!cin) {
            cin.clear();    // Restore input stream to working state
            cin.ignore(100, '\n'); // ignores extra input
        }
        cin >> itemNumber;
    } while (itemNumber < 1 || itemNumber > 4 || !cin);

    return itemNumber;
}

/**
 * Takes item information as parameters, writes the info to the
 * "productionItems.txt "file. Data is seperated by commas.
 * @param manufacturer Manufacturer of the product
 * @param name Name of the product
 * @param itemNumber Number that represents item type, 1-4
 */
void writeNewItemToFile(string manufacturer, string name, int itemNumber) {
    string itemType;
    switch (itemNumber) {
        case 1 :
            itemType = "MM";
            break;
        case 2 :
            itemType = "VI";
            break;
        case 3 :
            itemType = "AM";
            break;
        case 4 :
            itemType = "VM";
            break;
        default :
            break;
    }
    ofstream prodItemsFile;
    prodItemsFile.open("productionItems.txt", fstream::app); // Open to append
    prodItemsFile << manufacturer << "," << name << "," << itemType << endl;
    cout << "Successfully added item to catalog!" << endl;
}

