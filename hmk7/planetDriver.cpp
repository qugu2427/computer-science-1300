#include "Planet.h"
#include <iostream>

using namespace std;

int main(){
    // Default
    Planet p;
    p.setName("p");
    p.setRadius(300);
    cout << p.getRadius() << endl;
    cout << p.getName() << endl;
    cout << p.getVolume() << endl;
    // Param 
    Planet somePlanet("Some Planet", 600000);
    cout << somePlanet.getRadius() << endl;
    cout << somePlanet.getName() << endl;
    cout << somePlanet.getVolume() << endl;
}