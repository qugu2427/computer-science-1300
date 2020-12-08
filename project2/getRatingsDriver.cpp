#include "User.h"
#include "Book.h"
#include <iostream>

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

int main(){
    //Creating 3 books
    Book books[3];
    //Setting book title and author for book 1
    books[0].setTitle("Title1");
    books[0].setAuthor("Author1");
    //Setting book title and author for book 2
    books[1].setTitle("Title2");
    books[1].setAuthor("Author2");
    //Setting book title and author for book 3
    books[2].setTitle("Title3");
    books[2].setAuthor("Author3");
    //Creating 2 users
    User users[2];
    //Setting username and ratings for User1
    users[0].setUsername("User1");
    users[0].setNumRatings(3);
    users[0].setRatingAt(0,1);
    users[0].setRatingAt(1,4);
    users[0].setRatingAt(2,2);
    //Setting username and ratings for User2
    users[1].setUsername("User2");
    users[1].setNumRatings(3);
    users[1].setRatingAt(0,0);
    users[1].setRatingAt(1,5);
    users[1].setRatingAt(2,3);


    std::cout << getRating("User1", "Title2", users, books, 2, 3) << std::endl;

}