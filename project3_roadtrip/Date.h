#pragma once

#include <string>

// CRITERIA: 4+ data members
class Date {
    private:
        int month;
        int day;
        int year;
        std::string names[12];
        int dayCounts[12];
    public:
        Date();
        Date(int month, int day, int year);
        std::string getMonth();
        int getDay();
        int getYear();
        void addDays(int days);
};