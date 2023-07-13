//
// Created by Mattia Benincasa on 13/07/23.
//
#include <iomanip>
#include "Clock.h"

void Clock::setMinute(int m) {
    if (m < 0 || m > 59)
        throw InvalidTime("InvalidMinute");
    minute = m;
}

void Clock::setHour(int h) {
    if (h < 0 || h > 23)
        throw InvalidTime("InvalidHour");
    hour = h;
}

std::ostream& operator << (std::ostream&, const Clock& c){
    std::cout << c.hour << std::setfill('0') << ":" << std::setw(2) << c.minute;
    return std::cout;
}