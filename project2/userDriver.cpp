#include "User.h"
#include <iostream>

int main(){
    User user = User();
    std::cout << user.getUsername() << " " << user.getNumRatings() << std::endl;
}