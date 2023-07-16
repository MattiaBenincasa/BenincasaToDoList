//
// Created by Mattia Benincasa on 13/07/23.
//
#include "Date.h"


void Date::setDay(int d) {
    if((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && (d <= 0 || d > 31))
        throw InvalidDate("Day is not valid: max 31 days for this month");
    else if ((month == 4 || month == 6 || month == 9 || month == 11) && (d <= 0 || d > 30))
        throw InvalidDate("Day is not valid: max 30 days for this month");
    else if (((year%4 == 0 || year%400 == 0) && month==2) && (d <= 0 || d > 29))
        throw InvalidDate("Day is not valid: max 29 days for this month");
    else if (((year%4 != 0 || year%400 != 0) && month==2) && (d <= 0 || d > 28))
        throw InvalidDate("Day is not valid: max 28 days for this month");

    day = d;
    valid = true;
}

void Date::setMonth(int m) {
    if(m <= 0 || m > 12)
        throw InvalidDate("Month selected is not valid.");
    month = m;
}

void Date::setYear(int y) {
    if(y <= 0 )
        throw InvalidDate("Year selected is not valid.");

    year = y;
}

std::ostream& operator << (std::ostream& os, const Date& d){
    os << d.day << "/" << d.month << "/" << d.year;
    return os;
}


std::istream& operator >> (std::istream& is, Date& d){
    is >> d.day >> d.month >> d.year;
    return is;
}
