//
// Created by Mattia Benincasa on 13/07/23.
//
#include "Date.h"

std::ostream& operator << (std::ostream& os, const Date& d){
    os << d.day << "/" << d.month << "/" << d.year << std::endl;
    return os;
}
