#pragma once
#define _USE_MATH_DEFINES

#include <string>
#include <math.h>

class Planet{
    private:
        std::string planetName;
        double planetRadius;
    public:
        Planet();
        Planet(std::string planetName, double planetRadius);
        std::string getName();
        void setName(std::string name);
        double getRadius();
        void setRadius(double radius);
        double getVolume();
};