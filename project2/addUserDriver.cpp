#include "User.h"
#include <iostream>

int addUser(std::string userName, User users[], int numRatings, int numUsersStored, int usersArrSize = 100){
    if(numUsersStored >= usersArrSize){ return -2; }
    if(userName.length() == 0){ return -1; }
    for(int i = 0;i < numUsersStored;i++){
        if(users[i].getUsername() == userName){ return -1; }
    }
    int ratings[50] = { 0 };
    users[numUsersStored] = User(userName, ratings, 0);
    return numUsersStored + 1;
}

int main(){
    // Normal use
    User users[2];
    int usersArrSize = 2;
    int numRatings  = 5;

    users[0].setUsername("Ninja");

    // Add 5 ratings given by the user "Ninja"
    for(int i=0; i<numRatings; i++) {
        users[0].setRatingAt(i, i);
    }

    int numUsersStored = 1;

    std::cout<<addUser("Knuth", users, numRatings, numUsersStored, usersArrSize)<<std::endl;
}