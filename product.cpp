//
// Created by Brandon Baker on 2019-05-22.
//

#include <iostream>
using namespace std;

enum itemType {Audio, Visual, AudioMobile, VisualMobile};

struct products {
    string manufacturer;
    string name;
    itemType itemType;
};
