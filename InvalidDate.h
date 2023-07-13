//
// Created by Mattia Benincasa on 13/07/23.
//

#ifndef BENINCASATODOLIST_INVALIDDATE_H
#define BENINCASATODOLIST_INVALIDDATE_H
#include <stdexcept>

class InvalidDate : public std::out_of_range {
public:
    explicit InvalidDate(std::string const &problem) : std::out_of_range(problem) {}
};

#endif //BENINCASATODOLIST_INVALIDDATE_H
