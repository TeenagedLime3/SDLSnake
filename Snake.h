//
// Created by Alex on 14/08/2024.
//

#ifndef SNAKE_H
#define SNAKE_H


#include <list>
#include <vector>

#include "Direction.h"
#include "Food.h"


class Snake {
private:
    int length{}; //unsigned cant be below 0
    Direction direction = UP; //starting direction

    int gridWidth{};
    int gridHeight{};

    std::list<Food>* foodList = nullptr;
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
    int getTailXCoordinate(int snakeIndex);
    int getTailYCoordinate(int snakeIndex);
    int getHeadXCoordinate();
    int getHeadYCoordinate();
    int getLength();

    void changeLength();
    void wrapAround();
    void moveSnake();
    void eatFoodIfTouching(std::list<Food>& FOOD_LIST);
};

#endif //SNAKE_H
