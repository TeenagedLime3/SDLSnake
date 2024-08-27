//
// Created by Alex on 22/08/2024.
//

#ifndef FOOD_H
#define FOOD_H

class Food {
private:
    int xCoordinate{};
    int yCoordinate{};

public:
    Food(int xCoordinate, int yCoordinate);


    int getXCoordinate();
    int getYCoordinate();

};

#endif //FOOD_H
