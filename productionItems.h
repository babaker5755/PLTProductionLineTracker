//
// Created by Brandon Baker on 2019-05-29.
//

#ifndef HELLOWORLD_PRODUCTIONITEMS_H
#define HELLOWORLD_PRODUCTIONITEMS_H

#include <iostream>
#include <string>
#include <vector>

std::string getManufacturer();

std::string getName();

int getItemType();

void writeNewItemToFile(std::string manufacturer, std::string name, int itemNumber);

#endif //HELLOWORLD_PRODUCTIONITEMS_H
