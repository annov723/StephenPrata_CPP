#include "mytime0.h"

#include <iostream>

Time::Time(){
    hours = minutes = 0;
}

Time::Time( int h, int m ){
    hours = h;
    minutes = m;
}

void Time::AddM( int m ){
    minutes += m;
    hours += minutes / 60;
    minutes %= 60;
}

void Time::AddH( int h ){
    hours += h;
}

void Time::Reset( int h, int m ){
    hours = h;
    minutes = m;
}

Time Time::operator+( const Time & t ) const{
    Time sum;
    sum.minutes = minutes + t.minutes;
    sum.hours = hours + t.hours + ( sum.minutes / 60 );
    sum.minutes %= 60;
    return sum;
}

Time Time::operator-( const Time & t ) const{
    Time diff;
    int tot1 = t.minutes + 60 * t.hours;
    int tot2 = minutes + 60 * hours;
    diff.minutes = ( tot2 - tot1 ) % 60;
    diff.hours = ( tot2 - tot1 ) / 60;
    return diff;
}

Time Time::operator*( double n ) const{
    Time res;
    long totalM = hours * n * 60 + minutes * n;
    res.minutes = totalM % 60;
    res.hours = totalM / 60;
    return res;
}

void Time::Show() const{
    std::cout << hours << " godzin " << minutes << " minut" << std::endl;
}

int Time::getH() const{
    return hours;
}

int Time::getM() const{
    return minutes;
}