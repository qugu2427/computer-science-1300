#include "City.h"

City::City()
:name(""),milesToNext(0){}

City::City(std::string name, int milesToNext):name(name), milesToNext(milesToNext){}

std::string City::getName(){
    return name;
}

int City::getMilesToNext(){
    return milesToNext;
}