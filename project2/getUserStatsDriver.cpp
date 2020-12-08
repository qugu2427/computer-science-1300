#include "User.h"
#include <iostream>
#include <iomanip>

int getUserStats(std::string username, User users[], int numUsersStored, int numBooksStored){
    for(int i = 0;i < numUsersStored;i++){
        User user = users[i];
        if(user.getUsername() == username){
            if(user.getNumRatings() == 0){
                std::cout << user.getUsername()+" has not rated any books." << std::endl;
                return 0;
            }
            int sum = 0;
            for(int j = 0;j < numBooksStored;j++){
                sum += user.getRatingAt(j);
            }
            double avg = (double)sum/numBooksStored;
            std::cout << username+" rated " << numBooksStored << " books" << std::endl;
            std::cout.precision(2);
            std::cout << username+"'s average rating was " << std::fixed << avg << std::endl;
            return 1;
        }
    }
    std::cout << username+" does not exist." << std::endl;
    return -3;
}

int main(){
    using namespace std;
    // User not found
    User users[1];

    //Setting username and ratings for User1
    users[0].setUsername("User1");
    users[0].setNumRatings(3);
    users[0].setRatingAt(0,1);
    users[0].setRatingAt(1,4);
    users[0].setRatingAt(2,2);

    cout<<"Function's returned value: "<<getUserStats("Madhu", users, 1, 3)<<endl;
}