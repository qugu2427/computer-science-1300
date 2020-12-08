#pragma once

#include <string>

class City
{
    private:
        std::string name;
        int milesToNext;
    public:
        City();
        City(std::string name, int milesToNext);
        std::string getName();
        int getMilesToNext();
};
