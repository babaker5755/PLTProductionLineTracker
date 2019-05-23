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

int main() {

    getPlaceholdersFromFile();

    cout << "Welcome to PLT" << endl;
    showMenu();

    return 0;
};

void showMenu() {
    cout << endl;
    cout << "1. Add Employee Account" << endl;
    cout << "2. Add Music Player" << endl;
    cout << "3. Add Movie Player" << endl;
    cout << "4. Display Production Statistics" << endl;
    cout << "5. Exit" << endl;
    int response = getMenuSelection();
    runMenuSelection(response);
};

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
};

void runMenuSelection(int response) {
    switch (response) {
        case 1 :
            addEmployeeAccount();
            break;
        case 2 :
            addMusicPlayer();
            break;
        case 3 :
            addMoviePlayer();
            break;
        case 4 :
            displayProductionStatistics();
            break;
        case 5 :
            exitSelected();
            break;
        default :
            break;
    }
};

void writeToFile() {
    //write to a file
    ofstream myFile;
    myFile.open("catalog.txt");
    myFile << "Writing this to a file." << endl;
    myFile.close();
};

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
    };
};

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
void incrementCountForItemType(int itemNumber) {
    //write default file placeholders
    switch (itemNumber) {
        case 1 : ++mmCount;
            break;
        case 2 : ++viCount;
            break;
        case 3 : ++amCount;
            break;
        case 4 : ++vmCount;
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

int getProductionCount() {
    return productionCount;
}



void addEmployeeAccount() {
    cout << "1" << endl;
    showMenu();
};

void addMoviePlayer() {
    cout << "3" << endl;
    showMenu();
};

void displayProductionStatistics() {
    cout << "4" << endl;
    showMenu();
};

void exitSelected() {
    cout << "5" << endl;
    showMenu();
};