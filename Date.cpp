//
// Created by Mattia Benincasa on 13/07/23.
//
#include "Date.h"


bool Date::leapYear(int y) const{
    if(y%400 == 0 || y%4 == 0)
        return true;
    else if(y%100 == 0)
        return false;

    return false;
}

void Date::controlDayMonth(int m) {
    if(((m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12 ) && day > 31) ||
       ((m == 4 || m == 6 || m == 9 || m == 11) && day > 30) || ((leapYear(year) && m == 2) &&
       day > 29) || (!leapYear(year) && month == 2) && day > 28){
        valid = false;
        throw InvalidDate("Date is not valid");
    }
}

void Date::controlDayYear(int y) {
    if(((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12 ) && day > 31) ||
       ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) || ((leapYear(y) && month == 2) &&
       day > 29) || (!leapYear(y) && month == 2) && day > 28){
        valid = false;
        throw InvalidDate("Date is not valid");
    }
}

void Date::setDay(int d) {

    if(((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12 ) && d > 31) ||
    ((month == 4 || month == 6 || month == 9 || month == 11) && d > 30) || ((leapYear(year) && month == 2) &&
    d > 29) || (!leapYear(year) && month == 2) && d > 28 || d <= 0){
        throw InvalidDate("Date is not valid");
    }

    day = d;
    valid = true;
}

void Date::setMonth(int m) {
    controlDayMonth(m);
    if(m <= 0 || m > 12) {
        valid = false;
        throw InvalidDate("Month selected is not valid.");
    }
    month = m;
}

void Date::setYear(int y) {
    controlDayYear(y);
    if(y <= 0 ) {
        valid = false;
        throw InvalidDate("Year selected is not valid.");
    }
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
