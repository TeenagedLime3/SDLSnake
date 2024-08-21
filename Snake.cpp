//
// Created by Alex on 14/08/2024.
//

#include "Snake.h"

#include <iostream>


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

    std::cout << "length: " << length << std::endl;

    for (unsigned int i = length - 1; i > 0; i--) {
        std::cout << i << std::endl;
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
unsigned int Snake::getLength(){ //TODO Discuss how const works in this context
    return length;
}
