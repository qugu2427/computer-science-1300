#include <iostream>
#include <fstream>
#include "Book.h"

void split(std::string str, std::string arr[], char delim){
    str += delim;
    int j = 0;
    for(int i = 0;i < str.length();i++){
        if(str[i] == delim){
            j++;
            continue;
        }
        arr[j] += str[i];
    }
}

int readBooks(std::string fileName, Book books[], int numBooksStored, int booksArrSize = 50){
    using namespace std;
    ifstream readFile(fileName);
    if(numBooksStored >= booksArrSize){ return -2; }
    if(!readFile.is_open()){ return -1; }
    string line;
    int bookCount = numBooksStored;
    while(getline(readFile, line)){
        if(line.find(',') == std::string::npos){
            continue;
        }
        if(bookCount == booksArrSize){
            return bookCount;
        }
        string lineAsArr[3];
        split(line, lineAsArr, ',');
        Book b(lineAsArr[1], lineAsArr[0], lineAsArr[2]);
        books[bookCount] = b;
        bookCount++;
    }
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

int main(){
    Book books[10] = {};
    readBooks("books.txt",books, 0, 10);
    for(int i = 0;i < 10;i++){
        std::cout << books[i].getAuthor() << ",";
        std::cout << books[i].getTitle() << ",";
        std::cout << books[i].getGenre() << std::endl;
    }
    printAllBooks(books,10);
}