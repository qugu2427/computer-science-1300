#include "Book.h"
#include <iostream>

int countGenre(std::string genre, Book books[], int numBooks){
    int count = 0;
    for(int i = 0;i < numBooks;i++){
        if(books[i].getGenre() == genre){ count++; }
    }
    return count;
}

int main(){
    // three books
    Book books[3];

    // putting books in the books array
    books[0].setTitle("Calculus");
    books[0].setAuthor("Gottfried Leibniz");
    books[0].setGenre("Math");

    books[1].setTitle("Algebra");
    books[1].setAuthor("Alan Turing");
    books[1].setGenre("Math");

    books[2].setTitle("Physics");
    books[2].setAuthor("Isaac Newton");
    books[2].setGenre("Science");

    std::cout << countGenre("Math", books, 3) << std::endl;
}