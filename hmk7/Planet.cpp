#include "Planet.h"

Planet::Planet(){
    planetName = "";
    planetRadius = 0.0;
}

Planet::Planet(std::string name, double radius){
    planetName = name;
    planetRadius = radius;
}

std::string Planet::getName(){
    return planetName;
}

void Planet::setName(std::string name){
    planetName = name;
}

double Planet::getRadius(){
    return planetRadius;
}

void Planet::setRadius(double radius){
    planetRadius = radius;
}

double Planet::getVolume(){
    return (4.0/3)*(M_PI)*(planetRadius*planetRadius*planetRadius);
}