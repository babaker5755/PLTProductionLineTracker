#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "main.h"

using namespace std;

int mmCount;
int viCount;
int amCount;
int vmCount;
int productionCount;

/**
 * Runs Program, first gets placeholders from placeholder.txt
 * then displays menu.
 * @return 0
 */
int main() {

    getPlaceholdersFromFile();

    cout << "Welcome to PLT" << endl;
    showMenu();

    return 0;
}

/**
 * Shows Menu and runs 2 functions that will get a valid selection
 * and then run the selection.
 */
void showMenu() {
    cout << endl;
    cout << "1. Produce Items" << endl;
    cout << "2. Add Employee Account" << endl;
    cout << "3. Add Production Item" << endl;
    cout << "4. Display Production Statistics" << endl;
    cout << "5. Exit" << endl;
    int selection = getMenuSelection();
    runMenuSelection(selection);
}

/**
 * Will repeat asking for a menu option until user
 * has entered a valid one.
 * @return Valid menu selection.
 */
int getMenuSelection() {
    int response;
    do {
        cout << "Please enter a number from the menu : " << " ";
        if (!cin) {
            cin.clear();    // Restore input stream to working state
            cin.ignore(100, '\n'); // ignores extra input
        }
        cin >> response;
    } while (response < 1 || response > 5 || !cin);

    return response;
}

/**
 * Takes selection and runs function of the selected option.
 * @param selection User selected option.
 */
void runMenuSelection(int selection) {
    switch (selection) {
        case 1 :
            //In "produceItems.cpp"
            produceItems();
            break;
        case 2 :
            //In "employeeAccounts.cpp"
            addEmployeeAccount();
            break;
        case 3 :
            //In "productionItems.cpp"
            addProductionItem();
            break;
        case 4 :
            //In "displayProductionStatistics.cpp"
            displayProductionStatistics();
            break;
        case 5 :
            exitSelected();
            break;
        default :
            break;
    }
}

/**
 * Will overwrite placeholder.txt file with all 1's to reset
 * item counts and production count.
 * Will start the file with __*__
 */
void writeDefaultPlaceholdersToFile() {
    //write default file placeholders
    ofstream placeholderFile;
    placeholderFile.open("placeholder.txt");
    placeholderFile << "__*__" << endl;
    placeholderFile << 1 << endl;
    placeholderFile << 1 << endl;
    placeholderFile << 1 << endl;
    placeholderFile << 1 << endl;
    placeholderFile << 1 << endl;
    placeholderFile.close();
}


/**
 * Checks if placeholder.txt file exists, and will create a new one if it doesn't.
 * Checks if the first line of placeholder.txt file is __*__, will write default values if not.
 * Reads 5 values from placeholder.txt file and assigns them to 5 global variables.
 * The 5 global values are the corresponding item count for each item type and the prod. count.
 */
void getPlaceholdersFromFile() {
    //read from a file
    string line;
    ifstream placeholderFile("placeholder.txt");
    if (!placeholderFile.is_open()) {
        writeDefaultPlaceholdersToFile();
    }
    if (placeholderFile.is_open()) {
        int i = 0;
        while (getline(placeholderFile, line)) {
            string firstline = "__*__";
            if (i == 0 && line != firstline) {
                writeDefaultPlaceholdersToFile();
            }

            int typeCount;
            istringstream iss(line);
            iss >> typeCount;

            switch (i) {
                case 1:
                    ::mmCount = typeCount;
                    break;
                case 2:
                    ::viCount = typeCount;
                    break;
                case 3:
                    ::amCount = typeCount;
                    break;
                case 4:
                    ::vmCount = typeCount;
                    break;
                case 5:
                    ::productionCount = typeCount;
                    break;
                default:
                    break;
            }

            i++;
        }
        placeholderFile.close();
    }
}


/**
 * Takes a number corresponding to item type, and returns the count for that item.
 * @param itemNumber number that corresponds to item type.
 * @return Returns the count for the given item type.
 */
int getCountFromItemType(int itemNumber) {
    int typeCount;
    switch (itemNumber) {
        case 1:
            typeCount = mmCount;
            break;
        case 2:
            typeCount = viCount;
            break;
        case 3:
            typeCount = amCount;
            break;
        case 4:
            typeCount = vmCount;
            break;
        default:
            break;
    }
    return typeCount;
}

/**
 * Takes number corresponding to item type, increments the corresponding global variable.
 * placeholder.txt file is overwritten with new values taken from global variables.
 * @param itemNumber number that corresponds to item type.
 */
void incrementCountForItemType(int itemNumber) {
    //write default file placeholders
    switch (itemNumber) {
        case 1 :
            ++mmCount;
            break;
        case 2 :
            ++viCount;
            break;
        case 3 :
            ++amCount;
            break;
        case 4 :
            ++vmCount;
            break;
    }
    ofstream placeholderFile;
    placeholderFile.open("placeholder.txt");
    placeholderFile << "__*__" << endl;
    placeholderFile << mmCount << endl;
    placeholderFile << viCount << endl;
    placeholderFile << amCount << endl;
    placeholderFile << vmCount << endl;
    placeholderFile << ++productionCount << endl;
    placeholderFile.close();
    getPlaceholdersFromFile();
}

/**
 * Getter for production count.
 * @return Production count.
 */
int getProductionCount() {
    return productionCount;
}


/**
 * Will end program.
 */
void exitSelected() {
    cout << "Have a Nice Day" << endl;
}