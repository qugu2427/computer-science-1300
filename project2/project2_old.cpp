#include <iostream>
#include <fstream>
#include "Book.h"
#include "User.h"

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

int readBooks(std::string fileName, Book books[], int numBooksStored, int booksArrSize = 50){
    using namespace std;
    if(numBooksStored >= booksArrSize){ return -2; }
    ifstream readFile(fileName);
    if(!readFile.is_open()){ return -1; }
    string line;
    int bookCount = numBooksStored;
    while(getline(readFile, line)){
        if(line.find(',') == std::string::npos){
            continue;
        }
        if(bookCount == booksArrSize){
            readFile.close();
            return bookCount;
        }
        string lineAsArr[3];
        split(line, lineAsArr, ',');
        Book b(lineAsArr[1], lineAsArr[0], lineAsArr[2]);
        books[bookCount] = b;
        bookCount++;
    }
    readFile.close();
    return bookCount;
}

void printAllBooks(Book books[], int numBooks){
    using namespace std;
    if(numBooks <= 0){
        cout << "No books are stored" << endl;
        return;
    }
    cout << "Here is a list of books" << endl;
    for(int i = 0;i < numBooks;i++){
        cout << books[i].getTitle() << " by " << books[i].getAuthor() << endl;
    }
}

int countGenre(std::string genre, Book books[], int numBooks){
    int count = 0;
    for(int i = 0;i < numBooks;i++){
        if(books[i].getGenre() == genre){ count++; }
    }
    return count;
}

// Doesnt match previous
int printAuthorGenre(std::string genre, char authorFirstLetter, Book books[], int numBooks){
    int count = 0;
    std::string outStr = "";
    for(int i = 0;i < numBooks;i++){
        Book book = books[i];
        if(book.getGenre() == genre && book.getAuthor()[0] == authorFirstLetter){
            outStr += book.getTitle()+" by "+book.getAuthor()+"\n";
            count++;
        }
    }
    if(outStr.length() == 0){ outStr = "Here is a list of books that match this genre-author pair:\nNo titles found for this genre-author pair.\n"; }// CHANGED
    else{ outStr = "Here is a list of books that match this genre-author pair:\n" + outStr; }
    std::cout << outStr;
    return count;
}

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

std::string toLower(std::string str){
    std::string lower = "";
    for(int i = 0;i < str.length();i++){
        lower += tolower(str[i]);
    }
    return lower;
}

int getRating(std::string username, std::string title, User users[], Book books[], int numUsersStored, int numBooksStored){
    Book book;
    User user;
    int bookIndex;
    for(int i = 0;i < numBooksStored;i++){
        if( toLower(title) == toLower(books[i].getTitle()) ){
            book = books[i];
            bookIndex = i;
            break;
        }
    }
    for(int i = 0;i < numUsersStored;i++){
        if( toLower(username) == toLower(users[i].getUsername()) ){
            user = users[i];
            break;
        }
    }
    if(book.getTitle() == "" || user.getUsername() == ""){ return -3; }
    return user.getRatingAt(bookIndex);
}

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
    Book books[50];
    int numBooksStored = 0;
    User users[100];
    int numUsersStored = 0;

    bool quit = false;
    while(!quit){
        std::cout << "Select a numerical option:\n======Main Menu=====\n1. Read books from file\n2. Print all books\n3. Book-count by genre\n4. Filter books by genre, author\n5. Add user\n6. Read ratings\n7. Get rating\n8. Get user statistics\n9. Quit" << std::endl;
        std::string optionStr;
        std::getline(std::cin, optionStr);
        char option = '0';
        if(optionStr.length() == 1){ option = optionStr[0]; }
        switch (option){
            case '1':
                {
                    std::string fileName;
                    std::cout << "Enter a book file name:" << std::endl;
                    std::getline(std::cin, fileName);
                    int res = readBooks(fileName, books, numBooksStored, 50);
                    if(res == -2){
                        std::cout << "Database is already full. No books were added." << std::endl;
                    } else if(res == -1) {
                        std::cout << "No books saved to the database." << std::endl;
                    } else if(res == 50) {
                        numBooksStored = 50;
                        std::cout << "Database is full. Some books may have not been added." << std::endl;
                    } else {
                        numBooksStored = res;
                        std::cout << "Total books in the database: " << numBooksStored << std::endl;
                    }
                }
                break;
            case '2':
                printAllBooks(books, numBooksStored);
                break;
            case '3':
                {
                    std::string genre;
                    std::cout << "Enter the genre:" << std::endl;
                    std::getline(std::cin, genre); //here
                    std::cout << "Total "+genre+" books in the database: " << countGenre(genre, books, numBooksStored) << std::endl;
                }
                break;
            case '4':
                {
                    std::string genre;
                    std::string authorLetter;
                    std::cout << "Enter the genre:" << std::endl;
                    std::getline(std::cin, genre); //here
                    std::cout << "Enter first char of author name:" << std::endl;
                    std::getline(std::cin, authorLetter);
                    //std::cout << genre << ":" << authorLetter << std::endl; 
                    int res = printAuthorGenre(genre, authorLetter[0], books, numBooksStored);
                    std::cout << "Number of titles found for this filter: " << res << std::endl;
                }
                break;
            case '5':
                {
                    std::string userName;
                    std::cout << "Enter a user name:" << std::endl;
                    std::getline(std::cin, userName);
                    int res = addUser(userName, users, 0, numUsersStored);
                    if(res == -2){
                        std::cout << "Database is already full. User cannot be added." << std::endl;
                    } else if(res == -1) {
                        std::cout << "User already exists or the username is empty." << std::endl;
                    } else {
                        numUsersStored++;
                        std::cout << "Welcome, "+userName+"!" << std::endl;
                    }
                }
                break;
            case '6':
                {
                    std::string fileName;
                    std::cout << "Enter the ratings file name:" << std::endl;
                    std::getline(std::cin, fileName);
                    int res = readRatings(fileName, users, numUsersStored, 50);
                    if(res == -1){
                        std::cout << "No ratings saved to the database." << std::endl;
                    } else if(res == -2) {
                        std::cout << "Database is already full. No ratings were added." << std::endl;
                    } else if(res == 100) {
                        std::cout << "Database is full. Some ratings may have not been added." << std::endl;
                    } else {
                        numUsersStored = res;
                        std::cout << "Total users in the database: " << numUsersStored << std::endl;
                    }
                }
                break;
            case '7':
                {
                    std::string userName, title;
                    std::cout << "Enter a user name:" << std::endl;
                    std::getline(std::cin, userName);
                    std::cout << "Enter a book title:" << std::endl;
                    std::getline(std::cin, title); //here
                    int res = getRating(userName, title, users, books, numUsersStored, numBooksStored);
                    if(res == -3){
                        std::cout << userName+" or "+title+" does not exist." << std::endl;
                    } else {
                        std::cout << userName+" rated "+title+" with " << res << std::endl;
                    }
                }
                break;
            case '8':
                {
                    std::string userName;
                    std::cout << "Enter a user name:" << std::endl;
                    std::getline(std::cin, userName);
                    getUserStats(userName, users, numUsersStored, numBooksStored);
                }
                break;
            case '9':
                std::cout << "Good bye!" << std::endl;
                quit = true;
                break;
            default:
                std::cout << "Invalid input." << std::endl;
                break;
        }
    }
    return 0;
}