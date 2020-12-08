#include<iostream>

using namespace std;

int main(){
    int year, month, days;
    bool isLeap;
    cout << "Enter a year:" << endl;
    cin >> year;
    cout << "Enter a month:" << endl;
    cin >> month;
    isLeap = year % 4 == 0;
    if(year > 1582){
        if(year % 100 == 0){
            isLeap = false;
        }
        if(year % 400 == 0){
            isLeap = true;
        }
    }
    
    if(month == 1 ||
        month == 3 ||
        month == 5 ||
        month == 7 ||
        month == 8 ||
        month == 10 ||
        month == 12){
            days = 31;
    }
    else if(month == 4 ||
        month == 6 ||
        month == 9 ||
        month == 11){
            days = 30;
    }
    else if(month == 2){
        if(isLeap){
            days = 29;
        }
        else{
            days = 28;
        }
    }
    else{
        cout << "Invalid month" << endl;
        return 0;
    }
    cout << days << " days" << endl;
}