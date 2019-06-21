//
// Created by Brandon Baker on 2019-05-30.
//

#include "main.h"
#include "productionItems.h"
#include "displayProductionStatistics.h"

#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <sstream>


/**
 * Will display the statistics menu and when that
 * is finished, it will run the main menu.
 */
void displayProductionStatistics() {

    showStatisticsMenu();

    showMenu();

}


/**
 * Shows Menu and runs 2 functions that will get a valid selection
 * and then run the selection.
 */
void showStatisticsMenu() {
    cout << endl;
    cout << "1. Get Production Count" << endl;
    cout << "2. Get Item Type Count" << endl;
    cout << "3. Display Item Type Percentages" << endl;
    cout << "4. Serial Number Lookup" << endl;
    cout << "5. Exit" << endl;
    int selection = getMenuSelection();
    runStatisticsMenuSelection(selection);
}

/**
 * Takes selection and runs function of the selected option.
 * @param selection User selected option.
 */
void runStatisticsMenuSelection(int selection) {
    switch (selection) {
        case 1 :
            getProductionNumber();
            break;
        case 2 :
            getItemTypeProductionNumber();
            break;
        case 3 :
            displayItemTypePercentages();
            break;
        case 4 :
            serialNumberLookup();
            break;
        case 5 :
            exitSelected();
            break;
        default :
            break;
    }
}

/**
 * Will run getProdutionCount from main.cpp, and
 * display a message with the production count.
 * @return
 */
int getProductionNumber() {
    int prodCount = getProductionCount();
    cout << "You have produced a total of " << prodCount << " items." << endl;
}

/**
 * Will ask user for the item type they'd like a
 * count of, and will then print a message containing
 * that number, and the type of item.
 * the function getItemType is declared in productionItems.cpp
 * the function getCountFromItemType is declared in main.cpp
 */
void getItemTypeProductionNumber() {
    int itemNumber;
    itemNumber = getItemType();
    int itemTypeProductionNumber;
    itemTypeProductionNumber = getCountFromItemType(itemNumber);
    string itemType;
    switch (itemNumber) {
        case 1 :
            itemType = " Audio items";
            break;
        case 2 :
            itemType = " Visual items";
            break;
        case 3 :
            itemType = " Audio Mobile items";
            break;
        case 4 :
            itemType = " Visual Mobile items";
            break;
        default :
            break;
    }
    cout << "You have produced " << itemTypeProductionNumber << itemType << endl;
}

/**
 * Will assign production count for each item type
 * to the corresponding variable. Then it will divide
 * each item type count by the total production count.
 * Then, the program prints each item type percentage
 * and the corresponding item type.
 */
void displayItemTypePercentages() {
    int mm, vi, am, vm, prodCount;
    double mmPercent, viPercent, amPercent, vmPercent;
    prodCount = getProductionCount();
    for (int i = 1; i <= 4; i++) {

        switch (i) {
            case 1:
                mm = getCountFromItemType(i);
                break;
            case 2:
                vi = getCountFromItemType(i);
                break;
            case 3:
                am = getCountFromItemType(i);
                break;
            case 4:
                vm = getCountFromItemType(i);
                break;
            default:
                break;
        }
    }

    mmPercent = getStringPercent(mm, prodCount);
    viPercent = getStringPercent(vi, prodCount);
    amPercent = getStringPercent(am, prodCount);
    vmPercent = getStringPercent(vm, prodCount);

    printf("%.2f Audio \n", mmPercent);
    printf("%.2f Video \n", viPercent);
    printf("%.2f Audio Mobile \n", amPercent);
    printf("%.2f Visual Mobile \n", vmPercent);
}

/** Takes in itemTypeCount and total production count
 * and returns the percent as a double
 * @param itemTypeCount how many of a specific item were produced
 * @param prodCount how many total items were produced
 * @return the percent, as a double
 */
double getStringPercent(int itemTypeCount, int prodCount) {
    if (itemTypeCount == 0 || prodCount == 0) {
        return 0.0;
    }
    double percent = (double) itemTypeCount / (double) prodCount;
    return percent;
}

/**
 * Asks user for serial number, looks for the serial number
 * anywhere in the "ProductionLog.csv" file. If the serial
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
    ifstream productionFile("ProductionLog.csv");
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