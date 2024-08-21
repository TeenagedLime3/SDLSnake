//
// Created by Alex on 14/08/2024.
//

#ifndef SNAKE_H
#define SNAKE_H
#define SCREEN_WIDTH  1920
#define SCREEN_HEIGHT  1080


#include "Direction.h"


class Snake {
private:
    unsigned int length; //unsigned cant be below 0
    Direction direction = UP; //starting direction


    //[headXCoordinate, headYCoordinate] [tailXCoordinate[0], tailYCoordinate[0]] ...

    int headXCoordinate = 5;
    int headYCoordinate = 5;

    //an array of the x co-ordinates of the tail of the snake.
    //E.G. the first element in the array is the x co-ordinate of the first part of the tail of the snake.
    int tailXCoordinate[10];

    //an array of the y co-ordinates of the tail of the snake.
    //E.G. the first element in the array is the y co-ordinate of the first part of the tail of the snake.
    int tailYCoordinate[10];


public:
    void changeDirection(Direction direction);
    Direction getDirection();
    int getTailXLocation(int snakeIndex);
    int getTailYLocation(int snakeIndex);
    int getHeadXLocation();
    int getHeadYLocation();

    void changeLength();
    unsigned int getLength();

    void moveSnake();
};

#endif //SNAKE_H
