#include "Planet.h"
#include <iostream>

int maxRadius(Planet planets[], int size){
    double maxRadius = 0;
    int maxRadiusIndex = -1;
    for(int i = 0;i < size;i++){
        if(planets[i].getRadius() > maxRadius){
            maxRadius = planets[i].getRadius();
            maxRadiusIndex = i;
        }
    }
    return maxRadiusIndex;
}

int main(){
    Planet planets[3];
    planets[0] = Planet("Planet Squanch",6.8);
    planets[1] = Planet("Delphi 6",8.6);
    planets[2] = Planet("Cronenberg World",8.6);
    int idx = maxRadius(planets, 3);
    std::cout << planets[idx].getName() << std::endl;
    std::cout << planets[idx].getRadius() << std::endl;
    std::cout << planets[idx].getVolume() << std::endl;
}