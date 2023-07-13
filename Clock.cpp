//
// Created by Mattia Benincasa on 13/07/23.
//
#include <iomanip>
#include "Clock.h"

std::ostream& operator << (std::ostream&, const Clock& c){
    std::cout << c.hour << std::setfill('0') << ":" << std::setw(2) << c.minute << std::endl;
    return std::cout;
}