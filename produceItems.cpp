//
// Created by Brandon Baker on 2019-05-22.
//


#include "main.h"
#include "produceItems.h"

#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

/**
 * Asks user to select from menu
 * Asks user for number of items produced
 * Prints record to production.txt file.
 * */
void produceItems() {

    int productionItemNumber = productionItemSelection();

    int numberOfItems = getNumberOfItemsProduced();

    writeItemsToProduction(productionItemNumber, numberOfItems);

    showMenu();

}

/**
 * Presents a menu of production items
 * and asks user for a production item number
 * that corresponds to a production item
 * @return the selection as an integer
 */
int productionItemSelection() {
    int productionItemNumber;
    vector<string> productionItems = getProductionItemsFromFile();
    do {

        cout << "Please select a production item number from the menu : " << endl;
        for (int i = 0; i < productionItems.size(); i++) {
            if (i != 0) {
                cout << i << ". " << productionItems[i] << endl;
            }
        }
        if (!cin) {
            cin.clear();    // Restore input stream to working state
            cin.ignore(100, '\n'); // ignores extra input
        }
        cin >> productionItemNumber;
    } while (!cin || productionItemNumber > productionItems.size() - 1 || productionItemNumber < 1);
    return productionItemNumber;

}

/**
 * Asks user for the number of items produced
 * @return the number of items produced
 */
int getNumberOfItemsProduced() {
    int numberOfItems;
    do {
        cout << "How many items did you produce? Enter a number between 0-1000." << endl;
        if (!cin) {
            cin.clear();    // Restore input stream to working state
            cin.ignore(100, '\n'); // ignores extra input
        }
        cin >> numberOfItems;
    } while (!cin || numberOfItems > 1000 || numberOfItems < 0);
    return numberOfItems;

}

/**
 * Takes product info and amount as parameters and writes them
 * to the "production.txt file". Creates a new line and serial number
 * for every item produced
 * @param productionItemNumber number that corresponds to the item selected
 * @param numberOfItems number of items produced
 */
void writeItemsToProduction(int productionItemNumber, int numberOfItems) {
    //Gets production catalog from file
    vector<string> productionItems = getProductionItemsFromFile();
    string productionItem = productionItems[productionItemNumber];

    stringstream prodItem(productionItem);
    vector<string> commaSeparatedProdItem;
    //Fills a vector with 3 items - the selected production item
    while (prodItem.good()) {
        string str;
        getline(prodItem, str, ',');
        commaSeparatedProdItem.push_back(str);
    }
    Product product;
    product.manufacturer = commaSeparatedProdItem[0];
    product.manufacturer = product.manufacturer.substr(0, 3);
    product.itemType = commaSeparatedProdItem[2];

    if (product.itemType == "MM") product.itemNumber = 1;
    if (product.itemType == "AM") product.itemNumber = 2;
    if (product.itemType == "VI") product.itemNumber = 3;
    if (product.itemType == "VM") product.itemNumber = 4;

    int productionCount = getProductionCount();
    int currentItemIndex = getCountFromItemType(product.itemNumber);

    string recordPrefix = product.manufacturer + product.itemType;
    ofstream prodFile;
    prodFile.open("ProductionLog.csv", fstream::app); // Open to append

    for (int i = 0; i < numberOfItems; i++) {
        prodFile << "Production Number : " << productionCount << " Serial Number : ";
        prodFile << recordPrefix << setfill('0') << setw(5) << currentItemIndex << endl; // adds leading zeros if needed
        incrementCountForItemType(product.itemNumber);
        productionCount++;
        currentItemIndex++;
    }
    cout << "Successfully added items to production record" << endl;
    prodFile.close();
}


/**
 * Will overwrite ProductLine.csv file with
 * 4 Basic production items. Used to create the file
 */
void writeDefaultProductionItems() {
    ofstream productionItemsFile;
    productionItemsFile.open("ProductLine.csv");
    productionItemsFile << "__*__" << endl;
    productionItemsFile << "Sony,Boombox,MM" << endl;
    productionItemsFile << "Panasonic,Monitor,VI" << endl;
    productionItemsFile << "Apple,Ipod Mini,AM" << endl;
    productionItemsFile << "Apply,Ipod,VM" << endl;
    productionItemsFile.close();
}

/**
 * Reads "ProductLine.csv" file and
 * returns an array of production items
 * in the form of a string. Manufacturer,name,type
 * @return returns production items as a vector of strings
 */
vector<string> getProductionItemsFromFile() {
    string line;
    vector<string> productionItems;
    ifstream productionItemsFile("ProductLine.csv");
    if (!productionItemsFile.is_open()) {
        writeDefaultProductionItems();
    }
    if (productionItemsFile.is_open()) {
        int i = 0;
        while (getline(productionItemsFile, line)) {
            string firstline = "__*__";
            if (i == 0 && line != firstline) {
                writeDefaultProductionItems();
            }
            productionItems.push_back(line);
            i++;
        }
        productionItems.erase(productionItems.begin());
        sort(productionItems.begin(), productionItems.end());
        productionItemsFile.close();
        return productionItems;
    } else { return productionItems; }
}


