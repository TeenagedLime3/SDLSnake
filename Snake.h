//
// Created by Alex on 14/08/2024.
//

#ifndef SNAKE_H
#define SNAKE_H


#include "Direction.h"


class Snake {
private:
    int length{}; //unsigned cant be below 0
    Direction direction = UP; //starting direction

    int gridWidth{};
    int gridHeight{};


    //[headXCoordinate, headYCoordinate] [tailXCoordinate[0], tailYCoordinate[0]] ...

    int headXCoordinate = 5;
    int headYCoordinate = 5;

    //an array of the x co-ordinates of the tail of the snake.
    //E.G. the first element in the array is the x co-ordinate of the first part of the tail of the snake.
    int tailXCoordinate[10]{};

    //an array of the y co-ordinates of the tail of the snake.
    //E.G. the first element in the array is the y co-ordinate of the first part of the tail of the snake.
    int tailYCoordinate[10]{};


public:
    Snake(int gridWidth, int gridHeight);

    void changeDirection(Direction direction);
    Direction getDirection();
    int getTailXLocation(int snakeIndex);
    int getTailYLocation(int snakeIndex);
    int getHeadXLocation();
    int getHeadYLocation();
    int getLength();

    void changeLength();
    void wrapAround();
    void moveSnake();
};

#endif //SNAKE_H
