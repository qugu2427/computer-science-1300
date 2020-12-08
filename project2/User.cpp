#include "User.h"

User::User()
    :username(""),numRatings(0){
    for(int i = 0;i < 50;i++){
        ratings[i] = 0;
    }
}

User::User(std::string username, int ratings[], int numRatings)
    :username(username),numRatings(numRatings){
    for(int i = 0;i < numRatings;i++){
        this->ratings[i] = ratings[i];
    }
}

std::string User::getUsername() const {
    return username;
}

void User::setUsername(std::string username){
    this->username = username;
}

int User::getRatingAt(int i) const {
    if(i < 0 || i >= SIZE){ return -1; }
    return ratings[i];
}

bool User::setRatingAt(int i, int rating){
    if(i < 0 || i >= SIZE || rating < 0 || rating > 5){
        return false;
    }
    ratings[i] = rating;
    return true;
}

int User::getNumRatings() const {
    return numRatings;
}

void User::setNumRatings(int numRatings){
    this->numRatings = numRatings;
}

int User::getSize() const {
    return SIZE;
}
