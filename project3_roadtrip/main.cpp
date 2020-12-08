#include "Game.h"
#include <fstream>

// CITERIA  1 nested loop, 2 Loops, File IO
int main(){
    while(true){
        system("clear");
        std::ifstream file;
        file.open("rules.txt");
        if(file.is_open()){
            std::string line;
            while( getline(file, line) ){
                std::cout << line << std::endl;
            }
            file.close();
            std::string in;
            std::cout << "\nPress ENTER to play again...";
            std::getline(std::cin, in);
        } else {
            std::cout << "Could not read rules.txt" << std::endl;
        }
        Game game;
        game.start();
    }
}