#include "Player.h"

Player::Player()
:thirst(0), hunger(0), tired(0){}


float Player::getThirst(){
    return thirst;
}

void Player::setThirst(float thirsty){
    this->thirst = thirsty;
    if(this->thirst < 0){
        this->thirst = 0;
    }
}

float Player::getHunger(){
    return hunger;
}

void Player::setHunger(float hungry){
    this->hunger = hungry;
    if(this->hunger < 0){
        this->hunger = 0;
    }
}

float Player::getTired(){
    return tired;
}

void Player::setTired(float tired){
    this->tired = tired;
    if(this->tired < 0){
        this->tired = 0;
    }
}
