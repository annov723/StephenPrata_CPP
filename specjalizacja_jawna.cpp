#include <iostream>

using namespace std;

template <typename Any>
void Swap( Any &a, Any &b );

struct job{
    char name[40];
    double salary;
    int floor;
};

//jawna specjalizacja
template <> void Swap<job>( job &a, job &b );

void Show( job const &a );

int main( void ){
    cout.precision( 2 ); //do 2 miejsc po przecinku
    cout.setf( ios::fixed, ios::floatfield );
    int i = 10, j = 20;
    cout << "Before the Swap: i = " << i << ", j = " << j << endl;
    Swap( i, j );
    cout << "After the Swap: i = " << i << ", j = " << j << endl;

    job worker1 = { "Ola", 3205.98, 9 }, worker2 = { "Bob", 23.78, 5 };
    cout << "Before the Swap:" << endl;
    Show( worker1 );
    Show( worker2 );
    Swap( worker1, worker2 );
    cout << "After the Swap:" << endl;
    Show( worker1 );
    Show( worker2 );



    return 0;
}

void Show( job const &a ){
    cout << a.name << " " << a.salary << " " << a.floor << endl;
}

template <typename Any>
void Swap( Any &a, Any &b ){
    Any temp = a;
    a = b;
    b = temp;
}

template <> void Swap<job>( job &a, job &b ){
    int temp = a.floor;
    a.floor = b.floor;
    b.floor = temp;
}