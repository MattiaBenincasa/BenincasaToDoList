//
// Created by Mattia Benincasa on 10/07/23.
//

#ifndef BENINCASATODOLIST_TIME_H
#define BENINCASATODOLIST_TIME_H

class Time {
public:
    Time(int h, int m) : minute(m), hour(h) {}

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

#endif //BENINCASATODOLIST_TIME_H
