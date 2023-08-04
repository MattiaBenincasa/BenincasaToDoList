//
// Created by Mattia Benincasa on 11/07/23.
//

#ifndef BENINCASATODOLIST_DATE_H
#define BENINCASATODOLIST_DATE_H
#include <iostream>
#include "InvalidDate.h"

class Date {
public:
    Date(int d = 1, int m = 1, int y = 2023) : day(d), month(m), year(y) {}

    int getDay() const{
        return day;
    }

    int getMonth() const{
        return month;
    }

    int getYear() const {
        return year;
    }

    bool leapYear(int y) const;
    void controlDayYear(int y);
    void controlDayMonth(int m);
    void setDay(int d);
    void setMonth(int m);
    void setYear(int y);
    friend std::ostream& operator << (std::ostream& os, const Date& d);
    friend std::istream& operator >> (std::istream& is, Date& d);

    bool getValid() const {
        return valid;
    }
private:
    int day;
    int month;
    int year;
    bool valid {false};
};


#endif //BENINCASATODOLIST_DATE_H
