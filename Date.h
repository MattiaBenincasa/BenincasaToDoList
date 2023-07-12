//
// Created by Mattia Benincasa on 11/07/23.
//

#ifndef BENINCASATODOLIST_DATE_H
#define BENINCASATODOLIST_DATE_H

class Date {
public:
    Date(int d = 1, int m = 1, int y = 1950) : day(d), month(m), year(y) {}

    int getDay() const{
        return day;
    }

    void setDay(int d) {
        day = d;
    }

    int getMonth() const{
        return month;
    }

    void setMonth(int m) {
        month = m;
    }

    int getYear() const {
        return year;
    }

    void setYear(int y) {
        year = y;
    }

private:
    int day;
    int month;
    int year;
};


#endif //BENINCASATODOLIST_DATE_H
