//
// Created by Brandon Baker on 2019-05-23.
//

#include "main.h"
#include "musicPlayer.h"
#include "moviePlayer.h"

using namespace std;

/**
 * Asks and gets manufacturer from user input.
 * Asks and gets name from user input.
 * Asks and gets item type from user input.
 * Prints record to production.txt file.
 * */
void addMoviePlayer() {
    string manufacturer = getManufacturer();
    string name = getName();
    int itemType = getItemType();
    printRecordToProduction(manufacturer, itemType);
    showMenu();
}