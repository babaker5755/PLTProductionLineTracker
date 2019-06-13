//
// Created by Brandon Baker on 2019-05-22.
//

#ifndef HELLOWORLD_PRODUCEITEMS_H
#define HELLOWORLD_PRODUCEITEMS_H

#include <iostream>
#include <string>
#include <vector>

struct Product {
    std::string manufacturer;
    std::string itemType;
    int itemNumber;
};

using namespace std;

void addProductionItem();

void writeDefaultProductionItems();

std::vector<std::string> getProductionItemsFromFile();

int productionItemSelection();

int getNumberOfItemsProduced();

void writeItemsToProduction(int productionItemNumber, int numberOfItems);

#endif //HELLOWORLD_PRODUCEITEMS_H
