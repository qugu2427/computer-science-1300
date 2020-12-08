#include "Book.h"

Book::Book(){
    title = "";
    author = "";
    genre = "";
}

Book::Book(std::string t, std::string a, std::string g){
    title = t;
    author = a;
    genre = g;
}

std::string Book::getTitle(){
    return title;
}

void Book::setTitle(std::string t){
    title = t;
}

std::string Book::getAuthor(){
    return author;
}

void Book::setAuthor(std::string a){
    author = a;
}

std::string Book::getGenre(){
    return genre;
}

void Book::setGenre(std::string g){
    genre = g;
}
