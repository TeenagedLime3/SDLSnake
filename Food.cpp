//
// Created by Alex on 22/08/2024.
//

#include "Food.h"

Food::Food(int xCoordinate, int yCoordinate) {
    this->xCoordinate = xCoordinate;
    this->yCoordinate = yCoordinate;
}

int Food::getYCoordinate() {
    return yCoordinate;
}
int Food::getXCoordinate() {
    return xCoordinate;
}