#include "Date.h"

Date::Date():month(2), day(28), year(2007){
    names[0] = "January";
    dayCounts[0] = 31;
    names[1] = "Febuary";
    dayCounts[1] = 28;
    names[2] = "March";
    dayCounts[2] = 31;
    names[3] = "April";
    dayCounts[3] = 30;
    names[4] = "May";
    dayCounts[4] = 31;
    names[5] = "June";
    dayCounts[5] = 30;
    names[6] = "July";
    dayCounts[6] = 31;
    names[7] = "August";
    dayCounts[7] = 31;
    names[8] = "September";
    dayCounts[8] = 30;
    names[9] = "October";
    dayCounts[9] = 31;
    names[10] = "November";
    dayCounts[10] = 30;
    names[11] = "December";
    dayCounts[11] = 31;
}

Date::Date(int month, int day, int year):month(month), day(day), year(year){
    names[0] = "January";
    dayCounts[0] = 31;
    names[1] = "Febuary";
    dayCounts[1] = 28;
    names[2] = "March";
    dayCounts[2] = 31;
    names[3] = "April";
    dayCounts[3] = 30;
    names[4] = "May";
    dayCounts[4] = 31;
    names[5] = "June";
    dayCounts[5] = 30;
    names[6] = "July";
    dayCounts[6] = 31;
    names[7] = "August";
    dayCounts[7] = 31;
    names[8] = "September";
    dayCounts[8] = 30;
    names[9] = "October";
    dayCounts[9] = 31;
    names[10] = "November";
    dayCounts[10] = 30;
    names[11] = "December";
    dayCounts[11] = 31;
}

std::string Date::getMonth(){
    return names[month];
}

int Date::getDay(){
    return day;
}

int Date::getYear(){
    return year;
}

void Date::addDays(int days){
    while(days > 0){
        if(day == dayCounts[month]){
            day = 1;
            if(month == 11){
                month = 0;
                year++;
            } else {
                month++;
            }
        } else {
            day++;
        }
        days--;
    }
}

