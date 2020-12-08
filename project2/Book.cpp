#include "Book.h"

Book::Book(){
    title = "";
    author = "";
    genre = "";
}

Book::Book(std::string title, std::string author, std::string genre){
    this->title = title;
    this->author = author;
    this->genre = genre;
}

std::string Book::getTitle(){
    return title;
}

void Book::setTitle(std::string title){
    this->title = title;
}

std::string Book::getAuthor(){
    return author;
}

void Book::setAuthor(std::string author){
    this->author = author;
}

std::string Book::getGenre(){
    return genre;
}

void Book::setGenre(std::string genre){
    this->genre = genre;
}