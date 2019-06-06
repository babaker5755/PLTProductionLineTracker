//
// Created by Brandon Baker on 2019-06-06.
//

#include "employeeAccounts.h"
#include <iostream>
#include "main.h"
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

/**
 * Takes user input for first and last name,
 * generates a username based off of the input
 * Gets input for password that meets requirements
 * Encrypts the password
 */
void addEmployeeAccount() {
    string username = getUsername();
    cout << "Your username  is : " << username << endl;
    string encryptedPassword = getPassword();
    writeAccountToFile(username, encryptedPassword);

    showMenu();
}

/**
 * Asks and gets first and last name from user.
 * @return Full item name.
 */

string getUsername() {
    string name;
    do {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Please your first and last name seperated by a space: " << " ";
        if (!cin) {
            cin.clear();    // Restore input stream to working state
            cin.ignore(100, '\n'); // ignores extra input
        }
        getline(cin, name);
    } while (!cin);

    stringstream fullName(name);
    vector<string> separatedNameVector;
    while (fullName.good()) {
        string str;
        getline(fullName, str, ' ');
        separatedNameVector.push_back(str);
    }
    string firstName = separatedNameVector[0];
    char firstInitial = firstName[0];
    string lastName = separatedNameVector[1];
    string username = firstInitial + lastName;

    return username;
}

/**
 * Asks user for password, checks if password meets conditions,
 * and then encrypts it
 * @return Encrypted password
 */
string getPassword() {
    string password;
    do {
        cout << "Please enter a password for your account: " << endl;
        cout << "Password must contain an upper case letter, a lower case letter," << endl;
        cout << "a number, and contain no symbols or spaces." << endl;
        if (!cin) {
            cin.clear();    // Restore input stream to working state
            cin.ignore(100, '\n'); // ignores extra input
        }
        getline(cin, password);
    } while (!cin && passwordMeetsRequirements(password));

    password = encryptPassword(password, "");

    return password;
}

/**
 * Writes username and encrypted password to employee account file
 * @param username username from user input
 * @param password encrypted password
 */
void writeAccountToFile(string username, string password) {
    ofstream employeeFile;
    employeeFile.open("employeeAccounts.txt", fstream::app); // Open to append
    employeeFile << username << "," << password << endl;
    cout << "Successfully added employee account." << endl;
}

/**
 * Recursive function that will return the encrypted password.
 * converts each character to ascii code and adds 100
 * Each char is always a 3 digit number
 * @param password starts as the user input password, is empty string at end of function
 * @param encryptedPassword Starts as an empty string
 * @return
 */
string encryptPassword(string password, string encryptedPassword) {
    if (password == "") {
        return encryptedPassword;
    } else {
        int nextChar = int(password[0]) + 100;
        encryptedPassword = encryptedPassword + to_string(nextChar);
        password.erase(0, 1);
        return encryptPassword(password, encryptedPassword);
    }
}

/**
 * Checks many conditions that password must meet to be used as password
 * @param password User input
 * @return a bool that represents if the password meets all requirements
 */
bool passwordMeetsRequirements(string password) {
    bool hasUpper = false;
    bool hasLower = false;
    bool hasPunct = false;
    bool hasSpace = false;
    bool hasNum = false;
    for (int i = 0; i < password.length(); i++) {
        if (isupper(password[i])) { hasUpper = true; }
        if (islower(password[i])) { hasLower = true; }
        if (ispunct(password[i])) { hasPunct = true; }
        if (isspace(password[i])) { hasSpace = true; }
        if (isdigit(password[i])) { hasNum = true; }
    }
    if (hasNum && hasUpper && hasLower && !hasPunct && !hasSpace && password.length() > 0) {
        return true;
    } else {
        return false;
    }
}
