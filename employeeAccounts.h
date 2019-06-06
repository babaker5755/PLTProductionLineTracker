//
// Created by Brandon Baker on 2019-06-06.
//

#ifndef HELLOWORLD_EMPLOYEEACCOUNTS_H
#define HELLOWORLD_EMPLOYEEACCOUNTS_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

string getUsername();

string getPassword();

string encryptPassword(string password, string encryptedPassword);

void writeAccountToFile(string username, string password);

bool passwordMeetsRequirements(string password);


#endif //HELLOWORLD_EMPLOYEEACCOUNTS_H
