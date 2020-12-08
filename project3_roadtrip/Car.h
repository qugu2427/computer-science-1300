#pragma once

#include <string>

class Car{
    private:
        std::string name;
        float efficiency;
        int tankSize;
    public:
        Car();
        Car(std::string name, float efficiency, int tankSize);
        std::string getName();
        float getEfficiency();
        int getTankSize();
};