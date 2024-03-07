#include "zesp.h"

using namespace std;

int main(){

    Zesp a( 3.0, 4.0 );
    Zesp c;
    cout << "Podaj liczbe zespolona(k, aby zakonczyc): ";
    while( cin >> c ){
        cout << "c to: " << c << endl;
        cout << "sprzezona z c to: " << ~c << endl;
        cout << "a to " << a << endl;
        cout << "a + c = " << a + c << endl;
        cout << "a - c = " << a - c << endl;
        cout << "a * c = " << a * c << endl;
        cout << "2 * c = " << 2 * c << endl;
        cout << "Podaj liczbe zespolona(k, aby zakonczyc): ";
    }

}