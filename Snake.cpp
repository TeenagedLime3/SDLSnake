//
// Created by Alex on 14/08/2024.
//

#include "Snake.h"


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
            headYCoordinate -= 2 * length;
            break;
        case RIGHT:
            headXCoordinate += 2 * length;
            break;
        case DOWN:
            headYCoordinate += 2 * length;
            break;
        case LEFT:
            headXCoordinate -= 2 * length;
            break;
    }

    tailXCoordinate[0] = headX;
    tailYCoordinate[0] = headY;

    for (unsigned int i = length - 1; i > 1; i--) {
        tailXCoordinate[i] = tailXCoordinate[i--];
        tailYCoordinate[i] = tailYCoordinate[i--];
    }
}
void Snake::changeLength() {
    length += 1;
}
void Snake::changeDirection(const Direction direction) {
    this->direction = direction;
}
unsigned int Snake::getLength(){ //TODO Discuss how const works in this context
    return length;
}
