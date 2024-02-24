#include "mytime0.h"

#include <iostream>

Time operator*( double n, const Time & t );

int main(){
    using std::cout;
    using std::endl;

    Time planning;
    Time coding( 2, 40 );
    Time fixing( 5, 55 );
    Time total;

    planning.Show();
    coding.Show();
    fixing.Show();
    total.Show();

    total = coding + fixing;

    cout << "coding + fixing: ";
    total.Show();

    planning.AddH( 3 );
    planning.AddM( 67 );
    total = total.operator+( planning );

    cout << "planning + coding + fixing: ";
    total.Show();

    cout << "planning before: ";
    planning.Show();
    planning = planning * 3.22;
    cout << "planning after: ";
    planning.Show();
    planning = planning.operator*( 0.5 );
    cout << "planning after after: ";
    planning.Show();
    planning = 3 * planning;
    cout << "planning after after after: ";
    planning.Show();

    total = fixing - coding;
    cout << "fixing is longer than coding: ";
    total.Show();

    return 0;
}

Time operator*( double n, const Time & t ){
    Time res;
    long totalM = t.getH() * n * 60 + t.getM() * n;
    res.AddM( totalM % 60 );
    res.AddH( totalM / 60 );
    return res;
}