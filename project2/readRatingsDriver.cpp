#include "User.h"
#include <fstream>
#include <iostream>

int split(std::string str, std::string arr[], char delim){
    str += delim;
    int j = 0;
    for(int i = 0;i < str.length();i++){
        if(str[i] == delim){
            j++;
            continue;
        }
        arr[j] += str[i];
    }
    return j;
}

// Reads ratings from a file and creates users from each line.
int readRatings(std::string fileName, User users[], int numUsersStored, int usersArrSize = 100, int maxCol = 50){
    if(numUsersStored >= usersArrSize){ return -2; }
    std::ifstream readFile(fileName);
    std::string line;
    if(!readFile.is_open()){ return -1; }
    while(getline(readFile, line)){
        if(line.find(',') == std::string::npos) { continue; }
        std::string segs[51];
        int segCount = split(line, segs, ',');
        std::string username = segs[0];
        int ratings[50];
        for(int i = 1;i <= maxCol && i < segCount;i++){
            ratings[i-1] = stoi( segs[i] );
        }
        users[numUsersStored] = User(username, ratings, 50);
        numUsersStored++;
        if(numUsersStored == usersArrSize){ break; }
    }
    readFile.close();
    return numUsersStored;
}

int main(){
    // check return value after reading the file
    User users[10];

    int numUsers = 0;
    int usersArrSize = 10;
    int maxColumns = 50;

    std::cout<<readRatings("ratings.txt", users, numUsers, usersArrSize, maxColumns)<<std::endl;
}