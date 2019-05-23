//
// Created by Brandon Baker on 2019-05-23.
//

#include "main.h"
#include "musicPlayer.h"
#include "moviePlayer.h"
using namespace std;

void addMoviePlayer() {
    string manufacturer = getManufacturer();
    string name = getName();
    int itemType = getItemType();
    printRecordToProduction(manufacturer, itemType);
    showMenu();
}