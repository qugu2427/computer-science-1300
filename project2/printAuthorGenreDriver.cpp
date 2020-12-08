#include "Book.h"
#include <iostream>

// Prints all books with matching genre and author first ketter. Returns number of matches.
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
    if(outStr.length() == 0){ outStr = "No titles found for this genre-author pair.\n"; }
    else{ outStr = "Here is a list of books that match this genre-author pair:\n" + outStr; }
    std::cout << outStr;
    return count;
}

int main(){
    Book books[50];
    books[0] = Book("Book1", "Bob", "Fiction");
    books[1] = Book("Book2", "Billy", "Fiction");
    books[3] = Book("Book3", "Bill", "Fiction");
    books[4] = Book("Book4", "Jim", "Fiction");
    books[5] = Book("Book5", "Bosna", "History");
    printAuthorGenre("Fiction", 'B', books, 5);
}