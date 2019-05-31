//
// Created by Brandon Baker on 2019-05-22.
//

#ifndef HELLOWORLD_PRODUCEITEMS_H
#define HELLOWORLD_PRODUCEITEMS_H

#include <iostream>

using namespace std;

void addProductionItem();

void writeDefaultProductionItems();

std::vector<std::string> getProductionItemsFromFile();

int productionItemSelection();

int getNumberOfItemsProduced();

void writeItemsToProduction(int productionItemNumber, int numberOfItems);

#endif //HELLOWORLD_PRODUCEITEMS_H
