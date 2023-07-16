//
// Created by Mattia Benincasa on 13/07/23.
//
#include <iomanip>
#include "Clock.h"

void Clock::setMinute(int m) {
    if (m < 0 || m > 59)
        throw InvalidTime("Minutes selected are not valid.");
    minute = m;
}

void Clock::setHour(int h) {
    if (h < 0 || h > 23)
        throw InvalidTime("Hours selected are not valid");
    hour = h;
    valid = true;
}

std::ostream& operator << (std::ostream& out, const Clock& c){
    out << c.hour << std::setfill('0') << ":" << std::setw(2) << c.minute;
    return out;
}

std::istream& operator >> (std::istream& cin, Clock& c){
    cin >> c.hour;
    cin >> c.minute;
    return cin;
}