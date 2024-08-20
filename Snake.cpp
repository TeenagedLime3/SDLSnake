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


void Snake::moveSnake(int speed) {
    int headX = headXCoordinate;
    int headY = headYCoordinate;

    switch (direction) {
        case UP:
            headYCoordinate -= speed;
            break;
        case RIGHT:
            headXCoordinate += speed;
            break;
        case DOWN:
            headYCoordinate += speed;
            break;
        case LEFT:
            headXCoordinate -= speed;
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
