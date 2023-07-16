//
// Created by Mattia Benincasa on 10/07/23.
//

#ifndef BENINCASATODOLIST_CLOCK_H
#define BENINCASATODOLIST_CLOCK_H
#include <iostream>
#include <fstream>
#include "InvalidTime.h"

class Clock {
public:
    explicit Clock(int h = 0, int m = 0) : minute(m), hour(h) {}

    int getMinute() const{
        return minute;
    }

    int getHour() const{
        return hour;
    }

    void setMinute(int m);
    void setHour(int h);
    friend std::ostream& operator << (std::ostream&, const Clock& c);
    friend std::istream& operator >> (std::istream& cin, Clock& c);

    bool getValid() const {
        return valid;
    }

private:
    int minute;
    int hour;
    bool valid {false};
};

#endif //BENINCASATODOLIST_CLOCK_H
