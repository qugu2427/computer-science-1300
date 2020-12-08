#include<iostream>
#include <iomanip>

using namespace std;

int main(){
    int pieces;
    float cost;
    cout << "Enter the number of sushi:" << endl;
    cin >> pieces;
    if(pieces <= 0){
        cout << "Invalid input" << endl;
        return 0;
    }
    cost = pieces * 1.99;
    if(pieces >= 100){
        cost -= cost * 0.25;
    }
    else if(pieces >= 50){
        cost -= cost * 0.2;
    }
    else if(pieces >= 20){
        cost -= cost * 0.15;
    }
    else if(pieces >= 10){
        cost -= cost * 0.1;
    }
    cout << "Total price: $" << fixed << setprecision(2) << cost << endl;
}