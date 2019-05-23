//
// Created by Brandon Baker on 2019-05-22.
//


#include "main.h"
#include "musicPlayer.h"

#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;

void addMusicPlayer() {
    string manufacturer = getManufacturer();
    string name = getName();
    int itemType = getItemType();
    printRecordToProduction(manufacturer, itemType);
    showMenu();
}

string getManufacturer() {
    string manufacturer;
    do {
        cout << "Please enter the manufacturer name : " << " ";
        if (!cin) {
            cin.clear();    // Restore input stream to working state
            cin.ignore(100, '\n'); // ignores extra input
        }
        cin >> manufacturer;
    } while (!cin || manufacturer.length() < 3);

    return manufacturer;
}

string getName() {
    string name;
    do {
        cout << "Please enter the product name : " << " ";
        if (!cin) {
            cin.clear();    // Restore input stream to working state
            cin.ignore(100, '\n'); // ignores extra input
        }
        cin >> name;
    } while (!cin);
    return name;
}

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

void printRecordToProduction(string manufacturer, int itemNumber) {
    string record;
    string man = manufacturer.substr(0,2);
    int productionCount = getProductionCount();
    int currentItemIndex = getCountFromItemType(itemNumber);
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
        default : break;
    }
    string recordPrefix = man + itemType;
    ofstream prodFile;
    prodFile.open("production.txt", fstream::app);
    prodFile << "Production Number : " << productionCount << " Serial Number : ";
    prodFile << recordPrefix << setfill('0') << setw(5) << currentItemIndex << endl;
    incrementCountForItemType(itemNumber);
    cout << "Successfully added item to production record" << endl;
    prodFile.close();
    //cout << setfill('0') << setw(5) << 0;
}
