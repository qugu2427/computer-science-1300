#include "Car.h"

Car::Car()
:name(""), efficiency(0), tankSize(0){}

Car::Car(std::string name, float efficiency, int tankSize)
:name(name), efficiency(efficiency), tankSize(tankSize){}

std::string Car::getName(){
    return name;
}

float Car::getEfficiency(){
    return efficiency;
}

int Car::getTankSize(){
    return tankSize;
}