#pragma once

#include <string>

class User{
    private:
        std::string username;
        static const int SIZE = 50;
        int ratings[SIZE];
        int numRatings;
    public:
        User();
        User(std::string username, int ratings[], int numRatings);
        std::string getUsername() const;
        void setUsername(std::string username);
        int getRatingAt(int i) const;
        bool setRatingAt(int i, int rating);
        int getNumRatings() const;
        void setNumRatings(int numRatings);
        int getSize() const;
};