#pragma once

#include "Date.h"
#include "Car.h"
#include "City.h"
#include "Player.h"

#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <chrono>
#include <thread>
#include <cstdlib>

// CRITERIA: 4+ data members, array of objects
class Game
{
    private:
        City cities[14];
        Date date;
        Car car;
        Player player;
        int city;
        float fuel;
        float money;
        bool gameOver;

        void pause();
        void clear();
        void setColor(int);
        void unsetColor();
        void selectCar();
        void map();
        void printHeading();
        void restraunt(float);
        void gasStation(float);
        void hotel(float);
        void flatTire();
        void travel();
        void printStats();
        void win();
        void die(std::string msg);
    public:
        Game();
        void start();
};
