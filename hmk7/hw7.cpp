#include <iostream>
#include "Book.h"
#include <fstream>

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
    using namespace std;
    Book books[50];
    int filledSlots = 0;
    bool quit = false;
    while(!quit){
        cout <<  "======Main Menu=====\n1. Read books\n2. Print all books\n3. Quit" << endl;
        int option;
        cin >> option;
        switch(option){
            case 1:
                {
                    string fileName;
                    cout << "Enter a book file name:" << endl;
                    cin >> fileName;
                    int totalBooks = readBooks(fileName, books, filledSlots, 50);
                    if(totalBooks == -1){
                        cout << "No books saved to the database." << endl;
                    } else if(totalBooks == -2){
                        cout << "Database is already full. No books were added." << endl;
                        filledSlots = 50;
                    } else if(totalBooks == 50){
                        cout << "Database is full. Some books may have not been added." << endl;
                        filledSlots = 50;
                    } else {
                        cout << "Total books in the database: " << totalBooks << endl;
                        filledSlots = totalBooks;
                    }
                }
                break;
            case 2:
                printAllBooks(books, filledSlots);
                break;
            case 3:
                cout << "Good bye!" << endl;
                quit = true;
                break;
            default:
                cout << "Invalid input." << endl;
                break;
        }
    }
}