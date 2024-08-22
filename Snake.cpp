//
// Created by Alex on 14/08/2024.
//

#include "Snake.h"

#include <iostream>

Snake::Snake(int gridWidth, int gridHeight) {
    this->gridWidth = gridWidth;
    this->gridHeight = gridHeight;
}

Direction Snake::getDirection(){
    return direction;
}
int Snake::getTailXLocation(const int snakeIndex) {
    return tailXCoordinate[snakeIndex];
}
int Snake::getTailYLocation(const int snakeIndex) {
    return tailYCoordinate[snakeIndex];
}
int Snake::getHeadXLocation() {
    return headXCoordinate;
}
int Snake::getHeadYLocation() {
    return headYCoordinate;
}
int Snake::getLength(){ //TODO Discuss how const works in this context
    return length;
}

void Snake::moveSnake() {
    int headX = headXCoordinate;
    int headY = headYCoordinate;

    switch (direction) {
        case UP:
            headYCoordinate -= 1;
            break;
        case RIGHT:
            headXCoordinate += 1;
            break;
        case DOWN:
            headYCoordinate += 1;
            break;
        case LEFT:
            headXCoordinate -= 1;
            break;
    }

    wrapAround();

    if(length == 0) {
        return;
    }

    for (int i = length - 1; i > 0; i--) {
        tailXCoordinate[i] = tailXCoordinate[i-1];
        tailYCoordinate[i] = tailYCoordinate[i-1];
    }

    tailXCoordinate[0] = headX;
    tailYCoordinate[0] = headY;
}

void Snake::changeLength() {
    length++;
}
void Snake::changeDirection(const Direction direction) {
    this->direction = direction;
}
void Snake::wrapAround() {
    if(headXCoordinate < 0) {
        headXCoordinate = gridWidth - 1;
    } else if (headXCoordinate > gridWidth){
        headXCoordinate = 0;
    }

    if(headYCoordinate < 0) {
        headYCoordinate = gridHeight - 1;
    } else if (headYCoordinate > gridHeight) {
        headYCoordinate = 0;
    }
}
