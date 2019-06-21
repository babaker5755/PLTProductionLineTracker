//
// Created by Brandon Baker on 2019-05-30.
//

#ifndef HELLOWORLD_DISPLAYPRODUCTIONSTATISTICS_H
#define HELLOWORLD_DISPLAYPRODUCTIONSTATISTICS_H

#include <iostream>
#include <vector>

using namespace std;

void showStatisticsMenu();

void runStatisticsMenuSelection(int selection);

void displayItemTypePercentages();

int getProductionNumber();

double getStringPercent(int itemTypeCount , int prodCount);

void serialNumberLookup();

void getItemTypeProductionNumber();




#endif //HELLOWORLD_DISPLAYPRODUCTIONSTATISTICS_H
