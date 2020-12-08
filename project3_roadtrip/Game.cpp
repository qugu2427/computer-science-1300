#include "Game.h"

// PRIVATE

// Pauses until enter is pressed
void Game::pause(){
    std::string in;
    std::cout << "\nPress ENTER to continue...";
    std::getline(std::cin, in);
}

// Wrapper to clear console until enter is pressed
void Game::clear(){
    system("clear");
}

// Sets ANSI color
void Game::setColor(int color){
    std::cout << "\x1B[" << color << "m";
}

// Sets ANSI color to default
void Game::unsetColor(){
    std::cout << "\033[0m";
}

// CRITERIA: 1 if chain
// Prompts user to select car
void Game::selectCar(){
    std::cout << "Choose a car:" << std::endl;
    std::cout << "1. Pickup Truck" << std::endl;
    std::cout << "2. Sports Car" << std::endl;
    std::cout << "3. Beater" << std::endl;
    std::cout << "4. Eco Car" << std::endl;
    std::string option;
    std::getline(std::cin, option);
    if(option == "1"){
        car = Car("Pickup Truck", 0.25, 10);
        fuel = ((float)car.getTankSize())/2;
    } else if(option == "2"){
        car = Car("Sports Car", 0.1, 8);
        fuel = ((float)car.getTankSize())/2;
    } else if(option == "3"){
        car = Car("Beater", 0.1, 8);
        fuel = ((float)car.getTankSize())/2;
    } else if(option == "4"){
        car = Car("Eco Car", 0.05, 5);
        fuel = ((float)car.getTankSize())/2;
    } else {
        std::cout << "Invalid option" << std::endl;
        pause();
        clear();
        selectCar();
    }
    clear();
}

// CRITERIA: 1 loop, 2 if statements
// Displays maps
void Game::map(){
    clear();
    std::cout << "START" << std::endl;
    for(int i = 0;i < 14;i++){
        std::cout << "-" << cities[i].getName();
        if(i == city){
            setColor(96);
            std::cout << "<-- You are here.";
            unsetColor();
        }
        std::cout << std::endl;
        if(i != 13){
            std::cout << "| " << cities[i].getMilesToNext() << " miles" << std::endl;
        }
    }
    std::cout << "FINISH" << std::endl;
    pause();
    clear();
}

// Prints game heading
void Game::printHeading(){
    std::cout << date.getMonth() << " " << date.getDay() << " " << date.getYear() << "\t" << cities[city].getName() << "\t" << car.getName() << std::endl;
    std::cout << "$" << money;
    setColor( (fuel > car.getTankSize() * 0.7) ? 32 : (fuel < car.getTankSize() * 0.25) ? 31 : 33 );
    std::cout << "\tFuel " << fuel << "/" << car.getTankSize();
    setColor( (player.getHunger() < 30) ? 32 : (player.getHunger() > 75) ? 31 : 33 );
    std::cout << "\t" << player.getHunger() << "\% hungry\t";
    setColor( (player.getThirst() < 30) ? 32 : (player.getThirst() > 75) ? 31 : 33 );
    std::cout << player.getThirst() << "\% thirsty\t";
    setColor( (player.getTired() < 30) ? 32 : (player.getTired() > 75) ? 31 : 33 );
    std::cout << player.getTired() << "\% tired" << std::endl;
    unsetColor();
}

// CRITERIA: 1 if chain, 5 if/else statements
// Prompts and displays restraunt
void Game::restraunt(float priceMultiplier){
    clear();
    float drinkPrice = 1.00 * priceMultiplier;
    float snackPrice = 2.00 * priceMultiplier;
    float meal1Price = 5.00 * priceMultiplier;
    float meal2Price = 10.00 * priceMultiplier;
    float meal3Price = 15.00 * priceMultiplier;
    printHeading();
    std::cout << "1. Drink (-25\% thirst)\t$" << drinkPrice << std::endl;
    std::cout << "2. Snack (-10\% hunger)\t$" << snackPrice << std::endl;
    std::cout << "3. One Course Meal (-50\% hunger, -75\% thirst)\t$" << meal1Price << std::endl;
    std::cout << "4. Two Course Meal (-75\% hunger, -100\% thirst)\t$" << meal2Price << std::endl;
    std::cout << "5. Three Course Meal (-100\% hunger, -100\% thirst)\t$" << meal3Price << std::endl;
    std::cout << "6. Exit" << std::endl;
    std::string option;
    std::getline(std::cin, option);
    if(option == "1"){
        if(money < drinkPrice){
            std::cout << "Not enough money" << std::endl;
            pause();
        } else {
            money -= drinkPrice;
            player.setThirst(player.getThirst() - 25);
        }
        restraunt(priceMultiplier);
    } else if(option == "2"){
        if(money < snackPrice){
            std::cout << "Not enough money" << std::endl;
            pause();
        } else {
            money -= snackPrice;
            player.setHunger(player.getHunger() - 10);
        }
        restraunt(priceMultiplier);
    } else if(option == "3"){
        if(money < meal1Price){
            std::cout << "Not enough money" << std::endl;
            pause();
        } else {
            money -= meal1Price;
            player.setThirst(player.getThirst() - 75);
            player.setHunger(player.getHunger() - 50);
        }
        restraunt(priceMultiplier);
    } else if(option == "4"){
        if(money < meal2Price){
            std::cout << "Not enough money" << std::endl;
            pause();
        } else {
            money -= meal2Price;
            player.setThirst(player.getThirst() - 100);
            player.setHunger(player.getHunger() - 75);
        }
        restraunt(priceMultiplier);
    } else if(option == "5"){
        if(money < meal3Price){
            std::cout << "Not enough money" << std::endl;
            pause();
        } else {
            money -= meal3Price;
            player.setThirst(player.getThirst() - 100);
            player.setHunger(player.getHunger() - 100);
        }
        restraunt(priceMultiplier);
    } else if(option == "6"){
        clear();
    } else {
        std::cout << "Invalid option." << std::endl;
        pause();
        restraunt(priceMultiplier);
    }
}

// CRITERIA: 1 if chain
// Prompts and displays gasStation
void Game::gasStation(float priceMultiplier){
    float fuelPrice = 3.25 * priceMultiplier;
    clear();
    printHeading();
    std::cout << "How many gallons of fuel would you like to buy?\t$" << fuelPrice << "/gallon" << std::endl;
    std::string gallonsInput;
    std::getline(std::cin, gallonsInput);
    float gallons;
    try{
        gallons = stof(gallonsInput);
        if(fuel == car.getTankSize()){
            std::cout << "Fuel tank is full." << std::endl;
            pause();
            clear();
        } else if(gallons < 0 || (int)((gallons > car.getTankSize() - fuel) + 0.01) ){
            std::cout << "Number must be between 0 and " << car.getTankSize() - fuel << "." << std::endl;
            pause();
            clear();
        } else if(gallons * fuelPrice > money) {
            std::cout << "Not enough money." << std::endl;
            pause();
            clear();
        } else {
            fuel += gallons;
            money -= fuelPrice * gallons;
            clear();
        }
    } catch(...) {
        std::cout << "Invalid input." << std::endl;
        pause();
        gasStation(priceMultiplier);
    }
}

// CRITERIA: 1 if/else
// Prompts and displays hotel
void Game::hotel(float priceMultiplier){
    float nightPrice = 25 * priceMultiplier;
    std::cout << "How many days would you like to rest at the hotel?\t$" << nightPrice << "/night" << std::endl;
    std::string daysInput;
    std::getline(std::cin, daysInput);
    int days;
    try{
        days = stoi(daysInput);
        if(days <= 0 || days > 10){
                std::cout << "Number must be between 1 and 10." << std::endl;
                pause();
                clear();
                return;
        } else {
            if(nightPrice * days > money){
                std::cout << "Not enough money." << std::endl;
                pause();
                clear();
                return;
            } else {
                money -= nightPrice * days;
            }
        }
    } catch(...) {
        std::cout << "Invalid input." << std::endl;
        pause();
        clear();
        return;
    }

    clear();
    unsigned char count = 0;
    while(count < days){
        printHeading();
        std::cout << "[";
        for(unsigned char i = 0;i < days;i++){
            if(i < count){
                std::cout << "zZzZ";
            } else {
                std::cout << "    ";
            }
        }
        std::cout << "]" << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(2000));
        player.setTired(player.getTired() - 10);
        count++;
        date.addDays(1);
        clear();
    }
    clear();
}

// CRITERIA: 1 if chain, 1 if/else
// Handles fat tire misfortune
void Game::flatTire(){
    clear();
    std::cout << "You got a flat tire." << std::endl;
    std::cout << "1. Call towtruck." << std::endl;
    std::cout << "2. Fix yourself." << std::endl;
    std::cout << "Enter an option: ";
    std::string option;
    std::getline(std::cin, option);
    if(option == "1"){
        if(money < 50){
            std::cout << "Not enough money." << std::endl;
            pause();
            flatTire();
        } else {
            money -= 50;
            std::cout << "A tow truck was called and your car was repaired." << std::endl;
            setColor(31);
            std::cout << "-$50" << std::endl;
            unsetColor();
        }
    } else if(option == "2"){
        player.setTired( player.getTired() + 30 );
        std::cout << "You fixed your tire." << std::endl;
        setColor(31);
        std::cout << "+30\% tired" << std::endl;
        unsetColor();
    } else {
        std::cout << "Invalid option." << std::endl;
        pause();
        flatTire();
    }
    pause();
    clear();
}

// CRITERIA: 2 loops, 1 nested loop, 1 if chain
// Handles traveling
void Game::travel(){
    // Calculate load duration
    int loadCount = cities[city].getMilesToNext()/50;
    float milesPerBar = cities[city].getMilesToNext()/loadCount;
    float totalMiles = 0;

    for(int i = 0;i < loadCount;i++){
        // Chance of misfortune
        std::srand(std::time(0));
        int n = rand()%30;
        if(n == 1){
            flatTire();
        } else if(n == 2){
            clear();
            std::cout << "You found some lucky cash underneath your seat!" << std::endl;
            setColor(32);
            money += 50;
            std::cout << "+$50" << std::endl;
            unsetColor();
            pause();
        } else if(n == 3){
            clear();
            std::cout << "Your car has a leak." << std::endl;
            setColor(31);
            fuel -= 1;
            std::cout << "-1 Fuel" << std::endl;
            unsetColor();
            pause();
        } else if(n == 3){
            clear();
            std::cout << "Your cars air conditioning broke." << std::endl;
            setColor(31);
            player.setThirst( player.getThirst() + 5 );
            std::cout << "+5\% Thirst" << std::endl;
            unsetColor();
            pause();
        }

        // Check if dead
        if(player.getThirst() > 100){
            die("You dehydrated to death.");
            return;
        } else if(player.getHunger() > 100){
            die("You starved to death.");
            return;
        } else if(player.getTired() > 100){
            die("You passed out and crashed.");
            return;
        } else if(fuel <= 0){
            die("You ran out of fuel.");
            return;
        }

        clear();
        printHeading();
        std::cout << cities[city].getName() << " ";
        for(int j = 0;j < loadCount;j++){
            if(j < i){
                std::cout << "\u25A0\u25A0\u25A0";
            } else {
                std::cout << "   ";
            }
        }
        std::cout << " " << cities[city+1].getName();
        std::cout << std::fixed << std::setprecision(0);
        std::cout << " " << totalMiles << "/" << cities[city].getMilesToNext() << " miles" << std::endl;
        std::cout << std::fixed << std::setprecision(1);
        totalMiles += milesPerBar;
        player.setThirst(player.getThirst() + 5);
        player.setHunger(player.getHunger() + 2);
        player.setTired(player.getTired() + 2);
        date.addDays(1);
        fuel -= car.getEfficiency();
        std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    }
    city++;
    if(city == 13){
        win();
        return;
    }
    clear();
}

// Prints stats at end of game
void Game::printStats(){
    std::cout << "Ended in " << cities[city].getName() << std::endl;
    std::cout << "$" << money  << std::endl;
    std::cout << "Fuel " << fuel << "/" << car.getTankSize() << "\t" << car.getName() << std::endl;
    std::cout << "Thirst " << player.getThirst() << "%" << std::endl;
    std::cout << "Hunger " << player.getHunger() << "%" << std::endl;
    std::cout << "Hunger " << player.getTired() << "%" << std::endl;
}

// Displays death
void Game::die(std::string msg){
    if(fuel <= 0){
        fuel = 0;
    }
    clear();
    setColor(30);
    setColor(101);
    std::cout << "  Game Over  " << std::endl;
    unsetColor();
    std::cout << msg << std::endl;
    printStats();
    pause();
    gameOver = true;
}

// Displays win
void Game::win(){
    clear();
    setColor(30);
    setColor(102);
    std::cout << "  You Win  " << std::endl;
    unsetColor();
    std::cout << "Congratulations!" << std::endl;
    printStats();
    pause();
    gameOver = true;
}

// PUBLIC

Game::Game()
:city(0), fuel(0), money(350), gameOver(false)
{
    cities[0] = City("Albany NY", 293);
    cities[1] = City("Herrisburg PA", 368);
    cities[2] = City("Columbus OH", 379);
    cities[3] = City("Nashville TN", 281);
    cities[4] = City("Montgomery AL", 248);
    cities[5] = City("Jackson MS", 263);
    cities[6] = City("Little Rock AR", 340);
    cities[7] = City("Oklahoma City OK", 388);
    cities[8] = City("Austin TX", 688);
    cities[9] = City("Santa Fe NM", 392);
    cities[10] = City("Denver CO", 521);
    cities[11] = City("Salt Lake City UT", 344);
    cities[12] = City("Boise ID", 637);
    cities[13] = City("San Francisco CA", 0);
}

// CRITERIA: 1 loop, 1 if chain
// Starts game loop
void Game::start(){
    std::cout << std::fixed << std::setprecision(1);
    clear();
    selectCar();
    while(!gameOver){
        printHeading();
        std::cout << "1. Map" << std::endl;
        std::cout << "2. Restraunt" << std::endl;
        std::cout << "3. Gas Station" << std::endl;
        std::cout << "4. Hotel" << std::endl;
        std::cout << "5. Continue on road trip" << std::endl;
        std::cout << "Enter an option: ";
        std::string option;
        std::getline(std::cin, option);
        if(option == "1"){
            map();
        } else if(option == "2") {
            restraunt(1 + city*0.2);
        } else if(option == "3") {
            gasStation(1 + city*0.2);
        } else if(option == "4") {
            hotel(1 + city*0.);
        } else if(option == "5") {
            travel();
        } else {
            std::cout << "Invalid option." << std::endl;
            pause();
            clear();
        }
    }
}
