//
// Created by Alex on 14/08/2024.
//

#include "Snake.h"

#include <iostream>
#include <list>

#include "Food.h"

Snake::Snake(int gridWidth, int gridHeight) {
    this->gridWidth = gridWidth;
    this->gridHeight = gridHeight;
    this->foodList = foodList;
}

Direction Snake::getDirection(){
    return direction;
}
int Snake::getTailXCoordinate(const int snakeIndex) {
    return tailXCoordinate[snakeIndex];
}
int Snake::getTailYCoordinate(const int snakeIndex) {
    return tailYCoordinate[snakeIndex];
}
int Snake::getHeadXCoordinate() {
    return headXCoordinate;
}
int Snake::getHeadYCoordinate() {
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
    } else if (headXCoordinate >= gridWidth){
        headXCoordinate = 0;
    }

    if(headYCoordinate < 0) {
        headYCoordinate = gridHeight - 1;
    } else if (headYCoordinate >= gridHeight ) {
        headYCoordinate = 0;
    }
}

void Snake::eatFoodIfTouching(std::list<Food>& foodList) {
    std::cout << foodList.size() << std::endl;
    foodList.remove_if([this](Food& food) {
        std::cout << "nom" << std::endl;
        return getHeadXCoordinate() == food.getXCoordinate() && getHeadYCoordinate() == food.getYCoordinate();
    });
    // LAMBDA (inline method)
    // for each food (Food& food) in foodList,
    // remove if (remove_if) this is true: (return getHeadXCoordinate() == food.getXCoordinate() && getHeadYCoordinate() == food.getYCoordinate())
}