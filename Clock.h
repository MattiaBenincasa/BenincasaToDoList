//
// Created by Mattia Benincasa on 10/07/23.
//

#ifndef BENINCASATODOLIST_CLOCK_H
#define BENINCASATODOLIST_CLOCK_H

class Clock {
public:
    Clock(int h, int m) : minute(m), hour(h) {}

    int getMinute() const{
        return minute;
    }

    void setMinute(int m){
        minute = m;
    }

    int getHour() const{
        return hour;
    }

    void setHour(int h) {
        hour = h;
    }

private:
    int minute;
    int hour;
};

#endif //BENINCASATODOLIST_CLOCK_H
