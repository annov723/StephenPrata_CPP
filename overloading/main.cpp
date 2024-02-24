#include "mytime0.h"

#include <iostream>

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

    return 0;
}