//
// Created by Mattia Benincasa on 13/07/23.
//

#ifndef BENINCASATODOLIST_IVALIDTIME_H
#define BENINCASATODOLIST_IVALIDTIME_H
#include <stdexcept>

class InvalidTime : public std::out_of_range{
public:
    explicit InvalidTime(std::string const &problems) : std::out_of_range(problems) {}
};

#endif //BENINCASATODOLIST_IVALIDTIME_H
