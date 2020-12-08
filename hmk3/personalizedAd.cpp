#include<iostream>
#include <string>

using namespace std;

void scen1();
void scen2();
void scen3();

int main(){
    int scen;
    cout << "How personalized should the ad be? (1-3)" << endl;
    cin >> scen;
    switch(scen){
        case 1:
            scen1();
            break;
        case 2:
            scen2();
            break;
        case 3:
            scen3();
            break;
        default:
            cout << "Invalid option." << endl;
            break;
    }
    return 0;
}

void scen1(){
    string input;
    cout << "Do you own a dog?" << endl;
    cin >> input;
    if(input == "yes" || input == "Yes"){
        cout << "Meat's the need of dogs like yours!" << endl;
    }
    else{
        cout << "Dirty mouth? Clean it up with new Orbit Raspberry Mint." << endl;
    }
}

void scen2(){
    int friends;
    cout << "How many Facebook friends do you have?" << endl;
    cin >> friends;
    if(friends >= 500){
        cout << "Don't like cleaning up after your dog? Call Doody Free to sign up for backyard cleanup or dog walking service." << endl;
    }
    else{
        cout << "Who doesn't need another cat? Adopt a shelter pet right meow." << endl;
    }
}

void scen3(){
    int zip, age;
    cout << "What is your zip code?" << endl;
    cin >> zip;
    cout << "What is your age?" << endl;
    cin >> age;
    if(zip >= 80301 && zip <= 80310){
        if(age >= 25){
            cout << "You are surrounded by professional athletes. Up your exercise game in the privacy of your home with a Peloton bike." << endl;
        }
        else{
            cout << "Looking for dinner that won't break the bank? Tacos. Come grab a $3 at Centro Latin Kitchen." << endl;
        }
    }
    else{
        cout << "Feeling Uninspired? The Boulder Flatirons are calling. Come hike to inspiring views, delicious food, and enjoy the hospitality of Boulder, CO." << endl;
    }
}