#pragma once

#include <string>

class Book{
    private:
        std::string title;
        std::string author;
        std::string genre;
    public:
        Book();
        Book(std::string title, std::string author, std::string genre);
        std::string getTitle();
        void setTitle(std::string title);
        std::string getAuthor();
        void setAuthor(std::string author);
        std::string getGenre();
        void setGenre(std::string genre);
};