//
// Created by Mattia Benincasa on 11/07/23.
//

#ifndef BENINCASATODOLIST_DATE_H
#define BENINCASATODOLIST_DATE_H
#include <iostream>

class Date {
public:
    Date(int d = 1, int m = 1, int y = 1950) : day(d), month(m), year(y) {}

    int getDay() const{
        return day;
    }

    int getMonth() const{
        return month;
    }

    int getYear() const {
        return year;
    }

    void setDay(int d);
    void setMonth(int m);
    void setYear(int y);
    friend std::ostream& operator << (std::ostream& os, const Date& d);

private:
    int day;
    int month;
    int year;
};


#endif //BENINCASATODOLIST_DATE_H
